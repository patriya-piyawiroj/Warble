#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <fstream>

#include <grpcpp/grpcpp.h>
#include <glog/logging.h>

#include "kvstore.grpc.pb.h"

#include "store.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode;
using kvstore::KeyValueStore;
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
  Kvmap map_;
  void CreateKeyFile(const std::string &key, const std::string &value, const std::string &filename);
  void Writeline(const char *file_name, const char *key, const char *val);
  void Deleteline(const char *file_name, int n);
};
  
