include_directories(${CMAKE_CURRENT_LIST_DIR})

# XDemangle is fully self-contained: all demanglers (MSVC, Itanium/GNU/GCC, Java,
# Borland, Watcom, Rust, D, GNAT/Ada) are implemented natively in xdemangle.cpp.
set(XDEMANGLE_SOURCES
    ${XDEMANGLE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/xdemangle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xdemangle.h
)
