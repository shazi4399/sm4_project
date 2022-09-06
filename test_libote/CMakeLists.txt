cmake_minimum_required(VERSION 3.22)
project(myProject)

set(CMAKE_CXX_STANDARD 11)
find_package(libOTe REQUIRED)


add_executable(myProject Network.cpp Common.cpp OT_Tests.cpp)
target_link_libraries(myProject oc::libOTe)