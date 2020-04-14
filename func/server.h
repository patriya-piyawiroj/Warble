//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
#ifndef FUNC_SERVER_H_
#define FUNC_SERVER_H_

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

// Server that implements functions defined in protos/func. Runs on port 50000. 
class FuncServiceImpl final : public FuncService::Service {
 public:
  // Hooks an event type
  Status hook(ServerContext* context, const HookRequest* request, HookReply* reply);

  // Unhooks an event type
  Status unhook(ServerContext* context, const UnhookRequest* request, UnhookReply* reply);

  // Calls an event
  Status event(ServerContext* context, EventRequest* request, EventReply* reply);
 private:
  // map of event types to strings representing functions declared in func/warble.h
  std::unordered_map<int, std::string> func_; 
};
#endif // FUNC_SERVER_H_
