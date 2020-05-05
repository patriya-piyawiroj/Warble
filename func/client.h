//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//

#ifndef FUNC_CLIENT_H_
#define FUNC_CLIENT_H_

#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
#include <optional>

#include <grpcpp/grpcpp.h>
#include <glog/logging.h>

#include "func.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::ClientReaderWriter;
using func::HookRequest;
using func::HookReply;
using func::UnhookRequest;
using func::UnhookReply;
using func::EventRequest;
using func::EventReply;
using func::FuncService;

// A client that connects to func server func/server.h over gRPC and formats request and response as needed
class FuncClient {
 public:
  // Instantiates client with connection to channel
  FuncClient(std::shared_ptr<Channel> channel);

  // Hooks a given event type and event function
  void Hook(const int32_t &event_type, const std::string &event_function);

  // Unhooks a given event type and event function
  void Unhook(const int32_t &event_type);
  
  // Calls an event with an event type and payload
  google::protobuf::Any Event(const int32_t &event_type, const google::protobuf::Any &payload);
 
 private:
  std::unique_ptr<FuncService::Stub> stub_;
};

#endif // FUNC_CLIENT_H_
