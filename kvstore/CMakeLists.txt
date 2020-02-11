cmake_minimum_required(VERSION 3.1...3.16)

project(kvstore)

set(gRPC_DIR "~/csci499_patriya-piyawiroj/third-party/grpc/")
find_package(gRPC CONFIG REQUIRED)

add_executable("${PROJECT_NAME}" kvstore_server.cpp)
target_link_libraries("${PROJECT_NAME}" gRPC::grpc++)

