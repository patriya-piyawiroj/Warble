#include <string>
#include <optional>

#include <grpcpp/grpcpp.h>

#include "kvstore_client.h"

// Warble features known by func
class WarbleService {
 public:
  //Initializes KvstoreClient
  WarbleService();

  // Check if user exists
  bool CheckUser(std::string username);

  // Checks if warble exists
  bool CheckWarble(std::string warbleID);
  
  // Feature 1: Registers a new user
  void RegisterUser(std::string username);

  // Feature 2: Creates a warble optionally as a reply, returns new warble ID
  std::string CreateWarble(std::string username, std::string text, std::optional<string> warbleID);
  
  // Feature 3: Follows a user
  void Follow(std::string username, std::string userToFollow);
  
  // Feature 4: Returns a warble from ID
  std::string Read(std::string warbleID);
  
  // Feature 5: Returns user follower and following
  std::string* Profile(std::string username);
 private:
  KvstoreClient kvstore_;
}
