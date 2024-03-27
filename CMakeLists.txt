# 若版本不够提醒用户升级到新的版本
cmake_minimum_required(VERSION 3.6)
SET (CMAKE_C_COMPILER             "/usr/bin/clang") # 填写绝对路径
SET (CMAKE_C_FLAGS                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER            "/usr/bin/clang++") # 填写绝对路径
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

# 设置项目名称，非必要但是都应加上
project(test)

# c++ 11标准
# Default to C99
# set (CMAKE_C_COMPILER /opt/j3_compile/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc)
# set (CMAKE_CXX_COMPILER /opt/j3_compile/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# message("cmake standard :"${CMAKE_C_STANDARD})
find_package(glog REQUIRED)
find_package(spdlog REQUIRED)
include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test src/main.cpp) # 生成可执行文件

target_link_libraries(test -lcurl)
target_link_libraries(test glog::glog spdlog::spdlog)

add_executable(spdlog_test src/spdlog_test.cpp) # 生成可执行文件
target_link_libraries(spdlog_test glog::glog spdlog::spdlog)


add_executable(thread_test src/thread_test.cpp) # 生成可执行文件
find_package(Threads REQUIRED)
target_link_libraries(thread_test PRIVATE Threads::Threads)


add_executable(thread_condition_variable_test src/thread_condition_variable_test.cpp) # 生成可执行文件
target_link_libraries(thread_condition_variable_test PRIVATE Threads::Threads)

add_executable(algorithm_test src/algorithm_test.cpp) # 生成可执行文件
add_executable(map_test src/map_test.cpp) # 生成可执行文件
add_executable(queue_test src/queue_test.cpp) # 生成可执行文件
add_executable(set_test src/set_test.cpp) # 生成可执行文件
add_executable(string_test src/string_test.cpp) # 生成可执行文件
add_executable(tuple_test src/tuple_test.cpp) # 生成可执行文件

add_executable(vector_test src/vector_test.cpp) # 生成可执行文件
add_executable(arry_test src/arry_test.cpp)
add_executable(stream_test src/stream_test.cpp) # 生成可执行文件


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/) # #${PROJECT_SOURCE_DIR}=~/product/ydu/工程的根目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)





