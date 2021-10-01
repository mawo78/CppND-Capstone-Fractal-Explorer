cmake_minimum_required(VERSION 3.7)

set(CXX_FLAGS "-Wall -pthread -std=c++17")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(FractalExplorer)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

add_executable(FractalExplorer src/main.cpp)

target_link_libraries(FractalExplorer ${OpenCV_LIBS})
