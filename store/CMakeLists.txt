cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

set(glog_DIR "~/csci499_patriya-piyawiroj/third_party/glog")
find_package(glog 0.4.0 REQUIRED)

# Gets proto filenames
get_filename_component(store_proto "../protos/kvstore.proto" ABSOLUTE)
get_filename_component(store_proto_path "${store_proto}" PATH)

find_package(gflags REQUIRED)

# Generates gRPC codes
set(DIST_DIR "${CMAKE_CURRENT_BINARY_DIR}/dist")
file(MAKE_DIRECTORY ${DIST_DIR})
set(store_proto_srcs "${DIST_DIR}/kvstore.pb.cc")
set(store_proto_hdrs "${DIST_DIR}/kvstore.pb.h")
set(store_grpc_srcs "${DIST_DIR}/kvstore.grpc.pb.cc")
set(store_grpc_hdrs "${DIST_DIR}/kvstore.grpc.pb.h")
add_custom_command(
      OUTPUT "${store_proto_srcs}" "${store_proto_hdrs}" "${store_grpc_srcs}" "${store_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${DIST_DIR}"
        --cpp_out "${DIST_DIR}"
        -I "${store_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${store_proto}"
      DEPENDS ${store_proto})

# Include generated *.pb.h files
include_directories("${DIST_DIR}")

#set(client_interface_hdrs "key_value_store_client_interface.h")

# Compiles store as a library
add_library(store STATIC store.cc store.h)
add_library(kvstore_client STATIC kvstore_client.cc kvstore_client.h)

# Adds test
#add_executable(store_test store_test.cc)
#target_link_libraries(store_test PUBLIC
	#gtest
    #gtest_main
    #kvstore_client.h kvstore_client.cc
    #store
    #)
#add_test(
	#NAME store_test
    #COMMAND store_test
    #)

add_executable(kvtest kvtest.cc 
	kvstore_client
	store
	${store_proto_srcs}
	${store_grpc_srcs})
target_link_libraries(kvtest
	${_GRPC_GRPCPP_UNSECURE}
	${_PROTOBUF_LIBPROTOBUF}
	glog::glog
	gflags
	store)
# Compiles key_value_store_server_sync
add_executable(key_value_store_server key_value_store_server.cc
    key_value_store_server.h
    store
    ${store_proto_srcs}
    ${store_grpc_srcs})
target_link_libraries(key_value_store_server
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    glog::glog
    store)
