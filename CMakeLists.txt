cmake_minimum_required(VERSION 3.10)
project(ArrayOperations)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES Array_operations.cpp Main.cpp)

add_executable(ArrayOperations ${SOURCE_FILES})

