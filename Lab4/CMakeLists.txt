cmake_minimum_required(VERSION 3.24)
project(Set)

set(CMAKE_CXX_STANDARD 20)

add_executable(Set App.cpp Set.h Set.cpp SetIterator.h SetIterator.cpp ExtendedTest.h ExtendedTest.cpp ShortTest.h ShortTest.cpp TestMethod.cpp TestMethod.h)
