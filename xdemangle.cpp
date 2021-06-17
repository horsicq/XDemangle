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
        case MODE_MSVC64:       sResult=QString("MSVC+++ 64");          break;
        case MODE_GCC:          sResult=QString("GNU C++");             break;
        case MODE_GCC_WIN32:    sResult=QString("GNU C++ for Win32");   break;
        case MODE_GCC_MAC:      sResult=QString("GNU C++ for MacOS");   break;
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
        case TYPE_NONE:             sResult=QString("");                    break;
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
        default:                    sResult="Unknown";
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
        default:                            sResult="Unknown";
    }

    return sResult;
}

QString XDemangle::paramModIdToString(quint32 nParamMod, XDemangle::MODE mode)
{
    Q_UNUSED(mode)

    QString sResult="Unknown"; // mb TODO translate

    switch(nParamMod)
    {
//        case PM_NONE:                   sResult=QString("");                    break; // mb TODO translate
//        case PM_POINTER:                sResult=QString("*");                   break;
//        case PM_REFERENCE:              sResult=QString("&");                   break;
//        case PM_POINTERCONST:           sResult=QString("*const");              break;
//        case PM_POINTERVOLATILE:        sResult=QString("*volatile");           break;
//        case PM_POINTERCONSTVOLATILE:   sResult=QString("*const volatile");     break;
//        case PM_DOUBLEREFERENCE:        sResult=QString("&&");                  break;
    }

    return sResult;
}

QString XDemangle::accessIdToString(quint32 nFunctionMod, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult;

//    if(nFunctionMod==0)
//    {
//        sResult=QString("Unknown");
//    }

    bool bStatic=nFunctionMod&FM_STATIC;
    bool bVirtual=nFunctionMod&FM_VIRTUAL;

    if      (nFunctionMod&FM_PRIVATE)       sResult+=QString("private:");
    else if (nFunctionMod&FM_PROTECTED)     sResult+=QString("protected:");
    else if (nFunctionMod&FM_PUBLIC)        sResult+=QString("public:");
    else                                    bStatic=false;

    if((nFunctionMod&FM_STATIC)||(nFunctionMod&FM_VIRTUAL))
    {
        if(sResult!="")     sResult+=" ";

        if      (bStatic)   sResult+=QString("static");
        else if (bVirtual)  sResult+=QString("virtual");
    }

    return sResult;
}

QString XDemangle::functionConventionIdToString(XDemangle::FC functionConvention, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult="Unknown"; // mb TODO translate

    switch(functionConvention)
    {
        case FC_UNKNOWN:            sResult=QString("");                            break;
        case FC_NONE:               sResult=QString("");                            break;
        case FC_CDECL:              sResult=QString("__cdecl");                     break;
        case FC_THISCALL:           sResult=QString("__thiscall");                  break;
        case FC_STDCALL:            sResult=QString("__stdcall");                   break;
        case FC_FASTCALL:           sResult=QString("__fastcall");                  break;
        case FC_CLRCALL:            sResult=QString("__clrcall");                   break;
        case FC_VECTORCALL:         sResult=QString("__vectorcall");                break;
        default:                    sResult="Unknown";
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
        case OP_REFERENCE:              sResult=QString("operator&");                       break;
        case OP_INCREMENT:              sResult=QString("operator++");                      break;
        case OP_DECREMENT:              sResult=QString("operator--");                      break;
        case OP_MINUS:                  sResult=QString("operator-");                       break;
        case OP_PLUS:                   sResult=QString("operator+");                       break;
        case OP_BITWISEAND:             sResult=QString("operator&");                       break;
        case OP_MEMBERPOINTER:          sResult=QString("operator->*");                     break;
        case OP_MULTIPLE:               sResult=QString("operator*");                       break;
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

QString XDemangle::qualIdToPointerString(quint32 nQual, XDemangle::MODE mode)
{
    Q_UNUSED(mode)

    QString sResult;

    if      (nQual&QUAL_POINTER)                sResult+="*";
    else if (nQual&QUAL_REFERENCE)              sResult+="&";
    else if (nQual&QUAL_DOUBLEREFERENCE)        sResult+="&&";
    else if (nQual&QUAL_RVALUEREF)              sResult+="&&";

    if(nQual&QUAL_CONST)
    {
        sResult+="const";
    }

    if(nQual&QUAL_VOLATILE)
    {
        if(nQual&QUAL_CONST)
        {
            sResult+=" ";
        }

        sResult+="volatile";
    }

    return sResult;
}

QString XDemangle::qualIdToStorageString(quint32 nQual, XDemangle::MODE mode)
{
    Q_UNUSED(mode)

    QString sResult;

    if(nQual&QUAL_CONST) sResult="const";

    return sResult;
}

XDemangle::SYNTAX XDemangle::getSyntaxFromMode(XDemangle::MODE mode)
{
    SYNTAX result=SYNTAX_UNKNOWN;

    if(     (mode==MODE_MSVC32)||
            (mode==MODE_MSVC64)||
            (mode==MODE_MSVC))
    {
        result=SYNTAX_MICROSOFT;
    }
    else if((mode==MODE_GCC)||
            (mode==MODE_GCC_MAC)||
            (mode==MODE_GCC_WIN32))
    {
        result=SYNTAX_ITANIUM;
    }

    return result;
}

qint32 XDemangle::ms_demangle_StringLiteralSymbol(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    if(_compare(sString,"@_"))
    {
        nResult+=2;
        sString=sString.mid(2,-1);
    }
    else
    {
        pSymbol->bIsValid=false;
    }

    bool bWchar=false;

    if(_compare(sString,"0"))
    {
        nResult+=1;
        sString=sString.mid(1,-1);
    }
    else if(_compare(sString,"1"))
    {
        bWchar=true;
        nResult+=1;
        sString=sString.mid(1,-1);
    }
    else
    {
        pSymbol->bIsValid=false;
    }

    if(pSymbol->bIsValid)
    {
        NUMBER number=readNumber(pHdata,sString,pSymbol->mode);
        nResult+=number.nSize;
        sString=sString.mid(number.nSize,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_UntypedVariable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nPSize=ms_demangle_NameScope(pSymbol,pHdata,pParameter,sString);

    nResult+=nPSize;
    sString=sString.mid(nPSize,-1);

    reverseList(&(pParameter->listDnames));

    if(!_compare(sString,"8"))
    {
        pSymbol->bIsValid=false;
    }

    if(pSymbol->bIsValid)
    {
        nResult+=1;
        sString=sString.mid(1,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_SpecialTable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nNSSize=ms_demangle_NameScope(pSymbol,pHdata,pParameter,sString);

    reverseList(&(pParameter->listDnames));

    nResult+=nNSSize;
    sString=sString.mid(nNSSize,-1);

    if( (!_compare(sString,"6"))&&
        (!_compare(sString,"7")))
    {
        pSymbol->bIsValid=false;
    }

    if(pSymbol->bIsValid)
    {
        nResult+=1;
        sString=sString.mid(1,-1);

        if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

            pParameter->nQualifier=signature.nValue;
            sString=sString.mid(signature.nSize,-1);
            nResult+=signature.nSize;
        }

        if(_compare(sString,"@"))
        {
            nResult+=1;
            sString=sString.mid(1,-1);
        }
        else
        {
            DPARAMETER parameter={};
            parameter.st=ST_NAME;

            qint32 nPSize=ms_demangle_NameScope(pSymbol,pHdata,&parameter,sString);

            nResult+=nPSize;
            sString=sString.mid(nPSize,-1);

            reverseList(&(parameter.listDnames));

            pParameter->listTarget.append(parameter);
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_LocalStaticGuard(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nNSSize=ms_demangle_NameScope(pSymbol,pHdata,pParameter,sString);

    reverseList(&(pParameter->listDnames));

    nResult+=nNSSize;
    sString=sString.mid(nNSSize,-1);

    // Visible
    if(_compare(sString,"4IA"))
    {
        // Visible false
        nResult+=3;
        sString=sString.mid(3,-1);
    }
    else if(_compare(sString,"5"))
    {
        // Visible true
        nResult+=1;
        sString=sString.mid(1,-1);
    }
    else
    {
        pSymbol->bIsValid=false;
    }

    if(sString!="")
    {
        NUMBER number=readNumber(pHdata,sString,pSymbol->mode);
        pParameter->sScope=QString::number(number.nValue);

        nResult+=number.nSize;
        sString=sString.mid(number.nSize,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Type(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString, MSDT msdt)
{
    qint32 nResult=0;

    if(msdt==MSDT_MANGLE)
    {
        if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

            pParameter->nQualifier=signature.nValue;

            nResult+=signature.nSize;
            sString=sString.mid(signature.nSize,-1);
        }
    }
    else if(msdt==MSDT_RESULT)
    {
        if(_compare(sString,"?"))
        {
            sString=sString.mid(1,-1);
            nResult+=1;

            if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
            {
                SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

                pParameter->nQualifier=signature.nValue;

                nResult+=signature.nSize;
                sString=sString.mid(signature.nSize,-1);
            }
        }
    }

    if(isSignaturePresent(sString,&(pHdata->mapTagTypes)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapTagTypes));
        pParameter->type=(TYPE)signature.nValue;
        pParameter->st=ST_TYPE;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);

        qint32 nFNSize=ms_demangle_FullTypeName(pSymbol,pHdata,pParameter,sString);

        nResult+=nFNSize;
        sString=sString.mid(nFNSize,-1);
    }
    else if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
    {
        if(ms_isPointerMember(pSymbol,pHdata,sString))
        {
            qint32 nPTSize=ms_demangle_MemberPointerType(pSymbol,pHdata,pParameter,sString);

            nResult+=nPTSize;
            sString=sString.mid(nPTSize,-1);
        }
        else if(pSymbol->bIsValid)
        {
            qint32 nPTSize=ms_demangle_PointerType(pSymbol,pHdata,pParameter,sString);

            nResult+=nPTSize;
            sString=sString.mid(nPTSize,-1);
        }
    }
    else if(_compare(sString,"Y")) // Array
    {
        sString=sString.mid(1,-1);
        nResult+=1;

        while(pSymbol->bIsValid)
        {
            NUMBER number=readNumber(pHdata,sString,pSymbol->mode);

            if(number.nSize==0)
            {
                break;
            }

            pParameter->listIndexes.append(number.nValue);

            sString=sString.mid(number.nSize,-1);
            nResult+=number.nSize;
        }

        if(_compare(sString,"$$C"))
        {
            sString=sString.mid(3,-1);
            nResult+=3;

            if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
            {
                SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

                pParameter->nQualifier|=signature.nValue;

                nResult+=signature.nSize;
                sString=sString.mid(signature.nSize,-1);
            }
        }

        qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,pParameter,sString,MSDT_DROP);

        sString=sString.mid(nTSize,-1);
        nResult+=nTSize;
    }
    else if(isSignaturePresent(sString,&(pHdata->mapTypes)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapTypes));
        pParameter->type=(TYPE)signature.nValue;
        pParameter->st=ST_TYPE;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }
    else if(_compare(sString,"$$A8@@")) // Function
    {
        sString=sString.mid(6,-1);
        nResult+=6;

        pParameter->st=ST_FUNCTION;

        qint32 nFSize=ms_demangle_FunctionType(pSymbol,pHdata,pParameter,sString,true);

        sString=sString.mid(nFSize,-1);
        nResult+=nFSize;
    }
    else if(_compare(sString,"$$A6")) // Function
    {
        sString=sString.mid(4,-1);
        nResult+=4;

        pParameter->st=ST_FUNCTION;

        qint32 nFSize=ms_demangle_FunctionType(pSymbol,pHdata,pParameter,sString,false);

        sString=sString.mid(nFSize,-1);
        nResult+=nFSize;
    }
    else
    {
    #ifdef QT_DEBUG
        qDebug("TODO: TYPE");
    #endif
        pSymbol->bIsValid=false;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_PointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    pParameter->st=ST_POINTER;

    if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapPointerTypes));

        pParameter->nQualifier=signature.nValue;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }

    if(_compare(sString,"6"))
    {
        nResult+=1;
        sString=sString.mid(1,-1);

        DPARAMETER parameter={};
        parameter.st=ST_FUNCTION;
//        parameter.type=TYPE_FUNCTION;
//        pParameter->type=TYPE_POINTERTOFUNCTION; // TODO remove

        qint32 nFTSize=ms_demangle_FunctionType(pSymbol,pHdata,&parameter,sString,false);
        pParameter->listPointer.append(parameter);

        nResult+=nFTSize;
        sString=sString.mid(nFTSize,-1);
    }
    else
    {
        qint32 nESize=ms_demangle_ExtQualifiers(pSymbol,sString,&(pParameter->nQualifier));

        nResult+=nESize;
        sString=sString.mid(nESize,-1);

        DPARAMETER parameter={};

        qint32 nPSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_MANGLE);

        pParameter->listPointer.append(parameter);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_MemberPointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    pParameter->st=ST_POINTER;

    if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapPointerTypes));

        pParameter->nQualifier=signature.nValue;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }

    qint32 nESize=ms_demangle_ExtQualifiers(pSymbol,sString,&(pParameter->nQualifier));

    nResult+=nESize;
    sString=sString.mid(nESize,-1);

    if(_compare(sString,"8"))
    {
        nResult+=1;
        sString=sString.mid(1,-1);

        DPARAMETER parameter={};
        parameter.st=ST_FUNCTION;

        qint32 nFTSize=ms_demangle_FullTypeName(pSymbol,pHdata,pParameter,sString);

        nResult+=nFTSize;
        sString=sString.mid(nFTSize,-1);

        qint32 nPSize=ms_demangle_FunctionType(pSymbol,pHdata,&parameter,sString,true);

        pParameter->listPointer.append(parameter);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);
    }
    else
    {
        DPARAMETER parameter={};

        if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

            parameter.nQualifier=signature.nValue;

            nResult+=signature.nSize;
            sString=sString.mid(signature.nSize,-1);
        }

        qint32 nFTSize=ms_demangle_FullTypeName(pSymbol,pHdata,pParameter,sString);

        nResult+=nFTSize;
        sString=sString.mid(nFTSize,-1);

        qint32 nPSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

        pParameter->listPointer.append(parameter);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FullTypeName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nUnkName=ms_demangle_UnkTypeName(pSymbol,pHdata,pParameter,sString,true);
    nResult+=nUnkName;

    sString=sString.mid(nUnkName,-1);

    qint32 nNameScope=ms_demangle_NameScope(pSymbol,pHdata,pParameter,sString);
    nResult+=nNameScope;

    sString=sString.mid(nNameScope,-1);

    reverseList(&(pParameter->listDnames));

    return nResult;
}

qint32 XDemangle::ms_demangle_FullSymbolName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nUnkName=ms_demangle_UnkSymbolName(pSymbol,pHdata,pParameter,sString,NB_SIMPLE);
    nResult+=nUnkName;

    sString=sString.mid(nUnkName,-1);

    qint32 nNameScope=ms_demangle_NameScope(pSymbol,pHdata,pParameter,sString);
    nResult+=nNameScope;

    sString=sString.mid(nNameScope,-1);

    reverseList(&(pParameter->listDnames));

    return nResult;
}

qint32 XDemangle::ms_demangle_UnkTypeName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, bool bSave)
{
    qint32 nResult=0;

    if(isReplaceStringPresent(pSymbol,pHdata,sString))
    {
        SIGNATURE signature=getReplaceStringSignature(pSymbol,pHdata,sString);
        // TODO Error empty String
        DNAME dname={};
        dname.sName=signature.sKey;

        pParameter->listDnames.append(dname);

        sString=sString.mid(signature.nSize,-1);
        nResult+=signature.nSize;
    }
    else if(_compare(sString,"?$"))
    {
        qint32 nTSize=ms_demangle_Template(pSymbol,pHdata,pParameter,sString,NB_TEMPLATE);
        sString=sString.mid(nTSize,-1);
        nResult+=nTSize;
    }
    else
    {
        STRING string=readString(pHdata,sString,pSymbol->mode);

        if(string.nSize)
        {
            if(bSave)
            {
                addStringRef(pSymbol,pHdata,string.sString);
            }

            DNAME dname={};
            dname.sName=string.sString;

            pParameter->listDnames.append(dname);

            sString=sString.mid(string.nSize,-1);
            nResult+=string.nSize;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_UnkSymbolName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString, NB nb)
{
    qint32 nResult=0;

    if(isReplaceStringPresent(pSymbol,pHdata,sString))
    {
        SIGNATURE signature=getReplaceStringSignature(pSymbol,pHdata,sString);
        // TODO Error empty String
        DNAME dname={};
        dname.sName=signature.sKey;

        pParameter->listDnames.append(dname);

        sString=sString.mid(signature.nSize,-1);
        nResult+=signature.nSize;
    }
    else if(_compare(sString,"?$"))
    {
        qint32 nTSize=ms_demangle_Template(pSymbol,pHdata,pParameter,sString,nb);
        sString=sString.mid(nTSize,-1);
        nResult+=nTSize;
    }
    else if(isSignaturePresent(sString,&(pHdata->mapOperators)))
    {
        DNAME dname={};
        SIGNATURE signature=getSignature(sString,&(pHdata->mapOperators));
        dname._operator=(OP)signature.nValue;
        nResult+=signature.nSize;

        pParameter->listDnames.append(dname);
    }
    else
    {
        STRING string=readString(pHdata,sString,pSymbol->mode);

        if(string.nSize)
        {
            if(nb&NB_SIMPLE)
            {
                addStringRef(pSymbol,pHdata,string.sString);
            }

            DNAME dname={};
            dname.sName=string.sString;

            pParameter->listDnames.append(dname);

            sString=sString.mid(string.nSize,-1);
            nResult+=string.nSize;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    while(sString!="")
    {
        if(isReplaceStringPresent(pSymbol,pHdata,sString))
        {
            SIGNATURE signature=getReplaceStringSignature(pSymbol,pHdata,sString);
            // TODO Error empty String
            DNAME dname={};
            dname.sName=signature.sKey;

            pParameter->listDnames.append(dname);

            sString=sString.mid(signature.nSize,-1);
            nResult+=signature.nSize;
        }
        else if(_compare(sString,"?$"))
        {
            qint32 nTSize=ms_demangle_Template(pSymbol,pHdata,pParameter,sString,NB_TEMPLATE);
            sString=sString.mid(nTSize,-1);
            nResult+=nTSize;
        }
        else if(_compare(sString,"?A"))
        {
        #ifdef QT_DEBUG
            qDebug("TODO: AnonymousNamespaceName");
        #endif
            sString=sString.mid(2,-1);
            nResult+=2;
        }
        else if(isLocalScopePresent(pSymbol,pHdata,sString))
        {
            SIGNATURE signature=getLocalScopeSignature(pSymbol,pHdata,sString);

            DNAME dnameLocalScope={};
            dnameLocalScope.sName=QString("`%1'").arg(signature.sValue);

            pParameter->listDnames.append(dnameLocalScope);

            sString=sString.mid(signature.nSize,-1);
            nResult+=signature.nSize;

            DSYMBOL symbol=ms_getSymbol(sString,pSymbol->mode,pHdata);

            DNAME dnameSymbol={};
            dnameSymbol.sName=QString("`%1'").arg(dsymbolToString(symbol));

            pParameter->listDnames.append(dnameSymbol);

            sString=sString.mid(symbol.nSize,-1);
            nResult+=symbol.nSize;
        }
        else
        {
            STRING string=readString(pHdata,sString,pSymbol->mode);

            if(string.nSize)
            {
                addStringRef(pSymbol,pHdata,string.sString);

                DNAME dname={};
                dname.sName=string.sString;

                pParameter->listDnames.append(dname);

                sString=sString.mid(string.nSize,-1);
                nResult+=string.nSize;
            }
        }

        if(_compare(sString,"@"))
        {
            nResult+=1;
            sString=sString.mid(1,-1);

            break;
        }

        if(!(pSymbol->bIsValid))
        {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Declarator(DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pDParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nFNSize=ms_demangle_FullSymbolName(pSymbol,pHdata,pDParameter,sString);

    nResult+=nFNSize;
    sString=sString.mid(nFNSize,-1);

    qint32 nRSize=ms_demangle_Parameters(pSymbol,pHdata,pDParameter,sString);

    nResult+=nRSize;
    sString=sString.mid(nRSize,-1);

    return nResult;
}

qint32 XDemangle::ms_demangle_Parameters(DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    if( _compare(sString,"0")||
        _compare(sString,"1")||
        _compare(sString,"2")||
        _compare(sString,"3")||
        _compare(sString,"4"))
    {
        // Variables
        pParameter->st=ST_VARIABLE;

        qint32 nVSize=ms_demangle_Variable(pSymbol,pHdata,pParameter,sString);
        nResult+=nVSize;
    }
    else
    {
        // Functions
        pParameter->st=ST_FUNCTION;
        qint32 nFSize=ms_demangle_Function(pSymbol,pHdata,pParameter,sString);
        nResult+=nFSize;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Function(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    if(_compare(sString,"$$J0"))
    {
        nResult+=4;
        sString=sString.mid(4,-1);
        pParameter->nAccess=FM_EXTERNC;
    }

    if(isSignaturePresent(sString,&(pHdata->mapAccessMods)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapAccessMods));
        pParameter->nAccess|=signature.nValue;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }

    if(pParameter->nAccess&FM_STATICTHISADJUST)
    {
    #ifdef QT_DEBUG
        qDebug("TODO: FM_STATICTHISADJUST");
    #endif
    }

    if(pParameter->nAccess&FM_VIRTUALTHISADJUST)
    {
    #ifdef QT_DEBUG
        qDebug("TODO: FM_VIRTUALTHISADJUST");
    #endif
    }

    if(!(pParameter->nAccess&FM_NOPARAMETERLIST))
    {
        bool bThisQual=!(pParameter->nAccess&(FM_GLOBAL|FM_STATIC));

        qint32 nFSize=ms_demangle_FunctionType(pSymbol,pHdata,pParameter,sString,bThisQual);

        nResult+=nFSize;
        sString=sString.mid(nFSize,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Variable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    if(isSignaturePresent(sString,&(pHdata->mapAccessMods)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapAccessMods));

        pParameter->nAccess=signature.nValue;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }

    DPARAMETER parameter={};
    parameter.st=ST_TYPE;

    qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

    pParameter->listParameters.append(parameter);

    nResult+=nTSize;
    sString=sString.mid(nTSize,-1);

    if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

        pParameter->nQualifier=signature.nValue;
        sString=sString.mid(signature.nSize,-1);
        nResult+=signature.nSize;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, bool bThisQual)
{
    qint32 nResult=0;

    if(bThisQual)
    {       
        qint32 nESize=ms_demangle_ExtQualifiers(pSymbol,sString,&(pParameter->nQualifier));

        sString=sString.mid(nESize,-1);
        nResult+=nESize;

        if(_compare(sString,"G"))
        {
            pParameter->nRefQualifier|=QUAL_REFERENCE;
            sString=sString.mid(1,-1);
            nResult+=1;
        }
        else if(_compare(sString,"H"))
        {
            pParameter->nRefQualifier|=QUAL_RVALUEREF;
            sString=sString.mid(1,-1);
            nResult+=1;
        }

        if(isSignaturePresent(sString,&(pHdata->mapQualifiers)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapQualifiers));

            pParameter->nRefQualifier|=signature.nValue;
            sString=sString.mid(signature.nSize,-1);
            nResult+=signature.nSize;
        }
    }

    if(isSignaturePresent(sString,&(pHdata->mapFunctionConventions)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapFunctionConventions));

        pParameter->functionConvention=(FC)signature.nValue;
        sString=sString.mid(signature.nSize,-1);
        nResult+=signature.nSize;
    }

    if(_compare(sString,"@"))
    {
        pParameter->type=TYPE_NONE;
        sString=sString.mid(1,-1);
        nResult+=1;
    }
    else
    {
        DPARAMETER parameter={};

        qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_RESULT);

        pParameter->listReturn.append(parameter);

        nResult+=nTSize;
        sString=sString.mid(nTSize,-1);
    }

    if(_compare(sString,"X"))
    {
        // Void
        DPARAMETER parameter={};

        qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

        pParameter->listParameters.append(parameter);

        sString=sString.mid(nTSize,-1);
        nResult+=nTSize;
    }
    else
    {
        qint32 nPSize=ms_demangle_FunctionParameters(pSymbol,pHdata,pParameter,sString);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);
    }

    if(_compare(sString,"Z"))
    {
        nResult+=1;
        sString=sString.mid(1,-1);
    }
    else if(_compare(sString,"_E"))
    {
    #ifdef QT_DEBUG
        qDebug("TODO: function exception");
    #endif

        pSymbol->bIsValid=false;

        nResult+=2;
        sString=sString.mid(2,-1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    while(sString!="")
    {
        bool bBreak=false;

        if(_compare(sString,"@"))
        {
            sString=sString.mid(1,-1);
            nResult+=1;

            break;
        }
        else if(_compare(sString,"Z"))
        {
            bBreak=true;
        }

        if(isReplaceArgPresent(pSymbol,pHdata,sString))
        {
            SIGNATURE signature=getReplaceArgSignature(pSymbol,pHdata,sString);

            DPARAMETER parameter={};

            ms_demangle_Type(pSymbol,pHdata,&parameter,signature.sKey,MSDT_DROP);

            pParameter->listParameters.append(parameter);

            sString=sString.mid(signature.nSize,-1);
            nResult+=signature.nSize;
        }
        else
        {
            DPARAMETER parameter={};

            qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

            pParameter->listParameters.append(parameter);

            QString sArg=sString.left(nTSize);
            addArgRef(pSymbol,pHdata,sArg);

            nResult+=nTSize;
            sString=sString.mid(nTSize,-1);
        }

        if(bBreak)
        {
            break;
        }

        if(!(pSymbol->bIsValid))
        {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Template(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, XDemangle::NB nb)
{
    qint32 nResult=0;

    if(_compare(sString,"?$"))
    {
        sString=sString.mid(2,-1);
        nResult+=2;

        XDemangle::HDATA hdata=*pHdata;
        hdata.listArgRef.clear();
        hdata.listStringRef.clear();

        DPARAMETER parameter={};
        parameter.st=ST_TEMPLATE;

        qint32 nNName=ms_demangle_UnkSymbolName(pSymbol,&hdata,&parameter,sString,NB_SIMPLE);
        sString=sString.mid(nNName,-1);
        nResult+=nNName;

        qint32 nTName=ms_demangle_TemplateParameters(pSymbol,&hdata,&parameter,sString);
        sString=sString.mid(nTName,-1);
        nResult+=nTName;

        QString sName=_nameToString(pSymbol,&parameter);
//        QString sTemplate=ms_parameterToString(pSymbol,&parameter,sName);
        QString sTemplate=ms_parameterToString(pSymbol,&parameter,sName,"");

        DNAME dname={};
        dname.sName=sTemplate;

        pParameter->listDnames.append(dname);

        if(nb&NB_TEMPLATE)
        {
            addStringRef(pSymbol,pHdata,sTemplate);
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_TemplateParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    while(sString!="")
    {
        if(_compare(sString,"@"))
        {
            break;
        }

        if(_compare(sString,"$S"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);
        }

        if(_compare(sString,"$$V")||_compare(sString,"$$Z"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);
        }

        if(_compare(sString,"$$$V"))
        {
            nResult+=4;
            sString=sString.mid(4,-1);
        }

        if(_compare(sString,"$$Y"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);

            pSymbol->bIsValid=false;
        #ifdef QT_DEBUG
            qDebug("TODO: Template alias");
        #endif
        }
        else if(_compare(sString,"$$B"))
        {
            // TODO CHeck
            nResult+=3;
            sString=sString.mid(3,-1);

            DPARAMETER parameter={};

            qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

            pParameter->listParameters.append(parameter);

            nResult+=nTSize;
            sString=sString.mid(nTSize,-1);
        }
        else if(_compare(sString,"$$C"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);

            DPARAMETER parameter={};

            qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_MANGLE);

            pParameter->listParameters.append(parameter);

            nResult+=nTSize;
            sString=sString.mid(nTSize,-1);
        }
        else if(_compare(sString,"$1")||_compare(sString,"$H")||
                _compare(sString,"$I")||_compare(sString,"$J"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            pSymbol->bIsValid=false;
        #ifdef QT_DEBUG
            qDebug("TODO: Template");
        #endif
        }
        else if(_compare(sString,"$E?"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);

            pSymbol->bIsValid=false;
        #ifdef QT_DEBUG
            qDebug("TODO: Reference to symbol");
        #endif
        }
        else if(_compare(sString,"$0"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            NUMBER number=readNumber(pHdata,sString,pSymbol->mode);

            DPARAMETER parameter={};

            parameter.st=ST_CONST;
            parameter.varConst=QString::number(number.nValue);

            pParameter->listParameters.append(parameter);

            nResult+=number.nSize;
            sString=sString.mid(number.nSize,-1);
        }
        else
        {
            DPARAMETER parameter={};

            qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

            pParameter->listParameters.append(parameter);

            nResult+=nTSize;
            sString=sString.mid(nTSize,-1);

            if(!(pSymbol->bIsValid))
            {
                break;
            }
        }
    }

    if(_compare(sString,"@"))
    {
        sString=sString.mid(1,-1);
        nResult+=1;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_ExtQualifiers(XDemangle::DSYMBOL *pSymbol, QString sString, quint32 *pnQual)
{
    Q_UNUSED(pSymbol)

    qint32 nResult=0;

    if(_compare(sString,"E")) // mb TODO Check MODE_MSVC64
    {
        (*pnQual)|=QUAL_POINTER64;
        sString=sString.mid(1,-1);
        nResult+=1;
    }
    if(_compare(sString,"I"))
    {
        (*pnQual)|=QUAL_RESTRICT;
        sString=sString.mid(1,-1);
        nResult+=1;
    }
    if(_compare(sString,"F"))
    {
        (*pnQual)|=QUAL_UNALIGNED;
        sString=sString.mid(1,-1);
        nResult+=1;
    }

    return nResult;
}

bool XDemangle::ms_isPointerMember(XDemangle::DSYMBOL *pSymbol, HDATA *pHdata, QString sString)
{
    if(_compare(sString,"$"))
    {
        // rvalue ref
        return false;
    }
    else if(_compare(sString,"A"))
    {
        // ref
        return false;
    }
    // PQRS
    sString=sString.mid(1,-1);

    if(isSignaturePresent(sString,&(pHdata->mapNumbers)))
    {
        if((!_compare(sString,"6"))&&(!_compare(sString,"8")))
        {
            pSymbol->bIsValid=false;

            return false;
        }

        return _compare(sString,"8");
    }

    quint32 nQual=0;

    qint32 nESize=ms_demangle_ExtQualifiers(pSymbol,sString,&nQual);

    sString=sString.mid(nESize,-1);

    if(sString=="")
    {
        pSymbol->bIsValid=false;

        return false;
    }

    if(_compare(sString,"A")||_compare(sString,"B")||_compare(sString,"C")||_compare(sString,"D"))
    {
        return false;
    }

    if(_compare(sString,"Q")||_compare(sString,"R")||_compare(sString,"S")||_compare(sString,"T"))
    {
        return true;
    }

    pSymbol->bIsValid=false;

    return false;
}

void XDemangle::addStringRef(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        if(!pHdata->listStringRef.contains(sString))
        {
            if(pHdata->listStringRef.count()<10)
            {
                pHdata->listStringRef.append(sString);
            }
        }
    }
    else if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_ITANIUM)
    {
        if(!pHdata->listStringRef.contains(sString)) // TODO rewrite!
        {
            pHdata->listStringRef.append(sString);
        }
    }
}

void XDemangle::addArgRef(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        if(sString.size()>1)
        {
            if(!pHdata->listArgRef.contains(sString))
            {
                if(pHdata->listArgRef.count()<10)
                {
                    pHdata->listArgRef.append(sString);
                }
            }
        }
    }
}

bool XDemangle::isReplaceStringPresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    bool bResult=false;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        bResult=isSignaturePresent(sString,&(pHdata->mapNumbers));
    }
    else if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_ITANIUM)
    {
        if(_compare(sString,"S"))
        {
            sString=sString.mid(1,-1);

            NUMBER number=readSymNumber(pHdata,sString,pSymbol->mode);

            if(number.nSize)
            {
                sString=sString.mid(number.nSize,-1);
            }

            if(_compare(sString,"_"))
            {
                sString=sString.mid(1,-1);

                bResult=true;
            }
        }
    }

    return bResult;
}

bool XDemangle::isReplaceArgPresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    bool bResult=false;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        bResult=isSignaturePresent(sString,&(pHdata->mapNumbers));
    }
    else if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_ITANIUM)
    {
        if(_compare(sString,"T"))
        {
            sString=sString.mid(1,-1);

            NUMBER number=readSymNumber(pHdata,sString,pSymbol->mode);

            if(number.nSize)
            {
                sString=sString.mid(number.nSize,-1);
            }

            if(_compare(sString,"_"))
            {
                sString=sString.mid(1,-1);

                bResult=true;
            }
        }
    }

    return bResult;
}

bool XDemangle::isLocalScopePresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    bool bResult=false;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        if(_compare(sString,"?"))
        {
            sString=sString.mid(1,-1);

            NUMBER number=readNumber(pHdata,sString,pSymbol->mode);

            if(number.nSize)
            {
                sString=sString.mid(number.nSize,-1);

                if(_compare(sString,"?"))
                {
                    bResult=true;
                }
            }
        }
    }

    return bResult;
}

XDemangle::SIGNATURE XDemangle::getReplaceStringSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    SIGNATURE result={};

    qint32 nIndex=-1;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapNumbers));

        nIndex=signature.nValue;
        result.nSize=1;
        result.nValue=signature.nValue;
    }
    else if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_ITANIUM)
    {
        if(_compare(sString,"S"))
        {
            sString=sString.mid(1,-1);

            NUMBER number=readSymNumber(pHdata,sString,pSymbol->mode);

            if(number.nSize)
            {
                sString=sString.mid(number.nSize,-1);
                result.nValue=number.nValue+1;
            }

            if(_compare(sString,"_"))
            {
                sString=sString.mid(1,-1);

                result.nSize=2+number.nSize;

                nIndex=result.nValue;
            }
        }
    }

    if((nIndex!=-1)&&(nIndex<pHdata->listStringRef.count()))
    {
        result.sKey=pHdata->listStringRef.at(nIndex);
    }
    else
    {
        pSymbol->bIsValid=false;
    #ifdef QT_DEBUG
        qDebug("Replace String Error!!!");
    #endif
    }

    return result;
}

XDemangle::SIGNATURE XDemangle::getReplaceArgSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    SIGNATURE result={};

    qint32 nIndex=0;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapNumbers));
        result.nSize=1;
        nIndex=signature.nValue;
    }
    else if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_ITANIUM)
    {
        if(_compare(sString,"T"))
        {
            sString=sString.mid(1,-1);

            NUMBER number=readSymNumber(pHdata,sString,pSymbol->mode);

            if(number.nSize)
            {
                sString=sString.mid(number.nSize,-1);
                result.nValue=number.nValue+1;
            }

            if(_compare(sString,"_"))
            {
                sString=sString.mid(1,-1);

                result.nSize=2+number.nSize;

                nIndex=result.nValue;
            }
        }
    }

    if(nIndex<pHdata->listArgRef.count())
    {
        result.sKey=pHdata->listArgRef.at(nIndex);
        result.nValue=nIndex;
    }
    else
    {
        pSymbol->bIsValid=false;
    #ifdef QT_DEBUG
        qDebug("Replace Arg Error!!!");
    #endif
    }

    return result;
}

XDemangle::SIGNATURE XDemangle::getLocalScopeSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    SIGNATURE result={};

    QString _sString=sString;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        if(_compare(_sString,"?"))
        {
            _sString=_sString.mid(1,-1);

            NUMBER number=readNumber(pHdata,_sString,pSymbol->mode);

            if(number.nSize)
            {
                _sString=_sString.mid(number.nSize,-1);

                if(_compare(_sString,"?"))
                {
                    result.nSize=number.nSize+2;
                    result.sKey=sString.left(result.nSize);
                    result.sValue=QString::number(number.nValue);
                }
            }
        }
    }

    return result;
}

QString XDemangle::ms_parameterToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, QString sName, QString sPrefix)
{
    QString sResult;

//    if(sName=="")
//    {
//        sName=ms_nameToString(pSymbol,pParameter); // TODO Check
//    }

    if(pParameter->st==ST_VARIABLE)
    {
        if(pParameter->listParameters.count())
        {
            DPARAMETER parameter=pParameter->listParameters.at(0);
            DPARAMETER parameterLast=getLastPointerParameter(&parameter); // TODO GetLast

            QString sAccess=accessIdToString(pParameter->nAccess,pSymbol->mode);
            QString sQual=qualIdToStorageString(pParameter->nQualifier,pSymbol->mode);

            if((pParameter->nQualifier&QUAL_CONST)&&(parameterLast.nQualifier&QUAL_CONST)) // TODO Check
            {
                sQual="";
            }

            QString sType=ms_parameterToString(pSymbol,&parameter,sName,"");

            if(sAccess!="") sResult+=QString("%1 ").arg(sAccess);
            sResult+=sType;
            if(sQual!="") sResult+=QString(" %1").arg(sQual);

            if(parameter.st!=ST_POINTER) // TODO Check
            {
                if(sName!="")       sResult+=QString(" %1").arg(sName);
            }
        }
    }
    else if(pParameter->st==ST_TYPE)
    {
        QString sType=typeIdToString(pParameter->type,pSymbol->mode);
        QString sQual=qualIdToPointerString(pParameter->nQualifier,pSymbol->mode);
        QString sTypeName=_nameToString(pSymbol,pParameter);

        sResult+=sType;

        if(sTypeName!="")   sResult+=QString(" %1").arg(sTypeName);

        if(sQual!="")     sResult+=QString(" %1").arg(sQual);
    }
    else if(pParameter->st==ST_CONST)
    {
        sResult=pParameter->varConst.toString();
    }
    else if(pParameter->st==ST_NAME)
    {
        sResult=_nameToString(pSymbol,pParameter);
    }
    else if(pParameter->st==ST_POINTER)
    {
        if(pParameter->listPointer.count())
        {
            DPARAMETER lastParameter=getLastPointerParameter(pParameter);

            QString sPointer=ms_getPointerString(pSymbol,pParameter,sName);

            QString _sPrefix=sPointer;
            if(sPrefix!="")
            {
                _sPrefix+=" ";
                _sPrefix+=sPrefix;
            }

            sResult=ms_parameterToString(pSymbol,&lastParameter,"",_sPrefix);

            if(lastParameter.st!=ST_FUNCTION)
            {
                if(!isPointerEnd(sResult)) // TODO Function
                {
                    sResult+=QString(" ");
                }

                sResult+=QString("%1").arg(sPointer);
            }
        }
    }
    else if(pParameter->st==ST_FUNCTION)
    {
        QString sAccess=accessIdToString(pParameter->nAccess,pSymbol->mode);
        QString sConv=functionConventionIdToString(pParameter->functionConvention,pSymbol->mode);
        QString sRefQualStorage=qualIdToStorageString(pParameter->nRefQualifier,pSymbol->mode);
        QString sRefQualPointer=qualIdToPointerString((pParameter->nRefQualifier)&(~(QUAL_CONST)),pSymbol->mode);
        QString sReturn;
        QString sArgs;

        TYPE typeReturn=TYPE_NONE;

        sArgs+="(";

        int nNumberOfParameters=pParameter->listParameters.count();

        for(int i=0;i<nNumberOfParameters;i++)
        {
            DPARAMETER parameter=pParameter->listParameters.at(i);

            sArgs+=ms_parameterToString(pSymbol,&parameter,"","");

            if(i!=(nNumberOfParameters-1))
            {
                sArgs+=", ";
            }
        }

        sArgs+=")";

        if(pParameter->listReturn.count())
        {
            DPARAMETER parameter=pParameter->listReturn.at(0);
            typeReturn=parameter.type;
        }

        QString _sPrefix;

        if(sPrefix!="") _sPrefix+="(";

        if(sConv!="") _sPrefix+=sConv;

        if((sPrefix!="")||(sName!=""))
        {
            if(sConv!="") _sPrefix+=" ";

            if(sPrefix!="") _sPrefix+=QString("%1").arg(sPrefix);
            if(sName!="")   _sPrefix+=QString("%1").arg(sName);
        }

        if(sPrefix!="") _sPrefix+=")";
        _sPrefix+=sArgs;
        if(sRefQualStorage!="")    _sPrefix+=QString(" %1").arg(sRefQualStorage);
        if(sRefQualPointer!="")    _sPrefix+=QString(" %1").arg(sRefQualPointer);

        bool bFuncReturn=false;

        if(pParameter->listReturn.count())
        {
            DPARAMETER parameter=pParameter->listReturn.at(0);

            bFuncReturn=(getLastPointerParameter(&parameter).st==ST_FUNCTION);

            sReturn=ms_parameterToString(pSymbol,&parameter,"",_sPrefix);
        }

        if(sAccess!="")     sResult+=QString("%1 ").arg(sAccess);
        if(sReturn!="")     sResult+=QString("%1").arg(sReturn);

        if(!bFuncReturn)
        {
            if(_getStringEnd(sResult)!=QChar(' ')) sResult+=" ";

            sResult+=_sPrefix;
        }
    }
    else if(pParameter->st==ST_TYPEINFO)
    {
        if(pParameter->listTarget.count())
        {
            DPARAMETER parameter=pParameter->listTarget.at(0);

            sResult=QString("%1 `RTTI Type Descriptor Name'").arg(ms_parameterToString(pSymbol,&parameter,"","")); // TODO
        }
    }
    else if((pParameter->st==ST_VFTABLE)||
            (pParameter->st==ST_VBTABLE)||
            (pParameter->st==ST_LOCALVFTABLE)||
            (pParameter->st==ST_RTTICOMPLETEOBJLOCATOR))
    {
        QString sSC=qualIdToStorageString(pParameter->nQualifier,pSymbol->mode);
        if(sSC!="")    sResult+=QString("%1 ").arg(sSC);

        if(pParameter->st==ST_VFTABLE)
        {
            sResult+=sName+QString("::`vftable'");
        }
        else if(pParameter->st==ST_VBTABLE)
        {
            sResult+=sName+QString("::`vbtable'");
        }
        else if(pParameter->st==ST_LOCALVFTABLE)
        {
            sResult+=sName+QString("::`local vftable'");
        }
        else if(pParameter->st==ST_RTTICOMPLETEOBJLOCATOR)
        {
            sResult+=sName+QString("::`RTTI Complete Object Locator'");
        }

        if(pParameter->listTarget.count())
        {
            DPARAMETER parameter=pParameter->listTarget.at(0);

            sResult+=QString("{for `%1'}").arg(ms_parameterToString(pSymbol,&parameter,"",""));
        }
    }
    else if((pParameter->st==ST_LOCALSTATICGUARD)||
            (pParameter->st==ST_LOCALSTATICTHREADGUARD))
    {
        sResult=(_nameToString(pSymbol,pParameter));

        if(pParameter->st==ST_LOCALSTATICGUARD)
        {
            sResult+=QString("::`local static guard'");
        }
        else if(pParameter->st==ST_LOCALSTATICTHREADGUARD)
        {
            sResult+=sName+QString("::`local static thread guard'");
        }

        if(pParameter->sScope!="")
        {
            sResult+=QString("{%1}").arg(pParameter->sScope);
        }
    }
    else if((pParameter->st==ST_RTTIBASECLASSARRAY)||
            (pParameter->st==ST_RTTICLASSHIERARCHYDESCRIPTOR))
    {
        sResult=(_nameToString(pSymbol,pParameter));

        if(pParameter->st==ST_RTTIBASECLASSARRAY)
        {
            sResult+=QString("::`RTTI Base Class Array'");
        }
        else if(pParameter->st==ST_RTTICLASSHIERARCHYDESCRIPTOR)
        {
            sResult+=QString("::`RTTI Class Hierarchy Descriptor'");
        }
    }
    else if(pParameter->st==ST_TEMPLATE)
    {
        sResult+=sName;
        sResult+="<";

        int nNumberOfParameters=pParameter->listParameters.count();

        for(int i=0;i<nNumberOfParameters;i++)
        {
            DPARAMETER parameter=pParameter->listParameters.at(i);

            sResult+=ms_parameterToString(pSymbol,&parameter,"","");

            if(i!=(nNumberOfParameters-1))
            {
                sResult+=", ";
            }
        }

        sResult+=">";
    }

    return sResult;
}

QString XDemangle::_nameToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter)
{
    QString sResult;

    // TODO function
    int nNumberOfNames=pParameter->listDnames.count();

    for(int i=0;i<nNumberOfNames;i++)
    {
        QString _sName;

        if(pParameter->listDnames.at(i)._operator!=OP_UNKNOWN)
        {
            _sName=operatorIdToString(pParameter->listDnames.at(i)._operator,pSymbol->mode);

            if((pParameter->listDnames.at(i)._operator==OP_CONSTRUCTOR)||(pParameter->listDnames.at(i)._operator==OP_DESTRUCTOR))
            {
                if(nNumberOfNames>1)
                {
                    QString sBasic=pParameter->listDnames.at(nNumberOfNames-2).sName;

                    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_ITANIUM)
                    {
                        if(sBasic.contains("<")) //Template
                        {
                            sBasic=sBasic.section("<",0,0);
                        }
                    }

                    _sName+=sBasic;
                }
            }
            else if(pParameter->listDnames.at(i)._operator==OP_TYPE)
            {
                if(pSymbol->paramMain.listReturn.count())
                {
                    DPARAMETER parameter=pSymbol->paramMain.listReturn.at(0);
                    _sName+=ms_parameterToString(pSymbol,&parameter,"","");
                }
            }
        }
        else if(pParameter->listDnames.at(i).sName!="")
        {
            _sName=pParameter->listDnames.at(i).sName;
        }

        sResult+=_sName;

        if(i!=(nNumberOfNames-1))
        {
            sResult+="::";
        }
    }

    return sResult;
}

XDemangle::DPARAMETER XDemangle::getLastPointerParameter(XDemangle::DPARAMETER *pParameter)
{
    DPARAMETER result=*pParameter;

    while(result.st==ST_POINTER)
    {
        if(result.listPointer.count())
        {
            result=result.listPointer.at(0);
        }
        else
        {
            break;
        }
    }

    return result;
}

QString XDemangle::ms_getPointerString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, QString sName)
{
    QString sResult;

    DPARAMETER parameter=*pParameter;

    int i=0;

    QString sMain=sName;
    QString sPrefix;
    QString sIndexes;
    bool bArray=false;

    while(parameter.st==ST_POINTER)
    {
        QString _sName=_nameToString(pSymbol,&parameter);
        QString sPointer=qualIdToPointerString(parameter.nQualifier,pSymbol->mode);

        if(_sName!="")
        {
            sPointer=QString("%1::%2").arg(_sName,sPointer);
        }

        if(i==0)
        {
            if((sMain!="")&&(!isPointerEnd(sPointer)))
            {
                sPointer+=" ";
            }

            sMain=sMain.prepend(sPointer);
        }
        else
        {
            if((sPrefix!="")&&(!isPointerEnd(sPointer)))
            {
                sPointer+=" ";
            }

            sPrefix=sPrefix.prepend(sPointer);
        }

        if(parameter.listPointer.count())
        {
            parameter=parameter.listPointer.at(0);
        }
        else
        {
            break;
        }

        int nNumberOfIndexes=parameter.listIndexes.count();

        for(int j=1;j<nNumberOfIndexes;j++)
        {
            bArray=true;
            sIndexes+=QString("[%1]").arg(parameter.listIndexes.at(j));
        }

        i++;
    }

    if(bArray)
    {
        sMain=QString("(%1)").arg(sMain);
        sMain+=sIndexes;
    }

    sResult=sPrefix;

    if(sMain!="")
    {
        if((sResult!="")&&(!isPointerEnd(sResult)))
        {
            sResult+=" ";
        }

        sResult+=sMain;
    }

    return sResult;
}

QString XDemangle::itanium_parameterToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, QString sPrefix)
{
    QString sResult;

    QString sName=_nameToString(pSymbol,pParameter);

    if(pParameter->st==ST_TYPE)
    {
        QString sType=typeIdToString(pParameter->type,pSymbol->mode);

        sResult=sType;
    }
    else if(pParameter->st==ST_POINTER)
    {
        DPARAMETER lastParameter=getLastPointerParameter(pParameter);

        QString sPointer=itanium_getPointerString(pSymbol,pParameter);

        sResult=itanium_parameterToString(pSymbol,&lastParameter,sPointer);

        if((sPointer!="")&&(lastParameter.st!=ST_FUNCTION))
        {
            if((sPointer.at(0)!=QChar('*'))&&(sPointer.at(0)!=QChar('&')))
            {
                sResult+=" ";
            }

            sResult+=sPointer;
        }
    }
    else if(pParameter->st==ST_NAME)
    {
        sResult=sName;
    }
    else if(pParameter->st==ST_VARIABLE)
    {
        sResult=sName;
    }
    else if(pParameter->st==ST_TARGET)
    {
        if(pParameter->listTarget.count())
        {
            DPARAMETER parameter=pParameter->listTarget.at(0);

            sResult+=itanium_parameterToString(pSymbol,&parameter,"");
            sResult+=" ";
        }
        sResult+=sName;
    }
    else if(pParameter->st==ST_CONST)
    {
        sResult=pParameter->varConst.toString();
    }
    else if(pParameter->st==ST_TEMPLATE)
    {
        sResult+=sName;
        sResult+="<";

        int nNumberOfParameters=pParameter->listParameters.count();

        for(int i=0;i<nNumberOfParameters;i++)
        {
            DPARAMETER parameter=pParameter->listParameters.at(i);

            sResult+=itanium_parameterToString(pSymbol,&parameter,"");

            if(i!=(nNumberOfParameters-1))
            {
                sResult+=", ";
            }
        }

        if(_getStringEnd(sResult)==QChar('>'))
        {
            sResult+=" ";
        }

        sResult+=">";
    }
    else if(pParameter->st==ST_FUNCTION)
    {
        QString sFuncConvention=functionConventionIdToString(pParameter->functionConvention,pSymbol->mode);
        QString sQual=qualIdToStorageString(pParameter->nQualifier,pSymbol->mode);

        if(sFuncConvention!="")
        {
            sResult+=QString("%1 ").arg(sFuncConvention);
        }

        if(pParameter->listReturn.count())
        {
            DPARAMETER parameter=pParameter->listReturn.at(0);

            sResult+=QString("%1 ").arg(itanium_parameterToString(pSymbol,&parameter,""));
        }

        sResult+=sName;

        if(sPrefix!="")
        {
            sResult+=QString("(%1)").arg(sPrefix);
        }

        qint32 nNumberOfParameters=pParameter->listParameters.count();

        if(nNumberOfParameters)
        {
            sResult+="(";

            for(int i=0;i<nNumberOfParameters;i++)
            {
                DPARAMETER parameter=pParameter->listParameters.at(i);

                if(parameter.type==TYPE_VOID)
                {
                    break;
                }

                sResult+=itanium_parameterToString(pSymbol,&parameter,"");

                if(i!=(nNumberOfParameters-1))
                {
                    sResult+=", ";
                }
            }

            sResult+=")";
        }

        if(sQual!="")
        {
            sResult+=QString(" %1").arg(sQual);
        }
    }
    else if((pParameter->st==ST_VTABLE)||
            (pParameter->st==ST_TYPEINFO)||
            (pParameter->st==ST_GUARDVARIABLE)||
            (pParameter->st==ST_TRANSACTIONCLONE))
    {
        if(pParameter->listTarget.count())
        {
            DPARAMETER parameter=pParameter->listTarget.at(0);

            QString _sName=_nameToString(pSymbol,&parameter);

            if(pParameter->st==ST_VTABLE)
            {
                sResult+="vtable for ";
            }
            else if(pParameter->st==ST_TYPEINFO)
            {
                sResult+="typeinfo for ";
            }
            else if(pParameter->st==ST_GUARDVARIABLE)
            {
                sResult+="guard variable for ";
            }
            else if(pParameter->st==ST_TRANSACTIONCLONE)
            {
                sResult+="transaction clone for ";
            }

            sResult+=_sName;
        }
    }
    else if(pParameter->st==ST_NONVIRTUALTHUNK)
    {
        if(pParameter->listTarget.count())
        {
            DPARAMETER parameter=pParameter->listTarget.at(0);

            QString _sName=itanium_parameterToString(pSymbol,&parameter,"");

            if(pParameter->st==ST_NONVIRTUALTHUNK)
            {
                sResult+="non-virtual thunk to ";
            }

            sResult+=_sName;
        }
    }

    return sResult;
}

qint32 XDemangle::itanium_demangle_Encoding(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    pParameter->st=ST_VARIABLE;

    qint32 nNSSize=itanium_demangle_NameScope(pSymbol,pHdata,pParameter,sString);

    sString=sString.mid(nNSSize,-1);
    nResult+=nNSSize;

    qint32 nPSize=itanium_demangle_Function(pSymbol,pHdata,pParameter,sString,pHdata->listArgRef.count());

    sString=sString.mid(nPSize,-1);
    nResult+=nPSize;

    if(nPSize)
    {
        pParameter->st=ST_FUNCTION;
    }

    if(_compare(sString,"@")&&(pSymbol->mode==MODE_GCC_WIN32))
    {
        if(pParameter->functionConvention!=FC_FASTCALL)
        {
            pParameter->functionConvention=FC_STDCALL;
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;


    if(_compare(sString,"Z"))
    {
        nResult++;
        sString=sString.mid(1,-1);

        DPARAMETER parameter={};
        qint32 nESize=itanium_demangle_Encoding(pSymbol,pHdata,&parameter,sString);

        DNAME dname={};
        dname.sName=itanium_parameterToString(pSymbol,&parameter,"");

        pParameter->listDnames.append(dname);

        nResult+=nESize;
        sString=sString.mid(nESize,-1);
    }

    bool bNested=false;

    if(_compare(sString,"N"))
    {
        nResult++;
        sString=sString.mid(1,-1);

        bNested=true;
    }

    if(_compare(sString,"K"))
    {
        nResult++;
        sString=sString.mid(1,-1);

        pParameter->nQualifier=QUAL_CONST;
    }

    QString sAddString;

    while(sString!="")
    {
        pHdata->listArgRef.clear();

        DNAME dname={};

        bool bAdd=true;
        bool bSpecial=false;

        if(isReplaceStringPresent(pSymbol,pHdata,sString))
        {
            SIGNATURE signature=getReplaceStringSignature(pSymbol,pHdata,sString);

            dname.sName=signature.sKey;

            nResult+=signature.nSize;
            sString=sString.mid(signature.nSize,-1);

            bAdd=false;
        }
        else if(_compare(sString,"St"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            dname.sName="std";

            bAdd=false;
            bSpecial=true;
        }
        else if(_compare(sString,"Sa"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            dname.sName="std::allocator";

            bAdd=false;
            bSpecial=false;
        }
        else if(_compare(sString,"Sb"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            dname.sName="std::basic_string";

            bAdd=false;
            bSpecial=false;
        }
        else if(_compare(sString,"Ss"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            dname.sName="std::string";

            bAdd=false;
            bSpecial=false;
        }
        else if(_compare(sString,"cv")) // Conversion
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            DPARAMETER parameter={};

            qint32 nTSize=itanium_demangle_Type(pSymbol,pHdata,&parameter,sString);

            nResult+=nTSize;
            sString=sString.mid(nTSize,-1);

            dname.sName=QString("operator %1").arg(itanium_parameterToString(pSymbol,&parameter,""));

            // TODO _
        }
        else if(isSignaturePresent(sString,&(pHdata->mapOperators)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapOperators));

            dname._operator=(OP)signature.nValue;

            nResult+=signature.nSize;
            sString=sString.mid(signature.nSize,-1);
        }
        else
        {
            STRING string=readString(pHdata,sString,pSymbol->mode);

            dname.sName=string.sString;

            nResult+=string.nSize;
            sString=sString.mid(string.nSize,-1);

            if(string.nSize==0)
            {
                pSymbol->bIsValid=false;
            }
        }

        if(sAddString!="")
        {
            sAddString+="::";
        }

        sAddString+=dname.sName;

        if(_compare(sString,"I")) // Template
        {
            nResult++;
            sString=sString.mid(1,-1);

            if(bAdd)
            {
                addStringRef(pSymbol,pHdata,sAddString);
            }

            DPARAMETER parameter={};
            parameter.st=ST_TEMPLATE;
            qint32 nPSize=itanium_demangle_Parameters(pSymbol,pHdata,&parameter,sString);

            nResult+=nPSize;
            sString=sString.mid(nPSize,-1);

            QString sTemplate=itanium_parameterToString(pSymbol,&parameter,"");

            dname.sName+=sTemplate;
            sAddString+=sTemplate;

            int nNumberOfArgs=parameter.listParameters.count();

            for(int i=0;i<nNumberOfArgs;i++)
            {
                DPARAMETER _parameter=parameter.listParameters.at(i);
                pHdata->listArgRef.append(itanium_parameterToString(pSymbol,&_parameter,""));
            }
        }

        pParameter->listDnames.append(dname);

        if(bNested&&_compare(sString,"E"))
        {
            nResult++;
            sString=sString.mid(1,-1);

            break;
        }
        else if((!bNested)&&(!bSpecial))
        {
            break;
        }

        if(!pSymbol->bIsValid)
        {
            break;
        }

        if((sAddString!="")&&(bAdd))
        {
            addStringRef(pSymbol,pHdata,sAddString);
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_Function(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, bool bReturn)
{
    qint32 nResult=0;

    if(bReturn)
    {
        DPARAMETER parameter={};

        qint32 nRSize=itanium_demangle_Type(pSymbol,pHdata,&parameter,sString);

        pParameter->listReturn.append(parameter);

        nResult+=nRSize;
        sString=sString.mid(nRSize,-1);
    }

    qint32 nFSize=itanium_demangle_Parameters(pSymbol,pHdata,pParameter,sString);

    nResult+=nFSize;
    sString=sString.mid(nFSize,-1);

    return nResult;
}

qint32 XDemangle::itanium_demangle_Parameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    while(sString!="")
    {
        DPARAMETER parameter={};

        qint32 nPSize=itanium_demangle_Type(pSymbol,pHdata,&parameter,sString);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);

        pParameter->listParameters.append(parameter);

        if(nPSize==0)
        {
            pSymbol->bIsValid=false;
        }

        if(!pSymbol->bIsValid)
        {
            break;
        }

        if(_compare(sString,"E"))
        {
            nResult++;
            sString=sString.mid(1,-1);

            break;
        }

        if(_compare(sString,"@")&&(pSymbol->mode==MODE_GCC_WIN32))
        {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_Type(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    if(isReplaceArgPresent(pSymbol,pHdata,sString))
    {
        SIGNATURE signature=getReplaceArgSignature(pSymbol,pHdata,sString);

        DNAME dname={};
        dname.sName=signature.sKey;

        pParameter->listDnames.append(dname);

        pParameter->st=ST_NAME;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }
    else if(isSignaturePresent(sString,&(pHdata->mapPointerTypes))) // Pointers
    {
        qint32 nPSize=itanium_demangle_PointerType(pSymbol,pHdata,pParameter,sString);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);
    }
    else if(_compare(sString,"U"))
    {
        nResult+=1;
        sString=sString.mid(1,-1);

        pParameter->st=ST_TARGET;

        qint32 nNSSize=itanium_demangle_NameScope(pSymbol,pHdata,pParameter,sString);

        nResult+=nNSSize;
        sString=sString.mid(nNSSize,-1);

        DPARAMETER parameter={};

        qint32 nTSize=itanium_demangle_Type(pSymbol,pHdata,&parameter,sString);

        pParameter->listTarget.append(parameter);

        nResult+=nTSize;
        sString=sString.mid(nTSize,-1);
    }
    else if(_compare(sString,"A")) // Array
    {
        nResult+=1;
        sString=sString.mid(1,-1);

        NUMBER number=readNumber(pHdata,sString,pSymbol->mode);
        pParameter->listIndexes.append(number.nValue);

        nResult+=number.nSize;
        sString=sString.mid(number.nSize,-1);

        pParameter->st=ST_POINTER;

        if(_compare(sString,"_"))
        {
            nResult+=1;
            sString=sString.mid(1,-1);
        }
        else
        {
            pSymbol->bIsValid=false;
        }

        DPARAMETER parameter={};

        qint32 nPSize=itanium_demangle_Type(pSymbol,pHdata,&parameter,sString);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);

        pParameter->listPointer.append(parameter);
    }
    else if(_compare(sString,"F")) // Function
    {
        nResult+=1;
        sString=sString.mid(1,-1);

        pParameter->st=ST_FUNCTION;

        qint32 nFSize=itanium_demangle_Function(pSymbol,pHdata,pParameter,sString,true);

        nResult+=nFSize;
        sString=sString.mid(nFSize,-1);
    }
    else if(_compare(sString,"L")) // Const
    {
        pParameter->st=ST_CONST;
        nResult+=1;
        sString=sString.mid(1,-1);

        if(_compare(sString,"i")) // Number
        {
            nResult+=1;
            sString=sString.mid(1,-1);

            NUMBER number=readNumberS(pHdata,sString,pSymbol->mode);

            pParameter->varConst=number.nValue;

            nResult+=number.nSize;
            sString=sString.mid(number.nSize,-1);
        }
        else if(_compare(sString,"b"))
        {
            nResult+=1;
            sString=sString.mid(1,-1);

            if(_compare(sString,"0"))
            {
                pParameter->varConst="false";
            }
            else if(_compare(sString,"1"))
            {
                pParameter->varConst="true";
            }
            else
            {
            #ifdef QT_DEBUG
                qDebug("TODO: unknown bool");
            #endif
                pSymbol->bIsValid=false;
            }

            nResult+=1;
            sString=sString.mid(1,-1);
        }
        else
        {
        #ifdef QT_DEBUG
            qDebug("TODO: unknown const");
        #endif
            pSymbol->bIsValid=false;
        }

        if(_compare(sString,"E"))
        {
            nResult+=1;
            sString=sString.mid(1,-1);
        }
    }
//    else if(_compare(sString,"T_"))
//    {
//        nResult+=2;
//        sString=sString.mid(2,-1);
//    }
    else if(isSignaturePresent(sString,&(pHdata->mapTypes))) // Simple types
    {
        pParameter->st=ST_TYPE;
        SIGNATURE signatureType=getSignature(sString,&(pHdata->mapTypes));
        pParameter->type=(TYPE)signatureType.nValue;

        nResult+=signatureType.nSize;
        sString=sString.mid(signatureType.nSize,-1);
    }
    else if(_compare(sString,"@"))
    {
        if(pSymbol->mode!=MODE_GCC_WIN32)
        {
            pSymbol->bIsValid=false;
        }
    }
    else
    {
        pParameter->st=ST_NAME;

        qint32 nNSSize=itanium_demangle_NameScope(pSymbol,pHdata,pParameter,sString);

        nResult+=nNSSize;
        sString=sString.mid(nNSSize,-1);

        if(nNSSize==0)
        {
        #ifdef QT_DEBUG
            qDebug("TODO: type");
        #endif
            pSymbol->bIsValid=false;
        }
    }

    if((nResult>1)&&(pParameter->st!=ST_CONST))
    {
        QString sParam=itanium_parameterToString(pSymbol,pParameter,"");

        addStringRef(pSymbol,pHdata,sParam);
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_PointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
    {
        pParameter->st=ST_POINTER;
        SIGNATURE signature=getSignature(sString,&(pHdata->mapPointerTypes));
        pParameter->nQualifier=signature.nValue;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);

        DPARAMETER parameter={};

        qint32 nPSize=itanium_demangle_Type(pSymbol,pHdata,&parameter,sString);

        nResult+=nPSize;
        sString=sString.mid(nPSize,-1);

        pParameter->listPointer.append(parameter);
    }

    return nResult;
}

QString XDemangle::itanium_getPointerString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter)
{
    QString sResult;

    DPARAMETER parameter=*pParameter;

    QString sPrefix;
    QString sIndexes;
    QString sMain;

    int i=0;

    while(parameter.st==ST_POINTER)
    {
        QString sPointer=qualIdToPointerString(parameter.nQualifier,pSymbol->mode);

        if(i==0)
        {
            sMain=sPointer;
        }
        else
        {
            if((sPrefix!="")&&(sPrefix.at(0)!=QChar('*'))&&(sPrefix.at(0)!=QChar('&')))
            {
                sPointer+=" ";
            }

            sPrefix=sPrefix.prepend(sPointer);
        }

        if(parameter.listIndexes.count())
        {
            sIndexes=sIndexes.append(QString("[%1]").arg(parameter.listIndexes.at(0)));
        }

        if(parameter.listPointer.count())
        {
            parameter=parameter.listPointer.at(0);
        }
        else
        {
            break;
        }

        i++;
    }

    sResult=sPrefix;

    if(sIndexes!="")
    {
        if(sResult!="")
        {
            sResult+=" ";
        }

        sMain=QString("(%1)").arg(sMain);
        sResult+=sMain;
        sResult+=" ";

        sResult+=sIndexes;
    }
    else
    {
        sResult+=sMain;
    }

    return sResult;
}

QString XDemangle::demangle(QString sString, XDemangle::MODE mode)
{
    QString sResult;

    DSYMBOL symbol=_getSymbol(sString,mode);

    sResult=dsymbolToString(symbol);

    if(sResult=="")
    {
        sResult=sString;
    }

    return sResult;
}

XDemangle::DSYMBOL XDemangle::_getSymbol(QString sString, XDemangle::MODE mode)
{
    DSYMBOL result={};

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        result=ms_getSymbol(sString,mode);
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        result=itanium_getSymbol(sString,mode);
    }

    return result;
}

XDemangle::DSYMBOL XDemangle::ms_getSymbol(QString sString, XDemangle::MODE mode,HDATA *pHdata)
{
    DSYMBOL result={};

    result.bIsValid=true;
    result.mode=mode;

    HDATA hdata={};

    if(pHdata)
    {
        hdata=*pHdata;
    }
    else
    {
        hdata=getHdata(mode);
    }

    if(_compare(sString,"."))
    {
        result.nSize+=1;
        sString=sString.mid(1,-1);

        DPARAMETER parameter={};

        qint32 nTSize=ms_demangle_Type(&result,&hdata,&parameter,sString,MSDT_RESULT);

        result.paramMain.listTarget.append(parameter);

        sString=sString.mid(nTSize,-1);
        result.nSize+=nTSize;

        result.paramMain.st=ST_TYPEINFO;
    }
    else if(_compare(sString,"??@"))
    {
        // TODO MD5
    #ifdef QT_DEBUG
        qDebug("TODO: MD5");
    #endif
    }
    else if(_compare(sString,"?"))
    {
        result.nSize+=1;
        sString=sString.mid(1,-1);

        // TODO demangleSpecialIntrinsic

        if(isSignaturePresent(sString,&(hdata.mapSpecInstr)))
        {
            SIGNATURE signature=getSignature(sString,&(hdata.mapSpecInstr));
            result.paramMain.st=(ST)signature.nValue;

            sString=sString.mid(signature.nSize,-1);
            result.nSize+=signature.nSize;

            if( (result.paramMain.st==ST_VBTABLE)||
                (result.paramMain.st==ST_VFTABLE)||
                (result.paramMain.st==ST_LOCALVFTABLE)||
                (result.paramMain.st==ST_RTTICOMPLETEOBJLOCATOR))
            {
                qint32 nSTSize=ms_demangle_SpecialTable(&result,&hdata,&(result.paramMain),sString);

                sString=sString.mid(nSTSize,-1);
                result.nSize+=nSTSize;
            }
            else if((result.paramMain.st==ST_LOCALSTATICGUARD)||
                    (result.paramMain.st==ST_LOCALSTATICTHREADGUARD))
            {
                qint32 nSTSize=ms_demangle_LocalStaticGuard(&result,&hdata,&(result.paramMain),sString);

                sString=sString.mid(nSTSize,-1);
                result.nSize+=nSTSize;
            }
            else if((result.paramMain.st==ST_RTTIBASECLASSARRAY)||
                    (result.paramMain.st==ST_RTTICLASSHIERARCHYDESCRIPTOR))
            {
                qint32 nSTSize=ms_demangle_UntypedVariable(&result,&hdata,&(result.paramMain),sString);

                sString=sString.mid(nSTSize,-1);
                result.nSize+=nSTSize;
            }
            else if((result.paramMain.st==ST_STRINGLITERALSYMBOL))
            {
                qint32 nSTSize=ms_demangle_StringLiteralSymbol(&result,&hdata,&(result.paramMain),sString);


                sString=sString.mid(nSTSize,-1);
                result.nSize+=nSTSize;
            }
        }
        else
        {
            qint32 nDSize=ms_demangle_Declarator(&result,&hdata,&(result.paramMain),sString);

            sString=sString.mid(nDSize,-1);
            result.nSize+=nDSize;
        }
    }

    if(pHdata)
    {
        *pHdata=hdata;
    }

    return result;
}

XDemangle::DSYMBOL XDemangle::itanium_getSymbol(QString sString, XDemangle::MODE mode)
{
    DSYMBOL result={};

    if( _compare(sString,"_Z")||
        (_compare(sString,"@_Z")&&(mode==MODE_GCC_WIN32))||
        (_compare(sString,"__Z")&&((mode==MODE_GCC)||(mode==MODE_GCC_MAC))))
    {
        HDATA hdata=getHdata(mode);

        result.bIsValid=true;
        result.mode=mode;

        if(_compare(sString,"@_Z")) // Fastcall
        {
            result.paramMain.st=ST_FUNCTION; // TODO Check !!!
            result.paramMain.functionConvention=FC_FASTCALL;
            sString=sString.mid(3,-1);
            result.nSize+=3;
        }
        else if(_compare(sString,"_Z"))
        {
            sString=sString.mid(2,-1);
            result.nSize+=2;
        }
        else if(_compare(sString,"__Z"))
        {
            sString=sString.mid(3,-1);
            result.nSize+=3;
        }

        if(isSignaturePresent(sString,&(hdata.mapSpecInstr)))
        {
            SIGNATURE signature=getSignature(sString,&(hdata.mapSpecInstr));

            result.paramMain.st=(ST)signature.nValue;
            sString=sString.mid(signature.nSize,-1);
            result.nSize+=signature.nSize;

            DPARAMETER parameter={};

            if( (result.paramMain.st==ST_TYPEINFO)||
                (result.paramMain.st==ST_VTABLE)||
                (result.paramMain.st==ST_GUARDVARIABLE)||
                (result.paramMain.st==ST_TRANSACTIONCLONE))
            {
                qint32 nNSSize=itanium_demangle_NameScope(&result,&hdata,&parameter,sString);
                sString=sString.mid(nNSSize,-1);
                result.nSize+=nNSSize;
            }
            else if(result.paramMain.st==ST_NONVIRTUALTHUNK)
            {
                NUMBER number=readNumberS(&hdata,sString,result.mode);

                sString=sString.mid(number.nSize,-1);
                result.nSize+=number.nSize;

                if(_compare(sString,"_"))
                {
                    sString=sString.mid(1,-1);
                    result.nSize+=1;
                }

                qint32 nESize=itanium_demangle_Encoding(&result,&hdata,&parameter,sString);
                sString=sString.mid(nESize,-1);
                result.nSize+=nESize;
            }

            result.paramMain.listTarget.append(parameter);
        }
        else
        {
            qint32 nESize=itanium_demangle_Encoding(&result,&hdata,&(result.paramMain),sString);

            sString=sString.mid(nESize,-1);
            result.nSize+=nESize;
        }

//    #ifdef QT_DEBUG
//        for(int i=0;i<hdata.listStringRef.count();i++)
//        {
//            qDebug("%d: %s",i,hdata.listStringRef.at(i).toLatin1().data());
//        }
//    #endif
    }

    return result;
}

XDemangle::MODE XDemangle::detectMode(QString sString)
{
    MODE result=MODE_GCC;

    if(_compare(sString,"?")&&(sString.contains("@")))
    {
        result=MODE_MSVC;
    }
    else if(_compare(sString,"@_Z")||(_compare(sString,"_Z")&&(sString.section("@",-1,-1).toUInt())))
    {
        result=MODE_GCC_WIN32;
    }
    else if(_compare(sString,"_Z"))
    {
        result=MODE_GCC;
    }
    else if(_compare(sString,"__Z"))
    {
        result=MODE_GCC_MAC;
    }

    return result;
}

QList<XDemangle::MODE> XDemangle::getAllModes()
{
    QList<MODE> listResult;

    listResult.append(MODE_AUTO);
    listResult.append(MODE_MSVC32);
    listResult.append(MODE_GCC);
    listResult.append(MODE_GCC_MAC);
    listResult.append(MODE_GCC_WIN32);
    listResult.append(MODE_BORLAND32);
    listResult.append(MODE_WATCOM);

    return listResult;
}

QList<XDemangle::MODE> XDemangle::getSupportedModes()
{
    QList<MODE> listResult;

    listResult.append(MODE_AUTO);
    listResult.append(MODE_GCC);
    listResult.append(MODE_GCC_MAC);
    listResult.append(MODE_GCC_WIN32);
    listResult.append(MODE_MSVC);
    listResult.append(MODE_MSVC32);
    listResult.append(MODE_MSVC64);

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

void XDemangle::reverseList(QList<XDemangle::DNAME> *pList)
{
    int nNumberOfRecords=pList->count();

    for(int i=0;i<(nNumberOfRecords/2);i++)
    {
        pList->swap(i,nNumberOfRecords-(1+i));
    }
}

XDemangle::HDATA XDemangle::getHdata(XDemangle::MODE mode)
{
    XDemangle::HDATA result={};

    result.mapPointerTypes=getPointerTypes(mode);
    result.mapObjectClasses=getObjectClasses(mode);
    result.mapTypes=getTypes(mode);
    result.mapTagTypes=getTagTypes(mode);
    result.mapStorageClasses=getStorageClasses(mode);
    result.mapAccessMods=getAccessMods(mode);
    result.mapFunctionConventions=getFunctionConventions(mode);
    result.mapOperators=getOperators(mode);
    result.mapNumbers=getNumbers(mode);
    result.mapSymNumbers=getSymNumbers(mode);
    result.mapQualifiers=getQualifiers(mode);
    result.mapSpecInstr=getSpecInstr(mode);

    return result;
}

QString XDemangle::dsymbolToString(XDemangle::DSYMBOL symbol)
{
    QString sResult;

    if(symbol.bIsValid)
    {
        if(getSyntaxFromMode(symbol.mode)==SYNTAX_MICROSOFT)
        {
            QString sName=_nameToString(&symbol,&(symbol.paramMain));
            sResult=ms_parameterToString(&symbol,&(symbol.paramMain),sName,"");
        }
        else if(getSyntaxFromMode(symbol.mode)==SYNTAX_ITANIUM)
        {
            sResult=itanium_parameterToString(&symbol,&(symbol.paramMain),"");
        }
    }

    return sResult;
}

XDemangle::STRING XDemangle::readString(HDATA *pHdata,QString sString, XDemangle::MODE mode)
{
    STRING result={};

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        result.sString=sString.section("@",0,0);
        result.sOriginal=result.sString;

        if(sString.contains("@"))
        {
            result.sOriginal+="@";
        }

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
            result.sOriginal+=sString.leftRef(number.nSize);
            sString=sString.mid(number.nSize,-1);
            result.sString=sString.left(number.nValue);
            result.nSize=number.nSize+result.sString.size();
            result.sOriginal+=result.sString;
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
        else if(isSignaturePresent(sString,&(pHdata->mapSymNumbers)))
        {
            while((sString!="")&&(!_compare(sString,"@")))
            {
                result.nValue*=16;

                SIGNATURE signature=getSignature(sString,&(pHdata->mapSymNumbers));

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

XDemangle::NUMBER XDemangle::readNumberS(XDemangle::HDATA *pHdata, QString sString, XDemangle::MODE mode)
{
    NUMBER result={};

    bool bNeg=false;

    if(_compare(sString,"n"))
    {
        result.nSize+=1;
        sString=sString.mid(1,-1);

        bNeg=true;
    }

    NUMBER number=readNumber(pHdata,sString,mode);

    qint64 nValue=number.nValue;

    if(bNeg)
    {
        nValue=-nValue;
    }

    result.nSize+=number.nSize;
    result.nValue=nValue;

    return result;
}

XDemangle::NUMBER XDemangle::readSymNumber(XDemangle::HDATA *pHdata, QString sString, XDemangle::MODE mode)
{
    NUMBER result={};

    if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        while((sString!="")&&(isSignaturePresent(sString,&(pHdata->mapSymNumbers))))
        {
            result.nValue*=36;

            SIGNATURE signature=getSignature(sString,&(pHdata->mapSymNumbers));

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

bool XDemangle::isPointerEnd(QString sString)
{
    bool bResult=false;

    bResult=(_getStringEnd(sString)==QChar('*'))||(_getStringEnd(sString)==QChar('&'))||(_getStringEnd(sString)==QChar('_'));

    return bResult;
}

bool XDemangle::isSignaturePresent(QString sString, QMap<QString, quint32> *pMap)
{
    bool bResult=false;

    QMapIterator<QString,quint32> i(*pMap);

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

XDemangle::SIGNATURE XDemangle::getSignature(QString sString, QMap<QString, quint32> *pMap)
{
    SIGNATURE result={};

    QMapIterator<QString,quint32> i(*pMap);

    while(i.hasNext())
    {
        i.next();

        QString sKey=i.key();
        qint32 nValue=i.value();

        if(_compare(sString,sKey))
        {
            result.nSize=sKey.size();
            result.nValue=nValue;
            result.sKey=sKey;

            break;
        }
    }

    return result;
}

QMap<QString, quint32> XDemangle::getObjectClasses(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

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

QMap<QString, quint32> XDemangle::getTypes(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("@",TYPE_NONE);
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

QMap<QString, quint32> XDemangle::getTagTypes(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("T",TYPE_UNION);
        mapResult.insert("U",TYPE_STRUCT);
        mapResult.insert("V",TYPE_CLASS);
        mapResult.insert("W4",TYPE_ENUM);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getPointerTypes(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
//        mapResult.insert("?",PM_NONE); // For classes return
        mapResult.insert("P",QUAL_POINTER);
        mapResult.insert("A",QUAL_REFERENCE);
        mapResult.insert("Q",QUAL_POINTER|QUAL_CONST);
        mapResult.insert("R",QUAL_POINTER|QUAL_VOLATILE);
        mapResult.insert("S",QUAL_POINTER|QUAL_CONST|QUAL_VOLATILE);
        mapResult.insert("$$Q",QUAL_DOUBLEREFERENCE);
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        mapResult.insert("O",QUAL_DOUBLEREFERENCE);
        mapResult.insert("P",QUAL_POINTER);
        mapResult.insert("R",QUAL_REFERENCE);
        mapResult.insert("K",QUAL_CONST);
        mapResult.insert("V",QUAL_VOLATILE);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getStorageClasses(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

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
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        mapResult.insert("K",SC_CONST);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getAccessMods(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("0",FM_PRIVATE|FM_STATIC);             // Member
        mapResult.insert("1",FM_PROTECTED|FM_STATIC);           // Member
        mapResult.insert("2",FM_PUBLIC|FM_STATIC);              // Member
        mapResult.insert("3",FM_GLOBAL);                        // Variable
        mapResult.insert("4",FM_FUNCTIONLOCAL|FM_STATIC);       // Variable
        mapResult.insert("9",FM_EXTERNC|FM_NOPARAMETERLIST);
        mapResult.insert("A",FM_PRIVATE);
        mapResult.insert("B",FM_PRIVATE|FM_FAR);
        mapResult.insert("C",FM_PRIVATE|FM_STATIC);
        mapResult.insert("D",FM_PRIVATE|FM_STATIC|FM_FAR);
        mapResult.insert("E",FM_PRIVATE|FM_VIRTUAL);
        mapResult.insert("F",FM_PRIVATE|FM_VIRTUAL|FM_FAR);
        mapResult.insert("I",FM_PROTECTED);
        mapResult.insert("J",FM_PROTECTED|FM_FAR);
        mapResult.insert("K",FM_PROTECTED|FM_STATIC);
        mapResult.insert("L",FM_PROTECTED|FM_STATIC|FM_FAR);
        mapResult.insert("M",FM_PROTECTED|FM_VIRTUAL);
        mapResult.insert("N",FM_PROTECTED|FM_VIRTUAL|FM_FAR);
        mapResult.insert("Q",FM_PUBLIC);
        mapResult.insert("R",FM_PUBLIC|FM_FAR);
        mapResult.insert("S",FM_PUBLIC|FM_STATIC);
        mapResult.insert("T",FM_PUBLIC|FM_STATIC|FM_FAR);
        mapResult.insert("U",FM_PUBLIC|FM_VIRTUAL);
        mapResult.insert("V",FM_PUBLIC|FM_VIRTUAL|FM_FAR);
        mapResult.insert("W",FM_PUBLIC|FM_VIRTUAL|FM_STATICTHISADJUST);
        mapResult.insert("X",FM_PUBLIC|FM_VIRTUAL|FM_STATICTHISADJUST|FM_FAR);
        mapResult.insert("Y",FM_GLOBAL);
        mapResult.insert("Z",FM_GLOBAL|FM_FAR);
        mapResult.insert("$",FM_VIRTUALTHISADJUST);
        mapResult.insert("$R0",FM_VIRTUALTHISADJUST|FM_VIRTUALTHISADJUSTEX|FM_PRIVATE|FM_VIRTUAL);
        mapResult.insert("$R1",FM_VIRTUALTHISADJUST|FM_VIRTUALTHISADJUSTEX|FM_PRIVATE|FM_VIRTUAL|FM_FAR);
        mapResult.insert("$R2",FM_VIRTUALTHISADJUST|FM_VIRTUALTHISADJUSTEX|FM_PROTECTED|FM_VIRTUAL);
        mapResult.insert("$R3",FM_VIRTUALTHISADJUST|FM_VIRTUALTHISADJUSTEX|FM_PROTECTED|FM_VIRTUAL|FM_FAR);
        mapResult.insert("$R4",FM_VIRTUALTHISADJUST|FM_VIRTUALTHISADJUSTEX|FM_PUBLIC|FM_VIRTUAL|FM_FAR);
        mapResult.insert("$R5",FM_VIRTUALTHISADJUST|FM_VIRTUALTHISADJUSTEX|FM_PUBLIC|FM_VIRTUAL|FM_FAR);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getFunctionConventions(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

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

QMap<QString, quint32> XDemangle::getOperators(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

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
        mapResult.insert("C1",OP_CONSTRUCTOR);
        mapResult.insert("C2",OP_CONSTRUCTOR);
        mapResult.insert("D0",OP_DESTRUCTOR);
        mapResult.insert("D1",OP_DESTRUCTOR);
        mapResult.insert("D2",OP_DESTRUCTOR);
        mapResult.insert("nw",OP_NEW);
        mapResult.insert("dl",OP_DELETE);
        mapResult.insert("aS",OP_ASSIGN);               // operator=
        mapResult.insert("rs",OP_RIGHTSHIFT);           // operator>>
        mapResult.insert("ls",OP_LEFTSHIFT);            // operator<<
        mapResult.insert("nt",OP_LOGICALNOT);           // operator!
        mapResult.insert("eq",OP_EQUALS);               // operator==
        mapResult.insert("ne",OP_NOTEQUALS);            // operator!=
        mapResult.insert("ix",OP_ARRAYSUBSCRIPT);       // operator[]
        mapResult.insert("pt",OP_POINTER);              // operator->
        mapResult.insert("de",OP_DEREFERENCE);          // operator*
        mapResult.insert("ad",OP_REFERENCE);            // operator&
        mapResult.insert("pp",OP_INCREMENT);            // operator++
        mapResult.insert("mm",OP_DECREMENT);            // operator--
        mapResult.insert("mi",OP_MINUS);                // operator-
        mapResult.insert("pl",OP_PLUS);                 // operator+
        mapResult.insert("an",OP_BITWISEAND);           // operator&
        mapResult.insert("pm",OP_MEMBERPOINTER);        // operator->*
        mapResult.insert("ml",OP_MULTIPLE);             // operator*
        mapResult.insert("dv",OP_DIVIDE);               // operator/
        mapResult.insert("rm",OP_MODULUS);              // operator%
        mapResult.insert("lt",OP_LESSTHAN);             // operator<
        mapResult.insert("le",OP_LESSTHANEQUAL);        // operator<=
        mapResult.insert("gt",OP_GREATERTHAN);          // operator>
        mapResult.insert("ge",OP_GREATERTHANEQUAL);     // operator>=
        mapResult.insert("cm",OP_COMMA);                // operator,
        mapResult.insert("cl",OP_PARENS);               // operator()
        mapResult.insert("co",OP_BITWISENOT);           // operator~
        mapResult.insert("eo",OP_BITWISEXOR);           // operator^
        mapResult.insert("or",OP_BITWISEOR);            // operator|
        mapResult.insert("aa",OP_LOGICALAND);           // operator&&
        mapResult.insert("oo",OP_LOGICALOR);            // operator||
        mapResult.insert("mL",OP_TIMESEQUAL);           // operator*=
        mapResult.insert("pL",OP_PLUSEQUAL);            // operator+=
        mapResult.insert("mI",OP_MINUSEQUAL);           // operator-=
        mapResult.insert("dV",OP_DIVEQUAL);             // operator/=
        mapResult.insert("rM",OP_MODEQUAL);             // operator%=
        mapResult.insert("rS",OP_RSHEQUAL);             // operator>>=
        mapResult.insert("lS",OP_LSHEQUAL);             // operator<<=
        mapResult.insert("aN",OP_BITWISEANDEQUAL);      // operator&=
        mapResult.insert("oR",OP_BITWISEOREQUAL);       // operator|=
        mapResult.insert("eO",OP_BITWISEXOREQUAL);      // operator^=
        mapResult.insert("na",OP_ARRAYNEW);             // operator new[]
        mapResult.insert("da",OP_ARRAYDELETE);          // operator delete[]
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getNumbers(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if( (getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)||
        (getSyntaxFromMode(mode)==SYNTAX_ITANIUM))
    {        
        for(quint32 i=0;i<10;i++)
        {
            mapResult.insert(QString("%1").arg(i),i);
        }
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getLineNumbers(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {  
        for(quint32 i=0;i<10;i++)
        {
            mapResult.insert(QString("?%1?").arg(i),i+1);
        }
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getSymNumbers(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        for(quint32 i=0;i<16;i++)
        {
            mapResult.insert(QString("%1").arg(QChar('A'+i)),i);
        }
    }
    else if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        for(quint32 i=0;i<10;i++)
        {
            mapResult.insert(QString("%1").arg(QChar('0'+i)),i);
        }

        for(quint32 i=0;i<26;i++)
        {
            mapResult.insert(QString("%1").arg(QChar('A'+i)),i+10);
        }
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getQualifiers(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("A",QUAL_NONE);
        mapResult.insert("B",QUAL_CONST);
        mapResult.insert("C",QUAL_VOLATILE);
        mapResult.insert("D",QUAL_CONST|QUAL_VOLATILE);
        mapResult.insert("Q",QUAL_MEMBER|QUAL_NONE);
        mapResult.insert("R",QUAL_MEMBER|QUAL_CONST);
        mapResult.insert("S",QUAL_MEMBER|QUAL_VOLATILE);
        mapResult.insert("T",QUAL_MEMBER|QUAL_CONST|QUAL_VOLATILE);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getSpecInstr(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
        mapResult.insert("?_7",ST_VFTABLE);
        mapResult.insert("?_8",ST_VBTABLE);
        mapResult.insert("?_B",ST_LOCALSTATICGUARD);
        mapResult.insert("?_C",ST_STRINGLITERALSYMBOL);
        mapResult.insert("?_R2",ST_RTTIBASECLASSARRAY);
        mapResult.insert("?_R3",ST_RTTICLASSHIERARCHYDESCRIPTOR);
        mapResult.insert("?_R4",ST_RTTICOMPLETEOBJLOCATOR);
        mapResult.insert("?_S",ST_LOCALVFTABLE);
        mapResult.insert("?__J",ST_LOCALSTATICTHREADGUARD);
    }
    else
    if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        mapResult.insert("TI",ST_TYPEINFO);
        mapResult.insert("TV",ST_VTABLE);
        mapResult.insert("Th",ST_NONVIRTUALTHUNK);
        mapResult.insert("GV",ST_GUARDVARIABLE);
        mapResult.insert("GT",ST_TRANSACTIONCLONE);
    }

    return mapResult;
}
