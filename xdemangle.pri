INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/xdemangle.h

SOURCES += \
    $$PWD/xdemangle.cpp

# XDemangle is fully self-contained (no XCppfilt / libiberty dependency).

!contains(XCONFIG, xarchive) {
    XCONFIG += xarchive
    include($$PWD/../XArchive/xarchive.pri)
}

DISTFILES += \
    $$PWD/LICENSE \
    $$PWD/README.md \
    $$PWD/xdemangle.cmake
