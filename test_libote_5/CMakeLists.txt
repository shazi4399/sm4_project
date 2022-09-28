 cmake_minimum_required(VERSION 3.15)
project(KKRT)

 #add_definitions(-DENABLE_KKRT=1)
add_executable(main main.cpp)

find_package(libOTe REQUIRED)

target_link_libraries(main oc::libOTe)