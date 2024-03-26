cmake_minimum_required(VERSION 3.24)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix Matrix.cpp Matrix.h ShortTest.h ShortTest.cpp ExtendedTest.cpp App.cpp Iterator.h Iterator.cpp)
