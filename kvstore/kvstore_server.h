#include <iostream>
#include <grpc/grpc.h>
#include <unordered_map>
#include <string>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;

class KvstoreServiceImpl final : public KeyValueStore::Service {
public:
  Status put(ServerContext* context, const PutRequest* request, PutReply* reply){}
  Status get(ServerContext* context, const GetRequest* request, GetReply* reply){}
  Status remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply){}
private:
  std::unordered_map<std::string, std::string> map_;
  std::mutex mu_;
};
  
