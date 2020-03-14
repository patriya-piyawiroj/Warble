#include "warble_cli.h"

void WarbleInterface::PrintError(const std::string &errorMessage, const std::string &fields) {
  std::cout << errorMessage << fields << std::endl;
}

// Registers the given non-blank username
void WarbleInterface::RegisterUser(std::string username) {
  if (username == "") {
    PrintError(MISSING_ARGUMENT_ERROR, "username");
    return;
  }
  LOG(INFO) << "Registering " << username;

  // Calls warble function registeruser
  RegisteruserRequest request;
  RegisteruserReply reply;
  request.set_username(username);
  warble_service.RegisterUser(request, reply);
}

// Posts a new warble returns the id of new warble
std::string WarbleInterface::Warble(const std::string &username, const std::string &text) {
  return "";
}

// Posts a new warble as a reply 
std::string WarbleInterface::Reply(const std::string &username, const std::string &text, const std::string &warbleID) {
  return "";
}

// Starts following a given user
void WarbleInterface::Follow(std::string username, std::string userToFollow) {

}

// Reads a warble thread from the given id
void WarbleInterface::Read(std::string warbleID) {

}

// Returns this user's following and followers
void WarbleInterface::Profile(std::string username) {

}

int main(int argc, char* argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  WarbleInterface warble;


  // register user if registeruser flag is present
  if (!FLAGS_registeruser.empty()) {
    warble.RegisterUser(FLAGS_registeruser);
    return 0;
  }

  // if not user logged in, can not perform other functions
  if (FLAGS_user.empty()) { 
    warble.PrintError(INVALID_FLAG_ERROR, "username");
    return 0;
  }

  LOG(INFO) << "Using user: " << FLAGS_user;
  
  if (!FLAGS_warble.empty() && FLAGS_reply.empty())
    // creates new warble if user and warble flag exists but reply does not 
    warble.Warble(FLAGS_user, FLAGS_warble); 
  if (!FLAGS_reply.empty()) 
    // create new warble as reply if user, warble and reply flags exist
    if (FLAGS_warble.empty())
      warble.PrintError(INVALID_FLAG_ERROR, "warble");    
      return 0;	    
    warble.Reply(FLAGS_user, FLAGS_warble, FLAGS_reply);
  if (!FLAGS_follow.empty()) 
    // follows another user if user and follow flags exist
    warble.Follow(FLAGS_user, FLAGS_follow);
  if (!FLAGS_read.empty()) 
    // reads a warble if read flag exists
    warble.Read(FLAGS_read);

  if (!FLAGS_profile) 
    // prints profile
    warble.Profile(FLAGS_user);

  return 0;
}
