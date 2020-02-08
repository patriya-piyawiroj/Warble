#include <stdlib.h>
#include <gflags/gflags.h>
#include <iostream>

const std::string INVALID_FLAG_ERROR = "Invalid flag combinations";
const std::string MISSING_ARGUMENT_ERROR = "Missing arguments";

DEFINE_string(registeruser, "", "Registers the given username");
DEFINE_string(user, "", "Logs in as the given username");
DEFINE_string(warble, "", "Creates a new warble with the given text");
DEFINE_string(reply, "", "Indicates that the new warble is a reply to the given id");
DEFINE_string(follow, "", "Starts following the given username");
DEFINE_string(read, "", "Reads the warble thread starting at the given id");
DEFINE_bool(profile, false, "Get the user's profile of following and followers");

// TODO: Prints error message
void PrintError(const std::string &errorMessage, const std::string &fields) {
  printf("%s %s", errorMessage.c_str(), fields.c_str());
}

// TODO: Registers the given non-blank username
void RegisterUser(std::string username) {
	
}

// TODO: Posts a new warble (optionally as a reply), returns the id of new warble
std::string Warble(const std::string &username, const std::string &text,
                   const std::string &warbleID = "") {
  return "";
}

// Starts following a given user
void Follow(std::string username, std::string userToFollow) {

}

// Reads a warble thread from the given id
void Read(std::string warbleID) {

}

// Returns this user's following and followers
void Profile() {

}

int main(int argc, char* argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, true);

  if (!FLAGS_registeruser.empty()) {
    RegisterUser(FLAGS_registeruser);
    return 0;
  }

  // if not user logged in, can not perform other functions
  if (!FLAGS_user.empty()) { 
    //TODO: Print error
    PrintError(MISSING_ARGUMENT_ERROR, "username");
    return 0;
  }
  
  if (FLAGS_warble != "") 
    Warble(FLAGS_user, FLAGS_warble); 
  if (FLAGS_reply != "") 
    Warble(FLAGS_user, FLAGS_warble, FLAGS_reply);
  if (FLAGS_follow != "") 
    Follow(FLAGS_user, FLAGS_follow);
  if (FLAGS_read != "") 
    Read(FLAGS_read);
  if (FLAGS_profile) 
    Profile();

  return 0;
}
