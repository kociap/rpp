cmake_minimum_required(VERSION 3.1)

project(rpp)
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

set(RPP_SOURCE_FILES

)

set(RPP_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(rpp RPP_SOURCE_FILES)
target_include_directories(rpp RPP_INCLUDE_DIRS CURL_INCLUDE_DIRS)
