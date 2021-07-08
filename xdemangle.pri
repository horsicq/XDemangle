INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/xdemangle.h

SOURCES += \
    $$PWD/xdemangle.cpp

!contains(XCONFIG, xcppfilt) {
    XCONFIG += xcppfilt
    include($$PWD/../XCppfilt/xcppfilt.pri)
}
