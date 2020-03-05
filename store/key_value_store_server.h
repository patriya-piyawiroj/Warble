#include <iostream>
#include <unordered_map>
#include <string>

#include <grpcpp/grpcpp.h>

#include "kvstore.grpc.pb.h"

#include "store.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;
using kvstore::RemoveRequest;
using kvstore::RemoveReply;

class KvstoreServiceImpl final : public KeyValueStore::Service {
 public:
  Status put(ServerContext* context, const PutRequest* request, PutReply* reply);
  Status get(ServerContext* context, const GetRequest* request, GetReply* reply);
  Status remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply);
 private:
  Kvmap kvmap_;
};
  
