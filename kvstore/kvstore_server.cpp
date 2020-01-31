#include <iostream>
#include <grpc/grpc.h>
#include <unordered_map>

class KvstoreServiceImpl final :  public KeyValueStore::Service {

  Status put(ServerContext* context, const PutRequest* request, PutReply* reply) {
    // TODO: put
     return Status::OK;
  }

  Status get(ServerContext* context, const GetRequest* request, GetReply* reply) {
    // TODO: get
    return Status::OK;
  }

  Status remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply) {
    // TODO: remove
    return Status::OK;
  }
};

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
