cmake_minimum_required(VERSION 3.22)
project(sm4_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_sm4 test_sm4.c sm4.c)
