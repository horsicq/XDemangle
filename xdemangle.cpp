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
        case TYPE_UNKNOWN:      sResult=QString("Unknown");             break; // mb TODO translate
        case TYPE_INT:          sResult=QString("int");                 break;
    }

    return sResult;
}

QString XDemangle::convert(QString sString, MODE mode)
{
    QString sResult;

    if(sString!="")
    {
        SYMBOL symbol={};

        if(mode==MODE_MSVC)
        {
            symbol=handle_MSVC(sString);
        }

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
    // ??$qbswap@$01@@YAPEAXPEBX_JPEAX@Z
    // ?qHash@@YAIABVQGeoCoordinate@@I@Z
    // int alpha / ?alpha@@3HA
    SYMBOL result={};
    // All C++ begins with ?

    if(_compare(sString,"?"))
    {
        result.mode=MODE_MSVC;

        QMap<QString,qint32> mapObjectClasses=getObjectClasses(MODE_MSVC);
        QMap<QString,qint32> mapTypes=getTypes(MODE_MSVC);
        QMap<QString,qint32> mapStorageClasses=getStorageClasses(MODE_MSVC);

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

    if(!bResult)
    {
    #ifdef QT_DEBUG
        qDebug(sString.toLatin1().data());
    #endif
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

    if(result.nSize==0)
    {
    #ifdef QT_DEBUG
        qDebug(sString.toLatin1().data());
    #endif
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
        mapResult.insert("H",TYPE_INT);
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
    }

    return mapResult;
}
