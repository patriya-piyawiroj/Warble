#include <func_server.h>

  Status FuncServiceImpl::hook(ServerContext* context, const HookRequest* request, HookReply* reply) {
    // TODO
  }

  Status FuncServiceImpl::unhook(ServerContext* context, const UnhookRequest* request, UnhookReply* reply){
    // TODO:
  }

  Status FuncServiceImpl::event(ServerContext* context, EventRequest* request, EventReply* reply){
    //  TODO: 
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
