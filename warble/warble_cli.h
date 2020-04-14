//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//

#ifndef WARBLE_CLIENT_H_
#define WARBLE_CLIENT_H_

#include <stdlib.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>

#include "mock_service.h"

DEFINE_string(registeruser, "", "Registers the given username");
DEFINE_string(user, "", "Logs in as the given username");
DEFINE_string(warble, "", "Creates a new warble with the given text");
DEFINE_string(reply, "", "Indicates that the new warble is a reply to the given id");
DEFINE_string(follow, "", "Starts following the given username");
DEFINE_string(read, "", "Reads the warble thread starting at the given id");
DEFINE_string(store, "", "Stores to the given file name");
DEFINE_bool(profile, false, "Get the user's profile of following and followers");

class WarbleInterface {
 public:
  static const std::string INVALID_FLAG_ERROR;                                                                            static const std::string MISSING_ARGUMENT_ERROR;
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
#endif // WARBLE_CLIENT_H_
