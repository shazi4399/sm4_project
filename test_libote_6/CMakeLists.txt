cmake_minimum_required(VERSION 2.8)
project(demo)



add_definitions(-DENABLE_KOS=1)

add_executable(main main.cpp OT_Tests.cpp)

find_package(libOTe REQUIRED)

target_link_libraries(main oc::libOTe)