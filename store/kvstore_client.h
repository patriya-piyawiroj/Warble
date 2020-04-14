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

// A client that connects to kvstore server store/key_value_store_server.h over gRPC 
// and formats parameters to match kvstore.proto requests and response
class KvstoreClient {
 public:
  // Instantiates client with connection to channel
  KvstoreClient(std::shared_ptr<Channel> channel); 

  // Calls put for given key and value in kvstore server
  void Put(const std::string& key, const std::string& value);

  // Calls get for given key in kvstore server
  std::optional<std::string> Get(const std::string&  key); 

  // Calls remove for given key in kvstore server
  void Remove(const std::string& key);
 private:
  std::unique_ptr<KeyValueStore::Stub> stub_;
};
  
#endif // STORE_CLIENT_H_
