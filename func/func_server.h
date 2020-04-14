#include <iostream>
#include <grpc/grpc.h>

#include "warble_service.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;

class FuncServiceImpl final : public FuncService::Service {
 public:
  Status hook(ServerContext* context, const HookRequest* request, HookReply* reply);
  Status unhook(ServerContext* context, const UnhookRequest* request, UnhookReply* reply);
  Status event(ServerContext* context, EventRequest* request, EventReply* reply);
 private:
  std::unordered_map<int, std::string> map_;
  WarbleService warble_;
}