include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/../XLLVMDemangler/3rdparty/)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../XLLVMDemangler/3rdparty/llvm/Demangle/)

if (NOT DEFINED XCPPFILT_SOURCES)
    include(${CMAKE_CURRENT_LIST_DIR}/../XCppfilt/xcppfilt.cmake)
    set(XDEMANGLE_SOURCES ${XDEMANGLE_SOURCES} ${XCPPFILT_SOURCES})
endif()

set(XDEMANGLE_SOURCES
    ${XDEMANGLE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/xdemangle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xdemangle.h
)
