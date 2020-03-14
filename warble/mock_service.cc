#include "mock_service.h"

void MockServer::RegisterUser(const std::string &username) {
   
  // Feature Logic
  std::string key = "username-" + username;
  map_.put(key, username);
  std::string followersKey = "followers-" + username;
  map_.put(followersKey, "");
  std::string followingKey = "following-" + username;
  map_.put(followingKey, "");

  LOG(INFO) << "Put in username: " << username;
  LOG(INFO) << "Retrieved: " << map_.get(key).value();
}
