cmake_minimum_required(VERSION 3.6...3.16)
project(warble)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(glog_DIR "~/csci499_patriya-piyawiroj/third_party/glog")

find_package(gflags REQUIRED)
find_package(glog 0.4.0 REQUIRED)

# Gets proto filenames
get_filename_component(warble_proto "../protos/warble.proto" ABSOLUTE)
get_filename_component(warble_proto_path "${warble_proto}" PATH)

# Generates gRPC codes
set(DIST_DIR "${CMAKE_CURRENT_BINARY_DIR}/dist")
file(MAKE_DIRECTORY ${DIST_DIR})
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

# Compiles movk server as library
#add_library(mock_service STATIC mock_service.cc mock_service.h)

add_executable("${PROJECT_NAME}" warble_cli.cc warble_cli.h
	mock_service.h mock_service.cc
	store.h store.cc
	${warble_proto_srcs}
	${warble_grpc_srcs})
target_link_libraries("${PROJECT_NAME}"
	${_GRPC_GRCPP_UNSECURE}
	${_PROTOBUF_LIBPROTOBUF}
	#mock_service
	gflags
	glog::glog)


#target_link_libraries("${PROJECT_NAME}" gflags)
#target_link_libraries("${PROJECT_NAME}" glog::glog)
