#include "warble.h"

void WarbleImpl::Call(std::string event_function, const google::protobuf::Any* any_request, google::protobuf::Any* any_reply) {
  if (event_function.compare("register") == 0) {
    RegisteruserRequest request;
    RegisteruserReply reply;
    if (any_request.UnpackTo(&request)) {
      RegisterUser(&request, &reply);
      any_reply.PackFrom(reply);
    }
  } else if (event_function.compare("create") == 0) {
    WarbleRequest request;
    WarbleReply reply;
    if (any_request.UnpackTo(&request)) {
      CreateWarble(&request, &reply);
      any_reply.PackFrom(reply);
    }
  } else if (event_function.compare("follow") == 0) {
    FollowRequest request;
    FollowReply reply; 
    if (any_request.UnpackTo(&request)) {
      Follow(&request, &reply);
      any_reply.PackFrom(reply);
    }
  } else if (event_function.compare("read") == 0) {
    ReadRequest request;                          
    ReadReply reply;
    if (any_request.UnpackTo(&request)) {                                   
      Read(&request, &reply);
      any_reply.PackFrom(reply);
    }
  } else if (event_function.compare("profile") == 0) {
    ProfileRequest request;
    ProfileReply reply;
    if (any_request.UnpackTo(&request)) {
      Profile(&request, &reply);
      any_reply.PackFrom(reply);
  } 
}

// Returns true if user exists, false otherwise
bool WarbleImpl::CheckUser(std::string username) {
  std::string key = "username-" + username;
  std::optional<std::string> user = map_.get(key);
  return user.has_value();
}

// Returns true if warble exists, false if otherwise
bool WarbleImpl::CheckWarble(std::string warbleID) {
  std::string key = "warble-" + warbleID;
  std::optional<std::string> warble = map_.get(key);
  return warble.has_value();
}

// Creates a Warble
Warble WarbleImpl::Create_Warble(std::string username, std::string text, std::string id, std::string parent_id) {
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
std::string WarbleImpl::Convert_Warble(Warble warble) {
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
Warble WarbleImpl::To_Warble(std::string string) {
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
void WarbleImpl::RegisterUser(const RegisteruserRequest* request, RegisteruserReply* reply) {
  std::string username = request->username();
  
  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));  

  // Feature Logic
  std::string key = "username-" + username;
  client.Put(key, username);
  std::string followersKey = "followers-" + username;
  client.Put(followersKey, "");
  std::string followingKey = "following-" + username;
  client.Put(followingKey, "");

  LOG(INFO) << "Put in username: " << username;
  LOG(INFO) << "Retrieved: " << map_.get(key).value();
}

// Feature 2: Post new warble
std::string WarbleImpl::CreateWarble(const WarbleRequest* request, WarbleReply* reply) {
  // Get Request Params
  std::string username = request->username();
  std::string text = request->text();
  std::string parent_id = request->parent_id();

  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

  // Feature Logic
  std::string hash_str = username + "-" + text + "-" + parent_id;
  std::size_t id = std::hash<std::string>{}(hash_str);
  std::string key = "warble-" + id;
  Warble warble = Create_Warble(username,text,std::to_string(id),parent_id);
  std::string warble_string = Convert_Warble(warble);
  client.Put(key, warble_string);
  LOG(INFO) << "Creating new warble with hash: " <<  id;

  // Set Reply
  //reply->add_warbles(warble);
  return std::to_string(id);
}

// Feature 3: Follow
void WarbleImpl::Follow(const FollowRequest* request, FollowReply* reply) {
  // Get Request Params
  std::string username = request->username();
  std::string to_follow = request->to_follow();

  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

  // Add username to followers of to_follow
  std::string followersKey = "followers-" + to_follow;
  std::optional<std::string> followers = client.Get(followersKey);
  if (followers.has_value()) {
    std::string updated = followers.value() + username + ",";
    client.Put(followersKey, updated); 
    LOG(INFO) << username << " is now following " << to_follow;
  } 
  // Add userToFollow to following of username
  std::string followingKey = "following-" + username;
  std::optional<std::string> following = client.Get(followingKey);
  if (following.has_value()) {
    std::string updated = following.value() + to_follow + ",";
    client.Put(followingKey, updated);
    LOG(INFO) << to_follow << " has follower " << username;
  }
  LOG(INFO) << " finished following";
  return;
}

// Feature 4: Read
void WarbleImpl::Read(const ReadRequest* request, ReadReply* reply) {
  // Get Request Params
  std::string warble_id = request->warble_id();

  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

  // Feature Logic
  std::string key = "warble-" + warble_id;
  std::optional<std::string> warble_string = client.Get(key);
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
void WarbleImpl::Profile(const ProfileRequest* request, ProfileReply* reply) {

  // Get Request Params
  std::string username = request->username();

  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

  // Feature Logic
  std::string followersKey = "followers-" + username;
  std::optional<std::string> followers = client.Get(followersKey);
  std::string followingKey = "following-" + username;
  std::optional<std::string> following = client.Get(followingKey);

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

