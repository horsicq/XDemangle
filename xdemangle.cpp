/* Copyright (c) 2021-2023 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "xdemangle.h"

XDemangle::XDemangle(QObject *pParent) : QObject(pParent)
{
}

QString XDemangle::modeIdToString(XDemangle::MODE mode)
{
    QString sResult = tr("Unknown");

    switch (mode) {
        case MODE_UNKNOWN:
            sResult = tr("Unknown");
            break;
        case MODE_AUTO:
            sResult = tr("Automatic");
            break;
        case MODE_MSVC:
            sResult = QString("MSVC+++");
            break;
        case MODE_MSVC32:
            sResult = QString("MSVC+++ 32");
            break;
        case MODE_MSVC64:
            sResult = QString("MSVC+++ 64");
            break;
        case MODE_GNU_V3:
            sResult = QString("GNU V3");
            break;
        case MODE_GCC_WIN:
            sResult = QString("GNU C++ for Windows");
            break;
        case MODE_GCC_MAC:
            sResult = QString("GNU C++ for MacOS");
            break;
        case MODE_JAVA:
            sResult = QString("Java");
            break;
        case MODE_WATCOM:
            sResult = QString("Watcom");
            break;
        case MODE_BORLAND32:
            sResult = QString("Borland 32");
            break;
        case MODE_BORLAND64:
            sResult = QString("Borland 64");
            break;
        case MODE_RUST:
            sResult = QString("Rust");
            break;
    }

    return sResult;
}

QString XDemangle::typeIdToString(XDemangle::XTYPE type, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // mb TODO

    QString sResult = tr("Unknown");

    switch (type) {
        case XTYPE_UNKNOWN:
            sResult = QString("");
            break;
        case XTYPE_NONE:
            sResult = QString("");
            break;
        case XTYPE_VOID:
            sResult = QString("void");
            break;
        case XTYPE_BOOL:
            sResult = QString("bool");
            break;
        case XTYPE_INT:
            sResult = QString("int");
            break;
        case XTYPE_SCHAR:
            sResult = QString("signed char");
            break;
        case XTYPE_CHAR:
            sResult = QString("char");
            break;
        case XTYPE_UCHAR:
            sResult = QString("unsigned char");
            break;
        case XTYPE_SHORT:
            sResult = QString("short");
            break;
        case XTYPE_USHORT:
            sResult = QString("unsigned short");
            break;
        case XTYPE_UINT:
            sResult = QString("unsigned int");
            break;
        case XTYPE_LONG:
            sResult = QString("long");
            break;
        case XTYPE_ULONG:
            sResult = QString("unsigned long");
            break;
        case XTYPE_FLOAT:
            sResult = QString("float");
            break;
        case XTYPE_FLOAT128:
            sResult = QString("__float128");
            break;
        case XTYPE_DOUBLE:
            sResult = QString("double");
            break;
        case XTYPE_LONGDOUBLE:
            sResult = QString("long double");
            break;
        case XTYPE_LONGDOUBLE_64:
            sResult = QString("long double");
            break;
        case XTYPE_LONGDOUBLE_80:
            sResult = QString("long double");
            break;
        case XTYPE_INT64:
            sResult = QString("__int64");
            break;
        case XTYPE_UINT64:
            sResult = QString("unsigned __int64");
            break;
        case XTYPE_LONGLONG:
            sResult = QString("long long");
            break;
        case XTYPE_ULONGLONG:
            sResult = QString("unsigned long long");
            break;
        case XTYPE_CHAR8:
            sResult = QString("char8_t");
            break;
        case XTYPE_CHAR16:
            sResult = QString("char16_t");
            break;
        case XTYPE_CHAR32:
            sResult = QString("char32_t");
            break;
        case XTYPE_DECIMAL32:
            sResult = QString("decimal32");
            break;
        case XTYPE_DECIMAL64:
            sResult = QString("decimal64");
            break;
        case XTYPE_DECIMAL128:
            sResult = QString("decimal128");
            break;
        case XTYPE_WCHAR:
            sResult = QString("wchar_t");
            break;
        case XTYPE_VARARGS:
            sResult = QString("...");
            break;
        case XTYPE_CLASS:
            sResult = QString("class");
            break;
        case XTYPE_UNION:
            sResult = QString("union");
            break;
        case XTYPE_STRUCT:
            sResult = QString("struct");
            break;
        case XTYPE_ENUM:
            sResult = QString("enum");
            break;
        case XTYPE_POINTERTOFUNCTION:
            sResult = QString("");
            break;
        case XTYPE_NULLPTR:
            sResult = QString("std::nullptr_t");
            break;  // TODO Check !!!
        default:
            sResult = "Unknown";
    }

    return sResult;
}

QString XDemangle::storageClassIdToString(XDemangle::SC storageClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult = QString("Unknown");

    switch (storageClass) {
        case SC_UNKNOWN:
            sResult = QString("");
            break;
        case SC_NEAR:
            sResult = QString("");
            break;
        case SC_CONST:
            sResult = QString("const");
            break;
        case SC_VOLATILE:
            sResult = QString("volatile");
            break;
        case SC_CONSTVOLATILE:
            sResult = QString("const volatile");
            break;
        case SC_FAR:
            sResult = QString("");
            break;
        case SC_CONSTFAR:
            sResult = QString("const");
            break;
        case SC_VOLATILEFAR:
            sResult = QString("volatile");
            break;
        case SC_CONSTVOLATILEFAR:
            sResult = QString("const volatile");
            break;
        case SC_HUGE:
            sResult = QString("");
            break;
        case SC_EXECUTABLE:
            sResult = QString("");
            break;
    }

    return sResult;
}

QString XDemangle::objectClassIdToString(OC objectClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult = QString("Unknown");

    switch (objectClass) {
        case OC_UNKNOWN:
            sResult = QString("Unknown");
            break;
        case OC_GLOBALOBJECT:
            sResult = QString("");
            break;
        case OC_PRIVATESTATICCLASSMEMBER:
            sResult = QString("private: static");
            break;
        case OC_PROTECTEDSTATICCLASSMEMBER:
            sResult = QString("protected: static");
            break;
        case OC_PUBLICSTATICCLASSMEMBER:
            sResult = QString("public: static");
            break;
        default:
            sResult = QString("Unknown");
    }

    return sResult;
}

QString XDemangle::accessIdToString(quint32 nFunctionMod, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult;

    //    if(nFunctionMod==0)
    //    {
    //        sResult=QString("Unknown");
    //    }

    bool bStatic = nFunctionMod & FM_STATIC;
    bool bVirtual = nFunctionMod & FM_VIRTUAL;

    if (nFunctionMod & FM_PRIVATE)
        sResult += QString("private:");
    else if (nFunctionMod & FM_PROTECTED)
        sResult += QString("protected:");
    else if (nFunctionMod & FM_PUBLIC)
        sResult += QString("public:");
    else
        bStatic = false;

    if ((nFunctionMod & FM_STATIC) || (nFunctionMod & FM_VIRTUAL)) {
        if (sResult != "") sResult += " ";

        if (bStatic)
            sResult += QString("static");
        else if (bVirtual)
            sResult += QString("virtual");
    }

    return sResult;
}

QString XDemangle::functionConventionIdToString(XDemangle::FC functionConvention, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult = QString("Unknown");

    switch (functionConvention) {
        case FC_UNKNOWN:
            sResult = QString("");
            break;
        case FC_NONE:
            sResult = QString("");
            break;
        case FC_CDECL:
            sResult = QString("__cdecl");
            break;
        case FC_THISCALL:
            sResult = QString("__thiscall");
            break;
        case FC_STDCALL:
            sResult = QString("__stdcall");
            break;
        case FC_FASTCALL:
            sResult = QString("__fastcall");
            break;
        case FC_CLRCALL:
            sResult = QString("__clrcall");
            break;
        case FC_VECTORCALL:
            sResult = QString("__vectorcall");
            break;
        default:
            sResult = QString("Unknown");
    }

    return sResult;
}

QString XDemangle::operatorIdToString(XDemangle::OP _operator, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult = QString("Unknown");

    switch (_operator) {
        case OP_UNKNOWN:
            sResult = QString("Unknown");
            break;
        case OP_CONSTRUCTOR:
            sResult = QString("");
            break;
        case OP_DESTRUCTOR:
            sResult = QString("~");
            break;
        case OP_NEW:
            sResult = QString("operator new");
            break;
        case OP_DELETE:
            sResult = QString("operator delete");
            break;
        case OP_ASSIGN:
            sResult = QString("operator=");
            break;
        case OP_RIGHTSHIFT:
            sResult = QString("operator>>");
            break;
        case OP_LEFTSHIFT:
            sResult = QString("operator<<");
            break;
        case OP_LOGICALNOT:
            sResult = QString("operator!");
            break;
        case OP_EQUALS:
            sResult = QString("operator==");
            break;
        case OP_NOTEQUALS:
            sResult = QString("operator!=");
            break;
        case OP_ARRAYSUBSCRIPT:
            sResult = QString("operator[]");
            break;
        case OP_POINTER:
            sResult = QString("operator->");
            break;
        case OP_DEREFERENCE:
            sResult = QString("operator*");
            break;
        case OP_REFERENCE:
            sResult = QString("operator&");
            break;
        case OP_INCREMENT:
            sResult = QString("operator++");
            break;
        case OP_DECREMENT:
            sResult = QString("operator--");
            break;
        case OP_MINUS:
            sResult = QString("operator-");
            break;
        case OP_PLUS:
            sResult = QString("operator+");
            break;
        case OP_BITWISEAND:
            sResult = QString("operator&");
            break;
        case OP_MEMBERPOINTER:
            sResult = QString("operator->*");
            break;
        case OP_MULTIPLE:
            sResult = QString("operator*");
            break;
        case OP_DIVIDE:
            sResult = QString("operator/");
            break;
        case OP_MODULUS:
            sResult = QString("operator%");
            break;
        case OP_LESSTHAN:
            sResult = QString("operator<");
            break;
        case OP_LESSTHANEQUAL:
            sResult = QString("operator<=");
            break;
        case OP_GREATERTHAN:
            sResult = QString("operator>");
            break;
        case OP_GREATERTHANEQUAL:
            sResult = QString("operator>=");
            break;
        case OP_COMMA:
            sResult = QString("operator,");
            break;
        case OP_PARENS:
            sResult = QString("operator()");
            break;
        case OP_BITWISENOT:
            sResult = QString("operator~");
            break;
        case OP_BITWISEXOR:
            sResult = QString("operator^");
            break;
        case OP_BITWISEOR:
            sResult = QString("operator|");
            break;
        case OP_LOGICALAND:
            sResult = QString("operator&&");
            break;
        case OP_LOGICALOR:
            sResult = QString("operator||");
            break;
        case OP_TIMESEQUAL:
            sResult = QString("operator*=");
            break;
        case OP_PLUSEQUAL:
            sResult = QString("operator+=");
            break;
        case OP_MINUSEQUAL:
            sResult = QString("operator-=");
            break;
        case OP_DIVEQUAL:
            sResult = QString("operator/=");
            break;
        case OP_MODEQUAL:
            sResult = QString("operator%=");
            break;
        case OP_RSHEQUAL:
            sResult = QString("operator>>=");
            break;
        case OP_LSHEQUAL:
            sResult = QString("operator<<=");
            break;
        case OP_BITWISEANDEQUAL:
            sResult = QString("operator&=");
            break;
        case OP_BITWISEOREQUAL:
            sResult = QString("operator|=");
            break;
        case OP_BITWISEXOREQUAL:
            sResult = QString("operator^=");
            break;
        case OP_VBASEDTOR:
            sResult = QString("`vbase dtor'");
            break;
        case OP_VECDELDTOR:
            sResult = QString("`vector deleting dtor'");
            break;
        case OP_DEFAULTCTORCLOSURE:
            sResult = QString("`default ctor closure'");
            break;
        case OP_SCALARDELDTOR:
            sResult = QString("`scalar deleting dtor'");
            break;
        case OP_VECCTORITER:
            sResult = QString("`vector ctor iterator'");
            break;
        case OP_VECDTORITER:
            sResult = QString("`vector dtor iterator'");
            break;
        case OP_VECVBASECTORITER:
            sResult = QString("`vector vbase ctor iterator'");
            break;
        case OP_VDISPMAP:
            sResult = QString("`virtual displacement map'");
            break;
        case OP_EHVECCTORITER:
            sResult = QString("`eh vector ctor iterator'");
            break;
        case OP_EHVECDTORITER:
            sResult = QString("`eh vector dtor iterator'");
            break;
        case OP_EHVECVBASECTORITER:
            sResult = QString("`eh vector vbase ctor iterator'");
            break;
        case OP_COPYCTORCLOSURE:
            sResult = QString("`copy ctor closure'");
            break;
        case OP_ARRAYNEW:
            sResult = QString("operator new[]");
            break;
        case OP_ARRAYDELETE:
            sResult = QString("operator delete[]");
            break;
        case OP_TYPE:
            sResult = QString("operator ");
            break;
    }

    return sResult;
}

QString XDemangle::qualIdToPointerString(quint32 nQual, XDemangle::MODE mode)
{
    Q_UNUSED(mode)

    QString sResult;

    if (nQual & QUAL_POINTER)
        sResult += "*";
    else if (nQual & QUAL_REFERENCE)
        sResult += "&";
    else if (nQual & QUAL_DOUBLEREFERENCE)
        sResult += "&&";
    else if (nQual & QUAL_RVALUEREF)
        sResult += "&&";

    if (nQual & QUAL_CONST) {
        sResult += "const";
    }

    if (nQual & QUAL_VOLATILE) {
        if (nQual & QUAL_CONST) {
            sResult += " ";
        }

        sResult += "volatile";
    }

    if (nQual & QUAL_SIGNED)
        sResult += "signed";
    else if (nQual & QUAL_UNSIGNED)
        sResult += "unsigned";

    return sResult;
}

QString XDemangle::qualIdToStorageString(quint32 nQual, XDemangle::MODE mode)
{
    Q_UNUSED(mode)

    QString sResult;

    if (nQual & QUAL_CONST) sResult = "const";

    return sResult;
}

XDemangle::SYNTAX XDemangle::getSyntaxFromMode(XDemangle::MODE mode)
{
    SYNTAX result = SYNTAX_UNKNOWN;

    if ((mode == MODE_MSVC32) || (mode == MODE_MSVC64) || (mode == MODE_MSVC)) {
        result = SYNTAX_MICROSOFT;
    } else if ((mode == MODE_GNU_V3) || (mode == MODE_GCC_MAC) || (mode == MODE_GCC_WIN)) {
        result = SYNTAX_ITANIUM;
    } else if (mode == MODE_BORLAND32) {
        result = SYNTAX_BORLAND;
    }

    return result;
}

qint32 XDemangle::ms_demangle_StringLiteralSymbol(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    Q_UNUSED(pParameter)

    qint32 nResult = 0;

    if (_compare(_sString, "@_")) {
        nResult += 2;
        _sString = _sString.mid(2, -1);
    } else {
        pSymbol->bIsValid = false;
    }

    bool bWchar = false;

    if (_compare(_sString, "0")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);
    } else if (_compare(_sString, "1")) {
        bWchar = true;
        nResult += 1;
        _sString = _sString.mid(1, -1);
    } else {
        pSymbol->bIsValid = false;
    }

    Q_UNUSED(bWchar)

    // TODO

    if (pSymbol->bIsValid) {
        NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);
        nResult += number.nSize;
        _sString = _sString.mid(number.nSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_UntypedVariable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    qint32 nPSize = ms_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

    nResult += nPSize;
    _sString = _sString.mid(nPSize, -1);

    reverseList(&(pParameter->listDnames));

    if (!_compare(_sString, "8")) {
        pSymbol->bIsValid = false;
    }

    if (pSymbol->bIsValid) {
        nResult += 1;
        _sString = _sString.mid(1, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_SpecialTable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    qint32 nNSSize = ms_demangle_NameScope(pSymbol, pHdata, pParameter, sString);

    reverseList(&(pParameter->listDnames));

    nResult += nNSSize;
    sString = sString.mid(nNSSize, -1);

    if ((!_compare(sString, "6")) && (!_compare(sString, "7"))) {
        pSymbol->bIsValid = false;
    }

    if (pSymbol->bIsValid) {
        nResult += 1;
        sString = sString.mid(1, -1);

        if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

            pParameter->nQualifier = signature.nValue;
            sString = sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        }

        if (_compare(sString, "@")) {
            nResult += 1;
            sString = sString.mid(1, -1);
        } else {
            DPARAMETER parameter = {};
            parameter.st = ST_NAME;

            qint32 nPSize = ms_demangle_NameScope(pSymbol, pHdata, &parameter, sString);

            nResult += nPSize;
            sString = sString.mid(nPSize, -1);

            reverseList(&(parameter.listDnames));

            pParameter->listTarget.append(parameter);
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_LocalStaticGuard(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    qint32 nNSSize = ms_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

    reverseList(&(pParameter->listDnames));

    nResult += nNSSize;
    _sString = _sString.mid(nNSSize, -1);

    // Visible
    if (_compare(_sString, "4IA")) {
        // Visible false
        nResult += 3;
        _sString = _sString.mid(3, -1);
    } else if (_compare(_sString, "5")) {
        // Visible true
        nResult += 1;
        _sString = _sString.mid(1, -1);
    } else {
        pSymbol->bIsValid = false;
    }

    if (_sString != "") {
        NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);
        pParameter->sScope = QString::number(number.nValue);

        nResult += number.nSize;
        _sString = _sString.mid(number.nSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Type(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString, MSDT msdt)
{
    qint32 nResult = 0;

    if (msdt == MSDT_MANGLE) {
        if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

            pParameter->nQualifier = signature.nValue;

            nResult += signature.nSize;
            sString = sString.mid(signature.nSize, -1);
        }
    } else if (msdt == MSDT_RESULT) {
        if (_compare(sString, "?")) {
            sString = sString.mid(1, -1);
            nResult += 1;

            if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
                SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

                pParameter->nQualifier = signature.nValue;

                nResult += signature.nSize;
                sString = sString.mid(signature.nSize, -1);
            }
        }
    }

    if (isSignaturePresent(sString, &(pHdata->mapTagTypes))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapTagTypes));
        pParameter->type = (XTYPE)signature.nValue;
        pParameter->st = ST_TYPE;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);

        qint32 nFNSize = ms_demangle_FullTypeName(pSymbol, pHdata, pParameter, sString);

        nResult += nFNSize;
        sString = sString.mid(nFNSize, -1);
    } else if (isSignaturePresent(sString, &(pHdata->mapPointerTypes))) {
        if (ms_isPointerMember(pSymbol, pHdata, sString)) {
            qint32 nPTSize = ms_demangle_MemberPointerType(pSymbol, pHdata, pParameter, sString);

            nResult += nPTSize;
            sString = sString.mid(nPTSize, -1);
        } else if (pSymbol->bIsValid) {
            qint32 nPTSize = ms_demangle_PointerType(pSymbol, pHdata, pParameter, sString);

            nResult += nPTSize;
            sString = sString.mid(nPTSize, -1);
        }
    } else if (_compare(sString, "Y"))  // Array
    {
        sString = sString.mid(1, -1);
        nResult += 1;

        while (pSymbol->bIsValid) {
            NUMBER number = readNumber(pHdata, sString, pSymbol->mode);

            if (number.nSize == 0) {
                break;
            }

            pParameter->listIndexes.append(number.nValue);

            sString = sString.mid(number.nSize, -1);
            nResult += number.nSize;
        }

        if (_compare(sString, "$$C")) {
            sString = sString.mid(3, -1);
            nResult += 3;

            if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
                SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

                pParameter->nQualifier |= signature.nValue;

                nResult += signature.nSize;
                sString = sString.mid(signature.nSize, -1);
            }
        }

        qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, pParameter, sString, MSDT_DROP);

        sString = sString.mid(nTSize, -1);
        nResult += nTSize;
    } else if (isSignaturePresent(sString, &(pHdata->mapTypes))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapTypes));
        pParameter->type = (XTYPE)signature.nValue;
        pParameter->st = ST_TYPE;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);
    } else if (_compare(sString, "$$A8@@"))  // Function
    {
        sString = sString.mid(6, -1);
        nResult += 6;

        pParameter->st = ST_FUNCTION;

        qint32 nFSize = ms_demangle_FunctionType(pSymbol, pHdata, pParameter, sString, true);

        sString = sString.mid(nFSize, -1);
        nResult += nFSize;
    } else if (_compare(sString, "$$A6"))  // Function
    {
        sString = sString.mid(4, -1);
        nResult += 4;

        pParameter->st = ST_FUNCTION;

        qint32 nFSize = ms_demangle_FunctionType(pSymbol, pHdata, pParameter, sString, false);

        sString = sString.mid(nFSize, -1);
        nResult += nFSize;
    } else {
#ifdef QT_DEBUG
        qDebug("%s", "TODO: TYPE");
#endif
        pSymbol->bIsValid = false;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_PointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;

    qint32 nResult = 0;

    pParameter->st = ST_POINTER;

    if (isSignaturePresent(_sString, &(pHdata->mapPointerTypes))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapPointerTypes));

        pParameter->nQualifier = signature.nValue;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);
    }

    if (_compare(_sString, "6")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        DPARAMETER parameter = {};
        parameter.st = ST_FUNCTION;
        //        parameter.type=XTYPE_FUNCTION;
        //        pParameter->type=XTYPE_POINTERTOFUNCTION; // TODO remove

        qint32 nFTSize = ms_demangle_FunctionType(pSymbol, pHdata, &parameter, _sString, false);
        pParameter->listPointer.append(parameter);

        nResult += nFTSize;
        _sString = _sString.mid(nFTSize, -1);
    } else {
        qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, _sString, &(pParameter->nQualifier));

        nResult += nESize;
        _sString = _sString.mid(nESize, -1);

        DPARAMETER parameter = {};

        qint32 nPSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_MANGLE);

        pParameter->listPointer.append(parameter);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_MemberPointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    pParameter->st = ST_POINTER;

    if (isSignaturePresent(sString, &(pHdata->mapPointerTypes))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapPointerTypes));

        pParameter->nQualifier = signature.nValue;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);
    }

    qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, sString, &(pParameter->nQualifier));

    nResult += nESize;
    sString = sString.mid(nESize, -1);

    if (_compare(sString, "8")) {
        nResult += 1;
        sString = sString.mid(1, -1);

        DPARAMETER parameter = {};
        parameter.st = ST_FUNCTION;

        qint32 nFTSize = ms_demangle_FullTypeName(pSymbol, pHdata, pParameter, sString);

        nResult += nFTSize;
        sString = sString.mid(nFTSize, -1);

        qint32 nPSize = ms_demangle_FunctionType(pSymbol, pHdata, &parameter, sString, true);

        pParameter->listPointer.append(parameter);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);
    } else {
        DPARAMETER parameter = {};

        if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

            parameter.nQualifier = signature.nValue;

            nResult += signature.nSize;
            sString = sString.mid(signature.nSize, -1);
        }

        qint32 nFTSize = ms_demangle_FullTypeName(pSymbol, pHdata, pParameter, sString);

        nResult += nFTSize;
        sString = sString.mid(nFTSize, -1);

        qint32 nPSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_DROP);

        pParameter->listPointer.append(parameter);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FullTypeName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    qint32 nUnkName = ms_demangle_UnkTypeName(pSymbol, pHdata, pParameter, sString, true);
    nResult += nUnkName;

    sString = sString.mid(nUnkName, -1);

    qint32 nNameScope = ms_demangle_NameScope(pSymbol, pHdata, pParameter, sString);
    nResult += nNameScope;

    sString = sString.mid(nNameScope, -1);

    reverseList(&(pParameter->listDnames));

    return nResult;
}

qint32 XDemangle::ms_demangle_FullSymbolName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    qint32 nUnkName = ms_demangle_UnkSymbolName(pSymbol, pHdata, pParameter, sString, NB_SIMPLE);
    nResult += nUnkName;

    sString = sString.mid(nUnkName, -1);

    qint32 nNameScope = ms_demangle_NameScope(pSymbol, pHdata, pParameter, sString);
    nResult += nNameScope;

    sString = sString.mid(nNameScope, -1);

    reverseList(&(pParameter->listDnames));

    return nResult;
}

qint32 XDemangle::ms_demangle_UnkTypeName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString, bool bSave)
{
    QString _sString = sString;

    qint32 nResult = 0;

    if (isReplaceStringPresent(pSymbol, pHdata, _sString)) {
        SIGNATURE signature = getReplaceStringSignature(pSymbol, pHdata, _sString);
        // TODO Error empty String
        DNAME dname = {};
        dname.sName = signature.sString;

        pParameter->listDnames.append(dname);

        _sString = _sString.mid(signature.nSize, -1);
        nResult += signature.nSize;
    } else if (_compare(_sString, "?$")) {
        qint32 nTSize = ms_demangle_Template(pSymbol, pHdata, pParameter, _sString, NB_TEMPLATE);
        _sString = _sString.mid(nTSize, -1);
        nResult += nTSize;
    } else {
        STRING string = readString(pHdata, _sString, pSymbol->mode);

        if (string.nSize) {
            if (bSave) {
                addStringRef(pSymbol, pHdata, string.sString);
            }

            DNAME dname = {};
            dname.sName = string.sString;

            pParameter->listDnames.append(dname);

            _sString = _sString.mid(string.nSize, -1);
            nResult += string.nSize;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_UnkSymbolName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString, NB nb)
{
    qint32 nResult = 0;

    if (isReplaceStringPresent(pSymbol, pHdata, sString)) {
        SIGNATURE signature = getReplaceStringSignature(pSymbol, pHdata, sString);
        // TODO Error empty String
        DNAME dname = {};
        dname.sName = signature.sString;

        pParameter->listDnames.append(dname);

        sString = sString.mid(signature.nSize, -1);
        nResult += signature.nSize;
    } else if (_compare(sString, "?$")) {
        qint32 nTSize = ms_demangle_Template(pSymbol, pHdata, pParameter, sString, nb);
        sString = sString.mid(nTSize, -1);
        nResult += nTSize;
    } else if (isSignaturePresent(sString, &(pHdata->mapOperators))) {
        DNAME dname = {};
        SIGNATURE signature = getSignature(sString, &(pHdata->mapOperators));
        dname._operator = (OP)signature.nValue;
        nResult += signature.nSize;

        pParameter->listDnames.append(dname);
    } else {
        STRING string = readString(pHdata, sString, pSymbol->mode);

        if (string.nSize) {
            if (nb & NB_SIMPLE) {
                addStringRef(pSymbol, pHdata, string.sString);
            }

            DNAME dname = {};
            dname.sName = string.sString;

            pParameter->listDnames.append(dname);

            sString = sString.mid(string.nSize, -1);
            nResult += string.nSize;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    while (sString != "") {
        if (isReplaceStringPresent(pSymbol, pHdata, sString)) {
            SIGNATURE signature = getReplaceStringSignature(pSymbol, pHdata, sString);
            // TODO Error empty String
            DNAME dname = {};
            dname.sName = signature.sString;

            pParameter->listDnames.append(dname);

            sString = sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        } else if (_compare(sString, "?$")) {
            qint32 nTSize = ms_demangle_Template(pSymbol, pHdata, pParameter, sString, NB_TEMPLATE);
            sString = sString.mid(nTSize, -1);
            nResult += nTSize;
        } else if (_compare(sString, "?A")) {
#ifdef QT_DEBUG
            qDebug("TODO: AnonymousNamespaceName");
#endif
            sString = sString.mid(2, -1);
            nResult += 2;
        } else if (isLocalScopePresent(pSymbol, pHdata, sString)) {
            SIGNATURE signature = getLocalScopeSignature(pSymbol, pHdata, sString);

            DNAME dnameLocalScope = {};
            dnameLocalScope.sName = QString("`%1'").arg(signature.sValue);

            pParameter->listDnames.append(dnameLocalScope);

            sString = sString.mid(signature.nSize, -1);
            nResult += signature.nSize;

            DSYMBOL symbol = ms_getSymbol(sString, pSymbol->mode, pHdata);

            DNAME dnameSymbol = {};
            dnameSymbol.sName = QString("`%1'").arg(dsymbolToString(symbol));

            pParameter->listDnames.append(dnameSymbol);

            sString = sString.mid(symbol.nSize, -1);
            nResult += symbol.nSize;
        } else {
            STRING string = readString(pHdata, sString, pSymbol->mode);

            if (string.nSize) {
                addStringRef(pSymbol, pHdata, string.sString);

                DNAME dname = {};
                dname.sName = string.sString;

                pParameter->listDnames.append(dname);

                sString = sString.mid(string.nSize, -1);
                nResult += string.nSize;
            }
        }

        if (_compare(sString, "@")) {
            nResult += 1;
            sString = sString.mid(1, -1);

            break;
        }

        if (!(pSymbol->bIsValid)) {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Declarator(DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pDParameter, QString sString)
{
    qint32 nResult = 0;

    qint32 nFNSize = ms_demangle_FullSymbolName(pSymbol, pHdata, pDParameter, sString);

    nResult += nFNSize;
    sString = sString.mid(nFNSize, -1);

    qint32 nRSize = ms_demangle_Parameters(pSymbol, pHdata, pDParameter, sString);

    nResult += nRSize;
    sString = sString.mid(nRSize, -1);

    return nResult;
}

qint32 XDemangle::ms_demangle_Parameters(DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    if (_compare(sString, "0") || _compare(sString, "1") || _compare(sString, "2") || _compare(sString, "3") || _compare(sString, "4")) {
        // Variables
        pParameter->st = ST_VARIABLE;

        qint32 nVSize = ms_demangle_Variable(pSymbol, pHdata, pParameter, sString);
        nResult += nVSize;
    } else {
        // Functions
        pParameter->st = ST_FUNCTION;
        qint32 nFSize = ms_demangle_Function(pSymbol, pHdata, pParameter, sString);
        nResult += nFSize;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Function(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    if (_compare(sString, "$$J0")) {
        nResult += 4;
        sString = sString.mid(4, -1);
        pParameter->nAccess = FM_EXTERNC;
    }

    if (isSignaturePresent(sString, &(pHdata->mapAccessMods))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapAccessMods));
        pParameter->nAccess |= signature.nValue;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);
    }

    if (pParameter->nAccess & FM_STATICTHISADJUST) {
#ifdef QT_DEBUG
        qDebug("TODO: FM_STATICTHISADJUST");
#endif
    }

    if (pParameter->nAccess & FM_VIRTUALTHISADJUST) {
#ifdef QT_DEBUG
        qDebug("TODO: FM_VIRTUALTHISADJUST");
#endif
    }

    if (!(pParameter->nAccess & FM_NOPARAMETERLIST)) {
        bool bThisQual = !(pParameter->nAccess & (FM_GLOBAL | FM_STATIC));

        qint32 nFSize = ms_demangle_FunctionType(pSymbol, pHdata, pParameter, sString, bThisQual);

        nResult += nFSize;
        sString = sString.mid(nFSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Variable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    if (isSignaturePresent(sString, &(pHdata->mapAccessMods))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapAccessMods));

        pParameter->nAccess = signature.nValue;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);
    }

    DPARAMETER parameter = {};
    parameter.st = ST_TYPE;

    qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_DROP);

    pParameter->listParameters.append(parameter);

    nResult += nTSize;
    sString = sString.mid(nTSize, -1);

    if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

        pParameter->nQualifier = signature.nValue;
        sString = sString.mid(signature.nSize, -1);
        nResult += signature.nSize;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, bool bThisQual)
{
    qint32 nResult = 0;

    if (bThisQual) {
        qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, sString, &(pParameter->nQualifier));

        sString = sString.mid(nESize, -1);
        nResult += nESize;

        if (_compare(sString, "G")) {
            pParameter->nRefQualifier |= QUAL_REFERENCE;
            sString = sString.mid(1, -1);
            nResult += 1;
        } else if (_compare(sString, "H")) {
            pParameter->nRefQualifier |= QUAL_RVALUEREF;
            sString = sString.mid(1, -1);
            nResult += 1;
        }

        if (isSignaturePresent(sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(sString, &(pHdata->mapQualifiers));

            pParameter->nRefQualifier |= signature.nValue;
            sString = sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        }
    }

    if (isSignaturePresent(sString, &(pHdata->mapFunctionConventions))) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapFunctionConventions));

        pParameter->functionConvention = (FC)signature.nValue;
        sString = sString.mid(signature.nSize, -1);
        nResult += signature.nSize;
    }

    if (_compare(sString, "@")) {
        pParameter->type = XTYPE_NONE;
        sString = sString.mid(1, -1);
        nResult += 1;
    } else {
        DPARAMETER parameter = {};

        qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_RESULT);

        pParameter->listReturn.append(parameter);

        nResult += nTSize;
        sString = sString.mid(nTSize, -1);
    }

    if (_compare(sString, "X")) {
        // Void
        DPARAMETER parameter = {};

        qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_DROP);

        pParameter->listParameters.append(parameter);

        sString = sString.mid(nTSize, -1);
        nResult += nTSize;
    } else {
        qint32 nPSize = ms_demangle_FunctionParameters(pSymbol, pHdata, pParameter, sString);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);
    }

    if (_compare(sString, "Z")) {
        nResult += 1;
        sString = sString.mid(1, -1);
    } else if (_compare(sString, "_E")) {
#ifdef QT_DEBUG
        qDebug("TODO: function exception");
#endif

        pSymbol->bIsValid = false;

        nResult += 2;
        sString = sString.mid(2, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    while (sString != "") {
        bool bBreak = false;

        if (_compare(sString, "@")) {
            sString = sString.mid(1, -1);
            nResult += 1;

            break;
        } else if (_compare(sString, "Z")) {
            bBreak = true;
        }

        if (isReplaceArgPresent(pSymbol, pHdata, sString)) {
            SIGNATURE signature = getReplaceArgSignature(pSymbol, pHdata, sString);

            DPARAMETER parameter = {};

            ms_demangle_Type(pSymbol, pHdata, &parameter, signature.sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            sString = sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        } else {
            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            QString sArg = sString.left(nTSize);
            addArgRef(pSymbol, pHdata, sArg);

            nResult += nTSize;
            sString = sString.mid(nTSize, -1);
        }

        if (bBreak) {
            break;
        }

        if (!(pSymbol->bIsValid)) {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Template(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, XDemangle::NB nb)
{
    qint32 nResult = 0;

    if (_compare(sString, "?$")) {
        sString = sString.mid(2, -1);
        nResult += 2;

        XDemangle::HDATA hdata = *pHdata;
        hdata.listArgRef.clear();
        hdata.listStringRef.clear();

        DPARAMETER parameter = {};
        parameter.st = ST_TEMPLATE;

        qint32 nNName = ms_demangle_UnkSymbolName(pSymbol, &hdata, &parameter, sString, NB_SIMPLE);
        sString = sString.mid(nNName, -1);
        nResult += nNName;

        qint32 nTName = ms_demangle_TemplateParameters(pSymbol, &hdata, &parameter, sString);
        sString = sString.mid(nTName, -1);
        nResult += nTName;

        QString sName = _nameToString(pSymbol, &parameter);
        //        QString sTemplate=ms_parameterToString(pSymbol,&parameter,sName);
        QString sTemplate = ms_parameterToString(pSymbol, &parameter, sName, "");

        DNAME dname = {};
        dname.sName = sTemplate;

        pParameter->listDnames.append(dname);

        if (nb & NB_TEMPLATE) {
            addStringRef(pSymbol, pHdata, sTemplate);
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_TemplateParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    while (sString != "") {
        if (_compare(sString, "@")) {
            break;
        }

        if (_compare(sString, "$S")) {
            nResult += 2;
            sString = sString.mid(2, -1);
        }

        if (_compare(sString, "$$V") || _compare(sString, "$$Z")) {
            nResult += 3;
            sString = sString.mid(3, -1);
        }

        if (_compare(sString, "$$$V")) {
            nResult += 4;
            sString = sString.mid(4, -1);
        }

        if (_compare(sString, "$$Y")) {
            nResult += 3;
            sString = sString.mid(3, -1);

            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("TODO: Template alias");
#endif
        } else if (_compare(sString, "$$B")) {
            // TODO Check
            nResult += 3;
            sString = sString.mid(3, -1);

            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            nResult += nTSize;
            sString = sString.mid(nTSize, -1);
        } else if (_compare(sString, "$$C")) {
            nResult += 3;
            sString = sString.mid(3, -1);

            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_MANGLE);

            pParameter->listParameters.append(parameter);

            nResult += nTSize;
            sString = sString.mid(nTSize, -1);
        } else if (_compare(sString, "$1") || _compare(sString, "$H") || _compare(sString, "$I") || _compare(sString, "$J")) {
            nResult += 2;
            sString = sString.mid(2, -1);

            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("TODO: Template");
#endif
        } else if (_compare(sString, "$E?")) {
            nResult += 3;
            sString = sString.mid(3, -1);

            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("TODO: Reference to symbol");
#endif
        } else if (_compare(sString, "$0")) {
            nResult += 2;
            sString = sString.mid(2, -1);

            NUMBER number = readNumber(pHdata, sString, pSymbol->mode);

            DPARAMETER parameter = {};

            parameter.st = ST_CONST;
            parameter.varConst = QString::number(number.nValue);

            pParameter->listParameters.append(parameter);

            nResult += number.nSize;
            sString = sString.mid(number.nSize, -1);
        } else {
            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            nResult += nTSize;
            sString = sString.mid(nTSize, -1);

            if (!(pSymbol->bIsValid)) {
                break;
            }
        }
    }

    if (_compare(sString, "@")) {
        sString = sString.mid(1, -1);
        nResult += 1;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_ExtQualifiers(XDemangle::DSYMBOL *pSymbol, const QString &sString, quint32 *pnQual)
{
    QString _sString = sString;
    Q_UNUSED(pSymbol)

    qint32 nResult = 0;

    if (_compare(_sString, "E"))  // mb TODO Check MODE_MSVC64
    {
        (*pnQual) |= QUAL_POINTER64;
        _sString = _sString.mid(1, -1);
        nResult += 1;
    }
    if (_compare(_sString, "I")) {
        (*pnQual) |= QUAL_RESTRICT;
        _sString = _sString.mid(1, -1);
        nResult += 1;
    }
    if (_compare(_sString, "F")) {
        (*pnQual) |= QUAL_UNALIGNED;
        _sString = _sString.mid(1, -1);
        nResult += 1;
    }

    return nResult;
}

bool XDemangle::ms_isPointerMember(XDemangle::DSYMBOL *pSymbol, HDATA *pHdata, QString sString)
{
    if (_compare(sString, "$")) {
        // rvalue ref
        return false;
    } else if (_compare(sString, "A")) {
        // ref
        return false;
    }
    // PQRS
    sString = sString.mid(1, -1);

    if (isSignaturePresent(sString, &(pHdata->mapNumbers))) {
        if ((!_compare(sString, "6")) && (!_compare(sString, "8"))) {
            pSymbol->bIsValid = false;

            return false;
        }

        return _compare(sString, "8");
    }

    quint32 nQual = 0;

    qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, sString, &nQual);

    sString = sString.mid(nESize, -1);

    if (sString == "") {
        pSymbol->bIsValid = false;

        return false;
    }

    if (_compare(sString, "A") || _compare(sString, "B") || _compare(sString, "C") || _compare(sString, "D")) {
        return false;
    }

    if (_compare(sString, "Q") || _compare(sString, "R") || _compare(sString, "S") || _compare(sString, "T")) {
        return true;
    }

    pSymbol->bIsValid = false;

    return false;
}

void XDemangle::addStringRef(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if (!pHdata->listStringRef.contains(sString)) {
            if (pHdata->listStringRef.count() < 10) {
                pHdata->listStringRef.append(sString);
            }
        }
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        qFatal("Remove");
    }
}

void XDemangle::addArgRef(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if (sString.size() > 1) {
            if (!pHdata->listArgRef.contains(sString)) {
                if (pHdata->listArgRef.count() < 10) {
                    pHdata->listArgRef.append(sString);
                }
            }
        }
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        pHdata->listArgRef.append(sString);
    }
}

void XDemangle::addStringListRef(DSYMBOL *pSymbol, HDATA *pHdata, QList<QString> listString)
{
    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        pHdata->listListStringRef.append(listString);
    }
}

bool XDemangle::isReplaceStringPresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    QString _sString = sString;
    bool bResult = false;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        bResult = isSignaturePresent(_sString, &(pHdata->mapNumbers));
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (_compare(_sString, "S")) {
            _sString = _sString.mid(1, -1);

            NUMBER number = readSymNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize) {
                _sString = _sString.mid(number.nSize, -1);
            }

            if (_compare(_sString, "_")) {
                _sString = _sString.mid(1, -1);

                bResult = true;
            }
        }
    }

    return bResult;
}

bool XDemangle::isReplaceArgPresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    QString _sString = sString;

    bool bResult = false;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        bResult = isSignaturePresent(_sString, &(pHdata->mapNumbers));
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (_compare(_sString, "T")) {
            _sString = _sString.mid(1, -1);

            NUMBER number = readSymNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize) {
                _sString = _sString.mid(number.nSize, -1);
            }

            if (_compare(_sString, "_")) {
                _sString = _sString.mid(1, -1);

                bResult = true;
            }
        }
    }

    return bResult;
}

bool XDemangle::isLocalScopePresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    bool bResult = false;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if (_compare(sString, "?")) {
            sString = sString.mid(1, -1);

            NUMBER number = readNumber(pHdata, sString, pSymbol->mode);

            if (number.nSize) {
                sString = sString.mid(number.nSize, -1);

                if (_compare(sString, "?")) {
                    bResult = true;
                }
            }
        }
    }

    return bResult;
}

XDemangle::SIGNATURE XDemangle::getReplaceStringSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    SIGNATURE result = {};

    qint32 nIndex = -1;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapNumbers));

        nIndex = signature.nValue;
        result.nSize = 1;
        result.nValue = signature.nValue;
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (_compare(sString, "S")) {
            sString = sString.mid(1, -1);

            NUMBER number = readSymNumber(pHdata, sString, pSymbol->mode);

            if (number.nSize) {
                sString = sString.mid(number.nSize, -1);
                result.nValue = number.nValue + 1;
            }

            if (_compare(sString, "_")) {
                sString = sString.mid(1, -1);

                result.nSize = 2 + number.nSize;

                nIndex = result.nValue;
            }
        }
    }

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if ((nIndex != -1) && (nIndex < pHdata->listStringRef.count())) {
            result.sString = pHdata->listStringRef.at(nIndex);
        } else {
            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("Replace String Error!!!");
#endif
        }
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if ((nIndex != -1) && (nIndex < pHdata->listListStringRef.count())) {
            result.listStrings = pHdata->listListStringRef.at(nIndex);
        } else {
            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("Replace String Error!!!");
#endif
        }
    }

    return result;
}

XDemangle::SIGNATURE XDemangle::getReplaceArgSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, QString sString)
{
    SIGNATURE result = {};

    QString sOrigString = sString;

    qint32 nIndex = 0;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        SIGNATURE signature = getSignature(sString, &(pHdata->mapNumbers));
        result.nSize = 1;
        nIndex = signature.nValue;
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (_compare(sString, "T")) {
            sString = sString.mid(1, -1);

            NUMBER number = readSymNumber(pHdata, sString, pSymbol->mode);

            if (number.nSize) {
                sString = sString.mid(number.nSize, -1);
                result.nValue = number.nValue + 1;
            }

            if (_compare(sString, "_")) {
                sString = sString.mid(1, -1);

                result.nSize = 2 + number.nSize;

                nIndex = result.nValue;
            }
        }
    }

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if (nIndex < pHdata->listArgRef.count()) {
            result.sString = pHdata->listArgRef.at(nIndex);
            result.nValue = nIndex;
        } else {
            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("Replace Arg Error!!!");
#endif
        }
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        bool bSuccess = false;

        if (pHdata->listListTemplates.count()) {
            qint32 nCount = pHdata->listListTemplates.first().count();
            bSuccess = (nIndex < nCount);
        }

        if (bSuccess) {
            result.sString = pHdata->listListTemplates.first().at(nIndex);
            result.nValue = nIndex;
        } else {
            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("Replace Arg Error!!! %d %d %s", pHdata->listListTemplates.count(), nIndex, sOrigString.toLatin1().data());
#endif
            //            pSymbol->bIsValid=true;
            //            result.sString="TEST";
            //            result.nValue=nIndex;
        }
    }

    return result;
}

XDemangle::SIGNATURE XDemangle::getLocalScopeSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    SIGNATURE result = {};

    QString _sString = sString;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if (_compare(_sString, "?")) {
            _sString = _sString.mid(1, -1);

            NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize) {
                _sString = _sString.mid(number.nSize, -1);

                if (_compare(_sString, "?")) {
                    result.nSize = number.nSize + 2;
                    result.sString = sString.left(result.nSize);
                    result.sValue = QString::number(number.nValue);
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

    if (pParameter->st == ST_VARIABLE) {
        if (pParameter->listParameters.count()) {
            DPARAMETER parameter = pParameter->listParameters.at(0);
            DPARAMETER parameterLast = getLastPointerParameter(&parameter);  // TODO GetLast

            QString sAccess = accessIdToString(pParameter->nAccess, pSymbol->mode);
            QString sQual = qualIdToStorageString(pParameter->nQualifier, pSymbol->mode);

            if ((pParameter->nQualifier & QUAL_CONST) && (parameterLast.nQualifier & QUAL_CONST))  // TODO Check
            {
                sQual = "";
            }

            QString sType = ms_parameterToString(pSymbol, &parameter, sName, "");

            if (sAccess != "") sResult += QString("%1 ").arg(sAccess);
            sResult += sType;
            if (sQual != "") sResult += QString(" %1").arg(sQual);

            if (parameter.st != ST_POINTER)  // TODO Check
            {
                if (sName != "") sResult += QString(" %1").arg(sName);
            }
        }
    } else if (pParameter->st == ST_TYPE) {
        QString sType = typeIdToString(pParameter->type, pSymbol->mode);
        QString sQual = qualIdToPointerString(pParameter->nQualifier, pSymbol->mode);
        QString sTypeName = _nameToString(pSymbol, pParameter);

        sResult += sType;

        if (sTypeName != "") sResult += QString(" %1").arg(sTypeName);

        if (sQual != "") sResult += QString(" %1").arg(sQual);
    } else if (pParameter->st == ST_CONST) {
        sResult += pParameter->varConst.toString();
    } else if (pParameter->st == ST_NAME) {
        sResult = _nameToString(pSymbol, pParameter);
    } else if (pParameter->st == ST_POINTER) {
        if (pParameter->listPointer.count()) {
            DPARAMETER lastParameter = getLastPointerParameter(pParameter);

            QString sPointer = ms_getPointerString(pSymbol, pParameter, sName);

            QString _sPrefix = sPointer;
            if (sPrefix != "") {
                _sPrefix += " ";
                _sPrefix += sPrefix;
            }

            sResult = ms_parameterToString(pSymbol, &lastParameter, "", _sPrefix);

            if (lastParameter.st != ST_FUNCTION) {
                if (!isPointerEnd(sResult))  // TODO Function
                {
                    sResult += QString(" ");
                }

                sResult += QString("%1").arg(sPointer);
            }
        }
    } else if (pParameter->st == ST_FUNCTION) {
        QString sAccess = accessIdToString(pParameter->nAccess, pSymbol->mode);
        QString sConv = functionConventionIdToString(pParameter->functionConvention, pSymbol->mode);
        QString sRefQualStorage = qualIdToStorageString(pParameter->nRefQualifier, pSymbol->mode);
        QString sRefQualPointer = qualIdToPointerString((pParameter->nRefQualifier) & (~(QUAL_CONST)), pSymbol->mode);
        QString sReturn;
        QString sArgs;

        //        TYPE typeReturn=XTYPE_NONE;

        sArgs += "(";

        qint32 nNumberOfParameters = pParameter->listParameters.count();

        for (qint32 i = 0; i < nNumberOfParameters; i++) {
            DPARAMETER parameter = pParameter->listParameters.at(i);

            sArgs += ms_parameterToString(pSymbol, &parameter, "", "");

            if (i != (nNumberOfParameters - 1)) {
                sArgs += ", ";
            }
        }

        sArgs += ")";

        if (pParameter->listReturn.count()) {
            DPARAMETER parameter = pParameter->listReturn.at(0);
            //            typeReturn=parameter.type;
        }

        QString _sPrefix;

        if (sPrefix != "") _sPrefix += "(";

        if (sConv != "") _sPrefix += sConv;

        if ((sPrefix != "") || (sName != "")) {
            if (sConv != "") _sPrefix += " ";

            if (sPrefix != "") _sPrefix += QString("%1").arg(sPrefix);
            if (sName != "") _sPrefix += QString("%1").arg(sName);
        }

        if (sPrefix != "") _sPrefix += ")";
        _sPrefix += sArgs;
        if (sRefQualStorage != "") _sPrefix += QString(" %1").arg(sRefQualStorage);
        if (sRefQualPointer != "") _sPrefix += QString(" %1").arg(sRefQualPointer);

        bool bFuncReturn = false;

        if (pParameter->listReturn.count()) {
            DPARAMETER parameter = pParameter->listReturn.at(0);

            bFuncReturn = (getLastPointerParameter(&parameter).st == ST_FUNCTION);

            sReturn = ms_parameterToString(pSymbol, &parameter, "", _sPrefix);
        }

        if (sAccess != "") sResult += QString("%1 ").arg(sAccess);
        if (sReturn != "") sResult += QString("%1").arg(sReturn);

        if (!bFuncReturn) {
            if (_getStringEnd(sResult) != QChar(' ')) sResult += " ";

            sResult += _sPrefix;
        }
    } else if (pParameter->st == ST_TYPEINFO) {
        if (pParameter->listTarget.count()) {
            DPARAMETER parameter = pParameter->listTarget.at(0);

            sResult = QString("%1 `RTTI Type Descriptor Name'").arg(ms_parameterToString(pSymbol, &parameter, "", ""));  // TODO
        }
    } else if ((pParameter->st == ST_VFTABLE) || (pParameter->st == ST_VBTABLE) || (pParameter->st == ST_LOCALVFTABLE) || (pParameter->st == ST_RTTICOMPLETEOBJLOCATOR)) {
        QString sSC = qualIdToStorageString(pParameter->nQualifier, pSymbol->mode);
        if (sSC != "") sResult += QString("%1 ").arg(sSC);

        if (pParameter->st == ST_VFTABLE) {
            sResult += sName + QString("::`vftable'");
        } else if (pParameter->st == ST_VBTABLE) {
            sResult += sName + QString("::`vbtable'");
        } else if (pParameter->st == ST_LOCALVFTABLE) {
            sResult += sName + QString("::`local vftable'");
        } else if (pParameter->st == ST_RTTICOMPLETEOBJLOCATOR) {
            sResult += sName + QString("::`RTTI Complete Object Locator'");
        }

        if (pParameter->listTarget.count()) {
            DPARAMETER parameter = pParameter->listTarget.at(0);

            sResult += QString("{for `%1'}").arg(ms_parameterToString(pSymbol, &parameter, "", ""));
        }
    } else if ((pParameter->st == ST_LOCALSTATICGUARD) || (pParameter->st == ST_LOCALSTATICTHREADGUARD)) {
        sResult = (_nameToString(pSymbol, pParameter));

        if (pParameter->st == ST_LOCALSTATICGUARD) {
            sResult += QString("::`local static guard'");
        } else if (pParameter->st == ST_LOCALSTATICTHREADGUARD) {
            sResult += sName + QString("::`local static thread guard'");
        }

        if (pParameter->sScope != "") {
            sResult += QString("{%1}").arg(pParameter->sScope);
        }
    } else if ((pParameter->st == ST_RTTIBASECLASSARRAY) || (pParameter->st == ST_RTTICLASSHIERARCHYDESCRIPTOR)) {
        sResult = (_nameToString(pSymbol, pParameter));

        if (pParameter->st == ST_RTTIBASECLASSARRAY) {
            sResult += QString("::`RTTI Base Class Array'");
        } else if (pParameter->st == ST_RTTICLASSHIERARCHYDESCRIPTOR) {
            sResult += QString("::`RTTI Class Hierarchy Descriptor'");
        }
    } else if (pParameter->st == ST_TEMPLATE) {
        sResult += sName;
        sResult += "<";

        qint32 nNumberOfParameters = pParameter->listParameters.count();

        for (qint32 i = 0; i < nNumberOfParameters; i++) {
            DPARAMETER parameter = pParameter->listParameters.at(i);

            sResult += ms_parameterToString(pSymbol, &parameter, "", "");

            if (i != (nNumberOfParameters - 1)) {
                sResult += ", ";
            }
        }

        sResult += ">";
    }

    return sResult;
}

QString XDemangle::_nameToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter)
{
    QString sResult;

    // TODO function
    qint32 nNumberOfNames = pParameter->listDnames.count();

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (nNumberOfNames > 1) {
            if ((pParameter->listDnames.at(nNumberOfNames - 1)._operator == OP_CONSTRUCTOR) ||
                (pParameter->listDnames.at(nNumberOfNames - 1)._operator == OP_DESTRUCTOR)) {
                QString sOperator = pParameter->listDnames.at(nNumberOfNames - 2).sName;

                bool bReplace = false;

                if (sOperator == "std::istream") {
                    sOperator = "std::basic_istream<char, std::char_traits<char> >";
                    bReplace = true;
                } else if (sOperator == "std::ostream") {
                    sOperator = "std::basic_ostream<char, std::char_traits<char> >";
                    bReplace = true;
                } else if (sOperator == "std::iostream") {
                    sOperator = "std::basic_iostream<char, std::char_traits<char> >";
                    bReplace = true;
                } else if (sOperator == "std::string") {
                    sOperator = "std::basic_string<char, std::char_traits<char>, std::allocator<char> >";
                    bReplace = true;
                }

                if (bReplace) {
                    pParameter->listDnames[nNumberOfNames - 2].sName = sOperator;
                }
            }
        }
    }

    for (qint32 i = 0; i < nNumberOfNames; i++) {
        QString _sName;

        if (pParameter->listDnames.at(i)._operator != OP_UNKNOWN) {
            _sName += operatorIdToString(pParameter->listDnames.at(i)._operator, pSymbol->mode);

            if ((pParameter->listDnames.at(i)._operator == OP_CONSTRUCTOR) || (pParameter->listDnames.at(i)._operator == OP_DESTRUCTOR)) {
                if (nNumberOfNames > 1) {
                    QString sBasic = pParameter->listDnames.at(nNumberOfNames - 2).sName;

                    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
                        if (sBasic.contains("<"))  // Template
                        {
                            sBasic = sBasic.section("<", 0, 0);
                        }

                        if (sBasic.contains("["))  // abi
                        {
                            sBasic = sBasic.section("[", 0, 0);
                        }

                        if (sBasic.contains("::")) {
                            sBasic = sBasic.section("::", -1, -1);
                        }
                    }

                    _sName += sBasic;
                }
            } else if (pParameter->listDnames.at(i)._operator == OP_TYPE) {
                if (pSymbol->paramMain.listReturn.count()) {
                    DPARAMETER parameter = pSymbol->paramMain.listReturn.at(0);
                    _sName += ms_parameterToString(pSymbol, &parameter, "", "");
                }
            }
        }

        if (pParameter->listDnames.at(i).sName != "") {
            _sName += pParameter->listDnames.at(i).sName;
        }

        sResult += _sName;

        if (i != (nNumberOfNames - 1)) {
            sResult += "::";
        }
    }

    return sResult;
}

XDemangle::DPARAMETER XDemangle::getLastPointerParameter(XDemangle::DPARAMETER *pParameter)
{
    DPARAMETER result = *pParameter;

    while (result.st == ST_POINTER) {
        if (result.listPointer.count()) {
            result = result.listPointer.at(0);
        } else {
            break;
        }
    }

    return result;
}

QString XDemangle::ms_getPointerString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, QString sName)
{
    QString sResult;

    DPARAMETER parameter = *pParameter;

    qint32 i = 0;

    QString sMain = sName;
    QString sPrefix;
    QString sIndexes;
    bool bArray = false;

    while (parameter.st == ST_POINTER) {
        QString _sName = _nameToString(pSymbol, &parameter);
        QString sPointer = qualIdToPointerString(parameter.nQualifier, pSymbol->mode);

        if (_sName != "") {
            sPointer = QString("%1::%2").arg(_sName, sPointer);
        }

        if (i == 0) {
            if ((sMain != "") && (!isPointerEnd(sPointer))) {
                sPointer += " ";
            }

            sMain = sMain.prepend(sPointer);
        } else {
            if ((sPrefix != "") && (!isPointerEnd(sPointer))) {
                sPointer += " ";
            }

            sPrefix = sPrefix.prepend(sPointer);
        }

        if (parameter.listPointer.count()) {
            parameter = parameter.listPointer.at(0);
        } else {
            break;
        }

        qint32 nNumberOfIndexes = parameter.listIndexes.count();

        for (qint32 j = 1; j < nNumberOfIndexes; j++) {
            bArray = true;
            sIndexes += QString("[%1]").arg(parameter.listIndexes.at(j));
        }

        i++;
    }

    if (bArray) {
        sMain = QString("(%1)").arg(sMain);
        sMain += sIndexes;
    }

    sResult = sPrefix;

    if (sMain != "") {
        if ((sResult != "") && (!isPointerEnd(sResult))) {
            sResult += " ";
        }

        sResult += sMain;
    }

    return sResult;
}

QString XDemangle::itanium_parameterToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, QString sPrefix)
{
    QString sResult;

    QString sName = _nameToString(pSymbol, pParameter);

    if (pParameter->listClass.count()) {
        DPARAMETER parameter = pParameter->listClass.at(0);
        QString sClass = _nameToString(pSymbol, &parameter);

        sName = QString("(%1::*)").arg(sClass);
    }

    if (pParameter->st == ST_TYPE) {
        QString sType = typeIdToString(pParameter->type, pSymbol->mode);

        sResult = sType;
    } else if (pParameter->st == ST_PACKEDTYPE) {
        QString sType = typeIdToString(pParameter->type, pSymbol->mode);

        sResult = sType + "...";
    } else if (pParameter->st == ST_POINTER) {
        DPARAMETER lastParameter = getLastPointerParameter(pParameter);

        QString sPointer = itanium_getPointerString(pSymbol, pParameter);

        sResult = itanium_parameterToString(pSymbol, &lastParameter, sPointer);

        if ((sPointer != "") && (lastParameter.st != ST_FUNCTION)) {
            if ((sPointer.at(0) != QChar('*')) && (sPointer.at(0) != QChar('&'))) {
                sResult += " ";
            }

            sResult += sPointer;
        }
    } else if (pParameter->st == ST_NAME) {
        sResult = sName;
    } else if (pParameter->st == ST_VARIABLE) {
        sResult = sName;
    } else if (pParameter->st == ST_TARGET) {
        if (pParameter->listTarget.count()) {
            DPARAMETER parameter = pParameter->listTarget.at(0);

            sResult += itanium_parameterToString(pSymbol, &parameter, "");
            sResult += " ";
        }
        sResult += sName;
    } else if (pParameter->st == ST_CONST) {
        if (sName != "") {
            sResult += QString("(%1)").arg(sName);
        }

        QString sValue = pParameter->varConst.toString();

        if (pParameter->typeConst == XTYPE_BOOL) {
            if (sValue == "0") {
                sValue = "false";
            } else if (sValue == "1") {
                sValue = "true";
            }
        }

        sResult += sValue;

        if (pParameter->typeConst == XTYPE_UINT) {
            sResult += "u";
        } else if (pParameter->typeConst == XTYPE_LONGLONG) {
            sResult += "ll";
        }
    } else if (pParameter->st == ST_TEMPLATE) {
        sResult += sName;
        sResult += "<";

        qint32 nNumberOfParameters = pParameter->listParameters.count();

        for (qint32 i = 0; i < nNumberOfParameters; i++) {
            DPARAMETER parameter = pParameter->listParameters.at(i);

            sResult += itanium_parameterToString(pSymbol, &parameter, "");

            if (i != (nNumberOfParameters - 1)) {
                sResult += ", ";
            }
        }

        if (_getStringEnd(sResult) == QChar('>')) {
            sResult += " ";
        }

        sResult += ">";
    } else if (pParameter->st == ST_FUNCTION) {
        QString sFuncConvention = functionConventionIdToString(pParameter->functionConvention, pSymbol->mode);
        QString sQual = qualIdToStorageString(pParameter->nQualifier, pSymbol->mode);

        if (sFuncConvention != "") {
            sResult += QString("%1 ").arg(sFuncConvention);
        }

        if (pParameter->listReturn.count()) {
            DPARAMETER parameter = pParameter->listReturn.at(0);

            sResult += QString("%1 ").arg(itanium_parameterToString(pSymbol, &parameter, ""));
        }

        sResult += sName;

        if (sPrefix != "") {
            sResult += QString("(%1)").arg(sPrefix);
        }

        qint32 nNumberOfParameters = pParameter->listParameters.count();

        if (nNumberOfParameters) {
            sResult += "(";

            for (qint32 i = 0; i < nNumberOfParameters; i++) {
                DPARAMETER parameter = pParameter->listParameters.at(i);

                if ((parameter.st == ST_TYPE) && (parameter.type == XTYPE_VOID)) {
                    break;
                }

                sResult += itanium_parameterToString(pSymbol, &parameter, "");

                if (i != (nNumberOfParameters - 1)) {
                    sResult += ", ";
                }
            }

            sResult += ")";
        }

        if (sQual != "") {
            sResult += QString(" %1").arg(sQual);
        }
    } else if ((pParameter->st == ST_VTABLE) || (pParameter->st == ST_TYPEINFO) || (pParameter->st == ST_TYPEINFONAME) || (pParameter->st == ST_GUARDVARIABLE) ||
               (pParameter->st == ST_TRANSACTIONCLONE) || (pParameter->st == ST_NONVIRTUALTHUNK) || (pParameter->st == ST_VIRTUALTHUNK) || (pParameter->st == ST_VTT) ||
               (pParameter->st == ST_CONSTRUCTIONVTABLE)) {
        if (pParameter->listTarget.count()) {
            DPARAMETER parameter = pParameter->listTarget.at(0);

            QString _sName = itanium_parameterToString(pSymbol, &parameter, "");

            if (pParameter->st == ST_VTABLE) {
                sResult += "vtable for ";
            } else if (pParameter->st == ST_TYPEINFO) {
                sResult += "typeinfo for ";
            } else if (pParameter->st == ST_TYPEINFONAME) {
                sResult += "typeinfo name for ";
            } else if (pParameter->st == ST_GUARDVARIABLE) {
                sResult += "guard variable for ";
            } else if (pParameter->st == ST_TRANSACTIONCLONE) {
                sResult += "transaction clone for ";
            } else if (pParameter->st == ST_NONVIRTUALTHUNK) {
                sResult += "non-virtual thunk to ";
            } else if (pParameter->st == ST_VIRTUALTHUNK) {
                sResult += "virtual thunk to ";
            } else if (pParameter->st == ST_VTT) {
                sResult += "VTT for ";
            } else if (pParameter->st == ST_CONSTRUCTIONVTABLE) {
                sResult += "construction vtable for ";
            }

            sResult += _sName;
        }
    }

    return sResult;
}

qint32 XDemangle::itanium_demangle_Encoding(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    pParameter->st = ST_VARIABLE;

    qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, sString);

    sString = sString.mid(nNSSize, -1);
    nResult += nNSSize;

    bool bReturn = false;

    if (pParameter->listDnames.count()) {
        bReturn = pParameter->listDnames.last().bTemplates;  // TODO Check!!!
    }

    qint32 nPSize = itanium_demangle_Function(pSymbol, pHdata, pParameter, sString, bReturn);

    sString = sString.mid(nPSize, -1);
    nResult += nPSize;

    if (nPSize) {
        pParameter->st = ST_FUNCTION;
    }

    if (_compare(sString, "@") && (pSymbol->mode == MODE_GCC_WIN)) {
        if (pParameter->functionConvention != FC_FASTCALL) {
            pParameter->functionConvention = FC_STDCALL;
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    if (_compare(sString, "Z")) {
        nResult++;
        sString = sString.mid(1, -1);

        DPARAMETER parameter = {};
        qint32 nESize = itanium_demangle_Encoding(pSymbol, pHdata, &parameter, sString);

        DNAME dname = {};
        dname.sName = itanium_parameterToString(pSymbol, &parameter, "");

        pParameter->listDnames.append(dname);

        nResult += nESize;
        sString = sString.mid(nESize, -1);
    }

    bool bNested = false;

    if (_compare(sString, "N")) {
        nResult++;
        sString = sString.mid(1, -1);

        bNested = true;
    }

    if (_compare(sString, "K")) {
        nResult++;
        sString = sString.mid(1, -1);

        pParameter->nQualifier = QUAL_CONST;
    }

    QList<QString> listAddString;

    while (sString != "") {
        //        pHdata->listArgRef.clear();

        DNAME dname = {};

        bool bAdd = true;
        bool bSpecial = false;
        bool bOperator = false;

        if (isReplaceStringPresent(pSymbol, pHdata, sString)) {
            SIGNATURE signature = getReplaceStringSignature(pSymbol, pHdata, sString);

            dname.sName = join(&signature.listStrings, "::");

            nResult += signature.nSize;
            sString = sString.mid(signature.nSize, -1);

            bAdd = false;
        } else if (_compare(sString, "St")) {
            nResult += 2;
            sString = sString.mid(2, -1);

            dname.sName = "std";

            bAdd = false;
            bSpecial = true;
        } else if (pHdata->mapStd.contains(sString.left(2))) {
            QString sStd = pHdata->mapStd.value(sString.left(2));

            nResult += 2;
            sString = sString.mid(2, -1);

            dname.sName = sStd;

            bAdd = false;
            bSpecial = false;
        } else if (_compare(sString, "cv"))  // Conversion
        {
            nResult += 2;
            sString = sString.mid(2, -1);

            DPARAMETER parameter = {};

            qint32 nTSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, sString);

            nResult += nTSize;
            sString = sString.mid(nTSize, -1);

            dname.sName = QString("operator %1").arg(itanium_parameterToString(pSymbol, &parameter, ""));

            // TODO _
        } else if (isSignaturePresent(sString, &(pHdata->mapOperators))) {
            SIGNATURE signature = getSignature(sString, &(pHdata->mapOperators));

            dname._operator = (OP)signature.nValue;

            nResult += signature.nSize;
            sString = sString.mid(signature.nSize, -1);

            bOperator = true;
        } else {
            STRING string = readString(pHdata, sString, pSymbol->mode);

            dname.sName = string.sString;

            nResult += string.nSize;
            sString = sString.mid(string.nSize, -1);

            if (string.nSize == 0) {
                pSymbol->bIsValid = false;
            }
        }

        if (bOperator) {
            listAddString.append(operatorIdToString(dname._operator, pSymbol->mode));
        } else {
            listAddString.append(dname.sName);
        }

        if (_compare(sString, "I"))  // Template
        {
            nResult++;
            sString = sString.mid(1, -1);

            if (bAdd) {
                addStringListRef(pSymbol, pHdata, listAddString);
            }

            bAdd = true;

            DPARAMETER parameter = {};
            parameter.st = ST_TEMPLATE;
            qint32 nPSize = itanium_demangle_Parameters(pSymbol, pHdata, &parameter, sString);

            nResult += nPSize;
            sString = sString.mid(nPSize, -1);

            QString sTemplate = itanium_parameterToString(pSymbol, &parameter, "");

            dname.sName += sTemplate;
            dname.bTemplates = true;

            if (listAddString.count()) {
                listAddString[listAddString.count() - 1] += sTemplate;
            }

            qint32 nNumberOfArgs = parameter.listParameters.count();

            QList<QString> listTemplates;

            for (qint32 i = 0; i < nNumberOfArgs; i++) {
                DPARAMETER _parameter = parameter.listParameters.at(i);
                QString sParameter = itanium_parameterToString(pSymbol, &_parameter, "");
                //                addArgRef(pSymbol,pHdata,sParameter);

                listTemplates.append(sParameter);
            }

            pHdata->listListTemplates.append(listTemplates);

            pParameter->bTemplatePresent = true;
        }

        if (_compare(sString, "B"))  // abi::source
        {
            nResult++;
            sString = sString.mid(1, -1);

            STRING string = readString(pHdata, sString, pSymbol->mode);

            dname.sName += QString("[abi:%1]").arg(string.sString);

            nResult += string.nSize;
            sString = sString.mid(string.nSize, -1);
        }

        pParameter->listDnames.append(dname);

        if (bNested && _compare(sString, "E")) {
            nResult++;
            sString = sString.mid(1, -1);

            break;
        } else if ((!bNested) && (!bSpecial)) {
            break;
        }

        if (!pSymbol->bIsValid) {
            break;
        }

        if (listAddString.count() && (bAdd)) {
            addStringListRef(pSymbol, pHdata, listAddString);
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_Function(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString, bool bReturn)
{
    qint32 nResult = 0;

    if (bReturn) {
        DPARAMETER parameter = {};

        qint32 nRSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, sString);

        pParameter->listReturn.append(parameter);

        nResult += nRSize;
        sString = sString.mid(nRSize, -1);
    }

    qint32 nFSize = itanium_demangle_Parameters(pSymbol, pHdata, pParameter, sString);

    nResult += nFSize;
    sString = sString.mid(nFSize, -1);

    return nResult;
}

qint32 XDemangle::itanium_demangle_Parameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    while (sString != "") {
        DPARAMETER parameter = {};

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, sString);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);

        pParameter->listParameters.append(parameter);

        //        if(parameter.bTemplatePresent&&(pSymbol->listListTemplates.count()))
        //        {
        //            pSymbol->listListTemplates.removeLast();
        //        }

        if (nPSize == 0) {
            pSymbol->bIsValid = false;
        }

        if (!pSymbol->bIsValid) {
            break;
        }

        if (_compare(sString, "E")) {
            nResult++;
            sString = sString.mid(1, -1);

            break;
        }

        if (_compare(sString, "@") && (pSymbol->mode == MODE_GCC_WIN)) {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_Type(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    bool bAdd = true;

    if (isReplaceArgPresent(pSymbol, pHdata, sString)) {
        SIGNATURE signature = getReplaceArgSignature(pSymbol, pHdata, sString);

        DNAME dname = {};
        dname.sName = signature.sString;

        pParameter->listDnames.append(dname);

        pParameter->st = ST_NAME;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);
    } else if (isSignaturePresent(sString, &(pHdata->mapPointerTypes)))  // Pointers
    {
        qint32 nPSize = itanium_demangle_PointerType(pSymbol, pHdata, pParameter, sString);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);
    } else if (_compare(sString, "U")) {
        nResult += 1;
        sString = sString.mid(1, -1);

        pParameter->st = ST_TARGET;

        qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, sString);

        nResult += nNSSize;
        sString = sString.mid(nNSSize, -1);

        DPARAMETER parameter = {};

        qint32 nTSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, sString);

        pParameter->listTarget.append(parameter);

        nResult += nTSize;
        sString = sString.mid(nTSize, -1);
    } else if (_compare(sString, "A"))  // Array
    {
        nResult += 1;
        sString = sString.mid(1, -1);

        NUMBER number = readNumber(pHdata, sString, pSymbol->mode);
        pParameter->listIndexes.append(number.nValue);

        nResult += number.nSize;
        sString = sString.mid(number.nSize, -1);

        pParameter->st = ST_POINTER;

        if (_compare(sString, "_")) {
            nResult += 1;
            sString = sString.mid(1, -1);
        } else {
            pSymbol->bIsValid = false;
        }

        DPARAMETER parameter = {};

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, sString);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);

        pParameter->listPointer.append(parameter);
    } else if (_compare(sString, "F"))  // Function
    {
        nResult += 1;
        sString = sString.mid(1, -1);

        pParameter->st = ST_FUNCTION;

        qint32 nFSize = itanium_demangle_Function(pSymbol, pHdata, pParameter, sString, true);

        nResult += nFSize;
        sString = sString.mid(nFSize, -1);
    } else if (_compare(sString, "M"))  // Pointer to member
    {
        nResult += 1;
        sString = sString.mid(1, -1);

        pParameter->st = ST_POINTER;

        DPARAMETER parameterClass = {};

        qint32 nClassSize = itanium_demangle_Type(pSymbol, pHdata, &parameterClass, sString);

        nResult += nClassSize;
        sString = sString.mid(nClassSize, -1);

        DPARAMETER parameterMember = {};

        qint32 nMemberSize = itanium_demangle_Type(pSymbol, pHdata, &parameterMember, sString);

        nResult += nMemberSize;
        sString = sString.mid(nMemberSize, -1);

        parameterMember.listClass.append(parameterClass);
        pParameter->listPointer.append(parameterMember);
    } else if (_compare(sString, "L"))  // Const
    {
        pParameter->st = ST_CONST;
        nResult += 1;
        sString = sString.mid(1, -1);

        qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, sString);

        if (nNSSize) {
            nResult += nNSSize;
            sString = sString.mid(nNSSize, -1);

            NUMBER number = readNumberS(pHdata, sString, pSymbol->mode);

            pParameter->varConst = number.nValue;

            nResult += number.nSize;
            sString = sString.mid(number.nSize, -1);
        } else if (isSignaturePresent(sString, &(pHdata->mapTypes))) {
            SIGNATURE signature = getSignature(sString, &(pHdata->mapTypes));

            pParameter->typeConst = (XTYPE)signature.nValue;

            nResult += signature.nSize;
            sString = sString.mid(signature.nSize, -1);

            NUMBER number = readNumberS(pHdata, sString, pSymbol->mode);

            pParameter->varConst = number.nValue;

            nResult += number.nSize;
            sString = sString.mid(number.nSize, -1);

            pSymbol->bIsValid = true;
        } else {
#ifdef QT_DEBUG
            qDebug("TODO: unknown const %s", sString.toLatin1().data());
#endif
            pSymbol->bIsValid = false;
        }

        if (_compare(sString, "E")) {
            nResult += 1;
            sString = sString.mid(1, -1);
        }
    } else if (_compare(sString, "X")) {
        nResult += 1;
        sString = sString.mid(1, -1);

        qint32 nTSize = itanium_demangle_Type(pSymbol, pHdata, pParameter, sString);

        nResult += nTSize;
        sString = sString.mid(nTSize, -1);

        if (_compare(sString, "E")) {
            nResult += 1;
            sString = sString.mid(1, -1);
        }
    } else if (_compare(sString, "J")) {
        nResult += 1;
        sString = sString.mid(1, -1);

        //        pSymbol->bIsValid=true;

        DPARAMETER parameter = {};
        parameter.st = ST_TEMPLATE;
        qint32 nPSize = itanium_demangle_Parameters(pSymbol, pHdata, &parameter, sString);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);

        QString sTemplate = itanium_parameterToString(pSymbol, &parameter, "");

        //        pParameter->st=ST_NAME;

        //        DNAME dname;
        //        dname.sName+=sTemplate;
        //        pParameter->listDnames.append(dname);

        qint32 nNumberOfArgs = parameter.listParameters.count();

        QList<QString> listTemplates;

        for (qint32 i = 0; i < nNumberOfArgs; i++) {
            DPARAMETER _parameter = parameter.listParameters.at(i);
            QString sParameter = itanium_parameterToString(pSymbol, &_parameter, "");
            //                addArgRef(pSymbol,pHdata,sParameter);

            listTemplates.append(sParameter);
        }

        pHdata->listListTemplates.append(listTemplates);

        pParameter->bTemplatePresent = true;

        if (_compare(sString, "E")) {
            nResult += 1;
            sString = sString.mid(1, -1);
        }
    } else if (_compare(sString, "Dp")) {
        nResult += 2;
        sString = sString.mid(2, -1);

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, pParameter, sString);
        pParameter->st = ST_PACKEDTYPE;

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);
    } else if (isSignaturePresent(sString, &(pHdata->mapTypes)))  // Simple types
    {
        pParameter->st = ST_TYPE;
        SIGNATURE signatureType = getSignature(sString, &(pHdata->mapTypes));
        pParameter->type = (XTYPE)signatureType.nValue;

        nResult += signatureType.nSize;
        sString = sString.mid(signatureType.nSize, -1);
    } else if (_compare(sString, "@")) {
        if (pSymbol->mode != MODE_GCC_WIN) {
            pSymbol->bIsValid = false;
        }
    } else {
        pParameter->st = ST_NAME;

        if (isReplaceStringPresent(pSymbol, pHdata, sString)) {
            bAdd = false;
        }

        qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, sString);

        if (pHdata->mapStd.contains(sString.left(2)) && (nNSSize == 2)) {
            bAdd = false;
        }

        nResult += nNSSize;
        sString = sString.mid(nNSSize, -1);

        if (nNSSize == 0) {
#ifdef QT_DEBUG
            qDebug("TODO: type %s", sString.toLatin1().data());
#endif
            pSymbol->bIsValid = false;
        }
    }

    //    QString _sParam=itanium_parameterToString(pSymbol,pParameter,"");

    if ((pParameter->st != ST_TYPE) && (pParameter->st != ST_CONST) && bAdd) {
        QString sParam = itanium_parameterToString(pSymbol, pParameter, "");

        QList<QString> listArgs;

        if (sParam.contains("::"))  // TODO Check // TODO if not std::
        {
            listArgs.append(sParam.split("::"));
        } else {
            listArgs.append(sParam);
        }

        addStringListRef(pSymbol, pHdata, listArgs);
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_PointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, QString sString)
{
    qint32 nResult = 0;

    if (isSignaturePresent(sString, &(pHdata->mapPointerTypes))) {
        pParameter->st = ST_POINTER;
        SIGNATURE signature = getSignature(sString, &(pHdata->mapPointerTypes));
        pParameter->nQualifier = signature.nValue;

        nResult += signature.nSize;
        sString = sString.mid(signature.nSize, -1);

        DPARAMETER parameter = {};

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, sString);

        nResult += nPSize;
        sString = sString.mid(nPSize, -1);

        pParameter->listPointer.append(parameter);
    }

    return nResult;
}

QString XDemangle::itanium_getPointerString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter)
{
    QString sResult;

    DPARAMETER parameter = *pParameter;

    QString sPrefix;
    QString sIndexes;
    QString sMain;

    qint32 nIndex = 0;

    while (parameter.st == ST_POINTER) {
        QString sPointer = qualIdToPointerString(parameter.nQualifier, pSymbol->mode);

        if (nIndex == 0) {
            sMain = sPointer;
        } else {
            if ((sPrefix != "") && (sPrefix.at(0) != QChar('*')) && (sPrefix.at(0) != QChar('&'))) {
                sPointer += " ";
            }

            sPrefix = sPrefix.prepend(sPointer);
        }

        if (parameter.listIndexes.count()) {
            sIndexes = sIndexes.append(QString("[%1]").arg(parameter.listIndexes.at(0)));
        }

        if (parameter.listPointer.count()) {
            parameter = parameter.listPointer.at(0);
        } else {
            break;
        }

        nIndex++;
    }

    sResult = sPrefix;

    if (sIndexes != "") {
        if (sResult != "") {
            sResult += " ";
        }

        sMain = QString("(%1)").arg(sMain);
        sResult += sMain;
        sResult += " ";

        sResult += sIndexes;
    } else {
        sResult += sMain;
    }

    return sResult;
}

QString XDemangle::join(QList<QString> *pListStrings, const QString &sJoin)
{
    QString sResult;

    qint32 nCount = pListStrings->count();

    for (qint32 i = 0; i < nCount; i++) {
        sResult += pListStrings->at(i);

        if (i != (nCount - 1)) {
            sResult += sJoin;
        }
    }

    return sResult;
}

qint32 XDemangle::borland_demangle_Encoding(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;

    qint32 nResult = 0;

    pParameter->st = ST_VARIABLE;

    qint32 nNSSize = borland_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

    _sString = _sString.mid(nNSSize, -1);
    nResult += nNSSize;

    if (_compare(_sString, "$")) {
        _sString = _sString.mid(1, -1);
        nResult += 1;
    }

    if (_compare(_sString, "q")) {
        _sString = _sString.mid(1, -1);
        nResult += 1;

        pParameter->st = ST_FUNCTION;
        pParameter->functionConvention = FC_NONE;

        if (isSignaturePresent(_sString, &(pHdata->mapFunctionConventions))) {
            SIGNATURE signatureType = getSignature(_sString, &(pHdata->mapFunctionConventions));
            pParameter->functionConvention = (FC)signatureType.nValue;

            nResult += signatureType.nSize;
            _sString = _sString.mid(signatureType.nSize, -1);
        }

        while (_sString != "") {
            DPARAMETER parameter = {};

            qint32 nPSize = borland_demangle_Type(pSymbol, pHdata, &parameter, _sString);

            pParameter->listParameters.append(parameter);

            _sString = _sString.mid(nPSize, -1);
            nResult += nPSize;

            if (!(pSymbol->bIsValid)) {
                break;
            }
        }
    }

    return nResult;
}

qint32 XDemangle::borland_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;

    qint32 nResult = 0;

    while (_sString != "") {
        DNAME dname = {};

        if (_compare(_sString, "@$b"))  // Operands
        {
            nResult += 3;
            _sString = _sString.mid(3, -1);

            if (isSignaturePresent(_sString, &(pHdata->mapOperators))) {
                SIGNATURE signature = getSignature(_sString, &(pHdata->mapOperators));

                dname._operator = (OP)signature.nValue;

                nResult += signature.nSize;
                _sString = _sString.mid(signature.nSize, -1);
            } else {
#ifdef QT_DEBUG
                qDebug("%s", "TODO: Invalid operand");
#endif

                pSymbol->bIsValid = false;
            }
        } else {
            STRING string = readString(pHdata, _sString, pSymbol->mode);

            if (string.nSize == 0) {
                break;
            }

            dname.sName = string.sString;

            _sString = _sString.mid(string.nSize, -1);
            nResult += string.nSize;
        }

        pParameter->listDnames.append(dname);
    }

    return nResult;
}

qint32 XDemangle::borland_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;

    qint32 nResult = 0;

    if (isSignaturePresent(_sString, &(pHdata->mapPointerTypes)))  // Pointers
    {
        qint32 nPSize = borland_demangle_PointerType(pSymbol, pHdata, pParameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    } else if (isSignaturePresent(_sString, &(pHdata->mapTypes)))  // Simple types
    {
        pParameter->st = ST_TYPE;
        SIGNATURE signatureType = getSignature(_sString, &(pHdata->mapTypes));
        pParameter->type = (XTYPE)signatureType.nValue;

        nResult += signatureType.nSize;
        _sString = _sString.mid(signatureType.nSize, -1);
    } else {
#ifdef QT_DEBUG
        qDebug("%s", "TODO: TYPE");
#endif
        pSymbol->bIsValid = false;
    }

    return nResult;
}

qint32 XDemangle::borland_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;

    qint32 nResult = 0;

    if (isSignaturePresent(_sString, &(pHdata->mapPointerTypes))) {
        pParameter->st = ST_POINTER;
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapPointerTypes));
        pParameter->nQualifier = signature.nValue;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);

        DPARAMETER parameter = {};

        qint32 nPSize = borland_demangle_Type(pSymbol, pHdata, &parameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);

        pParameter->listPointer.append(parameter);
    }

    return nResult;
}

QString XDemangle::borland_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter)
{
    QString sResult;

    QString sName = _nameToString(pSymbol, pParameter);

    if (pParameter->st == ST_TYPE) {
        QString sType = typeIdToString(pParameter->type, pSymbol->mode);

        sResult = sType;
    } else if (pParameter->st == ST_POINTER) {
        DPARAMETER lastParameter = getLastPointerParameter(pParameter);

        QString sPointer = borland_getPointerString(pSymbol, pParameter);

        // TODO volatile const!

        sResult += sPointer;

        if (!isPointerEnd(sResult)) {
            sResult += QString(" ");
        }

        sResult += borland_parameterToString(pSymbol, &lastParameter);  // TODO
    } else if (pParameter->st == ST_FUNCTION) {
        if (pParameter->functionConvention != FC_NONE) {
            sResult += QString("%1 ").arg(functionConventionIdToString(pParameter->functionConvention, pSymbol->mode));
        }

        sResult += sName;

        qint32 nNumberOfParameters = pParameter->listParameters.count();

        if (nNumberOfParameters) {
            sResult += "(";

            for (qint32 i = 0; i < nNumberOfParameters; i++) {
                DPARAMETER parameter = pParameter->listParameters.at(i);

                if ((parameter.st == ST_TYPE) && (parameter.type == XTYPE_VOID)) {
                    break;
                }

                sResult += borland_parameterToString(pSymbol, &parameter);

                if (i != (nNumberOfParameters - 1)) {
                    sResult += ", ";
                }
            }

            sResult += ")";
        }
    }

    return sResult;
}

QString XDemangle::borland_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter)
{
    QString sResult;

    DPARAMETER parameter = *pParameter;

    QString sPrefix;

    while (parameter.st == ST_POINTER) {
        QString sPointer = qualIdToPointerString(parameter.nQualifier, pSymbol->mode);

        sResult = sPrefix.prepend(sPointer);

        if (parameter.listPointer.count()) {
            parameter = parameter.listPointer.at(0);
        } else {
            break;
        }
    }

    return sResult;
}

QString XDemangle::demangle(const QString &sString, XDemangle::MODE mode)
{
    QString sResult;

    QString _sString = sString;

    if (mode == MODE_GNU_V3) {
        sResult = XCppfilt::demangleGnuV3(_sString);
    } else if (mode == MODE_GCC_WIN) {
        QString sPrefix;
        if (_compare(_sString, "@_Z")) {
            _sString = _sString.mid(1, -1);
            sPrefix = "fastcall";
        }

        if (_sString.section("@", -1, -1).toInt()) {
            _sString = _sString.section("@", 0, -2);
        }

        sResult = XCppfilt::demangleGnuV3(_sString);

        if (sPrefix != "") {
            sResult = QString("%1 %2").arg(sPrefix, sResult);
        }
    } else if (mode == MODE_GCC_MAC) {
        if (_compare(_sString, "__Z")) {
            _sString = _sString.mid(1, -1);
        }

        sResult = XCppfilt::demangleGnuV3(_sString);
    } else if (mode == MODE_JAVA) {
        sResult = XCppfilt::demangleJavaV3(_sString);
    } else if (mode == MODE_RUST) {
        sResult = XCppfilt::demangleRust(_sString);
    } else if (mode == MODE_BORLAND32) {
        DSYMBOL symbol = borland_getSymbol(_sString, mode);

        sResult = dsymbolToString(symbol);
    } else if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        DSYMBOL symbol = ms_getSymbol(_sString, mode);

        sResult = dsymbolToString(symbol);
    }

    if (sResult == "") {
        sResult = _sString;
    }

    return sResult;
}

XDemangle::DSYMBOL XDemangle::_getSymbol(const QString &sString, XDemangle::MODE mode)
{
    DSYMBOL result = {};

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        result = ms_getSymbol(sString, mode);
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        result = itanium_getSymbol(sString, mode);
    }

    return result;
}

XDemangle::DSYMBOL XDemangle::ms_getSymbol(const QString &sString, XDemangle::MODE mode, HDATA *pHdata)
{
    DSYMBOL result = {};
    QString _sString = sString;

    result.bIsValid = true;
    result.mode = mode;

    HDATA hdata = {};

    if (pHdata) {
        hdata = *pHdata;
    } else {
        hdata = getHdata(mode);
    }

    if (_compare(_sString, ".")) {
        result.nSize += 1;
        _sString = _sString.mid(1, -1);

        DPARAMETER parameter = {};

        qint32 nTSize = ms_demangle_Type(&result, &hdata, &parameter, _sString, MSDT_RESULT);

        result.paramMain.listTarget.append(parameter);

        _sString = _sString.mid(nTSize, -1);
        result.nSize += nTSize;

        result.paramMain.st = ST_TYPEINFO;
    } else if (_compare(_sString, "??@")) {
        // TODO MD5
#ifdef QT_DEBUG
        qDebug("TODO: MD5");
#endif
    } else if (_compare(_sString, "?")) {
        result.nSize += 1;
        _sString = _sString.mid(1, -1);

        // TODO demangleSpecialIntrinsic

        if (isSignaturePresent(_sString, &(hdata.mapSpecInstr))) {
            SIGNATURE signature = getSignature(_sString, &(hdata.mapSpecInstr));
            result.paramMain.st = (ST)signature.nValue;

            _sString = _sString.mid(signature.nSize, -1);
            result.nSize += signature.nSize;

            if ((result.paramMain.st == ST_VBTABLE) || (result.paramMain.st == ST_VFTABLE) || (result.paramMain.st == ST_LOCALVFTABLE) ||
                (result.paramMain.st == ST_RTTICOMPLETEOBJLOCATOR)) {
                qint32 nSTSize = ms_demangle_SpecialTable(&result, &hdata, &(result.paramMain), _sString);

                _sString = _sString.mid(nSTSize, -1);
                result.nSize += nSTSize;
            } else if ((result.paramMain.st == ST_LOCALSTATICGUARD) || (result.paramMain.st == ST_LOCALSTATICTHREADGUARD)) {
                qint32 nSTSize = ms_demangle_LocalStaticGuard(&result, &hdata, &(result.paramMain), _sString);

                _sString = _sString.mid(nSTSize, -1);
                result.nSize += nSTSize;
            } else if ((result.paramMain.st == ST_RTTIBASECLASSARRAY) || (result.paramMain.st == ST_RTTICLASSHIERARCHYDESCRIPTOR)) {
                qint32 nSTSize = ms_demangle_UntypedVariable(&result, &hdata, &(result.paramMain), _sString);

                _sString = _sString.mid(nSTSize, -1);
                result.nSize += nSTSize;
            } else if (result.paramMain.st == ST_STRINGLITERALSYMBOL) {
                qint32 nSTSize = ms_demangle_StringLiteralSymbol(&result, &hdata, &(result.paramMain), _sString);

                _sString = _sString.mid(nSTSize, -1);
                result.nSize += nSTSize;
            }
        } else {
            qint32 nDSize = ms_demangle_Declarator(&result, &hdata, &(result.paramMain), _sString);

            _sString = _sString.mid(nDSize, -1);
            result.nSize += nDSize;
        }
    }

    if (pHdata) {
        *pHdata = hdata;
    }

    return result;
}

XDemangle::DSYMBOL XDemangle::itanium_getSymbol(const QString &sString, XDemangle::MODE mode)
{
    DSYMBOL result = {};

    QString _sString = sString;

    if (_compare(_sString, "_Z") || (_compare(_sString, "@_Z") && (mode == MODE_GCC_WIN)) ||
        (_compare(_sString, "__Z") && ((mode == MODE_GNU_V3) || (mode == MODE_GCC_MAC)))) {
        HDATA hdata = getHdata(mode);

        result.bIsValid = true;
        result.mode = mode;

        if (_compare(_sString, "@_Z"))  // Fastcall
        {
            result.paramMain.st = ST_FUNCTION;  // TODO Check !!!
            result.paramMain.functionConvention = FC_FASTCALL;
            _sString = _sString.mid(3, -1);
            result.nSize += 3;
        } else if (_compare(_sString, "_Z")) {
            _sString = _sString.mid(2, -1);
            result.nSize += 2;
        } else if (_compare(_sString, "__Z")) {
            _sString = _sString.mid(3, -1);
            result.nSize += 3;
        }

        if (isSignaturePresent(_sString, &(hdata.mapSpecInstr))) {
            SIGNATURE signature = getSignature(_sString, &(hdata.mapSpecInstr));

            result.paramMain.st = (ST)signature.nValue;
            _sString = _sString.mid(signature.nSize, -1);
            result.nSize += signature.nSize;

            DPARAMETER parameter = {};

            if ((result.paramMain.st == ST_TYPEINFO) || (result.paramMain.st == ST_TYPEINFONAME) || (result.paramMain.st == ST_VTABLE) ||
                (result.paramMain.st == ST_GUARDVARIABLE) || (result.paramMain.st == ST_TRANSACTIONCLONE) || (result.paramMain.st == ST_VTT) ||
                (result.paramMain.st == ST_CONSTRUCTIONVTABLE)) {
                qint32 nNSSize = itanium_demangle_Type(&result, &hdata, &parameter, _sString);

                _sString = _sString.mid(nNSSize, -1);
                result.nSize += nNSSize;
            } else if (result.paramMain.st == ST_NONVIRTUALTHUNK) {
                NUMBER number = readNumberS(&hdata, _sString, result.mode);

                _sString = _sString.mid(number.nSize, -1);
                result.nSize += number.nSize;

                if (_compare(_sString, "_")) {
                    _sString = _sString.mid(1, -1);
                    result.nSize += 1;
                }

                qint32 nESize = itanium_demangle_Encoding(&result, &hdata, &parameter, _sString);
                _sString = _sString.mid(nESize, -1);
                result.nSize += nESize;
            } else if (result.paramMain.st == ST_VIRTUALTHUNK) {
                NUMBER number1 = readNumberS(&hdata, _sString, result.mode);

                _sString = _sString.mid(number1.nSize, -1);
                result.nSize += number1.nSize;

                if (_compare(_sString, "_n")) {
                    _sString = _sString.mid(2, -1);
                    result.nSize += 2;
                }

                NUMBER number2 = readNumberS(&hdata, _sString, result.mode);

                _sString = _sString.mid(number2.nSize, -1);
                result.nSize += number2.nSize;

                if (_compare(_sString, "_")) {
                    _sString = _sString.mid(1, -1);
                    result.nSize += 1;
                }

                qint32 nESize = itanium_demangle_Encoding(&result, &hdata, &parameter, _sString);
                _sString = _sString.mid(nESize, -1);
                result.nSize += nESize;
            }

            result.paramMain.listTarget.append(parameter);
        } else {
            qint32 nESize = itanium_demangle_Encoding(&result, &hdata, &(result.paramMain), _sString);

            _sString = _sString.mid(nESize, -1);
            result.nSize += nESize;
        }

        //    #ifdef QT_DEBUG
        //        for(qint32 i=0;i<hdata.listListStringRef.count();i++)
        //        {
        //            qDebug("%d: %s",i,hdata.listListStringRef.at(i).join("<>").toLatin1().data());
        //        }

        //        for(qint32 i=0;i<hdata.listArgRef.count();i++)
        //        {
        //            qDebug("%d: %s",i,hdata.listArgRef.at(i).toLatin1().data());
        //        }

        //        for(qint32 i=0;i<hdata.listListTemplates.count();i++)
        //        {
        //            for(qint32 j=0;j<hdata.listListTemplates.at(i).count();j++)
        //            {
        //                qDebug("%d %d: %s",i,j,hdata.listListTemplates.at(i).at(j).toLatin1().data());
        //            }
        //        }
        //    #endif
    }

    return result;
}

XDemangle::DSYMBOL XDemangle::borland_getSymbol(const QString &sString, MODE mode)
{
    DSYMBOL result = {};

    if (_compare(sString, "@")) {
        HDATA hdata = getHdata(mode);

        result.bIsValid = true;
        result.mode = mode;

        result.nSize += borland_demangle_Encoding(&result, &hdata, &(result.paramMain), sString);
    }

    return result;
}

XDemangle::MODE XDemangle::detectMode(const QString &sString)
{
    MODE result = MODE_GNU_V3;

    if (_compare(sString, "?") && (sString.contains("@"))) {
        result = MODE_MSVC;
    } else if (_compare(sString, "@_Z") || (_compare(sString, "_Z") && (sString.section("@", -1, -1).toUInt()))) {
        result = MODE_GCC_WIN;
    } else if (_compare(sString, "_Z")) {
        result = MODE_GNU_V3;
    } else if (_compare(sString, "__Z")) {
        result = MODE_GCC_MAC;
    }

    return result;
}

QList<XDemangle::MODE> XDemangle::getAllModes()
{
    QList<MODE> listResult;

    listResult.append(MODE_AUTO);
    listResult.append(MODE_MSVC32);
    listResult.append(MODE_GNU_V3);
    listResult.append(MODE_GCC_MAC);
    listResult.append(MODE_GCC_WIN);
    listResult.append(MODE_BORLAND32);
    listResult.append(MODE_WATCOM);

    return listResult;
}

QList<XDemangle::MODE> XDemangle::getSupportedModes()
{
    QList<MODE> listResult;

    listResult.append(MODE_AUTO);
    listResult.append(MODE_GNU_V3);
    listResult.append(MODE_GCC_MAC);
    listResult.append(MODE_GCC_WIN);
    listResult.append(MODE_MSVC);
    listResult.append(MODE_MSVC32);
    listResult.append(MODE_MSVC64);
    listResult.append(MODE_JAVA);
    listResult.append(MODE_RUST);

    return listResult;
}

void XDemangle::reverseList(QList<QString> *pList)
{
    qint32 nNumberOfRecords = pList->count();

    for (qint32 i = 0; i < (nNumberOfRecords / 2); i++) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 13, 0)
        pList->swapItemsAt(i, nNumberOfRecords - (1 + i));
#else
        pList->swap(i, nNumberOfRecords - (1 + i));
#endif
    }
}

void XDemangle::reverseList(QList<XDemangle::DNAME> *pList)
{
    qint32 nNumberOfRecords = pList->count();

    for (qint32 i = 0; i < (nNumberOfRecords / 2); i++) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 13, 0)
        pList->swapItemsAt(i, nNumberOfRecords - (1 + i));
#else
        pList->swap(i, nNumberOfRecords - (1 + i));
#endif
    }
}

XDemangle::HDATA XDemangle::getHdata(XDemangle::MODE mode)
{
    XDemangle::HDATA result = {};

    result.mapPointerTypes = getPointerTypes(mode);
    result.mapObjectClasses = getObjectClasses(mode);
    result.mapTypes = getTypes(mode);
    result.mapTagTypes = getTagTypes(mode);
    result.mapStorageClasses = getStorageClasses(mode);
    result.mapAccessMods = getAccessMods(mode);
    result.mapFunctionConventions = getFunctionConventions(mode);
    result.mapOperators = getOperators(mode);
    result.mapNumbers = getNumbers(mode);
    result.mapSymNumbers = getSymNumbers(mode);
    result.mapQualifiers = getQualifiers(mode);
    result.mapSpecInstr = getSpecInstr(mode);
    result.mapStd = getStd(mode);

    return result;
}

QString XDemangle::dsymbolToString(XDemangle::DSYMBOL symbol)
{
    QString sResult;

    if (symbol.bIsValid) {
        if (getSyntaxFromMode(symbol.mode) == SYNTAX_MICROSOFT) {
            QString sName = _nameToString(&symbol, &(symbol.paramMain));
            sResult = ms_parameterToString(&symbol, &(symbol.paramMain), sName, "");
        } else if (getSyntaxFromMode(symbol.mode) == SYNTAX_ITANIUM) {
            sResult = itanium_parameterToString(&symbol, &(symbol.paramMain), "");
        } else if (getSyntaxFromMode(symbol.mode) == SYNTAX_BORLAND) {
            sResult = borland_parameterToString(&symbol, &(symbol.paramMain));
        }
    }

    return sResult;
}

XDemangle::STRING XDemangle::readString(HDATA *pHdata, const QString &sString, XDemangle::MODE mode)
{
    QString _sString = sString;

    STRING result = {};

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        result.sString = _sString.section("@", 0, 0);
        result.sOriginal = result.sString;

        if (_sString.contains("@")) {
            result.sOriginal += "@";
        }

        result.nSize = result.sString.size();

        if (result.nSize) {
            if (result.sString != _sString) {
                result.nSize++;
            }
        }
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        NUMBER number = readNumber(pHdata, _sString, mode);

        if (number.nSize) {
            result.sOriginal += _sString.left(number.nSize);
            _sString = _sString.mid(number.nSize, -1);
            result.sString = _sString.left(number.nValue);
            result.nSize = number.nSize + result.sString.size();
            result.sOriginal += result.sString;
        }
    } else if (getSyntaxFromMode(mode) == SYNTAX_BORLAND) {
        if (_compare(_sString, "@")) {
            result.sOriginal += _sString.at(0);
            _sString = _sString.mid(1, -1);
            result.nSize++;

            while ((_sString != "") && (!_compare(_sString, "@")) && (!_compare(_sString, "$"))) {
                result.sOriginal += _sString.at(0);
                result.sString += _sString.at(0);
                result.nSize++;
                _sString = _sString.mid(1, -1);
            }
        }
    }

    return result;
}

XDemangle::NUMBER XDemangle::readNumber(HDATA *pHdata, const QString &sString, XDemangle::MODE mode)
{
    QString _sString = sString;

    NUMBER result = {};

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        bool bNeg = false;

        if (_compare(_sString, "?")) {
            _sString = _sString.mid(1, -1);
            bNeg = true;
        }

        if (isSignaturePresent(_sString, &(pHdata->mapNumbers))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapNumbers));

            if (signature.nSize) {
                result.nValue = signature.nValue + 1;
                result.nSize = 1;
            }
        } else if (isSignaturePresent(_sString, &(pHdata->mapSymNumbers))) {
            while ((_sString != "") && (!_compare(_sString, "@"))) {
                result.nValue *= 16;

                SIGNATURE signature = getSignature(_sString, &(pHdata->mapSymNumbers));

                if (signature.nSize) {
                    _sString = _sString.mid(signature.nSize, -1);
                    result.nSize += signature.nSize;

                    result.nValue += signature.nValue;
                } else {
                    break;
                }
            }

            if (_compare(_sString, "@Z"))  // End of function
            {
                result.nSize = 0;
            } else if (_compare(_sString, "@")) {
                _sString = _sString.mid(1, -1);
                result.nSize++;
            } else {
                result.nSize = 0;
            }
        }

        if ((bNeg) && (result.nSize)) {
            result.nSize++;
            result.nValue = -(result.nValue);
        }
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        while ((_sString != "") && (isSignaturePresent(_sString, &(pHdata->mapNumbers)))) {
            result.nValue *= 10;

            SIGNATURE signature = getSignature(_sString, &(pHdata->mapNumbers));

            result.nValue += signature.nValue;

            result.nSize++;

            _sString = _sString.mid(signature.nSize, -1);
        }
    }

    return result;
}

XDemangle::NUMBER XDemangle::readNumberS(XDemangle::HDATA *pHdata, const QString &sString, XDemangle::MODE mode)
{
    QString _sString = sString;
    NUMBER result = {};

    bool bNeg = false;

    if (_compare(_sString, "n")) {
        result.nSize += 1;
        _sString = _sString.mid(1, -1);

        bNeg = true;
    }

    NUMBER number = readNumber(pHdata, _sString, mode);

    qint64 nValue = number.nValue;

    if (bNeg) {
        nValue = -nValue;
    }

    result.nSize += number.nSize;
    result.nValue = nValue;

    return result;
}

XDemangle::NUMBER XDemangle::readSymNumber(XDemangle::HDATA *pHdata, const QString &sString, XDemangle::MODE mode)
{
    QString _sString = sString;
    NUMBER result = {};

    if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        while ((_sString != "") && (isSignaturePresent(_sString, &(pHdata->mapSymNumbers)))) {
            result.nValue *= 36;

            SIGNATURE signature = getSignature(_sString, &(pHdata->mapSymNumbers));

            result.nValue += signature.nValue;

            result.nSize++;

            _sString = _sString.mid(signature.nSize, -1);
        }
    }

    return result;
}

bool XDemangle::_compare(const QString &sString, const QString &sSignature)
{
    bool bResult = false;

    qint32 nSignatureSize = sSignature.size();

    if (sString.size() >= nSignatureSize) {
        QString _sString = sString.left(nSignatureSize);

        bResult = (_sString == sSignature);
    }

    return bResult;
}

QChar XDemangle::_getStringEnd(const QString &sString)
{
    QChar cResult = QChar(' ');

    if (sString != "") {
        cResult = sString.at(sString.size() - 1);
    }

    return cResult;
}

QString XDemangle::_removeLastSymbol(const QString &sString)
{
    QString _sString = sString;

    if (_sString != "") {
        _sString.resize(_sString.size() - 1);
    }

    return _sString;
}

bool XDemangle::isPointerEnd(const QString &sString)
{
    bool bResult = false;

    bResult = (_getStringEnd(sString) == QChar('*')) || (_getStringEnd(sString) == QChar('&')) || (_getStringEnd(sString) == QChar('_'));

    return bResult;
}

bool XDemangle::isSignaturePresent(const QString &sString, QMap<QString, quint32> *pMap)
{
    bool bResult = false;

    QMapIterator<QString, quint32> i(*pMap);

    while (i.hasNext()) {
        i.next();

        if (_compare(sString, i.key())) {
            bResult = true;

            break;
        }
    }

    return bResult;
}

XDemangle::SIGNATURE XDemangle::getSignature(const QString &sString, QMap<QString, quint32> *pMap)
{
    SIGNATURE result = {};

    QMapIterator<QString, quint32> i(*pMap);

    while (i.hasNext()) {
        i.next();

        QString sKey = i.key();
        qint32 nValue = i.value();

        if (_compare(sString, sKey)) {
            result.nSize = sKey.size();
            result.nValue = nValue;
            result.sString = sKey;

            break;
        }
    }

    return result;
}

QMap<QString, quint32> XDemangle::getObjectClasses(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("0", OC_PRIVATESTATICCLASSMEMBER);
        mapResult.insert("1", OC_PROTECTEDSTATICCLASSMEMBER);
        mapResult.insert("2", OC_PUBLICSTATICCLASSMEMBER);
        mapResult.insert("3", OC_GLOBALOBJECT);
        mapResult.insert("4", OC_FUNCTIONLOCALSTATIC);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getTypes(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("@", XTYPE_NONE);
        mapResult.insert("X", XTYPE_VOID);
        mapResult.insert("C", XTYPE_SCHAR);
        mapResult.insert("D", XTYPE_CHAR);
        mapResult.insert("E", XTYPE_UCHAR);
        mapResult.insert("F", XTYPE_SHORT);
        mapResult.insert("G", XTYPE_USHORT);
        mapResult.insert("H", XTYPE_INT);
        mapResult.insert("I", XTYPE_UINT);
        mapResult.insert("J", XTYPE_LONG);
        mapResult.insert("K", XTYPE_ULONG);
        mapResult.insert("M", XTYPE_FLOAT);
        mapResult.insert("N", XTYPE_DOUBLE);
        mapResult.insert("O", XTYPE_LONGDOUBLE_64);
        mapResult.insert("Z", XTYPE_VARARGS);
        mapResult.insert("_J", XTYPE_INT64);
        mapResult.insert("_K", XTYPE_UINT64);
        mapResult.insert("_N", XTYPE_BOOL);
        mapResult.insert("_Q", XTYPE_CHAR8);
        mapResult.insert("_S", XTYPE_CHAR16);
        mapResult.insert("_U", XTYPE_CHAR32);
        mapResult.insert("_W", XTYPE_WCHAR);
        mapResult.insert("$$T", XTYPE_NULLPTR);
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        mapResult.insert("v", XTYPE_VOID);
        mapResult.insert("a", XTYPE_SCHAR);
        mapResult.insert("c", XTYPE_CHAR);
        mapResult.insert("h", XTYPE_UCHAR);
        mapResult.insert("s", XTYPE_SHORT);
        mapResult.insert("t", XTYPE_USHORT);
        mapResult.insert("i", XTYPE_INT);
        mapResult.insert("j", XTYPE_UINT);
        mapResult.insert("l", XTYPE_LONG);
        mapResult.insert("m", XTYPE_ULONG);
        mapResult.insert("f", XTYPE_FLOAT);
        mapResult.insert("g", XTYPE_FLOAT128);
        mapResult.insert("d", XTYPE_DOUBLE);
        mapResult.insert("e", XTYPE_LONGDOUBLE_64);
        mapResult.insert("z", XTYPE_VARARGS);
        mapResult.insert("x", XTYPE_LONGLONG);
        mapResult.insert("y", XTYPE_ULONGLONG);
        mapResult.insert("b", XTYPE_BOOL);
        mapResult.insert("Du", XTYPE_CHAR8);
        mapResult.insert("Ds", XTYPE_CHAR16);
        mapResult.insert("Di", XTYPE_CHAR32);
        mapResult.insert("Df", XTYPE_DECIMAL32);
        mapResult.insert("Dd", XTYPE_DECIMAL64);
        mapResult.insert("De", XTYPE_DECIMAL128);
        mapResult.insert("w", XTYPE_WCHAR);
        mapResult.insert("Dn", XTYPE_NULLPTR);
    } else if (getSyntaxFromMode(mode) == SYNTAX_BORLAND) {
        mapResult.insert("v", XTYPE_VOID);
        mapResult.insert("c", XTYPE_CHAR);
        mapResult.insert("s", XTYPE_SHORT);
        mapResult.insert("i", XTYPE_INT);
        mapResult.insert("j", XTYPE_INT64);
        mapResult.insert("l", XTYPE_LONG);
        mapResult.insert("f", XTYPE_FLOAT);
        mapResult.insert("d", XTYPE_DOUBLE);
        mapResult.insert("g", XTYPE_LONGDOUBLE);
        mapResult.insert("e", XTYPE_VARARGS);  // TODO Check ve
        mapResult.insert("o", XTYPE_BOOL);
        mapResult.insert("b", XTYPE_WCHAR);
        mapResult.insert("Cs", XTYPE_CHAR16);
        mapResult.insert("Ci", XTYPE_CHAR32);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getTagTypes(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("T", XTYPE_UNION);
        mapResult.insert("U", XTYPE_STRUCT);
        mapResult.insert("V", XTYPE_CLASS);
        mapResult.insert("W4", XTYPE_ENUM);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getPointerTypes(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        //        mapResult.insert("?",PM_NONE); // For classes return
        mapResult.insert("P", QUAL_POINTER);
        mapResult.insert("A", QUAL_REFERENCE);
        mapResult.insert("Q", QUAL_POINTER | QUAL_CONST);
        mapResult.insert("R", QUAL_POINTER | QUAL_VOLATILE);
        mapResult.insert("S", QUAL_POINTER | QUAL_CONST | QUAL_VOLATILE);
        mapResult.insert("$$Q", QUAL_DOUBLEREFERENCE);
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        mapResult.insert("O", QUAL_DOUBLEREFERENCE);
        mapResult.insert("P", QUAL_POINTER);
        mapResult.insert("R", QUAL_REFERENCE);
        mapResult.insert("K", QUAL_CONST);
        mapResult.insert("V", QUAL_VOLATILE);
    } else if (getSyntaxFromMode(mode) == SYNTAX_BORLAND) {
        mapResult.insert("z", QUAL_SIGNED);
        mapResult.insert("u", QUAL_UNSIGNED);
        mapResult.insert("p", QUAL_POINTER);
        mapResult.insert("r", QUAL_REFERENCE);
        mapResult.insert("x", QUAL_CONST);
        mapResult.insert("w", QUAL_VOLATILE);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getStorageClasses(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("A", SC_NEAR);
        mapResult.insert("B", SC_CONST);
        mapResult.insert("C", SC_VOLATILE);
        mapResult.insert("D", SC_CONSTVOLATILE);
        mapResult.insert("E", SC_FAR);
        mapResult.insert("F", SC_CONSTFAR);
        mapResult.insert("G", SC_VOLATILEFAR);
        mapResult.insert("H", SC_CONSTVOLATILEFAR);
        mapResult.insert("I", SC_HUGE);
        //        mapResult.insert("F",SC_UNALIGNED);
        //        mapResult.insert("I",SC_RESTRICT);
        mapResult.insert("Z", SC_EXECUTABLE);
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        mapResult.insert("K", SC_CONST);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getAccessMods(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("0", FM_PRIVATE | FM_STATIC);        // Member
        mapResult.insert("1", FM_PROTECTED | FM_STATIC);      // Member
        mapResult.insert("2", FM_PUBLIC | FM_STATIC);         // Member
        mapResult.insert("3", FM_GLOBAL);                     // Variable
        mapResult.insert("4", FM_FUNCTIONLOCAL | FM_STATIC);  // Variable
        mapResult.insert("9", FM_EXTERNC | FM_NOPARAMETERLIST);
        mapResult.insert("A", FM_PRIVATE);
        mapResult.insert("B", FM_PRIVATE | FM_FAR);
        mapResult.insert("C", FM_PRIVATE | FM_STATIC);
        mapResult.insert("D", FM_PRIVATE | FM_STATIC | FM_FAR);
        mapResult.insert("E", FM_PRIVATE | FM_VIRTUAL);
        mapResult.insert("F", FM_PRIVATE | FM_VIRTUAL | FM_FAR);
        mapResult.insert("I", FM_PROTECTED);
        mapResult.insert("J", FM_PROTECTED | FM_FAR);
        mapResult.insert("K", FM_PROTECTED | FM_STATIC);
        mapResult.insert("L", FM_PROTECTED | FM_STATIC | FM_FAR);
        mapResult.insert("M", FM_PROTECTED | FM_VIRTUAL);
        mapResult.insert("N", FM_PROTECTED | FM_VIRTUAL | FM_FAR);
        mapResult.insert("Q", FM_PUBLIC);
        mapResult.insert("R", FM_PUBLIC | FM_FAR);
        mapResult.insert("S", FM_PUBLIC | FM_STATIC);
        mapResult.insert("T", FM_PUBLIC | FM_STATIC | FM_FAR);
        mapResult.insert("U", FM_PUBLIC | FM_VIRTUAL);
        mapResult.insert("V", FM_PUBLIC | FM_VIRTUAL | FM_FAR);
        mapResult.insert("W", FM_PUBLIC | FM_VIRTUAL | FM_STATICTHISADJUST);
        mapResult.insert("X", FM_PUBLIC | FM_VIRTUAL | FM_STATICTHISADJUST | FM_FAR);
        mapResult.insert("Y", FM_GLOBAL);
        mapResult.insert("Z", FM_GLOBAL | FM_FAR);
        mapResult.insert("$", FM_VIRTUALTHISADJUST);
        mapResult.insert("$R0", FM_VIRTUALTHISADJUST | FM_VIRTUALTHISADJUSTEX | FM_PRIVATE | FM_VIRTUAL);
        mapResult.insert("$R1", FM_VIRTUALTHISADJUST | FM_VIRTUALTHISADJUSTEX | FM_PRIVATE | FM_VIRTUAL | FM_FAR);
        mapResult.insert("$R2", FM_VIRTUALTHISADJUST | FM_VIRTUALTHISADJUSTEX | FM_PROTECTED | FM_VIRTUAL);
        mapResult.insert("$R3", FM_VIRTUALTHISADJUST | FM_VIRTUALTHISADJUSTEX | FM_PROTECTED | FM_VIRTUAL | FM_FAR);
        mapResult.insert("$R4", FM_VIRTUALTHISADJUST | FM_VIRTUALTHISADJUSTEX | FM_PUBLIC | FM_VIRTUAL | FM_FAR);
        mapResult.insert("$R5", FM_VIRTUALTHISADJUST | FM_VIRTUALTHISADJUSTEX | FM_PUBLIC | FM_VIRTUAL | FM_FAR);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getFunctionConventions(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        if ((mode == MODE_MSVC) || (mode == MODE_MSVC32)) {
            mapResult.insert("A", FC_CDECL);
            mapResult.insert("I", FC_FASTCALL);
        } else if (mode == MODE_MSVC64) {
            mapResult.insert("A", FC_FASTCALL);
        }

        mapResult.insert("B", FC_CDECL);
        mapResult.insert("C", FC_PASCAL);
        mapResult.insert("D", FC_PASCAL);
        mapResult.insert("E", FC_THISCALL);
        mapResult.insert("F", FC_THISCALL);
        mapResult.insert("G", FC_STDCALL);
        mapResult.insert("H", FC_STDCALL);
        mapResult.insert("J", FC_FASTCALL);
        mapResult.insert("M", FC_CLRCALL);
        mapResult.insert("N", FC_CLRCALL);
        mapResult.insert("O", FC_EABI);
        mapResult.insert("P", FC_EABI);
        mapResult.insert("Q", FC_VECTORCALL);
        mapResult.insert("S", FC_SWIFT);
    } else if (getSyntaxFromMode(mode) == SYNTAX_BORLAND) {
        mapResult.insert("qr", FC_FASTCALL);
        mapResult.insert("qs", FC_STDCALL);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getOperators(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("?0", OP_CONSTRUCTOR);
        mapResult.insert("?1", OP_DESTRUCTOR);
        mapResult.insert("?2", OP_NEW);
        mapResult.insert("?3", OP_DELETE);
        mapResult.insert("?4", OP_ASSIGN);
        mapResult.insert("?5", OP_RIGHTSHIFT);
        mapResult.insert("?6", OP_LEFTSHIFT);
        mapResult.insert("?7", OP_LOGICALNOT);
        mapResult.insert("?8", OP_EQUALS);
        mapResult.insert("?9", OP_NOTEQUALS);
        mapResult.insert("?A", OP_ARRAYSUBSCRIPT);
        mapResult.insert("?B", OP_TYPE);
        mapResult.insert("?C", OP_POINTER);
        mapResult.insert("?D", OP_DEREFERENCE);
        mapResult.insert("?E", OP_INCREMENT);
        mapResult.insert("?F", OP_DECREMENT);
        mapResult.insert("?G", OP_MINUS);
        mapResult.insert("?H", OP_PLUS);
        mapResult.insert("?I", OP_BITWISEAND);
        mapResult.insert("?J", OP_MEMBERPOINTER);
        mapResult.insert("?K", OP_DIVIDE);
        mapResult.insert("?L", OP_MODULUS);
        mapResult.insert("?M", OP_LESSTHAN);
        mapResult.insert("?N", OP_LESSTHANEQUAL);
        mapResult.insert("?O", OP_GREATERTHAN);
        mapResult.insert("?P", OP_GREATERTHANEQUAL);
        mapResult.insert("?Q", OP_COMMA);
        mapResult.insert("?R", OP_PARENS);
        mapResult.insert("?S", OP_BITWISENOT);
        mapResult.insert("?T", OP_BITWISEXOR);
        mapResult.insert("?U", OP_BITWISEOR);
        mapResult.insert("?V", OP_LOGICALAND);
        mapResult.insert("?W", OP_LOGICALOR);
        mapResult.insert("?X", OP_TIMESEQUAL);
        mapResult.insert("?Y", OP_PLUSEQUAL);
        mapResult.insert("?Z", OP_MINUSEQUAL);
        mapResult.insert("?_0", OP_DIVEQUAL);
        mapResult.insert("?_1", OP_MODEQUAL);
        mapResult.insert("?_2", OP_RSHEQUAL);
        mapResult.insert("?_3", OP_LSHEQUAL);
        mapResult.insert("?_4", OP_BITWISEANDEQUAL);
        mapResult.insert("?_5", OP_BITWISEOREQUAL);
        mapResult.insert("?_6", OP_BITWISEXOREQUAL);
        mapResult.insert("?_D", OP_VBASEDTOR);
        mapResult.insert("?_E", OP_VECDELDTOR);
        mapResult.insert("?_F", OP_DEFAULTCTORCLOSURE);
        mapResult.insert("?_G", OP_SCALARDELDTOR);
        mapResult.insert("?_H", OP_VECCTORITER);
        mapResult.insert("?_I", OP_VECDTORITER);
        mapResult.insert("?_J", OP_VECVBASECTORITER);
        mapResult.insert("?_K", OP_VDISPMAP);
        mapResult.insert("?_L", OP_EHVECCTORITER);
        mapResult.insert("?_M", OP_EHVECDTORITER);
        mapResult.insert("?_N", OP_EHVECVBASECTORITER);
        mapResult.insert("?_O", OP_COPYCTORCLOSURE);
        mapResult.insert("?_U", OP_ARRAYNEW);
        mapResult.insert("?_V", OP_ARRAYDELETE);
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        mapResult.insert("C1", OP_CONSTRUCTOR);
        mapResult.insert("C2", OP_CONSTRUCTOR);
        mapResult.insert("D0", OP_DESTRUCTOR);
        mapResult.insert("D1", OP_DESTRUCTOR);
        mapResult.insert("D2", OP_DESTRUCTOR);
        mapResult.insert("nw", OP_NEW);
        mapResult.insert("dl", OP_DELETE);
        mapResult.insert("aS", OP_ASSIGN);            // operator=
        mapResult.insert("rs", OP_RIGHTSHIFT);        // operator>>
        mapResult.insert("ls", OP_LEFTSHIFT);         // operator<<
        mapResult.insert("nt", OP_LOGICALNOT);        // operator!
        mapResult.insert("eq", OP_EQUALS);            // operator==
        mapResult.insert("ne", OP_NOTEQUALS);         // operator!=
        mapResult.insert("ix", OP_ARRAYSUBSCRIPT);    // operator[]
        mapResult.insert("pt", OP_POINTER);           // operator->
        mapResult.insert("de", OP_DEREFERENCE);       // operator*
        mapResult.insert("ad", OP_REFERENCE);         // operator&
        mapResult.insert("pp", OP_INCREMENT);         // operator++
        mapResult.insert("mm", OP_DECREMENT);         // operator--
        mapResult.insert("mi", OP_MINUS);             // operator-
        mapResult.insert("pl", OP_PLUS);              // operator+
        mapResult.insert("an", OP_BITWISEAND);        // operator&
        mapResult.insert("pm", OP_MEMBERPOINTER);     // operator->*
        mapResult.insert("ml", OP_MULTIPLE);          // operator*
        mapResult.insert("dv", OP_DIVIDE);            // operator/
        mapResult.insert("rm", OP_MODULUS);           // operator%
        mapResult.insert("lt", OP_LESSTHAN);          // operator<
        mapResult.insert("le", OP_LESSTHANEQUAL);     // operator<=
        mapResult.insert("gt", OP_GREATERTHAN);       // operator>
        mapResult.insert("ge", OP_GREATERTHANEQUAL);  // operator>=
        mapResult.insert("cm", OP_COMMA);             // operator,
        mapResult.insert("cl", OP_PARENS);            // operator()
        mapResult.insert("co", OP_BITWISENOT);        // operator~
        mapResult.insert("eo", OP_BITWISEXOR);        // operator^
        mapResult.insert("or", OP_BITWISEOR);         // operator|
        mapResult.insert("aa", OP_LOGICALAND);        // operator&&
        mapResult.insert("oo", OP_LOGICALOR);         // operator||
        mapResult.insert("mL", OP_TIMESEQUAL);        // operator*=
        mapResult.insert("pL", OP_PLUSEQUAL);         // operator+=
        mapResult.insert("mI", OP_MINUSEQUAL);        // operator-=
        mapResult.insert("dV", OP_DIVEQUAL);          // operator/=
        mapResult.insert("rM", OP_MODEQUAL);          // operator%=
        mapResult.insert("rS", OP_RSHEQUAL);          // operator>>=
        mapResult.insert("lS", OP_LSHEQUAL);          // operator<<=
        mapResult.insert("aN", OP_BITWISEANDEQUAL);   // operator&=
        mapResult.insert("oR", OP_BITWISEOREQUAL);    // operator|=
        mapResult.insert("eO", OP_BITWISEXOREQUAL);   // operator^=
        mapResult.insert("na", OP_ARRAYNEW);          // operator new[]
        mapResult.insert("da", OP_ARRAYDELETE);       // operator delete[]
    } else if (getSyntaxFromMode(mode) == SYNTAX_BORLAND) {
        mapResult.insert("ctr", OP_CONSTRUCTOR);
        mapResult.insert("dtr", OP_DESTRUCTOR);
        mapResult.insert("new", OP_NEW);
        mapResult.insert("dele", OP_DELETE);
        mapResult.insert("asg", OP_ASSIGN);            // operator=
        mapResult.insert("rsh", OP_RIGHTSHIFT);        // operator>>
        mapResult.insert("lsh", OP_LEFTSHIFT);         // operator<<
        mapResult.insert("not", OP_LOGICALNOT);        // operator!
        mapResult.insert("eql", OP_EQUALS);            // operator==
        mapResult.insert("neq", OP_NOTEQUALS);         // operator!=
        mapResult.insert("xor", OP_ARRAYSUBSCRIPT);    // operator[]
        mapResult.insert("arow", OP_POINTER);          // operator->
        mapResult.insert("ind", OP_DEREFERENCE);       // operator*
        mapResult.insert("adr", OP_REFERENCE);         // operator&
        mapResult.insert("inc", OP_INCREMENT);         // operator++
        mapResult.insert("dec", OP_DECREMENT);         // operator--
        mapResult.insert("sub", OP_MINUS);             // operator-
        mapResult.insert("add", OP_PLUS);              // operator+
        mapResult.insert("and", OP_BITWISEAND);        // operator&
        mapResult.insert("arwm", OP_MEMBERPOINTER);    // operator->*
        mapResult.insert("mul", OP_MULTIPLE);          // operator*
        mapResult.insert("div", OP_DIVIDE);            // operator/
        mapResult.insert("mod", OP_MODULUS);           // operator%
        mapResult.insert("lss", OP_LESSTHAN);          // operator<
        mapResult.insert("leq", OP_LESSTHANEQUAL);     // operator<=
        mapResult.insert("gtr", OP_GREATERTHAN);       // operator>
        mapResult.insert("geq", OP_GREATERTHANEQUAL);  // operator>=
        mapResult.insert("coma", OP_COMMA);            // operator,
        mapResult.insert("call", OP_PARENS);           // operator()
        mapResult.insert("cmp", OP_BITWISENOT);        // operator~
        mapResult.insert("xor", OP_BITWISEXOR);        // operator^
        mapResult.insert("or", OP_BITWISEOR);          // operator|
        mapResult.insert("land", OP_LOGICALAND);       // operator&&
        mapResult.insert("lor", OP_LOGICALOR);         // operator||
        mapResult.insert("rmul", OP_TIMESEQUAL);       // operator*=
        mapResult.insert("rplu", OP_PLUSEQUAL);        // operator+=
        mapResult.insert("rmin", OP_MINUSEQUAL);       // operator-=
        mapResult.insert("rdiv", OP_DIVEQUAL);         // operator/=
        mapResult.insert("rmod", OP_MODEQUAL);         // operator%=
        mapResult.insert("rrsh", OP_RSHEQUAL);         // operator>>=
        mapResult.insert("rlsh", OP_LSHEQUAL);         // operator<<=
        mapResult.insert("rand", OP_BITWISEANDEQUAL);  // operator&=
        mapResult.insert("ror", OP_BITWISEOREQUAL);    // operator|=
        mapResult.insert("rxor", OP_BITWISEXOREQUAL);  // operator^=
        mapResult.insert("nwa", OP_ARRAYNEW);          // operator new[]
        mapResult.insert("dla", OP_ARRAYDELETE);       // operator delete[]
        // TODO check @class1@$bsubs$qi
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getNumbers(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if ((getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) || (getSyntaxFromMode(mode) == SYNTAX_ITANIUM)) {
        for (quint32 i = 0; i < 10; i++) {
            mapResult.insert(QString("%1").arg(i), i);
        }
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getLineNumbers(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        for (quint32 i = 0; i < 10; i++) {
            mapResult.insert(QString("?%1?").arg(i), i + 1);
        }
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getSymNumbers(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        for (quint32 i = 0; i < 16; i++) {
            mapResult.insert(QString("%1").arg(QChar('A' + i)), i);
        }
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        for (quint32 i = 0; i < 10; i++) {
            mapResult.insert(QString("%1").arg(QChar('0' + i)), i);
        }

        for (quint32 i = 0; i < 26; i++) {
            mapResult.insert(QString("%1").arg(QChar('A' + i)), i + 10);
        }
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getQualifiers(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("A", QUAL_NONE);
        mapResult.insert("B", QUAL_CONST);
        mapResult.insert("C", QUAL_VOLATILE);
        mapResult.insert("D", QUAL_CONST | QUAL_VOLATILE);
        mapResult.insert("Q", QUAL_MEMBER | QUAL_NONE);
        mapResult.insert("R", QUAL_MEMBER | QUAL_CONST);
        mapResult.insert("S", QUAL_MEMBER | QUAL_VOLATILE);
        mapResult.insert("T", QUAL_MEMBER | QUAL_CONST | QUAL_VOLATILE);
    }

    return mapResult;
}

QMap<QString, quint32> XDemangle::getSpecInstr(XDemangle::MODE mode)
{
    QMap<QString, quint32> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_MICROSOFT) {
        mapResult.insert("?_7", ST_VFTABLE);
        mapResult.insert("?_8", ST_VBTABLE);
        mapResult.insert("?_B", ST_LOCALSTATICGUARD);
        mapResult.insert("?_C", ST_STRINGLITERALSYMBOL);
        mapResult.insert("?_R2", ST_RTTIBASECLASSARRAY);
        mapResult.insert("?_R3", ST_RTTICLASSHIERARCHYDESCRIPTOR);
        mapResult.insert("?_R4", ST_RTTICOMPLETEOBJLOCATOR);
        mapResult.insert("?_S", ST_LOCALVFTABLE);
        mapResult.insert("?__J", ST_LOCALSTATICTHREADGUARD);
    } else if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        mapResult.insert("TI", ST_TYPEINFO);
        mapResult.insert("TS", ST_TYPEINFONAME);
        mapResult.insert("TV", ST_VTABLE);
        mapResult.insert("Th", ST_NONVIRTUALTHUNK);
        mapResult.insert("Tv", ST_VIRTUALTHUNK);
        mapResult.insert("GV", ST_GUARDVARIABLE);
        mapResult.insert("GTt", ST_TRANSACTIONCLONE);
        mapResult.insert("TT", ST_VTT);
        mapResult.insert("TC", ST_CONSTRUCTIONVTABLE);
    }

    return mapResult;
}

QMap<QString, QString> XDemangle::getStd(MODE mode)
{
    QMap<QString, QString> mapResult;

    if (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) {
        mapResult.insert("Sa", "std::allocator");
        mapResult.insert("Sb", "std::basic_string");
        mapResult.insert("Ss", "std::string");
        mapResult.insert("Si", "std::istream");  // TODO Check
        mapResult.insert("So", "std::ostream");
        mapResult.insert("Sd", "std::iostream");
    }

    return mapResult;
}
