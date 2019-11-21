cmake_minimum_required(VERSION 3.15)
project(code)
set(CMAKE_CXX_STANDARD 17)

add_executable(Bubble 冒泡排序.cpp)
add_executable(Quick_Sort 快速排序.cpp)
add_executable(Straight_Insertion_Sort 直接插入排序.cpp)
add_executable(Shell_Sort 希尔排序.cpp)