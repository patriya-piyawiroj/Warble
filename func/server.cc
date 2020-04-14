#include "server.h"

Status FuncServiceImpl::hook(ServerContext* context, const HookRequest* request, HookReply* reply) {
  int event_type = request->event_type();
  std::string event_function = request->event_function();
  std::pair<int, std::string> pair(event_type, event_function);
  func_.insert(pair);
  return Status::OK;
}

Status FuncServiceImpl::unhook(ServerContext* context, const UnhookRequest* request, UnhookReply* reply) {
  int event_type = request->event_type();
  auto it = func_.find(event_type);
  if (it == func_.end()) {
    return Status(StatusCode::NOT_FOUND, "Event not found");
  }
  return Status::OK;
}

Status FuncServiceImpl::event(ServerContext* context, EventRequest* request, EventReply* reply) {
/*  int event_type = request->event_type();
  auto it = map_.find(event_type):
  if (it == map_.end()) {
    return Status(StatusCode::NOT_FOUND, "Event not found");
  } 
  std::string event_function = it*;
  Any request_payload;
  Any reply_payload;
  request_payload.PackFrom(request->paylaod());
  reply_payload(reply->payload());
  warble_.Call(event_function, &request_payload, &reply_payload);
*/
  return Status::OK;
}

void RunServer() {
  std::string server_address("127.0.0.1:50000");
  FuncServiceImpl service;

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
