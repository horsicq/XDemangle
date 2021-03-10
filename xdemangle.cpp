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
        case MODE_UNKNOWN:      sResult=tr("Unknown");                  break;
        case MODE_AUTO:         sResult=tr("Automatic");                break;
        case MODE_MSVC32:       sResult=QString("MSVC+++ 32");          break;
        case MODE_GCC:          sResult=QString("GCC");                 break;
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

QString XDemangle::storageClassIdToString(XDemangle::SC storageClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(storageClass)
    {
        case SC_UNKNOWN:            sResult=QString("Unknown");             break; // mb TODO translate
        case SC_NEAR:               sResult=QString("");                    break;
        case SC_CONST:              sResult=QString("const");               break;
        case SC_VOLATILE:           sResult=QString("volatile");            break;
        case SC_CONSTVOLATILE:      sResult=QString("const volatile");      break;
        case SC_FAR:                sResult=QString("");                    break;
        case SC_CONSTFAR:           sResult=QString("const");               break;
        case SC_VOLATILEFAR:        sResult=QString("volatile");            break;
        case SC_CONSTVOLATILEFAR:   sResult=QString("const volatile");      break;
        case SC_HUGE:               sResult=QString("");                    break;
        case SC_EXECUTABLE:         sResult=QString("");                    break;
    }

    return sResult;
}

QString XDemangle::objectClassIdToString(OC objectClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(objectClass)
    {
        case OC_UNKNOWN:                    sResult=QString("Unknown");             break; // mb TODO translate
        case OC_GLOBALOBJECT:               sResult=QString("");                    break;
        case OC_PRIVATESTATICCLASSMEMBER:   sResult=QString("private static");      break;
        case OC_PROTECTEDSTATICCLASSMEMBER: sResult=QString("protected static");    break;
        case OC_PUBLICSTATICCLASSMEMBER:    sResult=QString("public static");       break;
    }

    return sResult;
}

QString XDemangle::paramModIdToString(XDemangle::PM paramMod, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(paramMod)
    {
        case PM_NONE:               sResult=QString("");                    break; // mb TODO translate
        case PM_POINTER:            sResult=QString("*");                   break;
        case PM_REFERENCE:          sResult=QString("&");                   break;
    }

    return sResult;
}

QString XDemangle::functionConventionIdToString(XDemangle::FC functionConvention, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(functionConvention)
    {
        case FC_UNKNOWN:            sResult=QString("Unknown");                    break; // mb TODO translate
        case FC_CDECL:              sResult=QString("__cdecl");                    break;
        case FC_THISCALL:           sResult=QString("__thiscall");                 break;
        case FC_STDCALL:            sResult=QString("__stdcall");                  break;
        case FC_FASTCALL:           sResult=QString("__fastcall");                 break;
        case FC_VECTORCALL:         sResult=QString("__vectorcall");               break;
    }

    return sResult;
}

XDemangle::SYMBOL XDemangle::getSymbol(QString sString, XDemangle::MODE mode)
{
    SYMBOL result={};

    if(mode==MODE_MSVC32)
    {
        result=handle_MSVC_family(sString);
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

XDemangle::MODE XDemangle::detectMode(QString sString)
{
    MODE result=MODE_UNKNOWN;

    if(_compare(sString,"?"))
    {
        result=MODE_MSVC32;
    }

    return result;
}

QList<XDemangle::MODE> XDemangle::getAllModes()
{
    QList<MODE> listResult;

    listResult.append(MODE_AUTO);
    listResult.append(MODE_MSVC32);
    listResult.append(MODE_GCC);
    listResult.append(MODE_BORLAND);
    listResult.append(MODE_WATCOM);

    return listResult;
}

QString XDemangle::symbolToString(XDemangle::SYMBOL symbol)
{
    QString sResult;

    if(symbol.bValid)
    {
        if(symbol.symbolType==ST_VARIABLE)
        {
            QString sObjectClass=objectClassIdToString(symbol.objectClass,symbol.mode);
            QString sParameter=getStringFromParameter(symbol.paramVariable,symbol.mode);
            QString sName=getNameFromSymbol(symbol);

            if(sObjectClass!="")    sResult+=QString("%1 ").arg(sObjectClass);
            if(sParameter!="")      sResult+=QString("%1 ").arg(sParameter);
            if(sName!="")           sResult+=QString("%1").arg(sName);
        }
        else if((symbol.symbolType==ST_FUNCTION)||(symbol.symbolType==ST_CLASSMETHOD))
        {
            QString sParameterReturn=getStringFromParameter(symbol.paramFunctionReturn,symbol.mode);
            QString sFunctionConvention=functionConventionIdToString(symbol.functionConvention,symbol.mode);
            QString sName=getNameFromSymbol(symbol);

            sResult+=QString("%1 ").arg(sParameterReturn);
            sResult+=QString("%1 ").arg(sFunctionConvention);
            sResult+=sName;
            sResult+=QString("(");

            int nNumberOfrguments=symbol.listFunctionArguments.count();

            for(int i=0;i<nNumberOfrguments;i++)
            {
                sResult+=getStringFromParameter(symbol.listFunctionArguments.at(i),symbol.mode);

                if(i!=nNumberOfrguments-1)
                {
                    sResult+=QString(",");;
                }
            }

            sResult+=QString(")");
        }
    }

    return sResult;
}

XDemangle::STRING XDemangle::readString(QString sString, XDemangle::MODE mode)
{
    STRING result={};

    if(mode==MODE_MSVC32)
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

XDemangle::SYMBOL XDemangle::handle_MSVC_family(QString sString)
{
    SYMBOL result={};
    // All C++ begins with ?

    if(_compare(sString,"?"))
    {
        sString=sString.mid(1,-1);

        result.mode=MODE_MSVC32;

        QMap<QString,qint32> mapParamMods=getParamMods(MODE_MSVC32);
        QMap<QString,qint32> mapObjectClasses=getObjectClasses(MODE_MSVC32);
        QMap<QString,qint32> mapTypes=getTypes(MODE_MSVC32);
        QMap<QString,qint32> mapStorageClasses=getStorageClasses(MODE_MSVC32);
        QMap<QString,qint32> mapFunctionMods=getFunctionMods(MODE_MSVC32);
        QMap<QString,qint32> mapFunctionConventions=getFunctionConventions(MODE_MSVC32);
        QMap<QString,qint32> mapOperators=getOperators(MODE_MSVC32);

        if(isSignaturePresent(sString,&mapOperators))
        {
            SIGNATURE signatureOP=getSignature(sString,&mapTypes);
            result._operator=(OP)signatureOP.nValue;
            sString=sString.mid(signatureOP.nSize,-1);
        }

        // Name
        while(sString!="")
        {
            STRING _string=readString(sString,MODE_MSVC32);

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
            result.symbolType=ST_VARIABLE;

            SIGNATURE signatureOC=getSignature(sString,&mapObjectClasses);
            result.objectClass=(OC)signatureOC.nValue;
            sString=sString.mid(signatureOC.nSize,-1);

            if(isSignaturePresent(sString,&mapTypes))
            {
                SIGNATURE signature=getSignature(sString,&mapTypes);
                result.paramVariable.type=(TYPE)signature.nValue;
                sString=sString.mid(signature.nSize,-1);
            }
        }
        else if(isSignaturePresent(sString,&mapFunctionMods))
        {
            SIGNATURE signatureFM=getSignature(sString,&mapFunctionMods);
            result.functionMod=(FM)signatureFM.nValue;
            sString=sString.mid(signatureFM.nSize,-1);

            if((result.functionMod==FM_FAR)||(result.functionMod==FM_NEAR))
            {
                // Function
                result.symbolType=ST_FUNCTION;
                // Global function
                if(isSignaturePresent(sString,&mapFunctionConventions))
                {
                    SIGNATURE signature=getSignature(sString,&mapFunctionConventions);
                    result.functionConvention=(FC)signature.nValue;
                    sString=sString.mid(signature.nSize,-1);
                }
            }
            else
            {
                // Class method
                result.symbolType=ST_CLASSMETHOD;

            }

            int nIndex=0;

            while(sString!="")
            {
                SIGNATURE signatureParamMod={};
                SIGNATURE signatureStorageClass={};

                if(isSignaturePresent(sString,&mapParamMods))
                {
                    signatureParamMod=getSignature(sString,&mapParamMods);
                    sString=sString.mid(signatureParamMod.nSize,-1);

                    signatureStorageClass=getSignature(sString,&mapStorageClasses);
                    sString=sString.mid(signatureStorageClass.nSize,-1);
                }

                SIGNATURE signatureType=getSignature(sString,&mapTypes);

                if(signatureType.nSize)
                {
                    PARAMETER parameter={};
                    parameter.type=(TYPE)signatureType.nValue;
                    parameter.paramMod=(PM)signatureParamMod.nValue;

                    if(signatureStorageClass.nValue)
                    {
                        parameter.storageClass=(SC)signatureStorageClass.nValue;
                    }
                    else
                    {
                        parameter.storageClass=SC_NEAR; // TODO Check
                    }

                    if(nIndex==0)
                    {
                        result.paramFunctionReturn=parameter;
                    }
                    else
                    {
                        result.listFunctionArguments.append(parameter);
                    }
                }
                else
                {
                    break;
                }

                sString=sString.mid(signatureType.nSize,-1);

                if((nIndex>0)&&(signatureType.nValue==(TYPE)TYPE_VOID)) //if func(void)
                {
                    break;
                }

                nIndex++;
            }

            if(_compare(sString,"@"))
            {
                sString=sString.mid(1,-1);
            }
        }

        if(isSignaturePresent(sString,&mapStorageClasses))
        {
            SIGNATURE signature=getSignature(sString,&mapStorageClasses);
            result.paramVariable.storageClass=(SC)signature.nValue;
            sString=sString.mid(signature.nSize,-1);
        }

        if((sString=="")&&(result.paramVariable.storageClass!=SC_UNKNOWN)) // TODO more checks
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

    if(mode==MODE_MSVC32)
    {
        mapResult.insert("@0",OC_PRIVATESTATICCLASSMEMBER);
        mapResult.insert("@1",OC_PROTECTEDSTATICCLASSMEMBER);
        mapResult.insert("@2",OC_PUBLICSTATICCLASSMEMBER);
        mapResult.insert("@3",OC_GLOBALOBJECT);
        mapResult.insert("@4",OC_FUNCTIONLOCALSTATIC);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getTypes(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC32)
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

QMap<QString, qint32> XDemangle::getParamMods(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC32)
    {
        mapResult.insert("P",PM_POINTER);
        mapResult.insert("A",PM_REFERENCE);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getStorageClasses(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC32)
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
        mapResult.insert("Z",SC_EXECUTABLE);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getFunctionMods(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC32)
    {
        mapResult.insert("@A",FM_PRIVATE_NEAR);
        mapResult.insert("@B",FM_PRIVATE_FAR);
        mapResult.insert("@C",FM_PRIVATE_STATICNEAR);
        mapResult.insert("@D",FM_PRIVATE_STATICFAR);
        mapResult.insert("@E",FM_PRIVATE_VIRTUALNEAR);
        mapResult.insert("@F",FM_PRIVATE_VIRTUALFAR);
        mapResult.insert("@I",FM_PROTECTED_NEAR);
        mapResult.insert("@J",FM_PROTECTED_FAR);
        mapResult.insert("@K",FM_PROTECTED_STATICNEAR);
        mapResult.insert("@L",FM_PROTECTED_STATICFAR);
        mapResult.insert("@M",FM_PROTECTED_VIRTUALNEAR);
        mapResult.insert("@N",FM_PROTECTED_VIRTUALFAR);
        mapResult.insert("@Q",FM_PUBLIC_NEAR);
        mapResult.insert("@R",FM_PUBLIC_FAR);
        mapResult.insert("@S",FM_PUBLIC_STATICNEAR);
        mapResult.insert("@T",FM_PUBLIC_STATICFAR);
        mapResult.insert("@U",FM_PUBLIC_VIRTUALNEAR);
        mapResult.insert("@V",FM_PUBLIC_VIRTUALFAR);
        mapResult.insert("@Y",FM_NEAR);
        mapResult.insert("@Z",FM_FAR);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getFunctionConventions(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC32)
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

QMap<QString, qint32> XDemangle::getOperators(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(mode==MODE_MSVC32)
    {
        mapResult.insert("?0",OP_CONSTRUCTOR);
        mapResult.insert("?1",OP_DESTRUCTOR);
    }

    return mapResult;
}

QString XDemangle::getNameFromSymbol(XDemangle::SYMBOL symbol)
{
    QString sResult;

    int nNumberOfNames=symbol.listNames.count();

    for(int i=nNumberOfNames-1;i>=0;i--)
    {
        sResult+=symbol.listNames.at(i);

        if(i)
        {
            sResult+="::";
        }
    }

    return sResult;
}

QString XDemangle::getStringFromParameter(XDemangle::PARAMETER parameter, MODE mode)
{
    QString sResult;

    QString sStorageClass=storageClassIdToString(parameter.storageClass,mode);
    QString sType=typeIdToString(parameter.type,mode);
    QString sParamMod=paramModIdToString(parameter.paramMod,mode);

    if(sStorageClass!="")   sResult+=QString("%1 ").arg(sStorageClass);
    if(sType!="")           sResult+=QString("%1").arg(sType);
    if(sParamMod!="")       sResult+=QString(" %1").arg(sParamMod);

    return sResult;
}
