//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
#ifndef STORE_CLIENT_H_
#define STORE_CLIENT_H_
#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
#include <optional>

#include <grpcpp/grpcpp.h>
#include <glog/logging.h>

#include "kvstore.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::ClientReaderWriter;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;
using kvstore::RemoveRequest;
using kvstore::RemoveReply;
using kvstore::KeyValueStore;

class KvstoreClient {
 public:
  KvstoreClient(std::shared_ptr<Channel> channel); 
  void Put(const std::string& key, const std::string& value, const std::optional<std::string>& filename);
  std::optional<std::string> Get(const std::string&  key); 
  void Remove(const std::string& key);
 private:
  std::unique_ptr<KeyValueStore::Stub> stub_;
};
  
#endif // STORE_CLIENT_H_
