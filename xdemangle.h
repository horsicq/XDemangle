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
        MODE_MSVC,
        MODE_GCC_2XX,
        MODE_GCC_3XX,
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
        TYPE_LONGDOUBLE,
        TYPE_INT64,
        TYPE_UINT64,
        TYPE_CHAR8,
        TYPE_CHAR16,
        TYPE_CHAR32,
        TYPE_WCHAR,
        TYPE_VARARGS
    };

    struct PARAMETER
    {
        TYPE type;
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
        SC_VOLATILE
    };

    struct SYMBOL
    {
        bool bValid;
        MODE mode;
        QList<QString> listNames;
        PARAMETER paramReturn;
        QList<PARAMETER> listFunctionArguments;
        OC objectClass;
        SC storageClass;
    };

    explicit XDemangle(QObject *pParent=nullptr);
    QString modeIdToString(MODE mode);
    QString typeIdToString(TYPE type,MODE mode);
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
    SYMBOL handle_MSVC(QString sString);
    bool _compare(QString sString,QString sSignature);

    bool isSignaturePresent(QString sString,QMap<QString,qint32> *pMap);
    SIGNATURE getSignature(QString sString,QMap<QString,qint32> *pMap);
    QMap<QString,qint32> getObjectClasses(MODE mode);
    QMap<QString,qint32> getTypes(MODE mode);
    QMap<QString,qint32> getStorageClasses(MODE mode);
};

#endif // XDEMANGLE_H
