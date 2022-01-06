cmake_minimum_required(VERSION 3.17)
project(coursework)

set(CMAKE_CXX_STANDARD 14)
add_executable(coursework main.cpp)
add_subdirectory(./mylib)
include_directories(./mylib)
target_link_libraries(${PROJECT_NAME} lib)
