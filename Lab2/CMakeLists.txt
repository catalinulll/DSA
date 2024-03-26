cmake_minimum_required(VERSION 3.24)
project(PriorityQueue)

set(CMAKE_CXX_STANDARD 20)

add_executable(PriorityQueue App.cpp PriorityQueue.h PriorityQueue.cpp ExtendedTest.h ExtendedTest.cpp ShortTest.h ShortTest.cpp)
