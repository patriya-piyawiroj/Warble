#include <stdlib.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>

#include "mock_service.h"

const std::string INVALID_FLAG_ERROR = "Invalid flag combinations. Missing ";
const std::string MISSING_ARGUMENT_ERROR = "Missing arguments for ";

DEFINE_string(registeruser, "", "Registers the given username");
DEFINE_string(user, "", "Logs in as the given username");
DEFINE_string(warble, "", "Creates a new warble with the given text");
DEFINE_string(reply, "", "Indicates that the new warble is a reply to the given id");
DEFINE_string(follow, "", "Starts following the given username");
DEFINE_string(read, "", "Reads the warble thread starting at the given id");
DEFINE_bool(profile, false, "Get the user's profile of following and followers");

class WarbleInterface {
 public:
  void PrintError(const std::string &errorMessage, const std::string &fields);
  void RegisterUser(std::string username);
  std::string Warble(const std::string &username, const std::string &text);
  std::string Reply(const std::string &username, const std::string &text,
                     const std::string &warbleID);
  void Follow(std::string username, std::string userToFollow);
  void Read(std::string warbleID);
  void Profile(std::string usernamer);
 
 private:
  MockServer warble_service;
};
