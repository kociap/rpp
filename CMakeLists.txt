cmake_minimum_required(VERSION 3.12)

project(rpp)
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

set(RPP_SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/source/response.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/rpp.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/url.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/body.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/request.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/urlsearchparams.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/headers.cpp"
)

set(RPP_HEADER_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rpp/body.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rpp/headers.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rpp/request.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rpp/response.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rpp/url.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rpp/urlsearchparams.hpp"
)

set(RPP_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# curl
set(BUILD_TESTING CACHE BOOL OFF) # Disable curl tests
set(BUILD_CURL_EXE CACHE BOOL OFF)
add_subdirectory(curl)

set(RPP_CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/curl/include)

add_library(rpp STATIC ${RPP_SOURCE_FILES} ${RPP_HEADER_FILES})
target_link_libraries(rpp libcurl)
target_include_directories(rpp
    PUBLIC ${RPP_INCLUDE_DIRS}
    PRIVATE ${RPP_CURL_INCLUDE_DIRS}
)