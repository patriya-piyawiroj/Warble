cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(glog_DIR "~/csci499_patriya-piyawiroj/third_party/glog")
find_package(glog 0.4.0 REQUIRED)

# Gets proto filenames
get_filename_component(func_proto "../protos/func.proto" ABSOLUTE)
get_filename_component(func_proto_path "${func_proto}" PATH)
get_filename_component(warble_proto "../protos/warble.proto" ABSOLUTE)
get_filename_component(warble_proto_path "${warble_proto}" PATH)

# Generates gRPC codes
set(DIST_DIR "${CMAKE_CURRENT_BINARY_DIR}/dist")
file(MAKE_DIRECTORY ${DIST_DIR})
set(func_proto_srcs "${DIST_DIR}/func.pb.cc")
set(func_proto_hdrs "${DIST_DIR}/func.pb.h")
set(func_grpc_srcs "${DIST_DIR}/func.grpc.pb.cc")
set(func_grpc_hdrs "${DIST_DIR}/func.grpc.pb.h")
add_custom_command(
    OUTPUT "${func_proto_srcs}" "${func_proto_hdrs}" "${func_grpc_srcs}" "${func_grpc_hdrs}"
    COMMAND ${_PROTOBUF_PROTOC}   
    ARGS --grpc_out "${DIST_DIR}"		
    --cpp_out "${DIST_DIR}"		
    -I "${func_proto_path}"		
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"		
    "${func_proto}"
    DEPENDS ${func_proto})	

set(warble_proto_srcs "${DIST_DIR}/warble.pb.cc")
set(warble_proto_hdrs "${DIST_DIR}/warble.pb.h")
set(warble_grpc_srcs "${DIST_DIR}/warble.grpc.pb.cc")
set(warble_grpc_hdrs "${DIST_DIR}/warble.grpc.pb.h")
add_custom_command(
    OUTPUT "${warble_proto_srcs}" "${warble_proto_hdrs}" "${warble_grpc_srcs}" "${warble_grpc_hdrs}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${DIST_DIR}"
    --cpp_out "${DIST_DIR}"
    -I "${warble_proto_path}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${warble_proto}"
    DEPENDS ${warble_proto})
	


# Include generated *.pb.h files
include_directories("${DIST_DIR}")

# Compiles key_value_store_server_sync
add_executable(server server.cc server.h
    warble.cc warble.h
    store
    ${warble_proto_srcs}
    ${warble_grpc_srcs}
    ${func_proto_srcs}		 
    ${func_grpc_srcs})
target_link_libraries(server
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}			   
    glog::glog)

