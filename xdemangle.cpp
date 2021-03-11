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
        case MODE_BORLAND32:    sResult=QString("Borland");             break;
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
        case TYPE_EMPTY:            sResult=QString("");                    break;
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

QString XDemangle::operatorIdToString(XDemangle::OP _operator, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(_operator)
    {
        case OP_UNKNOWN:                sResult=QString("Unknown");             break; // mb TODO translate
        case OP_CONSTRUCTOR:            sResult=QString("");                    break;
        case OP_DESTRUCTOR:             sResult=QString("~");                   break;
        case OP_NEW:                    sResult=QString("operator new");        break;
        case OP_DELETE:                 sResult=QString("operator delete");     break;
        case OP_ASSIGN:                 sResult=QString("operator =");          break;
        case OP_RIGHTSHIFT:             sResult=QString("operator >>");         break;
        case OP_LEFTSHIFT:              sResult=QString("operator <<");         break;
        case OP_LOGICALNOT:             sResult=QString("operator !");          break;
        case OP_EQUALS:                 sResult=QString("operator ==");         break;
        case OP_NOTEQUALS:              sResult=QString("operator !=");         break;
        case OP_ARRAYSUBSCRIPT:         sResult=QString("operator []");         break;
        case OP_POINTER:                sResult=QString("operator ->");         break;
        case OP_DEREFERENCE:            sResult=QString("operator *");          break;
        case OP_INCREMENT:              sResult=QString("operator ++");         break;
        case OP_DECREMENT:              sResult=QString("operator --");         break;
        case OP_MINUS:                  sResult=QString("operator -");          break;
        case OP_PLUS:                   sResult=QString("operator +");          break;
        case OP_BITWISEAND:             sResult=QString("operator &");          break;
        case OP_MEMBERPOINTER:          sResult=QString("operator ->*");        break;
        case OP_DIVIDE:                 sResult=QString("operator /");          break;
        case OP_MODULUS:                sResult=QString("operator %");          break;
        case OP_LESSTHAN:               sResult=QString("operator <");          break;
        case OP_LESSTHANEQUAL:          sResult=QString("operator <=");         break;
        case OP_GREATERTHAN:            sResult=QString("operator >");          break;
        case OP_GREATERTHANEQUAL:       sResult=QString("operator >=");         break;
        case OP_COMMA:                  sResult=QString("operator ,");          break;
        case OP_PARENS:                 sResult=QString("operator ()");         break;
        case OP_BITWISENOT:             sResult=QString("operator ~");          break;
        case OP_BITWISEXOR:             sResult=QString("operator ^");          break;
        case OP_BITWISEOR:              sResult=QString("operator |");          break;
        case OP_LOGICALAND:             sResult=QString("operator &&");         break;
        case OP_LOGICALOR:              sResult=QString("operator ||");         break;
        case OP_TIMESEQUAL:             sResult=QString("operator *=");         break;
        case OP_PLUSEQUAL:              sResult=QString("operator +=");         break;
        case OP_MINUSEQUAL:             sResult=QString("operator -=");         break;
        case OP_DIVEQUAL:               sResult=QString("operator /=");         break;
        case OP_MODEQUAL:               sResult=QString("operator %=");         break;
        case OP_RSHEQUAL:               sResult=QString("operator >>=");        break;
        case OP_LSHEQUAL:               sResult=QString("operator <<=");        break;
        case OP_BITWISEANDEQUAL:        sResult=QString("operator &=");         break;
        case OP_BITWISEOREQUAL:         sResult=QString("operator |=");         break;
        case OP_BITWISEXOREQUAL:        sResult=QString("operator ^=");         break;
        case OP_ARRAYNEW:               sResult=QString("operator new[]");      break;
        case OP_ARRAYDELETE:            sResult=QString("operator delete[]");   break;
    }

    return sResult;
}

XDemangle::SYNTAX XDemangle::getSyntaxFromMode(XDemangle::MODE mode)
{
    SYNTAX result=SYNTAX_UNKNOWN;

    if((mode==MODE_MSVC32)||(mode==MODE_MSVC64))
    {
        result=SYNTAX_MS;
    }

    return result;
}

XDemangle::SYMBOL XDemangle::getSymbol(QString sString, XDemangle::MODE mode)
{
    SYMBOL result={};

    result.mode=mode;

    QMap<QString,qint32> mapParamMods=getParamMods(mode);
    QMap<QString,qint32> mapObjectClasses=getObjectClasses(mode);
    QMap<QString,qint32> mapTypes=getTypes(mode);
    QMap<QString,qint32> mapStorageClasses=getStorageClasses(mode);
    QMap<QString,qint32> mapFunctionMods=getFunctionMods(mode);
    QMap<QString,qint32> mapFunctionConventions=getFunctionConventions(mode);
    QMap<QString,qint32> mapOperators=getOperators(mode);
    QMap<QString,qint32> mapIndexes=getIndexes(mode);

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
    {
        if(_compare(sString,"?"))
        {
            sString=sString.mid(1,-1);

            if(isSignaturePresent(sString,&mapOperators))
            {
                SIGNATURE signatureOP=getSignature(sString,&mapOperators);
                result._operator=(OP)signatureOP.nValue;
                sString=sString.mid(signatureOP.nSize,-1);
            }

            // Name
            while(sString!="")
            {
                STRING _string=readString(sString,mode);

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
            // Reverse
            int nNumberOfRecords=result.paramVariable.listNames.count();

            for(int i=0;i<(nNumberOfRecords/2);i++)
            {
                result.listNames.swap(i,nNumberOfRecords-(1+i));
            }

            if(isSignaturePresent(sString,&mapObjectClasses))
            {
                result.symbolType=ST_VARIABLE;

                SIGNATURE signatureOC=getSignature(sString,&mapObjectClasses);
                result.objectClass=(OC)signatureOC.nValue;
                sString=sString.mid(signatureOC.nSize,-1);
            }
            else if(isSignaturePresent(sString,&mapFunctionMods))
            {
                result.symbolType=ST_FUNCTION;

                SIGNATURE signatureFM=getSignature(sString,&mapFunctionMods);
                result.functionMod=(FM)signatureFM.nValue;
                sString=sString.mid(signatureFM.nSize,-1);

                if((result.functionMod!=FM_FAR)&&(result.functionMod!=FM_NEAR)) // Class member
                {
                    if(isSignaturePresent(sString,&mapStorageClasses))
                    {
                        SIGNATURE signatureSC=getSignature(sString,&mapStorageClasses);
                        result.paramVariable.storageClass=(SC)signatureSC.nValue;
                        sString=sString.mid(signatureSC.nSize,-1);
                    }
                }

                if(isSignaturePresent(sString,&mapFunctionConventions))
                {
                    SIGNATURE signature=getSignature(sString,&mapFunctionConventions);
                    result.functionConvention=(FC)signature.nValue;
                    sString=sString.mid(signature.nSize,-1);
                }
                else
                {
                     result.functionConvention=FC_THISCALL; // TODO Check
                }
            }

            int nIndex=0;

            QMap<QString,qint32> mapArgs;

            while(sString!="")
            {
                qint32 _nPrefixCount=0;

                if((nIndex>0)&&(_compare(sString,"@")))
                {
                    sString=sString.mid(1,-1);
                    break;
                }

                if(isSignaturePresent(sString,&mapIndexes))
                {
                    SIGNATURE signatureIndex=getSignature(sString,&mapIndexes);

                    QList<QString> list=mapArgs.keys(signatureIndex.nValue);

                    if(list.count()>0)
                    {
                        sString=sString.mid(signatureIndex.nSize,-1);
                        sString.prepend(list.at(0));
                    }
                }

                QString _sString=sString;

                SIGNATURE signatureParamMod={};
                SIGNATURE signatureStorageClass={};

                if(isSignaturePresent(sString,&mapParamMods))
                {
                    signatureParamMod=getSignature(sString,&mapParamMods);
                    sString=sString.mid(signatureParamMod.nSize,-1);
                    _nPrefixCount+=signatureParamMod.nSize;

                    signatureStorageClass=getSignature(sString,&mapStorageClasses);
                    sString=sString.mid(signatureStorageClass.nSize,-1);
                    _nPrefixCount+=signatureStorageClass.nSize;
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
                        result.paramVariable=parameter;
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
                _nPrefixCount+=signatureType.nSize;

                if(nIndex>0)
                {
                    if(_nPrefixCount>1)
                    {
                        QString sArg=_sString.left(_nPrefixCount);

                        if(!mapArgs.contains(sArg))
                        {
                            int nCount=mapArgs.count();
                            mapArgs.insert(sArg,nCount);
                        }
                    }
                }

                if((nIndex>0)&&(signatureType.nValue==(TYPE)TYPE_VOID)) //if func(void)
                {
                    if(_compare(sString,"@"))
                    {
                        sString=sString.mid(1,-1);
                    }

                    break;
                }

                nIndex++;
            }

            if(isSignaturePresent(sString,&mapStorageClasses))
            {
                SIGNATURE signature=getSignature(sString,&mapStorageClasses);
                if(result.paramVariable.storageClass==SC_UNKNOWN)
                {
                    result.paramVariable.storageClass=(SC)signature.nValue;
                }

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

    if(_compare(sString,"?")&&(sString.contains("@")))
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
    listResult.append(MODE_BORLAND32);
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
        else if((symbol.symbolType==ST_FUNCTION))
        {
            QString sParameterReturn=getStringFromParameter(symbol.paramVariable,symbol.mode);
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
    {
        mapResult.insert("@",TYPE_EMPTY);
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
    {
        mapResult.insert("P",PM_POINTER);
        mapResult.insert("A",PM_REFERENCE);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getStorageClasses(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
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

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
    {
        mapResult.insert("?0",OP_CONSTRUCTOR);
        mapResult.insert("?1",OP_DESTRUCTOR);
        mapResult.insert("?2",OP_NEW);
        mapResult.insert("?3",OP_DELETE);
        mapResult.insert("?4",OP_ASSIGN);
        mapResult.insert("?5",OP_RIGHTSHIFT);
        mapResult.insert("?6",OP_LEFTSHIFT);
        mapResult.insert("?7",OP_LOGICALNOT);
        mapResult.insert("?8",OP_EQUALS);
        mapResult.insert("?9",OP_NOTEQUALS);
        mapResult.insert("?A",OP_ARRAYSUBSCRIPT);
        mapResult.insert("?C",OP_POINTER);
        mapResult.insert("?D",OP_DEREFERENCE);
        mapResult.insert("?E",OP_INCREMENT);
        mapResult.insert("?F",OP_DECREMENT);
        mapResult.insert("?G",OP_MINUS);
        mapResult.insert("?H",OP_PLUS);
        mapResult.insert("?I",OP_BITWISEAND);
        mapResult.insert("?J",OP_MEMBERPOINTER);
        mapResult.insert("?K",OP_DIVIDE);
        mapResult.insert("?L",OP_MODULUS);
        mapResult.insert("?M",OP_LESSTHAN);
        mapResult.insert("?N",OP_LESSTHANEQUAL);
        mapResult.insert("?O",OP_GREATERTHAN);
        mapResult.insert("?P",OP_GREATERTHANEQUAL);
        mapResult.insert("?Q",OP_COMMA);
        mapResult.insert("?R",OP_PARENS);
        mapResult.insert("?S",OP_BITWISENOT);
        mapResult.insert("?T",OP_BITWISEXOR);
        mapResult.insert("?U",OP_BITWISEOR);
        mapResult.insert("?V",OP_LOGICALAND);
        mapResult.insert("?W",OP_LOGICALOR);
        mapResult.insert("?X",OP_TIMESEQUAL);
        mapResult.insert("?Y",OP_PLUSEQUAL);
        mapResult.insert("?Z",OP_MINUSEQUAL);
        mapResult.insert("?_0",OP_DIVEQUAL);
        mapResult.insert("?_1",OP_MODEQUAL);
        mapResult.insert("?_2",OP_RSHEQUAL);
        mapResult.insert("?_3",OP_LSHEQUAL);
        mapResult.insert("?_4",OP_BITWISEANDEQUAL);
        mapResult.insert("?_5",OP_BITWISEOREQUAL);
        mapResult.insert("?_6",OP_BITWISEXOREQUAL);
        mapResult.insert("?_U",OP_ARRAYNEW);
        mapResult.insert("?_V",OP_ARRAYDELETE);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getIndexes(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MS)
    {
        mapResult.insert("0",0);
        mapResult.insert("1",1);
        mapResult.insert("2",2);
        mapResult.insert("3",3);
        mapResult.insert("4",4);
        mapResult.insert("5",5);
        mapResult.insert("6",6);
        mapResult.insert("7",7);
        mapResult.insert("8",8);
        mapResult.insert("9",9);
    }

    return mapResult;
}

QString XDemangle::getNameFromSymbol(XDemangle::SYMBOL symbol)
{
    QString sResult;

    int nNumberOfNames=symbol.listNames.count();

    for(int i=0;i<nNumberOfNames;i++)
    {
        sResult+=symbol.listNames.at(i);

        if(i!=(nNumberOfNames-1))
        {
            sResult+="::";
        }
    }

    if(symbol._operator!=OP_UNKNOWN)
    {
        sResult+=QString("::%1").arg(operatorIdToString(symbol._operator,symbol.mode));

        if((symbol._operator==OP_CONSTRUCTOR)||(symbol._operator==OP_DESTRUCTOR))
        {
            if(nNumberOfNames)
            {
                sResult+=symbol.listNames.at(nNumberOfNames-1);
            }
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
