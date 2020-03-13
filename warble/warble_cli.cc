#include "warble_cli.h"

// TODO: Prints error message
void WarbleInterface::PrintError(const std::string &errorMessage, const std::string &fields) {
  //printf("%s %s", errorMessage.c_str(), fields.c_str());
  cout << errorMessage << fields;
}

// Registers the given non-blank username
void WarbleInterface::RegisterUser(std::string username) {
  if (username == "") {
    LOG(ERROR) << "Username was blank";
    return;
  }
  LOG(INFO) << "Registering " << username;
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
  WarbleInteface warble;


  // register user if registeruser flag is present
  if (!FLAGS_registeruser.empty()) {
    warble.RegisterUser(FLAGS_registeruser);
    return 0;
  }

  // if not user logged in, can not perform other functions
  if (!FLAGS_user.empty()) { 
    //TODO: Print error
    warble.PrintError(MISSING_ARGUMENT_ERROR, "username");
    return 0;
  }
  
  if (!FLAGS_warble.empty()) 
    Warble(FLAGS_user, FLAGS_warble); 
  if (!FLAGS_reply.empty()) 
    Warble(FLAGS_user, FLAGS_warble, FLAGS_reply);
  if (!FLAGS_follow.empty()) 
    Follow(FLAGS_user, FLAGS_follow);
  if (!FLAGS_read.empty()) 
    Read(FLAGS_read);
  if (!FLAGS_profile) 
    Profile();

  return 0;
}
