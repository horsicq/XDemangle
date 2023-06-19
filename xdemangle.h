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
#ifndef XDEMANGLE_H
#define XDEMANGLE_H

#include <QMap>
#include <QObject>
#include <QVariant>
#ifdef QT_DEBUG
#include <QDebug>
#endif
#include "xcppfilt.h"

class XDemangle : public QObject {
    Q_OBJECT

public:
    enum MODE {
        MODE_UNKNOWN = 0,
        MODE_AUTO,
        MODE_MSVC,  // Generic
        MODE_MSVC32,
        MODE_MSVC64,
        MODE_GNU_V3,  // Generic
        MODE_GCC_WIN,
        MODE_GCC_MAC,
        MODE_JAVA,
        MODE_BORLAND32,
        MODE_BORLAND64,
        MODE_WATCOM,
        MODE_RUST
        // TODO more !!!
    };

    enum SYNTAX {
        SYNTAX_UNKNOWN = 0,
        SYNTAX_MICROSOFT,
        SYNTAX_ITANIUM,
        SYNTAX_BORLAND,
        SYNTAX_WATCOM
    };

    enum XTYPE {
        XTYPE_UNKNOWN = 0,
        XTYPE_NONE,  // For Constructors & Destructors
        XTYPE_BOOL,
        XTYPE_VOID,
        XTYPE_INT,
        XTYPE_SCHAR,
        XTYPE_CHAR,
        XTYPE_UCHAR,
        XTYPE_SHORT,
        XTYPE_USHORT,
        XTYPE_UINT,
        XTYPE_LONG,
        XTYPE_ULONG,
        XTYPE_FLOAT,
        XTYPE_FLOAT128,
        XTYPE_DOUBLE,
        XTYPE_LONGDOUBLE,
        XTYPE_LONGDOUBLE_64,
        XTYPE_LONGDOUBLE_80,
        XTYPE_INT64,
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
        XTYPE_CONST
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
        SC_VOLATILE,
        SC_CONSTVOLATILE,
        SC_FAR,
        SC_CONSTFAR,
        SC_VOLATILEFAR,
        SC_CONSTVOLATILEFAR,
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
        FC_PASCAL,
        FC_FORTRAN,
        FC_THISCALL,
        FC_STDCALL,
        FC_FASTCALL,
        FC_MSFASTCALL,
        FC_REGCALL,
        FC_CLRCALL,
        FC_EABI,
        FC_SWIFT,
        FC_VECTORCALL
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
        ST_TYPEINFO,  // TODO
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
    NUMBER readSymNumber(HDATA *pHdata, QString sString, MODE mode);
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

    qint32 ms_demangle_StringLiteralSymbol(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_UntypedVariable(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_SpecialTable(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_LocalStaticGuard(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString, MSDT msdt);
    qint32 ms_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 ms_demangle_MemberPointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_FullTypeName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_FullSymbolName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_UnkTypeName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString, bool bSave);
    qint32 ms_demangle_UnkSymbolName(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString, NB nb);
    qint32 ms_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_Declarator(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_Parameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_Function(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_Variable(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_FunctionType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString, bool bThisQual);
    qint32 ms_demangle_FunctionParameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_Template(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString, NB nb);
    qint32 ms_demangle_TemplateParameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 ms_demangle_ExtQualifiers(DSYMBOL *pSymbol, const QString &sString, quint32 *pnQual);
    bool ms_isPointerMember(DSYMBOL *pSymbol, HDATA *pHdata, QString sString);

    void addStringRef(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    void addArgRef(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    void addStringListRef(DSYMBOL *pSymbol, HDATA *pHdata, QList<QString> listString);
    bool isReplaceStringPresent(DSYMBOL *pSymbol, HDATA *pHdata, QString sString);
    bool isReplaceArgPresent(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);
    bool isLocalScopePresent(DSYMBOL *pSymbol, HDATA *pHdata, QString sString);
    SIGNATURE getReplaceStringSignature(DSYMBOL *pSymbol, HDATA *pHdata, QString sString);
    SIGNATURE getReplaceArgSignature(DSYMBOL *pSymbol, HDATA *pHdata, QString sString);
    SIGNATURE getLocalScopeSignature(DSYMBOL *pSymbol, HDATA *pHdata, const QString &sString);

    QString ms_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter, QString sName, QString sPrefix);
    QString _nameToString(DSYMBOL *pSymbol, DPARAMETER *pParameter);

    DPARAMETER getLastPointerParameter(DPARAMETER *pParameter);
    QString ms_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter, QString sName);

    // libelftc_dem_gnu3.c
    QString itanium_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter, QString sPrefix);
    qint32 itanium_demangle_Encoding(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 itanium_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 itanium_demangle_Function(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString, bool bReturn);
    qint32 itanium_demangle_Parameters(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 itanium_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    qint32 itanium_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, QString sString);
    QString itanium_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter);

    static QString join(QList<QString> *pListStrings, const QString &sJoin);

    qint32 borland_demangle_Encoding(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 borland_demangle_NameScope(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 borland_demangle_Type(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    qint32 borland_demangle_PointerType(DSYMBOL *pSymbol, HDATA *pHdata, DPARAMETER *pParameter, const QString &sString);
    QString borland_parameterToString(DSYMBOL *pSymbol, DPARAMETER *pParameter);
    QString borland_getPointerString(DSYMBOL *pSymbol, DPARAMETER *pParameter);
};

#endif  // XDEMANGLE_H
