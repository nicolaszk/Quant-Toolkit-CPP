cmake_minimum_required(VERSION 3.10)
project(CsvParser)

#using c++17 std
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#flags for profiling
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(main main.cpp CsvReader.cpp)

