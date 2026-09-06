/* Copyright (c) 2021-2026 hors<horsicq@gmail.com>
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
        case MODE_UNKNOWN: sResult = tr("Unknown"); break;
        case MODE_AUTO: sResult = tr("Automatic"); break;
        case MODE_MSVC: sResult = QString("MSVC++"); break;
        case MODE_MSVC32: sResult = QString("MSVC++ 32"); break;
        case MODE_MSVC64: sResult = QString("MSVC++ 64"); break;
        case MODE_MSVCARM32: sResult = QString("MSVC++ ARM32"); break;
        case MODE_MSVCARM64: sResult = QString("MSVC++ ARM64"); break;
        case MODE_GNU_V2: sResult = QString("GNU V2"); break;  // GCC 2.9.x
        case MODE_GNU_V3: sResult = QString("GNU V3"); break;
        case MODE_GCC_WIN: sResult = QString("GNU C++ for Windows"); break;
        case MODE_GCC_MAC: sResult = QString("GNU C++ for MacOS"); break;
        case MODE_JAVA: sResult = QString("Java"); break;
        case MODE_WATCOM: sResult = QString("Watcom"); break;
        case MODE_BORLAND32: sResult = QString("Borland 32"); break;
        case MODE_BORLAND64: sResult = QString("Borland 64"); break;
        case MODE_RUST: sResult = QString("Rust"); break;
        case MODE_GNAT: sResult = QString("GNAT"); break;
        case MODE_DLANG: sResult = QString("DLANG"); break;
        case MODE_SWIFT: sResult = QString("Swift"); break;
        case MODE_GO: sResult = QString("Go"); break;
        case MODE_HASKELL: sResult = QString("Haskell"); break;
        case MODE_OCAML: sResult = QString("OCaml"); break;
        case MODE_TRU64: sResult = QString("Tru64 C++"); break;
        case MODE_SUN: sResult = QString("SunPro C++"); break;
    }

    return sResult;
}

QString XDemangle::typeIdToString(XDemangle::XTYPE type, XDemangle::MODE mode)
{
    QString sResult;

    switch (type) {
        case XTYPE_UNKNOWN: sResult = QString(""); break;
        case XTYPE_NONE: sResult = QString(""); break;
        case XTYPE_VOID: sResult = QString("void"); break;
        case XTYPE_LPVOID: sResult = QString("LPVOID"); break;
        case XTYPE_BOOL: sResult = QString("bool"); break;
        case XTYPE_VCRTBOOL: sResult = QString("__vcrt_bool"); break;
        case XTYPE_BOOL8: sResult = QString("BOOL8"); break;
        case XTYPE_WINBOOL: sResult = QString("WINBOOL"); break;
        case XTYPE_BYTE: sResult = QString("byte"); break;
        case XTYPE__BYTE: sResult = QString("_BYTE"); break;
        case XTYPE_INT: sResult = QString("int"); break;
        case XTYPE_SINT: sResult = QString("signed int"); break;
        case XTYPE_INTPTR: sResult = QString("INT_PTR"); break;
        case XTYPE_UINTPTR: sResult = QString("UINT_PTR"); break;
        case XTYPE_UINTPTRT: sResult = QString("uintptr_t"); break;
        case XTYPE_SCHAR: sResult = QString("signed char"); break;
        case XTYPE_CHAR: sResult = QString("char"); break;
        case XTYPE_UCHAR: sResult = QString("unsigned char"); break;
        case XTYPE_SHORT: sResult = QString("short"); break;
        case XTYPE_USHORT: sResult = QString("unsigned short"); break;
        case XTYPE_UINT: sResult = QString("unsigned int"); break;
        case XTYPE__UINT8: sResult = QString("unsigned __int8"); break;
        case XTYPE_LONG: sResult = QString("long"); break;
        case XTYPE_ULONG: sResult = QString("unsigned long"); break;
        case XTYPE_FLOAT: sResult = QString("float"); break;
        case XTYPE_FLOAT128: sResult = QString("__float128"); break;
        case XTYPE_DOUBLE: sResult = QString("double"); break;
        case XTYPE_LONGDOUBLE: sResult = QString("long double"); break;
        case XTYPE_LONGDOUBLE_64: sResult = QString("long double"); break;
        case XTYPE_LONGDOUBLE_80: sResult = QString("long double"); break;
        case XTYPE_INT8: sResult = QString("__int8"); break;
        case XTYPE_INT16: sResult = QString("__int16"); break;
        case XTYPE_INT32: sResult = QString("__int32"); break;
        case XTYPE_INT64: sResult = QString("__int64"); break;
        case XTYPE_INT128: sResult = QString("__int128"); break;
        case XTYPE_UINT128: sResult = QString("unsigned __int128"); break;
        case XTYPE_HALF: sResult = QString("half"); break;
        case XTYPE_UINT64: sResult = QString("unsigned __int64"); break;
        case XTYPE_LONGLONG: sResult = QString("long long"); break;
        case XTYPE_ULONGLONG: sResult = QString("unsigned long long"); break;
        case XTYPE_CHAR8: sResult = QString("char8_t"); break;
        case XTYPE_CHAR16: sResult = QString("char16_t"); break;
        case XTYPE_CHAR32: sResult = QString("char32_t"); break;
        case XTYPE_DECIMAL32: sResult = QString("decimal32"); break;
        case XTYPE_DECIMAL64: sResult = QString("decimal64"); break;
        case XTYPE_DECIMAL128: sResult = QString("decimal128"); break;
        case XTYPE_WCHAR: sResult = QString("wchar_t"); break;
        case XTYPE_VARARGS: sResult = QString("..."); break;
        case XTYPE_CLASS: sResult = QString("class"); break;
        case XTYPE_UNION: sResult = QString("union"); break;
        case XTYPE_STRUCT: sResult = QString("struct"); break;
        case XTYPE_ENUM: sResult = QString("enum"); break;
        case XTYPE_POINTERTOFUNCTION: sResult = QString(""); break;
        // Itanium (Dn) renders "decltype(nullptr)"; MSVC ($$T) renders "std::nullptr_t".
        case XTYPE_NULLPTR: sResult = (getSyntaxFromMode(mode) == SYNTAX_ITANIUM) ? QString("decltype(nullptr)") : QString("std::nullptr_t"); break;
        case XTYPE_NTSTATUS: sResult = QString("NTSTATUS"); break;  // Used by Drivers
        case XTYPE_DWORD: sResult = QString("DWORD"); break;
        case XTYPE__DWORD: sResult = QString("_DWORD"); break;
        case XTYPE_QWORD: sResult = QString("QWORD"); break;
        case XTYPE__QWORD: sResult = QString("_QWORD"); break;
        case XTYPE_HWND: sResult = QString("HWND"); break;
        case XTYPE_HDC: sResult = QString("HDC"); break;
        case XTYPE_LRESULT: sResult = QString("LRESULT"); break;
        case XTYPE_HRESULT: sResult = QString("HRESULT"); break;
        case XTYPE_HMODULE: sResult = QString("HMODULE"); break;
        case XTYPE_HMONITOR: sResult = QString("HMONITOR"); break;
        case XTYPE_HGLOBAL: sResult = QString("HGLOBAL"); break;
        case XTYPE_HLOCAL: sResult = QString("HLOCAL"); break;
        case XTYPE_LSTATUS: sResult = QString("LSTATUS"); break;
        case XTYPE_SURFACE: sResult = QString("surface"); break;
        case XTYPE_BSTR: sResult = QString("BSTR"); break;
        case XTYPE_BCSTR: sResult = QString("BCSTR"); break;
        case XTYPE_LPCSTR: sResult = QString("LPCSTR"); break;
        case XTYPE_LPWSTR: sResult = QString("LPWSTR"); break;
        case XTYPE_SIZET: sResult = QString("size_t"); break;
        case XTYPE_WINTT: sResult = QString("wint_t"); break;
        case XTYPE_FILE: sResult = QString("FILE"); break;
        case XTYPE_LOCALEFACET: sResult = QString("std::locale::facet"); break;
        case XTYPE_CCHECKLISTBOX: sResult = QString("CCheckListBox"); break;
        case XTYPE__WORD: sResult = QString("_WORD"); break;
        case XTYPE_IOSTREAMINIT: sResult = QString("Iostream_init"); break;
        case XTYPE_STDEXCEPTION: sResult = QString("std::exception"); break;
        case XTYPE_FARPROC: sResult = QString("FARPROC"); break;
        case XTYPE_HANDLE: sResult = QString("HANDLE"); break;
        case XTYPE_HKEY: sResult = QString("HKEY"); break;
        case XTYPE_M128: sResult = QString("__m128"); break;
        case XTYPE_CEXCEPTION: sResult = QString("CException"); break;
        case XTYPE_CFILE: sResult = QString("CFile"); break;
        case XTYPE_CFILEFIND: sResult = QString("CFileFind"); break;
        case XTYPE_CWND: sResult = QString("CWnd"); break;
        case XTYPE_CSTRING: sResult = QString("CString"); break;
        case XTYPE_CSTRINGARRAY: sResult = QString("CStringArray"); break;
        case XTYPE_CDialog: sResult = QString("CDialog"); break;
        case XTYPE_AFXTERMAPPSTATE: sResult = QString("_AFX_TERM_APP_STATE"); break;
        case XTYPE_AFXMODULESTATE: sResult = QString("AFX_MODULE_STATE"); break;
        case XTYPE_AFXMODULETHREADSTATE: sResult = QString("AFX_MODULE_THREAD_STATE"); break;
        case XTYPE_LPCRITICALSECTION: sResult = QString("LPCRITICAL_SECTION"); break;
        case XTYPE_HGDIOBJ: sResult = QString("HGDIOBJ"); break;
        case XTYPE_COLORREF: sResult = QString("COLORREF"); break;
        case XTYPE_HBITMAP: sResult = QString("HBITMAP"); break;
        case XTYPE_HPALETTE: sResult = QString("HPALETTE"); break;
        case XTYPE_HBRUSH: sResult = QString("HBRUSH"); break;
        case XTYPE_HCURSOR: sResult = QString("HCURSOR"); break;
        case XTYPE_HMENU: sResult = QString("HMENU"); break;
        case XTYPE_EXCEPTION: sResult = QString("exception"); break;
        case XTYPE_ERRNOT: sResult = QString("errno_t"); break;
        case XTYPE_LARGEINTEGER: sResult = QString("LARGE_INTERGER"); break;
        case XTYPE_LPTOPLEVELEXCEPTIONFILTER: sResult = QString("LPTOP_LEVEL_EXCEPTION_FILTER"); break;
        case XTYPE_TYPEINFO: sResult = QString("type_info"); break;
        case XTYPE_BOOLEAN: sResult = QString("BOOLEAN"); break;
        case XTYPE_PCWSTR: sResult = QString("PCWSTR"); break;
        case XTYPE_HHOOK: sResult = QString("HHOOK"); break;
        case XTYPE_LPDIRECTDRAW: sResult = QString("LPDIRECTDRAW"); break;
        case XTYPE_STDIOSBASE: sResult = QString("std::ios_base"); break;
        case XTYPE_PIMAGESECTIONHEADER: sResult = QString("PIMAGE_SECTION_HEADER"); break;
        case XTYPE_STDOSTREAMSENTRY: sResult = QString("std::ostream::sentry"); break;
        case XTYPE_W64: sResult = QString("__w64"); break;
        case XTYPE_GC: sResult = QString("__gc"); break;
        case XTYPE_PIN: sResult = QString("__pin"); break;
        case XTYPE_BOX: sResult = QString("__box"); break;
        case XTYPE_BASED: sResult = QString("__based"); break;
        case XTYPE_QSTRING: sResult = QString("QString"); break;
        case XTYPE_QMAPNODEBASE: sResult = QString("QMapNodeBase"); break;
        case XTYPE_QTHREAD: sResult = QString("QThread"); break;
        case XTYPE_QMETAOBJECT: sResult = QString("QMetaObject"); break;
        case XTYPE_QLISTDATA: sResult = QString("QListData"); break;
        case XTYPE_QSPACERITEM: sResult = QString("QSpacerItem"); break;
        case XTYPE_QWIDGET: sResult = QString("QWidget"); break;
        case XTYPE_QOBJECT: sResult = QString("QObject"); break;
        case XTYPE_QNETWORKACCESSMANAGER: sResult = QString("QNetworkAccessManager"); break;
        case XTYPE_PTR64: sResult = QString("__ptr64"); break;
        case XTYPE_ATOM: sResult = QString("ATOM"); break;
        case XTYPE_PULONG: sResult = QString("PULONG"); break;
        case XTYPE_MMRESULT: sResult = QString("MRESULT"); break;
        case XTYPE_WPARAM: sResult = QString("WPARAM"); break;
        case XTYPE_HINSTANCE: sResult = QString("HINSTANCE"); break;
        default: sResult = tr("Unknown");
    }

    return sResult;
}

QString XDemangle::storageClassIdToString(XDemangle::SC storageClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult = tr("Unknown");

    switch (storageClass) {
        case SC_UNKNOWN: sResult = QString(""); break;
        case SC_NEAR: sResult = QString(""); break;
        case SC_CONST: sResult = QString("const"); break;
        case SC_CONSTCHAR: sResult = QString("const char"); break;
        case SC_VOLATILE: sResult = QString("volatile"); break;
        case SC_CONSTVOLATILE: sResult = QString("const volatile"); break;
        case SC_FAR: sResult = QString(""); break;
        case SC_CONSTFAR: sResult = QString("const"); break;
        case SC_VOLATILEFAR: sResult = QString("volatile"); break;
        case SC_CONSTVOLATILEFAR: sResult = QString("const volatile"); break;
        case SC_CONSTCLASS: sResult = QString("const class"); break;
        case SC_HUGE: sResult = QString(""); break;
        case SC_EXECUTABLE: sResult = QString(""); break;
    }

    return sResult;
}

QString XDemangle::objectClassIdToString(OC objectClass, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult;

    switch (objectClass) {
        case OC_UNKNOWN: sResult = QString("Unknown"); break;
        case OC_GLOBALOBJECT: sResult = QString(""); break;
        case OC_PRIVATESTATICCLASSMEMBER: sResult = QString("private: static"); break;
        case OC_PROTECTEDSTATICCLASSMEMBER: sResult = QString("protected: static"); break;
        case OC_PUBLICSTATICCLASSMEMBER: sResult = QString("public: static"); break;
        default: sResult = tr("Unknown");
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

    if (nFunctionMod & FM_PRIVATE) sResult += QString("private:");
    else if (nFunctionMod & FM_PROTECTED) sResult += QString("protected:");
    else if (nFunctionMod & FM_PUBLIC) sResult += QString("public:");
    else bStatic = false;

    if ((nFunctionMod & FM_STATIC) || (nFunctionMod & FM_VIRTUAL)) {
        if (sResult != "") sResult += " ";

        if (bStatic) sResult += QString("static");
        else if (bVirtual) sResult += QString("virtual");
    }

    return sResult;
}

QString XDemangle::functionConventionIdToString(XDemangle::FC functionConvention, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult;

    switch (functionConvention) {
        case FC_UNKNOWN: sResult = QString(""); break;
        case FC_NONE: sResult = QString(""); break;
        case FC_CDECL: sResult = QString("__cdecl"); break;
        case FC_CDECLPOINTER: sResult = QString("*__cdecl"); break;
        case FC_CDECL16FAR: sResult = QString("__cdecl16far"); break;
        case FC_CDECL16NEAR: sResult = QString("__cdecl16near"); break;
        case FC_THISCALL: sResult = QString("__thiscall"); break;
        case FC_THISCALLPOINTER: sResult = QString("*__thiscall"); break;
        case FC_STDCALL: sResult = QString("__stdcall"); break;
        case FC_STDCALL16FAR: sResult = QString("__stdcall16far"); break;
        case FC_STDCALLPOINTER: sResult = QString("*__stdcall"); break;
        case FC_FASTCALL: sResult = QString("__fastcall"); break;
        case FC_CLRCALL: sResult = QString("__clrcall"); break;
        case FC_VECTORCALL: sResult = QString("__vectorcall"); break;
        case FC_USERCALL: sResult = QString("__usercall"); break;
        case FC_USERPURGE: sResult = QString("__userpurge"); break;
        case FC_USERPURGEPOINTER: sResult = QString("*__userpurge"); break;
        case FC_NORETURN: sResult = QString("__noreturn"); break;
        case FC_PASCAL: sResult = QString("__pascal"); break;
        case FC_SWIFT1: sResult = QString("__swift_1"); break;
        case FC_SWIFT2: sResult = QString("__swift_2"); break;
        case FC_SWIFT3: sResult = QString("__swift_3"); break;
        case FC_RESTRICT: sResult = QString("__restrict"); break;
        case FC_UNALIGNED: sResult = QString("__unaligned"); break;
        default: sResult = tr("Unknown");
    }

    return sResult;
}

QString XDemangle::operatorIdToString(XDemangle::OP _operator, XDemangle::MODE mode)
{
    Q_UNUSED(mode)  // TODO

    QString sResult = tr("Unknown");

    switch (_operator) {
        case OP_UNKNOWN: sResult = QString("Unknown"); break;
        case OP_CONSTRUCTOR: sResult = QString(""); break;
        case OP_DESTRUCTOR: sResult = QString("~"); break;
        case OP_NEW: sResult = QString("operator new"); break;
        case OP_DELETE: sResult = QString("operator delete"); break;
        case OP_ASSIGN: sResult = QString("operator="); break;
        case OP_RIGHTSHIFT: sResult = QString("operator>>"); break;
        case OP_LEFTSHIFT: sResult = QString("operator<<"); break;
        case OP_LOGICALNOT: sResult = QString("operator!"); break;
        case OP_EQUALS: sResult = QString("operator=="); break;
        case OP_NOTEQUALS: sResult = QString("operator!="); break;
        case OP_ARRAYSUBSCRIPT: sResult = QString("operator[]"); break;
        case OP_POINTER: sResult = QString("operator->"); break;
        case OP_DEREFERENCE: sResult = QString("operator*"); break;
        case OP_REFERENCE: sResult = QString("operator&"); break;
        case OP_INCREMENT: sResult = QString("operator++"); break;
        case OP_DECREMENT: sResult = QString("operator--"); break;
        case OP_MINUS: sResult = QString("operator-"); break;
        case OP_PLUS: sResult = QString("operator+"); break;
        case OP_BITWISEAND: sResult = QString("operator&"); break;
        case OP_MEMBERPOINTER: sResult = QString("operator->*"); break;
        case OP_MULTIPLE: sResult = QString("operator*"); break;
        case OP_DIVIDE: sResult = QString("operator/"); break;
        case OP_MODULUS: sResult = QString("operator%"); break;
        case OP_LESSTHAN: sResult = QString("operator<"); break;
        case OP_LESSTHANEQUAL: sResult = QString("operator<="); break;
        case OP_GREATERTHAN: sResult = QString("operator>"); break;
        case OP_GREATERTHANEQUAL: sResult = QString("operator>="); break;
        case OP_THREWAYCOMPARISON: sResult = QString("operator<=>"); break;
        case OP_COMMA: sResult = QString("operator,"); break;
        case OP_PARENS: sResult = QString("operator()"); break;
        case OP_BITWISENOT: sResult = QString("operator~"); break;
        case OP_BITWISEXOR: sResult = QString("operator^"); break;
        case OP_BITWISEOR: sResult = QString("operator|"); break;
        case OP_LOGICALAND: sResult = QString("operator&&"); break;
        case OP_LOGICALOR: sResult = QString("operator||"); break;
        case OP_TIMESEQUAL: sResult = QString("operator*="); break;
        case OP_PLUSEQUAL: sResult = QString("operator+="); break;
        case OP_MINUSEQUAL: sResult = QString("operator-="); break;
        case OP_DIVEQUAL: sResult = QString("operator/="); break;
        case OP_MODEQUAL: sResult = QString("operator%="); break;
        case OP_RSHEQUAL: sResult = QString("operator>>="); break;
        case OP_LSHEQUAL: sResult = QString("operator<<="); break;
        case OP_BITWISEANDEQUAL: sResult = QString("operator&="); break;
        case OP_BITWISEOREQUAL: sResult = QString("operator|="); break;
        case OP_BITWISEXOREQUAL: sResult = QString("operator^="); break;
        case OP_VBASEDTOR: sResult = QString("`vbase dtor'"); break;
        case OP_VECDELDTOR: sResult = QString("`vector deleting dtor'"); break;
        case OP_DEFAULTCTORCLOSURE: sResult = QString("`default ctor closure'"); break;
        case OP_SCALARDELDTOR: sResult = QString("`scalar deleting dtor'"); break;
        case OP_VECCTORITER: sResult = QString("`vector ctor iterator'"); break;
        case OP_VECDTORITER: sResult = QString("`vector dtor iterator'"); break;
        case OP_VECVBASECTORITER: sResult = QString("`vector vbase ctor iterator'"); break;
        case OP_VDISPMAP: sResult = QString("`virtual displacement map'"); break;
        case OP_EHVECCTORITER: sResult = QString("`eh vector ctor iterator'"); break;
        case OP_EHVECDTORITER: sResult = QString("`eh vector dtor iterator'"); break;
        case OP_EHVECVBASECTORITER: sResult = QString("`eh vector vbase ctor iterator'"); break;
        case OP_COPYCTORCLOSURE: sResult = QString("`copy ctor closure'"); break;
        case OP_ARRAYNEW: sResult = QString("operator new[]"); break;
        case OP_ARRAYDELETE: sResult = QString("operator delete[]"); break;
        case OP_TYPE: sResult = QString("operator "); break;
    }

    return sResult;
}

QString XDemangle::qualIdToPointerString(quint32 nQual, XDemangle::MODE mode)
{
    Q_UNUSED(mode)

    QString sResult;

    if (nQual & QUAL_POINTER) sResult += "*";
    else if (nQual & QUAL_REFERENCE) sResult += "&";
    else if (nQual & QUAL_DOUBLEREFERENCE) sResult += "&&";
    else if (nQual & QUAL_RVALUEREF) sResult += "&&";

    if (nQual & QUAL_CONST) {
        sResult += "const";
    }

    if (nQual & QUAL_VOLATILE) {
        if (nQual & QUAL_CONST) {
            sResult += " ";
        }

        sResult += "volatile";
    }

    if (nQual & QUAL_SIGNED) sResult += "signed";
    else if (nQual & QUAL_UNSIGNED) sResult += "unsigned";

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

    if ((mode == MODE_MSVC32) || (mode == MODE_MSVC64) || (mode == MODE_MSVC) || (mode == MODE_MSVCARM32) || (mode == MODE_MSVCARM64)) {
        result = SYNTAX_MICROSOFT;
    } else if ((mode == MODE_GNU_V3) || (mode == MODE_GCC_MAC) || (mode == MODE_GCC_WIN) || (mode == MODE_JAVA) || (mode == MODE_BORLAND64)) {
        // Embarcadero's 64-bit C++ compiler (bcc64) is Clang-based and uses the Itanium ABI.
        result = SYNTAX_ITANIUM;
    } else if (mode == MODE_BORLAND32) {
        result = SYNTAX_BORLAND;
    } else if (mode == MODE_WATCOM) {
        result = SYNTAX_WATCOM;
    } else if ((mode == MODE_GNU_V2) || (mode == MODE_TRU64)) {
        // Tru64/DEC C++ (ARM mode) is the same family, differing only in the '__X' marker.
        result = SYNTAX_GNU2;
    } else if (mode == MODE_SWIFT) {
        result = SYNTAX_SWIFT;
    } else if (mode == MODE_SUN) {
        result = SYNTAX_SUN;
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

qint32 XDemangle::ms_demangle_SpecialTable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    qint32 nNSSize = ms_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

    reverseList(&(pParameter->listDnames));

    nResult += nNSSize;
    _sString = _sString.mid(nNSSize, -1);

    if ((!_compare(_sString, "6")) && (!_compare(_sString, "7"))) {
        pSymbol->bIsValid = false;
    }

    if (pSymbol->bIsValid) {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

            pParameter->nQualifier = signature.nValue;
            _sString = _sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        }

        if (_compare(_sString, "@")) {
            nResult += 1;
            _sString = _sString.mid(1, -1);
        } else {
            DPARAMETER parameter = {};
            parameter.st = ST_NAME;

            qint32 nPSize = ms_demangle_NameScope(pSymbol, pHdata, &parameter, _sString);

            nResult += nPSize;
            _sString = _sString.mid(nPSize, -1);

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

qint32 XDemangle::ms_demangle_Type(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, MSDT msdt)
{
    QString _sString = sString;
    qint32 nResult = 0;

    if (msdt == MSDT_MANGLE) {
        if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

            pParameter->nQualifier = signature.nValue;

            nResult += signature.nSize;
            _sString = _sString.mid(signature.nSize, -1);
        }
    } else if (msdt == MSDT_RESULT) {
        if (_compare(_sString, "?")) {
            _sString = _sString.mid(1, -1);
            nResult += 1;

            if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
                SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

                pParameter->nQualifier = signature.nValue;

                nResult += signature.nSize;
                _sString = _sString.mid(signature.nSize, -1);
            }
        }
    }

    if (isSignaturePresent(_sString, &(pHdata->mapTagTypes))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapTagTypes));
        pParameter->type = (XTYPE)signature.nValue;
        pParameter->st = ST_TYPE;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);

        qint32 nFNSize = ms_demangle_FullTypeName(pSymbol, pHdata, pParameter, _sString);

        nResult += nFNSize;
        _sString = _sString.mid(nFNSize, -1);
    } else if (isSignaturePresent(_sString, &(pHdata->mapPointerTypes))) {
        if (ms_isPointerMember(pSymbol, pHdata, _sString)) {
            qint32 nPTSize = ms_demangle_MemberPointerType(pSymbol, pHdata, pParameter, _sString);

            nResult += nPTSize;
            _sString = _sString.mid(nPTSize, -1);
        } else if (pSymbol->bIsValid) {
            qint32 nPTSize = ms_demangle_PointerType(pSymbol, pHdata, pParameter, _sString);

            nResult += nPTSize;
            _sString = _sString.mid(nPTSize, -1);
        }
    } else if (_compare(_sString, "Y"))  // Array
    {
        _sString = _sString.mid(1, -1);
        nResult += 1;

        while (pSymbol->bIsValid) {
            NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize == 0) {
                break;
            }

            pParameter->listIndexes.append(number.nValue);

            _sString = _sString.mid(number.nSize, -1);
            nResult += number.nSize;
        }

        if (_compare(_sString, "$$C")) {
            _sString = _sString.mid(3, -1);
            nResult += 3;

            if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
                SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

                pParameter->nQualifier |= signature.nValue;

                nResult += signature.nSize;
                _sString = _sString.mid(signature.nSize, -1);
            }
        }

        qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, pParameter, _sString, MSDT_DROP);

        _sString = _sString.mid(nTSize, -1);
        nResult += nTSize;
    } else if (isSignaturePresent(_sString, &(pHdata->mapTypes))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapTypes));
        pParameter->type = (XTYPE)signature.nValue;
        pParameter->st = ST_TYPE;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);
    } else if (_compare(_sString, "$$A8@@"))  // Function
    {
        _sString = _sString.mid(6, -1);
        nResult += 6;

        pParameter->st = ST_FUNCTION;

        qint32 nFSize = ms_demangle_FunctionType(pSymbol, pHdata, pParameter, _sString, true);

        _sString = _sString.mid(nFSize, -1);
        nResult += nFSize;
    } else if (_compare(_sString, "$$A6"))  // Function
    {
        _sString = _sString.mid(4, -1);
        nResult += 4;

        pParameter->st = ST_FUNCTION;

        qint32 nFSize = ms_demangle_FunctionType(pSymbol, pHdata, pParameter, _sString, false);

        _sString = _sString.mid(nFSize, -1);
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

qint32 XDemangle::ms_demangle_MemberPointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
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

    qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, _sString, &(pParameter->nQualifier));

    nResult += nESize;
    _sString = _sString.mid(nESize, -1);

    if (_compare(_sString, "8")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        DPARAMETER parameter = {};
        parameter.st = ST_FUNCTION;

        qint32 nFTSize = ms_demangle_FullTypeName(pSymbol, pHdata, pParameter, _sString);

        nResult += nFTSize;
        _sString = _sString.mid(nFTSize, -1);

        qint32 nPSize = ms_demangle_FunctionType(pSymbol, pHdata, &parameter, _sString, true);

        pParameter->listPointer.append(parameter);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    } else {
        DPARAMETER parameter = {};

        if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

            parameter.nQualifier = signature.nValue;

            nResult += signature.nSize;
            _sString = _sString.mid(signature.nSize, -1);
        }

        qint32 nFTSize = ms_demangle_FullTypeName(pSymbol, pHdata, pParameter, _sString);

        nResult += nFTSize;
        _sString = _sString.mid(nFTSize, -1);

        qint32 nPSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_DROP);

        pParameter->listPointer.append(parameter);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FullTypeName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    qint32 nUnkName = ms_demangle_UnkTypeName(pSymbol, pHdata, pParameter, _sString, true);
    nResult += nUnkName;

    _sString = _sString.mid(nUnkName, -1);

    qint32 nNameScope = ms_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);
    nResult += nNameScope;

    _sString = _sString.mid(nNameScope, -1);

    reverseList(&(pParameter->listDnames));

    return nResult;
}

qint32 XDemangle::ms_demangle_FullSymbolName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    qint32 nUnkName = ms_demangle_UnkSymbolName(pSymbol, pHdata, pParameter, _sString, NB_SIMPLE);
    nResult += nUnkName;

    _sString = _sString.mid(nUnkName, -1);

    qint32 nNameScope = ms_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);
    nResult += nNameScope;

    _sString = _sString.mid(nNameScope, -1);

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

qint32 XDemangle::ms_demangle_UnkSymbolName(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, NB nb)
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
        qint32 nTSize = ms_demangle_Template(pSymbol, pHdata, pParameter, _sString, nb);
        _sString = _sString.mid(nTSize, -1);
        nResult += nTSize;
    } else if (isSignaturePresent(_sString, &(pHdata->mapOperators))) {
        DNAME dname = {};
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapOperators));
        dname._operator = (OP)signature.nValue;
        nResult += signature.nSize;

        pParameter->listDnames.append(dname);
    } else {
        STRING string = readString(pHdata, _sString, pSymbol->mode);

        if (string.nSize) {
            if (nb & NB_SIMPLE) {
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

qint32 XDemangle::ms_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;

    qint32 nResult = 0;

    while (_sString != "") {
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
        } else if (_compare(_sString, "?A")) {
#ifdef QT_DEBUG
            qDebug("TODO: AnonymousNamespaceName");
#endif
            _sString = _sString.mid(2, -1);
            nResult += 2;
        } else if (isLocalScopePresent(pSymbol, pHdata, _sString)) {
            SIGNATURE signature = getLocalScopeSignature(pSymbol, pHdata, _sString);

            DNAME dnameLocalScope = {};
            dnameLocalScope.sName = QString("`%1'").arg(signature.sValue);

            pParameter->listDnames.append(dnameLocalScope);

            _sString = _sString.mid(signature.nSize, -1);
            nResult += signature.nSize;

            DSYMBOL symbol = ms_getSymbol(_sString, pSymbol->mode, pHdata);

            DNAME dnameSymbol = {};
            dnameSymbol.sName = QString("`%1'").arg(dsymbolToString(symbol));

            pParameter->listDnames.append(dnameSymbol);

            _sString = _sString.mid(symbol.nSize, -1);
            nResult += symbol.nSize;
        } else {
            STRING string = readString(pHdata, _sString, pSymbol->mode);

            if (string.nSize) {
                addStringRef(pSymbol, pHdata, string.sString);

                DNAME dname = {};
                dname.sName = string.sString;

                pParameter->listDnames.append(dname);

                _sString = _sString.mid(string.nSize, -1);
                nResult += string.nSize;
            }
        }

        if (_compare(_sString, "@")) {
            nResult += 1;
            _sString = _sString.mid(1, -1);

            break;
        }

        if (!(pSymbol->bIsValid)) {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Declarator(DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pDParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    qint32 nFNSize = ms_demangle_FullSymbolName(pSymbol, pHdata, pDParameter, _sString);

    nResult += nFNSize;
    _sString = _sString.mid(nFNSize, -1);

    qint32 nRSize = ms_demangle_Parameters(pSymbol, pHdata, pDParameter, _sString);

    nResult += nRSize;
    _sString = _sString.mid(nRSize, -1);

    return nResult;
}

qint32 XDemangle::ms_demangle_Parameters(DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
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

qint32 XDemangle::ms_demangle_Function(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    if (_compare(_sString, "$$J0")) {
        nResult += 4;
        _sString = _sString.mid(4, -1);
        pParameter->nAccess = FM_EXTERNC;
    }

    if (isSignaturePresent(_sString, &(pHdata->mapAccessMods))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapAccessMods));
        pParameter->nAccess |= signature.nValue;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);
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

        qint32 nFSize = ms_demangle_FunctionType(pSymbol, pHdata, pParameter, _sString, bThisQual);

        nResult += nFSize;
        _sString = _sString.mid(nFSize, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_Variable(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    if (isSignaturePresent(_sString, &(pHdata->mapAccessMods))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapAccessMods));

        pParameter->nAccess = signature.nValue;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);
    }

    DPARAMETER parameter = {};
    parameter.st = ST_TYPE;

    qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_DROP);

    pParameter->listParameters.append(parameter);

    nResult += nTSize;
    _sString = _sString.mid(nTSize, -1);

    if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

        pParameter->nQualifier = signature.nValue;
        _sString = _sString.mid(signature.nSize, -1);
        nResult += signature.nSize;
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString,
                                           bool bThisQual)
{
    QString _sString = sString;
    qint32 nResult = 0;

    if (bThisQual) {
        qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, _sString, &(pParameter->nQualifier));

        _sString = _sString.mid(nESize, -1);
        nResult += nESize;

        if (_compare(_sString, "G")) {
            pParameter->nRefQualifier |= QUAL_REFERENCE;
            _sString = _sString.mid(1, -1);
            nResult += 1;
        } else if (_compare(_sString, "H")) {
            pParameter->nRefQualifier |= QUAL_RVALUEREF;
            _sString = _sString.mid(1, -1);
            nResult += 1;
        }

        if (isSignaturePresent(_sString, &(pHdata->mapQualifiers))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapQualifiers));

            pParameter->nRefQualifier |= signature.nValue;
            _sString = _sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        }
    }

    if (isSignaturePresent(_sString, &(pHdata->mapFunctionConventions))) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapFunctionConventions));

        pParameter->functionConvention = (FC)signature.nValue;
        _sString = _sString.mid(signature.nSize, -1);
        nResult += signature.nSize;
    }

    if (_compare(_sString, "@")) {
        pParameter->type = XTYPE_NONE;
        _sString = _sString.mid(1, -1);
        nResult += 1;
    } else {
        DPARAMETER parameter = {};

        qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_RESULT);

        pParameter->listReturn.append(parameter);

        nResult += nTSize;
        _sString = _sString.mid(nTSize, -1);
    }

    if (_compare(_sString, "X")) {
        // Void
        DPARAMETER parameter = {};

        qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_DROP);

        pParameter->listParameters.append(parameter);

        _sString = _sString.mid(nTSize, -1);
        nResult += nTSize;
    } else {
        qint32 nPSize = ms_demangle_FunctionParameters(pSymbol, pHdata, pParameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    }

    if (_compare(_sString, "Z")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);
    } else if (_compare(_sString, "_E")) {
#ifdef QT_DEBUG
        qDebug("TODO: function exception");
#endif

        pSymbol->bIsValid = false;

        nResult += 2;
        _sString = _sString.mid(2, -1);
    }

    return nResult;
}

qint32 XDemangle::ms_demangle_FunctionParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    while (_sString != "") {
        bool bBreak = false;

        if (_compare(_sString, "@")) {
            _sString = _sString.mid(1, -1);
            nResult += 1;

            break;
        } else if (_compare(_sString, "Z")) {
            bBreak = true;
        }

        if (isReplaceArgPresent(pSymbol, pHdata, _sString)) {
            SIGNATURE signature = getReplaceArgSignature(pSymbol, pHdata, _sString);

            DPARAMETER parameter = {};

            ms_demangle_Type(pSymbol, pHdata, &parameter, signature.sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            _sString = _sString.mid(signature.nSize, -1);
            nResult += signature.nSize;
        } else {
            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            QString sArg = _sString.left(nTSize);
            addArgRef(pSymbol, pHdata, sArg);

            nResult += nTSize;
            _sString = _sString.mid(nTSize, -1);
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

qint32 XDemangle::ms_demangle_Template(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString, XDemangle::NB nb)
{
    QString _sString = sString;
    qint32 nResult = 0;

    if (_compare(_sString, "?$")) {
        _sString = _sString.mid(2, -1);
        nResult += 2;

        XDemangle::HDATA hdata = *pHdata;
        hdata.listArgRef.clear();
        hdata.listStringRef.clear();

        DPARAMETER parameter = {};
        parameter.st = ST_TEMPLATE;

        qint32 nNName = ms_demangle_UnkSymbolName(pSymbol, &hdata, &parameter, _sString, NB_SIMPLE);
        _sString = _sString.mid(nNName, -1);
        nResult += nNName;

        qint32 nTName = ms_demangle_TemplateParameters(pSymbol, &hdata, &parameter, _sString);
        _sString = _sString.mid(nTName, -1);
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

qint32 XDemangle::ms_demangle_TemplateParameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    while (_sString != "") {
        if (_compare(_sString, "@")) {
            break;
        }

        if (_compare(_sString, "$S")) {
            nResult += 2;
            _sString = _sString.mid(2, -1);
        }

        if (_compare(_sString, "$$V") || _compare(_sString, "$$Z")) {
            nResult += 3;
            _sString = _sString.mid(3, -1);
        }

        if (_compare(_sString, "$$$V")) {
            nResult += 4;
            _sString = _sString.mid(4, -1);
        }

        if (_compare(_sString, "$$Y")) {
            nResult += 3;
            _sString = _sString.mid(3, -1);

            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("TODO: Template alias");
#endif
        } else if (_compare(_sString, "$$B")) {
            // TODO Check
            nResult += 3;
            _sString = _sString.mid(3, -1);

            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            nResult += nTSize;
            _sString = _sString.mid(nTSize, -1);
        } else if (_compare(_sString, "$$C")) {
            nResult += 3;
            _sString = _sString.mid(3, -1);

            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_MANGLE);

            pParameter->listParameters.append(parameter);

            nResult += nTSize;
            _sString = _sString.mid(nTSize, -1);
        } else if (_compare(_sString, "$1") || _compare(_sString, "$H") || _compare(_sString, "$I") || _compare(_sString, "$J")) {
            nResult += 2;
            _sString = _sString.mid(2, -1);

            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("TODO: Template");
#endif
        } else if (_compare(_sString, "$E?")) {
            nResult += 3;
            _sString = _sString.mid(3, -1);

            pSymbol->bIsValid = false;
#ifdef QT_DEBUG
            qDebug("TODO: Reference to symbol");
#endif
        } else if (_compare(_sString, "$0")) {
            nResult += 2;
            _sString = _sString.mid(2, -1);

            NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);

            DPARAMETER parameter = {};

            parameter.st = ST_CONST;
            parameter.varConst = QString::number(number.nValue);

            pParameter->listParameters.append(parameter);

            nResult += number.nSize;
            _sString = _sString.mid(number.nSize, -1);
        } else {
            DPARAMETER parameter = {};

            qint32 nTSize = ms_demangle_Type(pSymbol, pHdata, &parameter, _sString, MSDT_DROP);

            pParameter->listParameters.append(parameter);

            nResult += nTSize;
            _sString = _sString.mid(nTSize, -1);

            if (!(pSymbol->bIsValid)) {
                break;
            }
        }
    }

    if (_compare(_sString, "@")) {
        _sString = _sString.mid(1, -1);
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

bool XDemangle::ms_isPointerMember(XDemangle::DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString)
{
    QString _sString = sString;

    if (_compare(_sString, "$")) {
        // rvalue ref
        return false;
    } else if (_compare(_sString, "A")) {
        // ref
        return false;
    }
    // PQRS
    _sString = _sString.mid(1, -1);

    if (isSignaturePresent(_sString, &(pHdata->mapNumbers))) {
        if ((!_compare(_sString, "6")) && (!_compare(_sString, "8"))) {
            pSymbol->bIsValid = false;

            return false;
        }

        return _compare(_sString, "8");
    }

    quint32 nQual = 0;

    qint32 nESize = ms_demangle_ExtQualifiers(pSymbol, _sString, &nQual);

    _sString = _sString.mid(nESize, -1);

    if (_sString == "") {
        pSymbol->bIsValid = false;

        return false;
    }

    if (_compare(_sString, "A") || _compare(_sString, "B") || _compare(_sString, "C") || _compare(_sString, "D")) {
        return false;
    }

    if (_compare(_sString, "Q") || _compare(_sString, "R") || _compare(_sString, "S") || _compare(_sString, "T")) {
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

void XDemangle::addStringListRef(DSYMBOL *pSymbol, HDATA *pHdata, const QList<QString> &listString)
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

bool XDemangle::isLocalScopePresent(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    QString _sString = sString;
    bool bResult = false;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        if (_compare(_sString, "?")) {
            _sString = _sString.mid(1, -1);

            NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize) {
                _sString = _sString.mid(number.nSize, -1);

                if (_compare(_sString, "?")) {
                    bResult = true;
                }
            }
        }
    }

    return bResult;
}

XDemangle::SIGNATURE XDemangle::getReplaceStringSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    QString _sString = sString;
    SIGNATURE result = {};

    qint32 nIndex = -1;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapNumbers));

        nIndex = signature.nValue;
        result.nSize = 1;
        result.nValue = signature.nValue;
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (_compare(_sString, "S")) {
            _sString = _sString.mid(1, -1);

            NUMBER number = readSymNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize) {
                _sString = _sString.mid(number.nSize, -1);
                result.nValue = number.nValue + 1;
            }

            if (_compare(_sString, "_")) {
                _sString = _sString.mid(1, -1);

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

XDemangle::SIGNATURE XDemangle::getReplaceArgSignature(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, const QString &sString)
{
    QString _sString = sString;

    SIGNATURE result = {};

    QString sOrigString = _sString;

    qint32 nIndex = 0;

    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_MICROSOFT) {
        SIGNATURE signature = getSignature(_sString, &(pHdata->mapNumbers));
        result.nSize = 1;
        nIndex = signature.nValue;
    } else if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (_compare(_sString, "T")) {
            _sString = _sString.mid(1, -1);

            NUMBER number = readSymNumber(pHdata, _sString, pSymbol->mode);

            if (number.nSize) {
                _sString = _sString.mid(number.nSize, -1);
                result.nValue = number.nValue + 1;
            }

            if (_compare(_sString, "_")) {
                _sString = _sString.mid(1, -1);

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

        // Template-parameter references (T_, T0_, ...) resolve against the template
        // arguments of the enclosing function template. That argument list is the
        // last one appended while parsing the name (nested template lists inside the
        // arguments are appended earlier), so the most-recently-completed list is the
        // active context.
        if (pHdata->listListTemplates.count()) {
            qint32 nCount = pHdata->listListTemplates.last().count();
            bSuccess = (nIndex < nCount);
        }

        if (bSuccess) {
            result.sString = pHdata->listListTemplates.last().at(nIndex);
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

QString XDemangle::ms_parameterToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, const QString &sName, const QString &sPrefix)
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

    // libiberty prints the std iostream/string substitutions with their short
    // typedef names (std::ostream, std::string, ...) everywhere EXCEPT as the
    // class of a constructor/destructor, where the full basic_* template-id is
    // shown (so the ctor/dtor base name is basic_ostream, not ostream).
    if (getSyntaxFromMode(pSymbol->mode) == SYNTAX_ITANIUM) {
        if (nNumberOfNames > 1) {
            if ((pParameter->listDnames.at(nNumberOfNames - 1)._operator == OP_CONSTRUCTOR) ||
                (pParameter->listDnames.at(nNumberOfNames - 1)._operator == OP_DESTRUCTOR)) {
                QString sClass = pParameter->listDnames.at(nNumberOfNames - 2).sName;
                QString sFull;

                if (sClass == "std::istream") {
                    sFull = "std::basic_istream<char, std::char_traits<char> >";
                } else if (sClass == "std::ostream") {
                    sFull = "std::basic_ostream<char, std::char_traits<char> >";
                } else if (sClass == "std::iostream") {
                    sFull = "std::basic_iostream<char, std::char_traits<char> >";
                } else if (sClass == "std::string") {
                    sFull = "std::basic_string<char, std::char_traits<char>, std::allocator<char> >";
                }

                if (sFull != "") {
                    pParameter->listDnames[nNumberOfNames - 2].sName = sFull;
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
            sResult += (pSymbol->mode == MODE_JAVA) ? QString(".") : QString("::");
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

QString XDemangle::ms_getPointerString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, const QString &sName)
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
            sPointer = QString("%1::%2").arg(_sName).arg(sPointer);
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

QString XDemangle::itanium_parameterToString(XDemangle::DSYMBOL *pSymbol, XDemangle::DPARAMETER *pParameter, const QString &sPrefix)
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

        if (pSymbol->mode == MODE_JAVA) {
            // Java never shows pointers: a pointer to a class prints the class name,
            // and JArray<X>* prints X[] (with one [] per pointer/array level).
            QString sInner = itanium_parameterToString(pSymbol, &lastParameter, "");
            QString sSuffix;

            while (sInner.startsWith("JArray<") && sInner.endsWith(">")) {
                sInner = sInner.mid(7, sInner.size() - 8).trimmed();
                sSuffix += "[]";
            }

            sResult = sInner + sSuffix;
        } else {
            QString sPointer = itanium_getPointerString(pSymbol, pParameter);

            sResult = itanium_parameterToString(pSymbol, &lastParameter, sPointer);

            if ((sPointer != "") && (lastParameter.st != ST_FUNCTION)) {
                if ((sPointer.at(0) != QChar('*')) && (sPointer.at(0) != QChar('&'))) {
                    sResult += " ";
                }

                sResult += sPointer;
            }
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

        bool bJava = (pSymbol->mode == MODE_JAVA);

        if (sFuncConvention != "") {
            sResult += QString("%1 ").arg(sFuncConvention);
        }

        QString sReturn;

        if (pParameter->listReturn.count()) {
            DPARAMETER parameter = pParameter->listReturn.at(0);

            sReturn = itanium_parameterToString(pSymbol, &parameter, "");
        }

        // Java prints the return type as a postfix (after the argument list); C++ prints it first.
        if ((sReturn != "") && (!bJava)) {
            sResult += QString("%1 ").arg(sReturn);
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
        } else if (bJava && (sReturn != "")) {
            sResult += "()";  // Java always shows the argument list, even when empty
        }

        if (sQual != "") {
            sResult += QString(" %1").arg(sQual);
        }

        if (bJava && (sReturn != "")) {
            sResult += sReturn;  // postfix return type, no separating space
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

qint32 XDemangle::itanium_demangle_Encoding(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    pParameter->st = ST_VARIABLE;

    qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

    _sString = _sString.mid(nNSSize, -1);
    nResult += nNSSize;

    bool bReturn = false;

    if (pParameter->listDnames.count()) {
        bReturn = pParameter->listDnames.last().bTemplates;  // TODO Check!!!
    }

    qint32 nPSize = itanium_demangle_Function(pSymbol, pHdata, pParameter, _sString, bReturn);

    _sString = _sString.mid(nPSize, -1);
    nResult += nPSize;

    if (nPSize) {
        pParameter->st = ST_FUNCTION;
    }

    if (_compare(_sString, "@") && (pSymbol->mode == MODE_GCC_WIN)) {
        if (pParameter->functionConvention != FC_FASTCALL) {
            pParameter->functionConvention = FC_STDCALL;
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_NameScope(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    if (_compare(_sString, "Z"))  // Local name: Z <encoding> E <local-entity> [<discriminator>]
    {
        nResult++;
        _sString = _sString.mid(1, -1);

        DPARAMETER parameterOuter = {};
        qint32 nESize = itanium_demangle_Encoding(pSymbol, pHdata, &parameterOuter, _sString);

        nResult += nESize;
        _sString = _sString.mid(nESize, -1);

        QString sOuter = itanium_parameterToString(pSymbol, &parameterOuter, "");

        if (_compare(_sString, "E")) {
            nResult++;
            _sString = _sString.mid(1, -1);
        }

        QString sInner;

        if (_compare(_sString, "s")) {  // String literal
            nResult++;
            _sString = _sString.mid(1, -1);

            sInner = "string literal";
        } else if (_compare(_sString, "d")) {  // Parameter (default argument) scope
            nResult++;
            _sString = _sString.mid(1, -1);

            NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);
            nResult += number.nSize;
            _sString = _sString.mid(number.nSize, -1);

            if (_compare(_sString, "_")) {
                nResult++;
                _sString = _sString.mid(1, -1);
            }

            DPARAMETER parameterInner = {};
            qint32 nISize = itanium_demangle_Encoding(pSymbol, pHdata, &parameterInner, _sString);
            nResult += nISize;
            _sString = _sString.mid(nISize, -1);

            sInner = itanium_parameterToString(pSymbol, &parameterInner, "");
        } else {
            DPARAMETER parameterInner = {};
            qint32 nISize = itanium_demangle_Encoding(pSymbol, pHdata, &parameterInner, _sString);
            nResult += nISize;
            _sString = _sString.mid(nISize, -1);

            sInner = itanium_parameterToString(pSymbol, &parameterInner, "");
        }

        // Optional discriminator: _ <number>  or  __ <number> _   (not printed)
        if (_compare(_sString, "_")) {
            nResult++;
            _sString = _sString.mid(1, -1);

            if (_compare(_sString, "_")) {
                nResult++;
                _sString = _sString.mid(1, -1);
            }

            NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);
            nResult += number.nSize;
            _sString = _sString.mid(number.nSize, -1);

            if (_compare(_sString, "_")) {
                nResult++;
                _sString = _sString.mid(1, -1);
            }
        }

        DNAME dname = {};
        dname.sName = sOuter + QString("::") + sInner;

        pParameter->listDnames.append(dname);

        return nResult;
    }

    bool bNested = false;

    if (_compare(_sString, "N")) {
        nResult++;
        _sString = _sString.mid(1, -1);

        bNested = true;
    }

    if (_compare(_sString, "K")) {
        nResult++;
        _sString = _sString.mid(1, -1);

        pParameter->nQualifier = QUAL_CONST;
    }

    QList<QString> listAddString;

    while (_sString != "") {
        //        pHdata->listArgRef.clear();

        DNAME dname = {};

        bool bAdd = true;
        bool bSpecial = false;
        bool bOperator = false;

        if (isReplaceStringPresent(pSymbol, pHdata, _sString)) {
            SIGNATURE signature = getReplaceStringSignature(pSymbol, pHdata, _sString);

            dname.sName = join(&signature.listStrings, (pSymbol->mode == MODE_JAVA) ? QString(".") : QString("::"));

            nResult += signature.nSize;
            _sString = _sString.mid(signature.nSize, -1);

            bAdd = false;
        } else if (_compare(_sString, "St")) {
            nResult += 2;
            _sString = _sString.mid(2, -1);

            dname.sName = "std";

            bAdd = false;
            bSpecial = true;
        } else if (pHdata->mapStd.contains(_sString.left(2))) {
            QString sStd = pHdata->mapStd.value(_sString.left(2));

            nResult += 2;
            _sString = _sString.mid(2, -1);

            dname.sName = sStd;

            bAdd = false;
            bSpecial = false;
        } else if (_compare(_sString, "cv"))  // Conversion
        {
            nResult += 2;
            _sString = _sString.mid(2, -1);

            DPARAMETER parameter = {};

            qint32 nTSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, _sString);

            nResult += nTSize;
            _sString = _sString.mid(nTSize, -1);

            dname.sName = QString("operator %1").arg(itanium_parameterToString(pSymbol, &parameter, ""));

            // TODO _
        } else if (isSignaturePresent(_sString, &(pHdata->mapOperators))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapOperators));

            dname._operator = (OP)signature.nValue;

            nResult += signature.nSize;
            _sString = _sString.mid(signature.nSize, -1);

            bOperator = true;
        } else {
            STRING string = readString(pHdata, _sString, pSymbol->mode);

            dname.sName = string.sString;

            nResult += string.nSize;
            _sString = _sString.mid(string.nSize, -1);

            if (string.nSize == 0) {
                pSymbol->bIsValid = false;
            }
        }

        if (bOperator) {
            listAddString.append(operatorIdToString(dname._operator, pSymbol->mode));
        } else {
            listAddString.append(dname.sName);
        }

        if (_compare(_sString, "I"))  // Template
        {
            nResult++;
            _sString = _sString.mid(1, -1);

            if (bAdd) {
                addStringListRef(pSymbol, pHdata, listAddString);
            }

            bAdd = true;

            DPARAMETER parameter = {};
            parameter.st = ST_TEMPLATE;
            qint32 nPSize = itanium_demangle_Parameters(pSymbol, pHdata, &parameter, _sString);

            nResult += nPSize;
            _sString = _sString.mid(nPSize, -1);

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

        if (_compare(_sString, "B"))  // abi::source
        {
            nResult++;
            _sString = _sString.mid(1, -1);

            STRING string = readString(pHdata, _sString, pSymbol->mode);

            dname.sName += QString("[abi:%1]").arg(string.sString);

            nResult += string.nSize;
            _sString = _sString.mid(string.nSize, -1);
        }

        pParameter->listDnames.append(dname);

        if (bNested && _compare(_sString, "E")) {
            nResult++;
            _sString = _sString.mid(1, -1);

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

qint32 XDemangle::itanium_demangle_Function(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString,
                                            bool bReturn)
{
    QString _sString = sString;
    qint32 nResult = 0;

    // GCJ (Java) marks a function type that carries an explicit return type with a
    // leading 'J' at the bare-function-type position: J <return-type> <arg-types>.
    if (_compare(_sString, "J")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);
        bReturn = true;
    }

    if (bReturn) {
        DPARAMETER parameter = {};

        qint32 nRSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, _sString);

        pParameter->listReturn.append(parameter);

        nResult += nRSize;
        _sString = _sString.mid(nRSize, -1);
    }

    qint32 nFSize = itanium_demangle_Parameters(pSymbol, pHdata, pParameter, _sString);

    nResult += nFSize;
    _sString = _sString.mid(nFSize, -1);

    return nResult;
}

qint32 XDemangle::itanium_demangle_Parameters(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    while (_sString != "") {
        // Empty parameter list (e.g. the outer encoding of a local name "Z <encoding> E ..."):
        // stop before consuming the terminator that belongs to the enclosing construct.
        if (_compare(_sString, "E")) {
            break;
        }

        DPARAMETER parameter = {};

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);

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

        if (_compare(_sString, "E")) {
            nResult++;
            _sString = _sString.mid(1, -1);

            break;
        }

        if (_compare(_sString, "@") && (pSymbol->mode == MODE_GCC_WIN)) {
            break;
        }
    }

    return nResult;
}

qint32 XDemangle::itanium_demangle_Type(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
{
    QString _sString = sString;
    qint32 nResult = 0;

    bool bAdd = true;

    if (isReplaceArgPresent(pSymbol, pHdata, _sString)) {
        SIGNATURE signature = getReplaceArgSignature(pSymbol, pHdata, _sString);

        DNAME dname = {};
        dname.sName = signature.sString;

        pParameter->listDnames.append(dname);

        pParameter->st = ST_NAME;

        nResult += signature.nSize;
        _sString = _sString.mid(signature.nSize, -1);
    } else if (isSignaturePresent(_sString, &(pHdata->mapPointerTypes)))  // Pointers
    {
        qint32 nPSize = itanium_demangle_PointerType(pSymbol, pHdata, pParameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    } else if (_compare(_sString, "U")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        pParameter->st = ST_TARGET;

        qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

        nResult += nNSSize;
        _sString = _sString.mid(nNSSize, -1);

        DPARAMETER parameter = {};

        qint32 nTSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, _sString);

        pParameter->listTarget.append(parameter);

        nResult += nTSize;
        _sString = _sString.mid(nTSize, -1);
    } else if (_compare(_sString, "A"))  // Array
    {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        NUMBER number = readNumber(pHdata, _sString, pSymbol->mode);
        pParameter->listIndexes.append(number.nValue);

        nResult += number.nSize;
        _sString = _sString.mid(number.nSize, -1);

        pParameter->st = ST_POINTER;

        if (_compare(_sString, "_")) {
            nResult += 1;
            _sString = _sString.mid(1, -1);
        } else {
            pSymbol->bIsValid = false;
        }

        DPARAMETER parameter = {};

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);

        pParameter->listPointer.append(parameter);
    } else if (_compare(_sString, "F"))  // Function
    {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        pParameter->st = ST_FUNCTION;

        qint32 nFSize = itanium_demangle_Function(pSymbol, pHdata, pParameter, _sString, true);

        nResult += nFSize;
        _sString = _sString.mid(nFSize, -1);
    } else if (_compare(_sString, "M"))  // Pointer to member
    {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        pParameter->st = ST_POINTER;

        DPARAMETER parameterClass = {};

        qint32 nClassSize = itanium_demangle_Type(pSymbol, pHdata, &parameterClass, _sString);

        nResult += nClassSize;
        _sString = _sString.mid(nClassSize, -1);

        DPARAMETER parameterMember = {};

        qint32 nMemberSize = itanium_demangle_Type(pSymbol, pHdata, &parameterMember, _sString);

        nResult += nMemberSize;
        _sString = _sString.mid(nMemberSize, -1);

        parameterMember.listClass.append(parameterClass);
        pParameter->listPointer.append(parameterMember);
    } else if (_compare(_sString, "L"))  // Const
    {
        pParameter->st = ST_CONST;
        nResult += 1;
        _sString = _sString.mid(1, -1);

        qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

        if (nNSSize) {
            nResult += nNSSize;
            _sString = _sString.mid(nNSSize, -1);

            NUMBER number = readNumberS(pHdata, _sString, pSymbol->mode);

            pParameter->varConst = number.nValue;

            nResult += number.nSize;
            _sString = _sString.mid(number.nSize, -1);
        } else if (isSignaturePresent(_sString, &(pHdata->mapTypes))) {
            SIGNATURE signature = getSignature(_sString, &(pHdata->mapTypes));

            pParameter->typeConst = (XTYPE)signature.nValue;

            nResult += signature.nSize;
            _sString = _sString.mid(signature.nSize, -1);

            NUMBER number = readNumberS(pHdata, _sString, pSymbol->mode);

            pParameter->varConst = number.nValue;

            nResult += number.nSize;
            _sString = _sString.mid(number.nSize, -1);

            pSymbol->bIsValid = true;
        } else {
#ifdef QT_DEBUG
            qDebug("TODO: unknown const %s", _sString.toLatin1().data());
#endif
            pSymbol->bIsValid = false;
        }

        if (_compare(_sString, "E")) {
            nResult += 1;
            _sString = _sString.mid(1, -1);
        }
    } else if (_compare(_sString, "X")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        qint32 nTSize = itanium_demangle_Type(pSymbol, pHdata, pParameter, _sString);

        nResult += nTSize;
        _sString = _sString.mid(nTSize, -1);

        if (_compare(_sString, "E")) {
            nResult += 1;
            _sString = _sString.mid(1, -1);
        }
    } else if (_compare(_sString, "J")) {
        nResult += 1;
        _sString = _sString.mid(1, -1);

        //        pSymbol->bIsValid=true;

        DPARAMETER parameter = {};
        parameter.st = ST_TEMPLATE;
        qint32 nPSize = itanium_demangle_Parameters(pSymbol, pHdata, &parameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);

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

        if (_compare(_sString, "E")) {
            nResult += 1;
            _sString = _sString.mid(1, -1);
        }
    } else if (_compare(_sString, "Dp")) {
        nResult += 2;
        _sString = _sString.mid(2, -1);

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, pParameter, _sString);
        pParameter->st = ST_PACKEDTYPE;

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);
    } else if (isSignaturePresent(_sString, &(pHdata->mapTypes)))  // Simple types
    {
        pParameter->st = ST_TYPE;
        SIGNATURE signatureType = getSignature(_sString, &(pHdata->mapTypes));
        pParameter->type = (XTYPE)signatureType.nValue;

        nResult += signatureType.nSize;
        _sString = _sString.mid(signatureType.nSize, -1);
    } else if (_compare(_sString, "@")) {
        if (pSymbol->mode != MODE_GCC_WIN) {
            pSymbol->bIsValid = false;
        }
    } else {
        pParameter->st = ST_NAME;

        if (isReplaceStringPresent(pSymbol, pHdata, _sString)) {
            bAdd = false;
        }

        qint32 nNSSize = itanium_demangle_NameScope(pSymbol, pHdata, pParameter, _sString);

        if (pHdata->mapStd.contains(_sString.left(2)) && (nNSSize == 2)) {
            bAdd = false;
        }

        nResult += nNSSize;
        _sString = _sString.mid(nNSSize, -1);

        if (nNSSize == 0) {
#ifdef QT_DEBUG
            qDebug("TODO: type %s", _sString.toLatin1().data());
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

qint32 XDemangle::itanium_demangle_PointerType(XDemangle::DSYMBOL *pSymbol, XDemangle::HDATA *pHdata, XDemangle::DPARAMETER *pParameter, const QString &sString)
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

        qint32 nPSize = itanium_demangle_Type(pSymbol, pHdata, &parameter, _sString);

        nResult += nPSize;
        _sString = _sString.mid(nPSize, -1);

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

// --- Watcom (Open Watcom C++) -------------------------------------------------
//
// Grammar (as emitted by the Open Watcom C++ compiler, see bld/lib_misc/c/demangle.c):
//
//   symbol      := 'W?' scoped-name type
//   scoped-name := name ( ':' scope )*                     ( scopes read inner -> outer )
//   name        := identifier '$' | digit | '$' operator   ( digit = replicate back-reference )
//   scope       := name | ':' template-args                ( '::' introduces template args )
//   type        := ( 'p'|'r' ) mem-model type              ( pointer / reference )
//                | '[' base10 ']' type                     ( array; leading dim omitted )
//                | ( 'x'|'y' ) type                        ( const / volatile )
//                | ( 'n'|'f'|'g'|'h' ) type                ( near / far / far16 / huge )
//                | '(' type* ')' type                      ( function: params then return )
//                | '$' scoped-name '$'                     ( class / struct / union / enum )
//                | '_'                                     ( no type - ctor / dtor )
//                | base-type                               ( a c s i l z b d t q w e v, u-prefixed )
//
// Every fresh identifier (name/scope/class) is registered in listStringRef; a single
// decimal digit 0..9 is a back-reference into that list. Integers use base-32 with a
// 'z' (positive) / 'y' (negative) terminator; array dimensions use base-10.

XDemangle::DSYMBOL XDemangle::watcom_getSymbol(const QString &sString, XDemangle::MODE mode)
{
    DSYMBOL result = {};
    result.mode = mode;

    if (!_compare(sString, "W?")) {
        return result;  // bIsValid stays false
    }

    result.bIsValid = true;

    HDATA hdata = getHdata(mode);

    qint32 nPos = 2;  // skip "W?"

    QString sName = watcom_parseScopedName(&result, &hdata, sString, &nPos, true);

    if (!result.bIsValid) {
        return result;
    }

    QString sFull = watcom_parseType(&result, &hdata, sString, &nPos, sName);

    if (!result.bIsValid) {
        return result;
    }

    result.nSize = nPos;
    result.sResult = sFull;

    return result;
}

QString XDemangle::watcom_parseScopedName(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos, bool bAllowOperator)
{
    QList<QString> listChain;
    OP _operator = OP_UNKNOWN;
    bool bOperatorLike = false;

    QChar cFirst = watcom_charAt(sString, *pnPos);

    if (bAllowOperator && (cFirst == QChar('$'))) {
        // Operator or special member (schema: mapOperators)
        QString sRem = sString.mid(*pnPos);

        if (isSignaturePresent(sRem, &(pHdata->mapOperators))) {
            SIGNATURE signature = getSignature(sRem, &(pHdata->mapOperators));
            _operator = (OP)signature.nValue;
            *pnPos += signature.nSize;
            bOperatorLike = true;
            listChain.append("");  // placeholder, resolved once the class scope is known
        } else {
            pSymbol->bIsValid = false;  // unsupported special symbol (e.g. $W vtable / typeinfo)
            return "";
        }
    } else {
        QString sName = watcom_parseName(pSymbol, pHdata, sString, pnPos);

        if (!pSymbol->bIsValid) {
            return "";
        }

        listChain.append(sName);
    }

    // Scope chain (each ':' introduces an enclosing scope; '::' introduces template arguments)
    while (watcom_charAt(sString, *pnPos) == QChar(':')) {
        *pnPos += 1;  // consume ':'

        QChar cScope = watcom_charAt(sString, *pnPos);

        if (cScope == QChar(':')) {  // template arguments - attach to the most recent element
            *pnPos += 1;             // consume second ':'

            QString sTemplate = watcom_parseTemplateArgs(pSymbol, pHdata, sString, pnPos);

            if (!pSymbol->bIsValid) {
                return "";
            }

            if (!listChain.isEmpty()) {
                listChain.last() += sTemplate;
            }
        } else if (cScope == QChar('?')) {  // embedded mangled name - not supported
            pSymbol->bIsValid = false;
            return "";
        } else {
            QString sScope = watcom_parseName(pSymbol, pHdata, sString, pnPos);

            if (!pSymbol->bIsValid) {
                return "";
            }

            listChain.append(sScope);
        }
    }

    // Resolve operator / constructor / destructor names (constructor and destructor
    // borrow the enclosing class name, which is only known after the scopes are read)
    if (bOperatorLike) {
        QString sClass;

        if (listChain.count() >= 2) {
            sClass = listChain.at(1);

            qint32 nTemplate = sClass.indexOf(QChar('<'));

            if (nTemplate >= 0) {
                sClass = sClass.left(nTemplate);
            }
        }

        QString sName = operatorIdToString(_operator, pSymbol->mode);

        if (_operator == OP_CONSTRUCTOR) {
            sName = sClass;
        } else if (_operator == OP_DESTRUCTOR) {
            sName = QString("~") + sClass;
        }

        listChain[0] = sName;
    }

    return watcom_renderQualified(listChain);
}

QString XDemangle::watcom_parseName(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos)
{
    QString sResult;

    QChar cFirst = watcom_charAt(sString, *pnPos);

    if ((cFirst >= QChar('0')) && (cFirst <= QChar('9'))) {
        // Back-reference (replicate index 0..9)
        qint32 nIndex = watcom_charToDigit(cFirst);
        *pnPos += 1;

        if ((nIndex >= 0) && (nIndex < pHdata->listStringRef.count())) {
            sResult = pHdata->listStringRef.at(nIndex);
        } else {
            pSymbol->bIsValid = false;
        }
    } else {
        qint32 nStart = *pnPos;

        while (watcom_isIdentifierChar(watcom_charAt(sString, *pnPos))) {
            *pnPos += 1;
        }

        if ((*pnPos > nStart) && (watcom_charAt(sString, *pnPos) == QChar('$'))) {
            sResult = sString.mid(nStart, *pnPos - nStart);
            *pnPos += 1;  // consume '$'

            pHdata->listStringRef.append(sResult);  // register for later back-references
        } else {
            pSymbol->bIsValid = false;
        }
    }

    return sResult;
}

QString XDemangle::watcom_parseTemplateArgs(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos)
{
    QList<QString> listArgs;

    while (pSymbol->bIsValid) {
        QChar c = watcom_charAt(sString, *pnPos);

        if (c == QChar('1')) {  // type argument
            *pnPos += 1;

            QString sType = watcom_parseType(pSymbol, pHdata, sString, pnPos, "");

            if (!pSymbol->bIsValid) {
                break;
            }

            listArgs.append(sType);
        } else if (c == QChar('0')) {  // integer argument
            *pnPos += 1;

            qint64 nValue = watcom_parseBase32(sString, pnPos);
            QChar cTerm = watcom_charAt(sString, *pnPos);

            if (cTerm == QChar('z')) {  // positive
                *pnPos += 1;
                listArgs.append(QString::number(nValue));
            } else if (cTerm == QChar('y')) {  // negative
                *pnPos += 1;
                listArgs.append(QString::number(-nValue));
            } else {
                pSymbol->bIsValid = false;
                break;
            }
        } else {
            break;  // end of template argument list
        }
    }

    return QString("<") + join(&listArgs, ", ") + QString(">");
}

QString XDemangle::watcom_parseType(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos, const QString &sCore)
{
    if (!pSymbol->bIsValid) {
        return sCore;
    }

    QChar c = watcom_charAt(sString, *pnPos);

    if (c == QChar('\0')) {
        pSymbol->bIsValid = false;
        return sCore;
    }

    QString sRem = sString.mid(*pnPos);

    // Pointer / reference (schema: mapPointerTypes)
    if (isSignaturePresent(sRem, &(pHdata->mapPointerTypes))) {
        SIGNATURE signature = getSignature(sRem, &(pHdata->mapPointerTypes));
        *pnPos += signature.nSize;

        QString sSym = (signature.nValue & QUAL_REFERENCE) ? QString("&") : QString("*");

        // Memory model of the pointer itself (schema: mapStorageClasses)
        QString sMem;
        QString sRem2 = sString.mid(*pnPos);

        if (isSignaturePresent(sRem2, &(pHdata->mapStorageClasses))) {
            SIGNATURE signatureMem = getSignature(sRem2, &(pHdata->mapStorageClasses));
            sMem = watcom_memoryModelString((SC)signatureMem.nValue);
            *pnPos += signatureMem.nSize;
        }

        QString sNewCore = sMem + sSym + sCore;

        if (watcom_pointeeNeedsParen(sString, *pnPos)) {
            sNewCore = QString("(") + sNewCore + QString(")");
        }

        return watcom_parseType(pSymbol, pHdata, sString, pnPos, sNewCore);
    }

    // Array(s) - the leading dimension is omitted by the compiler
    if (c == QChar('[')) {
        QString sDims;

        while (watcom_charAt(sString, *pnPos) == QChar('[')) {
            *pnPos += 1;

            QString sDim;

            if (watcom_charAt(sString, *pnPos) != QChar(']')) {
                sDim = QString::number(watcom_parseBase10(sString, pnPos));
            }

            if (watcom_charAt(sString, *pnPos) == QChar(']')) {
                *pnPos += 1;
            } else {
                pSymbol->bIsValid = false;
                return sCore;
            }

            sDims += QString("[") + sDim + QString("]");
        }

        return watcom_parseType(pSymbol, pHdata, sString, pnPos, sCore + sDims);
    }

    // const / volatile (schema: mapQualifiers)
    if (isSignaturePresent(sRem, &(pHdata->mapQualifiers))) {
        SIGNATURE signature = getSignature(sRem, &(pHdata->mapQualifiers));
        *pnPos += signature.nSize;

        QString sQualifier = (signature.nValue & QUAL_CONST) ? QString("const ") : QString("volatile ");
        QString sInner = watcom_parseType(pSymbol, pHdata, sString, pnPos, sCore);

        return sQualifier + sInner;
    }

    // Object / pointer memory model (schema: mapStorageClasses)
    if (isSignaturePresent(sRem, &(pHdata->mapStorageClasses))) {
        SIGNATURE signature = getSignature(sRem, &(pHdata->mapStorageClasses));
        *pnPos += signature.nSize;

        QString sPrefix = watcom_memoryModelString((SC)signature.nValue);
        QString sInner = watcom_parseType(pSymbol, pHdata, sString, pnPos, sCore);

        return sPrefix + sInner;
    }

    // Function: '(' parameters ')' return-type
    if (c == QChar('(')) {
        *pnPos += 1;

        QList<QString> listParams;

        while ((watcom_charAt(sString, *pnPos) != QChar(')')) && pSymbol->bIsValid) {
            qint32 nPrev = *pnPos;

            QString sParam = watcom_parseType(pSymbol, pHdata, sString, pnPos, "");

            if (!pSymbol->bIsValid) {
                break;
            }

            if (*pnPos == nPrev) {  // no progress - avoid an infinite loop on malformed input
                pSymbol->bIsValid = false;
                break;
            }

            listParams.append(sParam);
        }

        if (!pSymbol->bIsValid) {
            return sCore;
        }

        if (watcom_charAt(sString, *pnPos) == QChar(')')) {
            *pnPos += 1;
        } else {
            pSymbol->bIsValid = false;
            return sCore;
        }

        QString sParams = join(&listParams, ", ");
        QString sCore2 = sCore + QString("(") + sParams + QString(")");

        return watcom_parseType(pSymbol, pHdata, sString, pnPos, sCore2);
    }

    // Class / struct / union / enum by (possibly scoped) name
    if (c == QChar('$')) {
        *pnPos += 1;

        QString sName = watcom_parseScopedName(pSymbol, pHdata, sString, pnPos, false);

        if (!pSymbol->bIsValid) {
            return sCore;
        }

        if (watcom_charAt(sString, *pnPos) == QChar('$')) {
            *pnPos += 1;
        } else {
            pSymbol->bIsValid = false;
            return sCore;
        }

        return watcom_joinBaseCore(sName, sCore);
    }

    // No type - constructor / destructor return placeholder
    if (c == QChar('_')) {
        *pnPos += 1;
        return sCore;
    }

    // Base type (schema: mapTypes)
    if (isSignaturePresent(sRem, &(pHdata->mapTypes))) {
        SIGNATURE signature = getSignature(sRem, &(pHdata->mapTypes));
        *pnPos += signature.nSize;

        QString sBase = typeIdToString((XTYPE)signature.nValue, pSymbol->mode);

        return watcom_joinBaseCore(sBase, sCore);
    }

    pSymbol->bIsValid = false;
    return sCore;
}

qint64 XDemangle::watcom_parseBase32(const QString &sString, qint32 *pnPos)
{
    qint64 nValue = 0;

    while (true) {
        qint32 nDigit = watcom_charToDigit(watcom_charAt(sString, *pnPos));

        if ((nDigit < 0) || (nDigit >= 32)) {
            break;
        }

        nValue = nValue * 32 + nDigit;
        *pnPos += 1;
    }

    return nValue;
}

qint64 XDemangle::watcom_parseBase10(const QString &sString, qint32 *pnPos)
{
    qint64 nValue = 0;

    while (true) {
        QChar c = watcom_charAt(sString, *pnPos);

        if ((c < QChar('0')) || (c > QChar('9'))) {
            break;
        }

        nValue = nValue * 10 + (qint32)(c.unicode() - '0');
        *pnPos += 1;
    }

    return nValue;
}

QChar XDemangle::watcom_charAt(const QString &sString, qint32 nPos)
{
    QChar cResult = QChar('\0');

    if ((nPos >= 0) && (nPos < sString.size())) {
        cResult = sString.at(nPos);
    }

    return cResult;
}

qint32 XDemangle::watcom_charToDigit(QChar cChar)
{
    qint32 nResult = -1;

    char16_t nUnicode = cChar.unicode();

    if ((nUnicode >= '0') && (nUnicode <= '9')) {
        nResult = (qint32)(nUnicode - '0');
    } else if ((nUnicode >= 'A') && (nUnicode <= 'Z')) {
        nResult = (qint32)(nUnicode - 'A' + 10);
    } else if ((nUnicode >= 'a') && (nUnicode <= 'z')) {
        nResult = (qint32)(nUnicode - 'a' + 10);
    }

    return nResult;
}

bool XDemangle::watcom_isIdentifierChar(QChar cChar)
{
    char16_t nUnicode = cChar.unicode();

    return (((nUnicode >= 'A') && (nUnicode <= 'Z')) || ((nUnicode >= 'a') && (nUnicode <= 'z')) || ((nUnicode >= '0') && (nUnicode <= '9')) || (nUnicode == '_'));
}

bool XDemangle::watcom_pointeeNeedsParen(const QString &sString, qint32 nPos)
{
    qint32 i = nPos;
    QChar c = watcom_charAt(sString, i);

    // Skip memory-model and cv qualifiers - they do not change the declarator precedence
    while ((c == QChar('n')) || (c == QChar('f')) || (c == QChar('g')) || (c == QChar('h')) || (c == QChar('x')) || (c == QChar('y'))) {
        i += 1;
        c = watcom_charAt(sString, i);
    }

    // A pointer to an array or to a function needs parentheses around the declarator
    return ((c == QChar('[')) || (c == QChar('(')));
}

QString XDemangle::watcom_memoryModelString(XDemangle::SC storageClass)
{
    QString sResult;

    switch (storageClass) {
        case SC_NEAR: sResult = QString(""); break;
        case SC_FAR: sResult = QString("__far "); break;
        case SC_HUGE: sResult = QString("__huge "); break;
        default: sResult = QString(""); break;
    }

    return sResult;
}

QString XDemangle::watcom_joinBaseCore(const QString &sBase, const QString &sCore)
{
    QString sResult = sBase;

    if (sCore != "") {
        sResult += QString(" ") + sCore;
    }

    return sResult;
}

QString XDemangle::watcom_renderQualified(const QList<QString> &listChain)
{
    QString sResult;

    qint32 nCount = listChain.count();

    for (qint32 i = nCount - 1; i >= 1; i--) {
        sResult += listChain.at(i) + QString("::");
    }

    if (nCount > 0) {
        sResult += listChain.at(0);
    }

    return sResult;
}

// --- GNAT / Ada --------------------------------------------------------------
//
// Native port of libiberty's ada_demangle. Ada unit names are lower-case and
// dot-separated; the mangling uses '__' as the package separator, 'O<op>' for
// operator names, and a handful of uppercase suffixes (TK task bodies, S<x>
// stream ops, D<x> controlled ops, X body-nested, __<digits> overload numbers,
// ___elabs/etc. special names). Encoding documented in gcc/ada/exp_dbug.ads.

bool XDemangle::gnat_isLower(QChar cChar)
{
    char16_t nUnicode = cChar.unicode();

    return ((nUnicode >= 'a') && (nUnicode <= 'z'));
}

bool XDemangle::gnat_isDigit(QChar cChar)
{
    char16_t nUnicode = cChar.unicode();

    return ((nUnicode >= '0') && (nUnicode <= '9'));
}

bool XDemangle::gnat_demangleName(const QString &sMangled, QString *psResult)
{
    static const char *const operators[][2] = {{"Oabs", "abs"},  {"Oand", "and"},    {"Omod", "mod"},  {"Onot", "not"},  {"Oor", "or"},
                                               {"Orem", "rem"},  {"Oxor", "xor"},    {"Oeq", "="},     {"One", "/="},    {"Olt", "<"},
                                               {"Ole", "<="},    {"Ogt", ">"},       {"Oge", ">="},    {"Oadd", "+"},    {"Osubtract", "-"},
                                               {"Oconcat", "&"}, {"Omultiply", "*"}, {"Odivide", "/"}, {"Oexpon", "**"}, {nullptr, nullptr}};

    static const char *const special[][2] = {{"_elabb", "'Elab_Body"},     {"_elabs", "'Elab_Spec"}, {"_size", "'Size"},
                                             {"_alignment", "'Alignment"}, {"_assign", ".\":=\""},   {nullptr, nullptr}};

    QString d;
    qint32 p = 0;

    if (!gnat_isLower(watcom_charAt(sMangled, 0))) {
        return false;
    }

    while (true) {
        QChar c = watcom_charAt(sMangled, p);

        if (gnat_isLower(c)) {
            // An identifier, which is always lower case.
            do {
                d += sMangled.at(p);
                p++;
            } while (gnat_isLower(watcom_charAt(sMangled, p)) || gnat_isDigit(watcom_charAt(sMangled, p)) ||
                     ((watcom_charAt(sMangled, p) == QChar('_')) && (gnat_isLower(watcom_charAt(sMangled, p + 1)) || gnat_isDigit(watcom_charAt(sMangled, p + 1)))));
        } else if (c == QChar('O')) {
            // An operator name.
            bool bFound = false;

            for (qint32 k = 0; operators[k][0] != nullptr; k++) {
                QString sOp = QString(operators[k][0]);

                if (sMangled.mid(p).startsWith(sOp)) {
                    p += sOp.size();
                    d += QChar('"') + QString(operators[k][1]) + QChar('"');
                    bFound = true;
                    break;
                }
            }

            if (!bFound) {
                return false;
            }
        } else {
            return false;
        }

        // The name can be directly followed by some uppercase letters.
        if ((watcom_charAt(sMangled, p) == QChar('T')) && (watcom_charAt(sMangled, p + 1) == QChar('K'))) {
            if ((watcom_charAt(sMangled, p + 2) == QChar('B')) && (watcom_charAt(sMangled, p + 3) == QChar('\0'))) {
                break;  // Subprogram for task body.
            } else if ((watcom_charAt(sMangled, p + 2) == QChar('_')) && (watcom_charAt(sMangled, p + 3) == QChar('_'))) {
                p += 4;  // Inner declarations in a task.
                d += QChar('.');
                continue;
            } else {
                return false;
            }
        }

        if ((watcom_charAt(sMangled, p) == QChar('E')) && (watcom_charAt(sMangled, p + 1) == QChar('\0'))) {
            return false;  // Exception name.
        }

        if (((watcom_charAt(sMangled, p) == QChar('P')) || (watcom_charAt(sMangled, p) == QChar('N'))) && (watcom_charAt(sMangled, p + 1) == QChar('\0'))) {
            break;  // Protected type subprogram.
        }

        if (((watcom_charAt(sMangled, p) == QChar('N')) || (watcom_charAt(sMangled, p) == QChar('S'))) && (watcom_charAt(sMangled, p + 1) == QChar('\0'))) {
            return false;  // Enumerated type name table.
        }

        if (watcom_charAt(sMangled, p) == QChar('X')) {
            // Body nested.
            p++;

            while ((watcom_charAt(sMangled, p) == QChar('n')) || (watcom_charAt(sMangled, p) == QChar('b'))) {
                p++;
            }
        }

        if ((watcom_charAt(sMangled, p) == QChar('S')) && (watcom_charAt(sMangled, p + 1) != QChar('\0')) &&
            ((watcom_charAt(sMangled, p + 2) == QChar('_')) || (watcom_charAt(sMangled, p + 2) == QChar('\0')))) {
            // Stream operations.
            QString sName;
            QChar cStream = watcom_charAt(sMangled, p + 1);

            if (cStream == QChar('R')) {
                sName = "'Read";
            } else if (cStream == QChar('W')) {
                sName = "'Write";
            } else if (cStream == QChar('I')) {
                sName = "'Input";
            } else if (cStream == QChar('O')) {
                sName = "'Output";
            } else {
                return false;
            }

            p += 2;
            d += sName;
        } else if (watcom_charAt(sMangled, p) == QChar('D')) {
            // Controlled type operation.
            QString sName;
            QChar cCtrl = watcom_charAt(sMangled, p + 1);

            if (cCtrl == QChar('F')) {
                sName = ".Finalize";
            } else if (cCtrl == QChar('A')) {
                sName = ".Adjust";
            } else {
                return false;
            }

            d += sName;
            break;
        }

        if (watcom_charAt(sMangled, p) == QChar('_')) {
            // Separator.
            QChar cNext = watcom_charAt(sMangled, p + 1);

            if (cNext == QChar('_')) {
                // Standard separator.
                p += 2;

                if (gnat_isDigit(watcom_charAt(sMangled, p))) {
                    // Overloading number.
                    do {
                        p++;
                    } while (gnat_isDigit(watcom_charAt(sMangled, p)) || ((watcom_charAt(sMangled, p) == QChar('_')) && gnat_isDigit(watcom_charAt(sMangled, p + 1))));

                    if (watcom_charAt(sMangled, p) == QChar('X')) {
                        p++;

                        while ((watcom_charAt(sMangled, p) == QChar('n')) || (watcom_charAt(sMangled, p) == QChar('b'))) {
                            p++;
                        }
                    }
                } else if ((watcom_charAt(sMangled, p) == QChar('_')) && (watcom_charAt(sMangled, p + 1) != QChar('_'))) {
                    // Special names.
                    bool bFound = false;

                    for (qint32 k = 0; special[k][0] != nullptr; k++) {
                        QString sSpecial = QString(special[k][0]);

                        if (sMangled.mid(p).startsWith(sSpecial)) {
                            p += sSpecial.size();
                            d += QString(special[k][1]);
                            bFound = true;
                            break;
                        }
                    }

                    if (bFound) {
                        break;
                    } else {
                        return false;
                    }
                } else {
                    d += QChar('.');
                    continue;
                }
            } else if ((cNext == QChar('B')) || (cNext == QChar('E'))) {
                // Entry Body or barrier Evaluation.
                p += 2;

                while (gnat_isDigit(watcom_charAt(sMangled, p))) {
                    p++;
                }

                if ((watcom_charAt(sMangled, p) == QChar('s')) && (watcom_charAt(sMangled, p + 1) == QChar('\0'))) {
                    break;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        if ((watcom_charAt(sMangled, p) == QChar('.')) && gnat_isDigit(watcom_charAt(sMangled, p + 1))) {
            // Nested subprogram.
            p += 2;

            while (gnat_isDigit(watcom_charAt(sMangled, p))) {
                p++;
            }
        }

        if (watcom_charAt(sMangled, p) == QChar('\0')) {
            break;  // End of mangled name.
        } else {
            return false;
        }
    }

    *psResult = d;

    return true;
}

QString XDemangle::gnat_demangle(const QString &sString)
{
    QString sMangled = sString;

    // Discard leading _ada_, which is used for library level subprograms.
    if (sMangled.startsWith("_ada_")) {
        sMangled = sMangled.mid(5);
    }

    QString sResult;

    if (gnat_demangleName(sMangled, &sResult)) {
        return sResult;
    }

    return QString("<") + sMangled + QString(">");
}

// --- Haskell (GHC Z-encoding) -------------------------------------------------
//
// Decodes GHC's Z-encoding (compiler/GHC/Utils/Encoding.hs): 'z'/'Z' introduce
// escapes, e.g. zi -> '.', zm -> '-', ZL -> '(', z<hex>U -> a code point,
// Z<n>T -> an n-tuple constructor. A literal 'z' in the source is encoded 'zz'.

QString XDemangle::haskell_demangle(const QString &sString)
{
    QString sResult;
    qint32 nLen = sString.size();
    qint32 i = 0;

    while (i < nLen) {
        QChar c = sString.at(i);

        if ((c == QChar('Z')) && (i + 1 < nLen)) {
            QChar d = sString.at(i + 1);

            if ((d >= QChar('0')) && (d <= QChar('9'))) {
                // Tuple: Z<digits>(T|H)  (the T/H terminates the escape).
                qint32 j = i + 1;
                qint64 n = 0;

                while ((j < nLen) && (sString.at(j) >= QChar('0')) && (sString.at(j) <= QChar('9'))) {
                    n = n * 10 + (sString.at(j).unicode() - '0');
                    j++;
                }

                if ((j < nLen) && (sString.at(j) == QChar('T'))) {
                    if (n == 0) {
                        sResult += "()";
                    } else {
                        sResult += "(";
                        for (qint64 k = 0; k < n - 1; k++) sResult += ",";
                        sResult += ")";
                    }
                    i = j + 1;
                } else if ((j < nLen) && (sString.at(j) == QChar('H'))) {
                    if (n == 1) {
                        sResult += "(# #)";
                    } else {
                        sResult += "(#";
                        for (qint64 k = 0; k < n - 1; k++) sResult += ",";
                        sResult += "#)";
                    }
                    i = j + 1;
                } else {
                    sResult += c;
                    i++;
                }
            } else {
                QChar r = d;
                if (d == QChar('L')) r = QChar('(');
                else if (d == QChar('R')) r = QChar(')');
                else if (d == QChar('M')) r = QChar('[');
                else if (d == QChar('N')) r = QChar(']');
                else if (d == QChar('C')) r = QChar(':');
                else if (d == QChar('Z')) r = QChar('Z');
                sResult += r;
                i += 2;
            }
        } else if ((c == QChar('z')) && (i + 1 < nLen)) {
            QChar d = sString.at(i + 1);

            if ((d >= QChar('0')) && (d <= QChar('9'))) {
                // Numeric escape: z<hex>U
                qint32 j = i + 1;
                qint64 n = 0;

                while (j < nLen) {
                    qint32 hv = watcom_charToDigit(sString.at(j));
                    if ((hv < 0) || (hv >= 16)) break;
                    n = n * 16 + hv;
                    j++;
                }

                if ((j < nLen) && (sString.at(j) == QChar('U'))) {
                    if (n <= 0xFFFF) {
                        sResult += QChar((char16_t)n);
                    } else {
                        char32_t cp = (char32_t)n;
                        sResult += QString::fromUcs4(&cp, 1);
                    }
                    i = j + 1;
                } else {
                    sResult += c;
                    i++;
                }
            } else {
                QChar r = d;
                switch (d.unicode()) {
                    case 'z': r = QChar('z'); break;
                    case 'a': r = QChar('&'); break;
                    case 'b': r = QChar('|'); break;
                    case 'c': r = QChar('^'); break;
                    case 'd': r = QChar('$'); break;
                    case 'e': r = QChar('='); break;
                    case 'g': r = QChar('>'); break;
                    case 'h': r = QChar('#'); break;
                    case 'i': r = QChar('.'); break;
                    case 'l': r = QChar('<'); break;
                    case 'm': r = QChar('-'); break;
                    case 'n': r = QChar('!'); break;
                    case 'p': r = QChar('+'); break;
                    case 'q': r = QChar('\''); break;
                    case 'r': r = QChar('\\'); break;
                    case 's': r = QChar('/'); break;
                    case 't': r = QChar('*'); break;
                    case 'u': r = QChar('_'); break;
                    case 'v': r = QChar('%'); break;
                    default: r = d; break;
                }
                sResult += r;
                i += 2;
            }
        } else {
            sResult += c;
            i++;
        }
    }

    return sResult;
}

// --- OCaml -------------------------------------------------------------------
//
// OCaml native symbols look like  caml<Module>__<name>_<stamp> . Strip the caml
// prefix, decode $XX hex escapes, drop a trailing _<digits> stamp and turn the
// module separator __ into '.'.

QString XDemangle::ocaml_demangle(const QString &sString)
{
    if (!sString.startsWith("caml")) {
        return QString();  // -> raw fallback
    }

    QString s = sString.mid(4);

    // Decode $XX hex escapes.
    QString sDecoded;
    qint32 i = 0;

    while (i < s.size()) {
        QChar c = s.at(i);

        if ((c == QChar('$')) && (i + 2 < s.size())) {
            qint32 hi = watcom_charToDigit(s.at(i + 1));
            qint32 lo = watcom_charToDigit(s.at(i + 2));

            if ((hi >= 0) && (hi < 16) && (lo >= 0) && (lo < 16)) {
                sDecoded += QChar((char16_t)((hi << 4) | lo));
                i += 3;
                continue;
            }
        }

        sDecoded += c;
        i++;
    }

    // Drop a trailing _<digits> compilation stamp.
    qint32 nUnderscore = sDecoded.lastIndexOf(QChar('_'));

    if (nUnderscore >= 0) {
        QString sTail = sDecoded.mid(nUnderscore + 1);
        bool bAllDigits = !sTail.isEmpty();

        for (qint32 k = 0; k < sTail.size(); k++) {
            if (!((sTail.at(k) >= QChar('0')) && (sTail.at(k) <= QChar('9')))) {
                bAllDigits = false;
                break;
            }
        }

        if (bAllDigits) {
            sDecoded = sDecoded.left(nUnderscore);
        }
    }

    sDecoded.replace("__", ".");

    return sDecoded;
}

// --- Go ----------------------------------------------------------------------
//
// Go symbol names are largely readable; the "mangling" is a small set of
// substitutions the linker applies: the Plan-9 middle dot (U+00B7) separates
// package/name, the division slash (U+2215) stands in for '/' in import paths,
// and %xx encodes other bytes.

QString XDemangle::go_demangle(const QString &sString)
{
    QString sResult;
    qint32 i = 0;

    while (i < sString.size()) {
        QChar c = sString.at(i);

        if (c == QChar((char16_t)0x00B7)) {  // middle dot
            sResult += QChar('.');
            i++;
        } else if (c == QChar((char16_t)0x2215)) {  // division slash
            sResult += QChar('/');
            i++;
        } else if ((c == QChar('%')) && (i + 2 < sString.size())) {
            qint32 hi = watcom_charToDigit(sString.at(i + 1));
            qint32 lo = watcom_charToDigit(sString.at(i + 2));

            if ((hi >= 0) && (hi < 16) && (lo >= 0) && (lo < 16)) {
                sResult += QChar((char16_t)((hi << 4) | lo));
                i += 3;
            } else {
                sResult += c;
                i++;
            }
        } else {
            sResult += c;
            i++;
        }
    }

    return sResult;
}

// --- GNU v2 (pre-Itanium GCC 2.x) --------------------------------------------
//
// Native port of the common paths of the historical libiberty cplus-dem.c. Uses
// the same "declarator" model: prefix operators (P/R/C/V/A/F/T) accumulate into a
// `decl` string (prepended/appended), then the base type is read into `result`
// and combined as `result + " " + decl`. All-or-nothing: unparsable => raw.

qint64 XDemangle::gnu2_consumeCount(const QString &sM, qint32 *pnPos, bool *pbOk)
{
    QChar c = watcom_charAt(sM, *pnPos);
    if (!((c >= QChar('0')) && (c <= QChar('9')))) {
        *pbOk = false;
        return -1;
    }
    qint64 n = 0;
    while (true) {
        c = watcom_charAt(sM, *pnPos);
        if (!((c >= QChar('0')) && (c <= QChar('9')))) break;
        n = n * 10 + (c.unicode() - '0');
        *pnPos += 1;
    }
    *pbOk = true;
    return n;
}

qint64 XDemangle::gnu2_getCount(const QString &sM, qint32 *pnPos, bool *pbOk)
{
    // single digit, unless the digits are followed by '_' (then the whole value)
    QChar c = watcom_charAt(sM, *pnPos);
    if (!((c >= QChar('0')) && (c <= QChar('9')))) {
        *pbOk = false;
        return -1;
    }
    qint32 nSave = *pnPos;
    qint64 n = gnu2_consumeCount(sM, pnPos, pbOk);
    if (!*pbOk) return -1;
    if (watcom_charAt(sM, *pnPos) == QChar('_')) {
        *pnPos += 1;
        return n;
    }
    // not underscore-terminated: only the first digit counted
    *pnPos = nSave + 1;
    return (watcom_charAt(sM, nSave).unicode() - '0');
}

QString XDemangle::gnu2_operatorName(const QString &sCode, bool *pbOk)
{
    static const char *ops[][2] = {{"nw", " new"}, {"dl", " delete"}, {"vn", " new []"}, {"vd", " delete []"}, {"as", "="},       {"ne", "!="},      {"eq", "=="},
                                   {"ge", ">="},   {"gt", ">"},       {"le", "<="},      {"lt", "<"},          {"pl", "+"},       {"apl", "+="},     {"mi", "-"},
                                   {"ami", "-="},  {"ml", "*"},       {"amu", "*="},     {"aml", "*="},        {"md", "%"},       {"amd", "%="},     {"dv", "/"},
                                   {"adv", "/="},  {"aa", "&&"},      {"oo", "||"},      {"nt", "!"},          {"pp", "++"},      {"mm", "--"},      {"or", "|"},
                                   {"aor", "|="},  {"er", "^"},       {"aer", "^="},     {"ad", "&"},          {"aad", "&="},     {"co", "~"},       {"cl", "()"},
                                   {"ls", "<<"},   {"als", "<<="},    {"rs", ">>"},      {"ars", ">>="},       {"rf", "->"},      {"vc", "[]"},      {"cm", ", "},
                                   {"cn", "?:"},   {"mx", ">?"},      {"mn", "<?"},      {"rm", "->*"},        {"sz", "sizeof "}, {nullptr, nullptr}};
    for (qint32 i = 0; ops[i][0] != nullptr; i++) {
        if (sCode == QString(ops[i][0])) {
            *pbOk = true;
            return QString("operator") + QString(ops[i][1]);
        }
    }
    *pbOk = false;
    return QString();
}

bool XDemangle::gnu2_integralValue(GNU2INFO *pI, QString *psResult)
{
    QChar c = watcom_charAt(pI->sMangled, pI->nPos);

    if (c == QChar('E')) {
        return false;  // expression - unsupported
    }
    if ((c == QChar('Q')) || (c == QChar('K'))) {
        return gnu2_qualified(pI, psResult, nullptr);
    }

    QString s;
    bool bMultidigit = false;
    bool bLeaveUnderscore = false;

    if (c == QChar('_')) {
        if (watcom_charAt(pI->sMangled, pI->nPos + 1) == QChar('m')) {
            bMultidigit = true;
            s += "-";
            pI->nPos += 2;
        } else {
            bLeaveUnderscore = true;  // consume_count_with_underscores will eat the '_'
        }
    } else {
        if (c == QChar('m')) {
            s += "-";
            pI->nPos++;
        }
        bMultidigit = true;
        bLeaveUnderscore = true;
    }

    qint64 nValue;
    bool bOk = false;

    if (bMultidigit) {
        nValue = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
        if (!bOk) return false;
    } else {
        // consume_count_with_underscores
        if (watcom_charAt(pI->sMangled, pI->nPos) == QChar('_')) {
            pI->nPos++;
            nValue = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
            if (!bOk || (watcom_charAt(pI->sMangled, pI->nPos) != QChar('_'))) return false;
            pI->nPos++;
        } else {
            QChar d = watcom_charAt(pI->sMangled, pI->nPos);
            if (!((d >= QChar('0')) && (d <= QChar('9')))) return false;
            nValue = d.unicode() - '0';
            pI->nPos++;
        }
    }

    s += QString::number(nValue);

    if (((nValue > 9) || bMultidigit) && !bLeaveUnderscore && (watcom_charAt(pI->sMangled, pI->nPos) == QChar('_'))) {
        pI->nPos++;
    }

    *psResult = s;
    return true;
}

bool XDemangle::gnu2_fundType(GNU2INFO *pI, QString *psResult)
{
    QString result;
    bool done = false;

    // Qualifier / sign prefixes (may be several).
    while (!done) {
        QChar c = watcom_charAt(pI->sMangled, pI->nPos);
        if ((c == QChar('C')) || (c == QChar('V')) || (c == QChar('u'))) {
            QString sQ = (c == QChar('C')) ? QString("const") : ((c == QChar('V')) ? QString("volatile") : QString("__restrict"));
            if (!result.isEmpty()) result.prepend(" ");
            result.prepend(sQ);
            pI->nPos++;
        } else if (c == QChar('U')) {
            pI->nPos++;
            if (!result.isEmpty()) result += " ";
            result += "unsigned";
        } else if (c == QChar('S')) {
            pI->nPos++;
            if (!result.isEmpty()) result += " ";
            result += "signed";
        } else if (c == QChar('J')) {
            pI->nPos++;
            if (!result.isEmpty()) result += " ";
            result += "__complex";
        } else {
            done = true;
        }
    }

    QChar c = watcom_charAt(pI->sMangled, pI->nPos);
    QString sWord;
    bool bWord = true;

    switch (c.unicode()) {
        case 'v': sWord = "void"; break;
        case 'x': sWord = "long long"; break;
        case 'l': sWord = "long"; break;
        case 'i': sWord = "int"; break;
        case 's': sWord = "short"; break;
        case 'b': sWord = "bool"; break;
        case 'c': sWord = "char"; break;
        case 'w': sWord = "wchar_t"; break;
        case 'r': sWord = "long double"; break;
        case 'd': sWord = "double"; break;
        case 'f': sWord = "float"; break;
        default: bWord = false; break;
    }

    if (bWord) {
        pI->nPos++;
        if (!result.isEmpty()) result += " ";
        result += sWord;
        *psResult = result;
        return true;
    }

    if ((c >= QChar('0')) && (c <= QChar('9'))) {  // explicit class name <len><name>
        bool bOk = false;
        qint64 nLen = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
        if (!bOk || (pI->nPos + (qint32)nLen > pI->sMangled.size())) return false;
        QString sName = pI->sMangled.mid(pI->nPos, (qint32)nLen);
        pI->nPos += (qint32)nLen;
        if (!result.isEmpty()) result += " ";
        result += sName;
        *psResult = result;
        return true;
    }

    if (c == QChar('t')) {  // template class
        QString sTmpl;
        QString sBare;
        if (!gnu2_template(pI, &sTmpl, &sBare)) return false;
        if (!result.isEmpty()) result += " ";
        result += sTmpl;
        *psResult = result;
        return true;
    }

    return false;
}

bool XDemangle::gnu2_template(GNU2INFO *pI, QString *psResult, QString *psBareName)
{
    if (watcom_charAt(pI->sMangled, pI->nPos) != QChar('t')) return false;
    pI->nPos++;

    bool bOk = false;
    qint64 nLen = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
    if (!bOk || (pI->nPos + (qint32)nLen > pI->sMangled.size())) return false;
    QString sName = pI->sMangled.mid(pI->nPos, (qint32)nLen);
    pI->nPos += (qint32)nLen;

    qint64 nArgs = gnu2_getCount(pI->sMangled, &(pI->nPos), &bOk);
    if (!bOk) return false;

    QStringList slArgs;
    for (qint64 i = 0; i < nArgs; i++) {
        QChar c = watcom_charAt(pI->sMangled, pI->nPos);
        if (c == QChar('Z')) {  // type argument
            pI->nPos++;
            QString sType;
            if (!gnu2_type(pI, &sType)) return false;
            slArgs.append(sType);
        } else {  // value argument: <param-type> <literal>
            QString sType;
            if (!gnu2_type(pI, &sType)) return false;  // the parameter type (not printed)
            QString sVal;
            if (!gnu2_integralValue(pI, &sVal)) return false;
            slArgs.append(sVal);
        }
    }

    QString sJoined = slArgs.join(", ");
    QString sSpace = sJoined.endsWith(">") ? QString(" ") : QString("");
    *psResult = sName + QString("<") + sJoined + sSpace + QString(">");
    if (psBareName) *psBareName = sName;
    return true;
}

bool XDemangle::gnu2_qualified(GNU2INFO *pI, QString *psResult, QString *psLastName)
{
    if ((watcom_charAt(pI->sMangled, pI->nPos) != QChar('Q'))) return false;
    pI->nPos++;

    bool bOk = false;
    qint64 nCount;
    if (watcom_charAt(pI->sMangled, pI->nPos) == QChar('_')) {
        pI->nPos++;  // Q _ <count> _ ...  (for count >= 10)
        nCount = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
        if (!bOk) return false;
        if (watcom_charAt(pI->sMangled, pI->nPos) == QChar('_')) pI->nPos++;
    } else {
        QChar c = watcom_charAt(pI->sMangled, pI->nPos);
        if (!((c >= QChar('0')) && (c <= QChar('9')))) return false;
        nCount = c.unicode() - '0';
        pI->nPos++;
    }

    QStringList sl;
    QString sLast;
    for (qint64 i = 0; i < nCount; i++) {
        QChar c = watcom_charAt(pI->sMangled, pI->nPos);
        if (c == QChar('t')) {
            QString sTmpl, sBare;
            if (!gnu2_template(pI, &sTmpl, &sBare)) return false;
            sl.append(sTmpl);
            sLast = sBare;
        } else if ((c >= QChar('0')) && (c <= QChar('9'))) {
            qint64 nLen = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
            if (!bOk || (pI->nPos + (qint32)nLen > pI->sMangled.size())) return false;
            QString sName = pI->sMangled.mid(pI->nPos, (qint32)nLen);
            pI->nPos += (qint32)nLen;
            sl.append(sName);
            sLast = sName;
        } else {
            return false;
        }
    }

    *psResult = sl.join("::");
    if (psLastName) *psLastName = sLast;
    return true;
}

bool XDemangle::gnu2_type(GNU2INFO *pI, QString *psResult)
{
    QString decl;
    QString result;
    bool done = false;
    bool success = true;

    while (success && !done) {
        QChar c = watcom_charAt(pI->sMangled, pI->nPos);
        switch (c.unicode()) {
            case 'P':
            case 'p':
                pI->nPos++;
                decl.prepend("*");
                break;
            case 'R':
                pI->nPos++;
                decl.prepend("&");
                break;
            case 'O':
                pI->nPos++;
                decl.prepend("&&");
                break;
            case 'C':
            case 'V':
            case 'u': {
                QString sQ = (c == QChar('C')) ? QString("const") : ((c == QChar('V')) ? QString("volatile") : QString("__restrict"));
                if (!decl.isEmpty()) decl.prepend(" ");
                decl.prepend(sQ);
                pI->nPos++;
                break;
            }
            case 'F': {
                pI->nPos++;
                if (!decl.isEmpty() && ((decl.at(0) == QChar('*')) || (decl.at(0) == QChar('&')))) {
                    decl.prepend("(");
                    decl.append(")");
                }
                // nested args (save/restore remembered types)
                QList<QString> savedRem = pI->listRemembered;
                QString sArgs;
                if (!gnu2_args(pI, &sArgs)) {
                    success = false;
                    break;
                }
                pI->listRemembered = savedRem;
                decl.append(sArgs);
                if (watcom_charAt(pI->sMangled, pI->nPos) == QChar('_')) pI->nPos++;
                break;
            }
            case 'T': {
                pI->nPos++;
                bool bOk = false;
                qint64 n = gnu2_getCount(pI->sMangled, &(pI->nPos), &bOk);
                if (!bOk || (n < 0) || (n >= pI->listRemembered.size())) {
                    success = false;
                    break;
                }
                // Splice the remembered type back in (it is a fully-rendered type).
                QString sRem = pI->listRemembered.at((qint32)n);
                if (!result.isEmpty()) result += " ";
                result += sRem;
                if (!decl.isEmpty()) {
                    result += " ";
                    result += decl;
                }
                *psResult = result;
                return true;
            }
            case 'M': {  // pointer to member: <class>::* (optionally a member function)
                pI->nPos++;
                QChar cc = watcom_charAt(pI->sMangled, pI->nPos);
                QString sCls;
                if ((cc >= QChar('0')) && (cc <= QChar('9'))) {
                    bool bOk = false;
                    qint64 nLen = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
                    if (!bOk || (pI->nPos + (qint32)nLen > pI->sMangled.size())) {
                        success = false;
                        break;
                    }
                    sCls = pI->sMangled.mid(pI->nPos, (qint32)nLen);
                    pI->nPos += (qint32)nLen;
                } else if (cc == QChar('Q')) {
                    if (!gnu2_qualified(pI, &sCls, nullptr)) {
                        success = false;
                        break;
                    }
                } else if (cc == QChar('t')) {
                    QString sBare;
                    if (!gnu2_template(pI, &sCls, &sBare)) {
                        success = false;
                        break;
                    }
                } else {
                    success = false;
                    break;
                }
                // decl (so far, e.g. "*") becomes  (Class::*<decl>)
                decl = QString("(") + sCls + QString("::") + decl + QString(")");
                // Member-function pointer: optional cv, then F <args> _ <ret>.
                QChar cq = watcom_charAt(pI->sMangled, pI->nPos);
                if ((cq == QChar('C')) || (cq == QChar('V')) || (cq == QChar('u'))) {
                    pI->nPos++;  // member cv-qualifier (consumed; rendering omitted)
                }
                if (watcom_charAt(pI->sMangled, pI->nPos) == QChar('F')) {
                    pI->nPos++;
                    QList<QString> savedRem = pI->listRemembered;
                    QString sArgs;
                    if (!gnu2_args(pI, &sArgs)) {
                        success = false;
                        break;
                    }
                    pI->listRemembered = savedRem;
                    decl.append(sArgs);
                    if (watcom_charAt(pI->sMangled, pI->nPos) == QChar('_')) pI->nPos++;
                }
                break;
            }
            case 'G': pI->nPos++; break;
            default: done = true; break;
        }
    }

    if (!success) return false;

    QChar c = watcom_charAt(pI->sMangled, pI->nPos);
    if ((c == QChar('Q')) || (c == QChar('K'))) {
        if (!gnu2_qualified(pI, &result, nullptr)) return false;
    } else if ((c == QChar('X')) || (c == QChar('Y'))) {
        // Template-parameter substitution X<idx>_<cnt> (two consume_count_with_underscores).
        pI->nPos++;
        qint64 nIdx = -1;
        for (qint32 nWhich = 0; nWhich < 2; nWhich++) {
            qint64 nVal;
            QChar d = watcom_charAt(pI->sMangled, pI->nPos);
            if (d == QChar('_')) {
                pI->nPos++;
                bool bOk = false;
                nVal = gnu2_consumeCount(pI->sMangled, &(pI->nPos), &bOk);
                if (!bOk || (watcom_charAt(pI->sMangled, pI->nPos) != QChar('_'))) return false;
                pI->nPos++;
            } else if ((d >= QChar('0')) && (d <= QChar('9'))) {
                nVal = d.unicode() - '0';
                pI->nPos++;
            } else {
                return false;
            }
            if (nWhich == 0) nIdx = nVal;
        }
        if ((nIdx < 0) || (nIdx >= pI->listTmplArgs.size())) return false;
        result = pI->listTmplArgs.at((qint32)nIdx);
    } else {
        if (!gnu2_fundType(pI, &result)) return false;
    }

    if (!decl.isEmpty()) {
        result += " ";
        result += decl;
    }

    *psResult = result;
    return true;
}

bool XDemangle::gnu2_args(GNU2INFO *pI, QString *psResult)
{
    QStringList slArgs;
    bool bEllipsis = false;

    while (true) {
        QChar c = watcom_charAt(pI->sMangled, pI->nPos);
        if ((c == QChar('\0')) || (c == QChar('_'))) break;

        if (c == QChar('e')) {  // ellipsis (appended as ",..." with no space)
            pI->nPos++;
            bEllipsis = true;
            break;
        }

        if (c == QChar('N')) {  // N<repeat><index> : repeat a remembered type
            pI->nPos++;
            bool bOk = false;
            qint64 nRepeat = gnu2_getCount(pI->sMangled, &(pI->nPos), &bOk);
            if (!bOk) return false;
            qint64 nIndex = gnu2_getCount(pI->sMangled, &(pI->nPos), &bOk);
            if (!bOk || (nIndex < 0) || (nIndex >= pI->listRemembered.size())) return false;
            QString sType = pI->listRemembered.at((qint32)nIndex);
            for (qint64 i = 0; i < nRepeat; i++) slArgs.append(sType);
            continue;
        }

        if (c == QChar('T')) {  // T<index> : one copy of a remembered type
            pI->nPos++;
            bool bOk = false;
            qint64 nIndex = gnu2_getCount(pI->sMangled, &(pI->nPos), &bOk);
            if (!bOk || (nIndex < 0) || (nIndex >= pI->listRemembered.size())) return false;
            slArgs.append(pI->listRemembered.at((qint32)nIndex));
            continue;
        }

        QString sType;
        qint32 nBefore = pI->nPos;
        if (!gnu2_type(pI, &sType)) return false;
        if (pI->nPos == nBefore) return false;  // no progress guard
        pI->listRemembered.append(sType);
        slArgs.append(sType);
    }

    QString sInner = slArgs.join(", ");
    if (bEllipsis) {
        sInner += (sInner.isEmpty() ? QString("...") : QString(",..."));
    } else if (slArgs.isEmpty()) {
        sInner = "void";
    }
    *psResult = QString("(") + sInner + QString(")");
    return true;
}

bool XDemangle::gnu2_special(const QString &sMangled, QString *psResult)
{
    // type_info node / function: __ti<type> / __tf<type>
    if (sMangled.startsWith("__ti") || sMangled.startsWith("__tf")) {
        GNU2INFO I;
        I.sMangled = sMangled;
        I.nPos = 4;
        I.bErrored = false;
        QString sType;
        if (!gnu2_type(&I, &sType) || (I.nPos != sMangled.size())) return false;
        *psResult = sType + (sMangled.startsWith("__ti") ? QString(" type_info node") : QString(" type_info function"));
        return true;
    }

    // Global constructors/destructors, and anonymous-namespace members (_GLOBAL_).
    {
        qint32 g = sMangled.indexOf("_GLOBAL_");
        if (g >= 0) {
            qint32 p = g + 8;
            QChar m1 = watcom_charAt(sMangled, p);
            QChar kind = watcom_charAt(sMangled, p + 1);
            QChar m2 = watcom_charAt(sMangled, p + 2);
            if (((m1 == QChar('$')) || (m1 == QChar('.'))) && ((m2 == QChar('$')) || (m2 == QChar('.')))) {
                if (kind == QChar('I')) {
                    *psResult = QString("global constructors keyed to ") + sMangled.mid(p + 3);
                    return true;
                }
                if (kind == QChar('D')) {
                    *psResult = QString("global destructors keyed to ") + sMangled.mid(p + 3);
                    return true;
                }
                if (kind == QChar('N')) {
                    qint32 nLast = qMax(sMangled.lastIndexOf(QChar('$')), sMangled.lastIndexOf(QChar('.')));
                    QString sVar = (nLast >= 0) ? sMangled.mid(nLast + 1) : QString();
                    *psResult = QString("{anonymous}::") + sVar;
                    return true;
                }
            }
            return false;  // some other _GLOBAL_ form -> raw
        }
    }

    // Destructor: _$_<class> / _._<class>
    if (sMangled.startsWith("_$_") || sMangled.startsWith("_._")) {
        GNU2INFO I;
        I.sMangled = sMangled;
        I.nPos = 3;
        I.bErrored = false;
        QChar c = watcom_charAt(sMangled, 3);
        QString sClass, sBare;
        if (c == QChar('Q')) {
            if (!gnu2_qualified(&I, &sClass, &sBare)) return false;
        } else if (c == QChar('t')) {
            if (!gnu2_template(&I, &sClass, &sBare)) return false;
        } else if ((c >= QChar('0')) && (c <= QChar('9'))) {
            bool bOk = false;
            qint64 nLen = gnu2_consumeCount(sMangled, &(I.nPos), &bOk);
            if (!bOk || (I.nPos + (qint32)nLen > sMangled.size())) return false;
            sClass = sMangled.mid(I.nPos, (qint32)nLen);
            I.nPos += (qint32)nLen;
            sBare = sClass;
        } else {
            return false;
        }
        QString sArgs;
        if (!gnu2_args(&I, &sArgs) || (I.nPos != sMangled.size())) return false;
        *psResult = sClass + QString("::~") + sBare + sArgs;
        return true;
    }

    // New-style vtable: __vt_<name>
    if (sMangled.startsWith("__vt_")) {
        GNU2INFO I;
        I.sMangled = sMangled;
        I.nPos = 5;
        I.bErrored = false;
        QChar c = watcom_charAt(sMangled, 5);
        QString sName, sBare;
        if (c == QChar('Q')) {
            if (!gnu2_qualified(&I, &sName, &sBare)) return false;
        } else if ((c >= QChar('0')) && (c <= QChar('9'))) {
            bool bOk = false;
            qint64 nLen = gnu2_consumeCount(sMangled, &(I.nPos), &bOk);
            if (!bOk || (I.nPos + (qint32)nLen > sMangled.size())) return false;
            sName = sMangled.mid(I.nPos, (qint32)nLen);
        } else {
            return false;
        }
        *psResult = sName + QString(" virtual table");
        return true;
    }

    // Old-style vtable: _vt$<name> / _vt.<name>  ($/. separated components -> ::)
    if (sMangled.startsWith("_vt$") || sMangled.startsWith("_vt.")) {
        QString sRest = sMangled.mid(4);
        // Split on the CPLUS markers; a component may be a template (t...), a
        // length-prefixed class name (<digits>...) or a plain literal.
        QStringList slParts;
        QString sCur = sRest;
        sCur.replace(QChar('.'), QChar('$'));
        QStringList slRaw = sCur.split(QChar('$'));
        for (qint32 i = 0; i < slRaw.size(); i++) {
            QString sPart = slRaw.at(i);
            QChar c = watcom_charAt(sPart, 0);
            if ((c == QChar('t')) && (watcom_charAt(sPart, 1) >= QChar('0')) && (watcom_charAt(sPart, 1) <= QChar('9'))) {
                GNU2INFO I;
                I.sMangled = sPart;
                I.nPos = 0;
                I.bErrored = false;
                QString sTmpl, sBare;
                if (gnu2_template(&I, &sTmpl, &sBare) && (I.nPos == sPart.size())) {
                    slParts.append(sTmpl);
                    continue;
                }
            }
            slParts.append(sPart);
        }
        *psResult = slParts.join("::") + QString(" virtual table");
        return true;
    }

    // Anonymous-namespace / global con/destructor keys: leave these to raw fallback
    // rather than mis-parsing them as static data.
    if (sMangled.contains("_GLOBAL_")) {
        return false;
    }

    // Static data member: _<class><M><var>  (class starts with a digit / Q / t)
    if (sMangled.startsWith("_") && !sMangled.startsWith("__")) {
        QChar c = watcom_charAt(sMangled, 1);
        if (((c >= QChar('0')) && (c <= QChar('9'))) || (c == QChar('Q')) || (c == QChar('t'))) {
            GNU2INFO I;
            I.sMangled = sMangled;
            I.nPos = 1;
            I.bErrored = false;
            QString sClass, sBare;
            if (c == QChar('Q')) {
                if (!gnu2_qualified(&I, &sClass, &sBare)) return false;
            } else if (c == QChar('t')) {
                if (!gnu2_template(&I, &sClass, &sBare)) return false;
            } else {
                bool bOk = false;
                qint64 nLen = gnu2_consumeCount(sMangled, &(I.nPos), &bOk);
                if (!bOk || (I.nPos + (qint32)nLen > sMangled.size())) return false;
                sClass = sMangled.mid(I.nPos, (qint32)nLen);
                I.nPos += (qint32)nLen;
            }
            QChar cSep = watcom_charAt(sMangled, I.nPos);
            if ((cSep != QChar('$')) && (cSep != QChar('.'))) return false;
            I.nPos++;
            QString sVar = sMangled.mid(I.nPos);
            if (sVar.isEmpty()) return false;
            *psResult = sClass + QString("::") + sVar;
            return true;
        }
    }

    return false;
}

QString XDemangle::gnu2_tryFunction(const QString &sMangled, qint32 nSigStart, const QString &sFuncName, bool bCtor, bool bAllowXMarker)
{
    GNU2INFO I;
    I.sMangled = sMangled;
    I.nPos = nSigStart;
    I.bErrored = false;
    I.bExpectReturn = false;

    // Signature: leading const/volatile member quals, member class, optional S/F, args.
    QString sQuals;
    while (true) {
        QChar c = watcom_charAt(I.sMangled, I.nPos);
        if (c == QChar('C')) {
            if (!sQuals.isEmpty()) sQuals += " ";
            sQuals += "const";
            I.nPos++;
        } else if (c == QChar('V')) {
            if (!sQuals.isEmpty()) sQuals += " ";
            sQuals += "volatile";
            I.nPos++;
        } else break;
    }

    QString sClass;
    QString sBareClass;
    QChar c = watcom_charAt(I.sMangled, I.nPos);

    if ((c >= QChar('0')) && (c <= QChar('9'))) {
        bool bOk = false;
        qint64 nLen = gnu2_consumeCount(I.sMangled, &(I.nPos), &bOk);
        if (!bOk || (I.nPos + (qint32)nLen > I.sMangled.size())) return QString();
        sClass = I.sMangled.mid(I.nPos, (qint32)nLen);
        I.nPos += (qint32)nLen;
        sBareClass = sClass;
        I.listRemembered.append(sClass);
    } else if (c == QChar('Q')) {
        if (!gnu2_qualified(&I, &sClass, &sBareClass)) return QString();
        I.listRemembered.append(sClass);
    } else if (c == QChar('t')) {
        if (!gnu2_template(&I, &sClass, &sBareClass)) return QString();
        I.listRemembered.append(sClass);
    }

    if (watcom_charAt(I.sMangled, I.nPos) == QChar('S')) {
        I.nPos++;  // static member
    }

    // Template function: H <tparam-count> <tparams...> _ <args...> _ <return-type>
    QString sTmplArgs;
    if (watcom_charAt(I.sMangled, I.nPos) == QChar('H')) {
        I.nPos++;
        I.bExpectReturn = true;
        bool bOk = false;
        qint64 nT = gnu2_getCount(I.sMangled, &(I.nPos), &bOk);
        if (!bOk) return QString();
        QStringList slT;
        for (qint64 i = 0; i < nT; i++) {
            QChar ct = watcom_charAt(I.sMangled, I.nPos);
            if (ct == QChar('Z')) {
                I.nPos++;
                QString sType;
                if (!gnu2_type(&I, &sType)) return QString();
                I.listTmplArgs.append(sType);
                slT.append(sType);
            } else {
                return QString();  // value template params not supported here
            }
        }
        sTmplArgs = QString("<") + slT.join(", ") + (slT.join(", ").endsWith(">") ? QString(" ") : QString("")) + QString(">");
        if (watcom_charAt(I.sMangled, I.nPos) == QChar('_')) I.nPos++;
    }

    if (watcom_charAt(I.sMangled, I.nPos) == QChar('F')) {
        I.nPos++;
    } else if (bAllowXMarker && !I.bExpectReturn && (watcom_charAt(I.sMangled, I.nPos) == QChar('X'))) {
        // DEC/Tru64 ARM-mode uses '__X' where GNU/ARM use '__F'. Guard against template
        // functions (H-form: bExpectReturn set, NO marker) whose arg list begins with an
        // 'X<idx>' back-reference -- that leading 'X' is an argument, not the marker.
        I.nPos++;
    }

    QString sArgs;
    if (!gnu2_args(&I, &sArgs)) {
        return QString();
    }

    // Template-function return type: after the args, '_' then the return type.
    QString sReturn;
    if (I.bExpectReturn) {
        if (watcom_charAt(I.sMangled, I.nPos) == QChar('_')) I.nPos++;
        if (!gnu2_type(&I, &sReturn)) return QString();
    }

    // The whole signature must be consumed (all-or-nothing).
    if (I.nPos != I.sMangled.size()) {
        return QString();
    }

    QString sFunc;
    if (bCtor) {
        sFunc = sBareClass;
    } else {
        sFunc = sFuncName;
    }
    sFunc += sTmplArgs;

    QString sFull;
    if (!sClass.isEmpty()) {
        sFull = sClass + QString("::") + sFunc;
    } else {
        sFull = sFunc;
    }
    sFull += sArgs;
    if (!sQuals.isEmpty()) {
        sFull += QString(" ") + sQuals;
    }
    if (!sReturn.isEmpty()) {
        sFull = sReturn + QString(" ") + sFull;  // template functions encode a return type
    }

    return sFull;
}

// --- SunPro / Sun Studio C++ ('__1c' scheme) ---------------------------------
//
// Conservative subset only. There is no runnable Sun demangler available here to
// verify against, so this models just the parts confirmed from the documented ABI
// and the canonical vectors: a (possibly qualified) free function whose parameters
// and return type are fundamental types. Everything else (pointers, references,
// cv-quals, unsigned/wide/long-long, templates, operators, member quals, extended
// length codes) is intentionally NOT modeled -> the all-or-nothing contract returns
// "" and the symbol is passed through raw, never guessed.

bool XDemangle::sun_builtin(QChar cCode, QString *psType)
{
    if (cCode == QChar('v')) {
        *psType = "void";
        return true;
    }
    if (cCode == QChar('b')) {
        *psType = "bool";
        return true;
    }
    if (cCode == QChar('c')) {
        *psType = "char";
        return true;
    }
    if (cCode == QChar('s')) {
        *psType = "short";
        return true;
    }
    if (cCode == QChar('i')) {
        *psType = "int";
        return true;
    }
    if (cCode == QChar('l')) {
        *psType = "long";
        return true;
    }
    if (cCode == QChar('f')) {
        *psType = "float";
        return true;
    }
    if (cCode == QChar('d')) {
        *psType = "double";
        return true;
    }
    return false;
}

QString XDemangle::sun_demangle(const QString &sString)
{
    //  '__1c' (<len-letter><name>)+ '6F' <arg-type>* '_' <ret-type> '_'
    // where <len-letter> encodes an identifier length 1..25 as 'B'..'Z'.
    if (!sString.startsWith("__1c")) {
        return QString();
    }
    qint32 nPos = 4;

    QStringList slName;
    while (true) {
        QChar c = watcom_charAt(sString, nPos);
        if ((c >= QChar('B')) && (c <= QChar('Z'))) {
            qint32 nLen = c.unicode() - 'A';  // 'B' = 1 .. 'Z' = 25
            nPos++;
            if ((nPos + nLen) > sString.size()) {
                return QString();
            }
            slName.append(sString.mid(nPos, nLen));
            nPos += nLen;
        } else {
            break;
        }
    }
    if (slName.isEmpty()) {
        return QString();
    }

    // Function descriptor '6F'.
    if ((watcom_charAt(sString, nPos) != QChar('6')) || (watcom_charAt(sString, nPos + 1) != QChar('F'))) {
        return QString();
    }
    nPos += 2;

    // Argument types until the '_' separator.
    QStringList slArgs;
    while (watcom_charAt(sString, nPos) != QChar('_')) {
        if (nPos >= sString.size()) {
            return QString();
        }
        QString sTy;
        if (!sun_builtin(watcom_charAt(sString, nPos), &sTy)) {
            return QString();
        }
        slArgs.append(sTy);
        nPos++;
    }
    nPos++;  // consume '_'

    // Return type, then the terminating '_'.
    QString sRet;
    if (!sun_builtin(watcom_charAt(sString, nPos), &sRet)) {
        return QString();
    }
    nPos++;
    if (watcom_charAt(sString, nPos) != QChar('_')) {
        return QString();
    }
    nPos++;

    // All-or-nothing: the whole symbol must be consumed.
    if (nPos != sString.size()) {
        return QString();
    }

    QString sArgsStr = slArgs.isEmpty() ? QString("void") : slArgs.join(", ");
    return sRet + QString(" ") + slName.join("::") + QString("(") + sArgsStr + QString(")");
}

QString XDemangle::gnu2_demangle(const QString &sString, bool bAllowXMarker)
{
    QString sResult;
    if (gnu2_special(sString, &sResult)) {
        return sResult;
    }

    if (!sString.contains("__") || sString.contains("_GLOBAL_")) {
        return QString();  // not an ordinary GNU-v2 function name
    }

    if (sString.startsWith("__")) {
        QChar c2 = watcom_charAt(sString, 2);
        if (((c2 >= QChar('0')) && (c2 <= QChar('9'))) || (c2 == QChar('Q')) || (c2 == QChar('t'))) {
            // Constructor: __<class> ...
            return gnu2_tryFunction(sString, 2, QString(), true, bAllowXMarker);
        }
        // Operator: name is __<code> up to the next "__".
        qint32 nn = sString.indexOf("__", 2);
        if (nn < 0) return QString();
        QString sCode = sString.mid(2, nn - 2);
        QString sFuncName;
        if (sCode.startsWith("op")) {  // conversion operator: operator <type>
            GNU2INFO T;
            T.sMangled = sCode.mid(2);
            T.nPos = 0;
            T.bErrored = false;
            QString sType;
            if (!gnu2_type(&T, &sType) || (T.nPos != T.sMangled.size())) return QString();
            sFuncName = QString("operator ") + sType;
        } else {
            bool bOk = false;
            sFuncName = gnu2_operatorName(sCode, &bOk);
            if (!bOk) return QString();
        }
        return gnu2_tryFunction(sString, nn + 2, sFuncName, false, bAllowXMarker);
    }

    // Plain function <name>__<signature>. The name may itself contain "__", so try
    // each "__" run left-to-right, splitting at the last pair in the run (the
    // demangle_prefix / iterate_demangle_function backtracking), and accept the
    // first split whose signature fully parses.
    qint32 i = 0;
    while (i < sString.size()) {
        if ((watcom_charAt(sString, i) == QChar('_')) && (watcom_charAt(sString, i + 1) == QChar('_'))) {
            qint32 nScan = i;
            while (watcom_charAt(sString, nScan + 2) == QChar('_')) {
                nScan++;  // advance to the last pair in the run
            }
            qint32 nNameEnd = nScan;
            qint32 nSigStart = nScan + 2;
            if (nNameEnd > 0) {
                QString sName = sString.left(nNameEnd);
                QString sTry = gnu2_tryFunction(sString, nSigStart, sName, false, bAllowXMarker);
                if (!sTry.isEmpty()) {
                    return sTry;
                }
            }
            // skip past the whole run
            i = nScan + 2;
            while (watcom_charAt(sString, i) == QChar('_')) i++;
        } else {
            i++;
        }
    }

    return QString();
}

// --- Swift -------------------------------------------------------------------
//
// Swift mangling is a linear, post-order scheme: reading left->right, identifiers
// and known-type tokens push nodes; single/multi-letter operators pop operands and
// push a combined node; 'A' back-references reuse earlier substitutable nodes. This
// covers the common core (types, nominal types, bound generics with sugar, tuples,
// back-references, and simple functions); anything not fully parsed falls back to
// the raw string (all-or-nothing), so wrong output is never produced.

// Node kinds
static const qint32 SWK_IDENT = 1;       // a bare identifier (name / module)
static const qint32 SWK_TYPE = 2;        // a rendered type
static const qint32 SWK_LISTMARK = 3;    // empty-list 'y' or first-element '_' marker
static const qint32 SWK_EFFECT = 4;      // a postfix function effect (" async", " throws")
static const qint32 SWK_ATTR = 5;        // a prefix function-type attribute ("@Sendable ", ...)
static const qint32 SWK_REQ = 6;         // a generic-signature requirement ("A: Swift.Equatable")
static const qint32 SWK_COUNT = 7;       // generic-param counts from 'r' (slItems = per-depth counts)
static const qint32 SWK_PACKMARK = 8;    // 'Rv' pack marker (sText = index letter of the pack param)
static const qint32 SWK_GENERICSIG = 9;  // assembled "<params where reqs>" ready to splice after a name

// Layout-constraint letter -> printed constraint (only the ones Swift prints as a name).
static QString swift_layoutName(QChar cLayout)
{
    if (cLayout == QChar('C')) return QString("AnyObject");  // Class
    if (cLayout == QChar('D')) return QString("_NativeClass");
    if (cLayout == QChar('N')) return QString("_NativeRefCountedObject");
    if (cLayout == QChar('R')) return QString("_RefCountedObject");
    if (cLayout == QChar('T')) return QString("_Trivial");
    if (cLayout == QChar('U')) return QString("_UnknownLayout");
    if (cLayout == QChar('B')) return QString("_BridgeObject");
    return QString();  // size/alignment forms -> caller bails to raw
}

QChar XDemangle::swift_peek(SWIFTINFO *pI)
{
    if (pI->nPos < pI->sSym.size()) {
        return pI->sSym.at(pI->nPos);
    }
    return QChar('\0');
}

QChar XDemangle::swift_nextc(SWIFTINFO *pI)
{
    QChar c = swift_peek(pI);
    if (c == QChar('\0')) {
        pI->bErrored = true;
    } else {
        pI->nPos++;
    }
    return c;
}

bool XDemangle::swift_eat(SWIFTINFO *pI, QChar cChar)
{
    if (swift_peek(pI) == cChar) {
        pI->nPos++;
        return true;
    }
    return false;
}

qint64 XDemangle::swift_parseNatural(SWIFTINFO *pI, bool *pbOk)
{
    QChar c = swift_peek(pI);
    if (!((c >= QChar('1')) && (c <= QChar('9')))) {
        *pbOk = false;
        return 0;
    }
    qint64 n = 0;
    while (true) {
        c = swift_peek(pI);
        if (!((c >= QChar('0')) && (c <= QChar('9')))) break;
        n = n * 10 + (c.unicode() - '0');
        pI->nPos++;
    }
    *pbOk = true;
    return n;
}

qint64 XDemangle::swift_parseIndex(SWIFTINFO *pI, bool *pbOk)
{
    // INDEX ::= '_' (=0) | <digits> '_' (=value+1)
    *pbOk = true;
    if (swift_eat(pI, QChar('_'))) {
        return 0;
    }
    QChar c = swift_peek(pI);
    if (!((c >= QChar('0')) && (c <= QChar('9')))) {
        *pbOk = false;
        return 0;
    }
    qint64 n = 0;
    while (true) {
        c = swift_peek(pI);
        if (!((c >= QChar('0')) && (c <= QChar('9')))) break;
        n = n * 10 + (c.unicode() - '0');
        pI->nPos++;
    }
    if (!swift_eat(pI, QChar('_'))) {
        *pbOk = false;
        return 0;
    }
    return n + 1;
}

void XDemangle::swift_push(SWIFTINFO *pI, qint32 nKind, const QString &sText)
{
    SWNODE node;
    node.nKind = nKind;
    node.sText = sText;
    pI->stackNodes.append(node);
}

void XDemangle::swift_pushSubst(SWIFTINFO *pI, qint32 nKind, const QString &sText)
{
    SWNODE node;
    node.nKind = nKind;
    node.sText = sText;
    pI->stackNodes.append(node);
    pI->listSubst.append(node);
}

bool XDemangle::swift_pop(SWIFTINFO *pI, SWNODE *pOut)
{
    if (pI->stackNodes.isEmpty()) {
        pI->bErrored = true;
        return false;
    }
    *pOut = pI->stackNodes.takeLast();
    return true;
}

QString XDemangle::swift_readIdentifier(SWIFTINFO *pI, bool *pbOk)
{
    qint64 nLen = swift_parseNatural(pI, pbOk);
    if (!*pbOk) {
        return QString();
    }
    // Compare as qint64 (never narrow to qint32 first: a length >= 2^31 would wrap
    // negative, pass the bounds check, and drive nPos negative -> OOB read).
    if ((nLen < 0) || ((qint64)pI->nPos + nLen > (qint64)pI->sSym.size())) {
        *pbOk = false;
        return QString();
    }
    QString sResult = pI->sSym.mid(pI->nPos, (qint32)nLen);
    pI->nPos += (qint32)nLen;
    *pbOk = true;
    return sResult;
}

QString XDemangle::swift_genericParamName(qint64 nDepth, qint64 nIndex)
{
    // Index -> base-26 letters, least-significant first (Swift's genericParameterName):
    // 0->A .. 25->Z, 26->AB, 27->BB, 52->AC, ...  Depth (>0) appends as a decimal suffix.
    QString sResult;
    quint64 nIdx = (nIndex < 0) ? 0 : (quint64)nIndex;
    do {
        sResult += QChar((char16_t)('A' + (nIdx % 26)));
        nIdx /= 26;
    } while (nIdx != 0);
    if (nDepth > 0) {
        sResult += QString::number(nDepth);
    }
    return sResult;
}

QList<XDemangle::SWNODE> XDemangle::swift_popTypeList(SWIFTINFO *pI)
{
    QList<SWNODE> listResult;
    while (!pI->stackNodes.isEmpty()) {
        SWNODE node = pI->stackNodes.takeLast();
        if (node.nKind == SWK_LISTMARK) {
            break;  // consume the marker
        }
        listResult.prepend(node);
    }
    return listResult;
}

void XDemangle::swift_demangleKnownType(SWIFTINFO *pI)
{
    // 'S' already consumed. Handle repeat count, concurrency 'c', 'Sg' Optional
    // sugar and the standard known-type table.
    QChar c = swift_peek(pI);

    if ((c >= QChar('0')) && (c <= QChar('9'))) {
        bool bOk = false;
        qint64 nRepeat = swift_parseNatural(pI, &bOk);
        // Bound the repeat (real counts are tiny) so a huge value can't drive an
        // unbounded push loop (OOM / hang) on crafted input.
        if (!bOk || (nRepeat > 4096)) {
            pI->bErrored = true;
            return;
        }
        // followed by a single known-type letter, repeated nRepeat times
        QChar letter = swift_nextc(pI);
        if (pI->bErrored) return;
        bool bKnownOk = false;
        QString sType;
        {
            SWIFTINFO tmp = *pI;  // reuse the table via a mini lookup below
            Q_UNUSED(tmp)
        }
        // inline known-type lookup for the letter
        static const char *known[] = {"A",     "AutoreleasingUnsafeMutablePointer",
                                      "a",     "Swift.Array",
                                      "B",     "Swift.BinaryFloatingPoint",
                                      "b",     "Swift.Bool",
                                      "D",     "Swift.Dictionary",
                                      "d",     "Swift.Double",
                                      "E",     "Swift.Encodable",
                                      "e",     "Swift.Decodable",
                                      "F",     "Swift.FloatingPoint",
                                      "f",     "Swift.Float",
                                      "G",     "Swift.RandomNumberGenerator",
                                      "H",     "Swift.Hashable",
                                      "h",     "Swift.Set",
                                      "I",     "Swift.DefaultIndices",
                                      "i",     "Swift.Int",
                                      "J",     "Swift.Character",
                                      "j",     "Swift.Numeric",
                                      "K",     "Swift.BidirectionalCollection",
                                      "k",     "Swift.RandomAccessCollection",
                                      "L",     "Swift.Comparable",
                                      "l",     "Swift.Collection",
                                      "M",     "Swift.MutableCollection",
                                      "m",     "Swift.RangeReplaceableCollection",
                                      "N",     "Swift.ClosedRange",
                                      "n",     "Swift.Range",
                                      "O",     "Swift.ObjectIdentifier",
                                      "P",     "Swift.UnsafePointer",
                                      "p",     "Swift.UnsafeMutablePointer",
                                      "Q",     "Swift.Equatable",
                                      "q",     "Swift.Optional",
                                      "R",     "Swift.UnsafeBufferPointer",
                                      "r",     "Swift.UnsafeMutableBufferPointer",
                                      "S",     "Swift.String",
                                      "s",     "Swift.Substring",
                                      "T",     "Swift.Sequence",
                                      "t",     "Swift.IteratorProtocol",
                                      "U",     "Swift.UnsignedInteger",
                                      "u",     "Swift.UInt",
                                      "V",     "Swift.UnsafeRawPointer",
                                      "v",     "Swift.UnsafeMutableRawPointer",
                                      "W",     "Swift.UnsafeRawBufferPointer",
                                      "w",     "Swift.UnsafeMutableRawBufferPointer",
                                      "X",     "Swift.RangeExpression",
                                      "x",     "Swift.Strideable",
                                      "Y",     "Swift.RawRepresentable",
                                      "y",     "Swift.StringProtocol",
                                      "Z",     "Swift.SignedInteger",
                                      "z",     "Swift.BinaryInteger",
                                      nullptr, nullptr};
        for (qint32 i = 0; known[i] != nullptr; i += 2) {
            if (letter == QChar(known[i][0])) {
                sType = QString(known[i + 1]);
                bKnownOk = true;
                break;
            }
        }
        if (!bKnownOk) {
            pI->bErrored = true;
            return;
        }
        for (qint64 k = 0; k < nRepeat; k++) {
            swift_push(pI, SWK_TYPE, sType);
        }
        return;
    }

    if (c == QChar('g')) {  // Optional sugar: type 'Sg' -> type?  (function types need parens)
        pI->nPos++;
        SWNODE inner;
        if (!swift_pop(pI, &inner)) return;
        QString sInner = inner.bFunc ? (QString("(") + inner.sText + QString(")")) : inner.sText;
        // 'A?' is really Optional<A>, a bound generic -> Swift adds it to the substitution list.
        swift_pushSubst(pI, SWK_TYPE, sInner + QString("?"));
        return;
    }

    if (c == QChar('c')) {  // concurrency types (Sc + letter)
        pI->nPos++;
        QChar d = swift_nextc(pI);
        if (pI->bErrored) return;
        static const char *conc[] = {"A",     "Swift.Actor",
                                     "C",     "Swift.CheckedContinuation",
                                     "c",     "Swift.UnsafeContinuation",
                                     "E",     "Swift.CancellationError",
                                     "e",     "Swift.UnownedSerialExecutor",
                                     "F",     "Swift.Executor",
                                     "f",     "Swift.SerialExecutor",
                                     "G",     "Swift.TaskGroup",
                                     "g",     "Swift.ThrowingTaskGroup",
                                     "I",     "Swift.AsyncIteratorProtocol",
                                     "i",     "Swift.AsyncSequence",
                                     "J",     "Swift.UnownedJob",
                                     "M",     "Swift.MainActor",
                                     "P",     "Swift.TaskPriority",
                                     "S",     "Swift.AsyncStream",
                                     "s",     "Swift.AsyncThrowingStream",
                                     "T",     "Swift.Task",
                                     "t",     "Swift.UnsafeCurrentTask",
                                     nullptr, nullptr};
        for (qint32 i = 0; conc[i] != nullptr; i += 2) {
            if (d == QChar(conc[i][0])) {
                swift_push(pI, SWK_TYPE, QString(conc[i + 1]));
                return;
            }
        }
        pI->bErrored = true;
        return;
    }

    // single known-type letter
    QChar letter = swift_nextc(pI);
    if (pI->bErrored) return;
    static const char *known2[] = {"A",     "AutoreleasingUnsafeMutablePointer",
                                   "a",     "Swift.Array",
                                   "B",     "Swift.BinaryFloatingPoint",
                                   "b",     "Swift.Bool",
                                   "D",     "Swift.Dictionary",
                                   "d",     "Swift.Double",
                                   "E",     "Swift.Encodable",
                                   "e",     "Swift.Decodable",
                                   "F",     "Swift.FloatingPoint",
                                   "f",     "Swift.Float",
                                   "G",     "Swift.RandomNumberGenerator",
                                   "H",     "Swift.Hashable",
                                   "h",     "Swift.Set",
                                   "I",     "Swift.DefaultIndices",
                                   "i",     "Swift.Int",
                                   "J",     "Swift.Character",
                                   "j",     "Swift.Numeric",
                                   "K",     "Swift.BidirectionalCollection",
                                   "k",     "Swift.RandomAccessCollection",
                                   "L",     "Swift.Comparable",
                                   "l",     "Swift.Collection",
                                   "M",     "Swift.MutableCollection",
                                   "m",     "Swift.RangeReplaceableCollection",
                                   "N",     "Swift.ClosedRange",
                                   "n",     "Swift.Range",
                                   "O",     "Swift.ObjectIdentifier",
                                   "P",     "Swift.UnsafePointer",
                                   "p",     "Swift.UnsafeMutablePointer",
                                   "Q",     "Swift.Equatable",
                                   "q",     "Swift.Optional",
                                   "R",     "Swift.UnsafeBufferPointer",
                                   "r",     "Swift.UnsafeMutableBufferPointer",
                                   "S",     "Swift.String",
                                   "s",     "Swift.Substring",
                                   "T",     "Swift.Sequence",
                                   "t",     "Swift.IteratorProtocol",
                                   "U",     "Swift.UnsignedInteger",
                                   "u",     "Swift.UInt",
                                   "V",     "Swift.UnsafeRawPointer",
                                   "v",     "Swift.UnsafeMutableRawPointer",
                                   "W",     "Swift.UnsafeRawBufferPointer",
                                   "w",     "Swift.UnsafeMutableRawBufferPointer",
                                   "X",     "Swift.RangeExpression",
                                   "x",     "Swift.Strideable",
                                   "Y",     "Swift.RawRepresentable",
                                   "y",     "Swift.StringProtocol",
                                   "Z",     "Swift.SignedInteger",
                                   "z",     "Swift.BinaryInteger",
                                   nullptr, nullptr};
    for (qint32 i = 0; known2[i] != nullptr; i += 2) {
        if (letter == QChar(known2[i][0])) {
            swift_push(pI, SWK_TYPE, QString(known2[i + 1]));
            return;
        }
    }
    pI->bErrored = true;
}

void XDemangle::swift_demangleBuiltin(SWIFTINFO *pI)
{
    // 'B' already consumed.
    QChar c = swift_nextc(pI);
    if (pI->bErrored) return;

    if (c == QChar('p')) {
        swift_push(pI, SWK_TYPE, "Builtin.RawPointer");
        return;
    }
    if (c == QChar('o')) {
        swift_push(pI, SWK_TYPE, "Builtin.NativeObject");
        return;
    }
    if (c == QChar('O')) {
        swift_push(pI, SWK_TYPE, "Builtin.UnknownObject");
        return;
    }
    if (c == QChar('b')) {
        swift_push(pI, SWK_TYPE, "Builtin.BridgeObject");
        return;
    }
    if (c == QChar('t')) {
        swift_push(pI, SWK_TYPE, "Builtin.SILToken");
        return;
    }
    if (c == QChar('w')) {
        swift_push(pI, SWK_TYPE, "Builtin.Word");
        return;
    }
    if (c == QChar('i')) {  // Bi<N>_ integer
        bool bOk = false;
        qint64 n = swift_parseNatural(pI, &bOk);
        if (!bOk || !swift_eat(pI, QChar('_'))) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_TYPE, QString("Builtin.Int%1").arg(n));
        return;
    }
    if (c == QChar('f')) {  // Bf<N>_ float
        bool bOk = false;
        qint64 n = swift_parseNatural(pI, &bOk);
        if (!bOk || !swift_eat(pI, QChar('_'))) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_TYPE, QString("Builtin.FPIEEE%1").arg(n));
        return;
    }
    if (c == QChar('v')) {  // Bv<N>_<element> vector
        bool bOk = false;
        qint64 n = swift_parseNatural(pI, &bOk);
        if (!bOk || !swift_eat(pI, QChar('_'))) {
            pI->bErrored = true;
            return;
        }
        SWNODE elem;
        if (!swift_pop(pI, &elem)) return;
        QString sElem = elem.sText;
        if (sElem.startsWith("Builtin.")) sElem = sElem.mid(8);
        swift_push(pI, SWK_TYPE, QString("Builtin.Vec%1x%2").arg(n).arg(sElem));
        return;
    }
    pI->bErrored = true;
}

void XDemangle::swift_demangleNominal(SWIFTINFO *pI, QChar cKind)
{
    Q_UNUSED(cKind)
    // context decl-name (C|V|O) : pop name (ident), pop context (type/ident).
    SWNODE name;
    if (!swift_pop(pI, &name)) return;
    SWNODE context;
    if (!swift_pop(pI, &context)) return;
    if (name.nKind != SWK_IDENT) {
        pI->bErrored = true;
        return;
    }
    // A nominal context is always a module or another nominal type; if it is a rendered
    // entity (contains a signature separator) this is really some other 'P'/'a' form
    // (e.g. a private-discriminator) we do not model -> fall back to raw, never guess.
    if (context.sText.contains(" : ") || context.sText.contains(" -> ")) {
        pI->bErrored = true;
        return;
    }

    // The module (context) is already in the substitution list: it was added when its
    // identifier was parsed. The nominal TYPE itself is added here, in order.
    QString sFull = context.sText + QString(".") + name.sText;
    SWNODE node;
    node.nKind = SWK_TYPE;
    node.sText = sFull;
    node.cKind = cKind;  // C=class / V=struct / O=enum / a=typealias / P=protocol
    pI->stackNodes.append(node);
    pI->listSubst.append(node);
}

void XDemangle::swift_demangleBoundGeneric(SWIFTINFO *pI)
{
    // 'G' already consumed. args are the type-list back to the 'y' marker; base is below.
    QList<SWNODE> listArgs = swift_popTypeList(pI);
    SWNODE base;
    if (!swift_pop(pI, &base)) return;
    if (listArgs.isEmpty()) {
        pI->bErrored = true;
        return;
    }

    QString sBase = base.sText;
    QStringList slArgs;
    for (qint32 i = 0; i < listArgs.size(); i++) slArgs.append(listArgs.at(i).sText);

    QString sResult;
    if ((sBase == "Swift.Array") && (slArgs.size() == 1)) {
        sResult = QString("[") + slArgs.at(0) + QString("]");
    } else if ((sBase == "Swift.Optional") && (slArgs.size() == 1)) {
        QString sInner = listArgs.at(0).bFunc ? (QString("(") + slArgs.at(0) + QString(")")) : slArgs.at(0);
        sResult = sInner + QString("?");
    } else if ((sBase == "Swift.Dictionary") && (slArgs.size() == 2)) {
        sResult = QString("[") + slArgs.at(0) + QString(" : ") + slArgs.at(1) + QString("]");
    } else {
        // Swift's printer nests angle brackets without a separating space (unlike C++).
        sResult = sBase + QString("<") + slArgs.join(", ") + QString(">");
    }

    swift_pushSubst(pI, SWK_TYPE, sResult);
}

void XDemangle::swift_demangleTuple(SWIFTINFO *pI)
{
    // 't' already consumed.  type-list ::= list-type '_' list-type*  |  empty-list 'y'
    // list-type ::= type identifier?   (each element is a type with an OPTIONAL trailing
    // label identifier). The '_' marker separates the first element from the rest.
    QList<SWNODE> above;
    QString sMarker;
    while (!pI->stackNodes.isEmpty()) {
        if (pI->stackNodes.last().nKind == SWK_LISTMARK) {
            sMarker = pI->stackNodes.last().sText;
            pI->stackNodes.removeLast();
            break;
        }
        above.prepend(pI->stackNodes.takeLast());
    }
    // Ordered element nodes: [first-element nodes below '_'] ++ above.
    QList<SWNODE> elems;
    if (sMarker == "_") {
        SWNODE top;
        if (!swift_pop(pI, &top)) return;
        if (top.nKind == SWK_IDENT) {  // trailing label sits on top of its type
            SWNODE ty;
            if (!swift_pop(pI, &ty)) return;
            if (ty.nKind != SWK_TYPE) {
                pI->bErrored = true;
                return;
            }
            elems.append(ty);
            elems.append(top);
        } else if (top.nKind == SWK_TYPE) {
            elems.append(top);
        } else {
            pI->bErrored = true;
            return;
        }
    }
    for (qint32 i = 0; i < above.size(); i++) elems.append(above.at(i));

    // Walk the elements: a TYPE, optionally followed by an IDENT label.
    QStringList slDisplay;
    QStringList slBare;
    qint32 i = 0;
    while (i < elems.size()) {
        if (elems.at(i).nKind != SWK_TYPE) {
            pI->bErrored = true;
            return;
        }
        QString sTy = elems.at(i).sText;
        i++;
        if ((i < elems.size()) && (elems.at(i).nKind == SWK_IDENT)) {
            slDisplay.append(elems.at(i).sText + QString(": ") + sTy);
            i++;
        } else {
            slDisplay.append(sTy);
        }
        slBare.append(sTy);
    }

    SWNODE node;
    node.nKind = SWK_TYPE;
    node.slItems = slBare;  // bare element types (for function-param re-labeling)
    node.bTuple = true;
    node.sText = QString("(") + slDisplay.join(", ") + QString(")");
    pI->stackNodes.append(node);
}

void XDemangle::swift_demangleSubstitution(SWIFTINFO *pI)
{
    // 'A' already consumed. This is a run of one-or-more back-references:
    //   lowercase [a-z]            -> substitution index (0..25), more follow
    //   uppercase [A-Z]            -> substitution index (0..25), last in the run
    //   NATURAL before a letter    -> repeat that substitution NATURAL times
    //   NATURAL? '_'               -> single substitution of index (NATURAL+1)+26, or 26
    // (mirrors libswiftDemangling's demangleMultiSubstitutions.)
    qint64 nRepeat = -1;
    while (true) {
        QChar c = swift_peek(pI);
        if ((c >= QChar('a')) && (c <= QChar('z'))) {
            qint64 nIndex = c.unicode() - 'a';
            if ((nIndex < 0) || (nIndex >= pI->listSubst.size())) {
                pI->bErrored = true;
                return;
            }
            SWNODE node = pI->listSubst.at((qint32)nIndex);
            qint64 nCopies = (nRepeat > 1) ? nRepeat : 1;
            for (qint64 k = 0; k < nCopies; k++) pI->stackNodes.append(node);
            nRepeat = -1;
            pI->nPos++;
            continue;
        }
        if ((c >= QChar('A')) && (c <= QChar('Z'))) {
            qint64 nIndex = c.unicode() - 'A';
            if ((nIndex < 0) || (nIndex >= pI->listSubst.size())) {
                pI->bErrored = true;
                return;
            }
            SWNODE node = pI->listSubst.at((qint32)nIndex);
            qint64 nCopies = (nRepeat > 1) ? nRepeat : 1;
            for (qint64 k = 0; k < nCopies; k++) pI->stackNodes.append(node);
            pI->nPos++;
            return;
        }
        if (c == QChar('_')) {
            pI->nPos++;
            qint64 nIndex = ((nRepeat < 0) ? 0 : (nRepeat + 1)) + 26;
            if ((nIndex < 0) || (nIndex >= pI->listSubst.size())) {
                pI->bErrored = true;
                return;
            }
            pI->stackNodes.append(pI->listSubst.at((qint32)nIndex));
            return;
        }
        if ((c >= QChar('0')) && (c <= QChar('9'))) {
            bool bOk = false;
            nRepeat = swift_parseNatural(pI, &bOk);
            // Bound the repeat/index (real values are tiny) so a huge count can't drive
            // an unbounded append loop (OOM / hang) on crafted input.
            if (!bOk || (nRepeat > 4096)) {
                pI->bErrored = true;
                return;
            }
            continue;
        }
        pI->bErrored = true;
        return;
    }
}

void XDemangle::swift_demangleFunction(SWIFTINFO *pI)
{
    // 'F' already consumed. Stack (bottom->top): context, decl-name, [label-list 'y'],
    // result-type, params-type, [effects...], [generic-sig].
    QString sGenericSig = swift_takeGenericSig(pI);
    QString sEffects;
    while (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_EFFECT)) {
        SWNODE e = pI->stackNodes.takeLast();
        sEffects.prepend(e.sText);  // keep the mangled order (async before throws)
    }

    SWNODE params;
    if (!swift_pop(pI, &params)) return;
    SWNODE result;
    if (!swift_pop(pI, &result)) return;

    // Label-list (mandatory for functions): the empty-list marker 'y' means no labels;
    // otherwise there is one label per parameter, each an identifier or the empty-label
    // marker '_' (which prints as "_:").
    qint32 nParams = params.bTuple ? params.slItems.size() : (((params.nKind == SWK_LISTMARK) || params.sText.isEmpty()) ? 0 : 1);
    QStringList slLabels;
    bool bLabeled = false;
    if (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_LISTMARK) && (pI->stackNodes.last().sText == "y")) {
        pI->stackNodes.removeLast();  // no parameter labels
    } else if (nParams > 0) {
        for (qint32 i = 0; i < nParams; i++) {
            if (pI->stackNodes.isEmpty()) {
                pI->bErrored = true;
                return;
            }
            SWNODE lab = pI->stackNodes.last();
            if (lab.nKind == SWK_IDENT) {
                slLabels.prepend(lab.sText);
                pI->stackNodes.removeLast();
            } else if ((lab.nKind == SWK_LISTMARK) && (lab.sText == "_")) {
                slLabels.prepend("_");
                pI->stackNodes.removeLast();
            } else {
                pI->bErrored = true;
                return;
            }
        }
        bLabeled = true;
    }

    SWNODE name;
    if (!swift_pop(pI, &name)) return;
    SWNODE context;
    if (!swift_pop(pI, &context)) return;
    if (name.nKind != SWK_IDENT) {
        pI->bErrored = true;
        return;
    }

    QString sParams;
    if (bLabeled) {
        QStringList slParamTypes = params.bTuple ? params.slItems : QStringList(params.sText);
        QStringList slParts;
        for (qint32 i = 0; i < slParamTypes.size(); i++) {
            QString sLbl = (i < slLabels.size()) ? slLabels.at(i) : QString();
            slParts.append(sLbl.isEmpty() ? slParamTypes.at(i) : (sLbl + QString(": ") + slParamTypes.at(i)));
        }
        sParams = QString("(") + slParts.join(", ") + QString(")");
    } else {
        if ((params.nKind == SWK_LISTMARK) || params.sText.isEmpty()) {
            sParams = "()";
        } else if (params.bTuple) {
            sParams = params.sText;  // already parenthesized
        } else {
            sParams = QString("(") + params.sText + QString(")");  // single non-tuple param
        }
    }

    QString sResultText = ((result.nKind == SWK_LISTMARK) || result.sText.isEmpty()) ? QString("()") : result.sText;

    QString sResult = context.sText + QString(".") + name.sText + sGenericSig + sParams + sEffects + QString(" -> ") + sResultText;
    swift_push(pI, SWK_TYPE, sResult);
}

QString XDemangle::swift_parseGPIName(SWIFTINFO *pI, bool *pbOk)
{
    // GENERIC-PARAM-INDEX -> absolute positional name (depth 0 -> A,B; depth 1 -> A1,B1).
    *pbOk = true;
    QChar c = swift_peek(pI);
    if (c == QChar('z')) {
        pI->nPos++;
        return swift_genericParamName(0, 0);
    }
    if (c == QChar('d')) {
        pI->nPos++;
        bool b1 = false, b2 = false;
        qint64 nDepth = swift_parseIndex(pI, &b1);
        qint64 nIndex = swift_parseIndex(pI, &b2);
        if (!b1 || !b2) {
            *pbOk = false;
            return QString();
        }
        return swift_genericParamName(nDepth + 1, nIndex);
    }
    if (c == QChar('s')) {
        *pbOk = false;
        return QString();
    }  // constrained-existential Self: unmodeled
    bool b = false;
    qint64 nIndex = swift_parseIndex(pI, &b);
    if (!b) {
        *pbOk = false;
        return QString();
    }
    return swift_genericParamName(0, nIndex + 1);
}

void XDemangle::swift_demangleRequirement(SWIFTINFO *pI)
{
    // 'R' already consumed. The next char selects the requirement / marker kind.
    QChar d = swift_peek(pI);

    if (d == QChar('v')) {  // Rv GPI : generic parameter pack marker (variadic)
        pI->nPos++;
        bool bOk = false;
        QString sName = swift_parseGPIName(pI, &bOk);
        if (!bOk) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_PACKMARK, sName);
        return;
    }
    // Inverse requirements (Ri/RI/Rj/RJ, ~Copyable/~Escapable): the real demangler's
    // handling is subtle (it even rejects some encodings) and these never appear in
    // compiler-emitted symbols for ordinary code -> bail to raw, never guess.
    if ((d == QChar('i')) || (d == QChar('j'))) {
        pI->bErrored = true;
        return;
    }

    // Conformance: 'R' GENERIC-PARAM-INDEX (d is a GPI start: z / d / '_' / digit; NOT 's').
    if ((d == QChar('z')) || (d == QChar('d')) || (d == QChar('_')) || ((d >= QChar('0')) && (d <= QChar('9')))) {
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        if (!bOk) {
            pI->bErrored = true;
            return;
        }
        // In a requirement, a protocol is markerless: known protocols are one type node,
        // but a user protocol is module + name (combine into "module.name").
        SWNODE proto;
        if (!swift_pop(pI, &proto)) return;
        QString sProto = proto.sText;
        if (proto.nKind == SWK_IDENT) {
            SWNODE ctx;
            if (!swift_pop(pI, &ctx)) return;
            sProto = ctx.sText + QString(".") + proto.sText;
        }
        swift_push(pI, SWK_REQ, sSubj + QString(": ") + sProto);
        return;
    }

    pI->nPos++;             // consume the sub-op letter
    if (d == QChar('p')) {  // protocol assoc-type-name 'Rp' GPI -> "subj.assoc: proto"
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        SWNODE assoc;
        if (!swift_pop(pI, &assoc)) return;
        SWNODE proto;
        if (!swift_pop(pI, &proto)) return;
        QString sProto = proto.sText;
        if (proto.nKind == SWK_IDENT) {
            SWNODE ctx;
            if (!swift_pop(pI, &ctx)) return;
            sProto = ctx.sText + QString(".") + proto.sText;
        }
        if (!bOk || (assoc.nKind != SWK_IDENT)) {
            pI->bErrored = true;
            return;
        }
        // The dependent member type "subj.assoc" is itself substitutable -> Swift adds it.
        QString sDep = sSubj + QString(".") + assoc.sText;
        SWNODE dep;
        dep.nKind = SWK_TYPE;
        dep.sText = sDep;
        pI->listSubst.append(dep);
        swift_push(pI, SWK_REQ, sDep + QString(": ") + sProto);
        return;
    }
    if (d == QChar('b')) {  // type 'Rb' GPI -> base class "subj: Type"
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        SWNODE ty;
        if (!swift_pop(pI, &ty)) return;
        if (!bOk) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_REQ, sSubj + QString(": ") + ty.sText);
        return;
    }
    if (d == QChar('c')) {  // type assoc-type-name 'Rc' GPI -> "subj.assoc: Type"
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        SWNODE assoc;
        if (!swift_pop(pI, &assoc)) return;
        SWNODE ty;
        if (!swift_pop(pI, &ty)) return;
        if (!bOk || (assoc.nKind != SWK_IDENT)) {
            pI->bErrored = true;
            return;
        }
        QString sDep = sSubj + QString(".") + assoc.sText;
        SWNODE dep;
        dep.nKind = SWK_TYPE;
        dep.sText = sDep;
        pI->listSubst.append(dep);
        swift_push(pI, SWK_REQ, sDep + QString(": ") + ty.sText);
        return;
    }
    if (d == QChar('s')) {  // type 'Rs' GPI -> same-type "subj == Type"
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        SWNODE ty;
        if (!swift_pop(pI, &ty)) return;
        if (!bOk) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_REQ, sSubj + QString(" == ") + ty.sText);
        return;
    }
    if (d == QChar('t')) {  // type assoc-type-name 'Rt' GPI -> "subj.assoc == Type"
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        SWNODE assoc;
        if (!swift_pop(pI, &assoc)) return;
        SWNODE ty;
        if (!swift_pop(pI, &ty)) return;
        if (!bOk || (assoc.nKind != SWK_IDENT)) {
            pI->bErrored = true;
            return;
        }
        QString sDep = sSubj + QString(".") + assoc.sText;
        SWNODE dep;
        dep.nKind = SWK_TYPE;
        dep.sText = sDep;
        pI->listSubst.append(dep);
        swift_push(pI, SWK_REQ, sDep + QString(" == ") + ty.sText);
        return;
    }
    if (d == QChar('Q')) {  // protocol substitution 'RQ' -> conformance whose subject is a dependent-type subst
        SWNODE subj;
        if (!swift_pop(pI, &subj)) return;
        SWNODE proto;
        if (!swift_pop(pI, &proto)) return;
        QString sProto = proto.sText;
        if (proto.nKind == SWK_IDENT) {
            SWNODE ctx;
            if (!swift_pop(pI, &ctx)) return;
            sProto = ctx.sText + QString(".") + proto.sText;
        }
        swift_push(pI, SWK_REQ, subj.sText + QString(": ") + sProto);
        return;
    }
    if (d == QChar('l')) {  // 'Rl' GPI LAYOUT-CONSTRAINT -> "subj: Layout" (no type operand in practice)
        bool bOk = false;
        QString sSubj = swift_parseGPIName(pI, &bOk);
        QChar cl = swift_nextc(pI);
        if (pI->bErrored || !bOk) {
            pI->bErrored = true;
            return;
        }
        QString sLayout = swift_layoutName(cl);
        if (sLayout.isEmpty()) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_REQ, sSubj + QString(": ") + sLayout);
        return;
    }
    // Rh same-shape, RP/RC/RT assoc-list, RM/Rm layout-on-assoc, RQ/RB/RS/RI/RJ substitution
    // variants: less common -> not modeled, fall back to raw.
    pI->bErrored = true;
}

void XDemangle::swift_demangleParamCounts(SWIFTINFO *pI)
{
    // 'r' already consumed. Read GENERIC-PARAM-COUNT* up to the 'l' terminator.
    // COUNT ::= 'z' (0 params) | INDEX (N+1 params).
    QStringList slCounts;
    while (true) {
        QChar c = swift_peek(pI);
        if (c == QChar('l')) break;
        if (c == QChar('z')) {
            pI->nPos++;
            slCounts.append(QString("0"));
            continue;
        }
        if ((c == QChar('_')) || ((c >= QChar('0')) && (c <= QChar('9')))) {
            bool bOk = false;
            qint64 n = swift_parseIndex(pI, &bOk);
            if (!bOk) {
                pI->bErrored = true;
                return;
            }
            slCounts.append(QString::number(n + 1));
            continue;
        }
        pI->bErrored = true;
        return;
    }
    SWNODE node;
    node.nKind = SWK_COUNT;
    node.slItems = slCounts;
    pI->stackNodes.append(node);
}

void XDemangle::swift_finishGenericSig(SWIFTINFO *pI)
{
    // 'l' already consumed. Assemble "<params[ where reqs]>" from the trailing SWK_COUNT
    // (optional), pack markers and requirements on the stack. The printed parameter list
    // is the DEEPEST depth's params, named by index only (A, B, ...) -- so a depth-1
    // method param prints as "A" here even though its body form is "A1".
    qint64 nParams = 1;
    if (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_COUNT)) {
        SWNODE cnt = pI->stackNodes.takeLast();
        // A multi-depth signature (2+ counts) prints as one '<...>' group per depth with
        // depth-suffixed names -- not modeled here -> bail to raw rather than collapse it
        // to a single group (never occurs in compiler-emitted symbols).
        if (cnt.slItems.size() >= 2) {
            pI->bErrored = true;
            return;
        }
        if (cnt.slItems.isEmpty()) {
            nParams = 0;  // 'r' with no counts (e.g. constrained extension) -> requirements only
        } else {
            bool bOk = false;
            nParams = cnt.slItems.last().toLongLong(&bOk);
            if (!bOk) {
                pI->bErrored = true;
                return;
            }
        }
    }
    QStringList slPacks;
    QStringList slReqs;
    while (!pI->stackNodes.isEmpty() && ((pI->stackNodes.last().nKind == SWK_PACKMARK) || (pI->stackNodes.last().nKind == SWK_REQ))) {
        SWNODE n = pI->stackNodes.takeLast();
        if (n.nKind == SWK_PACKMARK) slPacks.append(n.sText);
        else slReqs.prepend(n.sText);
    }
    if ((nParams < 0) || (nParams > 64)) {
        pI->bErrored = true;
        return;
    }
    QStringList slParams;
    for (qint64 i = 0; i < nParams; i++) {
        QString nm = swift_genericParamName(0, i);
        if (slPacks.contains(nm)) nm = QString("each ") + nm;
        slParams.append(nm);
    }
    QString sSig = QString("<") + slParams.join(", ");
    if (!slReqs.isEmpty()) sSig += QString(" where ") + slReqs.join(", ");
    sSig += QString(">");
    SWNODE node;
    node.nKind = SWK_GENERICSIG;
    node.sText = sSig;
    pI->stackNodes.append(node);
}

QString XDemangle::swift_takeGenericSig(SWIFTINFO *pI)
{
    if (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_GENERICSIG)) {
        return pI->stackNodes.takeLast().sText;
    }
    return QString();
}

static QString swift_accessorSuffix(QChar cAcc, bool *pbOk)
{
    *pbOk = true;
    if (cAcc == QChar('g')) return QString(".getter");
    if (cAcc == QChar('G')) return QString(".getter");  // global getter
    if (cAcc == QChar('s')) return QString(".setter");
    if (cAcc == QChar('m')) return QString(".materializeForSet");
    if (cAcc == QChar('w')) return QString(".willset");
    if (cAcc == QChar('W')) return QString(".didset");
    if (cAcc == QChar('r')) return QString(".read");
    if (cAcc == QChar('M')) return QString(".modify");
    if (cAcc == QChar('x')) return QString(".modify2");
    if (cAcc == QChar('p')) return QString();  // pseudo (storage): no suffix
    *pbOk = false;                             // addressors (a/l), yield (y/b/z): not handled -> raw
    return QString();
}

void XDemangle::swift_demangleTop(SWIFTINFO *pI)
{
    QChar c = swift_peek(pI);

    if ((c >= QChar('0')) && (c <= QChar('9'))) {
        bool bOk = false;
        QString sIdent = swift_readIdentifier(pI, &bOk);
        if (!bOk) {
            pI->bErrored = true;
            return;
        }
        // Every identifier (module / decl-name / label / type-name) is added to the
        // substitution list, in order (known 'S...' types are NOT — see below).
        swift_pushSubst(pI, SWK_IDENT, sIdent);
        return;
    }

    if (c == QChar('S')) {
        // Module abbreviations SC (__C_Synthesized) / So (imported Obj-C, __C).
        QChar d = watcom_charAt(pI->sSym, pI->nPos + 1);
        if (d == QChar('C')) {
            pI->nPos += 2;
            swift_push(pI, SWK_IDENT, "__C_Synthesized");
            return;
        }
        if (d == QChar('o')) {
            pI->nPos += 2;
            swift_push(pI, SWK_IDENT, "__C");
            return;
        }
        pI->nPos++;
        swift_demangleKnownType(pI);
        return;
    }

    if (c == QChar('s')) {  // Swift standard module as a context
        pI->nPos++;
        swift_push(pI, SWK_IDENT, "Swift");
        return;
    }

    if (c == QChar('B')) {
        pI->nPos++;
        swift_demangleBuiltin(pI);
        return;
    }

    if ((c == QChar('C')) || (c == QChar('V')) || (c == QChar('O')) || (c == QChar('a')) || (c == QChar('P'))) {
        // class / struct / enum / typealias / protocol : all are "context decl-name X"
        pI->nPos++;
        swift_demangleNominal(pI, c);
        return;
    }

    if (c == QChar('y')) {  // empty-list / start-of-list marker
        pI->nPos++;
        swift_push(pI, SWK_LISTMARK, "y");
        return;
    }

    if (c == QChar('_')) {  // first-element marker (a tuple/list has a first element below it)
        pI->nPos++;
        swift_push(pI, SWK_LISTMARK, "_");
        return;
    }

    if (c == QChar('G')) {
        pI->nPos++;
        swift_demangleBoundGeneric(pI);
        return;
    }

    if (c == QChar('t')) {
        pI->nPos++;
        swift_demangleTuple(pI);
        return;
    }

    if (c == QChar('D')) {  // type-for-debugger: the top type is the whole result
        pI->nPos++;
        return;
    }

    if (c == QChar('F')) {
        pI->nPos++;
        swift_demangleFunction(pI);
        return;
    }

    if (c == QChar('A')) {
        pI->nPos++;
        swift_demangleSubstitution(pI);
        return;
    }

    if (c == QChar('x')) {  // first generic parameter
        pI->nPos++;
        swift_push(pI, SWK_TYPE, swift_genericParamName(0, 0));
        return;
    }

    if (c == QChar('q')) {  // other dependent generic parameter
        pI->nPos++;
        if (swift_eat(pI, QChar('d'))) {
            bool bOkD = false;
            qint64 nDepth = swift_parseIndex(pI, &bOkD);
            bool bOkI = false;
            qint64 nIndex = swift_parseIndex(pI, &bOkI);
            if (!bOkD || !bOkI) {
                pI->bErrored = true;
                return;
            }
            swift_push(pI, SWK_TYPE, swift_genericParamName(nDepth + 1, nIndex));
            return;
        }
        bool bOk = false;
        qint64 nIndex = swift_parseIndex(pI, &bOk);
        if (!bOk) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_TYPE, swift_genericParamName(0, nIndex + 1));
        return;
    }

    if (c == QChar('m')) {  // metatype
        pI->nPos++;
        SWNODE inner;
        if (!swift_pop(pI, &inner)) return;
        swift_push(pI, SWK_TYPE, inner.sText + QString(".Type"));
        return;
    }

    if (c == QChar('Y')) {  // signature effect / function-type attribute
        pI->nPos++;
        QChar d = swift_nextc(pI);
        if (pI->bErrored) return;
        if (d == QChar('a')) {
            swift_push(pI, SWK_EFFECT, " async");
            return;
        }
        if (d == QChar('b')) {
            swift_push(pI, SWK_ATTR, "@Sendable ");
            return;
        }
        if (d == QChar('j')) {  // @differentiable(...)
            QChar k = swift_nextc(pI);
            if (pI->bErrored) return;
            if (k == QChar('f')) swift_push(pI, SWK_ATTR, "@differentiable(_forward) ");
            else if (k == QChar('r')) swift_push(pI, SWK_ATTR, "@differentiable(reverse) ");
            else if (k == QChar('d')) swift_push(pI, SWK_ATTR, "@differentiable ");
            else if (k == QChar('l')) swift_push(pI, SWK_ATTR, "@differentiable(_linear) ");
            else pI->bErrored = true;
            return;
        }
        // Per-element markers modifying the top type (list-type attributes).
        if ((d == QChar('t')) || (d == QChar('k')) || (d == QChar('i'))) {
            if (pI->stackNodes.isEmpty() || (pI->stackNodes.last().nKind != SWK_TYPE)) {
                pI->bErrored = true;
                return;
            }
            QString sPre = (d == QChar('t')) ? QString("_const ") : ((d == QChar('k')) ? QString("@noDerivative ") : QString("isolated "));
            pI->stackNodes.last().sText.prepend(sPre);
            return;
        }
        pI->bErrored = true;
        return;
    }

    if ((c == QChar('z')) || (c == QChar('n')) || (c == QChar('h'))) {  // inout / __owned / __shared
        pI->nPos++;
        if (pI->stackNodes.isEmpty() || (pI->stackNodes.last().nKind != SWK_TYPE)) {
            pI->bErrored = true;
            return;
        }
        QString sPre = (c == QChar('z')) ? QString("inout ") : ((c == QChar('n')) ? QString("__owned ") : QString("__shared "));
        pI->stackNodes.last().sText.prepend(sPre);
        return;
    }

    if (c == QChar('d')) {  // variadic
        pI->nPos++;
        if (pI->stackNodes.isEmpty() || (pI->stackNodes.last().nKind != SWK_TYPE)) {
            pI->bErrored = true;
            return;
        }
        pI->stackNodes.last().sText.append("...");
        return;
    }

    if (c == QChar('K')) {  // throws
        pI->nPos++;
        swift_push(pI, SWK_EFFECT, " throws");
        return;
    }

    if ((c == QChar('c')) || (c == QChar('X'))) {  // function type
        pI->nPos++;
        QString sConv;
        if (c == QChar('X')) {
            QChar k = swift_nextc(pI);
            if (pI->bErrored) return;
            if (k == QChar('E')) sConv = "";  // @noescape (implicit in display)
            else if (k == QChar('f')) sConv = "@convention(thin) ";
            else if (k == QChar('C')) sConv = "@convention(c) ";
            else if (k == QChar('B')) sConv = "@convention(block) ";
            else {
                pI->bErrored = true;
                return;
            }
        }
        // Collect trailing prefix attributes (@Sendable/@differentiable) and postfix
        // effects (async/throws) that belong to this function type.
        QString sPrefix;
        QString sEffects;
        while (!pI->stackNodes.isEmpty() && ((pI->stackNodes.last().nKind == SWK_EFFECT) || (pI->stackNodes.last().nKind == SWK_ATTR))) {
            SWNODE e = pI->stackNodes.takeLast();
            if (e.nKind == SWK_ATTR) sPrefix += e.sText;  // pop-order == display order (reverse of mangled)
            else sEffects.prepend(e.sText);
        }
        SWNODE params;
        if (!swift_pop(pI, &params)) return;
        SWNODE result;
        if (!swift_pop(pI, &result)) return;
        QString sP;
        if ((params.nKind == SWK_LISTMARK) || params.sText.isEmpty()) sP = "()";
        else if (params.bTuple) sP = params.sText;             // already parenthesized
        else sP = QString("(") + params.sText + QString(")");  // single non-tuple param
        QString sR = ((result.nKind == SWK_LISTMARK) || result.sText.isEmpty()) ? QString("()") : result.sText;
        SWNODE fn;
        fn.nKind = SWK_TYPE;
        fn.sText = sPrefix + sConv + sP + sEffects + QString(" -> ") + sR;
        fn.slItems = params.slItems;                // param type texts (for entity re-render with labels)
        fn.sAux = sEffects + QString(" -> ") + sR;  // effects + result tail (for entity re-render)
        fn.bFunc = true;                            // needs parens when used under Optional '?' / sugar
        pI->stackNodes.append(fn);
        return;
    }

    if (c == QChar('p')) {  // existential (protocol composition): <protocol-list> p
        pI->nPos++;
        if (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_LISTMARK) && (pI->stackNodes.last().sText == "y")) {
            pI->stackNodes.removeLast();
            swift_push(pI, SWK_TYPE, "Any");
            return;
        }
        // Collect protocol names above the first-element marker, plus the one below it.
        QStringList slProt;
        QString sMarker;
        while (!pI->stackNodes.isEmpty()) {
            if (pI->stackNodes.last().nKind == SWK_LISTMARK) {
                sMarker = pI->stackNodes.last().sText;
                pI->stackNodes.removeLast();
                break;
            }
            SWNODE nm = pI->stackNodes.takeLast();
            SWNODE ctx;
            if (!swift_pop(pI, &ctx) || (nm.nKind != SWK_IDENT)) {
                pI->bErrored = true;
                return;
            }
            slProt.prepend(ctx.sText + QString(".") + nm.sText);
        }
        if (sMarker == "_") {
            SWNODE nm;
            if (!swift_pop(pI, &nm)) return;
            SWNODE ctx;
            if (!swift_pop(pI, &ctx) || (nm.nKind != SWK_IDENT)) {
                pI->bErrored = true;
                return;
            }
            slProt.prepend(ctx.sText + QString(".") + nm.sText);
        }
        if (slProt.isEmpty()) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_TYPE, slProt.join(" & "));
        return;
    }

    if (c == QChar('E')) {  // extension context: <extended-type> <module> generic-signature? 'E'
        pI->nPos++;
        QString sGenSig = swift_takeGenericSig(pI);  // constrained extension: "< where reqs>"
        SWNODE module;
        if (!swift_pop(pI, &module)) return;
        SWNODE type;
        if (!swift_pop(pI, &type)) return;
        if (module.nKind != SWK_IDENT) {
            pI->bErrored = true;
            return;
        }
        SWNODE node;
        node.nKind = SWK_TYPE;
        node.cKind = type.cKind;  // preserve class-ness for a possible extension initializer
        node.sText = QString("(extension in ") + module.sText + QString("):") + type.sText + sGenSig;
        pI->stackNodes.append(node);
        return;
    }

    if (c == QChar('Q')) {
        QChar d = watcom_charAt(pI->sSym, pI->nPos + 1);
        if (d == QChar('p')) {  // pack expansion: pattern-type count-type 'Qp' -> "repeat <pattern>"
            pI->nPos += 2;
            SWNODE count;
            if (!swift_pop(pI, &count)) return;  // shape/count operand (not printed)
            SWNODE pattern;
            if (!swift_pop(pI, &pattern)) return;
            swift_push(pI, SWK_TYPE, QString("repeat ") + pattern.sText);
            return;
        }
        if (d == QChar('z')) {  // 'Qz' = 'Qyz' : associated type of param (0,0) -> "A.<assoc>"
            pI->nPos += 2;
            SWNODE assoc;
            if (!swift_pop(pI, &assoc)) return;
            if (assoc.nKind != SWK_IDENT) {
                pI->bErrored = true;
                return;
            }
            swift_pushSubst(pI, SWK_TYPE, swift_genericParamName(0, 0) + QString(".") + assoc.sText);
            return;
        }
        if (d == QChar('y')) {  // 'Qy' GPI : associated type of param(GPI) -> "name(GPI).<assoc>"
            pI->nPos += 2;
            bool bOk = false;
            QString sName = swift_parseGPIName(pI, &bOk);
            SWNODE assoc;
            if (!swift_pop(pI, &assoc)) return;
            if (!bOk || (assoc.nKind != SWK_IDENT)) {
                pI->bErrored = true;
                return;
            }
            swift_pushSubst(pI, SWK_TYPE, sName + QString(".") + assoc.sText);
            return;
        }
        pI->bErrored = true;  // QY/QZ/Qx/QX assoc-list forms not modeled
        return;
    }

    if (c == QChar('R')) {  // generic-signature requirement / parameter marker
        pI->nPos++;
        swift_demangleRequirement(pI);
        return;
    }

    if (c == QChar('r')) {  // generic-signature parameter counts ('r' GENERIC-PARAM-COUNT*)
        pI->nPos++;
        swift_demangleParamCounts(pI);
        return;
    }

    if (c == QChar('l')) {  // generic-signature terminator -> assemble "<params where reqs>"
        pI->nPos++;
        swift_finishGenericSig(pI);
        return;
    }

    if (c == QChar('v')) {  // variable / property : decl-name label-list? type 'v' ACCESSOR
        pI->nPos++;
        QChar acc = swift_nextc(pI);
        if (pI->bErrored) return;
        bool bAccOk = false;
        QString sSuffix = swift_accessorSuffix(acc, &bAccOk);
        if (!bAccOk) {
            pI->bErrored = true;
            return;
        }
        SWNODE type;
        if (!swift_pop(pI, &type)) return;
        if (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_LISTMARK)) {
            pI->stackNodes.removeLast();  // optional label-list
        }
        SWNODE name;
        if (!swift_pop(pI, &name)) return;
        SWNODE context;
        if (!swift_pop(pI, &context)) return;
        if (name.nKind != SWK_IDENT) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_TYPE, context.sText + QString(".") + name.sText + sSuffix + QString(" : ") + type.sText);
        return;
    }

    if (c == QChar('i')) {  // subscript : label-list type 'i' ACCESSOR (name is "subscript")
        pI->nPos++;
        QChar acc = swift_nextc(pI);
        if (pI->bErrored) return;
        bool bAccOk = false;
        QString sSuffix = swift_accessorSuffix(acc, &bAccOk);
        if (!bAccOk) {
            pI->bErrored = true;
            return;
        }
        SWNODE type;
        if (!swift_pop(pI, &type)) return;
        // Label-list: 'y' => the type prints as-is; otherwise one label per parameter,
        // merged into the (function-typed) subscript signature (e.g. "(_unchecked: Int) -> A").
        QStringList slLabels;
        bool bLabeled = false;
        if (!pI->stackNodes.isEmpty() && (pI->stackNodes.last().nKind == SWK_LISTMARK) && (pI->stackNodes.last().sText == "y")) {
            pI->stackNodes.removeLast();
        } else if (type.bFunc) {  // only a function-typed subscript carries a parameter label-list
            qint32 n = type.slItems.size();
            for (qint32 k = 0; k < n; k++) {
                if (pI->stackNodes.isEmpty()) {
                    pI->bErrored = true;
                    return;
                }
                SWNODE lab = pI->stackNodes.last();
                if (lab.nKind == SWK_IDENT) {
                    slLabels.prepend(lab.sText);
                    pI->stackNodes.removeLast();
                } else if ((lab.nKind == SWK_LISTMARK) && (lab.sText == "_")) {
                    slLabels.prepend("_");
                    pI->stackNodes.removeLast();
                } else {
                    pI->bErrored = true;
                    return;
                }
            }
            bLabeled = true;
        }
        SWNODE context;
        if (!swift_pop(pI, &context)) return;
        QString sTypeStr;
        if (bLabeled) {
            QStringList slParts;
            for (qint32 k = 0; k < type.slItems.size(); k++) {
                QString sLbl = (k < slLabels.size()) ? slLabels.at(k) : QString();
                slParts.append(sLbl.isEmpty() ? type.slItems.at(k) : (sLbl + QString(": ") + type.slItems.at(k)));
            }
            sTypeStr = QString("(") + slParts.join(", ") + QString(")") + type.sAux;
        } else {
            sTypeStr = type.sText;
        }
        if ((acc == QChar('p')) && type.bFunc) {
            // The pseudo (storage) accessor prints a function-typed subscript declaration
            // itself as a signature: "Ctx.subscript(params) -> result" (no " : type").
            swift_push(pI, SWK_TYPE, context.sText + QString(".subscript") + sTypeStr);
        } else {
            swift_push(pI, SWK_TYPE, context.sText + QString(".subscript") + sSuffix + QString(" : ") + sTypeStr);
        }
        return;
    }

    if (c == QChar('f')) {  // function-ish entity: constructor / destructor
        pI->nPos++;
        QChar d = swift_nextc(pI);
        if (pI->bErrored) return;
        if ((d == QChar('C')) || (d == QChar('c'))) {  // allocating / non-allocating constructor
            SWNODE type;
            if (!swift_pop(pI, &type)) return;
            QStringList slLabels;
            qint32 n = type.slItems.size();
            for (qint32 k = 0; k < n; k++) {
                if (pI->stackNodes.isEmpty()) {
                    pI->bErrored = true;
                    return;
                }
                SWNODE lab = pI->stackNodes.last();
                if (lab.nKind == SWK_IDENT) {
                    slLabels.prepend(lab.sText);
                    pI->stackNodes.removeLast();
                } else if ((lab.nKind == SWK_LISTMARK) && (lab.sText == "_")) {
                    slLabels.prepend("_");
                    pI->stackNodes.removeLast();
                } else {
                    pI->bErrored = true;
                    return;
                }
            }
            SWNODE context;
            if (!swift_pop(pI, &context)) return;
            QString sName = ((d == QChar('C')) && (context.cKind == QChar('C'))) ? QString("__allocating_init") : QString("init");
            QStringList slParts;
            for (qint32 k = 0; k < type.slItems.size(); k++) {
                QString sLbl = (k < slLabels.size()) ? slLabels.at(k) : QString();
                slParts.append(sLbl.isEmpty() ? type.slItems.at(k) : (sLbl + QString(": ") + type.slItems.at(k)));
            }
            // type.sAux is the "[ effects] -> result" tail (preserves throws/async).
            QString sTail = type.sAux.isEmpty() ? QString(" -> ()") : type.sAux;
            swift_push(pI, SWK_TYPE, context.sText + QString(".") + sName + QString("(") + slParts.join(", ") + QString(")") + sTail);
            return;
        }
        if (d == QChar('D')) {  // deallocating destructor
            SWNODE context;
            if (!swift_pop(pI, &context)) return;
            swift_push(pI, SWK_TYPE, context.sText + QString(".__deallocating_deinit"));
            return;
        }
        if (d == QChar('d')) {  // destructor
            SWNODE context;
            if (!swift_pop(pI, &context)) return;
            swift_push(pI, SWK_TYPE, context.sText + QString(".deinit"));
            return;
        }
        if (d == QChar('i')) {  // non-local variable initializer: wraps the preceding variable
            SWNODE inner;
            if (!swift_pop(pI, &inner)) return;
            swift_push(pI, SWK_TYPE, QString("variable initialization expression of ") + inner.sText);
            return;
        }
        if (d == QChar('A')) {  // default argument N generator: 'fA' INDEX, wraps the preceding entity
            bool bOk = false;
            qint64 nIdx = swift_parseIndex(pI, &bOk);
            if (!bOk) {
                pI->bErrored = true;
                return;
            }
            SWNODE inner;
            if (!swift_pop(pI, &inner)) return;
            swift_push(pI, SWK_TYPE, QString("default argument %1 of ").arg(nIdx) + inner.sText);
            return;
        }
        pI->bErrored = true;
        return;
    }

    if (c == QChar('Z')) {  // static : postfix on the just-produced entity
        pI->nPos++;
        if (pI->stackNodes.isEmpty()) {
            pI->bErrored = true;
            return;
        }
        pI->stackNodes.last().sText.prepend("static ");
        return;
    }

    if (c == QChar('T')) {  // thunks / wrappers around the whole preceding entity
        pI->nPos++;
        QChar d = swift_nextc(pI);
        if (pI->bErrored) return;
        QString sPrefix;
        if (d == QChar('o')) sPrefix = "@objc ";
        else if (d == QChar('O')) sPrefix = "@nonobjc ";
        else if (d == QChar('m')) sPrefix = "merged ";
        else if (d == QChar('j')) sPrefix = "dispatch thunk of ";      // 'Tj' dispatch thunk
        else if (d == QChar('q')) sPrefix = "method descriptor for ";  // 'Tq' method descriptor
        else {
            pI->bErrored = true;
            return;
        }
        SWNODE inner;
        if (!swift_pop(pI, &inner)) return;
        swift_push(pI, SWK_TYPE, sPrefix + inner.sText);
        return;
    }

    if (c == QChar('M')) {  // type-metadata / descriptor accessors: 'M'<kind> wrapping a type or entity
        pI->nPos++;
        QChar d = swift_nextc(pI);
        if (pI->bErrored) return;
        QString sDesc;
        if (d == QChar('a')) sDesc = "type metadata accessor for ";
        else if (d == QChar('n')) sDesc = "nominal type descriptor for ";
        else if (d == QChar('p')) sDesc = "protocol descriptor for ";
        else if (d == QChar('o')) sDesc = "class metadata base offset for ";
        else if (d == QChar('u')) sDesc = "method lookup function for ";
        else if (d == QChar('V')) sDesc = "property descriptor for ";
        else if (d == QChar('f')) sDesc = "full type metadata for ";
        else if (d == QChar('m')) sDesc = "metaclass for ";
        else if (d == QChar('F')) sDesc = "reflection metadata field descriptor ";  // no "for"
        else {
            pI->bErrored = true;
            return;
        }
        SWNODE inner;
        if (!swift_pop(pI, &inner)) return;
        if (inner.nKind != SWK_TYPE) {
            pI->bErrored = true;
            return;
        }
        swift_push(pI, SWK_TYPE, sDesc + inner.sText);
        return;
    }

    if (c == QChar('W')) {  // witness-table accessors
        pI->nPos++;
        QChar d = swift_nextc(pI);
        if (pI->bErrored) return;
        if (d == QChar('V')) {  // 'WV' value witness table (WP/Wl conformance forms not modeled)
            SWNODE inner;
            if (!swift_pop(pI, &inner)) return;
            if (inner.nKind != SWK_TYPE) {
                pI->bErrored = true;
                return;
            }
            swift_push(pI, SWK_TYPE, QString("value witness table for ") + inner.sText);
            return;
        }
        pI->bErrored = true;
        return;
    }

    // Unsupported operator -> mark errored so the whole symbol falls back to raw.
    pI->bErrored = true;
}

QString XDemangle::swift_demangle(const QString &sString)
{
    QString sBody;

    if (sString.startsWith("_$s")) sBody = sString.mid(3);
    else if (sString.startsWith("$s")) sBody = sString.mid(2);
    else if (sString.startsWith("_$S")) sBody = sString.mid(3);
    else if (sString.startsWith("$S")) sBody = sString.mid(2);
    else return QString();  // not Swift (or old _T form, unsupported) -> raw

    SWIFTINFO info;
    info.sSym = sBody;
    info.nPos = 0;
    info.bErrored = false;

    while ((info.nPos < info.sSym.size()) && !info.bErrored) {
        swift_demangleTop(&info);
    }

    // All-or-nothing: the whole body must parse into exactly one node.
    if (info.bErrored || (info.nPos != info.sSym.size()) || (info.stackNodes.size() != 1)) {
        return QString();
    }

    return info.stackNodes.at(0).sText;
}

// --- D language --------------------------------------------------------------
//
// Native port of libiberty's d-demangle.c. Positions are absolute indices into
// pInfo->sMangled; every parse function returns the new position or -1 on
// failure (mirroring the C code's "return the rest, or NULL"). The all-or-nothing
// contract of the entry point is preserved: leftover bytes => failure.

qint32 XDemangle::dlang_number(qint32 nPos, DLANGINFO *pInfo, quint32 *pnRet)
{
    if (nPos < 0) {
        return -1;
    }

    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (!((c >= QChar('0')) && (c <= QChar('9')))) {
        return -1;
    }

    quint32 nVal = 0;

    while ((c = watcom_charAt(pInfo->sMangled, nPos), (c >= QChar('0')) && (c <= QChar('9')))) {
        quint32 nDigit = (quint32)(c.unicode() - '0');

        if (nVal > (0xFFFFFFFFu - nDigit) / 10) {
            return -1;  // overflow
        }

        nVal = nVal * 10 + nDigit;
        nPos++;
    }

    if (watcom_charAt(pInfo->sMangled, nPos) == QChar('\0')) {
        return -1;  // a number must be followed by something
    }

    *pnRet = nVal;

    return nPos;
}

qint32 XDemangle::dlang_hexdigit(qint32 nPos, DLANGINFO *pInfo, qint32 *pnRet)
{
    qint32 nHigh = watcom_charToDigit(watcom_charAt(pInfo->sMangled, nPos));
    qint32 nLow = watcom_charToDigit(watcom_charAt(pInfo->sMangled, nPos + 1));

    if ((nHigh < 0) || (nHigh >= 16) || (nLow < 0) || (nLow >= 16)) {
        return -1;
    }

    *pnRet = (nHigh << 4) | nLow;

    return nPos + 2;
}

bool XDemangle::dlang_call_convention_p(QChar cChar)
{
    return ((cChar == QChar('F')) || (cChar == QChar('U')) || (cChar == QChar('V')) || (cChar == QChar('W')) || (cChar == QChar('R')) || (cChar == QChar('Y')));
}

qint32 XDemangle::dlang_decode_backref(qint32 nPos, DLANGINFO *pInfo, quint64 *pnRet)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (!(((c >= QChar('A')) && (c <= QChar('Z'))) || ((c >= QChar('a')) && (c <= QChar('z'))))) {
        return -1;
    }

    quint64 nVal = 0;

    while (true) {
        c = watcom_charAt(pInfo->sMangled, nPos);

        if (!(((c >= QChar('A')) && (c <= QChar('Z'))) || ((c >= QChar('a')) && (c <= QChar('z'))))) {
            break;
        }

        if (nVal > (0xFFFFFFFFFFFFFFFFULL - 25) / 26) {
            return -1;  // overflow
        }

        nVal *= 26;

        if ((c >= QChar('a')) && (c <= QChar('z'))) {  // final (least significant) digit
            nVal += (quint64)(c.unicode() - 'a');

            if ((qint64)nVal <= 0) {
                return -1;
            }

            *pnRet = nVal;

            return nPos + 1;
        }

        nVal += (quint64)(c.unicode() - 'A');
        nPos++;
    }

    return -1;
}

qint32 XDemangle::dlang_backref(qint32 nPos, DLANGINFO *pInfo, qint32 *pnTarget)
{
    *pnTarget = -1;

    if (watcom_charAt(pInfo->sMangled, nPos) != QChar('Q')) {
        return -1;
    }

    qint32 nQPos = nPos;
    nPos++;

    quint64 nRefPos = 0;
    nPos = dlang_decode_backref(nPos, pInfo, &nRefPos);

    if (nPos < 0) {
        return -1;
    }

    if (nRefPos > (quint64)nQPos) {  // cannot point before the string start
        return -1;
    }

    *pnTarget = nQPos - (qint32)nRefPos;

    return nPos;
}

qint32 XDemangle::dlang_symbol_backref(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    qint32 nBackref = -1;
    nPos = dlang_backref(nPos, pInfo, &nBackref);

    if (nPos < 0) {
        return -1;
    }

    quint32 nLen = 0;
    nBackref = dlang_number(nBackref, pInfo, &nLen);

    if (nBackref < 0) {
        return -1;
    }

    nBackref = dlang_lname(psDecl, nBackref, nLen, pInfo);

    if (nBackref < 0) {
        return -1;
    }

    return nPos;
}

qint32 XDemangle::dlang_type_backref(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, bool bIsFunction)
{
    if (nPos >= pInfo->nLastBackref) {  // must reference strictly earlier than the previous type backref
        return -1;
    }

    qint32 nSave = pInfo->nLastBackref;
    pInfo->nLastBackref = nPos;

    qint32 nTarget = -1;
    qint32 nAfter = dlang_backref(nPos, pInfo, &nTarget);
    qint32 nParsed = -1;

    if (nAfter >= 0) {
        if (bIsFunction) {
            nParsed = dlang_function_type(psDecl, nTarget, pInfo);
        } else {
            nParsed = dlang_type(psDecl, nTarget, pInfo);
        }
    }

    pInfo->nLastBackref = nSave;

    if ((nAfter < 0) || (nParsed < 0)) {
        return -1;
    }

    return nAfter;
}

bool XDemangle::dlang_symbol_name_p(qint32 nPos, DLANGINFO *pInfo)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if ((c >= QChar('0')) && (c <= QChar('9'))) {
        return true;
    }

    if ((watcom_charAt(pInfo->sMangled, nPos) == QChar('_')) && (watcom_charAt(pInfo->sMangled, nPos + 1) == QChar('_')) &&
        ((watcom_charAt(pInfo->sMangled, nPos + 2) == QChar('T')) || (watcom_charAt(pInfo->sMangled, nPos + 2) == QChar('U')))) {
        return true;
    }

    if (c != QChar('Q')) {
        return false;
    }

    qint32 nQPos = nPos;
    quint64 nRet = 0;
    qint32 nAfter = dlang_decode_backref(nPos + 1, pInfo, &nRet);

    if ((nAfter < 0) || (nRet > (quint64)nQPos)) {
        return false;
    }

    QChar cTarget = watcom_charAt(pInfo->sMangled, nQPos - (qint32)nRet);

    return ((cTarget >= QChar('0')) && (cTarget <= QChar('9')));
}

qint32 XDemangle::dlang_call_convention(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (c == QChar('\0')) {
        return -1;
    }

    if (c == QChar('F')) {
        nPos++;  // D default - no text
    } else if (c == QChar('U')) {
        nPos++;
        *psDecl += "extern(C) ";
    } else if (c == QChar('W')) {
        nPos++;
        *psDecl += "extern(Windows) ";
    } else if (c == QChar('V')) {
        nPos++;
        *psDecl += "extern(Pascal) ";
    } else if (c == QChar('R')) {
        nPos++;
        *psDecl += "extern(C++) ";
    } else if (c == QChar('Y')) {
        nPos++;
        *psDecl += "extern(Objective-C) ";
    } else {
        return -1;
    }

    return nPos;
}

qint32 XDemangle::dlang_type_modifiers(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (c == QChar('\0')) {
        return -1;
    }

    if (c == QChar('x')) {
        nPos++;
        *psDecl += " const";
        return nPos;
    }

    if (c == QChar('y')) {
        nPos++;
        *psDecl += " immutable";
        return nPos;
    }

    if (c == QChar('O')) {
        nPos++;
        *psDecl += " shared";
        return dlang_type_modifiers(psDecl, nPos, pInfo);
    }

    if (c == QChar('N')) {
        nPos++;

        if (watcom_charAt(pInfo->sMangled, nPos) == QChar('g')) {
            nPos++;
            *psDecl += " inout";
            return dlang_type_modifiers(psDecl, nPos, pInfo);
        }

        return -1;
    }

    return nPos;  // consume nothing, succeed
}

qint32 XDemangle::dlang_attributes(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    while (watcom_charAt(pInfo->sMangled, nPos) == QChar('N')) {
        QChar c = watcom_charAt(pInfo->sMangled, nPos + 1);

        if (c == QChar('a')) {
            nPos += 2;
            *psDecl += "pure ";
        } else if (c == QChar('b')) {
            nPos += 2;
            *psDecl += "nothrow ";
        } else if (c == QChar('c')) {
            nPos += 2;
            *psDecl += "ref ";
        } else if (c == QChar('d')) {
            nPos += 2;
            *psDecl += "@property ";
        } else if (c == QChar('e')) {
            nPos += 2;
            *psDecl += "@trusted ";
        } else if (c == QChar('f')) {
            nPos += 2;
            *psDecl += "@safe ";
        } else if (c == QChar('i')) {
            nPos += 2;
            *psDecl += "@nogc ";
        } else if (c == QChar('j')) {
            nPos += 2;
            *psDecl += "return ";
        } else if (c == QChar('l')) {
            nPos += 2;
            *psDecl += "scope ";
        } else if (c == QChar('m')) {
            nPos += 2;
            *psDecl += "@live ";
        } else if ((c == QChar('g')) || (c == QChar('h')) || (c == QChar('k'))) {
            break;  // Ng/Nh/Nk are parameter markers, not attributes - leave for the caller
        } else {
            return -1;
        }
    }

    return nPos;
}

qint32 XDemangle::dlang_function_type_noreturn(QString *psArgs, QString *psCall, QString *psAttr, qint32 nPos, DLANGINFO *pInfo)
{
    QString sDump;

    nPos = dlang_call_convention(psCall ? psCall : &sDump, nPos, pInfo);

    if (nPos < 0) {
        return -1;
    }

    nPos = dlang_attributes(psAttr ? psAttr : &sDump, nPos, pInfo);

    if (nPos < 0) {
        return -1;
    }

    if (psArgs) {
        *psArgs += "(";
    }

    nPos = dlang_function_args(psArgs ? psArgs : &sDump, nPos, pInfo);

    if (nPos < 0) {
        return -1;
    }

    if (psArgs) {
        *psArgs += ")";
    }

    return nPos;
}

qint32 XDemangle::dlang_function_type(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    if (watcom_charAt(pInfo->sMangled, nPos) == QChar('\0')) {
        return -1;
    }

    QString sAttr;
    QString sArgs;
    QString sType;

    // Mangled: CallConvention FuncAttrs Arguments ReturnType. The calling
    // convention text is written straight into decl (psCall == psDecl).
    nPos = dlang_function_type_noreturn(&sArgs, psDecl, &sAttr, nPos, pInfo);

    if (nPos < 0) {
        return -1;
    }

    nPos = dlang_type(&sType, nPos, pInfo);  // return type

    if (nPos < 0) {
        return -1;
    }

    *psDecl += sType + sArgs + QString(" ") + sAttr;

    return nPos;
}

qint32 XDemangle::dlang_function_args(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    qint32 n = 0;

    while (watcom_charAt(pInfo->sMangled, nPos) != QChar('\0')) {
        QChar c = watcom_charAt(pInfo->sMangled, nPos);

        if (c == QChar('X')) {  // typesafe variadic
            nPos++;
            *psDecl += "...";
            return nPos;
        }

        if (c == QChar('Y')) {  // C-style variadic
            nPos++;
            if (n != 0) {
                *psDecl += ", ";
            }
            *psDecl += "...";
            return nPos;
        }

        if (c == QChar('Z')) {  // end of arguments
            nPos++;
            return nPos;
        }

        if (n++ != 0) {
            *psDecl += ", ";
        }

        if (watcom_charAt(pInfo->sMangled, nPos) == QChar('M')) {
            nPos++;
            *psDecl += "scope ";
        }

        if ((watcom_charAt(pInfo->sMangled, nPos) == QChar('N')) && (watcom_charAt(pInfo->sMangled, nPos + 1) == QChar('k'))) {
            nPos += 2;
            *psDecl += "return ";
        }

        c = watcom_charAt(pInfo->sMangled, nPos);

        if (c == QChar('I')) {
            nPos++;
            *psDecl += "in ";

            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('K')) {
                nPos++;
                *psDecl += "ref ";
            }
        } else if (c == QChar('J')) {
            nPos++;
            *psDecl += "out ";
        } else if (c == QChar('K')) {
            nPos++;
            *psDecl += "ref ";
        } else if (c == QChar('L')) {
            nPos++;
            *psDecl += "lazy ";
        }

        nPos = dlang_type(psDecl, nPos, pInfo);

        if (nPos < 0) {
            return -1;
        }
    }

    return nPos;
}

qint32 XDemangle::dlang_type(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (c == QChar('\0')) {
        return -1;
    }

    switch (c.unicode()) {
        case 'O':
            nPos++;
            *psDecl += "shared(";
            nPos = dlang_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += ")";
            return nPos;
        case 'x':
            nPos++;
            *psDecl += "const(";
            nPos = dlang_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += ")";
            return nPos;
        case 'y':
            nPos++;
            *psDecl += "immutable(";
            nPos = dlang_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += ")";
            return nPos;
        case 'N':
            nPos++;
            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('g')) {
                nPos++;
                *psDecl += "inout(";
                nPos = dlang_type(psDecl, nPos, pInfo);
                if (nPos < 0) return -1;
                *psDecl += ")";
                return nPos;
            }
            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('h')) {
                nPos++;
                *psDecl += "__vector(";
                nPos = dlang_type(psDecl, nPos, pInfo);
                if (nPos < 0) return -1;
                *psDecl += ")";
                return nPos;
            }
            return -1;
        case 'A':
            nPos++;
            nPos = dlang_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += "[]";
            return nPos;
        case 'G': {
            nPos++;
            QString sNum;
            while ((watcom_charAt(pInfo->sMangled, nPos) >= QChar('0')) && (watcom_charAt(pInfo->sMangled, nPos) <= QChar('9'))) {
                sNum += watcom_charAt(pInfo->sMangled, nPos);
                nPos++;
            }
            nPos = dlang_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += QString("[") + sNum + QString("]");
            return nPos;
        }
        case 'H': {
            nPos++;
            QString sKey;
            nPos = dlang_type(&sKey, nPos, pInfo);  // key type
            if (nPos < 0) return -1;
            nPos = dlang_type(psDecl, nPos, pInfo);  // value type
            if (nPos < 0) return -1;
            *psDecl += QString("[") + sKey + QString("]");
            return nPos;
        }
        case 'P':
            nPos++;
            if (!dlang_call_convention_p(watcom_charAt(pInfo->sMangled, nPos))) {
                nPos = dlang_type(psDecl, nPos, pInfo);
                if (nPos < 0) return -1;
                *psDecl += "*";
                return nPos;
            }
            nPos = dlang_function_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += "function";
            return nPos;
        case 'F':
        case 'U':
        case 'W':
        case 'V':
        case 'R':
        case 'Y':
            nPos = dlang_function_type(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += "function";
            return nPos;
        case 'C':
        case 'S':
        case 'E':
        case 'T': nPos++; return dlang_parse_qualified(psDecl, nPos, pInfo, false);
        case 'D': {
            nPos++;
            QString sMods;
            nPos = dlang_type_modifiers(&sMods, nPos, pInfo);
            if (nPos < 0) return -1;
            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('Q')) {
                nPos = dlang_type_backref(psDecl, nPos, pInfo, true);
            } else {
                nPos = dlang_function_type(psDecl, nPos, pInfo);
            }
            if (nPos < 0) return -1;
            *psDecl += QString("delegate") + sMods;
            return nPos;
        }
        case 'B': nPos++; return dlang_parse_tuple(psDecl, nPos, pInfo);
        case 'Q': return dlang_type_backref(psDecl, nPos, pInfo, false);
        case 'z':
            nPos++;
            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('i')) {
                nPos++;
                *psDecl += "cent";
                return nPos;
            }
            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('k')) {
                nPos++;
                *psDecl += "ucent";
                return nPos;
            }
            return -1;
        case 'n':
            nPos++;
            *psDecl += "none";
            return nPos;
        case 'v':
            nPos++;
            *psDecl += "void";
            return nPos;
        case 'g':
            nPos++;
            *psDecl += "byte";
            return nPos;
        case 'h':
            nPos++;
            *psDecl += "ubyte";
            return nPos;
        case 's':
            nPos++;
            *psDecl += "short";
            return nPos;
        case 't':
            nPos++;
            *psDecl += "ushort";
            return nPos;
        case 'i':
            nPos++;
            *psDecl += "int";
            return nPos;
        case 'k':
            nPos++;
            *psDecl += "uint";
            return nPos;
        case 'l':
            nPos++;
            *psDecl += "long";
            return nPos;
        case 'm':
            nPos++;
            *psDecl += "ulong";
            return nPos;
        case 'f':
            nPos++;
            *psDecl += "float";
            return nPos;
        case 'd':
            nPos++;
            *psDecl += "double";
            return nPos;
        case 'e':
            nPos++;
            *psDecl += "real";
            return nPos;
        case 'o':
            nPos++;
            *psDecl += "ifloat";
            return nPos;
        case 'p':
            nPos++;
            *psDecl += "idouble";
            return nPos;
        case 'j':
            nPos++;
            *psDecl += "ireal";
            return nPos;
        case 'q':
            nPos++;
            *psDecl += "cfloat";
            return nPos;
        case 'r':
            nPos++;
            *psDecl += "cdouble";
            return nPos;
        case 'c':
            nPos++;
            *psDecl += "creal";
            return nPos;
        case 'b':
            nPos++;
            *psDecl += "bool";
            return nPos;
        case 'a':
            nPos++;
            *psDecl += "char";
            return nPos;
        case 'u':
            nPos++;
            *psDecl += "wchar";
            return nPos;
        case 'w':
            nPos++;
            *psDecl += "dchar";
            return nPos;
        default: return -1;
    }
}

qint32 XDemangle::dlang_identifier(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (c == QChar('\0')) {
        return -1;
    }

    if (c == QChar('Q')) {
        return dlang_symbol_backref(psDecl, nPos, pInfo);
    }

    if ((watcom_charAt(pInfo->sMangled, nPos) == QChar('_')) && (watcom_charAt(pInfo->sMangled, nPos + 1) == QChar('_')) &&
        ((watcom_charAt(pInfo->sMangled, nPos + 2) == QChar('T')) || (watcom_charAt(pInfo->sMangled, nPos + 2) == QChar('U')))) {
        return dlang_parse_template(psDecl, nPos, pInfo, 0xFFFFFFFFu);
    }

    quint32 nLen = 0;
    qint32 nEnd = dlang_number(nPos, pInfo, &nLen);

    if ((nEnd < 0) || (nLen == 0)) {
        return -1;
    }

    if ((quint32)(pInfo->sMangled.size() - nEnd) < nLen) {
        return -1;  // not enough characters
    }

    nPos = nEnd;

    if ((nLen >= 5) && (watcom_charAt(pInfo->sMangled, nPos) == QChar('_')) && (watcom_charAt(pInfo->sMangled, nPos + 1) == QChar('_')) &&
        ((watcom_charAt(pInfo->sMangled, nPos + 2) == QChar('T')) || (watcom_charAt(pInfo->sMangled, nPos + 2) == QChar('U')))) {
        return dlang_parse_template(psDecl, nPos, pInfo, nLen);
    }

    return dlang_lname(psDecl, nPos, nLen, pInfo);
}

qint32 XDemangle::dlang_lname(QString *psDecl, qint32 nPos, quint32 nLen, DLANGINFO *pInfo)
{
    if (nLen == 6) {
        if (pInfo->sMangled.mid(nPos, 6) == "__ctor") {
            *psDecl += "this";
            return nPos + 6;
        }
        if (pInfo->sMangled.mid(nPos, 6) == "__dtor") {
            *psDecl += "~this";
            return nPos + 6;
        }
        if (pInfo->sMangled.mid(nPos, 7) == "__initZ") {
            psDecl->insert(0, "initializer for ");
            if (psDecl->size() > 0) psDecl->chop(1);
            return nPos + 6;
        }
        if (pInfo->sMangled.mid(nPos, 7) == "__vtblZ") {
            psDecl->insert(0, "vtable for ");
            if (psDecl->size() > 0) psDecl->chop(1);
            return nPos + 6;
        }
    } else if (nLen == 7) {
        if (pInfo->sMangled.mid(nPos, 8) == "__ClassZ") {
            psDecl->insert(0, "ClassInfo for ");
            if (psDecl->size() > 0) psDecl->chop(1);
            return nPos + 7;
        }
    } else if (nLen == 10) {
        if (pInfo->sMangled.mid(nPos, 13) == "__postblitMFZ") {
            *psDecl += "this(this)";
            return nPos + 13;
        }
    } else if (nLen == 11) {
        if (pInfo->sMangled.mid(nPos, 12) == "__InterfaceZ") {
            psDecl->insert(0, "Interface for ");
            if (psDecl->size() > 0) psDecl->chop(1);
            return nPos + 11;
        }
    } else if (nLen == 12) {
        if (pInfo->sMangled.mid(nPos, 13) == "__ModuleInfoZ") {
            psDecl->insert(0, "ModuleInfo for ");
            if (psDecl->size() > 0) psDecl->chop(1);
            return nPos + 12;
        }
    }

    *psDecl += pInfo->sMangled.mid(nPos, nLen);

    return nPos + (qint32)nLen;
}

qint32 XDemangle::dlang_parse_integer(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, QChar cType)
{
    if ((cType == QChar('a')) || (cType == QChar('u')) || (cType == QChar('w'))) {  // character literal
        quint32 nVal = 0;
        nPos = dlang_number(nPos, pInfo, &nVal);
        if (nPos < 0) return -1;

        *psDecl += "'";

        if ((cType == QChar('a')) && (nVal >= 0x20) && (nVal < 0x7F)) {
            *psDecl += QChar((char16_t)nVal);
        } else {
            qint32 nWidth = 2;

            if (cType == QChar('a')) {
                *psDecl += "\\x";
                nWidth = 2;
            } else if (cType == QChar('u')) {
                *psDecl += "\\u";
                nWidth = 4;
            } else {
                *psDecl += "\\U";
                nWidth = 8;
            }

            QString sHex = QString::number(nVal, 16);
            while (sHex.size() < nWidth) {
                sHex.prepend("0");
            }
            *psDecl += sHex;
        }

        *psDecl += "'";
        return nPos;
    } else if (cType == QChar('b')) {  // boolean
        quint32 nVal = 0;
        nPos = dlang_number(nPos, pInfo, &nVal);
        if (nPos < 0) return -1;
        *psDecl += (nVal ? "true" : "false");
        return nPos;
    } else {  // plain integer - copy digits verbatim
        if (!((watcom_charAt(pInfo->sMangled, nPos) >= QChar('0')) && (watcom_charAt(pInfo->sMangled, nPos) <= QChar('9')))) {
            return -1;
        }

        while ((watcom_charAt(pInfo->sMangled, nPos) >= QChar('0')) && (watcom_charAt(pInfo->sMangled, nPos) <= QChar('9'))) {
            *psDecl += watcom_charAt(pInfo->sMangled, nPos);
            nPos++;
        }

        if ((cType == QChar('h')) || (cType == QChar('t')) || (cType == QChar('k'))) {
            *psDecl += "u";
        } else if (cType == QChar('l')) {
            *psDecl += "L";
        } else if (cType == QChar('m')) {
            *psDecl += "uL";
        }

        return nPos;
    }
}

qint32 XDemangle::dlang_parse_real(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    if (pInfo->sMangled.mid(nPos, 3) == "NAN") {
        *psDecl += "NaN";
        return nPos + 3;
    }
    if (pInfo->sMangled.mid(nPos, 3) == "INF") {
        *psDecl += "Inf";
        return nPos + 3;
    }
    if (pInfo->sMangled.mid(nPos, 4) == "NINF") {
        *psDecl += "-Inf";
        return nPos + 4;
    }

    if (watcom_charAt(pInfo->sMangled, nPos) == QChar('N')) {
        *psDecl += "-";
        nPos++;
    }

    qint32 nDig = watcom_charToDigit(watcom_charAt(pInfo->sMangled, nPos));
    if ((nDig < 0) || (nDig >= 16)) {
        return -1;
    }

    *psDecl += "0x";
    *psDecl += watcom_charAt(pInfo->sMangled, nPos);
    nPos++;
    *psDecl += ".";

    while (true) {
        qint32 nH = watcom_charToDigit(watcom_charAt(pInfo->sMangled, nPos));
        if ((nH < 0) || (nH >= 16)) break;
        *psDecl += watcom_charAt(pInfo->sMangled, nPos);
        nPos++;
    }

    if (watcom_charAt(pInfo->sMangled, nPos) != QChar('P')) {
        return -1;
    }

    *psDecl += "p";
    nPos++;

    if (watcom_charAt(pInfo->sMangled, nPos) == QChar('N')) {
        *psDecl += "-";
        nPos++;
    }

    while ((watcom_charAt(pInfo->sMangled, nPos) >= QChar('0')) && (watcom_charAt(pInfo->sMangled, nPos) <= QChar('9'))) {
        *psDecl += watcom_charAt(pInfo->sMangled, nPos);
        nPos++;
    }

    return nPos;
}

qint32 XDemangle::dlang_parse_string(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    QChar cType = watcom_charAt(pInfo->sMangled, nPos);
    nPos++;

    quint32 nLen = 0;
    nPos = dlang_number(nPos, pInfo, &nLen);

    if ((nPos < 0) || (watcom_charAt(pInfo->sMangled, nPos) != QChar('_'))) {
        return -1;
    }

    nPos++;
    *psDecl += "\"";

    for (quint32 i = 0; i < nLen; i++) {
        qint32 nStart = nPos;
        qint32 nVal = 0;
        nPos = dlang_hexdigit(nPos, pInfo, &nVal);
        if (nPos < 0) return -1;

        if (nVal == ' ') {
            *psDecl += " ";
        } else if (nVal == '\t') {
            *psDecl += "\\t";
        } else if (nVal == '\n') {
            *psDecl += "\\n";
        } else if (nVal == '\r') {
            *psDecl += "\\r";
        } else if (nVal == '\f') {
            *psDecl += "\\f";
        } else if (nVal == '\v') {
            *psDecl += "\\v";
        } else if ((nVal >= 0x20) && (nVal < 0x7F)) {
            *psDecl += QChar((char16_t)nVal);
        } else {
            *psDecl += "\\x";
            *psDecl += pInfo->sMangled.mid(nStart, 2);
        }
    }

    *psDecl += "\"";

    if (cType != QChar('a')) {
        *psDecl += cType;
    }

    return nPos;
}

qint32 XDemangle::dlang_parse_arrayliteral(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    quint32 nElements = 0;
    nPos = dlang_number(nPos, pInfo, &nElements);
    if (nPos < 0) return -1;

    *psDecl += "[";

    while (nElements != 0) {
        nPos = dlang_value(psDecl, nPos, pInfo, "", QChar('\0'));
        if (nPos < 0) return -1;
        nElements--;
        if (nElements != 0) *psDecl += ", ";
    }

    *psDecl += "]";
    return nPos;
}

qint32 XDemangle::dlang_parse_assocarray(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    quint32 nElements = 0;
    nPos = dlang_number(nPos, pInfo, &nElements);
    if (nPos < 0) return -1;

    *psDecl += "[";

    while (nElements != 0) {
        nPos = dlang_value(psDecl, nPos, pInfo, "", QChar('\0'));
        if (nPos < 0) return -1;
        *psDecl += ":";
        nPos = dlang_value(psDecl, nPos, pInfo, "", QChar('\0'));
        if (nPos < 0) return -1;
        nElements--;
        if (nElements != 0) *psDecl += ", ";
    }

    *psDecl += "]";
    return nPos;
}

qint32 XDemangle::dlang_parse_structlit(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, const QString &sName)
{
    quint32 nArgs = 0;
    nPos = dlang_number(nPos, pInfo, &nArgs);
    if (nPos < 0) return -1;

    if (!sName.isEmpty()) {
        *psDecl += sName;
    }

    *psDecl += "(";

    while (nArgs != 0) {
        nPos = dlang_value(psDecl, nPos, pInfo, "", QChar('\0'));
        if (nPos < 0) return -1;
        nArgs--;
        if (nArgs != 0) *psDecl += ", ";
    }

    *psDecl += ")";
    return nPos;
}

qint32 XDemangle::dlang_value(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, const QString &sName, QChar cType)
{
    QChar c = watcom_charAt(pInfo->sMangled, nPos);

    if (c == QChar('\0')) {
        return -1;
    }

    switch (c.unicode()) {
        case 'n':
            nPos++;
            *psDecl += "null";
            break;
        case 'N':
            nPos++;
            *psDecl += "-";
            nPos = dlang_parse_integer(psDecl, nPos, pInfo, cType);
            break;
        case 'i':
            nPos++;
            nPos = dlang_parse_integer(psDecl, nPos, pInfo, cType);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': nPos = dlang_parse_integer(psDecl, nPos, pInfo, cType); break;
        case 'e':
            nPos++;
            nPos = dlang_parse_real(psDecl, nPos, pInfo);
            break;
        case 'c':
            nPos++;
            nPos = dlang_parse_real(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += "+";
            if (watcom_charAt(pInfo->sMangled, nPos) != QChar('c')) return -1;
            nPos++;
            nPos = dlang_parse_real(psDecl, nPos, pInfo);
            if (nPos < 0) return -1;
            *psDecl += "i";
            break;
        case 'a':
        case 'w':
        case 'd': nPos = dlang_parse_string(psDecl, nPos, pInfo); break;
        case 'A':
            nPos++;
            if (cType == QChar('H')) {
                nPos = dlang_parse_assocarray(psDecl, nPos, pInfo);
            } else {
                nPos = dlang_parse_arrayliteral(psDecl, nPos, pInfo);
            }
            break;
        case 'S':
            nPos++;
            nPos = dlang_parse_structlit(psDecl, nPos, pInfo, sName);
            break;
        default: return -1;
    }

    return nPos;
}

qint32 XDemangle::dlang_parse_tuple(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    quint32 nElements = 0;
    nPos = dlang_number(nPos, pInfo, &nElements);
    if (nPos < 0) return -1;

    *psDecl += "Tuple!(";

    while (nElements != 0) {
        nPos = dlang_type(psDecl, nPos, pInfo);
        if (nPos < 0) return -1;
        nElements--;
        if (nElements != 0) *psDecl += ", ";
    }

    *psDecl += ")";
    return nPos;
}

qint32 XDemangle::dlang_template_symbol_param(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    if ((pInfo->sMangled.mid(nPos, 2) == "_D") && dlang_symbol_name_p(nPos + 2, pInfo)) {
        return dlang_parse_mangle(psDecl, nPos, pInfo);
    }

    if (watcom_charAt(pInfo->sMangled, nPos) == QChar('Q')) {
        return dlang_parse_qualified(psDecl, nPos, pInfo, false);
    }

    quint32 nLen = 0;
    qint32 nEndptr = dlang_number(nPos, pInfo, &nLen);

    if ((nEndptr < 0) || (nLen == 0)) {
        return -1;
    }

    // Legacy (<=2.076) ambiguity: try successively shorter length interpretations.
    quint32 nPsize = nLen;
    qint32 nSaved = psDecl->size();
    qint32 nPend = nEndptr;
    bool bEndptrValid = true;

    for (;;) {
        qint32 nMangled = nPend;

        if (nPsize == 0) {
            nPsize = nLen;
            nPend = nEndptr;
            bEndptrValid = false;
            nMangled = nPend;
        }

        qint32 nR = -1;

        if (dlang_symbol_name_p(nMangled, pInfo)) {
            nR = dlang_parse_qualified(psDecl, nMangled, pInfo, false);
        } else if ((pInfo->sMangled.mid(nMangled, 2) == "_D") && dlang_symbol_name_p(nMangled + 2, pInfo)) {
            nR = dlang_parse_mangle(psDecl, nMangled, pInfo);
        }

        if ((nR >= 0) && (!bEndptrValid || ((quint32)(nR - nPend) == nPsize))) {
            return nR;
        }

        if (!bEndptrValid) {
            return -1;
        }

        nPsize /= 10;

        if (psDecl->size() > nSaved) {
            psDecl->truncate(nSaved);
        }
    }
}

qint32 XDemangle::dlang_template_args(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    qint32 n = 0;

    while (watcom_charAt(pInfo->sMangled, nPos) != QChar('\0')) {
        QChar c = watcom_charAt(pInfo->sMangled, nPos);

        if (c == QChar('Z')) {
            nPos++;
            return nPos;
        }

        if (n++ != 0) {
            *psDecl += ", ";
        }

        if (watcom_charAt(pInfo->sMangled, nPos) == QChar('H')) {
            nPos++;  // "specialised" marker - skip
        }

        c = watcom_charAt(pInfo->sMangled, nPos);

        if (c == QChar('S')) {
            nPos++;
            nPos = dlang_template_symbol_param(psDecl, nPos, pInfo);
        } else if (c == QChar('T')) {
            nPos++;
            nPos = dlang_type(psDecl, nPos, pInfo);
        } else if (c == QChar('V')) {
            nPos++;
            QChar cType = watcom_charAt(pInfo->sMangled, nPos);

            if (cType == QChar('Q')) {
                qint32 nTarget = -1;
                qint32 nA = dlang_backref(nPos, pInfo, &nTarget);
                if (nA < 0) return -1;
                cType = watcom_charAt(pInfo->sMangled, nTarget);
            }

            QString sName;
            nPos = dlang_type(&sName, nPos, pInfo);
            if (nPos < 0) return -1;
            nPos = dlang_value(psDecl, nPos, pInfo, sName, cType);
        } else if (c == QChar('X')) {
            nPos++;
            quint32 nXLen = 0;
            qint32 nEnd = dlang_number(nPos, pInfo, &nXLen);
            if ((nEnd < 0) || ((quint32)(pInfo->sMangled.size() - nEnd) < nXLen)) return -1;
            *psDecl += pInfo->sMangled.mid(nEnd, nXLen);
            nPos = nEnd + (qint32)nXLen;
        } else {
            return -1;
        }

        if (nPos < 0) {
            return -1;
        }
    }

    return nPos;
}

qint32 XDemangle::dlang_parse_template(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, quint32 nLen)
{
    qint32 nStart = nPos;

    if (!dlang_symbol_name_p(nPos + 3, pInfo) || (watcom_charAt(pInfo->sMangled, nPos + 3) == QChar('0'))) {
        return -1;
    }

    nPos += 3;  // skip __T / __U

    nPos = dlang_identifier(psDecl, nPos, pInfo);
    if (nPos < 0) return -1;

    QString sArgs;
    nPos = dlang_template_args(&sArgs, nPos, pInfo);
    if (nPos < 0) return -1;

    *psDecl += QString("!(") + sArgs + QString(")");

    if ((nLen != 0xFFFFFFFFu) && ((quint32)(nPos - nStart) != nLen)) {
        return -1;
    }

    return nPos;
}

qint32 XDemangle::dlang_parse_qualified(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, bool bSuffixModifiers)
{
    qint32 n = 0;

    do {
        if (n++ != 0) {
            *psDecl += ".";
        }

        while (watcom_charAt(pInfo->sMangled, nPos) == QChar('0')) {
            nPos++;  // skip anonymous symbols
        }

        nPos = dlang_identifier(psDecl, nPos, pInfo);
        if (nPos < 0) return -1;

        if ((watcom_charAt(pInfo->sMangled, nPos) == QChar('M')) || dlang_call_convention_p(watcom_charAt(pInfo->sMangled, nPos))) {
            qint32 nStartFn = nPos;
            qint32 nSavedLen = psDecl->size();
            QString sMods;

            if (watcom_charAt(pInfo->sMangled, nPos) == QChar('M')) {
                nPos++;
                nPos = dlang_type_modifiers(&sMods, nPos, pInfo);
                if ((nPos >= 0) && (psDecl->size() > nSavedLen)) {
                    psDecl->truncate(nSavedLen);
                }
            }

            if (nPos >= 0) {
                nPos = dlang_function_type_noreturn(psDecl, nullptr, nullptr, nPos, pInfo);
            }

            if ((nPos >= 0) && bSuffixModifiers) {
                *psDecl += sMods;
            }

            if ((nPos < 0) || (watcom_charAt(pInfo->sMangled, nPos) == QChar('\0'))) {
                // Not actually a nested function - backtrack, leaving it as the symbol's own type.
                nPos = nStartFn;
                if (psDecl->size() > nSavedLen) {
                    psDecl->truncate(nSavedLen);
                }
            }
        }
    } while ((nPos >= 0) && dlang_symbol_name_p(nPos, pInfo));

    return nPos;
}

qint32 XDemangle::dlang_parse_mangle(QString *psDecl, qint32 nPos, DLANGINFO *pInfo)
{
    nPos += 2;  // skip "_D"

    nPos = dlang_parse_qualified(psDecl, nPos, pInfo, true);

    if (nPos >= 0) {
        if (watcom_charAt(pInfo->sMangled, nPos) == QChar('Z')) {
            nPos++;  // artificial symbol - no type
        } else {
            QString sDump;
            nPos = dlang_type(&sDump, nPos, pInfo);  // variable / return type - parsed and discarded
        }
    }

    return nPos;
}

QString XDemangle::dlang_demangle(const QString &sString)
{
    if (sString.isEmpty()) {
        return QString();
    }

    if (!((watcom_charAt(sString, 0) == QChar('_')) && (watcom_charAt(sString, 1) == QChar('D')))) {
        return QString();
    }

    QString sDecl;

    if (sString == "_Dmain") {
        sDecl = "D main";
    } else {
        DLANGINFO info;
        info.sMangled = sString;
        info.nLastBackref = sString.size();

        qint32 nPos = dlang_parse_mangle(&sDecl, 0, &info);

        if ((nPos < 0) || (watcom_charAt(sString, nPos) != QChar('\0'))) {
            sDecl.clear();  // leftover bytes => whole demangle fails
        }
    }

    return sDecl;  // empty on failure -> demangle() falls back to the raw string
}

// --- Rust --------------------------------------------------------------------
//
// Native port of libiberty's rust-demangle.c. Handles both the legacy scheme
// (_ZN..E, a length-prefixed path with a 17h<16 hex> hash suffix and $..$
// escapes) and the v0 scheme (_R.., with base-62 numbers, punycode identifiers
// and backreferences). Positions index into pR->sSym; output accumulates in
// pR->sOut.

QChar XDemangle::rust_peek(RUSTINFO *pR)
{
    if (pR->nNext < pR->nSymLen) {
        return pR->sSym.at(pR->nNext);
    }

    return QChar('\0');
}

bool XDemangle::rust_eat(RUSTINFO *pR, QChar cChar)
{
    if (rust_peek(pR) == cChar) {
        pR->nNext++;
        return true;
    }

    return false;
}

QChar XDemangle::rust_next(RUSTINFO *pR)
{
    QChar c = rust_peek(pR);

    if (c == QChar('\0')) {
        pR->bErrored = true;
    } else {
        pR->nNext++;
    }

    return c;
}

void XDemangle::rust_print_str(RUSTINFO *pR, const QString &sString)
{
    if (!pR->bErrored && !pR->bSkipping) {
        pR->sOut += sString;
    }
}

void XDemangle::rust_print_uint64(RUSTINFO *pR, quint64 nValue)
{
    rust_print_str(pR, QString::number(nValue));
}

void XDemangle::rust_print_uint64_hex(RUSTINFO *pR, quint64 nValue)
{
    rust_print_str(pR, QString::number(nValue, 16));
}

const char *XDemangle::rust_basic_type(QChar cTag)
{
    switch (cTag.unicode()) {
        case 'b': return "bool";
        case 'c': return "char";
        case 'e': return "str";
        case 'u': return "()";
        case 'a': return "i8";
        case 's': return "i16";
        case 'l': return "i32";
        case 'x': return "i64";
        case 'n': return "i128";
        case 'i': return "isize";
        case 'h': return "u8";
        case 't': return "u16";
        case 'm': return "u32";
        case 'y': return "u64";
        case 'o': return "u128";
        case 'j': return "usize";
        case 'f': return "f32";
        case 'd': return "f64";
        case 'z': return "!";
        case 'p': return "_";
        case 'v': return "...";
        default: return nullptr;
    }
}

XDemangle::RUSTIDENT XDemangle::rust_parse_ident(RUSTINFO *pR)
{
    RUSTIDENT ident;
    ident.nAsciiStart = -1;
    ident.nAsciiLen = 0;
    ident.nPunyStart = -1;
    ident.nPunyLen = 0;

    bool bPuny = false;

    if (pR->nVersion != -1) {
        bPuny = rust_eat(pR, QChar('u'));
    }

    QChar c = rust_next(pR);

    if (!((c >= QChar('0')) && (c <= QChar('9')))) {
        pR->bErrored = true;
        return ident;
    }

    quint64 nLen = (quint64)(c.unicode() - '0');

    if (c != QChar('0')) {
        while (true) {
            QChar p = rust_peek(pR);
            if (!((p >= QChar('0')) && (p <= QChar('9')))) break;
            nLen = nLen * 10 + (quint64)(rust_next(pR).unicode() - '0');
        }
    }

    if (pR->nVersion != -1) {
        rust_eat(pR, QChar('_'));  // optional separator
    }

    qint32 nStart = pR->nNext;
    pR->nNext += (qint32)nLen;

    if ((nStart > pR->nNext) || (pR->nNext > pR->nSymLen)) {
        pR->bErrored = true;
        return ident;
    }

    ident.nAsciiStart = nStart;
    ident.nAsciiLen = (qint32)nLen;

    if (bPuny) {
        qint32 nAsciiLen = (qint32)nLen;
        qint32 nPunyLen = 0;

        while (nAsciiLen > 0) {
            nAsciiLen--;
            if (pR->sSym.at(nStart + nAsciiLen) == QChar('_')) break;  // last '_' separates ascii & punycode
            nPunyLen++;
        }

        if (nPunyLen == 0) {
            pR->bErrored = true;
            return ident;
        }

        ident.nAsciiLen = nAsciiLen;
        ident.nPunyStart = nStart + ((qint32)nLen - nPunyLen);
        ident.nPunyLen = nPunyLen;
    }

    if (ident.nAsciiLen == 0) {
        ident.nAsciiStart = -1;  // empty ascii => NULL
    }

    return ident;
}

qint32 XDemangle::rust_decode_legacy_escape(const QString &sString, qint32 nPos, qint32 nLen, qint32 *pnOutLen)
{
    if ((nLen < 3) || (watcom_charAt(sString, nPos) != QChar('$'))) {
        return 0;
    }

    qint32 e = nPos + 1;  // after the leading '$'
    qint32 len = nLen - 1;
    qint32 nEscapeLen = 0;
    qint32 c = 0;

    QChar e0 = watcom_charAt(sString, e);

    if (e0 == QChar('C')) {
        nEscapeLen = 1;
        c = ',';
    } else if (len > 2) {
        nEscapeLen = 2;
        QChar e1 = watcom_charAt(sString, e + 1);

        if ((e0 == QChar('S')) && (e1 == QChar('P'))) c = '@';
        else if ((e0 == QChar('B')) && (e1 == QChar('P'))) c = '*';
        else if ((e0 == QChar('R')) && (e1 == QChar('F'))) c = '&';
        else if ((e0 == QChar('L')) && (e1 == QChar('T'))) c = '<';
        else if ((e0 == QChar('G')) && (e1 == QChar('T'))) c = '>';
        else if ((e0 == QChar('L')) && (e1 == QChar('P'))) c = '(';
        else if ((e0 == QChar('R')) && (e1 == QChar('P'))) c = ')';
        else if ((e0 == QChar('u')) && (len > 3)) {
            nEscapeLen = 3;

            QChar h = watcom_charAt(sString, e + 1);
            QChar l = watcom_charAt(sString, e + 2);
            qint32 hi = -1;
            qint32 lo = -1;

            if ((h >= QChar('0')) && (h <= QChar('9'))) hi = h.unicode() - '0';
            else if ((h >= QChar('a')) && (h <= QChar('f'))) hi = h.unicode() - 'a' + 10;
            if ((l >= QChar('0')) && (l <= QChar('9'))) lo = l.unicode() - '0';
            else if ((l >= QChar('a')) && (l <= QChar('f'))) lo = l.unicode() - 'a' + 10;

            if ((hi < 0) || (lo < 0) || (hi > 7)) return 0;
            c = (hi << 4) | lo;
            if (c < 0x20) return 0;
        }
    }

    if ((c == 0) || (len <= nEscapeLen) || (watcom_charAt(sString, e + nEscapeLen) != QChar('$'))) {
        return 0;
    }

    *pnOutLen = 2 + nEscapeLen;

    return c;
}

void XDemangle::rust_print_ident(RUSTINFO *pR, const RUSTIDENT &ident)
{
    if (pR->bErrored || pR->bSkipping) {
        return;
    }

    if (pR->nVersion == -1) {  // legacy - un-escape
        qint32 nStart = ident.nAsciiStart;
        qint32 nLen = ident.nAsciiLen;

        if (nStart < 0) {
            return;
        }

        // Drop a leading underscore that immediately precedes an escape.
        if ((nLen >= 2) && (pR->sSym.at(nStart) == QChar('_')) && (pR->sSym.at(nStart + 1) == QChar('$'))) {
            nStart++;
            nLen--;
        }

        qint32 p = nStart;
        qint32 nEnd = nStart + nLen;

        while (p < nEnd) {
            QChar c = pR->sSym.at(p);

            if (c == QChar('$')) {
                qint32 nOutLen = 0;
                qint32 nCh = rust_decode_legacy_escape(pR->sSym, p, nEnd - p, &nOutLen);

                if (nCh > 0) {
                    rust_print_str(pR, QString(QChar((char16_t)nCh)));
                    p += nOutLen;
                } else {
                    rust_print_str(pR, pR->sSym.mid(p, nEnd - p));  // malformed - rest verbatim
                    return;
                }
            } else if (c == QChar('.')) {
                if ((p + 1 < nEnd) && (pR->sSym.at(p + 1) == QChar('.'))) {
                    rust_print_str(pR, "::");
                    p += 2;
                } else {
                    rust_print_str(pR, ".");
                    p += 1;
                }
            } else {
                qint32 q = p;
                while ((q < nEnd) && (pR->sSym.at(q) != QChar('$')) && (pR->sSym.at(q) != QChar('.'))) {
                    q++;
                }
                rust_print_str(pR, pR->sSym.mid(p, q - p));
                p = q;
            }
        }

        return;
    }

    // v0
    if (ident.nPunyStart < 0) {
        if (ident.nAsciiStart >= 0) {
            rust_print_str(pR, pR->sSym.mid(ident.nAsciiStart, ident.nAsciiLen));
        }
        return;
    }

    // Punycode (RFC 3492 bootstring) decode.
    QList<uint> listCps;

    for (qint32 k = 0; k < ident.nAsciiLen; k++) {
        listCps.append((uint)pR->sSym.at(ident.nAsciiStart + k).unicode());
    }

    quint64 nI = 0;
    quint64 nC = 0x80;
    quint64 nBias = 72;
    quint64 nDamp = 700;

    qint32 nPos = ident.nPunyStart;
    qint32 nPunyEnd = ident.nPunyStart + ident.nPunyLen;

    while (nPos < nPunyEnd) {
        quint64 nDelta = 0;
        quint64 nW = 1;
        quint64 nK = 0;
        qint32 nD = 0;
        quint64 nT = 0;

        while (true) {
            nK += 36;
            nT = (nK < nBias) ? 0 : (nK - nBias);
            if (nT < 1) nT = 1;
            if (nT > 26) nT = 26;

            if (nPos >= nPunyEnd) {
                pR->bErrored = true;
                return;
            }

            QChar dc = pR->sSym.at(nPos);
            nPos++;

            if ((dc >= QChar('a')) && (dc <= QChar('z'))) nD = dc.unicode() - 'a';
            else if ((dc >= QChar('0')) && (dc <= QChar('9'))) nD = 26 + (dc.unicode() - '0');
            else {
                pR->bErrored = true;
                return;
            }

            nDelta += (quint64)nD * nW;
            nW *= (36 - nT);

            if ((quint64)nD < nT) break;
        }

        quint64 nLenOut = (quint64)listCps.size() + 1;
        nI += nDelta;
        nC += nI / nLenOut;
        nI %= nLenOut;

        listCps.insert((int)nI, (uint)nC);

        if (nPos == nPunyEnd) break;

        nI++;

        nDelta /= nDamp;
        nDamp = 2;
        nDelta += nDelta / nLenOut;
        nK = 0;
        while (nDelta > (quint64)(((36 - 1) * 26) / 2)) {
            nDelta /= (36 - 1);
            nK += 36;
        }
        nBias = nK + ((36 - 1 + 1) * nDelta) / (nDelta + 38);
    }

    QString sResult;
    for (qint32 k = 0; k < listCps.size(); k++) {
        char32_t cp = (char32_t)listCps.at(k);
        if (cp <= 0xFFFF) {
            sResult += QChar((char16_t)cp);
        } else {
            sResult += QString::fromUcs4(&cp, 1);
        }
    }

    rust_print_str(pR, sResult);
}

quint64 XDemangle::rust_parse_integer_62(RUSTINFO *pR)
{
    if (rust_eat(pR, QChar('_'))) {
        return 0;
    }

    quint64 x = 0;

    while (!rust_eat(pR, QChar('_'))) {
        QChar c = rust_next(pR);
        x *= 62;

        if ((c >= QChar('0')) && (c <= QChar('9'))) x += (quint64)(c.unicode() - '0');
        else if ((c >= QChar('a')) && (c <= QChar('z'))) x += 10 + (quint64)(c.unicode() - 'a');
        else if ((c >= QChar('A')) && (c <= QChar('Z'))) x += 10 + 26 + (quint64)(c.unicode() - 'A');
        else {
            pR->bErrored = true;
            return 0;
        }
    }

    return x + 1;
}

quint64 XDemangle::rust_parse_opt_integer_62(RUSTINFO *pR, QChar cTag)
{
    if (!rust_eat(pR, cTag)) {
        return 0;
    }

    return 1 + rust_parse_integer_62(pR);
}

quint64 XDemangle::rust_parse_disambiguator(RUSTINFO *pR)
{
    return rust_parse_opt_integer_62(pR, QChar('s'));
}

qint32 XDemangle::rust_parse_hex_nibbles(RUSTINFO *pR, quint64 *pnValue)
{
    qint32 nHexLen = 0;
    *pnValue = 0;

    while (!rust_eat(pR, QChar('_'))) {
        *pnValue <<= 4;

        QChar c = rust_next(pR);

        if ((c >= QChar('0')) && (c <= QChar('9'))) *pnValue |= (quint64)(c.unicode() - '0');
        else if ((c >= QChar('a')) && (c <= QChar('f'))) *pnValue |= 10 + (quint64)(c.unicode() - 'a');
        else {
            pR->bErrored = true;
            return 0;
        }

        nHexLen++;
    }

    return nHexLen;
}

void XDemangle::rust_print_lifetime_from_index(RUSTINFO *pR, quint64 nLt)
{
    rust_print_str(pR, "'");

    if (nLt == 0) {
        rust_print_str(pR, "_");
        return;
    }

    quint64 nDepth = pR->nBoundLifetimeDepth - nLt;

    if (nDepth < 26) {
        rust_print_str(pR, QString(QChar((char16_t)('a' + nDepth))));
    } else {
        rust_print_str(pR, "_");
        rust_print_uint64(pR, nDepth);
    }
}

void XDemangle::rust_demangle_binder(RUSTINFO *pR)
{
    if (pR->bErrored) {
        return;
    }

    quint64 nBound = rust_parse_opt_integer_62(pR, QChar('G'));

    if (nBound > 0) {
        rust_print_str(pR, "for<");

        for (quint64 i = 0; i < nBound; i++) {
            if (i > 0) rust_print_str(pR, ", ");
            pR->nBoundLifetimeDepth++;
            rust_print_lifetime_from_index(pR, 1);
        }

        rust_print_str(pR, "> ");
    }
}

void XDemangle::rust_demangle_generic_arg(RUSTINFO *pR)
{
    if (rust_eat(pR, QChar('L'))) {
        quint64 nLt = rust_parse_integer_62(pR);
        rust_print_lifetime_from_index(pR, nLt);
    } else if (rust_eat(pR, QChar('K'))) {
        rust_demangle_const(pR);
    } else {
        rust_demangle_type(pR);
    }
}

bool XDemangle::rust_demangle_path_maybe_open_generics(RUSTINFO *pR)
{
    bool bOpen = false;

    if (pR->bErrored) {
        return bOpen;
    }

    if (rust_eat(pR, QChar('B'))) {
        quint64 nBackref = rust_parse_integer_62(pR);
        if (!pR->bSkipping) {
            qint32 nOldNext = pR->nNext;
            pR->nNext = (qint32)nBackref;
            bOpen = rust_demangle_path_maybe_open_generics(pR);
            pR->nNext = nOldNext;
        }
    } else if (rust_eat(pR, QChar('I'))) {
        rust_demangle_path(pR, false);
        rust_print_str(pR, "<");
        bOpen = true;
        qint32 i = 0;
        while (!pR->bErrored && !rust_eat(pR, QChar('E'))) {
            if (i > 0) rust_print_str(pR, ", ");
            rust_demangle_generic_arg(pR);
            i++;
        }
    } else {
        rust_demangle_path(pR, false);
    }

    return bOpen;
}

void XDemangle::rust_demangle_dyn_trait(RUSTINFO *pR)
{
    if (pR->bErrored) {
        return;
    }

    bool bOpen = rust_demangle_path_maybe_open_generics(pR);

    while (rust_eat(pR, QChar('p'))) {
        if (!bOpen) rust_print_str(pR, "<");
        else rust_print_str(pR, ", ");
        bOpen = true;

        RUSTIDENT name = rust_parse_ident(pR);
        rust_print_ident(pR, name);
        rust_print_str(pR, " = ");
        rust_demangle_type(pR);
    }

    if (bOpen) {
        rust_print_str(pR, ">");
    }
}

void XDemangle::rust_demangle_const_uint(RUSTINFO *pR, QChar cTag)
{
    Q_UNUSED(cTag)

    if (pR->bErrored) {
        return;
    }

    quint64 nValue = 0;
    qint32 nHexLen = rust_parse_hex_nibbles(pR, &nValue);

    if (nHexLen > 16) {
        rust_print_str(pR, "0x");
        rust_print_str(pR, pR->sSym.mid(pR->nNext - nHexLen, nHexLen));  // does not fit in 64 bits - verbatim
    } else if (nHexLen > 0) {
        rust_print_uint64(pR, nValue);
    } else {
        pR->bErrored = true;
    }
}

void XDemangle::rust_demangle_const_int(RUSTINFO *pR, QChar cTag)
{
    if (rust_eat(pR, QChar('n'))) {
        rust_print_str(pR, "-");
    }

    rust_demangle_const_uint(pR, cTag);
}

void XDemangle::rust_demangle_const_bool(RUSTINFO *pR)
{
    quint64 nValue = 0;

    if (rust_parse_hex_nibbles(pR, &nValue) != 1) {
        pR->bErrored = true;
        return;
    }

    if (nValue == 0) rust_print_str(pR, "false");
    else if (nValue == 1) rust_print_str(pR, "true");
    else pR->bErrored = true;
}

void XDemangle::rust_demangle_const_char(RUSTINFO *pR)
{
    quint64 nValue = 0;
    qint32 nHexLen = rust_parse_hex_nibbles(pR, &nValue);

    if ((nHexLen == 0) || (nHexLen > 8)) {
        pR->bErrored = true;
        return;
    }

    rust_print_str(pR, "'");

    if (nValue == '\t') rust_print_str(pR, "\\t");
    else if (nValue == '\r') rust_print_str(pR, "\\r");
    else if (nValue == '\n') rust_print_str(pR, "\\n");
    else if ((nValue > ' ') && (nValue < '~')) {
        rust_print_str(pR, QString(QChar((char16_t)nValue)));
    } else {
        rust_print_str(pR, "\\u{");
        rust_print_uint64_hex(pR, nValue);
        rust_print_str(pR, "}");
    }

    rust_print_str(pR, "'");
}

void XDemangle::rust_demangle_const(RUSTINFO *pR)
{
    if (pR->bErrored) {
        return;
    }

    if (rust_eat(pR, QChar('B'))) {
        quint64 nBackref = rust_parse_integer_62(pR);
        if (!pR->bSkipping) {
            qint32 nOldNext = pR->nNext;
            pR->nNext = (qint32)nBackref;
            rust_demangle_const(pR);
            pR->nNext = nOldNext;
        }
        return;
    }

    QChar cTag = rust_next(pR);

    switch (cTag.unicode()) {
        case 'p': rust_print_str(pR, "_"); return;
        case 'h':
        case 't':
        case 'm':
        case 'y':
        case 'o':
        case 'j': rust_demangle_const_uint(pR, cTag); break;
        case 'a':
        case 's':
        case 'l':
        case 'x':
        case 'n':
        case 'i': rust_demangle_const_int(pR, cTag); break;
        case 'b': rust_demangle_const_bool(pR); break;
        case 'c': rust_demangle_const_char(pR); break;
        default: pR->bErrored = true; return;
    }

    if (pR->bErrored) {
        return;
    }

    if (pR->bVerbose) {
        rust_print_str(pR, ": ");
        const char *pBasic = rust_basic_type(cTag);
        if (pBasic) rust_print_str(pR, QString(pBasic));
    }
}

void XDemangle::rust_demangle_type(RUSTINFO *pR)
{
    if (pR->bErrored) {
        return;
    }

    QChar cTag = rust_next(pR);

    const char *pBasic = rust_basic_type(cTag);
    if (pBasic) {
        rust_print_str(pR, QString(pBasic));
        return;
    }

    switch (cTag.unicode()) {
        case 'R':
        case 'Q':
            rust_print_str(pR, "&");
            if (rust_eat(pR, QChar('L'))) {
                quint64 nLt = rust_parse_integer_62(pR);
                if (nLt) {
                    rust_print_lifetime_from_index(pR, nLt);
                    rust_print_str(pR, " ");
                }
            }
            if (cTag != QChar('R')) rust_print_str(pR, "mut ");
            rust_demangle_type(pR);
            break;
        case 'P':
        case 'O':
            rust_print_str(pR, "*");
            if (cTag != QChar('P')) rust_print_str(pR, "mut ");
            else rust_print_str(pR, "const ");
            rust_demangle_type(pR);
            break;
        case 'A':
        case 'S':
            rust_print_str(pR, "[");
            rust_demangle_type(pR);
            if (cTag == QChar('A')) {
                rust_print_str(pR, "; ");
                rust_demangle_const(pR);
            }
            rust_print_str(pR, "]");
            break;
        case 'T': {
            rust_print_str(pR, "(");
            qint32 i = 0;
            while (!pR->bErrored && !rust_eat(pR, QChar('E'))) {
                if (i > 0) rust_print_str(pR, ", ");
                rust_demangle_type(pR);
                i++;
            }
            if (i == 1) rust_print_str(pR, ",");
            rust_print_str(pR, ")");
            break;
        }
        case 'F': {
            quint64 nOldDepth = pR->nBoundLifetimeDepth;
            rust_demangle_binder(pR);

            if (rust_eat(pR, QChar('U'))) rust_print_str(pR, "unsafe ");

            if (rust_eat(pR, QChar('K'))) {
                QString sAbi;
                bool bAbiOk = true;

                if (rust_eat(pR, QChar('C'))) {
                    sAbi = "C";
                } else {
                    RUSTIDENT abi = rust_parse_ident(pR);
                    if (pR->bErrored || (abi.nAsciiStart < 0) || (abi.nPunyStart >= 0)) {
                        pR->bErrored = true;
                        bAbiOk = false;
                    } else {
                        sAbi = pR->sSym.mid(abi.nAsciiStart, abi.nAsciiLen);
                    }
                }

                if (bAbiOk) {
                    rust_print_str(pR, "extern \"");
                    sAbi.replace(QChar('_'), QChar('-'));  // '-' had been replaced by '_'
                    rust_print_str(pR, sAbi);
                    rust_print_str(pR, "\" ");
                }
            }

            if (!pR->bErrored) {
                rust_print_str(pR, "fn(");
                qint32 i = 0;
                while (!pR->bErrored && !rust_eat(pR, QChar('E'))) {
                    if (i > 0) rust_print_str(pR, ", ");
                    rust_demangle_type(pR);
                    i++;
                }
                rust_print_str(pR, ")");

                if (!rust_eat(pR, QChar('u'))) {
                    rust_print_str(pR, " -> ");
                    rust_demangle_type(pR);
                }
            }

            pR->nBoundLifetimeDepth = nOldDepth;
            break;
        }
        case 'D': {
            rust_print_str(pR, "dyn ");

            quint64 nOldDepth = pR->nBoundLifetimeDepth;
            rust_demangle_binder(pR);

            qint32 i = 0;
            while (!pR->bErrored && !rust_eat(pR, QChar('E'))) {
                if (i > 0) rust_print_str(pR, " + ");
                rust_demangle_dyn_trait(pR);
                i++;
            }

            pR->nBoundLifetimeDepth = nOldDepth;

            if (!rust_eat(pR, QChar('L'))) {
                pR->bErrored = true;
                return;
            }
            quint64 nLt = rust_parse_integer_62(pR);
            if (nLt) {
                rust_print_str(pR, " + ");
                rust_print_lifetime_from_index(pR, nLt);
            }
            break;
        }
        case 'B': {
            quint64 nBackref = rust_parse_integer_62(pR);
            if (!pR->bSkipping) {
                qint32 nOldNext = pR->nNext;
                pR->nNext = (qint32)nBackref;
                rust_demangle_type(pR);
                pR->nNext = nOldNext;
            }
            break;
        }
        default:
            pR->nNext--;  // go back to the tag so demangle_path sees it
            rust_demangle_path(pR, false);
            break;
    }
}

void XDemangle::rust_demangle_path(RUSTINFO *pR, bool bInValue)
{
    if (pR->bErrored) {
        return;
    }

    QChar cTag = rust_next(pR);

    switch (cTag.unicode()) {
        case 'C': {
            quint64 nDis = rust_parse_disambiguator(pR);
            RUSTIDENT name = rust_parse_ident(pR);
            rust_print_ident(pR, name);
            if (pR->bVerbose) {
                rust_print_str(pR, "[");
                rust_print_uint64_hex(pR, nDis);
                rust_print_str(pR, "]");
            }
            break;
        }
        case 'N': {
            QChar ns = rust_next(pR);
            bool bLower = ((ns >= QChar('a')) && (ns <= QChar('z')));
            bool bUpper = ((ns >= QChar('A')) && (ns <= QChar('Z')));
            if (!bLower && !bUpper) {
                pR->bErrored = true;
                return;
            }

            rust_demangle_path(pR, bInValue);

            quint64 nDis = rust_parse_disambiguator(pR);
            RUSTIDENT name = rust_parse_ident(pR);

            if (bUpper) {  // special namespaces (closures, shims, ...)
                rust_print_str(pR, "::{");
                if (ns == QChar('C')) rust_print_str(pR, "closure");
                else if (ns == QChar('S')) rust_print_str(pR, "shim");
                else rust_print_str(pR, QString(ns));

                if ((name.nAsciiStart >= 0) || (name.nPunyStart >= 0)) {
                    rust_print_str(pR, ":");
                    rust_print_ident(pR, name);
                }

                rust_print_str(pR, "#");
                rust_print_uint64(pR, nDis);
                rust_print_str(pR, "}");
            } else {  // ordinary namespace
                if ((name.nAsciiStart >= 0) || (name.nPunyStart >= 0)) {
                    rust_print_str(pR, "::");
                    rust_print_ident(pR, name);
                }
            }
            break;
        }
        case 'M':
        case 'X': {
            rust_parse_disambiguator(pR);
            bool bWasSkipping = pR->bSkipping;
            pR->bSkipping = true;
            rust_demangle_path(pR, bInValue);
            pR->bSkipping = bWasSkipping;
            // fall through
            rust_print_str(pR, "<");
            rust_demangle_type(pR);
            if (cTag != QChar('M')) {
                rust_print_str(pR, " as ");
                rust_demangle_path(pR, false);
            }
            rust_print_str(pR, ">");
            break;
        }
        case 'Y':
            rust_print_str(pR, "<");
            rust_demangle_type(pR);
            if (cTag != QChar('M')) {
                rust_print_str(pR, " as ");
                rust_demangle_path(pR, false);
            }
            rust_print_str(pR, ">");
            break;
        case 'I': {
            rust_demangle_path(pR, bInValue);
            if (bInValue) rust_print_str(pR, "::");
            rust_print_str(pR, "<");
            qint32 i = 0;
            while (!pR->bErrored && !rust_eat(pR, QChar('E'))) {
                if (i > 0) rust_print_str(pR, ", ");
                rust_demangle_generic_arg(pR);
                i++;
            }
            rust_print_str(pR, ">");
            break;
        }
        case 'B': {
            quint64 nBackref = rust_parse_integer_62(pR);
            if (!pR->bSkipping) {
                qint32 nOldNext = pR->nNext;
                pR->nNext = (qint32)nBackref;
                rust_demangle_path(pR, bInValue);
                pR->nNext = nOldNext;
            }
            break;
        }
        default: pR->bErrored = true; return;
    }
}

QString XDemangle::rust_demangle(const QString &sString)
{
    RUSTINFO r;
    r.nNext = 0;
    r.bErrored = false;
    r.bSkipping = false;
    r.bVerbose = false;
    r.nVersion = 0;
    r.nBoundLifetimeDepth = 0;

    if ((sString.size() >= 2) && (sString.at(0) == QChar('_')) && (sString.at(1) == QChar('R'))) {
        r.sSym = sString.mid(2);
        r.nVersion = 0;
    } else if ((sString.size() >= 3) && (sString.at(0) == QChar('_')) && (sString.at(1) == QChar('Z')) && (sString.at(2) == QChar('N'))) {
        r.sSym = sString.mid(3);
        r.nVersion = -1;
    } else {
        return QString();
    }

    if (r.nVersion == 0) {
        QChar c0 = watcom_charAt(r.sSym, 0);
        if (!((c0 >= QChar('A')) && (c0 <= QChar('Z')))) {
            return QString();
        }
    }

    // Charset scan (also fixes sym_len).
    r.nSymLen = 0;
    for (qint32 i = 0; i < r.sSym.size(); i++) {
        QChar c = r.sSym.at(i);
        bool bOk = (c == QChar('_')) || ((c >= QChar('0')) && (c <= QChar('9'))) || ((c >= QChar('a')) && (c <= QChar('z'))) || ((c >= QChar('A')) && (c <= QChar('Z')));

        if (r.nVersion == -1) {
            if ((c == QChar('$')) || (c == QChar('.')) || (c == QChar(':'))) bOk = true;
        }

        if (!bOk) {
            return QString();
        }

        r.nSymLen++;
    }

    if (r.nVersion == -1) {  // legacy
        if ((r.nSymLen == 0) || (r.sSym.at(r.nSymLen - 1) != QChar('E'))) {
            return QString();
        }
        r.nSymLen--;  // drop the trailing 'E'

        if (!((r.nSymLen > 19) && (r.sSym.mid(r.nSymLen - 19, 3) == "17h"))) {
            return QString();
        }

        // Validation pass.
        r.nNext = 0;
        RUSTIDENT lastIdent;
        lastIdent.nAsciiStart = -1;
        lastIdent.nAsciiLen = 0;
        lastIdent.nPunyStart = -1;
        lastIdent.nPunyLen = 0;

        while (r.nNext < r.nSymLen) {
            RUSTIDENT id = rust_parse_ident(&r);
            if (r.bErrored || (id.nAsciiStart < 0)) {
                return QString();
            }
            lastIdent = id;
        }

        // Legacy hash check: 'h' + 16 lowercase hex nibbles with >= 5 distinct values.
        bool bHashOk = false;
        if ((lastIdent.nAsciiLen == 17) && (watcom_charAt(r.sSym, lastIdent.nAsciiStart) == QChar('h'))) {
            quint32 nNibbleSet = 0;
            bool bAllHex = true;
            for (qint32 k = 0; k < 16; k++) {
                QChar hc = watcom_charAt(r.sSym, lastIdent.nAsciiStart + 1 + k);
                qint32 nv = -1;
                if ((hc >= QChar('0')) && (hc <= QChar('9'))) nv = hc.unicode() - '0';
                else if ((hc >= QChar('a')) && (hc <= QChar('f'))) nv = hc.unicode() - 'a' + 10;
                else {
                    bAllHex = false;
                    break;
                }
                nNibbleSet |= (1u << nv);
            }
            if (bAllHex) {
                qint32 nDistinct = 0;
                for (qint32 b = 0; b < 16; b++) {
                    if (nNibbleSet & (1u << b)) nDistinct++;
                }
                if (nDistinct >= 5) bHashOk = true;
            }
        }

        if (!bHashOk) {
            return QString();
        }

        // Print pass.
        r.nNext = 0;
        if (!r.bVerbose && (r.nSymLen > 19)) {
            r.nSymLen -= 19;  // hide the trailing hash
        }

        qint32 nCount = 0;
        while (r.nNext < r.nSymLen) {
            if (nCount++ > 0) rust_print_str(&r, "::");
            RUSTIDENT id = rust_parse_ident(&r);
            rust_print_ident(&r, id);
        }
    } else {  // v0
        rust_demangle_path(&r, true);

        if (!r.bErrored && (r.nNext < r.nSymLen)) {
            r.bSkipping = true;
            rust_demangle_path(&r, false);
        }

        if (r.nNext != r.nSymLen) {
            r.bErrored = true;
        }
    }

    if (r.bErrored) {
        return QString();
    }

    return r.sOut;
}

QString XDemangle::demangle(const QString &sString, XDemangle::MODE mode)
{
    QString sResult;

    QString _sString = sString;

    if (mode == MODE_AUTO) {
        mode = detectMode(_sString);
    }

    if ((mode == MODE_GNU_V3) || (mode == MODE_GCC_WIN) || (mode == MODE_GCC_MAC) || (mode == MODE_BORLAND64)) {
        // OpenVMS IA-64 wraps Itanium names in a 'CXX$' prefix; strip it before parsing
        // (only when a real Itanium '_Z' name follows, so a pathological non-VMS symbol
        // literally named 'CXX$...' is never altered). The full VMS case-reencoding suffix
        // is not decoded -> such names fall back to raw.
        QString sItanium = _sString.startsWith("CXX$_Z") ? _sString.mid(4) : _sString;
        DSYMBOL symbol = itanium_getSymbol(sItanium, mode);

        sResult = dsymbolToString(symbol);
    } else if (mode == MODE_JAVA) {
        DSYMBOL symbol = itanium_getSymbol(_sString, mode);

        sResult = dsymbolToString(symbol);
    } else if (mode == MODE_RUST) {
        sResult = rust_demangle(_sString);
    } else if (mode == MODE_GNAT) {
        sResult = gnat_demangle(_sString);
    } else if (mode == MODE_DLANG) {
        sResult = dlang_demangle(_sString);
    } else if (mode == MODE_GNU_V2) {
        sResult = gnu2_demangle(_sString);
    } else if (mode == MODE_TRU64) {
        sResult = gnu2_demangle(_sString, true);  // accept the '__X' ARM-mode marker
    } else if (mode == MODE_SUN) {
        sResult = sun_demangle(_sString);
    } else if (mode == MODE_SWIFT) {
        sResult = swift_demangle(_sString);
    } else if (mode == MODE_HASKELL) {
        sResult = haskell_demangle(_sString);
    } else if (mode == MODE_OCAML) {
        sResult = ocaml_demangle(_sString);
    } else if (mode == MODE_GO) {
        sResult = go_demangle(_sString);
    } else if (mode == MODE_BORLAND32) {
        DSYMBOL symbol = borland_getSymbol(_sString, mode);

        sResult = dsymbolToString(symbol);
    } else if (mode == MODE_WATCOM) {
        DSYMBOL symbol = watcom_getSymbol(_sString, mode);

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
    } else if (getSyntaxFromMode(mode) == SYNTAX_BORLAND) {
        result = borland_getSymbol(sString, mode);
    } else if (getSyntaxFromMode(mode) == SYNTAX_WATCOM) {
        result = watcom_getSymbol(sString, mode);
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
    } else if (_compare(sString, "W?")) {
        result = MODE_WATCOM;
    } else if (_compare(sString, "@") && (sString.contains("$q") || sString.contains("$b"))) {
        result = MODE_BORLAND32;
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
    listResult.append(MODE_MSVCARM32);
    listResult.append(MODE_MSVCARM64);
    listResult.append(MODE_GNU_V2);
    listResult.append(MODE_BORLAND32);
    listResult.append(MODE_BORLAND64);
    listResult.append(MODE_JAVA);
    listResult.append(MODE_RUST);
    listResult.append(MODE_GNAT);
    listResult.append(MODE_DLANG);
    listResult.append(MODE_WATCOM);
    listResult.append(MODE_SWIFT);
    listResult.append(MODE_GO);
    listResult.append(MODE_HASKELL);
    listResult.append(MODE_OCAML);
    listResult.append(MODE_TRU64);
    listResult.append(MODE_SUN);

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
        } else if (getSyntaxFromMode(symbol.mode) == SYNTAX_WATCOM) {
            sResult = symbol.sResult;
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
        mapResult.insert("n", XTYPE_INT128);
        mapResult.insert("o", XTYPE_UINT128);
        mapResult.insert("f", XTYPE_FLOAT);
        mapResult.insert("g", XTYPE_FLOAT128);
        mapResult.insert("d", XTYPE_DOUBLE);
        mapResult.insert("e", XTYPE_LONGDOUBLE_64);
        mapResult.insert("z", XTYPE_VARARGS);
        mapResult.insert("x", XTYPE_LONGLONG);
        mapResult.insert("y", XTYPE_ULONGLONG);
        mapResult.insert("b", XTYPE_BOOL);
        mapResult.insert("Dh", XTYPE_HALF);
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
    } else if (getSyntaxFromMode(mode) == SYNTAX_WATCOM) {
        mapResult.insert("a", XTYPE_CHAR);
        mapResult.insert("c", XTYPE_SCHAR);
        mapResult.insert("s", XTYPE_SHORT);
        mapResult.insert("i", XTYPE_INT);
        mapResult.insert("l", XTYPE_LONG);
        mapResult.insert("z", XTYPE_INT64);
        mapResult.insert("b", XTYPE_FLOAT);
        mapResult.insert("d", XTYPE_DOUBLE);
        mapResult.insert("t", XTYPE_LONGDOUBLE_64);
        mapResult.insert("q", XTYPE_BOOL);
        mapResult.insert("w", XTYPE_WCHAR);
        mapResult.insert("e", XTYPE_VARARGS);
        mapResult.insert("v", XTYPE_VOID);
        mapResult.insert("uc", XTYPE_UCHAR);
        mapResult.insert("us", XTYPE_USHORT);
        mapResult.insert("ui", XTYPE_UINT);
        mapResult.insert("ul", XTYPE_ULONG);
        mapResult.insert("uz", XTYPE_UINT64);
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
    } else if (getSyntaxFromMode(mode) == SYNTAX_WATCOM) {
        mapResult.insert("p", QUAL_POINTER);
        mapResult.insert("r", QUAL_REFERENCE);
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
    } else if (getSyntaxFromMode(mode) == SYNTAX_WATCOM) {
        // Memory model of the object / pointer
        mapResult.insert("n", SC_NEAR);
        mapResult.insert("f", SC_FAR);
        mapResult.insert("g", SC_FAR);  // __far16 (rendered as far)
        mapResult.insert("h", SC_HUGE);
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
    } else if (getSyntaxFromMode(mode) == SYNTAX_WATCOM) {
        // Special members
        mapResult.insert("$ct", OP_CONSTRUCTOR);
        mapResult.insert("$dt", OP_DESTRUCTOR);
        mapResult.insert("$nw", OP_NEW);
        mapResult.insert("$dl", OP_DELETE);
        mapResult.insert("$na", OP_ARRAYNEW);
        mapResult.insert("$da", OP_ARRAYDELETE);
        // Arithmetic / unary / misc (operatorFunction table, index a..u)
        mapResult.insert("$oa", OP_RIGHTSHIFT);      // operator>>
        mapResult.insert("$ob", OP_LEFTSHIFT);       // operator<<
        mapResult.insert("$oc", OP_LOGICALNOT);      // operator!
        mapResult.insert("$od", OP_ARRAYSUBSCRIPT);  // operator[]
        mapResult.insert("$oe", OP_POINTER);         // operator->
        mapResult.insert("$of", OP_DEREFERENCE);     // operator*
        mapResult.insert("$og", OP_INCREMENT);       // operator++
        mapResult.insert("$oh", OP_DECREMENT);       // operator--
        mapResult.insert("$oi", OP_MINUS);           // operator-
        mapResult.insert("$oj", OP_PLUS);            // operator+
        mapResult.insert("$ok", OP_BITWISEAND);      // operator&
        mapResult.insert("$ol", OP_MEMBERPOINTER);   // operator->*
        mapResult.insert("$om", OP_DIVIDE);          // operator/
        mapResult.insert("$on", OP_MODULUS);         // operator%
        mapResult.insert("$oo", OP_COMMA);           // operator,
        mapResult.insert("$op", OP_PARENS);          // operator()
        mapResult.insert("$oq", OP_BITWISENOT);      // operator~
        mapResult.insert("$or", OP_BITWISEXOR);      // operator^
        mapResult.insert("$os", OP_BITWISEOR);       // operator|
        mapResult.insert("$ot", OP_LOGICALAND);      // operator&&
        mapResult.insert("$ou", OP_LOGICALOR);       // operator||
        // Relational (relationalFunction table, index a..f)
        mapResult.insert("$ra", OP_EQUALS);            // operator==
        mapResult.insert("$rb", OP_NOTEQUALS);         // operator!=
        mapResult.insert("$rc", OP_LESSTHAN);          // operator<
        mapResult.insert("$rd", OP_LESSTHANEQUAL);     // operator<=
        mapResult.insert("$re", OP_GREATERTHAN);       // operator>
        mapResult.insert("$rf", OP_GREATERTHANEQUAL);  // operator>=
        // Assignment (assignmentFunction table, index a..k)
        mapResult.insert("$aa", OP_ASSIGN);           // operator=
        mapResult.insert("$ab", OP_TIMESEQUAL);       // operator*=
        mapResult.insert("$ac", OP_PLUSEQUAL);        // operator+=
        mapResult.insert("$ad", OP_MINUSEQUAL);       // operator-=
        mapResult.insert("$ae", OP_DIVEQUAL);         // operator/=
        mapResult.insert("$af", OP_MODEQUAL);         // operator%=
        mapResult.insert("$ag", OP_RSHEQUAL);         // operator>>=
        mapResult.insert("$ah", OP_LSHEQUAL);         // operator<<=
        mapResult.insert("$ai", OP_BITWISEANDEQUAL);  // operator&=
        mapResult.insert("$aj", OP_BITWISEOREQUAL);   // operator|=
        mapResult.insert("$ak", OP_BITWISEXOREQUAL);  // operator^=
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
    } else if (getSyntaxFromMode(mode) == SYNTAX_WATCOM) {
        mapResult.insert("x", QUAL_CONST);
        mapResult.insert("y", QUAL_VOLATILE);
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
        mapResult.insert("Si", "std::istream");
        mapResult.insert("So", "std::ostream");
        mapResult.insert("Sd", "std::iostream");
    }

    return mapResult;
}
