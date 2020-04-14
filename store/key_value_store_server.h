#ifndef STORE_SERVER_H_
#define STORE_SERVER_H_

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

DEFINE_string(store, "", "Stores to the given filename");

// Server that implements functions defined in protos/kvstore.proto Runs on port 50001 and takes a flag -store
// to store to file. Otherwise stores to kvstore/store.h
class KvstoreServiceImpl final : public KeyValueStore::Service {
 public:
  // variable that stores a filename if exists
  std::string filename_;

  // map put key,value
  Status put(ServerContext* context, const PutRequest* request, PutReply* reply);

  // map get key
  Status get(ServerContext* context, const GetRequest* request, GetReply* reply);

  // map remove key
  Status remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply);

 private:
  // Map defined in kvstore/store.h
  Kvmap map_;

  // Adds a key and value to given filename
  void CreateKeyFile(const std::string &key, const std::string &value, const std::string &filename);

  // Writes a line to given filename
  void Writeline(const std::string &file_name, const std::string &key, const std::string &val);

  // Deletes a line from given filename
  void Deleteline(const std::string &file_name, int n);
};
#endif // STORE_SERVER_H_
