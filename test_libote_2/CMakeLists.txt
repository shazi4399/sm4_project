cmake_minimum_required (VERSION 3.12)

project(test_s)

## OpenSSL
###########################################################################
find_package(OpenSSL REQUIRED)
find_package(libOTe REQUIRED)

add_executable(test_s test_s.cpp)

target_include_directories(test_s PUBLIC ${RELIC_INCLUDE_DIR} ${RLC_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
target_link_libraries(test_s oc::libOTe)
#target_link_libraries(test_s ${libOTe_LIB} ${cryptoTools_LIB} ${RELIC_LIBRARIES} ${RLC_LIBRARY}  gmp gmpxx ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})