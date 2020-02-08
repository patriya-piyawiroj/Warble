cmake_minimum_required(VERSION 3.6...3.16)
project(warble)

set(gflags_DIR  "~/csci499_patriya-piyawiroj/gflags-2.2.1/build")
find_package(gflags REQUIRED)
add_executable("${PROJECT_NAME}" warble.cpp)
target_link_libraries("${PROJECT_NAME}" gflags)

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
#install(FILES warble.cpp DESTINATION src)

