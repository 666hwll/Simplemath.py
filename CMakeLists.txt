cmake_minimum_required(VERSION 3.10)
project(Simplemath)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} simplemath.cpp)
add_library(local_strings STATIC local_strings.cpp)

target_link_libraries(${PROJECT_NAME} local_strings)