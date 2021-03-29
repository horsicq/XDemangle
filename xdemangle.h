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
        SYNTAX_BORLAND64,
        SYNTAX_WATCOM
    };

    enum TYPE
    {
        TYPE_UNKNOWN=0,
        TYPE_EMPTY, // For Constructors & Destructors
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
        OC_FUNCTIONLOCALSTATIC,
        OC_VFTABLE
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
        FM_NEAR,
        FM_FAR,
        FM_PUBLIC_NEAR,
        FM_PUBLIC_FAR,
        FM_PUBLIC_STATICNEAR,
        FM_PUBLIC_STATICFAR,
        FM_PUBLIC_VIRTUALNEAR,
        FM_PUBLIC_VIRTUALFAR,
        FM_PROTECTED_NEAR,
        FM_PROTECTED_FAR,
        FM_PROTECTED_STATICNEAR,
        FM_PROTECTED_STATICFAR,
        FM_PROTECTED_VIRTUALNEAR,
        FM_PROTECTED_VIRTUALFAR,
        FM_PRIVATE_NEAR,
        FM_PRIVATE_FAR,
        FM_PRIVATE_STATICNEAR,
        FM_PRIVATE_STATICFAR,
        FM_PRIVATE_VIRTUALNEAR,
        FM_PRIVATE_VIRTUALFAR,
    };

    enum FC
    {
        FC_UNKNOWN=0,
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
        ST_VFTABLE
    };

    enum PM
    {
        PM_NONE,
        PM_POINTER,
        PM_REFERENCE,
        PM_POINTERCONST, // Check
        PM_POINTERVOLATILE,
        PM_POINTERCONSTVOLATILE,
        PM_DOUBLEREFERENCE
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
        OP_INCREMENT,
        OP_DECREMENT,
        OP_MINUS,
        OP_PLUS,
        OP_BITWISEAND,
        OP_MEMBERPOINTER,
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
        OP_VIRTUALTABLE,
        OP_DEFAULTCTORCLOSURE,
        OP_TYPE
    };

    struct MOD
    {
        PM paramMod;
        SC storageClass;
    };

    struct PARAMETER
    {
        QString sRecord;
        QList<MOD> listMods;
        TYPE type;
        QList<QString> listNames;
        QList<qint64> listIndexes; // For var[x][y]
        QList<QList<PARAMETER>> listListTemplateParameters; // Template mb TODO flags;
        QList<PARAMETER> listFunctionParameters; // if pointer to a function
        qint64 nConst;
    };

    struct HDATA
    {
        QMap<QString,qint32> mapParamMods;
        QMap<QString,qint32> mapObjectClasses;
        QMap<QString,qint32> mapTypes;
        QMap<QString,qint32> mapNameTypes;
        QMap<QString,qint32> mapStorageClasses;
        QMap<QString,qint32> mapFunctionMods;
        QMap<QString,qint32> mapFunctionConventions;
        QMap<QString,qint32> mapOperators;
        QMap<QString,qint32> mapNumbers;
        QMap<QString,qint32> mapHexNumbers;
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
    };

    explicit XDemangle(QObject *pParent=nullptr);
    static QString modeIdToString(MODE mode);
    static QString typeIdToString(TYPE type,MODE mode);
    static QString storageClassIdToString(SC storageClass,MODE mode);
    static QString objectClassIdToString(OC objectClass,MODE mode);
    static QString paramModIdToString(PM paramMod,MODE mode);
    static QString functionModIdToString(FM functionMod,MODE mode);
    static QString functionConventionIdToString(FC functionConvention,MODE mode);
    static QString operatorIdToString(OP _operator,MODE mode);

    static SYNTAX getSyntaxFromMode(MODE mode);

    SYMBOL getSymbol(QString sString,MODE mode);
    QString convert(QString sString,MODE mode);

    qint32 handleParams(HDATA *pHdata,QString sString,MODE mode,QList<PARAMETER> *pListParameters,qint32 nLimit,QList<QString> *pListStringRefs,QList<QString> *pListArgRefs);
    qint32 handleParamStrings(HDATA *pHdata,QString sString,MODE mode,PARAMETER *pParameter,QList<QString> *pListStringRefs,QList<QString> *pListArgRefs);

    MODE detectMode(QString sString);

    static QList<MODE> getAllModes();
    static QList<MODE> getSupportedModes();
    static void reverseList(QList<QString> *pList);
    static void reverseList(QList<MOD> *pList);
    static void reverseList(QList<QList<PARAMETER>> *pListList);

    HDATA getHdata(MODE mode);

private:
    struct STRING
    {
        qint32 nSize;
        QString sString;
    };

    struct NUMBER
    {
        qint32 nSize;
        qint64 nValue;
    };

    struct SIGNATURE
    {
        qint32 nSize;
        qint32 nValue;
    };

    QString symbolToString(SYMBOL symbol);
    STRING readString(QString sString,MODE mode);
    NUMBER readNumber(HDATA *pHdata,QString sString,MODE mode);
    bool _compare(QString sString,QString sSignature);

    bool isSignaturePresent(QString sString,QMap<QString,qint32> *pMap);
    SIGNATURE getSignature(QString sString,QMap<QString,qint32> *pMap);
    QMap<QString,qint32> getObjectClasses(MODE mode);
    QMap<QString,qint32> getTypes(MODE mode);
    QMap<QString,qint32> getNameTypes(MODE mode);
    QMap<QString,qint32> getParamMods(MODE mode);
    QMap<QString,qint32> getStorageClasses(MODE mode);
    QMap<QString,qint32> getFunctionMods(MODE mode);
    QMap<QString,qint32> getFunctionConventions(MODE mode);
    QMap<QString,qint32> getOperators(MODE mode);
    QMap<QString,qint32> getNumbers(MODE mode);
    QMap<QString,qint32> getHexNumbers(MODE mode);

    QString getNameFromSymbol(SYMBOL symbol);
    QString getNameFromParameter(PARAMETER *pParameter,MODE mode);
    QString getTemplatesFromParameters(QList<PARAMETER> *pListParameters,MODE mode);
    QString getStringFromParameter(PARAMETER parameter,MODE mode,QString sName="",bool bFuncRet=false);
};

#endif // XDEMANGLE_H
