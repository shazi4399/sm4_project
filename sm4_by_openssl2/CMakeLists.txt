cmake_minimum_required(VERSION 3.22)
project(sm4_project)

set(CMAKE_CXX_STANDARD 11)

SET(CRYPTO_SO
        /usr/local/lib/libcrypto.so
)
add_executable(testsm4 main.c sm4.c)
target_link_libraries(testsm4 ${CRYPTO_SO})