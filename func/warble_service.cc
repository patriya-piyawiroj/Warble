
WarbleService::WarbleService() {
  kvstore_ = new KvstoreClient(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));
}

// Takes a function name and calls the relevant warble function and payload
void WarbleService::Call(std::string event_function, Any *request, Any *reply) {
  // TODO : Implement Logic for different event functions
  if ((event_function.compare("registeruser") == 0) {
    RegisteruserRequest request = any.unpack(ReigsteruserRequest.class);
    RegisteruserReply reply = any.unpack(RegisteruserReply.class);
    RegisterUser(request, reply);
  } else if ((event_function.compare("warble") == 0) {
  } else if ((event_function.compare("follow") == 0) {
  } else if ((event_function.compare("read") == 0) {
  } else if ((event_function.compare("profile") == 0 {
  }
}

// Returns true if user exists, false otherwise
bool WarbleService::CheckUser(std::string username) {
  std::string key = "username-" + username;
  std::optional<string> user = kvstore_.Get(key);
  if (user.has_value()) {
    return true;
  } else {
    return false;
  }
}

// Returns true if warble exists, false if otherwise
bool WarbleService::CheckWarble(std::string warbleID) {
  std::string key = "warble-" + warbleID;
  std::optional<string> warble = kvstore_.Get(key);
  if (warble.has_value()) {
    return true;
  } else {
    return false;
  }
}

// Creates a Warble
Warble WarbleService::Create_Warble(std::string username, std::string parent_id) {
  // TODO : Create Warble
  return new Warble;
}

// Converts Warble to string
std::string WarbleService::Convert_Warble(Warble warble) {
  // TODO : Logic
  return "";
}

// Converts string to Warble
Warble WarbleService::To_Warble(std::string) {
  // TODO: Logic
  return new Warble();
}

// Feature 1: Register User
Status WarbleService::RegisterUser(const RegisteruserRequest* request, const RegisteruserReply* reply) {
  // Get Request Params
  std::string username = request->username();

  // Feature Logic
  std::string key = "username-" + username;
  kvstore_.Put(key, username);
  std::string followersKey = "followers-" + username;
  kvstore_.Put(followersKey, "");
  std::string followingKey = "following-" + username;
  kvstore_.Put(followingKey, "");

  return Status::OK;
}

// Feature 2: Post new warble
std::string WarbleService::CreateWarble(const WarbleRequest* request, const WarbleReply* reply) {
  // Get Request Params
  std::string username = request->username();
  std::string text = request->text();
  int parent_id = request->parent_id();

  // Feature Logic
  std::string hash_str = username + "-" + text + "-" + parent_id;
  std::size_t id = std::hash<sstd::string>{}(warble);
  std::string key = "warble-" + id;
  Warble warble = Create_Warble(text, parent_id);
  std::string warble_string = Convert_Warble(warble);
  kvstore_.Put(key, warble_string);
  
  // Set Reply
  reply->set_warble(warble);
  return Status::OK;
}

// Feature 3: Follow
Status WarbleService::Follow(const FollowRequest* request, const FollowReply* reply) {
  // Get Request Params
  std::string username = request->username();
  std::string to_follow = request->to_follow();

  // Add username to followers of to_follow
  std::string followersKey = "followers-" + to_follow;
  std::string followers = kvstore_.Get(followersKey);
  followers.append(username + ",");
  kvstore_Put(followersKey, followers);

  // Add userToFollow to following of username
  std::string followingKey = "following-" + username;
  std::string following = kvstore_.Get(followingKey);
  following.append(to_follow + ",");
  kvstore_Put(followingKey, following);

  return Status::OK;
}

// Feature 4: Read
Status WarbleService::Read(const ReadRequest* request, const ReadReply* reply) {
  // Get Request Params
  std::string warble_id = request->warble_id();

  // Feature Logic
  std::string key = "warble-" + warble_id;
  std::string warble_string = kvstore_.Get(key);
  Warble warble = To_Warble(warble_string);

  // Set Reply
  reply->set_warbles(warble);
  return Status::OK;
}

// Feature 5: Profile
Status WarbleServie::Profile(const ProfileRequest* reqeust, const ProfileReply* reply) {

  // Get Request Params
  std::string username = request->username()
	
  // Feature Logic
  std::string followersKey = "followers-" + username;
  std::string followers = kvstore_.Get(followersKey);
  std::string followingKey = "following-" + username;
  std::string following = kvstore_.Get(followingKey);
  
  // Set Reply
  reply->set_followers(followers);
  reply->set_following(following);
  return Status::OK;
} 
