//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//

#include "mock_service.h"

// Returns true if user exists, false otherwise
bool MockServer::CheckUser(std::string username) {
  std::string key = "username-" + username;
  std::optional<std::string> user = map_.get(key);
  return user.has_value();
}

// Returns true if warble exists, false if otherwise
bool MockServer::CheckWarble(std::string warbleID) {
  std::string key = "warble-" + warbleID;
  std::optional<std::string> warble = map_.get(key);
  return warble.has_value();
}

// Creates a Warble
Warble MockServer::Create_Warble(std::string username, std::string text, std::string id, std::string parent_id) {
  // TODO : Create Warble
  Timestamp timestamp;
  timestamp.set_seconds(0);
  timestamp.set_useconds(0);
  Warble warble;
  warble.set_username(username);
  warble.set_text(text);
  warble.set_id(id);
  warble.set_parent_id(id);
  //warble.set_timestamp(timestamp);
  return warble;
}

// Converts Warble to string
std::string MockServer::Convert_Warble(Warble warble) {
  // Logic
  std::string result = "";
  //result += warble.timestamp().seconds() + ",";
  //result += warble.timestamp().useconds() + ",";
  result += warble.username() + ",";
  result += warble.text() + ",";
  result += warble.id() + ",";
  result += warble.parent_id() + ",";
  LOG(INFO) << "Created warble string: " << result;
  return result;
}

// Converts string to Warble
Warble MockServer::To_Warble(std::string string) {
  // Logic
  std::vector<std::string> result;
  std::stringstream s_stream(string);
  while(s_stream.good()) {
    std::string substr;
    getline(s_stream, substr, ',');
    result.push_back(substr);
  }
  Timestamp timestamp;
  //timestamp.set_seconds(result.at(0));
  //timestamp.set_useconds(result.at(1));
  Warble warble;
  warble.set_username(result.at(2));
  warble.set_text(result.at(3));
  warble.set_id(result.at(4));
  warble.set_parent_id(result.at(5));
  //warble.set_timestamp(timestamp);
  return warble;
}

// Feature 1: Register user:
void MockServer::RegisterUser(const RegisteruserRequest* request, RegisteruserReply* reply) {
  std::string username = request->username();
       	
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

// Feature 2: Post new warble
std::string MockServer::CreateWarble(const WarbleRequest* request, WarbleReply* reply) {
  // Get Request Params
  std::string username = request->username();
  std::string text = request->text();
  std::string parent_id = request->parent_id();

  // Feature Logic
  std::string hash_str = username + "-" + text + "-" + parent_id;
  std::size_t id = std::hash<std::string>{}(hash_str);
  std::string key = "warble-" + id;
  Warble warble = Create_Warble(username,text,std::to_string(id),parent_id);
  std::string warble_string = Convert_Warble(warble);
  map_.put(key, warble_string);
  LOG(INFO) << "Creating new warble with hash: " <<  id;

  // Set Reply
  //reply->add_warbles(warble);
  return std::to_string(id);
}

// Feature 3: Follow
void MockServer::Follow(const FollowRequest* request, FollowReply* reply) {
  // Get Request Params
  std::string username = request->username();
  std::string to_follow = request->to_follow();

  // Add username to followers of to_follow
  std::string followersKey = "followers-" + to_follow;
  std::optional<std::string> followers = map_.get(followersKey);
  if (followers.has_value()) {
    std::string updated = followers.value() + username + ",";
    map_.put(followersKey, updated); 
    LOG(INFO) << username << " is now following " << to_follow;
  } 
  // Add userToFollow to following of username
  std::string followingKey = "following-" + username;
  std::optional<std::string> following = map_.get(followingKey);
  if (following.has_value()) {
    std::string updated = following.value() + to_follow + ",";
    map_.put(followingKey, updated);
    LOG(INFO) << to_follow << " has follower " << username;
  }
  LOG(INFO) << " finished following";
  return;
}

// Feature 4: Read
void MockServer::Read(const ReadRequest* request, ReadReply* reply) {
  // Get Request Params
  std::string warble_id = request->warble_id();

  // Feature Logic
  std::string key = "warble-" + warble_id;
  std::optional<std::string> warble_string = map_.get(key);
  Warble warble;
  if (warble_string.has_value()) {
    Warble warble = To_Warble(warble_string.value());
  }
  // Set Reply
  //reply->add_warbles(warble);
  LOG(INFO) << "reading warble from id: " << warble_id;
  return;
}

// Feature 5: Profile
void MockServer::Profile(const ProfileRequest* request, ProfileReply* reply) {

  // Get Request Params
  std::string username = request->username();

  // Feature Logic
  std::string followersKey = "followers-" + username;
  std::optional<std::string> followers = map_.get(followersKey);
  std::string followingKey = "following-" + username;
  std::optional<std::string> following = map_.get(followingKey);

  // Set Reply
  if (followers.has_value()) {
    std::stringstream s_stream(followers.value());
    int i=0;
    while(s_stream.good()) {
      std::string substr;
      getline(s_stream, substr, ',');
      reply->set_followers(i, substr);
      i++;
    }
  }
  if (following.has_value()) {
    std::stringstream s_stream(following.value());
    int i=0;                                                                                                                while(s_stream.good()) {                                                                                                  std::string substr;                                                                                                     getline(s_stream, substr, ',');
      reply->set_following(i, substr);                                                                                        i++;			      
    }
  }
  LOG(INFO) << "Retrieved profile for " << username;
  return;
}

