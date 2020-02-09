#include <iostream>
#include <grpc/grpc.h>
#include <unordered_map>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;

class KvstoreServiceImpl final : public KeyValueStore::Service {

  
