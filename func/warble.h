#include <string>
#include <iostream>
#include <stdlib.h>
#include <optional>
#include <ctime>
#include <vector>
#include <sstream>

#include <grpcpp/grpcpp.h>
#include <glog/logging.h>

#include "warble.grpc.pb.h"

#include "store.h"


using grpc::Status;
using grpc::StatusCode;
using warble::Warble;
using warble::Timestamp;
using warble::RegisteruserRequest;
using warble::RegisteruserReply;
using warble::WarbleRequest;
using warble::WarbleReply;
using warble::FollowRequest;
using warble::FollowReply;
using warble::ReadRequest;
using warble::ReadReply;
using warble::ProfileRequest;
using warble::ProfileReply;

// A mock server that calls warble functions directly rather than through func. This is meant to simulate 
// warble functionality. Not to be confused with WarbleService as this does not connect to kvstore through gRPC.
// Rather, it uses a map defined and used in kvstore.
//     Example: 
//         MockServer server;
//         server.RegisterUser(username);
class WarbleImpl {
 public:
  // Feature 1: Registers a new user
  void RegisterUser(const RegisteruserRequest* request, RegisteruserReply* reply);
  
  // Feature 2: Creates a warble optionally as a reply, returns new warble ID
  std::string CreateWarble(const WarbleRequest* request, WarbleReply* reply);
  
  // Feature 3: Follows a user
  void Follow(const FollowRequest* request, FollowReply* reply);
  
  // Feature 4: Returns a warble from ID
  void Read(const ReadRequest* request, ReadReply* reply);
  
  // Feature 5: Returns user follower and following
  void Profile(const ProfileRequest* request, ProfileReply* reply);

 private:
  Kvmap map_;

  // Creats a warble
  Warble Create_Warble(std::string username, std::string text, std::string id, std::string parent_id);

  // Converst Warble to string
  std::string Convert_Warble(Warble warble);

  // Converts string to warble
  Warble To_Warble(std::string);

  // Check if user exists
  bool CheckUser(std::string username);
  
  // Checks if warble exists
  bool CheckWarble(std::string warbleID);       
};

