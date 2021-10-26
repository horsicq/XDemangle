include_directories(${CMAKE_CURRENT_LIST_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/../XCppfilt/xcppfilt.cmake)

set(XDEMANGLE_SOURCES
    ${XCPPFILT_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/xdemangle.cpp
)
