cmake_minimum_required(VERSION 3.24)
project(Bag)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bag App.cpp BagIterator.h Bag.cpp Bag.h ShortTest.cpp ShortTest.h ExtendedTest.cpp ExtendedTest.h BagIterator.cpp TestMethod.cpp TestMethod.h)
