//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
#ifndef FUNC_WARBLEIMPL_H_
#define FUNC_WARBLEIMPL_H_

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
#include "../store/kvstore_client.h"


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

// Warble functions defined in protos/warble.proto. These functions are known and used by func func/server.h
// and connects and stores data to kvstore through gRPC. 
//    Example: 
//        WarbleImpl warble;
//        warble.Call("register", RegisterUserRequest(), RegisterUserReply());
// All functions are handled through Call, which takes any protobuf payload. 
class WarbleImpl {
 public:
  // This function maps a given event_function string to one of the five features defined below and calls it 
  void Call(std::string event_function, const google::protobuf::Any* request, google::protobuf::Any* reply);

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

#endif // FUNC_WARBLEIMPL_H_
