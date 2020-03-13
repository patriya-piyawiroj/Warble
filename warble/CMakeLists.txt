cmake_minimum_required(VERSION 3.6...3.16)
project(warble)

set(glog_DIR " /usr/local/lib/cmake/glog")
find_package(gflags REQUIRED)
find_package(glog REQUIRED)
add_executable("${PROJECT_NAME}" warble_cli.cc)
target_link_libraries("${PROJECT_NAME}" gflags)
target_link_libraries("${PROJECT_NAME}" glog)
