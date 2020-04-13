#include <iostream>

#include <grpcpp/grpcpp.h>

#include "func.grpc.pb.h"
#include "warble.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode;
using func::FuncService;
using func::HookRequest;
using func::HookReply;
using func::UnhookRequest;
using func::UnhookReply;
using func::EventRequest;
using func::EventReply; 

class FuncServiceImpl final : public FuncService::Service {
 public:
  Status hook(ServerContext* context, const HookRequest* request, HookReply* reply);
  Status unhook(ServerContext* context, const UnhookRequest* request, UnhookReply* reply);
  Status event(ServerContext* context, EventRequest* request, EventReply* reply);
 private:
  std::unordered_map<int, std::string> func_; 
};