cmake_minimum_required(VERSION 3.29)
project(img2ansi)

set(CMAKE_CXX_STANDARD 20)

find_package(Freetype REQUIRED)
file(GLOB SOURCES "src/*.cc")

include_directories(${FREETYPE_INCLUDE_DIRS} include)

add_executable(img2ansi ${SOURCES} main.cc
        src/header-generator.h)
target_link_libraries(img2ansi ${FREETYPE_LIBRARIES})