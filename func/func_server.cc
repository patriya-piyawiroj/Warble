#include "func_server.h"

FuncServiceImpl::FuncServiceImpl() {
  KvstoreClient kvstore_(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
}

Status FuncServiceImpl::hook(ServerContext* context, const HookRequest* request, HookReply* reply) {
  auto event_type = request->event_type();
  auto event_function = request->event_function();
  kvstore_.Put(event_type, event_function);
  return Status::OK;
}

Status FuncServiceImpl::unhook(ServerContext* context, const UnhookRequest* request, UnhookReply* reply){
  auto event_type = request->event_type();
  kvstore_.Remove(event_type);
  return Status::OK;
}

Status FuncServiceImpl::event(ServerContext* context, EventRequest* request, EventReply* reply){
  //  TODO: Incoming int event_type and google.protobuf.Any payload. reply payload.
}

void RunServer() {
  std::string server_address("127.0.0.1:50000");
  FuncServiceImpl service;

  ServiceBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterServce(&servce);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char* argv[]) {
  RunServer();
  return 0;
}
