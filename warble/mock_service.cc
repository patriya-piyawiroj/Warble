#include "mock_service.h"

Status MockServer::RegisterUser(const RegisteruserRequest* request, const RegisteruserReply* reply) {
  std::string username = request->username();
   
  // Feature Logic
  std::string key = "username-" + username;
  map_.put(key, username);
  std::string followersKey = "followers-" + username;
  map_.put(followersKey, "");
  std::string followingKey = "following-" + username;
  map_.put(followingKey, "");

  LOG(INFO) << "Put in username: " << username;
  LOG(INFO) << "Retrieved: " << map_.get(key);
  return Status::OK 
}
