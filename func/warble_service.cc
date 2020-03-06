
WarbleService::WarbleService() {
  kvstore_ = new KvstoreClient(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));
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

// Feature 1: Register User
void WarbleService::RegisterUser(std::string username) {
  std::string key = "username-" + username;
  kvstore_.Put(key, username);
  std::string followersKey = "followers-" + username;
  kvstore_.Put(followersKey, "");
  std::string followingKey = "following-" + username;
  kvstore_.Put(followingKey, "");
}

// Feature 2: Post new warble
std::string WarbleService::CreateWarble(std::string username, std::string text, std::optional<string> warbleID) {
  std::string hash_str = warbleID.has_value ? username + "-" + text + "-" + warbleID.value() : username + "-" + text;
  std::size_t id = std::hash<sstd::string>{}(warble);
  std::string key = "warble-" + id;
  kvstore_.Put(key, text);
  cout << "warble ID: " << id;
  return id;
}

// Feature 3: Follow
void WarbleService::Follow(std::string username, std::string userToFollow) {
  // Add username to followers of userToFollow
  std::string followersKey = "followers-" + userToFollow;
  std::string followers = kvstore_.Get(followersKey);
  followers.append(username + ",");
  kvstore_Put(followersKey, followers);

  std::string followingKey = "following-" + username;
  std::string following = kvstore_.Get(followingKey);
  following.append(userToFollow + ",");
  kvstore_Put(followingKey, following);
}

// Feature 4: Read
void WarbleService::Read(std::string warbleID) {
  std::string key = "warble-" + warbleID;
  std::string text = kvstore_.Get(key);
  cout << "Text: " << text;
  return text;
}

// Feature 5: Profile
std::string* WarbleServie::Profile(std::string username) {
  std::string followersKey = "followers-" + username;
  std::string followers = kvstore_.Get(followersKey);
  std::string followingKey = "following-" + username;
  std::string following = kvstore_.Get(followingKey);
  std::string profileArray[] = {followers, following};
  return profileArray;
} 
