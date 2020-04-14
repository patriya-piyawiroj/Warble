//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//

#ifndef WARBLE_CLIENT_H_
#define WARBLE_CLIENT_H_

#include <stdlib.h>
#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "mock_service.h"

DEFINE_string(registeruser, "", "Registers the given username");
DEFINE_string(user, "", "Logs in as the given username");
DEFINE_string(warble, "", "Creates a new warble with the given text");
DEFINE_string(reply, "", "Indicates that the new warble is a reply to the given id");
DEFINE_string(follow, "", "Starts following the given username");
DEFINE_string(read, "", "Reads the warble thread starting at the given id");
DEFINE_string(store, "", "Stores to the given file name");
DEFINE_bool(profile, false, "Get the user's profile of following and followers");

// An interface set to handle user inputs and parse them into a format that can be sent 
// across grpc to perform warble functions 
class WarbleInterface {
 public:
  static const std::string INVALID_FLAG_ERROR;                                                                            static const std::string MISSING_ARGUMENT_ERROR;
  
  // A format for printing an error message and relevant fields
  void PrintError(const std::string &errorMessage, const std::string &fields);
  
  // Calls warble function RegisterUser to registers user to store
  void RegisterUser(std::string username);

  // Calls warble function to creates a new warble to store
  std::string Warble(const std::string &username, const std::string &text);

  // Calls warble function to creates a new warble as reply to store
  std::string Reply(const std::string &username, const std::string &text,
                     const std::string &warbleID);

  // Calls warble function Follow for a user and given user to follow
  void Follow(std::string username, std::string userToFollow);

  // Calls warble function Read to read a given warble
  void Read(std::string warbleID);

  // Calls warble function Profile to read the profile of a username
  void Profile(std::string username);
 
 private:
  MockServer warble_service;                                                            
};
#endif // WARBLE_CLIENT_H_
