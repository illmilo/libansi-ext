cmake_minimum_required(VERSION 3.29)
project(libansi-ext)

set(CMAKE_CXX_STANDARD 20)

find_package(Freetype REQUIRED)
find_package(OpenCV REQUIRED)
file(GLOB SOURCES "src/*.cc")

include_directories(${FREETYPE_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
#include_directories(${OPENCV_INCLUDE_DIRS})

add_executable(libansi-ext ${SOURCES} main.cc
        res/header-generator.h)
target_link_libraries(libansi-ext ${FREETYPE_LIBRARIES} ${OpenCV_LIBS})