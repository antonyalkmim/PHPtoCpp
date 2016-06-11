cmake_minimum_required(VERSION 3.5)
project(PHPtoCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    README.md
    transpiler.cpp
    transpiler.h node.cpp node.h list.cpp list.h)

add_executable(PHPtoCpp ${SOURCE_FILES})