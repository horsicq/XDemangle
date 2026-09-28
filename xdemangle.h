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
#ifndef XDEMANGLE_H
#define XDEMANGLE_H

#include <QMap>
#include <QObject>
#include <QVariant>
#ifdef QT_DEBUG
#include <QDebug>
#endif

class XDemangle : public QObject {
    Q_OBJECT

public:
    enum MODE {
        MODE_UNKNOWN = 0,
        MODE_AUTO,
        MODE_MSVC,  // Generic
        MODE_MSVC32,
        MODE_MSVC64,
        MODE_MSVCARM32,
        MODE_MSVCARM64,
        MODE_GNU_V2,
        MODE_GNU_V3,  // Generic
        MODE_GCC_WIN,
        MODE_GCC_MAC,
        MODE_JAVA,
        MODE_BORLAND32,
        MODE_BORLAND64,
        MODE_WATCOM,
        MODE_RUST,
        MODE_GNAT,
        MODE_DLANG,
        MODE_SWIFT,
        MODE_GO,
        MODE_HASKELL,
        MODE_OCAML,
        MODE_TRU64,  // DEC/Compaq Tru64 C++ (ARM-style, '__X' signature marker)
        MODE_SUN     // SunPro / Sun Studio C++ ('__1c' scheme)
        // TODO more !!!
    };

    enum SYNTAX {
        SYNTAX_UNKNOWN = 0,
        SYNTAX_MICROSOFT,
        SYNTAX_ITANIUM,
        SYNTAX_BORLAND,
        SYNTAX_WATCOM,
        SYNTAX_GNU2,
        SYNTAX_SWIFT,
        SYNTAX_SUN
    };

    enum XTYPE {
        XTYPE_UNKNOWN = 0,
        XTYPE_NONE,  // For Constructors & Destructors
        XTYPE_BOOL,
        XTYPE_VCRTBOOL,
        XTYPE_BOOL8,
        XTYPE_BYTE,
        XTYPE__BYTE,
        XTYPE_VOID,
        XTYPE_LPVOID,
        XTYPE_INT,
        XTYPE_INTPTR,
        XTYPE_SINT,
        XTYPE_SCHAR,
        XTYPE_CHAR,
        XTYPE_UCHAR,
        XTYPE_SHORT,
        XTYPE_USHORT,
        XTYPE_UINT,
        XTYPE_UINTPTR,
        XTYPE_UINTPTRT,
        XTYPE__UINT8,
        XTYPE_LONG,
        XTYPE_ULONG,
        XTYPE_FLOAT,
        XTYPE_FLOAT128,
        XTYPE_DOUBLE,
        XTYPE_LONGDOUBLE,
        XTYPE_LONGDOUBLE_64,
        XTYPE_LONGDOUBLE_80,
        XTYPE_INT8,
        XTYPE_INT16,
        XTYPE_INT32,
        XTYPE_INT64,
        XTYPE_INT128,
        XTYPE_UINT128,
        XTYPE_HALF,
        XTYPE_UINT64,
        XTYPE_LONGLONG,
        XTYPE_ULONGLONG,
        XTYPE_DECIMAL32,
        XTYPE_DECIMAL64,
        XTYPE_DECIMAL128,
        XTYPE_CHAR8,
        XTYPE_CHAR16,
        XTYPE_CHAR32,
        XTYPE_WCHAR,
        XTYPE_VARARGS,
        XTYPE_CLASS,
        XTYPE_UNION,
        XTYPE_STRUCT,
        XTYPE_ENUM,
        XTYPE_POINTERTOFUNCTION,
        XTYPE_POINTERTOFUNCTIONREF,
        XTYPE_MEMBER,
        XTYPE_FUNCTION,
        XTYPE_NULLPTR,
        XTYPE_CONST,
        XTYPE_NTSTATUS,
        XTYPE_DWORD,
        XTYPE__DWORD,
        XTYPE_QWORD,
        XTYPE__QWORD,
        XTYPE_HWND,
        XTYPE_HDC,
        XTYPE_LRESULT,
        XTYPE_HRESULT,
        XTYPE_HMODULE,
        XTYPE_HMONITOR,
        XTYPE_HGLOBAL,
        XTYPE_HLOCAL,
        XTYPE_LSTATUS,
        XTYPE_SURFACE,
        XTYPE_BSTR,
        XTYPE_BCSTR,
        XTYPE_LPCSTR,
        XTYPE_LPWSTR,
        XTYPE_SIZET,
        XTYPE_WINTT,
        XTYPE_FILE,
        XTYPE_LOCALEFACET,
        XTYPE_CCHECKLISTBOX,
        XTYPE__WORD,
        XTYPE_IOSTREAMINIT,
        XTYPE_STDEXCEPTION,
        XTYPE_FARPROC,
        XTYPE_HANDLE,
        XTYPE_HKEY,
        XTYPE_M128,
        XTYPE_CEXCEPTION,
        XTYPE_CFILE,
        XTYPE_CFILEFIND,
        XTYPE_CWND,
        XTYPE_CSTRING,
        XTYPE_CSTRINGARRAY,
        XTYPE_CDialog,
        XTYPE_AFXTERMAPPSTATE,
        XTYPE_AFXMODULESTATE,
        XTYPE_AFXMODULETHREADSTATE,
        XTYPE_LPCRITICALSECTION,
        XTYPE_HGDIOBJ,
        XTYPE_COLORREF,
        XTYPE_HBITMAP,
        XTYPE_HPALETTE,
        XTYPE_HCURSOR,
        XTYPE_HMENU,
        XTYPE_HBRUSH,
        XTYPE_EXCEPTION,
        XTYPE_ERRNOT,
        XTYPE_LARGEINTEGER,
        XTYPE_LPTOPLEVELEXCEPTIONFILTER,
        XTYPE_TYPEINFO,
        XTYPE_BOOLEAN,
        XTYPE_PCWSTR,
        XTYPE_HHOOK,
        XTYPE_LPDIRECTDRAW,
        XTYPE_STDIOSBASE,
        XTYPE_PIMAGESECTIONHEADER,
        XTYPE_WINBOOL,
        XTYPE_STDOSTREAMSENTRY,
        XTYPE_W64,
        XTYPE_GC,
        XTYPE_PIN,
        XTYPE_BOX,
        XTYPE_BASED,
        XTYPE_QSTRING,
        XTYPE_QMAPNODEBASE,
        XTYPE_QTHREAD,
        XTYPE_QMETAOBJECT,
        XTYPE_QLISTDATA,
        XTYPE_QSPACERITEM,
        XTYPE_QWIDGET,
        XTYPE_QOBJECT,
        XTYPE_QNETWORKACCESSMANAGER,
        XTYPE_PTR64,
        XTYPE_ATOM,
        XTYPE_PULONG,
        XTYPE_MMRESULT,
        XTYPE_WPARAM,
        XTYPE_HINSTANCE,
    };

    enum OC {
        OC_UNKNOWN = 0,
        OC_PRIVATESTATICCLASSMEMBER,
        OC_PROTECTEDSTATICCLASSMEMBER,
        OC_PUBLICSTATICCLASSMEMBER,
        OC_GLOBALOBJECT,
        OC_FUNCTIONLOCALSTATIC
    };

    enum SC {
        SC_UNKNOWN = 0,
        SC_NEAR,
        SC_CONST,
        SC_CONSTCHAR,
        SC_VOLATILE,
        SC_CONSTVOLATILE,
        SC_FAR,
        SC_CONSTFAR,
        SC_VOLATILEFAR,
        SC_CONSTVOLATILEFAR,
        SC_CONSTCLASS,
        SC_HUGE,
        SC_EXECUTABLE
    };

    enum FM {
        FM_UNKNOWN = 0,
        FM_PUBLIC = 0x00000001,
        FM_PROTECTED = 0x00000002,
        FM_PRIVATE = 0x00000004,
        FM_STATIC = 0x00000010,
        FM_VIRTUAL = 0x00000020,
        FM_NEAR = 0x00000100,
        FM_FAR = 0x00000200,
        FM_STATICTHISADJUST = 0x00001000,
        FM_VIRTUALTHISADJUST = 0x00002000,
        FM_VIRTUALTHISADJUSTEX = 0x00004000,
        FM_FUNCTIONLOCAL = 0x01000000,
        FM_GLOBAL = 0x10000000,
        FM_EXTERNC = 0x20000000,
        FM_NOPARAMETERLIST = 0x40000000,
    };

    enum FC {
        FC_UNKNOWN = 0,
        FC_NONE,
        FC_CDECL,
        FC_CDECLPOINTER,
        FC_CDECL16FAR,
        FC_CDECL16NEAR,
        FC_PASCAL,
        FC_FORTRAN,
        FC_THISCALL,
        FC_THISCALLPOINTER,
        FC_STDCALL,
        FC_STDCALLPOINTER,
        FC_STDCALL16FAR,
        FC_FASTCALL,
        FC_MSFASTCALL,
        FC_REGCALL,
        FC_CLRCALL,
        FC_EABI,
        FC_SWIFT,
        FC_VECTORCALL,
        FC_USERCALL,
        FC_USERPURGE,
        FC_USERPURGEPOINTER,
        FC_NORETURN,
        FC_SWIFT1,
        FC_SWIFT2,
        FC_SWIFT3,
        FC_RESTRICT,
        FC_UNALIGNED
    };

    enum ST {
        ST_UNKNOWN = 0,
        ST_VARIABLE,
        ST_TYPE,
        ST_PACKEDTYPE,
        ST_FUNCTION,
        ST_POINTER,
        ST_VTABLE,
        ST_VFTABLE,
        ST_VBTABLE,
        ST_TYPEINFO,
        ST_TYPEINFONAME,
        ST_TEMPLATE,
        ST_CONST,
        ST_NAME,
        ST_LOCALSTATICGUARD,
        ST_LOCALSTATICTHREADGUARD,
        ST_LOCALVFTABLE,
        ST_RTTICOMPLETEOBJLOCATOR,
        ST_RTTIBASECLASSARRAY,
        ST_RTTICLASSHIERARCHYDESCRIPTOR,
        ST_STRINGLITERALSYMBOL,
        ST_NONVIRTUALTHUNK,
        ST_VIRTUALTHUNK,
        ST_TARGET,
        ST_GUARDVARIABLE,
        ST_TRANSACTIONCLONE,
        ST_VTT,
        ST_CONSTRUCTIONVTABLE
    };

    enum OP {
        OP_UNKNOWN = 0,
        OP_CONSTRUCTOR,
        OP_DESTRUCTOR,
        OP_NEW,
        OP_DELETE,
        OP_ASSIGN,
        OP_RIGHTSHIFT,
        OP_LEFTSHIFT,
        OP_LOGICALNOT,
        OP_EQUALS,
        OP_NOTEQUALS,
        OP_ARRAYSUBSCRIPT,
        OP_POINTER,
        OP_DEREFERENCE,
        OP_REFERENCE,
        OP_INCREMENT,
        OP_DECREMENT,
        OP_MINUS,
        OP_PLUS,
        OP_BITWISEAND,
        OP_MEMBERPOINTER,
        OP_MULTIPLE,
        OP_DIVIDE,
        OP_MODULUS,
        OP_LESSTHAN,
        OP_LESSTHANEQUAL,
        OP_GREATERTHAN,
        OP_GREATERTHANEQUAL,
        OP_THREWAYCOMPARISON,
        OP_COMMA,
        OP_PARENS,
        OP_BITWISENOT,
        OP_BITWISEXOR,
        OP_BITWISEOR,
        OP_LOGICALAND,
        OP_LOGICALOR,
        OP_TIMESEQUAL,
        OP_PLUSEQUAL,
        OP_MINUSEQUAL,
        OP_DIVEQUAL,
        OP_MODEQUAL,
        OP_RSHEQUAL,
        OP_LSHEQUAL,
        OP_BITWISEANDEQUAL,
        OP_BITWISEOREQUAL,
        OP_BITWISEXOREQUAL,
        OP_ARRAYNEW,
        OP_ARRAYDELETE,
        OP_VBASEDTOR,
        OP_VECDELDTOR,
        OP_DEFAULTCTORCLOSURE,
        OP_SCALARDELDTOR,
        OP_VECCTORITER,
        OP_VECDTORITER,
        OP_VECVBASECTORITER,
        OP_VDISPMAP,
        OP_EHVECCTORITER,
        OP_EHVECDTORITER,
        OP_EHVECVBASECTORITER,
        OP_COPYCTORCLOSURE,
        OP_TYPE
    };

    enum QUAL {
        QUAL_NONE = 0x00000000,
        QUAL_CONST = 0x00000001,
        QUAL_VOLATILE = 0x00000002,
        QUAL_SIGNED = 0x00100000,
        QUAL_UNSIGNED = 0x00200000,
        QUAL_REFERENCE = 0x01000000,
        QUAL_RVALUEREF = 0x02000000,
        QUAL_POINTER = 0x04000000,
        QUAL_DOUBLEREFERENCE = 0x08000000,
        QUAL_MEMBER = 0x10000000,
        QUAL_POINTER64 = 0x20000000,
        QUAL_RESTRICT = 0x40000000,
        QUAL_UNALIGNED = 0x80000000,
    };

    struct HDATA {
        quint32 nParserDepth = 0;
        QMap<QString, quint32> mapPointerTypes;
        QMap<QString, quint32> mapObjectClasses;
        QMap<QString, quint32> mapTypes;
        QMap<QString, quint32> mapTagTypes;
        QMap<QString, quint32> mapStorageClasses;
        QMap<QString, quint32> mapAccessMods;
        QMap<QString, quint32> mapFunctionConventions;
        QMap<QString, quint32> mapOperators;
        QMap<QString, quint32> mapNumbers;
        QMap<QString, quint32> mapSymNumbers;
        QMap<QString, quint32> mapQualifiers;
        QMap<QString, quint32> mapSpecInstr;
        QMap<QString, QString> mapStd;            // Itanium
        QList<QString> listStringRef;             // MS
        QList<QString> listArgRef;                // MS Itanium templates
        QList<QList<QString>> listListStringRef;  // Itanium
        QList<QList<QString>> listListTemplates;  // Itanium
    };

    struct DNAME {
        QString sName;
        //        QList<QString> listNames;
        OP _operator;
        bool bTemplates;  // Itanium
                          //        QList<QString> listTemplates; // Itanium
    };

    struct DPARAMETER {
        QList<DNAME> listDnames;
        XTYPE type;
        XTYPE typeConst;
        QVariant varConst;
        ST st;
        OC objectClass;
        quint32 nQualifier;
        quint32 nRefQualifier;
        quint32 nAccess;
        FC functionConvention;
        QList<DPARAMETER> listReturn;
        QList<DPARAMETER> listParameters;
        QList<DPARAMETER> listClass;
        QList<DPARAMETER> listPointer;
        QList<DPARAMETER> listTarget;
        QList<qint64> listIndexes;  // For var[x][y]
        QString sScope;
        bool bTemplatePresent;  // Itanium
    };

    struct DSYMBOL {
        bool bIsValid;
        qint32 nSize;
        MODE mode;
        DPARAMETER paramMain;
        QString sResult;  // Used by Watcom (fully rendered declaration)
    };

    explicit XDemangle(QObject *pParent = nullptr);

    static QString modeIdToString(MODE mode);
    static QString typeIdToString(XTYPE type, MODE mode);
    static QString storageClassIdToString(SC storageClass, MODE mode);
    static QString objectClassIdToString(OC objectClass, MODE mode);
    static QString accessIdToString(quint32 nFunctionMod, MODE mode);
    static QString functionConventionIdToString(FC functionConvention, MODE mode);
    static QString operatorIdToString(OP _operator, MODE mode);
    static QString qualIdToPointerString(quint32 nQual, MODE mode);
    static QString qualIdToStorageString(quint32 nQual, MODE mode);
    QString demangle(const QString &sString, MODE mode);
    DSYMBOL _getSymbol(const QString &sString, MODE mode);
    DSYMBOL ms_getSymbol(const QString &sString, MODE mode, HDATA *pHdata = nullptr);
    DSYMBOL itanium_getSymbol(const QString &sString, MODE mode);
    DSYMBOL borland_getSymbol(const QString &sString, MODE mode);
    DSYMBOL watcom_getSymbol(const QString &sString, MODE mode);
    static MODE detectMode(const QString &sString);
    static QList<MODE> getAllModes();
    static QList<MODE> getSupportedModes();
    HDATA getHdata(MODE mode);

private:
    struct STRING {
        qint32 nSize;
        QString sString;
        QString sOriginal;
    };

    struct NUMBER {
        qint32 nSize;
        qint64 nValue;
    };

    struct SIGNATURE {
        qint32 nSize;
        QString sString;
        QList<QString> listStrings;
        quint32 nValue;
        QString sValue;
    };

    QString dsymbolToString(DSYMBOL symbol);

    STRING readString(HDATA *pHdata, const QString &sString, MODE mode);
    NUMBER readNumber(HDATA *pHdata, const QString &sString, MODE mode);
    NUMBER readNumberS(HDATA *pHdata, const QString &sString, MODE mode);
    NUMBER readSymNumber(HDATA *pHdata, const QString &sString, MODE mode);
    static bool _compare(const QString &sString, const QString &sSignature);
    QChar _getStringEnd(const QString &sString);
    QString _removeLastSymbol(const QString &sString);
    bool isPointerEnd(const QString &sString);
    bool isSignaturePresent(const QString &sString, QMap<QString, quint32> *pMap);
    SIGNATURE getSignature(const QString &sString, QMap<QString, quint32> *pMap);

    QMap<QString, quint32> getObjectClasses(MODE mode);
    QMap<QString, quint32> getTypes(MODE mode);
    QMap<QString, quint32> getTagTypes(MODE mode);
    QMap<QString, quint32> getPointerTypes(MODE mode);
    QMap<QString, quint32> getStorageClasses(MODE mode);
    QMap<QString, quint32> getAccessMods(MODE mode);
    QMap<QString, quint32> getFunctionConventions(MODE mode);
    QMap<QString, quint32> getOperators(MODE mode);
    QMap<QString, quint32> getNumbers(MODE mode);
    QMap<QString, quint32> getLineNumbers(MODE mode);
    QMap<QString, quint32> getSymNumbers(MODE mode);
    QMap<QString, quint32> getQualifiers(MODE mode);
    QMap<QString, quint32> getSpecInstr(MODE mode);
    QMap<QString, QString> getStd(MODE mode);

    static void reverseList(QList<QString> *pList);
    static void reverseList(QList<DNAME> *pList);

    static SYNTAX getSyntaxFromMode(MODE mode);

    enum MSDT {
        MSDT_DROP = 0,
        MSDT_MANGLE,
        MSDT_RESULT
    };

    enum NB {
        NB_TEMPLATE = 1,
        NB_SIMPLE = 2
    };

    qint32 ms_demangle_StringLiteralSymbol(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_UntypedVariable(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_SpecialTable(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_LocalStaticGuard(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, MSDT msdt);
    qint32 ms_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_MemberPointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_FullTypeName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_FullSymbolName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_UnkTypeName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, bool bSave);
    qint32 ms_demangle_UnkSymbolName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, NB nb);
    qint32 ms_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Declarator(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Parameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Function(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Variable(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_FunctionType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, bool bThisQual);
    qint32 ms_demangle_FunctionParameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Template(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, NB nb);
    qint32 ms_demangle_TemplateParameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_ExtQualifiers(DSYMBOL *pSymbol, const QString &sString, quint32 *pnQual);
    bool ms_isPointerMember(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);

    void addStringRef(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    void addArgRef(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    void addStringListRef(DSYMBOL *pSymbol, HDATA *pHdata, const QList<QString> &listString);
    bool isReplaceStringPresent(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    bool isReplaceArgPresent(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    bool isLocalScopePresent(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    SIGNATURE getReplaceStringSignature(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    SIGNATURE getReplaceArgSignature(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    SIGNATURE getLocalScopeSignature(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);

    QString ms_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter, const QString &sName, const QString &sPrefix);
    QString _nameToString(DSYMBOL *pSymbol, DPARAMETER *pParameter);

    DPARAMETER getLastPointerParameter(DPARAMETER *pParameter);
    QString ms_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter, const QString &sName);

    // libelftc_dem_gnu3.c
    QString itanium_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter, const QString &sPrefix);
    qint32 itanium_demangle_Encoding(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 itanium_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 itanium_demangle_Function(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, bool bReturn,
                                    bool bRequireEnd = false);
    qint32 itanium_demangle_Parameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString,
                                      bool bRequireEnd = false);
    qint32 itanium_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 itanium_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    QString itanium_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter);

    static QString join(QList<QString> *pListStrings, const QString &sJoin);

    qint32 borland_demangle_Encoding(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 borland_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 borland_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 borland_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    QString borland_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter);
    QString borland_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter);

    // Watcom (Open Watcom C++) - schema-driven recursive-descent, renders directly to a string
    QString watcom_parseScopedName(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos, bool bAllowOperator);
    QString watcom_parseName(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos);
    QString watcom_parseTemplateArgs(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos);
    QString watcom_parseType(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString, qint32 *pnPos, const QString &sCore);
    qint64 watcom_parseBase32(const QString &sString, qint32 *pnPos);
    qint64 watcom_parseBase10(const QString &sString, qint32 *pnPos);
    static QChar watcom_charAt(const QString &sString, qint32 nPos);
    static qint32 watcom_charToDigit(QChar cChar);
    static bool watcom_isIdentifierChar(QChar cChar);
    static bool watcom_pointeeNeedsParen(const QString &sString, qint32 nPos);
    static QString watcom_memoryModelString(SC storageClass);
    static QString watcom_joinBaseCore(const QString &sBase, const QString &sCore);
    static QString watcom_renderQualified(const QList<QString> &listChain);

    // GNAT / Ada (native port of libiberty ada_demangle; encoding: gcc/ada/exp_dbug.ads)
    QString gnat_demangle(const QString &sString);
    static bool gnat_demangleName(const QString &sMangled, QString *psResult);
    static bool gnat_isLower(QChar cChar);
    static bool gnat_isDigit(QChar cChar);

    // D language (native port of libiberty d-demangle). Positions are absolute
    // indices into sMangled; parse functions return the new position or -1 on failure.
    struct DLANGINFO {
        QString sMangled;
        qint32 nLastBackref;
        qint32 nDepth = 0;
        qint32 nSteps = 0;
    };
    QString dlang_demangle(const QString &sString);
    qint32 dlang_parse_mangle(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_qualified(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, bool bSuffixModifiers);
    qint32 dlang_identifier(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_lname(QString *psDecl, qint32 nPos, quint32 nLen, DLANGINFO *pInfo);
    qint32 dlang_type(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_function_type(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_function_type_noreturn(QString *psArgs, QString *psCall, QString *psAttr, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_function_args(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_call_convention(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_type_modifiers(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_attributes(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_tuple(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_template(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, quint32 nLen);
    qint32 dlang_template_args(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_template_symbol_param(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_value(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, const QString &sName, QChar cType);
    qint32 dlang_parse_integer(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, QChar cType);
    qint32 dlang_parse_real(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_string(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_arrayliteral(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_assocarray(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_parse_structlit(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, const QString &sName);
    qint32 dlang_number(qint32 nPos, DLANGINFO *pInfo, quint32 *pnRet);
    qint32 dlang_hexdigit(qint32 nPos, DLANGINFO *pInfo, qint32 *pnRet);
    qint32 dlang_decode_backref(qint32 nPos, DLANGINFO *pInfo, quint64 *pnRet);
    qint32 dlang_backref(qint32 nPos, DLANGINFO *pInfo, qint32 *pnTarget);
    qint32 dlang_symbol_backref(QString *psDecl, qint32 nPos, DLANGINFO *pInfo);
    qint32 dlang_type_backref(QString *psDecl, qint32 nPos, DLANGINFO *pInfo, bool bIsFunction);
    bool dlang_symbol_name_p(qint32 nPos, DLANGINFO *pInfo);
    static bool dlang_call_convention_p(QChar cChar);

    // Haskell (GHC Z-encoding), OCaml, Go - small self-contained schemes
    QString haskell_demangle(const QString &sString);
    QString ocaml_demangle(const QString &sString);
    QString go_demangle(const QString &sString);

    // SunPro / Sun Studio C++ ('__1c' scheme). Conservative subset (free functions,
    // fundamental-type params), all-or-nothing: bails to raw on anything not modeled.
    QString sun_demangle(const QString &sString);
    static bool sun_builtin(QChar cCode, QString *psType);

    // GNU v2 (pre-Itanium GCC 2.x / ARM style) - native port of the common paths of
    // the historical libiberty cplus-dem.c (function/member/operator/ctor/dtor/args/
    // fundamental+qualified+template types, T/N back-references, vtable/static specials).
    struct GNU2INFO {
        qint32 nDepth = 0;
        qint32 nSteps = 0;
        QString sMangled;
        qint32 nPos;
        bool bErrored;
        QList<QString> listRemembered;  // remembered arg types (T<n>/N<r><n> back-refs)
        QStringList listTmplArgs;       // template-function args (X<idx>)
        QString sReturn;                // template-function return type
        bool bExpectReturn;
    };
    QString gnu2_demangle(const QString &sString, bool bAllowXMarker = false);
    bool gnu2_special(const QString &sMangled, QString *psResult);
    QString gnu2_tryFunction(const QString &sMangled, qint32 nSigStart, const QString &sFuncName, bool bCtor, bool bAllowXMarker = false);
    bool gnu2_integralValue(GNU2INFO *pI, QString *psResult);
    bool gnu2_args(GNU2INFO *pI, QString *psResult);
    bool gnu2_type(GNU2INFO *pI, QString *psResult);
    bool gnu2_fundType(GNU2INFO *pI, QString *psResult);
    bool gnu2_qualified(GNU2INFO *pI, QString *psResult, QString *psLastName);
    bool gnu2_template(GNU2INFO *pI, QString *psResult, QString *psBareName);
    QString gnu2_className(GNU2INFO *pI, bool *pbOk);
    static QString gnu2_operatorName(const QString &sCode, bool *pbOk);
    static qint64 gnu2_consumeCount(const QString &sM, qint32 *pnPos, bool *pbOk);
    static qint64 gnu2_getCount(const QString &sM, qint32 *pnPos, bool *pbOk);

    // Swift ($s / _$s / $S / _$S). Post-order node-stack demangler; all-or-nothing

    // Swift ($s / _$s / $S / _$S). Post-order node-stack demangler; all-or-nothing
    // (only fully-parsed symbols render, otherwise the raw string is returned).
    struct SWNODE {
        qint32 nKind;
        QString sText;
        QStringList slItems;  // for tuples: the element type texts (enables labels)
        QString sAux;         // for function types: the result-type text (enables entity re-render)
        QChar cKind;          // for nominal types: the kind letter (C=class/V=struct/O=enum/...)
        bool bTuple = false;  // true only for tuple nodes (their sText is already parenthesized)
        bool bFunc = false;   // true for function-type nodes (need parens under ? / sugar)
    };
    struct SWIFTINFO {
        QString sSym;
        qint32 nPos;
        bool bErrored;
        QList<SWNODE> stackNodes;
        QList<SWNODE> listSubst;
    };
    QString swift_demangle(const QString &sString);
    static QChar swift_peek(SWIFTINFO *pI);
    static QChar swift_nextc(SWIFTINFO *pI);
    static bool swift_eat(SWIFTINFO *pI, QChar cChar);
    static qint64 swift_parseNatural(SWIFTINFO *pI, bool *pbOk);
    static qint64 swift_parseIndex(SWIFTINFO *pI, bool *pbOk);
    void swift_push(SWIFTINFO *pI, qint32 nKind, const QString &sText);
    void swift_pushSubst(SWIFTINFO *pI, qint32 nKind, const QString &sText);
    bool swift_pop(SWIFTINFO *pI, SWNODE *pOut);
    QString swift_readIdentifier(SWIFTINFO *pI, bool *pbOk);
    void swift_demangleTop(SWIFTINFO *pI);
    void swift_demangleKnownType(SWIFTINFO *pI);
    void swift_demangleBuiltin(SWIFTINFO *pI);
    void swift_demangleNominal(SWIFTINFO *pI, QChar cKind);
    void swift_demangleBoundGeneric(SWIFTINFO *pI);
    void swift_demangleTuple(SWIFTINFO *pI);
    void swift_demangleSubstitution(SWIFTINFO *pI);
    void swift_demangleFunction(SWIFTINFO *pI);
    void swift_demangleRequirement(SWIFTINFO *pI);          // 'R...' -> a where-clause requirement / param marker
    void swift_demangleParamCounts(SWIFTINFO *pI);          // 'r' GENERIC-PARAM-COUNT*  -> a param-count node
    void swift_finishGenericSig(SWIFTINFO *pI);             // 'l' -> assemble "<params where reqs>"
    QString swift_parseGPIName(SWIFTINFO *pI, bool *pbOk);  // GENERIC-PARAM-INDEX -> absolute param name
    QString swift_takeGenericSig(SWIFTINFO *pI);            // pop a pending generic-sig node (or "")
    QList<XDemangle::SWNODE> swift_popTypeList(SWIFTINFO *pI);
    static QString swift_genericParamName(qint64 nDepth, qint64 nIndex);

    // Rust (native port of libiberty rust-demangle: legacy _ZN..E + v0 _R..)
    struct RUSTINFO {
        QString sSym;  // symbol body after the _R / _ZN prefix
        qint32 nSymLen;
        qint32 nNext;
        bool bErrored;
        bool bSkipping;
        bool bVerbose;
        qint32 nVersion;  // 0 = v0, -1 = legacy
        qint32 nBoundLifetimeDepth;
        qint32 nDepth = 0;
        qint32 nSteps = 0;
        QString sOut;
    };
    struct RUSTIDENT {
        qint32 nAsciiStart;
        qint32 nAsciiLen;
        qint32 nPunyStart;
        qint32 nPunyLen;
    };
    QString rust_demangle(const QString &sString);
    // shared helpers
    static QChar rust_peek(RUSTINFO *pR);
    static bool rust_eat(RUSTINFO *pR, QChar cChar);
    static QChar rust_next(RUSTINFO *pR);
    static void rust_print_str(RUSTINFO *pR, const QString &sString);
    static void rust_print_uint64(RUSTINFO *pR, quint64 nValue);
    static void rust_print_uint64_hex(RUSTINFO *pR, quint64 nValue);
    static const char *rust_basic_type(QChar cTag);
    RUSTIDENT rust_parse_ident(RUSTINFO *pR);
    void rust_print_ident(RUSTINFO *pR, const RUSTIDENT &ident);
    static qint32 rust_decode_legacy_escape(const QString &sString, qint32 nPos, qint32 nLen, qint32 *pnEscapeLen);
    // v0
    quint64 rust_parse_integer_62(RUSTINFO *pR);
    quint64 rust_parse_opt_integer_62(RUSTINFO *pR, QChar cTag);
    quint64 rust_parse_disambiguator(RUSTINFO *pR);
    qint32 rust_parse_hex_nibbles(RUSTINFO *pR, quint64 *pnValue);
    void rust_demangle_path(RUSTINFO *pR, bool bInValue);
    void rust_demangle_generic_arg(RUSTINFO *pR);
    void rust_demangle_type(RUSTINFO *pR);
    void rust_demangle_binder(RUSTINFO *pR);
    bool rust_demangle_path_maybe_open_generics(RUSTINFO *pR);
    void rust_demangle_dyn_trait(RUSTINFO *pR);
    void rust_demangle_const(RUSTINFO *pR);
    void rust_demangle_const_uint(RUSTINFO *pR, QChar cTag);
    void rust_demangle_const_int(RUSTINFO *pR, QChar cTag);
    void rust_demangle_const_bool(RUSTINFO *pR);
    void rust_demangle_const_char(RUSTINFO *pR);
    void rust_print_lifetime_from_index(RUSTINFO *pR, quint64 nLt);
};

#endif  // XDEMANGLE_H
