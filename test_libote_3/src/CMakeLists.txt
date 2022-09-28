#INCLUDE_DIRECTORIES向工程添加多个特定的头文件搜索路径
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

#查找当前目录下所有的源文件
AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/src" SRC_LIST)

#在整个电脑上查找libOTe包
#find_package(libOTe REQUIRED)

#编译为指定名称的静态链接库
ADD_LIBRARY(SRC ${SRC_LIST})

target_link_libraries(SRC oc::libOTe relic_s)