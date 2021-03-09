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
        MODE_MSVC32, // TODO MSVC64
        MODE_GCC,
        MODE_BORLAND,
        MODE_WATCOM
        // TODO more
    };

    enum TYPE
    {
        TYPE_UNKNOWN=0,
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
        TYPE_VARARGS
    };

    enum OC
    {
        OC_UNKNOWN=0,
        OC_GLOBALOBJECT,
        OC_STATICCLASSMEMBER
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
        SC_HUGE
    };

    enum FD
    {
        FD_UNKNOWN=0,
        FD_NEAR,
        FD_FAR
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
        FC_VECTORCALL
    };

    enum ST
    {
        ST_UNKNOWN=0,
        ST_VARIABLE,
        ST_FUNCTION
    };

    enum PM
    {
        PM_NONE,
        PM_POINTER,
        PM_REFERENCE
    };

    struct PARAMETER
    {
        PM paramMod;
        SC storageClass;
        TYPE type;
    };

    struct SYMBOL
    {
        bool bValid;
        MODE mode;
        ST symbolType;
        QList<QString> listNames;
        // Variable
        OC objectClass;
        PARAMETER paramVariable;
        // Function
        PARAMETER paramFunctionReturn;
        QList<PARAMETER> listFunctionArguments;
        FD functionDistance;
        FC functionConvention;
    };

    explicit XDemangle(QObject *pParent=nullptr);
    QString modeIdToString(MODE mode);
    QString typeIdToString(TYPE type,MODE mode);
    QString storageClassIdToString(SC storageClass,MODE mode);
    QString objectClassIdToString(OC objectClass,MODE mode);
    QString paramModIdToString(PM paramMod,MODE mode);
    QString functionConventionIdToString(FC functionConvention,MODE mode);
    SYMBOL getSymbol(QString sString,MODE mode);
    QString convert(QString sString,MODE mode);

private:
    struct STRING
    {
        qint32 nSize;
        QString sString;
    };

    struct SIGNATURE
    {
        qint32 nSize;
        qint32 nValue;
    };

    QString symbolToString(SYMBOL symbol);
    STRING readString(QString sString,MODE mode);
    SYMBOL handle_MSVC_family(QString sString); // TODO rename or remove
    bool _compare(QString sString,QString sSignature);

    bool isSignaturePresent(QString sString,QMap<QString,qint32> *pMap);
    SIGNATURE getSignature(QString sString,QMap<QString,qint32> *pMap);
    QMap<QString,qint32> getObjectClasses(MODE mode);
    QMap<QString,qint32> getTypes(MODE mode);
    QMap<QString,qint32> getParamMods(MODE mode);
    QMap<QString,qint32> getStorageClasses(MODE mode);
    QMap<QString,qint32> getFunctionDistances(MODE mode);
    QMap<QString,qint32> getFunctionConventions(MODE mode);

    QString getNameFromSymbol(SYMBOL symbol);
    QString getStringFromParameter(PARAMETER parameter,MODE mode);
};

#endif // XDEMANGLE_H
