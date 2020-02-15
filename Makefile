HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++ -std=c++17
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++17
ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc`\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc`\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl\
           -lgflags\
           -lglog\
					 -lgtest\

endif
PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = ./protos
SRC_PATH = ./src
BIN = ./bin
TEST = ./tests
vpath %.proto $(PROTOS_PATH)

%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<

all: run_server run_service chirp key_value_store_unit_tests service_layer_unit_tests

run_server: key_value_store.pb.o key_value_store.grpc.pb.o ./src/key_value_store_interface.o ./src/key_value_store.o ./src/backend_server.o ./src/run_server.o
	$(CXX) $^ $(LDFLAGS) -o ./bin/$@

run_service: service.pb.o service.grpc.pb.o key_value_store.pb.o key_value_store.grpc.pb.o data_storage_types.pb.o data_storage_types.grpc.pb.o ./src/service.o ./src/backend_client.o ./src/key_value_store_interface.o ./src/service_controller.o ./src/run_service.o
	$(CXX) $^ $(LDFLAGS) -o ./bin/$@

warble: service.pb.o service.grpc.pb.o ./src/chirp_client.o
	$(CXX) $^ $(LDFLAGS) -o ./bin/$@

clean:
	rm -f *.o *.pb.cc *.pb.h bin/* logs/*

