#include "key_value_store_server.h"

Status KvstoreServiceImpl::put(ServerContext* context, const PutRequest* request, PutReply* reply) {
  std::cout << "Attempting put " << request->key() << std::endl;
  map_.put(request->key(), request->value());
  return Status::OK;
}

Status KvstoreServiceImpl::get(ServerContext* context, const GetRequest* request, GetReply* reply) {
  std::optional<std::string> opt = map_.get(request->key());
  if (opt.has_value()) {
    reply->set_value(opt.value());
    return Status::OK;
  } else {
    return Status(StatusCode::NOT_FOUND, "GetRequest unsuccessful");
  }
}

Status KvstoreServiceImpl::remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply) {
  bool removed = map_.remove(request->key());
  if (removed) {
    return Status::OK;
  } else {
    return grpc::Status(grpc::StatusCode::NOT_FOUND, "RemoveRequest unsuccessful");
  }
}

void RunServer() {
  std::string server_address("127.0.0.1:50001");
  KvstoreServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char* argv[]) {
  RunServer();
  return 0;
}
