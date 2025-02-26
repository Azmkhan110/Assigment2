cmake_minimum_required(VERSION 3.22)
project(assign)

set(CMAKE_CXX_STANDARD 20)

# Adds both main.cpp and Deque.cpp as source files
add_executable(assign main.cpp Deque.cpp)
