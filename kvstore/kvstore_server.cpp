#include kvstore_server.h

Status KvstoreServiceImpl::put(ServerContext* context, const PutRequest* request, PutReply* reply) {
  std::unique_lock<std::mutex> lock(mu_);
  map_.put(request->key(), request->value());
  return Status::OK;
}

Status KvstoreServiceImpl::get(ServerContext* context, const GetRequest* request, GetReply* reply) {
  std::unique_lock<std::mutex> lock(mu_);
  std::string value = map_.get(request->key());
  if (value == std::nullopt) {
     return Status::NOT_FOUND;
  } else {
     reply->set_reply(value);
     return Status::OK;
  }
}

Status KvstoreServiceImpl::remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply) {
  std::unique_lock<std::mutex> lock(mu_);
  bool removed = map_remove(request->key());
  if (removed) {
    return Status::OK;
  else {
    return Status::NOT_FOUND;
  }
}


void RunServer() {
  std::string server_address("127.0.0.1:50001");
  KvstoreServiceImpl service;

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
