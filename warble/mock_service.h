#include <grpcpp/grpcpp.h>

#include "warble.grpc.pb.h"

#include "../store/store.h"


using gprc::Status;
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
  Status RegisterUser(const RegisteruserRequest* request, const RegisteruserReply* reply);
  
  // Feature 2: Creates a warble optionally as a reply, returns new warble ID
  //Status CreateWarble(const WarbleRequest* request, const WarbleReply* reply);
  
  // Feature 3: Follows a user
  //Status Follow(const FollowRequest* request, const FollowReply* reply);
  
  // Feature 4: Returns a warble from ID
  //Status Read(const ReadRequest* request, const ReadReply* replyu);
  
  // Feature 5: Returns user follower and following
  //Status Profile(const ProfileRequest* request, const ProfileReply* reply);

 private:
  Kvamp map_;
}
