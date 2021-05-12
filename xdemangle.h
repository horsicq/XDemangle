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
#ifndef XDEMANGLE_H
#define XDEMANGLE_H

#include <QObject>
#include <QMap>
#ifdef QT_DEBUG
#include <QDebug>
#endif

class XDemangle : public QObject
{
    Q_OBJECT

public:
    enum MODE
    {
        MODE_UNKNOWN=0,
        MODE_AUTO,
        MODE_MSVC, // Generic
        MODE_MSVC32,
        MODE_MSVC64,
        MODE_GCC, // Generic
        MODE_BORLAND32,
        MODE_BORLAND64,
        MODE_WATCOM
        // TODO more
    };

    enum SYNTAX
    {
        SYNTAX_UNKNOWN=0,
        SYNTAX_MICROSOFT,
        SYNTAX_ITANIUM,
        SYNTAX_BORLAND32,
        SYNTAX_WATCOM
    };

    enum TYPE
    {
        TYPE_UNKNOWN=0,
        TYPE_NONE, // For Constructors & Destructors
        TYPE_BOOL,
        TYPE_VOID,
        TYPE_INT,
        TYPE_SCHAR,
        TYPE_CHAR,
        TYPE_UCHAR,
        TYPE_SHORT,
        TYPE_USHORT,
        TYPE_UINT,
        TYPE_LONG,
        TYPE_ULONG,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_LONGDOUBLE_64,
        TYPE_LONGDOUBLE_80,
        TYPE_INT64,
        TYPE_UINT64,
        TYPE_CHAR8,
        TYPE_CHAR16,
        TYPE_CHAR32,
        TYPE_WCHAR,
        TYPE_VARARGS,
        TYPE_CLASS,
        TYPE_UNION,
        TYPE_STRUCT,
        TYPE_ENUM,
        TYPE_POINTERTOFUNCTION,
        TYPE_POINTERTOFUNCTIONREF,
        TYPE_MEMBER,
        TYPE_FUNCTION,
        TYPE_NULLPTR,
        TYPE_CONST
    };

    enum OC
    {
        OC_UNKNOWN=0,
        OC_PRIVATESTATICCLASSMEMBER,
        OC_PROTECTEDSTATICCLASSMEMBER,
        OC_PUBLICSTATICCLASSMEMBER,
        OC_GLOBALOBJECT,
        OC_FUNCTIONLOCALSTATIC
    };

    enum SC
    {
        SC_UNKNOWN=0,
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

    enum FM
    {
        FM_UNKNOWN=0,
        FM_PUBLIC               =0x00000001,
        FM_PROTECTED            =0x00000002,
        FM_PRIVATE              =0x00000004,
        FM_STATIC               =0x00000010,
        FM_VIRTUAL              =0x00000020,
        FM_NEAR                 =0x00000100,
        FM_FAR                  =0x00000200,
        FM_STATICTHISADJUST     =0x00001000,
        FM_VIRTUALTHISADJUST    =0x00002000,
        FM_VIRTUALTHISADJUSTEX  =0x00004000,
        FM_GLOBAL               =0x10000000,
        FM_EXTERNC              =0x20000000,
        FM_NOPARAMETERLIST      =0x40000000,
    };

    enum FC
    {
        FC_UNKNOWN=0,
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

    enum ST
    {
        ST_UNKNOWN=0,
        ST_VARIABLE,
        ST_FUNCTION,
        ST_POINTER,
        ST_VFTABLE,
        ST_TYPEINFO, // TODO
        ST_TEMPLATE,
        ST_CONST
    };

    enum OP
    {
        OP_UNKNOWN=0,
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

    enum QUAL
    {
        QUAL_NONE               =0x00000000,
        QUAL_CONST              =0x00000001,
        QUAL_VOLATILE           =0x00000002,
        QUAL_REFERENCE          =0x01000000,
        QUAL_RVALUEREF          =0x02000000,
        QUAL_POINTER            =0x04000000,
        QUAL_DOUBLEREFERENCE    =0x08000000,
        QUAL_MEMBER             =0x10000000,
        QUAL_POINTER64          =0x20000000,
        QUAL_RESTRICT           =0x40000000,
        QUAL_UNALIGNED          =0x80000000,
    };

    struct PARAMETER
    {
        QString sRecord;
        TYPE type;
        quint32 nParamMod;
        SC storageClass;
        QList<QString> listNames;
        QList<PARAMETER> listMods;
        QList<qint64> listIndexes; // For var[x][y]
        bool bTemplate;
        QList<QList<PARAMETER>> listListTemplateParameters; // Template mb TODO flags;
        QList<PARAMETER> listFunctionParameters; // if pointer to a function
        FC functionConvention; // if function
        qint64 nConstValue;
        SC extraStorageClass;
    };

    struct HDATA
    {
        QMap<QString,quint32> mapPointerTypes;
        QMap<QString,quint32> mapObjectClasses;
        QMap<QString,quint32> mapTypes;
        QMap<QString,quint32> mapTagTypes;
        QMap<QString,quint32> mapSymbolTypes;
        QMap<QString,quint32> mapStorageClasses;
        QMap<QString,quint32> mapFunctionMods;
        QMap<QString,quint32> mapFunctionConventions;
        QMap<QString,quint32> mapOperators;
        QMap<QString,quint32> mapNumbers;
        QMap<QString,quint32> mapSymNumbers;
        QMap<QString,quint32> mapQualifiers;
        QList<QString> listStringRef;
        QList<QString> listArgRef;
    };

    struct SYMBOL
    {
        bool bValid;
        MODE mode;
        ST symbolType;
        OP _operator;
        PARAMETER paramMain;
        QList<PARAMETER> listParameters; // 0 - return
        // Variable
        OC objectClass;
        SC storageClass;
        // Function
        SC classStorageClass;
        FM functionMod;
        FC functionConvention;
        bool bRef;
        bool bDoubleRef;
        bool bParamTable;
        PARAMETER paramTable;
        bool bExtra;
        OC extraObjectClass;
        quint32 nExtraParamMod;
        SC extraStorageClass1;
        TYPE extraType;
        SC extraStorageClass2;
        QList<QString> listPreps;
        QString sPrep;
    };

    struct DPARAMETER;

    struct DNAME
    {
        QString sName;
        OP operand;
    };

    struct DPARAMETER
    {
        QList<DNAME> listDnames;
        TYPE type;
        QVariant varConst;
        ST st;
        quint32 nQualifier;
        quint32 nRefQualifier;
        quint32 functionMod;
        FC functionConvention;
        QList<DPARAMETER> listReturn;
        QList<DPARAMETER> listParameters;
        QList<DPARAMETER> listPointer;
        QList<DPARAMETER> listTypeinfo;
    };

    struct DSYMBOL
    {
        bool bIsValid;
        MODE mode;
        DPARAMETER paramMain;
    };

    explicit XDemangle(QObject *pParent=nullptr);
    static QString modeIdToString(MODE mode);
    static QString typeIdToString(TYPE type,MODE mode);
    static QString storageClassIdToString(SC storageClass,MODE mode);
    static QString objectClassIdToString(OC objectClass,MODE mode);
    static QString paramModIdToString(quint32 nParamMod,MODE mode); // TODO rename
    static QString functionModIdToString(quint32 nFunctionMod, MODE mode);
    static QString functionConventionIdToString(FC functionConvention,MODE mode);
    static QString operatorIdToString(OP _operator,MODE mode);
    static QString qualIdToPointerString(quint32 nQual,MODE mode);
    static QString qualIdToStorageString(quint32 nQual,MODE mode);

    SYMBOL getSymbol(QString sString,MODE mode);
    QString convert(QString sString,MODE mode);

    QString ms_demangle(QString sString,MODE mode);
    DSYMBOL getDSymbol(QString sString,MODE mode);

    MODE detectMode(QString sString);

    static QList<MODE> getAllModes();
    static QList<MODE> getSupportedModes();

    HDATA getHdata(MODE mode);

private:
    struct STRING
    {
        qint32 nSize;
        QString sString;
        QString sOriginal;
    };

    struct NUMBER
    {
        qint32 nSize;
        qint64 nValue;
    };

    struct SIGNATURE
    {
        qint32 nSize;
        QString sKey;
        quint32 nValue;
    };

    QString symbolToString(SYMBOL symbol);
    QString dsymbolToString(DSYMBOL symbol);

    STRING readString(HDATA *pHdata,QString sString,MODE mode);
    NUMBER readNumber(HDATA *pHdata,QString sString,MODE mode);
    NUMBER readSymNumber(HDATA *pHdata,QString sString,MODE mode);
    bool _compare(QString sString,QString sSignature);
    QChar _getStringEnd(QString sString);
    QString _removeLastSymbol(QString sString);

    bool isSignaturePresent(QString sString,QMap<QString,quint32> *pMap);
    SIGNATURE getSignature(QString sString,QMap<QString,quint32> *pMap);

    SIGNATURE Itanium_getReplaceSignature(HDATA *pHdata,QString sString,MODE mode);

    QMap<QString,quint32> getObjectClasses(MODE mode);
    QMap<QString,quint32> getTypes(MODE mode);
    QMap<QString,quint32> getTagTypes(MODE mode);
    QMap<QString,quint32> getSymbolTypes(MODE mode);
    QMap<QString,quint32> getPointerTypes(MODE mode);
    QMap<QString,quint32> getStorageClasses(MODE mode);
    QMap<QString,quint32> getFunctionMods(MODE mode);
    QMap<QString,quint32> getFunctionConventions(MODE mode);
    QMap<QString,quint32> getOperators(MODE mode);
    QMap<QString,quint32> getNumbers(MODE mode);
    QMap<QString,quint32> getLineNumbers(MODE mode);
    QMap<QString,quint32> getSymNumbers(MODE mode);
    QMap<QString,quint32> getQualifiers(MODE mode);

    SYMBOL Microsoft_handle(HDATA *pHdata,QString sString,MODE mode);
    SYMBOL Itanium_handle(HDATA *pHdata,QString sString,MODE mode);

    qint32 Microsoft_handleParams(HDATA *pHdata,QString sString,MODE mode,QList<PARAMETER> *pListParameters,qint32 nLimit,QList<QString> *pListStringRefs,QList<QString> *plistArgRefs);
    qint32 Microsoft_handleParamStrings(HDATA *pHdata,QString sString,MODE mode,PARAMETER *pParameter,QList<QString> *pListStringRefs,QList<QString> *plistArgRefs,bool bFirst);

    qint32 Itanium_handleParams(HDATA *pHdata,QString sString,MODE mode,QList<PARAMETER> *pListParameters,QList<QString> *pListStringRefs,bool bFirst,SYMBOL *pSymbol,bool bSplit);
    qint32 Itanium_handleParamStrings(HDATA *pHdata,QString sString,MODE mode,PARAMETER *pParameter,QList<QString> *pListStringRefs,bool bFirst,SYMBOL *pSymbol,bool bSplit);

    QString _getNameFromSymbol(SYMBOL symbol);
    QString _getNameFromParameter(PARAMETER *pParameter,MODE mode);
    QString _getTemplatesFromParameters(QList<PARAMETER> *pListParameters,MODE mode);
    QString _getStringFromParameter(PARAMETER parameter,MODE mode,QString sName="",bool bFuncRet=false);

    static void reverseList(QList<QString> *pList);
//    static void reverseList(QList<MOD> *pList);
    static void reverseList(QList<PARAMETER> *pList);
    static void reverseList(QList<QList<PARAMETER>> *pListList);
    static void reverseList(QList<DNAME> *pList);

    static SYNTAX getSyntaxFromMode(MODE mode);

    enum MSDT
    {
        MSDT_DROP=0,
        MSDT_MANGLE,
        MSDT_RESULT
    };

    enum NB
    {
        NB_TEMPLATE=1,
        NB_SIMPLE=2
    };

    qint32 ms_demangle_SpecialTable(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_Type(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString,MSDT msdt);
    qint32 ms_demangle_PointerType(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_FullName(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_UnkName(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString,NB nb);
    qint32 ms_demangle_NameScope(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_Declarator(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_Parameters(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_Function(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_FunctionType(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString,bool bThisQual);
    qint32 ms_demangle_FunctionParameters(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_Template(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString,NB nb);
    qint32 ms_demangle_TemplateParameters(DSYMBOL *pSymbol,HDATA *pHdata,DPARAMETER *pParameter,QString sString);
    qint32 ms_demangle_ExtQualifiers(DSYMBOL *pSymbol,QString sString,quint32 *pnQual);
    bool ms_isPointerMember(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);

    void addStringRef(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);
    void addArgRef(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);
    bool isReplaceStringPresent(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);
    bool isReplaceArgPresent(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);
    SIGNATURE getReplaceStringSignature(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);
    SIGNATURE getReplaceArgSignature(DSYMBOL *pSymbol,HDATA *pHdata,QString sString);

    QString ms_parameterToString(DSYMBOL *pSymbol,DPARAMETER *pParameter,QString sName); // TODO rename for generic
    QString ms_nameToString(DSYMBOL *pSymbol,DPARAMETER *pParameter);
};

#endif // XDEMANGLE_H
