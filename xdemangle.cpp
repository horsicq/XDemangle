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
        case MODE_MSVC:         sResult=QString("MSVC+++");             break;
        case MODE_MSVC32:       sResult=QString("MSVC+++ 32");          break;
        case MODE_GCC:          sResult=QString("GNU C++");             break;
        case MODE_WATCOM:       sResult=QString("Watcom");              break;
        case MODE_BORLAND32:    sResult=QString("Borland 32");          break;
        case MODE_BORLAND64:    sResult=QString("Borland 64");          break;
    }

    return sResult;
}

QString XDemangle::typeIdToString(XDemangle::TYPE type, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(type)
    {
        case TYPE_UNKNOWN:          sResult=QString("");                    break;
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
        case TYPE_INT64:
            if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
            {
                sResult=QString("__int64");
            }
            else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
            {
                sResult=QString("long long");
            }
            break; // TODO Check !!!
        case TYPE_UINT64:
            if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
            {
                sResult=QString("unsigned __int64");
            }
            else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
            {
                sResult=QString("unsigned long long");
            }
            break; // TODO Check !!!
        case TYPE_CHAR8:            sResult=QString("char8_t");             break;
        case TYPE_CHAR16:           sResult=QString("char16_t");            break;
        case TYPE_CHAR32:           sResult=QString("char32_t");            break;
        case TYPE_WCHAR:            sResult=QString("wchar_t");             break;
        case TYPE_VARARGS:          sResult=QString("...");                 break;
        case TYPE_CLASS:            sResult=QString("class");               break;
        case TYPE_UNION:            sResult=QString("union");               break;
        case TYPE_STRUCT:           sResult=QString("struct");              break;
        case TYPE_ENUM:             sResult=QString("enum");                break;
        case TYPE_POINTERTOFUNCTION:sResult=QString("");                    break;
        case TYPE_NULLPTR:          sResult=QString("std::nullptr_t");      break; // TODO Check !!!
    }

    return sResult;
}

QString XDemangle::storageClassIdToString(XDemangle::SC storageClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(storageClass)
    {
        case SC_UNKNOWN:            sResult=QString("");                    break;
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
        case OC_PRIVATESTATICCLASSMEMBER:   sResult=QString("private: static");     break;
        case OC_PROTECTEDSTATICCLASSMEMBER: sResult=QString("protected: static");   break;
        case OC_PUBLICSTATICCLASSMEMBER:    sResult=QString("public: static");      break;
    }

    return sResult;
}

QString XDemangle::paramModIdToString(XDemangle::PM paramMod, XDemangle::MODE mode)
{
    QString sResult="Unknown"; // mb TODO translate

    switch(paramMod)
    {
        case PM_NONE:                   sResult=QString("");                    break; // mb TODO translate
        case PM_POINTER:                sResult=QString("*");                   break;
        case PM_REFERENCE:              sResult=QString("&");                   break;
        case PM_POINTERCONST:           sResult=QString("*const");              break;
        case PM_POINTERVOLATILE:        sResult=QString("*volatile");           break;
        case PM_POINTERCONSTVOLATILE:   sResult=QString("*const volatile");     break;
        case PM_DOUBLEREFERENCE:        sResult=QString("&&");                  break;
    }

    return sResult;
}

QString XDemangle::functionModIdToString(XDemangle::FM functionMod, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(functionMod)
    {
        case FM_UNKNOWN:                sResult=QString("Unknown");             break; // mb TODO translate
        case FM_NEAR:                   sResult=QString("");                    break;
        case FM_FAR:                    sResult=QString("");                    break;
        case FM_PUBLIC_NEAR:            sResult=QString("public:");             break;
        case FM_PUBLIC_FAR:             sResult=QString("public:");             break;
        case FM_PUBLIC_STATICNEAR:      sResult=QString("public: static");      break;
        case FM_PUBLIC_STATICFAR:       sResult=QString("public: static");      break;
        case FM_PUBLIC_VIRTUALNEAR:     sResult=QString("public: virtual");     break;
        case FM_PUBLIC_VIRTUALFAR:      sResult=QString("public: virtual");     break;
        case FM_PROTECTED_NEAR:         sResult=QString("protected:");          break;
        case FM_PROTECTED_FAR:          sResult=QString("protected:");          break;
        case FM_PROTECTED_STATICNEAR:   sResult=QString("protected: static");   break;
        case FM_PROTECTED_STATICFAR:    sResult=QString("protected: static");   break;
        case FM_PROTECTED_VIRTUALNEAR:  sResult=QString("protected: virtual");  break;
        case FM_PROTECTED_VIRTUALFAR:   sResult=QString("protected: virtual");  break;
        case FM_PRIVATE_NEAR:           sResult=QString("private:");            break;
        case FM_PRIVATE_FAR:            sResult=QString("private:");            break;
        case FM_PRIVATE_STATICNEAR:     sResult=QString("private: static");     break;
        case FM_PRIVATE_STATICFAR:      sResult=QString("private: static");     break;
        case FM_PRIVATE_VIRTUALNEAR:    sResult=QString("private: virtual");    break;
        case FM_PRIVATE_VIRTUALFAR:     sResult=QString("private: virtual");    break;
    }

    return sResult;
}

QString XDemangle::functionConventionIdToString(XDemangle::FC functionConvention, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(functionConvention)
    {
        case FC_UNKNOWN:            sResult=QString("Unknown");                     break; // mb TODO translate
        case FC_NONE:               sResult=QString("");                            break;
        case FC_CDECL:              sResult=QString("__cdecl");                     break;
        case FC_THISCALL:           sResult=QString("__thiscall");                  break;
        case FC_STDCALL:            sResult=QString("__stdcall");                   break;
        case FC_FASTCALL:           sResult=QString("__fastcall");                  break;
        case FC_CLRCALL:            sResult=QString("__clrcall");                   break;
        case FC_VECTORCALL:         sResult=QString("__vectorcall");                break;
    }

    return sResult;
}

QString XDemangle::operatorIdToString(XDemangle::OP _operator, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(_operator)
    {
        case OP_UNKNOWN:                sResult=QString("Unknown");                         break; // mb TODO translate
        case OP_CONSTRUCTOR:            sResult=QString("");                                break;
        case OP_DESTRUCTOR:             sResult=QString("~");                               break;
        case OP_NEW:                    sResult=QString("operator new");                    break;
        case OP_DELETE:                 sResult=QString("operator delete");                 break;
        case OP_ASSIGN:                 sResult=QString("operator=");                       break;
        case OP_RIGHTSHIFT:             sResult=QString("operator>>");                      break;
        case OP_LEFTSHIFT:              sResult=QString("operator<<");                      break;
        case OP_LOGICALNOT:             sResult=QString("operator!");                       break;
        case OP_EQUALS:                 sResult=QString("operator==");                      break;
        case OP_NOTEQUALS:              sResult=QString("operator!=");                      break;
        case OP_ARRAYSUBSCRIPT:         sResult=QString("operator[]");                      break;
        case OP_POINTER:                sResult=QString("operator->");                      break;
        case OP_DEREFERENCE:            sResult=QString("operator*");                       break;
        case OP_INCREMENT:              sResult=QString("operator++");                      break;
        case OP_DECREMENT:              sResult=QString("operator--");                      break;
        case OP_MINUS:                  sResult=QString("operator-");                       break;
        case OP_PLUS:                   sResult=QString("operator+");                       break;
        case OP_BITWISEAND:             sResult=QString("operator&");                       break;
        case OP_MEMBERPOINTER:          sResult=QString("operator->*");                     break;
        case OP_DIVIDE:                 sResult=QString("operator/");                       break;
        case OP_MODULUS:                sResult=QString("operator%");                       break;
        case OP_LESSTHAN:               sResult=QString("operator<");                       break;
        case OP_LESSTHANEQUAL:          sResult=QString("operator<=");                      break;
        case OP_GREATERTHAN:            sResult=QString("operator>");                       break;
        case OP_GREATERTHANEQUAL:       sResult=QString("operator>=");                      break;
        case OP_COMMA:                  sResult=QString("operator,");                       break;
        case OP_PARENS:                 sResult=QString("operator()");                      break;
        case OP_BITWISENOT:             sResult=QString("operator~");                       break;
        case OP_BITWISEXOR:             sResult=QString("operator^");                       break;
        case OP_BITWISEOR:              sResult=QString("operator|");                       break;
        case OP_LOGICALAND:             sResult=QString("operator&&");                      break;
        case OP_LOGICALOR:              sResult=QString("operator||");                      break;
        case OP_TIMESEQUAL:             sResult=QString("operator*=");                      break;
        case OP_PLUSEQUAL:              sResult=QString("operator+=");                      break;
        case OP_MINUSEQUAL:             sResult=QString("operator-=");                      break;
        case OP_DIVEQUAL:               sResult=QString("operator/=");                      break;
        case OP_MODEQUAL:               sResult=QString("operator%=");                      break;
        case OP_RSHEQUAL:               sResult=QString("operator>>=");                     break;
        case OP_LSHEQUAL:               sResult=QString("operator<<=");                     break;
        case OP_BITWISEANDEQUAL:        sResult=QString("operator&=");                      break;
        case OP_BITWISEOREQUAL:         sResult=QString("operator|=");                      break;
        case OP_BITWISEXOREQUAL:        sResult=QString("operator^=");                      break;
        case OP_VIRTUALTABLE:           sResult=QString("`vftable'");                       break;
        case OP_VBTABLE:                sResult=QString("`vbtable'");                       break;
        case OP_VBASEDTOR:              sResult=QString("`vbase dtor'");                    break;
        case OP_VECDELDTOR:             sResult=QString("`vector deleting dtor'");          break;
        case OP_DEFAULTCTORCLOSURE:     sResult=QString("`default ctor closure'");          break;
        case OP_SCALARDELDTOR:          sResult=QString("`scalar deleting dtor'");          break;
        case OP_VECCTORITER:            sResult=QString("`vector ctor iterator'");          break;
        case OP_VECDTORITER:            sResult=QString("`vector dtor iterator'");          break;
        case OP_VECVBASECTORITER:       sResult=QString("`vector vbase ctor iterator'");    break;
        case OP_VDISPMAP:               sResult=QString("`virtual displacement map'");      break;
        case OP_EHVECCTORITER:          sResult=QString("`eh vector ctor iterator'");       break;
        case OP_EHVECDTORITER:          sResult=QString("`eh vector dtor iterator'");       break;
        case OP_EHVECVBASECTORITER:     sResult=QString("`eh vector vbase ctor iterator'"); break;
        case OP_COPYCTORCLOSURE:        sResult=QString("`copy ctor closure'");             break;
        case OP_ARRAYNEW:               sResult=QString("operator new[]");                  break;
        case OP_ARRAYDELETE:            sResult=QString("operator delete[]");               break;
        case OP_TYPE:                   sResult=QString("operator ");                       break;
    }

    return sResult;
}

XDemangle::SYNTAX XDemangle::getSyntaxFromMode(XDemangle::MODE mode)
{
    SYNTAX result=SYNTAX_UNKNOWN;

    if((mode==MODE_MSVC32)||(mode==MODE_MSVC64)||(mode==MODE_MSVC))
    {
        result=SYNTAX_MICROSOFT;
    }
    if(mode==MODE_GCC)
    {
        result=SYNTAX_ITANIUM;
    }

    return result;
}

XDemangle::SYMBOL XDemangle::getSymbol(QString sString, XDemangle::MODE mode)
{
    SYMBOL result={};

    HDATA hdata=getHdata(mode);

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        result=Microsoft_handle(&hdata,sString,mode);
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        result=Itanium_handle(&hdata,sString,mode);
    }

    return result;
}

QString XDemangle::convert(QString sString, MODE mode)
{
    QString sResult;

    if(sString!="")
    {
        SYMBOL symbol=getSymbol(sString,mode);

        if(symbol.bValid)
        {
            sResult=symbolToString(symbol);
        }
        else
        {
            sResult=sString;
        }
    }

    return sResult;
}

qint32 XDemangle::Microsoft_handleParams(HDATA *pHdata, QString sString, XDemangle::MODE mode, QList<XDemangle::PARAMETER> *pListParameters, qint32 nLimit, QList<QString> *pListStringRefs,QList<QString> *plistArgRefs)
{
    qint32 nResult=0;

    int nIndex=0;

    while(sString!="")
    {
        PARAMETER parameter={};

        bool bBreak=false;

        QString _sString=sString;
        qint32 nStringSize=nResult;

        if((nLimit)&&(nIndex>=nLimit))
        {
            break;
        }

        if((nIndex>0)&&(_compare(sString,"@")))
        {
            break;
        }

        bool bAddToRecord=true;

        if(isSignaturePresent(sString,&(pHdata->mapNumbers)))
        {
            SIGNATURE signatureIndex=getSignature(sString,&(pHdata->mapNumbers));

            if(signatureIndex.nValue<plistArgRefs->count())
            {
                QString sRecord=plistArgRefs->at(signatureIndex.nValue);
                sString=sString.replace(0,signatureIndex.nSize,sRecord);
                bAddToRecord=false;
                nResult++;
            }
            else
            {
            #ifdef QT_DEBUG
                qDebug("ERROR ArgRefs");
            #endif
            }
        }

        bool bFunction=false;

        if(_compare(sString,"P6")) // Pointer to a function
        {
            parameter.type=TYPE_POINTERTOFUNCTION;
            bFunction=true;

            if(bAddToRecord)
            {
                nResult+=2;
            }

            sString=sString.mid(2,-1);
        }
        else if(_compare(sString,"AAP6")) // Pointer to a function
        {
            parameter.type=TYPE_POINTERTOFUNCTIONREF;
            bFunction=true;

            if(bAddToRecord)
            {
                nResult+=4;
            }

            sString=sString.mid(4,-1);
        }
        if(_compare(sString,"$$A6")) // Function
        {
            parameter.type=TYPE_FUNCTION;
            bFunction=true;

            if(bAddToRecord)
            {
                nResult+=4;
            }

            sString=sString.mid(4,-1);
        }
        if(_compare(sString,"P8")) // Member
        {
            parameter.type=TYPE_MEMBER;
            bFunction=true;

            if(bAddToRecord)
            {
                nResult+=2;
            }

            sString=sString.mid(2,-1);

//            QList<QString> _ListStringRefs;
//            QList<QString> _ListArgRefs;
//            qint32 nNamesSize=handleParamStrings(pHdata,sString,mode,&parameter,&_ListStringRefs,&_ListArgRefs);
            qint32 nNamesSize=Microsoft_handleParamStrings(pHdata,sString,mode,&parameter,pListStringRefs,plistArgRefs,false);

            if(bAddToRecord)
            {
                nResult+=nNamesSize;
            }

            sString=sString.mid(nNamesSize,-1);
        }

        if(bFunction) // Pointer to a function
        {
            if((parameter.type==TYPE_POINTERTOFUNCTION)||(parameter.type==TYPE_POINTERTOFUNCTIONREF)||(parameter.type==TYPE_FUNCTION))
            {
                if(isSignaturePresent(sString,&(pHdata->mapFunctionConventions)))
                {
                    SIGNATURE signature=getSignature(sString,&(pHdata->mapFunctionConventions));
                    parameter.functionConvention=(FC)signature.nValue;

                    if(bAddToRecord)
                    {
                        nResult+=signature.nSize;
                    }

                    sString=sString.mid(signature.nSize,-1);
                }
            }
            else if(parameter.type==TYPE_MEMBER)
            {
                parameter.functionConvention=FC_THISCALL; // TODO Check
            }

            if((mode==MODE_MSVC)||(mode==MODE_MSVC64))
            {
                if(_compare(sString,"E"))
                {
                    if(bAddToRecord)
                    {
                        nResult++;
                    }

                    sString=sString.mid(1,-1);
                }
            }

            qint32 nPSize=Microsoft_handleParams(pHdata,sString,mode,&(parameter.listFunctionParameters),0,pListStringRefs,plistArgRefs);

            if(bAddToRecord)
            {
                nResult+=nPSize;
            }

            sString=sString.mid(nPSize,-1);

            if(_compare(sString,"@"))
            {
                if(bAddToRecord)
                {
                    nResult++;
                }

                sString=sString.mid(1,-1);
            }

            if(_compare(sString,"Z"))
            {
                if(bAddToRecord)
                {
                    nResult++;
                }

                sString=sString.mid(1,-1);
            }
        }
        else if(_compare(sString,"$0")) // const
        {
            parameter.type=TYPE_CONST;

            if(bAddToRecord)
            {
                nResult+=2;
            }

            sString=sString.mid(2,-1);

            NUMBER number=readNumber(pHdata,sString,mode);

            parameter.nConstValue=number.nValue;

            if(bAddToRecord)
            {
                nResult+=number.nSize;
            }

            sString=sString.mid(number.nSize,-1);
        }
        else
        {
            bool bMod=false;

            while(sString!="")
            {
                // TODO names
                if(isSignaturePresent(sString,&(pHdata->mapParamMods)))
                {
                    SIGNATURE signatureParamMod=getSignature(sString,&(pHdata->mapParamMods));

                    if(bAddToRecord)
                    {
                        nResult+=signatureParamMod.nSize;
                    }

                    sString=sString.mid(signatureParamMod.nSize,-1);

                    if(signatureParamMod.nSize)
                    {
                        if((mode==MODE_MSVC)||(mode==MODE_MSVC64))
                        {
                            if(_compare(sString,"E"))
                            {
                                if(bAddToRecord)
                                {
                                    nResult++;
                                }

                                sString=sString.mid(1,-1);
                            }
                        }
                    }

                    SIGNATURE signatureStorageClass=getSignature(sString,&(pHdata->mapStorageClasses));

                    if(bAddToRecord)
                    {
                        nResult+=signatureStorageClass.nSize;
                    }

                    sString=sString.mid(signatureStorageClass.nSize,-1);

                    PARAMETER mod={};
                    mod.paramMod=(PM)signatureParamMod.nValue;
                    mod.storageClass=(SC)signatureStorageClass.nValue;

                    if(isSignaturePresent(sString,&(pHdata->mapNumbers)))
                    {
                        // TODO Check
                        qint32 nNamesSize=Microsoft_handleParamStrings(pHdata,sString,mode,&mod,pListStringRefs,plistArgRefs,false);

                        if(bAddToRecord)
                        {
                            nResult+=nNamesSize;
                        }

                        sString=sString.mid(nNamesSize,-1);
                    }

                    parameter.listMods.append(mod);

                    bMod=true;
                }
                else
                {
                    break;
                }
            }

            if(bMod)
            {
                reverseList(&(parameter.listMods));
            }

            if(!bMod)
            {
                PARAMETER mod={};
                mod.storageClass=SC_NEAR;

                parameter.listMods.append(mod);
            }

            if(bMod)
            {
                if(_compare(sString,"Y"))
                {
                    // Array
                    sString=sString.mid(1,-1);

                    if(bAddToRecord)
                    {
                        nResult++;
                    }

                    while(true)
                    {
                        NUMBER number=readNumber(pHdata,sString,mode);

                        if(number.nSize)
                        {
                            parameter.listIndexes.append(number.nValue);

                            sString=sString.mid(number.nSize,-1);

                            if(bAddToRecord)
                            {
                                nResult+=number.nSize;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            if(_compare(sString,"$$C"))
            {
                sString=sString.mid(3,-1);

                if(bAddToRecord)
                {
                    nResult+=3;
                }

                SIGNATURE signatureStorageClass=getSignature(sString,&(pHdata->mapStorageClasses));

                if(bAddToRecord)
                {
                    nResult+=signatureStorageClass.nSize;
                }

                sString=sString.mid(signatureStorageClass.nSize,-1);

                parameter.extraStorageClass=(SC)signatureStorageClass.nValue;
            }

            SIGNATURE signatureType={};

            if(isSignaturePresent(sString,&(pHdata->mapTypes)))
            {
                signatureType=getSignature(sString,&(pHdata->mapTypes));

                if(bAddToRecord)
                {
                    nResult+=signatureType.nSize;
                }

                sString=sString.mid(signatureType.nSize,-1);
            }
            else if(isSignaturePresent(sString,&(pHdata->mapNameTypes)))
            {
                signatureType=getSignature(sString,&(pHdata->mapNameTypes));

                if(bAddToRecord)
                {
                    nResult+=signatureType.nSize;
                }

                sString=sString.mid(signatureType.nSize,-1);

                qint32 nNamesSize=Microsoft_handleParamStrings(pHdata,sString,mode,&parameter,pListStringRefs,plistArgRefs,false);

                if(bAddToRecord)
                {
                    nResult+=nNamesSize;
                }

                sString=sString.mid(nNamesSize,-1);
            }

            parameter.type=(TYPE)signatureType.nValue;

            if(!signatureType.nSize)
            {
                break;
            }

            if((nIndex>0)&&(signatureType.nValue==(TYPE)TYPE_VOID)&&(!bMod)) //if func(void) TODO Check! Check void *
            {
                bBreak=true;
            }

            if(signatureType.nValue==(TYPE)TYPE_VARARGS)
            {
                bBreak=true;
            }
        }

        parameter.sRecord=_sString.left(nResult-nStringSize);

        if(parameter.type!=TYPE_UNKNOWN)
        {
            pListParameters->append(parameter);
        }
        else
        {
            break;
        }

        if(nIndex>0) // No return types!
        {
            if(bAddToRecord)
            {
                if(parameter.sRecord.count()>1)
                {
                    QString sArg=parameter.sRecord;

                    if(!(plistArgRefs->contains(sArg)))
                    {
                        plistArgRefs->append(sArg);
                    }
                }
            }
        }

        if(bBreak)
        {
            break;
        }

        nIndex++;
    }

    return nResult;
}

qint32 XDemangle::Microsoft_handleParamStrings(HDATA *pHdata, QString sString, MODE mode, PARAMETER *pParameter, QList<QString> *pListStringRefs, QList<QString> *plistArgRefs, bool bFirst)
{
    qint32 nResult=0;

    qint32 nIndex=0;

    while(sString!="")
    {
        bool bAddToList=true;
        bool bTemplate=false;
        QString sRecord;

        if(isSignaturePresent(sString,&(pHdata->mapNumbers)))
        {
            SIGNATURE signatureIndex=getSignature(sString,&(pHdata->mapNumbers));

            if(signatureIndex.nValue<pListStringRefs->count())
            {
                sString=sString.replace(0,signatureIndex.nSize,pListStringRefs->at(signatureIndex.nValue));

                nResult+=signatureIndex.nSize;

                bAddToList=false;

//            #ifdef QT_DEBUG
//                for(int i=0;i<pListStringRefs->count();i++)
//                {
//                    qDebug(pListStringRefs->at(i).toLatin1().data());
//                }
//            #endif
            }
            else
            {
            #ifdef QT_DEBUG
                qDebug("ERROR Strings");
            #endif
            }
        }

        if(_compare(sString,"?$"))
        {
            // Template
            if(bAddToList)
            {
                nResult+=2;
            }

            sString=sString.mid(2,-1);
            bTemplate=true;
            sRecord+="?$";
        }

        STRING _string=readString(pHdata,sString,mode);

        if(_string.nSize)
        {
            pParameter->listNames.append(_string.sString);
            sRecord+=_string.sString+"@";
        }
        else
        {
            break;
        }

        if(bAddToList)
        {
            nResult+=_string.nSize;
        }

        sString=sString.mid(_string.nSize,-1);

        QString sTemplate;

//        QList<QString> _listStringRefs=*pListStringRefs;
        QList<QString> _listArgRefs=*plistArgRefs;
        QList<QString> _listStringRefs;
//        QList<QString> _listArgRefs;

        QList<PARAMETER> listTemplateParameters;

        if(bTemplate)
        {
            sTemplate=sString;
            
            _listStringRefs.append(sString);
            qint32 nPSize=Microsoft_handleParams(pHdata,sString,mode,&listTemplateParameters,0,&_listStringRefs,&_listArgRefs);
//            qint32 nPSize=handleParams(pHdata,sString,mode,&listTemplateParameters,0,pListStringRefs,pListArgRefs);

            sRecord+=sString.leftRef(nPSize);

            if(bAddToList)
            {
                nResult+=nPSize;
            }

            sString=sString.mid(nPSize,-1);

            if(_compare(sString,"@"))
            {
                sRecord+="@";

                if(bAddToList)
                {
                    nResult++;
                }

                sString=sString.mid(1,-1);
            }
        }

        pParameter->listListTemplateParameters.append(listTemplateParameters);

        if(bAddToList)
        {
            if((!bFirst)||(nIndex)||(!bTemplate))
            {
                if(!(pListStringRefs->contains(sRecord)))
                {
                    pListStringRefs->append(sRecord);
                }
            }

//            if(bTemplate)
//            {
//                int nStringSize=(_listStringRefs.size())-(pListStringRefs->size());
//                int nArgSize=(_listArgRefs.size())-(plistArgRefs->size());

//                if(nStringSize)
//                {
//                    pListStringRefs->append(_listStringRefs.mid(pListStringRefs->size()));
//                }

//                if(nArgSize)
//                {
//                    plistArgRefs->append(_listArgRefs.mid(plistArgRefs->size()));
//                }
//            }
        }

        nIndex++;
    }

    if(_compare(sString,"@"))
    {
        nResult++;
        sString=sString.mid(1,-1);
    }

    // Reverse
    reverseList(&(pParameter->listNames));
    reverseList(&(pParameter->listListTemplateParameters));

    return nResult;
}

XDemangle::MODE XDemangle::detectMode(QString sString)
{
    MODE result=MODE_UNKNOWN;

    if(_compare(sString,"?")&&(sString.contains("@")))
    {
        result=MODE_MSVC;
    }
    else if(_compare(sString,"_Z"))
    {
        result=MODE_GCC;
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

QList<XDemangle::MODE> XDemangle::getSupportedModes()
{
    QList<MODE> listResult;

    listResult.append(MODE_AUTO);

    return listResult;
}

void XDemangle::reverseList(QList<QString> *pList)
{
    int nNumberOfRecords=pList->count();

    for(int i=0;i<(nNumberOfRecords/2);i++)
    {
        pList->swap(i,nNumberOfRecords-(1+i));
    }
}

void XDemangle::reverseList(QList<XDemangle::PARAMETER> *pList)
{
    int nNumberOfRecords=pList->count();

    for(int i=0;i<(nNumberOfRecords/2);i++)
    {
        pList->swap(i,nNumberOfRecords-(1+i));
    }
}

//void XDemangle::reverseList(QList<XDemangle::MOD> *pList)
//{
//    int nNumberOfRecords=pList->count();

//    for(int i=0;i<(nNumberOfRecords/2);i++)
//    {
//        pList->swap(i,nNumberOfRecords-(1+i));
//    }
//}

void XDemangle::reverseList(QList<QList<XDemangle::PARAMETER> > *pListList)
{
    int nNumberOfRecords=pListList->count();

    for(int i=0;i<(nNumberOfRecords/2);i++)
    {
        pListList->swap(i,nNumberOfRecords-(1+i));
    }
}

XDemangle::HDATA XDemangle::getHdata(XDemangle::MODE mode)
{
    XDemangle::HDATA result={};

    result.mapParamMods=getParamMods(mode);
    result.mapObjectClasses=getObjectClasses(mode);
    result.mapTypes=getTypes(mode);
    result.mapNameTypes=getNameTypes(mode);
    result.mapStorageClasses=getStorageClasses(mode);
    result.mapFunctionMods=getFunctionMods(mode);
    result.mapFunctionConventions=getFunctionConventions(mode);
    result.mapOperators=getOperators(mode);
    result.mapNumbers=getNumbers(mode);
    result.mapHexNumbers=getHexNumbers(mode);

    return result;
}

QString XDemangle::symbolToString(XDemangle::SYMBOL symbol)
{
    QString sResult;

    if(symbol.bValid)
    {
        if(symbol.symbolType==ST_VARIABLE)
        {
            QString sObjectClass;

            if(symbol.objectClass!=OC_UNKNOWN)
            {
                sObjectClass=objectClassIdToString(symbol.objectClass,symbol.mode);
            }

            QString sParameter;

            QString sName=_getNameFromSymbol(symbol);

            if(symbol.listParameters.count())
            {
                sParameter=_getStringFromParameter(symbol.listParameters.at(0),symbol.mode,sName);
            }
            else
            {
                sParameter=sName;
            }

            if(sObjectClass!="")    sResult+=QString("%1 ").arg(sObjectClass);
            if(sParameter!="")      sResult+=QString("%1").arg(sParameter);
        }
        else if((symbol.symbolType==ST_FUNCTION))
        {
            int nNumberOfArguments=symbol.listParameters.count();

            if(nNumberOfArguments)
            {
                QString sClassStorage=storageClassIdToString(symbol.classStorageClass,symbol.mode);
                QString sFuncMod=functionModIdToString(symbol.functionMod,symbol.mode);
                QString sFunctionConvention=functionConventionIdToString(symbol.functionConvention,symbol.mode);
                QString sFunctionName=_getNameFromSymbol(symbol);

                QString sFunction=sFunctionConvention;

                if(sFunction!="")
                {
                    sFunction+=" ";
                }

                sFunction+=sFunctionName;

                sFunction+=QString("(");

                for(int i=1;i<nNumberOfArguments;i++)
                {
                    bool bEnable=true;

                    if(getSyntaxFromMode(symbol.mode)==SYNTAX_ITANIUM)
                    {
                        if(nNumberOfArguments==2)
                        {
                            if((symbol.listParameters.at(i).listMods.count()==0)&&(symbol.listParameters.at(i).type==TYPE_VOID))
                            {
                                bEnable=false;
                            }
                        }
                    }

                    if(bEnable)
                    {
                        sFunction+=_getStringFromParameter(symbol.listParameters.at(i),symbol.mode);

                        if(i!=nNumberOfArguments-1)
                        {
                            sFunction+=QString(", ");;
                        }
                    }

                }

                sFunction+=QString(")");

                if(symbol.classStorageClass!=SC_UNKNOWN)
                {
                    if(sClassStorage!="") sFunction+=QString(" %1").arg(sClassStorage);
                }

                if(symbol.bRef)
                {
                    sFunction+=QString(" &");
                }
                else if(symbol.bDoubleRef)
                {
                    sFunction+=QString(" &&");
                }

                QString sParameterReturn=_getStringFromParameter(symbol.listParameters.at(0),symbol.mode,sFunction,true);

                if(sFuncMod!="")            sResult+=QString("%1 ").arg(sFuncMod);
                if(sParameterReturn!="")    sResult+=QString("%1").arg(sParameterReturn);
            }
        }
        else if(symbol.symbolType==ST_VTABLE)
        {
            QString sStorage=storageClassIdToString(symbol.storageClass,symbol.mode);
            QString sName=_getNameFromSymbol(symbol);

            if(symbol.storageClass!=SC_UNKNOWN)
            {
                if(sStorage!="") sResult+=QString("%1 ").arg(sStorage);
            }

            sResult+=sName;

            if(symbol.bParamTable)
            {
                sResult+=QString("{for `%1'}").arg(_getStringFromParameter(symbol.paramTable,symbol.mode));
            }
        }

        if(symbol.bExtra)
        {
            sResult=QString("`%1'").arg(sResult);

            if((symbol.extraObjectClass==OC_FUNCTIONLOCALSTATIC)||(symbol.extraObjectClass==OC_GLOBALOBJECT))
            {
                sResult.prepend(QString("%1 %2 %3 ")
                        .arg(typeIdToString(symbol.extraType,symbol.mode))
                        .arg(storageClassIdToString(symbol.extraStorageClass1,symbol.mode))
                        .arg(paramModIdToString(symbol.extraParamMod,symbol.mode)));
            }
        }

        int nNumberOfPreps=symbol.listPreps.count();

        if(nNumberOfPreps)
        {
            for(int i=0;i<nNumberOfPreps;i++)
            {
                sResult+=QString("::%1").arg(symbol.listPreps.at(i));
            }
        }

        sResult+=symbol.sPrep;
    }

    return sResult;
}

XDemangle::STRING XDemangle::readString(HDATA *pHdata,QString sString, XDemangle::MODE mode)
{
    STRING result={};

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
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
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        NUMBER number=readNumber(pHdata,sString,mode);

        if(number.nSize)
        {
            sString=sString.mid(number.nSize,-1);
            result.sString=sString.left(number.nValue);
            result.nSize=number.nSize+result.sString.size();
        }
    }

    return result;
}

XDemangle::NUMBER XDemangle::readNumber(HDATA *pHdata, QString sString, XDemangle::MODE mode)
{
    NUMBER result={};

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        bool bNeg=false;

        if(_compare(sString,"?"))
        {
            sString=sString.mid(1,-1);
            bNeg=true;
        }

        if(isSignaturePresent(sString,&(pHdata->mapNumbers)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapNumbers));

            if(signature.nSize)
            {
                result.nValue=signature.nValue+1;
                result.nSize=1;
            }
        }
        else if(isSignaturePresent(sString,&(pHdata->mapHexNumbers)))
        {
            while((sString!="")&&(!_compare(sString,"@")))
            {
                result.nValue*=16;

                SIGNATURE signature=getSignature(sString,&(pHdata->mapHexNumbers));

                if(signature.nSize)
                {
                    sString=sString.mid(signature.nSize,-1);
                    result.nSize+=signature.nSize;

                    result.nValue+=signature.nValue;
                }
                else
                {
                    break;
                }
            }

            if(_compare(sString,"@Z")) // End of function
            {
                result.nSize=0;
            }
            else if(_compare(sString,"@"))
            {
                sString=sString.mid(1,-1);
                result.nSize++;
            }
            else
            {
                result.nSize=0;
            }
        }

        if((bNeg)&&(result.nSize))
        {
            result.nSize++;
            result.nValue=-(result.nValue);
        }
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        while((sString!="")&&(isSignaturePresent(sString,&(pHdata->mapNumbers))))
        {
            result.nValue*=10;

            SIGNATURE signature=getSignature(sString,&(pHdata->mapNumbers));

            result.nValue+=signature.nValue;

            result.nSize++;

            sString=sString.mid(signature.nSize,-1);
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

QChar XDemangle::_getStringEnd(QString sString)
{
    QChar cResult=QChar(' ');

    if(sString!="")
    {
        cResult=sString.at(sString.size()-1);
    }

    return cResult;
}

QString XDemangle::_removeLastSymbol(QString sString)
{
    if(sString!="")
    {
        sString.resize(sString.size()-1);
    }

    return sString;
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

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("0",OC_PRIVATESTATICCLASSMEMBER);
        mapResult.insert("1",OC_PROTECTEDSTATICCLASSMEMBER);
        mapResult.insert("2",OC_PUBLICSTATICCLASSMEMBER);
        mapResult.insert("3",OC_GLOBALOBJECT);
        mapResult.insert("4",OC_FUNCTIONLOCALSTATIC);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getTypes(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
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
        mapResult.insert("$$T",TYPE_NULLPTR);
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        mapResult.insert("v",TYPE_VOID);
        mapResult.insert("a",TYPE_SCHAR);
        mapResult.insert("c",TYPE_CHAR);
        mapResult.insert("h",TYPE_UCHAR);
        mapResult.insert("s",TYPE_SHORT);
        mapResult.insert("t",TYPE_USHORT);
        mapResult.insert("i",TYPE_INT);
        mapResult.insert("j",TYPE_UINT);
        mapResult.insert("l",TYPE_LONG);
        mapResult.insert("m",TYPE_ULONG);
        mapResult.insert("f",TYPE_FLOAT);
        mapResult.insert("d",TYPE_DOUBLE);
        mapResult.insert("e",TYPE_LONGDOUBLE_64);
        mapResult.insert("z",TYPE_VARARGS);
        mapResult.insert("x",TYPE_INT64);
        mapResult.insert("y",TYPE_UINT64);
        mapResult.insert("b",TYPE_BOOL);
        mapResult.insert("Du",TYPE_CHAR8);
        mapResult.insert("Ds",TYPE_CHAR16);
        mapResult.insert("Di",TYPE_CHAR32);
        mapResult.insert("w",TYPE_WCHAR);
        mapResult.insert("Dn",TYPE_NULLPTR);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getNameTypes(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("T",TYPE_UNION);
        mapResult.insert("U",TYPE_STRUCT);
        mapResult.insert("V",TYPE_CLASS);
        mapResult.insert("W4",TYPE_ENUM);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getParamMods(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("?",PM_NONE); // For classes return
        mapResult.insert("P",PM_POINTER);
        mapResult.insert("A",PM_REFERENCE);
        mapResult.insert("Q",PM_POINTERCONST);
        mapResult.insert("R",PM_POINTERVOLATILE);
        mapResult.insert("S",PM_POINTERCONSTVOLATILE);
        mapResult.insert("$$Q",PM_DOUBLEREFERENCE);
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        mapResult.insert("P",PM_POINTER);
        mapResult.insert("R",PM_REFERENCE);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getStorageClasses(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
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

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("A",FM_PRIVATE_NEAR);
        mapResult.insert("B",FM_PRIVATE_FAR);
        mapResult.insert("C",FM_PRIVATE_STATICNEAR);
        mapResult.insert("D",FM_PRIVATE_STATICFAR);
        mapResult.insert("E",FM_PRIVATE_VIRTUALNEAR);
        mapResult.insert("F",FM_PRIVATE_VIRTUALFAR);
        mapResult.insert("I",FM_PROTECTED_NEAR);
        mapResult.insert("J",FM_PROTECTED_FAR);
        mapResult.insert("K",FM_PROTECTED_STATICNEAR);
        mapResult.insert("L",FM_PROTECTED_STATICFAR);
        mapResult.insert("M",FM_PROTECTED_VIRTUALNEAR);
        mapResult.insert("N",FM_PROTECTED_VIRTUALFAR);
        mapResult.insert("Q",FM_PUBLIC_NEAR);
        mapResult.insert("R",FM_PUBLIC_FAR);
        mapResult.insert("S",FM_PUBLIC_STATICNEAR);
        mapResult.insert("T",FM_PUBLIC_STATICFAR);
        mapResult.insert("U",FM_PUBLIC_VIRTUALNEAR);
        mapResult.insert("V",FM_PUBLIC_VIRTUALFAR);
        mapResult.insert("Y",FM_NEAR);
        mapResult.insert("Z",FM_FAR);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getFunctionConventions(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        if((mode==MODE_MSVC)||(mode==MODE_MSVC32))
        {
            mapResult.insert("A",FC_CDECL);
            mapResult.insert("I",FC_FASTCALL);
        }
        else if(mode==MODE_MSVC64)
        {
            mapResult.insert("A",FC_FASTCALL);
        }

        mapResult.insert("B",FC_CDECL);
        mapResult.insert("C",FC_PASCAL);
        mapResult.insert("D",FC_PASCAL);
        mapResult.insert("E",FC_THISCALL);
        mapResult.insert("F",FC_THISCALL);
        mapResult.insert("G",FC_STDCALL);
        mapResult.insert("H",FC_STDCALL);
        mapResult.insert("J",FC_FASTCALL);
        mapResult.insert("M",FC_CLRCALL);
        mapResult.insert("N",FC_CLRCALL);
        mapResult.insert("O",FC_EABI);
        mapResult.insert("P",FC_EABI);
        mapResult.insert("Q",FC_VECTORCALL);
        mapResult.insert("S",FC_SWIFT);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getOperators(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
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
        mapResult.insert("?B",OP_TYPE);
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
        mapResult.insert("?_7",OP_VIRTUALTABLE);
        mapResult.insert("?_8",OP_VBTABLE);
        mapResult.insert("?_D",OP_VBASEDTOR);
        mapResult.insert("?_E",OP_VECDELDTOR);
        mapResult.insert("?_F",OP_DEFAULTCTORCLOSURE);
        mapResult.insert("?_G",OP_SCALARDELDTOR);
        mapResult.insert("?_H",OP_VECCTORITER);
        mapResult.insert("?_I",OP_VECDTORITER);
        mapResult.insert("?_J",OP_VECVBASECTORITER);
        mapResult.insert("?_K",OP_VDISPMAP);
        mapResult.insert("?_L",OP_EHVECCTORITER);
        mapResult.insert("?_M",OP_EHVECDTORITER);
        mapResult.insert("?_N",OP_EHVECVBASECTORITER);
        mapResult.insert("?_O",OP_COPYCTORCLOSURE);
        mapResult.insert("?_U",OP_ARRAYNEW);
        mapResult.insert("?_V",OP_ARRAYDELETE);
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
//        ::= ps        # + (unary)
//        ::= ng	# - (unary)
//        ::= ad	# & (unary)
//        ::= de	# * (unary)
//        ::= co	# ~
//        ::= pl	# +
//        ::= mi	# -
//        ::= ml	# *
//        ::= dv	# /
//        ::= rm	# %
//        ::= an	# &
//        ::= or	# |
//        ::= eo	# ^
//        ::= aS	# =
//        ::= pL	# +=
//        ::= mI	# -=
//        ::= mL	# *=
//        ::= dV	# /=
//        ::= rM	# %=
//        ::= aN	# &=
//        ::= oR	# |=
//        ::= eO	# ^=
//        ::= ls	# <<
//        ::= rs	# >>
//        ::= lS	# <<=
//        ::= rS	# >>=
//        ::= eq	# ==
//        ::= ne	# !=
//        ::= lt	# <
//        ::= gt	# >
//        ::= le	# <=
//        ::= ge	# >=
//        ::= ss	# <=>
//        ::= nt	# !
//        ::= aa	# &&
//        ::= oo	# ||
//        ::= pp	# ++ (postfix in <expression> context)
//        ::= mm	# -- (postfix in <expression> context)
//        ::= cm	# ,
//        ::= pm	# ->*
//        ::= pt	# ->
//        ::= cl	# ()
//        ::= ix	# []
//        ::= qu	# ?

        mapResult.insert("C1",OP_CONSTRUCTOR);
        mapResult.insert("C2",OP_CONSTRUCTOR);
        mapResult.insert("D1",OP_DESTRUCTOR);
        mapResult.insert("D2",OP_DESTRUCTOR);
        mapResult.insert("nw",OP_NEW);
        mapResult.insert("dl",OP_DELETE);
        mapResult.insert("XXXXX4",OP_ASSIGN);
        mapResult.insert("XXXXX5",OP_RIGHTSHIFT);
        mapResult.insert("XXXXX6",OP_LEFTSHIFT);
        mapResult.insert("XXXXX7",OP_LOGICALNOT);
        mapResult.insert("eq",OP_EQUALS);
        mapResult.insert("XXXXX9",OP_NOTEQUALS);
        mapResult.insert("XXXXXA",OP_ARRAYSUBSCRIPT);
        mapResult.insert("XXXXXB",OP_TYPE);
        mapResult.insert("XXXXXC",OP_POINTER);
        mapResult.insert("XXXXXD",OP_DEREFERENCE);
        mapResult.insert("pp",OP_INCREMENT);
        mapResult.insert("XXXXXF",OP_DECREMENT);
        mapResult.insert("mi",OP_MINUS);
        mapResult.insert("pl",OP_PLUS);
        mapResult.insert("XXXXXI",OP_BITWISEAND);
        mapResult.insert("XXXXXJ",OP_MEMBERPOINTER);
        mapResult.insert("XXXXXK",OP_DIVIDE);
        mapResult.insert("XXXXXL",OP_MODULUS);
        mapResult.insert("XXXXXM",OP_LESSTHAN);
        mapResult.insert("XXXXXN",OP_LESSTHANEQUAL);
        mapResult.insert("XXXXXO",OP_GREATERTHAN);
        mapResult.insert("XXXXXP",OP_GREATERTHANEQUAL);
        mapResult.insert("XXXXXQ",OP_COMMA);
        mapResult.insert("XXXXXR",OP_PARENS);
        mapResult.insert("XXXXXS",OP_BITWISENOT);
        mapResult.insert("eo",OP_BITWISEXOR);
        mapResult.insert("XXXXXU",OP_BITWISEOR);
        mapResult.insert("XXXXXV",OP_LOGICALAND);
        mapResult.insert("XXXXXW",OP_LOGICALOR);
        mapResult.insert("XXXXXX",OP_TIMESEQUAL);
        mapResult.insert("pL",OP_PLUSEQUAL);
        mapResult.insert("XXXXXZ",OP_MINUSEQUAL);
        mapResult.insert("XXXXX_0",OP_DIVEQUAL);
        mapResult.insert("XXXXX_1",OP_MODEQUAL);
        mapResult.insert("XXXXX_2",OP_RSHEQUAL);
        mapResult.insert("XXXXX_3",OP_LSHEQUAL);
        mapResult.insert("XXXXX_4",OP_BITWISEANDEQUAL);
        mapResult.insert("XXXXX_5",OP_BITWISEOREQUAL);
        mapResult.insert("XXXXX_6",OP_BITWISEXOREQUAL);
        mapResult.insert("XXXXX_7",OP_VIRTUALTABLE);
        mapResult.insert("XXXXX_8",OP_VBTABLE);
        mapResult.insert("XXXXX_D",OP_VBASEDTOR);
        mapResult.insert("XXXXX_E",OP_VECDELDTOR);
        mapResult.insert("XXXXX_F",OP_DEFAULTCTORCLOSURE);
        mapResult.insert("XXXXX_G",OP_SCALARDELDTOR);
        mapResult.insert("XXXXX_H",OP_VECCTORITER);
        mapResult.insert("XXXXX_I",OP_VECDTORITER);
        mapResult.insert("XXXXX_J",OP_VECVBASECTORITER);
        mapResult.insert("XXXXX_K",OP_VDISPMAP);
        mapResult.insert("XXXXX_L",OP_EHVECCTORITER);
        mapResult.insert("XXXXX_M",OP_EHVECDTORITER);
        mapResult.insert("XXXXX_N",OP_EHVECVBASECTORITER);
        mapResult.insert("XXXXX_O",OP_COPYCTORCLOSURE);
        mapResult.insert("na",OP_ARRAYNEW);
        mapResult.insert("da",OP_ARRAYDELETE);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getNumbers(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if( (getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)||
        (getSyntaxFromMode(mode)==SYNTAX_ITANIUM))
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

QMap<QString, qint32> XDemangle::getLineNumbers(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("?0??",1);
        mapResult.insert("?1??",2);
        mapResult.insert("?2??",3);
        mapResult.insert("?3??",4);
        mapResult.insert("?4??",5);
        mapResult.insert("?5??",6);
        mapResult.insert("?6??",7);
        mapResult.insert("?7??",8);
        mapResult.insert("?8??",9);
        mapResult.insert("?9??",10);
    }

    return mapResult;
}

QMap<QString, qint32> XDemangle::getHexNumbers(XDemangle::MODE mode)
{
    QMap<QString,qint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("A",0);
        mapResult.insert("B",1);
        mapResult.insert("C",2);
        mapResult.insert("D",3);
        mapResult.insert("E",4);
        mapResult.insert("F",5);
        mapResult.insert("G",6);
        mapResult.insert("H",7);
        mapResult.insert("I",8);
        mapResult.insert("J",9);
        mapResult.insert("K",10);
        mapResult.insert("L",11);
        mapResult.insert("M",12);
        mapResult.insert("N",13);
        mapResult.insert("O",14);
        mapResult.insert("P",15);
    }

    return mapResult;
}

XDemangle::SYMBOL XDemangle::Microsoft_handle(XDemangle::HDATA *pHdata, QString sString, XDemangle::MODE mode)
{
    SYMBOL result={};

    if(_compare(sString,"?"))
    {
        result.mode=mode;

        bool bFirst=true;
        QList<QString> listStringRefs;
        QList<QString> listArgRefs;

        sString=sString.mid(1,-1);

        QString _sString=sString;
        QMap<QString,qint32> mapLineNumbers=getLineNumbers(mode);
        QList<QString> _listPreps;
        QList<QString> _listStringRefs;

        while(_sString!="")
        {
            bool bLine=false;

            QString sRecord;

            if(_compare(_sString,"?_B"))
            {
                sRecord="`local static guard'";
                _sString=_sString.mid(3,-1);
            }
            else if(isSignaturePresent(_sString,&mapLineNumbers))
            {
                SIGNATURE signatureLineNumber=getSignature(_sString,&mapLineNumbers);

                sRecord=QString("`%1'").arg(signatureLineNumber.nValue);

                _sString=_sString.mid(signatureLineNumber.nSize,-1);

                bLine=true;
            }
            else if(isSignaturePresent(_sString,&(pHdata->mapNumbers)))
            {
                SIGNATURE signatureIndex=getSignature(_sString,&(pHdata->mapNumbers));

                if(signatureIndex.nValue<_listStringRefs.count())
                {
                    sRecord=_listStringRefs.at(signatureIndex.nValue);
                }

                _sString=_sString.mid(signatureIndex.nSize,-1);
            }
            else
            {
                STRING _string=readString(pHdata,_sString,mode);
                _sString=_sString.mid(_string.nSize,-1);

                if(_string.sString=="")
                {
                    break;
                }

                if(!_listStringRefs.contains(_string.sString))
                {
                    _listStringRefs.append(_string.sString);
                }

                sRecord=_string.sString;
            }

            _listPreps.append(sRecord);

            if(bLine)
            {
                reverseList(&_listPreps);

                sString=_sString;
                listStringRefs=_listStringRefs;
                result.listPreps=_listPreps;

                break;
            }
        }

        if(isSignaturePresent(sString,&(pHdata->mapOperators)))
        {
            SIGNATURE signatureOP=getSignature(sString,&(pHdata->mapOperators));
            result._operator=(OP)signatureOP.nValue;
            sString=sString.mid(signatureOP.nSize,-1);
            bFirst=false;
        }

        // Name
        qint32 nNamesSize=Microsoft_handleParamStrings(pHdata,sString,mode,&(result.paramMain),&listStringRefs,&listArgRefs,bFirst);

        sString=sString.mid(nNamesSize,-1);

//            if(_compare(sString,"@@@")) // TODO Check !!! Templates params
//            {
//                sString=sString.mid(2,-1);
//            }

        if(isSignaturePresent(sString,&(pHdata->mapObjectClasses)))
        {
            result.symbolType=ST_VARIABLE;

            SIGNATURE signatureOC=getSignature(sString,&(pHdata->mapObjectClasses));
            result.objectClass=(OC)signatureOC.nValue;
            sString=sString.mid(signatureOC.nSize,-1);
        }
        else if(isSignaturePresent(sString,&(pHdata->mapFunctionMods)))
        {
            result.symbolType=ST_FUNCTION;

            SIGNATURE signatureFM=getSignature(sString,&(pHdata->mapFunctionMods));
            result.functionMod=(FM)signatureFM.nValue;
            sString=sString.mid(signatureFM.nSize,-1);

            if( (result.functionMod!=FM_FAR)&&
                (result.functionMod!=FM_NEAR)&&
                (result.functionMod!=FM_PUBLIC_STATICNEAR)&&
                (result.functionMod!=FM_PUBLIC_STATICFAR)&&
                (result.functionMod!=FM_PROTECTED_STATICNEAR)&&
                (result.functionMod!=FM_PROTECTED_STATICFAR)&&
                (result.functionMod!=FM_PRIVATE_STATICNEAR)&&
                (result.functionMod!=FM_PRIVATE_STATICFAR))
            {
                if((mode==MODE_MSVC)||(mode==MODE_MSVC64))
                {
                    if(_compare(sString,"E"))
                    {
                        sString=sString.mid(1,-1);
                    }
                }

                if(_compare(sString,"G"))
                {
                    result.bRef=true;
                    sString=sString.mid(1,-1);
                }
                else if(_compare(sString,"H"))
                {
                    result.bDoubleRef=true;
                    sString=sString.mid(1,-1);
                }

                if(isSignaturePresent(sString,&(pHdata->mapStorageClasses)))
                {
                    SIGNATURE signatureSC=getSignature(sString,&(pHdata->mapStorageClasses));
                    result.classStorageClass=(SC)signatureSC.nValue;
                    sString=sString.mid(signatureSC.nSize,-1);
                }
            }

            if(isSignaturePresent(sString,&(pHdata->mapFunctionConventions)))
            {
                SIGNATURE signature=getSignature(sString,&(pHdata->mapFunctionConventions));
                result.functionConvention=(FC)signature.nValue;
                sString=sString.mid(signature.nSize,-1);
            }
            else
            {
                 result.functionConvention=FC_THISCALL; // TODO Check
            }
        }
        else if(_compare(sString,"6")||_compare(sString,"7")) // VFTABLE VBTABLE
        {
            result.symbolType=ST_VTABLE;
            sString=sString.mid(1,-1);
        }

        qint32 nLimit=0;

        if(result.symbolType==ST_VARIABLE)
        {
            nLimit=1;
        }

        qint32 nSize=Microsoft_handleParams(pHdata,sString,mode,&(result.listParameters),nLimit,&listStringRefs,&listArgRefs);

        sString=sString.mid(nSize,-1);

        if(_compare(sString,"@"))
        {
            sString=sString.mid(1,-1);
        }

        if((mode==MODE_MSVC)||(mode==MODE_MSVC64))
        {
            if(_compare(sString,"E"))
            {
                sString=sString.mid(1,-1);
            }
        }

        if(isSignaturePresent(sString,&(pHdata->mapStorageClasses)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapStorageClasses));

            result.storageClass=(SC)signature.nValue;

            if(result.symbolType==ST_VARIABLE)
            {
                if((result.listParameters.count()==1)&&(result.listParameters.at(0).listMods.count()==1)) // TODO Check
                {
                    result.listParameters[0].listMods[0].storageClass=result.storageClass;
                }
            }

            sString=sString.mid(signature.nSize,-1);
        }

        if(result.symbolType==ST_VTABLE)
        {
            qint32 nPSize=Microsoft_handleParamStrings(pHdata,sString,mode,&(result.paramTable),&listStringRefs,&listArgRefs,false);

            if(nPSize>1)
            {
                result.bParamTable=true;

                sString=sString.mid(nPSize,-1);
            }

            if(_compare(sString,"@"))
            {
                sString=sString.mid(1,-1);
            }
        }

        if(result.storageClass!=SC_UNKNOWN) // TODO more checks
        {
            result.bValid=true;
        }

        if(sString!="")
        {
            if(_compare(sString,"@"))
            {
                sString=sString.mid(1,-1);
            }

            // Extra
            result.bExtra=true;

            if(isSignaturePresent(sString,&(pHdata->mapObjectClasses)))
            {
                SIGNATURE signatureOC=getSignature(sString,&(pHdata->mapObjectClasses));
                result.extraObjectClass=(OC)signatureOC.nValue;
                sString=sString.mid(signatureOC.nSize,-1);

                SIGNATURE signaturePM=getSignature(sString,&(pHdata->mapParamMods));
                result.extraParamMod=(PM)signaturePM.nValue;
                sString=sString.mid(signaturePM.nSize,-1);

                SIGNATURE signatureSC1=getSignature(sString,&(pHdata->mapStorageClasses));
                result.extraStorageClass1=(SC)signatureSC1.nValue;
                sString=sString.mid(signatureSC1.nSize,-1);

                SIGNATURE signatureType=getSignature(sString,&(pHdata->mapTypes));
                result.extraType=(TYPE)signatureType.nValue;
                sString=sString.mid(signatureType.nSize,-1);

                SIGNATURE signatureSC2=getSignature(sString,&(pHdata->mapStorageClasses));
                result.extraStorageClass2=(SC)signatureSC2.nValue;
                sString=sString.mid(signatureSC2.nSize,-1);

                if( (result.extraObjectClass==OC_UNKNOWN)||
                    (result.extraStorageClass1==SC_UNKNOWN)||
                    (result.extraStorageClass2==SC_UNKNOWN))
                {
                    result.bValid=false;
                }
            }
            else if(_compare(sString,"5"))
            {
                sString=sString.mid(1,-1);

                SIGNATURE signatureNumbers=getSignature(sString,&(pHdata->mapNumbers));
                result.sPrep=QString("{%1}").arg(signatureNumbers.nValue+1);
                sString=sString.mid(signatureNumbers.nSize,-1);
            }
        }

        if(sString!="")
        {
        #ifdef QT_DEBUG
            qDebug(sString.toLatin1().data());
        #endif
        }
    }

    return result;
}

XDemangle::SYMBOL XDemangle::Itanium_handle(XDemangle::HDATA *pHdata, QString sString, XDemangle::MODE mode)
{
    SYMBOL result={};

    if(_compare(sString,"@_Z")||_compare(sString,"_Z"))
    {
        result.bValid=true;
        result.mode=mode;
        result.symbolType=ST_VARIABLE;

        bool bNamespace=false;

        if(_compare(sString,"@_Z")) // Fastcall
        {
            sString=sString.mid(3,-1);
        }
        else if(_compare(sString,"_Z"))
        {
            sString=sString.mid(2,-1);
        }

        if(_compare(sString,"N"))
        {
            bNamespace=true;
            sString=sString.mid(1,-1);
        }

        while(sString!="")
        {
            if(isSignaturePresent(sString,&(pHdata->mapOperators)))
            {
                SIGNATURE signatureOperator=getSignature(sString,&(pHdata->mapOperators));

                result._operator=(OP)signatureOperator.nValue;

                sString=sString.mid(signatureOperator.nSize,-1);
            }
            else
            {
                STRING string=readString(pHdata,sString,mode);

                if(string.nSize==0)
                {
                    break;
                }

                result.paramMain.listNames.append(string.sString);

                sString=sString.mid(string.nSize,-1);
            }

            if(!bNamespace)
            {
                break;
            }
        }

        if(bNamespace)
        {
            if(_compare(sString,"E")) // End
            {
                sString=sString.mid(1,-1);
            }
        }

        while(sString!="")
        {
            // TODO sRecord
            bool bParameter=false;
            PARAMETER parameter={};

            while(isSignaturePresent(sString,&(pHdata->mapParamMods)))
            {
                SIGNATURE signatureType=getSignature(sString,&(pHdata->mapParamMods));

                PARAMETER paramMod={};

                paramMod.paramMod=(PM)signatureType.nValue;

                parameter.listMods.append(paramMod);

                sString=sString.mid(signatureType.nSize,-1);
            }

            reverseList(&(parameter.listMods));

            if(isSignaturePresent(sString,&(pHdata->mapTypes)))
            {
                SIGNATURE signatureType=getSignature(sString,&(pHdata->mapTypes));

                parameter.type=(TYPE)signatureType.nValue;

                sString=sString.mid(signatureType.nSize,-1);

                bParameter=true;
            }

            if(bParameter)
            {
                if(result.listParameters.count()==0)
                {
                    result.functionMod=FM_NEAR;
                    result.functionConvention=FC_NONE;
                    result.symbolType=ST_FUNCTION;

                    PARAMETER paramReturn={};

                    paramReturn.type=TYPE_EMPTY;
                    paramReturn.storageClass=SC_NEAR;

                    result.listParameters.append(paramReturn);
                }

                result.listParameters.append(parameter);
            }
            else
            {
                break;
            }
        }
    }

    return result;
}

QString XDemangle::_getNameFromSymbol(XDemangle::SYMBOL symbol)
{
    QString sResult=_getNameFromParameter(&(symbol.paramMain),symbol.mode);

    if(symbol._operator!=OP_UNKNOWN)
    {
        if(sResult!="")
        {
            sResult+="::";
        }

        sResult+=operatorIdToString(symbol._operator,symbol.mode);

        if((symbol._operator==OP_CONSTRUCTOR)||(symbol._operator==OP_DESTRUCTOR))
        {
            int nNumberOfNames=symbol.paramMain.listNames.count();

            if(nNumberOfNames)
            {
                QList<PARAMETER> listTemplates;

                if(symbol.paramMain.listListTemplateParameters.count()>(nNumberOfNames-1))
                {
                    listTemplates=symbol.paramMain.listListTemplateParameters.at(nNumberOfNames-1);
                }

                sResult+=symbol.paramMain.listNames.at(nNumberOfNames-1)+_getTemplatesFromParameters(&listTemplates,symbol.mode);
            }
        }
        else if(symbol._operator==OP_TYPE)
        {
            int nNumberOfTypes=symbol.listParameters.count();

            if(nNumberOfTypes)
            {
                sResult+=_getStringFromParameter(symbol.listParameters.at(0),symbol.mode);
            }
        }
    }

    return sResult;
}

QString XDemangle::_getNameFromParameter(PARAMETER *pParameter, XDemangle::MODE mode)
{
    QString sResult;

    int nNumberOfNames=pParameter->listNames.count();
    int nNumberOfTemplates=pParameter->listListTemplateParameters.count();

    for(int i=0;i<nNumberOfNames;i++)
    {
        sResult+=pParameter->listNames.at(i);

        if(i<nNumberOfTemplates)
        {
            QList<PARAMETER> listParameter=pParameter->listListTemplateParameters.at(i);

            sResult+=_getTemplatesFromParameters(&listParameter,mode);
        }

        if(i!=(nNumberOfNames-1))
        {
            sResult+="::";
        }
    }

    return sResult;
}

QString XDemangle::_getTemplatesFromParameters(QList<PARAMETER> *pListParameters, XDemangle::MODE mode)
{
    QString sResult;

    int nNumberOfTemplates=pListParameters->count();

    if(nNumberOfTemplates)
    {
        sResult+="<";

        for(int i=0;i<nNumberOfTemplates;i++)
        {
            sResult+=_getStringFromParameter(pListParameters->at(i),mode);

            if(i!=(nNumberOfTemplates-1))
            {
                sResult+=", ";
            }
        }

        sResult+=">";
    }

    return sResult;
}

QString XDemangle::_getStringFromParameter(XDemangle::PARAMETER parameter, MODE mode, QString sName, bool bFuncRet)
{
    QString sResult;

    int nNumberOfFunctionParameters=parameter.listFunctionParameters.count();

    if(nNumberOfFunctionParameters)
    {
        QString sFunction;
        QString sFunctionConvention=functionConventionIdToString(parameter.functionConvention,mode);

        if(parameter.type==TYPE_POINTERTOFUNCTION)
        {
            sFunction=QString("(%1 *").arg(sFunctionConvention);

            if(sName!="") sFunction+=QString(" %1").arg(sName);
            sFunction+=")";
        }
        else if(parameter.type==TYPE_POINTERTOFUNCTIONREF)
        {
            sFunction=QString("(%1 *&").arg(sFunctionConvention);

            if(sName!="") sFunction+=QString(" %1").arg(sName);
            sFunction+=")";
        }
        else if(parameter.type==TYPE_FUNCTION)
        {
            sFunction=QString("%1").arg(sFunctionConvention);
        }
        else if(parameter.type==TYPE_MEMBER)
        {
            sFunction=QString("(%1 %2::*)").arg(sFunctionConvention).arg(_getNameFromParameter(&parameter,mode));
        }

        QString sReturn=_getStringFromParameter(parameter.listFunctionParameters.at(0),mode,sFunction,true);

        sResult=sReturn;

        sResult+="(";

        for(int i=1;i<nNumberOfFunctionParameters;i++)
        {
            sResult+=_getStringFromParameter(parameter.listFunctionParameters.at(i),mode);

            if(i!=nNumberOfFunctionParameters-1)
            {
                sResult+=QString(", ");
            }
        }

        sResult+=")";
    }
    else if(parameter.type==TYPE_CONST)
    {
        sResult=QString::number(parameter.nConstValue);
    }
    else
    {
        int nNumberOfIndexes=parameter.listIndexes.count();
        int nNumberOfMods=parameter.listMods.count();

        QString sMod;

        bool bParamMod=false;

        for(int i=0;i<nNumberOfMods;i++)
        {
            QString sStorageClass;

            if(i==0) // TODO Check!
            {
                sStorageClass=storageClassIdToString(parameter.listMods.at(i).storageClass,mode);
            }

            QString sParamMod=paramModIdToString(parameter.listMods.at(i).paramMod,mode);

            bParamMod=(sParamMod!="");

            if(parameter.listMods.at(i).listNames.count())
            {
                int nNumberOfNames=parameter.listMods.at(i).listNames.count();

                for(int j=0;j<nNumberOfNames;j++)
                {
                    sMod+=QString("%1::").arg(parameter.listMods.at(i).listNames.at(j));
                }
            }
            else
            {
                if(sStorageClass!="")
                {
                    if(_getStringEnd(sMod)!=QChar(' ')) sMod+=" ";
                    sMod+=QString("%1").arg(sStorageClass);
                }

                if(sParamMod!="")
                {
                    if( (_getStringEnd(sMod)!=QChar(' '))&&
                        (_getStringEnd(sMod)!=QChar('*'))&&
                        (_getStringEnd(sMod)!=QChar(':')))
                    {
                        sMod+=" ";
                    }
                    sMod+=QString("%1").arg(sParamMod);
                }
            }
        }

        QString sType=typeIdToString(parameter.type,mode);
        QString sTypeName=_getNameFromParameter(&parameter,mode);

        if(sType!="") sResult+=QString("%1").arg(sType);

        if(sTypeName!="")
        {
            if(_getStringEnd(sResult)!=QChar(' ')) sResult+=" ";

            sResult+=QString("%1").arg(sTypeName);
        }

        if(parameter.extraStorageClass!=SC_UNKNOWN)
        {
            if(_getStringEnd(sResult)!=QChar(' ')) sResult+=" ";
            sResult+=QString("%1").arg(storageClassIdToString(parameter.extraStorageClass,mode));
        }

        if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
        {
            if(sMod!="")
            {
                if(_getStringEnd(sResult)!=QChar(' '))
                {
                    sResult+=" ";
                }
            }
        }

        if(nNumberOfIndexes>1) sResult+="(";

        if(sMod!="") sResult+=QString("%1").arg(sMod);

        if(sResult!="")
        {
            if(_getStringEnd(sResult)==QChar(' '))
            {
                sResult=_removeLastSymbol(sResult);
            }
        }

        if(bFuncRet)
        {
            if(bParamMod)
            {
                if(sResult=="void &")
                {
                    sResult=_removeLastSymbol(sResult);
                }
                else
                {
                    sResult+=" ";
                }
            }
        }

        if(sName!="")
        {
            if( (_getStringEnd(sResult)!=QChar(' '))&&
                (_getStringEnd(sResult)!=QChar('*')))
            {
                sResult+=" ";
            }

            sResult+=QString("%1").arg(sName);
        }

        if(nNumberOfIndexes>1) sResult+=")";

        for(int i=1;i<nNumberOfIndexes;i++)
        {
            sResult+=QString("[%1]").arg(parameter.listIndexes.at(i));
        }
    }

    return sResult;
}
