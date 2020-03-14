#include <string>
#include <iostream>
#include <stdlib.h>
#include <optional>

#include <grpcpp/grpcpp.h>
#include <glog/logging.h>

#include "warble.grpc.pb.h"

#include "store.h"


using grpc::Status;
using grpc::StatusCode;
using warble::Warble;
using warble::RegisteruserRequest;
using warble::RegisteruserReply;

// A mock server that calls warble functions directly rather than through func. This is meant to simulate 
// warble functionality. Not to be confused with WarbleService as this does not connect to kvstore through gRPC.
// Rather, it uses a map defined and used in kvstore.
//     Example: 
//         MockServer server;
//         server.RegisterUser(username);
class MockServer {
 public:
  // Feature 1: Registers a new user
  void RegisterUser(const std::string& username);
  
  // Feature 2: Creates a warble optionally as a reply, returns new warble ID
  //Status CreateWarble(const WarbleRequest* request, const WarbleReply* reply);
  
  // Feature 3: Follows a user
  //Status Follow(const FollowRequest* request, const FollowReply* reply);
  
  // Feature 4: Returns a warble from ID
  //Status Read(const ReadRequest* request, const ReadReply* replyu);
  
  // Feature 5: Returns user follower and following
  //Status Profile(const ProfileRequest* request, const ProfileReply* reply);

 private:
  Kvmap map_;
};
