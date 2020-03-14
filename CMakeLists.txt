cmake_minimum_required(VERSION 3.3)
project(projectname C CXX)

# Uses cpp 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
include_directories(/usr/local/include)
link_directories(/usr/local/lib)


# Finds Protobuf installation
# Looks for protobuf-config.cmake file installed by Protobuf's CMake installation.
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
message(STATUS "Using protobuf ${protobuf_VERSION}")
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

# Hardcodes gRPC installation location
set(_GRPC_GRPCPP_UNSECURE grpc++_unsecure)
set(_GRPC_CPP_PLUGIN_EXECUTABLE /usr/local/bin/grpc_cpp_plugin)

set(THIRD_PARTY_DIR "third_party/grpc/third_party")

# Adds googletest
#add_subdirectory(${THIRD_PARTY_DIR}/googletest)
#enable_testing()

# Adds gflags
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
#find_package(gflags REQUIRED)

# Adds benchmark
#add_subdirectory(${THIRD_PARTY_DIR}/benchmark)

# Adds subdirectories
# ! Notice here !
add_subdirectory(store)
add_subdirectory(warble)
