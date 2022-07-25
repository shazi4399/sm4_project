cmake_minimum_required( VERSION 3.5 FATAL_ERROR )

project( test )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable( test test.cpp )

target_link_libraries( test PUBLIC "/usr/local/openssl/lib" )

target_include_directories( test PUBLIC "${PROJECT_SOURCE_DIR}" )
