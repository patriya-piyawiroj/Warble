cmake_minimum_required(VERSION 3.6...3.16)
project(warble)

set(gflags_DIR  "~/csci499_patriya-piyawiroj/third-party/gflags-2.2.1")
find_package(gflags REQUIRED)
add_executable("${PROJECT_NAME}" warble.cpp)
target_link_libraries("${PROJECT_NAME}" gflags)
