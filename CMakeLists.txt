cmake_minimum_required(VERSION 3.1)

project(rpp)
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

set(RPP_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/source/response.cpp
    ${PROJECT_SOURCE_DIR}/source/rpp.cpp
    ${PROEJCT_SOURCE_DIR}/source/url.cpp
)

set(RPP_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(curl)

set(RPP_CURL_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/curl/include)

add_library(rpp STATIC ${RPP_SOURCE_FILES})
target_link_libraries(rpp libcurl)
target_include_directories(rpp
    PUBLIC ${RPP_INCLUDE_DIRS}
    PRIVATE ${RPP_CURL_INCLUDE_DIRS}
)