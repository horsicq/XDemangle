// copyright (c) 2021 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include "xdemangle.h"

XDemangle::XDemangle(QObject *pParent) : QObject(pParent)
{

}

QString XDemangle::modeIdToString(XDemangle::MODE mode)
{
    QString sResult="Unknown"; // mb TODO translate

    switch(mode)
    {
        case MODE_UNKNOWN:      sResult=QString("Unknown");             break; // mb TODO translate
        case MODE_MSVC:         sResult=QString("MSVC C++");            break;
        case MODE_GCC_2XX:      sResult=QString("GCC 2.XX");            break;
        case MODE_GCC_3XX:      sResult=QString("GCC 3.XX-X.XX");       break;
        case MODE_WATCOM:       sResult=QString("Watcom");              break;
        case MODE_BORLAND:      sResult=QString("Borland");             break;
    }

    return sResult;
}

QString XDemangle::typeIdToString(XDemangle::TYPE type, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(type)
    {
        case TYPE_UNKNOWN:          sResult=QString("Unknown");             break; // mb TODO translate
        case TYPE_VOID:             sResult=QString("void");                break;
        case TYPE_BOOL:             sResult=QString("bool");                break;
        case TYPE_INT:              sResult=QString("int");                 break;
        case TYPE_SCHAR:            sResult=QString("signed char");         break;
        case TYPE_CHAR:             sResult=QString("char");                break;
        case TYPE_UCHAR:            sResult=QString("unsigned char");       break;
        case TYPE_SHORT:            sResult=QString("short");               break;
        case TYPE_USHORT:           sResult=QString("unsigned short");      break;
        case TYPE_UINT:             sResult=QString("unsigned int");        break;
        case TYPE_LONG:             sResult=QString("long");                break;
        case TYPE_ULONG:            sResult=QString("unsigned long");       break;
        case TYPE_FLOAT:            sResult=QString("float");               break;
        case TYPE_DOUBLE:           sResult=QString("double");              break;
        case TYPE_LONGDOUBLE_64:    sResult=QString("long double");         break;
        case TYPE_LONGDOUBLE_80:    sResult=QString("long double");         break;
        case TYPE_INT64:            sResult=QString("__int64");             break;
        case TYPE_UINT64:           sResult=QString("unsigned __int64");    break;
        case TYPE_CHAR8:            sResult=QString("char");                break;
        case TYPE_CHAR16:           sResult=QString("char16_t");            break;
        case TYPE_CHAR32:           sResult=QString("char32_t");            break;
        case TYPE_WCHAR:            sResult=QString("wchar_t");             break;
        case TYPE_VARARGS:          sResult=QString("...");                 break;
    }

    return sResult;
}

XDemangle::SYMBOL XDemangle::getSymbol(QString sString, XDemangle::MODE mode)
{
    SYMBOL result={};

    if(mode==MODE_MSVC)
    {
        result=handle_MSVC(sString);
    }

    return result;
}

QString XDemangle::convert(QString sString, MODE mode)
{
    QString sResult;

    if(sString!="")
    {
        SYMBOL symbol=getSymbol(sString,mode);

        sResult=symbolToString(symbol);
    }

    return sResult;
}

QString XDemangle::symbolToString(XDemangle::SYMBOL symbol)
{
    QString sResult;

    if(symbol.bValid)
    {
        if(symbol.objectClass==OC_STATICCLASSMEMBER)
        {
            sResult+=QString("static ");
        }

        if(symbol.storageClass==SC_CONST)
        {
            sResult+=QString("const ");
        }
        else if(symbol.storageClass==SC_VOLATILE)
        {
            sResult+=QString("volatile ");
        }
        else if(symbol.storageClass==SC_CONSTVOLATILE)
        {
            sResult+=QString("const volatile ");
        }
        else if(symbol.storageClass==SC_CONSTFAR)
        {
            sResult+=QString("const ");
        }
        else if(symbol.storageClass==SC_VOLATILEFAR)
        {
            sResult+=QString("volatile ");
        }
        else if(symbol.storageClass==SC_CONSTVOLATILEFAR)
        {
            sResult+=QString("const volatile ");
        }

        sResult+=QString("%1 ").arg(typeIdToString(symbol.paramReturn.type,symbol.mode));

        int nNumberOfNames=symbol.listNames.count();

        for(int i=nNumberOfNames-1;i>=0;i--)
        {
            sResult+=symbol.listNames.at(i);

            if(i)
            {
                sResult+="::";
            }
        }
    }

    return sResult;
}

XDemangle::STRING XDemangle::readString(QString sString, XDemangle::MODE mode)
{
    STRING result={};

    if(mode==MODE_MSVC)
    {
        result.sString=sString.section("@",0,0);

        result.nSize=result.sString.size();

        if(result.nSize)
        {
            if(result.sString!=sString)
            {
                result.nSize++;
            }
        }
    }

    return result;
}

XDemangle::SYMBOL XDemangle::handle_MSVC(QString sString)
{
    SYMBOL result={};
    // All C++ begins with ?

    if(_compare(sString,"?"))
    {
        result.mode=MODE_MSVC;

        QMap<QString,qint32> mapObjectClasses=getObjectClasses(MODE_MSVC);
        QMap<QString,qint32> mapTypes=getTypes(MODE_MSVC);
        QMap<QString,qint32> mapStorageClasses=getStorageClasses(MODE_MSVC);
        QMap<QString,qint32> mapFunctionDistances=getFunctionDistances(MODE_MSVC);
        QMap<QString,qint32> mapFunctionConventions=getFunctionConventions(MODE_MSVC);

        sString=sString.mid(1,-1);

        // Name
        while(sString!="")
        {
            STRING _string=readString(sString,MODE_MSVC);

            if(_string.nSize)
            {
                result.listNames.append(_string.sString);
            }
            else
            {
                break;
            }

            sString=sString.mid(_string.nSize,-1);
        }

        if(isSignaturePresent(sString,&mapObjectClasses))
        {
            SIGNATURE signature=getSignature(sString,&mapObjectClasses);
            result.objectClass=(OC)signature.nValue;
            sString=sString.mid(signature.nSize,-1);
        }

        if(isSignaturePresent(sString,&mapFunctionDistances))
        {
            SIGNATURE signature=getSignature(sString,&mapFunctionDistances);
            result.functionDistance=(FD)signature.nValue;
            sString=sString.mid(signature.nSize,-1);

            if(isSignaturePresent(sString,&mapFunctionConventions))
            {
                SIGNATURE signature=getSignature(sString,&mapFunctionConventions);
                result.functionConvention=(FC)signature.nValue;
                sString=sString.mid(signature.nSize,-1);
            }
        }

        if(isSignaturePresent(sString,&mapTypes))
        {
            SIGNATURE signature=getSignature(sString,&mapTypes);
            result.paramReturn.type=(TYPE)signature.nValue;
            sString=sString.mid(signature.nSize,-1);
        }

        while(sString!="") // TODO Check
        {
            SIGNATURE signature=getSignature(sString,&mapTypes);

            if(signature.nSize)
            {
                PARAMETER parameter={};
                parameter.type=(TYPE)signature.nValue;

                result.listFunctionArguments.append(parameter);
            }
            else
            {
                break;
            }

            sString=sString.mid(signature.nSize,-1);
        }

        if(isSignaturePresent(sString,&mapStorageClasses))
        {
            SIGNATURE signature=getSignature(sString,&mapStorageClasses);
            result.storageClass=(SC)signature.nValue;
            sString=sString.mid(signature.nSize,-1);
        }

        if(sString=="") // TODO more checks
        {
            result.bValid=true;
        }
        else
        {
        #ifdef QT_DEBUG
            qDebug(sString.toLatin1().data());
        #endif
        }
    }

    return result;
}

bool XDemangle::_compare(QString sString, QString sSignature)
{
    bool bResult=false;

    qint32 nSignatureSize=sSignature.size();

    if(sString.size()>=nSignatureSize)
    {
        QString _sString=sString.left(nSignatureSize);

        bResult=(_sString==sSignature);
    }

    return bResult;
}

bool XDemangle::isSignaturePresent(QString sString, QMap<QString, qint32> *pMap)
{
    bool bResult=false;

    QMapIterator<QString,qint32> i(*pMap);

    while(i.hasNext())
    {
        i.next();

        if(_compare(sString,i.key()))
        {
            bResult=true;

            break;
        }
    }

    return bResult;
}

XDemangle::SIGNATURE XDemangle::getSignature(QString sString, QMap<QString, qint32> *pMap)
{
    SIGNATURE result={};

    QMapIterator<QString,qint32> i(*pMap);

    while(i.hasNext())
    {
        i.next();

        QString sKey=i.key();
        qint32 nValue=i.value();

        if(_compare(sString,sKey))
        {
            result.nSize=sKey.size();
            result.nValue=nValue;

            break;
        }
    }

    return result;
}

QMap<QString, qint32> XDemangle::getObjectClasses(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC)
    {
        mapResult.insert("@2",OC_STATICCLASSMEMBER);
        mapResult.insert("@3",OC_GLOBALOBJECT);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getTypes(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC)
    {
        mapResult.insert("X",TYPE_VOID);
        mapResult.insert("C",TYPE_SCHAR);
        mapResult.insert("D",TYPE_CHAR);
        mapResult.insert("E",TYPE_UCHAR);
        mapResult.insert("F",TYPE_SHORT);
        mapResult.insert("G",TYPE_USHORT);
        mapResult.insert("H",TYPE_INT);
        mapResult.insert("I",TYPE_UINT);
        mapResult.insert("J",TYPE_LONG);
        mapResult.insert("K",TYPE_ULONG);
        mapResult.insert("M",TYPE_FLOAT);
        mapResult.insert("N",TYPE_DOUBLE);
        mapResult.insert("O",TYPE_LONGDOUBLE_64);
        mapResult.insert("Z",TYPE_VARARGS);
        mapResult.insert("_J",TYPE_INT64);
        mapResult.insert("_K",TYPE_UINT64);
        mapResult.insert("_N",TYPE_BOOL);
        mapResult.insert("_Q",TYPE_CHAR8);
        mapResult.insert("_S",TYPE_CHAR16);
        mapResult.insert("_U",TYPE_CHAR32);
        mapResult.insert("_W",TYPE_WCHAR);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getStorageClasses(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC)
    {
        mapResult.insert("A",SC_NEAR);
        mapResult.insert("B",SC_CONST);
        mapResult.insert("C",SC_VOLATILE);
        mapResult.insert("D",SC_CONSTVOLATILE);
        mapResult.insert("E",SC_FAR);
        mapResult.insert("F",SC_CONSTFAR);
        mapResult.insert("G",SC_VOLATILEFAR);
        mapResult.insert("H",SC_CONSTVOLATILEFAR);
        mapResult.insert("I",SC_HUGE);
//        mapResult.insert("F",SC_UNALIGNED);
//        mapResult.insert("I",SC_RESTRICT);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getFunctionDistances(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC)
    {
        mapResult.insert("@Y",FD_NEAR);
        mapResult.insert("@Q",FD_NEAR);
        mapResult.insert("@Z",FD_FAR);
        mapResult.insert("@R",FD_FAR);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getFunctionConventions(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC)
    {
        mapResult.insert("A",FC_CDECL);
        mapResult.insert("C",FC_PASCAL);
        mapResult.insert("E",FC_THISCALL);
        mapResult.insert("G",FC_STDCALL);
        mapResult.insert("I",FC_FASTCALL);
        mapResult.insert("Q",FC_VECTORCALL);
    }

    return mapResult;
}
