#include <iostream>
#include <string>

#include <grpc/grpc.h>

#include "kvstore.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;
using kvstore::RemoveRequest;
using kvstore::RemoveReply;

class KvstoreClient {
 public:
  KeyValueStoreClient(std::shared_ptr<Channel> channel); 
  void Put(const std::string& key, const std::string& value);
  void Get(const std::string&  key); 
  void Remove(const std::string& key):
 private:
  std::unique_ptr<KeyValueStore::Stub> stub_;
};
  
