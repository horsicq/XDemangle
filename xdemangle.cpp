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
        case TYPE_NONE:            sResult=QString("");                    break;
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

QString XDemangle::functionModIdToString(quint32 nFunctionMod, XDemangle::MODE mode)
{
    Q_UNUSED(mode) // TODO

    QString sResult;

    if(nFunctionMod==0)
    {
        sResult=QString("Unknown");
    }

    if      (nFunctionMod&FM_PRIVATE)       sResult+=QString("private:");
    else if (nFunctionMod&FM_PROTECTED)     sResult+=QString("protected:");
    else if (nFunctionMod&FM_PUBLIC)        sResult+=QString("public:");

    if((nFunctionMod&FM_STATIC)||(nFunctionMod&FM_VIRTUAL))
    {
        if(sResult!="")     sResult+=" ";

        if      (nFunctionMod&FM_STATIC)        sResult+=QString("static");
        else if (nFunctionMod&FM_VIRTUAL)       sResult+=QString("virtual");
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
    QString sResult;

    if      (nQual&QUAL_POINTER)                sResult="*";
    else if (nQual&QUAL_REFERENCE)              sResult="&";

    return sResult;
}

QString XDemangle::qualIdToStorageString(quint32 nQual, XDemangle::MODE mode)
{
    QString sResult;

    if(nQual&QUAL_CONST) sResult="const";

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
        pParameter->st=ST_VARIABLE;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);

        qint32 nFNSize=ms_demangle_FullName(pSymbol,pHdata,pParameter,sString);

        nResult+=nFNSize;
        sString=sString.mid(nFNSize,-1);
    }
    else if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
    {
        if(ms_isPointerMember(pSymbol,pHdata,sString))
        {
            qDebug("TODO: PointerMember");
        }
        else if(pSymbol->bIsValid)
        {
            qint32 nPTSize=ms_demangle_PointerType(pSymbol,pHdata,pParameter,sString);

            nResult+=nPTSize;
            sString=sString.mid(nPTSize,-1);
        }
    }
    else if(isSignaturePresent(sString,&(pHdata->mapTypes)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapTypes));
        pParameter->type=(TYPE)signature.nValue;
        pParameter->st=ST_VARIABLE;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }
    else
    {
        qDebug("TODO: TYPE");
        pSymbol->bIsValid=false;
    }

    // TODO Check isValid

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
        qDebug("TODO: function");
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

qint32 XDemangle::ms_demangle_FullName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pDParameter, QString sString)
{
    qint32 nResult=0;

    qint32 nUnkName=ms_demangle_UnkName(pSymbol,pHdata,pDParameter,sString,NB_SIMPLE);
    nResult+=nUnkName;

    sString=sString.mid(nUnkName,-1);

    qint32 nNameScope=ms_demangle_NameScope(pSymbol,pHdata,pDParameter,sString);
    nResult+=nNameScope;

    sString=sString.mid(nNameScope,-1);

    reverseList(&(pDParameter->listDnames));

    return nResult;
}

qint32 XDemangle::ms_demangle_UnkName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pDParameter, QString sString, NB nb)
{
    qint32 nResult=0;

    if(isReplaceStringPresent(pSymbol,pHdata,sString))
    {
        SIGNATURE signature=getReplaceStringSignature(pSymbol,pHdata,sString);
        // TODO Error empty String
        DNAME dname={};
        dname.sName=signature.sKey;

        pDParameter->listDnames.append(dname);

        sString=sString.mid(signature.nSize,-1);
        nResult+=signature.nSize;
    }
    else if(_compare(sString,"?$"))
    {
        qint32 nTSize=ms_demangle_Template(pSymbol,pHdata,pDParameter,sString,nb);
        sString=sString.mid(nTSize,-1);
        nResult+=nTSize;
    }
    else if(isSignaturePresent(sString,&(pHdata->mapOperators)))
    {
        DNAME dname={};
        SIGNATURE signature=getSignature(sString,&(pHdata->mapOperators));
        dname.operand=(OP)signature.nValue;
        nResult+=signature.nSize;

        pDParameter->listDnames.append(dname);
    }
    else
    {
        STRING string=readString(pHdata,sString,pSymbol->mode); // TODO Save

        if(string.nSize)
        {
            if(nb&NB_SIMPLE)
            {
                addStringRef(pSymbol,pHdata,string.sString);
            }

            DNAME dname={};
            dname.sName=string.sString;

            pDParameter->listDnames.append(dname);

            sString=sString.mid(string.nSize,-1);
            nResult+=string.nSize;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pDParameter, QString sString)
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

            pDParameter->listDnames.append(dname);

            sString=sString.mid(signature.nSize,-1);
            nResult+=signature.nSize;
        }
        else if(_compare(sString,"?$"))
        {
            qint32 nTSize=ms_demangle_Template(pSymbol,pHdata,pDParameter,sString,NB_TEMPLATE);
            sString=sString.mid(nTSize,-1);
            nResult+=nTSize;
        }
        else if(_compare(sString,"?A"))
        {
            // TODO AnonymousNamespaceName
            qDebug("TODO: AnonymousNamespaceName");
            sString=sString.mid(2,-1);
            nResult+=2;
        }
        // TODO LocallyScopedNamePiece
        else
        {
            STRING string=readString(pHdata,sString,pSymbol->mode);

            if(string.nSize)
            {
                addStringRef(pSymbol,pHdata,string.sString);

                DNAME dname={};
                dname.sName=string.sString;

                pDParameter->listDnames.append(dname);

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

    qint32 nFNSize=ms_demangle_FullName(pSymbol,pHdata,pDParameter,sString);

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

    if(isSignaturePresent(sString,&(pHdata->mapObjectClasses)))
    {
        // Variables
        pParameter->st=ST_VARIABLE;
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
        pParameter->functionMod=FM_EXTERNC;
    }

    if(isSignaturePresent(sString,&(pHdata->mapFunctionMods)))
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapFunctionMods));
        pParameter->functionMod|=signature.nValue;

        nResult+=signature.nSize;
        sString=sString.mid(signature.nSize,-1);
    }

    if(pParameter->functionMod&FM_STATICTHISADJUST)
    {
        qDebug("TODO: FM_STATICTHISADJUST");
    }

    if(pParameter->functionMod&FM_VIRTUALTHISADJUST)
    {
        qDebug("TODO: FM_VIRTUALTHISADJUST");
    }

    if(!(pParameter->functionMod&FM_NOPARAMETERLIST))
    {
        bool bThisQual=!(pParameter->functionMod&(FM_GLOBAL|FM_STATIC));

        qint32 nFSize=ms_demangle_FunctionType(pSymbol,pHdata,pParameter,sString,bThisQual);

        nResult+=nFSize;
        sString=sString.mid(nFSize,-1);
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

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult=0;

    while(sString!="")
    {
        if(_compare(sString,"@")||_compare(sString,"Z"))
        {
            break;
        }
        // TODO replace arg

        DPARAMETER parameter={};

        qint32 nTSize=ms_demangle_Type(pSymbol,pHdata,&parameter,sString,MSDT_DROP);

        pParameter->listParameters.append(parameter);

        nResult+=nTSize;
        sString=sString.mid(nTSize,-1);
        // TODO save

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
        DPARAMETER parameter={};
        parameter.st=ST_TEMPLATE;

        qint32 nNName=ms_demangle_UnkName(pSymbol,&hdata,&parameter,sString,NB_SIMPLE);
        sString=sString.mid(nNName,-1);
        nResult+=nNName;

        qint32 nTName=ms_demangle_TemplateParameters(pSymbol,&hdata,&parameter,sString);
        sString=sString.mid(nTName,-1);
        nResult+=nTName;

        QString sTemplate=ms_parameterToString(pSymbol,&parameter);

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
            qDebug("TODO: Template alias");
        }
        else if(_compare(sString,"$$B"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);

            pSymbol->bIsValid=false;
            qDebug("TODO: Template array");
        }
        else if(_compare(sString,"$$C"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);

            pSymbol->bIsValid=false;
            qDebug("TODO: Template Type has qualifiers.");
        }
        else if(_compare(sString,"$1")||_compare(sString,"$H")||
                _compare(sString,"$I")||_compare(sString,"$J"))
        {
            nResult+=2;
            sString=sString.mid(2,-1);

            pSymbol->bIsValid=false;
            qDebug("TODO: Template");
        }
        else if(_compare(sString,"$E?"))
        {
            nResult+=3;
            sString=sString.mid(3,-1);

            pSymbol->bIsValid=false;
            qDebug("TODO: Reference to symbol");
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

    if(_compare(sString,"E"))
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
        if((!_compare(sString,"6"))||(!_compare(sString,"8")))
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
}

bool XDemangle::isReplaceStringPresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    bool bResult=false;

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        bResult=isSignaturePresent(sString,&(pHdata->mapNumbers));
    }

    return bResult;
}

XDemangle::SIGNATURE XDemangle::getReplaceStringSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    SIGNATURE result={};

    if(getSyntaxFromMode(pSymbol->mode)==SYNTAX_MICROSOFT)
    {
        SIGNATURE signature=getSignature(sString,&(pHdata->mapNumbers));

        if(signature.nValue<pHdata->listStringRef.count())
        {
            result.sKey=pHdata->listStringRef.at(signature.nValue);
            result.nSize=1;
            result.nValue=signature.nValue;
        }
        else
        {
            pSymbol->bIsValid=false;
        #ifdef QT_DEBUG
            qDebug("Replace Error!!!");
        #endif
        }
    }

    return result;
}

QString XDemangle::ms_parameterToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter)
{
    QString sResult;

    QString sName;

    // TODO function
    int nNumberOfNames=pParameter->listDnames.count();

    for(int i=0;i<nNumberOfNames;i++)
    {
        QString _sName;

        if(pParameter->listDnames.at(i).operand!=OP_UNKNOWN)
        {
            _sName=operatorIdToString(pParameter->listDnames.at(i).operand,pSymbol->mode);

            if((pParameter->listDnames.at(i).operand==OP_CONSTRUCTOR)||(pParameter->listDnames.at(i).operand==OP_DESTRUCTOR))
            {
                if(nNumberOfNames>1)
                {
                    _sName+=pParameter->listDnames.at(nNumberOfNames-2).sName;
                }
            }
        }
        else if(pParameter->listDnames.at(i).sName!="")
        {
            _sName=pParameter->listDnames.at(i).sName;
        }

        sName+=_sName;

        if(i!=(nNumberOfNames-1))
        {
            sName+="::";
        }
    }

    if(pParameter->st==ST_VARIABLE)
    {
        QString sType=typeIdToString(pParameter->type,pSymbol->mode);
        QString sSC=qualIdToStorageString(pParameter->nQualifier,pSymbol->mode);

        sResult+=sType;

        if(sName!="")   sResult+=QString(" %1").arg(sName);
        if(sSC!="")     sResult+=QString(" %1").arg(sSC);
    }
    else if(pParameter->st==ST_CONST)
    {
        sResult=pParameter->varConst.toString();
    }
    else if(pParameter->st==ST_POINTER)
    {
        if(pParameter->listPointer.count())
        {
            DPARAMETER parameter=pParameter->listPointer.at(0);

            sResult=ms_parameterToString(pSymbol,&parameter);

            QString sPointer=qualIdToPointerString(pParameter->nQualifier,pSymbol->mode);

            if(sPointer!="")
            {
                sResult+=QString(" %1").arg(sPointer);
            }
        }
    }
    else if(pParameter->st==ST_FUNCTION)
    {
        QString sMod=functionModIdToString(pParameter->functionMod,pSymbol->mode);
        QString sConv=functionConventionIdToString(pParameter->functionConvention,pSymbol->mode);

        if(sMod!="")    sResult+=QString("%1 ").arg(sMod);

        if(pParameter->listReturn.count())
        {
            DPARAMETER parameter=pParameter->listReturn.at(0);

            QString sReturn=ms_parameterToString(pSymbol,&parameter);

            sResult+=QString("%1 ").arg(sReturn);
        }

        if(sConv!="")   sResult+=QString("%1 ").arg(sConv);

        sResult+=sName;
        sResult+="(";

        int nNumberOfParameters=pParameter->listParameters.count();

        for(int i=0;i<nNumberOfParameters;i++)
        {
            DPARAMETER parameter=pParameter->listParameters.at(i);

            sResult+=ms_parameterToString(pSymbol,&parameter);

            if(i!=(nNumberOfParameters-1))
            {
                sResult+=",";
            }
        }

        sResult+=")";
    }
    else if(pParameter->st==ST_TYPEINFO)
    {
        if(pParameter->listTypeinfo.count())
        {
            DPARAMETER parameter=pParameter->listTypeinfo.at(0);

            sResult=QString("%1 `RTTI Type Descriptor Name'").arg(ms_parameterToString(pSymbol,&parameter)); // TODO
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

            sResult+=ms_parameterToString(pSymbol,&parameter);

            if(i!=(nNumberOfParameters-1))
            {
                sResult+=", ";
            }
        }

        sResult+=">";
    }

    return sResult;
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

QString XDemangle::ms_demangle(QString sString, XDemangle::MODE mode)
{
    QString sResult;

    DSYMBOL symbol=getDSymbol(sString,mode);

    sResult=dsymbolToString(symbol);

    return sResult;
}

XDemangle::DSYMBOL XDemangle::getDSymbol(QString sString, XDemangle::MODE mode)
{
    DSYMBOL result={};

    result.bIsValid=true;
    result.mode=mode;

    HDATA hdata=getHdata(mode);

    if(_compare(sString,"."))
    {
        sString=sString.mid(1,-1);

        DPARAMETER parameter={};

        qint32 nTSize=ms_demangle_Type(&result,&hdata,&parameter,sString,MSDT_RESULT);

        result.paramMain.listTypeinfo.append(parameter);

        sString=sString.mid(nTSize,-1);

        result.paramMain.st=ST_TYPEINFO;
    }
    else if(_compare(sString,"??@"))
    {
        // TODO MD5
        qDebug("MD5");
    }
    else if(_compare(sString,"?"))
    {
        sString=sString.mid(1,-1);

        // TODO demangleSpecialIntrinsic

        qint32 nDSize=ms_demangle_Declarator(&result,&hdata,&(result.paramMain),sString);

        sString=sString.mid(nDSize,-1);
    }

    return result;
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
            SIGNATURE signatureIndex=getSignature(sString,&(pHdata->mapNumbers)); // TODO replace function

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
                if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
                {
                    SIGNATURE signatureParamMod=getSignature(sString,&(pHdata->mapPointerTypes));

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
                    mod.nParamMod=signatureParamMod.nValue;
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
            else if(isSignaturePresent(sString,&(pHdata->mapTagTypes)))
            {
                signatureType=getSignature(sString,&(pHdata->mapTagTypes));

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
            sRecord+=_string.sOriginal;
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

        pParameter->bTemplate=bTemplate;
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

qint32 XDemangle::Itanium_handleParams(XDemangle::HDATA *pHdata, QString sString, XDemangle::MODE mode, QList<XDemangle::PARAMETER> *pListParameters, QList<QString> *pListStringRefs, bool bFirst, SYMBOL *pSymbol, bool bSplit)
{
    qint32 nResult=0;

    bool bParameter=false;
    bool bClear=false;
    PARAMETER parameter={};
    QList<QString> listPos;
    QString sRawRecord;

    while(sString!="")
    {
        if(_compare(sString,"St"))
        {
            sString=sString.mid(2,-1);
            parameter.sRecord+="St";
            nResult+=2;

            parameter.listNames.append("std");
            QList<PARAMETER> _list;
            parameter.listListTemplateParameters.append(_list);
        }

        if(_compare(sString,"S"))
        {
            SIGNATURE signatureReplace=Itanium_getReplaceSignature(pHdata,sString,mode);

            if(signatureReplace.nValue<pListStringRefs->count())
            {
                QString sRecord=pListStringRefs->at(signatureReplace.nValue);
                sString=sString.mid(signatureReplace.nSize,-1);
                parameter.sRecord+=sRecord;

                Itanium_handleParams(pHdata,parameter.sRecord,mode,pListParameters,pListStringRefs,(pListParameters->count()==0)&(bFirst),pSymbol,false);

                nResult+=signatureReplace.nSize;
            }
            else
            {
            #ifdef QT_DEBUG
                // TODO Set Global error flag;
                qDebug("ERROR!!!");
                qDebug(signatureReplace.sKey.toLatin1().data());
            #endif
                break;
            }

            bClear=true;
        }
        else if(isSignaturePresent(sString,&(pHdata->mapPointerTypes)))
        {
            PARAMETER paramMod={};

            SIGNATURE signatureMod=getSignature(sString,&(pHdata->mapPointerTypes));

            listPos.append(signatureMod.sKey);

            paramMod.nParamMod=signatureMod.nValue;

            parameter.sRecord+=sString.leftRef(signatureMod.nSize);
            nResult+=signatureMod.nSize;

            sRawRecord+=sString.leftRef(signatureMod.nSize);
            sString=sString.mid(signatureMod.nSize,-1);

            parameter.listMods.append(paramMod);
        }
        else if(isSignaturePresent(sString,&(pHdata->mapStorageClasses)))
        {
            PARAMETER paramMod={};

            SIGNATURE signatureSC=getSignature(sString,&(pHdata->mapStorageClasses));

            listPos.append(signatureSC.sKey);

            paramMod.storageClass=(SC)signatureSC.nValue;

            parameter.sRecord+=sString.leftRef(signatureSC.nSize);
            nResult+=signatureSC.nSize;

            sRawRecord+=sString.leftRef(signatureSC.nSize);
            sString=sString.mid(signatureSC.nSize,-1);

            parameter.listMods.append(paramMod);
        }
        else if(_compare(sString,"A")) // [x]
        {
            parameter.sRecord+=sString.leftRef(1);
            nResult+=1;

            sRawRecord+=sString.leftRef(1);
            sString=sString.mid(1,-1);

            NUMBER number=readNumber(pHdata,sString,mode);

            parameter.listIndexes.append(number.nValue);

            parameter.sRecord+=sString.leftRef(number.nSize);
            nResult+=number.nSize;

            sRawRecord+=sString.leftRef(number.nSize);
            sString=sString.mid(number.nSize,-1);

            if(_compare(sString,"_"))
            {
                parameter.sRecord+=sString.leftRef(1);
                nResult+=1;

                sRawRecord+=sString.leftRef(1);
                sString=sString.mid(1,-1);
            }
        }
        else if(_compare(sString,"F")) // Function
        {
            parameter.sRecord+=sString.leftRef(1);
            nResult+=1;

            sRawRecord+=sString.leftRef(1);
            sString=sString.mid(1,-1);

            qint32 nParamSize=Itanium_handleParams(pHdata,sString,mode,&(parameter.listFunctionParameters),pListStringRefs,false,pSymbol,true);

            parameter.functionConvention=FC_NONE;

            if(sRawRecord=="PF")
            {
                parameter.type=TYPE_POINTERTOFUNCTION;
            }
            else
            {
                parameter.type=TYPE_FUNCTION;
            }

            QString _sRecord=sString.left(nParamSize);

            listPos.append(QString("F%1E").arg(_sRecord));

            parameter.sRecord+=sString.leftRef(nParamSize);
            nResult+=nParamSize;

            sRawRecord+=sString.leftRef(nParamSize);
            sString=sString.mid(nParamSize,-1);

            if(_compare(sString,"E"))
            {
                parameter.sRecord+=sString.leftRef(1);
                nResult+=1;

                sRawRecord+=sString.leftRef(1);
                sString=sString.mid(1,-1);
            }

            bParameter=true;
        }
        else if(isSignaturePresent(sString,&(pHdata->mapTypes)))
        {
            SIGNATURE signatureType=getSignature(sString,&(pHdata->mapTypes));

            listPos.append(signatureType.sKey);

            parameter.type=(TYPE)signatureType.nValue;

            parameter.sRecord+=sString.leftRef(signatureType.nSize);
            nResult+=signatureType.nSize;

            sRawRecord+=sString.leftRef(signatureType.nSize);
            sString=sString.mid(signatureType.nSize,-1);

            bParameter=true;
        }
        else if(_compare(sString,"Li"))
        {
            parameter.sRecord+=sString.leftRef(2);
            nResult+=2;

            sRawRecord+=sString.leftRef(2);
            sString=sString.mid(2,-1);

            bool bNeg=false;

            if(_compare(sString,"n"))
            {
                parameter.sRecord+=sString.leftRef(1);
                nResult+=1;

                sRawRecord+=sString.leftRef(1);
                sString=sString.mid(1,-1);

                bNeg=true;
            }

            NUMBER number=readNumber(pHdata,sString,mode);

            parameter.nConstValue=number.nValue;

            if(bNeg)
            {
                parameter.nConstValue=-parameter.nConstValue;
            }

            parameter.sRecord+=sString.leftRef(number.nSize);
            nResult+=number.nSize;

            sRawRecord+=sString.leftRef(number.nSize);
            sString=sString.mid(number.nSize,-1);

            if(_compare(sString,"E"))
            {
                parameter.sRecord+=sString.leftRef(1);
                nResult+=1;

                sRawRecord+=sString.leftRef(1);
                sString=sString.mid(1,-1);
            }

            parameter.type=TYPE_CONST;
            bParameter=true;
        }
        else
        {
            quint32 nNameSize=Itanium_handleParamStrings(pHdata,sString,mode,&parameter,pListStringRefs,false,pSymbol,bSplit);

            if(nNameSize)
            {
                listPos.append(sString.leftRef(nNameSize).toString());

                parameter.sRecord+=sString.leftRef(nNameSize);
                nResult+=nNameSize;

                sRawRecord+=sString.leftRef(nNameSize);
                sString=sString.mid(nNameSize,-1);

                bParameter=true;
            }
            else
            {
                break;
            }
        }

        if(bParameter)
        {
            bool bLastTemplate=false;

            if(pSymbol->paramMain.bTemplate)
            {
                int nTP=pSymbol->paramMain.listListTemplateParameters.count();

                if(pSymbol->paramMain.listListTemplateParameters.at(nTP-1).count())
                {
                    bLastTemplate=true;
                }
            }

            if((pListParameters->count()==0)&&(bFirst)&&(!bLastTemplate))
            {
                // Return
                PARAMETER paramReturn={};

                paramReturn.type=TYPE_NONE;
                paramReturn.storageClass=SC_NEAR;

                pListParameters->append(paramReturn);
            }

            reverseList(&(parameter.listMods));
            pListParameters->append(parameter);

            int nNumberOfPos=listPos.count();
            QString _sRecord;

            for(int i=(nNumberOfPos-1);i>=0;i--)
            {
                _sRecord=_sRecord.prepend(listPos.at(i));

                if(_sRecord.size()>1)
                {
                    if(!pListStringRefs->contains(_sRecord))
                    {
                        pListStringRefs->append(_sRecord);
                    }
                }
            }
        }

        if(bParameter||bClear)
        {
            bParameter=false;
            bClear=false;
            parameter={};
            listPos.clear();
            sRawRecord="";
        }
    }

    return nResult;
}

qint32 XDemangle::Itanium_handleParamStrings(XDemangle::HDATA *pHdata, QString sString, XDemangle::MODE mode, XDemangle::PARAMETER *pParameter, QList<QString> *pListStringRefs, bool bFirst, SYMBOL *pSymbol, bool bSplit)
{
    qint32 nResult=0;

    bool bNamespace=false;

    if(_compare(sString,"N"))
    {
        bNamespace=true;
        sString=sString.mid(1,-1);
        nResult++;
    }

    if(_compare(sString,"K"))
    {
        if(pSymbol)
        {
            pSymbol->classStorageClass=SC_CONST;
        }

        sString=sString.mid(1,-1);
        nResult++;
    }

    QString sPos;

    bool bBreak=false;

    while(sString!="")
    {
        if(bFirst&&isSignaturePresent(sString,&(pHdata->mapOperators)))
        {
            SIGNATURE signatureOperator=getSignature(sString,&(pHdata->mapOperators));

            pSymbol->_operator=(OP)signatureOperator.nValue;

            sString=sString.mid(signatureOperator.nSize,-1);

            nResult+=signatureOperator.nSize;

            bBreak=true;
        }
        else
        {
            if(_compare(sString,"St"))
            {
                sString=sString.mid(2,-1);
                nResult+=2;

                pParameter->listNames.append("std");
                QList<PARAMETER> _list;
                pParameter->listListTemplateParameters.append(_list);
            }
            else if(_compare(sString,"S")&&(pParameter->listNames.count()==0))
            {
                SIGNATURE signatureReplace=Itanium_getReplaceSignature(pHdata,sString,mode);

                if(signatureReplace.nValue<pListStringRefs->count())
                {
                    QString sRecord=pListStringRefs->at(signatureReplace.nValue);

                    Itanium_handleParamStrings(pHdata,sRecord,mode,pParameter,pListStringRefs,false,pSymbol,false);

                    sString=sString.mid(signatureReplace.nSize,-1);
                    nResult+=signatureReplace.nSize;

                    if(!bNamespace)
                    {
                        bBreak=true;
                    }
                }
                else
                {
                #ifdef QT_DEBUG
                    // TODO Set Global error flag;
                    qDebug("ERROR!!!");
                    qDebug(signatureReplace.sKey.toLatin1().data());
                #endif
                    break;
                }
            }
            else
            {
                STRING string=readString(pHdata,sString,mode);

                if(string.nSize==0)
                {
                    break;
                }

                pParameter->listNames.append(string.sString);
                sPos+=string.sOriginal;

                sString=sString.mid(string.nSize,-1);

                nResult+=string.nSize;

                bool bAdd=true;

                if(bFirst)
                {
                    if((bNamespace)&&(_compare(sString,"E")))
                    {
                        bAdd=false;
                    }
                    else if((!bNamespace)&&(!_compare(sString,"I")))
                    {
                        bAdd=false;
                    }
                }

                if(bAdd) // If not the last in main
                {
                    QString _sRecord=sPos;

                    if((!bFirst)&&(bNamespace)&&(_compare(sString,"E")))
                    {
                        _sRecord="N"+_sRecord+"E";
                    }

                    if(!pListStringRefs->contains(_sRecord))
                    {
                        pListStringRefs->append(_sRecord);
                    }
                }
            }
        }

        QList<PARAMETER> listTemplateParameters;

        if(_compare(sString,"I"))
        {
            sString=sString.mid(1,-1);

            nResult+=1;

            qint32 nParamSize=Itanium_handleParams(pHdata,sString,mode,&listTemplateParameters,pListStringRefs,false,pSymbol,true);

            sString=sString.mid(nParamSize,-1);
            nResult+=nParamSize;

            if(_compare(sString,"E"))
            {
                sString=sString.mid(1,-1);
                nResult+=1;
            }

            pParameter->bTemplate=true;
        }

        pParameter->listListTemplateParameters.append(listTemplateParameters);

        if(bNamespace)
        {
            if(_compare(sString,"E")) // End
            {
                sString=sString.mid(1,-1);
                nResult++;

                bBreak=true;
            }
        }

        if(bSplit&&(!bNamespace))
        {
            bBreak=true;
        }

        if(bBreak)
        {
            break;
        }
    }

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
    result.mapSymbolTypes=getSymbolTypes(mode);
    result.mapStorageClasses=getStorageClasses(mode);
    result.mapFunctionMods=getFunctionMods(mode);
    result.mapFunctionConventions=getFunctionConventions(mode);
    result.mapOperators=getOperators(mode);
    result.mapNumbers=getNumbers(mode);
    result.mapSymNumbers=getSymNumbers(mode);
    result.mapQualifiers=getQualifiers(mode);

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
            if(getSyntaxFromMode(symbol.mode)==SYNTAX_MICROSOFT)
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
            else if(getSyntaxFromMode(symbol.mode)==SYNTAX_ITANIUM)
            {
                QString sName=_getNameFromSymbol(symbol);

                sResult=QString("vtable for %1").arg(sName);
            }
        }
        else if(symbol.symbolType==ST_TYPEINFO)
        {
            if(getSyntaxFromMode(symbol.mode)==SYNTAX_ITANIUM)
            {
                QString sName=_getNameFromSymbol(symbol);

                sResult=QString("typeinfo for %1").arg(sName);
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
                        .arg(paramModIdToString(symbol.nExtraParamMod,symbol.mode)));
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

QString XDemangle::dsymbolToString(XDemangle::DSYMBOL symbol)
{
    QString sResult;

    if(symbol.bIsValid)
    {
        sResult=ms_parameterToString(&symbol,&(symbol.paramMain));
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

XDemangle::SIGNATURE XDemangle::Itanium_getReplaceSignature(HDATA *pHdata,QString sString,MODE mode)
{
    SIGNATURE result={};

    result.sKey+=sString.leftRef(1);
    sString=sString.mid(1,-1);

    result.nSize+=1;

    NUMBER number=readSymNumber(pHdata,sString,mode);

    if(number.nSize)
    {
        result.nValue=number.nValue+1;
        result.sKey+=sString.leftRef(number.nSize);
        sString=sString.mid(number.nSize,-1);
        result.nSize+=number.nSize;
    }

    if(_compare(sString,"_"))
    {
        result.sKey+=sString.leftRef(1);
        sString=sString.mid(1,-1);
        result.nSize+=1;
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

QMap<QString, quint32> XDemangle::getSymbolTypes(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
    {
        mapResult.insert("TI",ST_TYPEINFO);
        mapResult.insert("TV",ST_VTABLE);
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

QMap<QString, quint32> XDemangle::getFunctionMods(XDemangle::MODE mode)
{
    QMap<QString,quint32> mapResult;

    if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
    {
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
            mapResult.insert(QString("?%1??").arg(i),i+1);
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
        QMap<QString,quint32> mapLineNumbers=getLineNumbers(mode);
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
                (!(result.functionMod&FM_STATIC)))
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

                SIGNATURE signaturePM=getSignature(sString,&(pHdata->mapPointerTypes));
                result.nExtraParamMod=signaturePM.nValue;
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
        QList<QString> listStringRefs; // String and args

        result.bValid=true;
        result.mode=mode;
        result.symbolType=ST_VARIABLE;

        if(_compare(sString,"@_Z")) // Fastcall
        {
            result.functionConvention=FC_FASTCALL;
            sString=sString.mid(3,-1);
        }
        else if(_compare(sString,"_Z"))
        {
            sString=sString.mid(2,-1);
        }

        if(isSignaturePresent(sString,&(pHdata->mapSymbolTypes)))
        {
            SIGNATURE signature=getSignature(sString,&(pHdata->mapSymbolTypes));
            result.symbolType=(ST)signature.nValue;

            sString=sString.mid(signature.nSize,-1);
        }

        quint32 nNameSize=Itanium_handleParamStrings(pHdata,sString,mode,&(result.paramMain),&listStringRefs,true,&result,true);

        sString=sString.mid(nNameSize,-1);

        quint32 nParamSize=Itanium_handleParams(pHdata,sString,mode,&(result.listParameters),&listStringRefs,true,&result,true);

        if(nParamSize)
        {
            result.functionMod=FM_NEAR;
            result.functionConvention=FC_NONE;
            result.symbolType=ST_FUNCTION;
        }

        sString=sString.mid(nParamSize,-1);
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

        if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
        {
            if(_getStringEnd(sResult)==QChar('>'))
            {
                sResult+=" ";
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
            sFunction+=QString("(");

            if(sFunctionConvention!="")
            {
                sFunction+=QString("%1 ").arg(sFunctionConvention);
            }

            sFunction+=QString("*");

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
            sFunction=QString("(%1 %2::*)").arg(sFunctionConvention,_getNameFromParameter(&parameter,mode));
        }

        QString sReturn=_getStringFromParameter(parameter.listFunctionParameters.at(0),mode,sFunction,true);

        sResult=sReturn;

        if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
        {
            if(sResult!="")
            {
                if(_getStringEnd(sResult)!=QChar(')'))
                {
                    sResult+=" ";
                }
            }
        }

        sResult+="(";

        for(int i=1;i<nNumberOfFunctionParameters;i++)
        {
            bool bEnable=true;

            if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
            {
                if(nNumberOfFunctionParameters==2)
                {
                    if((parameter.listFunctionParameters.at(i).listMods.count()==0)&&(parameter.listFunctionParameters.at(i).type==TYPE_VOID))
                    {
                        bEnable=false;
                    }
                }
            }

            if(bEnable)
            {
                sResult+=_getStringFromParameter(parameter.listFunctionParameters.at(i),mode);

                if(i!=nNumberOfFunctionParameters-1)
                {
                    sResult+=QString(", ");
                }
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

            QString sParamMod=paramModIdToString(parameter.listMods.at(i).nParamMod,mode);

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

        bool bBrackets=true;

        if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
        {
            if(sMod=="const &")
            {
                sMod=" const&";
            }
            else if(sMod=="const *")
            {
                if(parameter.listIndexes.count())
                {
                    sMod="const (*)";
                    bBrackets=false;
                }
                else
                {
                    sMod=" const*";
                }
            }
            else if(sMod=="const **")
            {
                sMod=" const**";
            }
            else if(sMod=="const")
            {
                sMod=" const";
            }
        }

        int nStart=0;

        if(getSyntaxFromMode(mode)==SYNTAX_MICROSOFT)
        {
            nStart=1;
        }

        if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
        {
            if(nNumberOfIndexes>nStart) sResult+=" ";
        }

        if((nNumberOfIndexes>nStart)&&(bBrackets))
        {
            sResult+="(";
        }

        if(sMod!="")sResult+=QString("%1").arg(sMod);

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

        if((nNumberOfIndexes>nStart)&&(bBrackets))
        {
            sResult+=")";
        }

        if(getSyntaxFromMode(mode)==SYNTAX_ITANIUM)
        {
            if(nNumberOfIndexes)
            {
                sResult+=" ";
            }
        }

        for(int i=nStart;i<nNumberOfIndexes;i++)
        {
            sResult+=QString("[%1]").arg(parameter.listIndexes.at(i));
        }
    }

    return sResult;
}
