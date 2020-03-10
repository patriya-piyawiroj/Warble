#include <string>
#include <optional>

#include <grpcpp/grpcpp.h>

#include "func_server.h"
#include "kvstore_client.h"

// Warble features known by func
class WarbleService {
 public:
  // Initializes KvstoreClient
  WarbleService();

  // Calls relevant method given string
  void Call(std::string event_function, Any *request, Any *reply);

  // Feature 1: Registers a new user
  Status RegisterUser(const RegisteruserRequest* request, const RegisteruserReply* reply);

  // Feature 2: Creates a warble optionally as a reply, returns new warble ID
  Status CreateWarble(const WarbleRequest* request, const WarbleReply* reply);
  
  // Feature 3: Follows a user
  Status Follow(const FollowRequest* request, const FollowReply* reply);
  
  // Feature 4: Returns a warble from ID
  Status Read(const ReadRequest* request, const ReadReply* replyu);
  
  // Feature 5: Returns user follower and following
  Status Profile(const ProfileRequest* request, const ProfileReply* reply);

 private:
  KvstoreClient kvstore_;

  // Check if user exists
  bool CheckUser(std::string username);

  // Checks if warble exists
  bool CheckWarble(std::string warbleID);

  // Creates a warble
  Warble Create_Warble(std::string username, std::string parent_id);

  // Converst Warble to string
  std::string Convert_Warble(Warble warble);

  // Converts string to warble
  Warble To_Warble(std::string);
}
