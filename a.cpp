#include <stdlib.h>
#include <gflags/gflags.h>
#include <iostream>

DEFINE_string(registeruser, "", "Registers the given username");
DEFINE_string(user, "", "Logs in as the given username");
DEFINE_string(warble, "", "Creates a new warble with the given text");
DEFINE_string(reply, "", "Indicates that the new warble is a reply to the given id");
DEFINE_string(follow, "", "Starts following the given username");
DEFINE_string(read, "", "Reads the warble thread starting at the given id");
DEFINE_bool(profile, false, "Get the user's profile of following and followers");

// Success message

// Error message

// Registers the given non-blank username
void RegisterUser(std::string username) {
	std::cout << username;
}

// Posts a new warble (optionally as a reply), returns the id of new warble
std::string Warble(std::string username, std::string text, std::string warbleID="") {
	
}

// Starts following a given user
void Follow(std::string username, std::string userToFollow) {

}

// Reads a warble thread from the given id
void Read(std::string warbleID) {

}

// Returns this user's following and followers
void profile() {

}

}

int main(int argc, char* argv[]) {
	google::ParseCommandLineFlags(&argc, &argv, true);
	if (FLAGS_registeruser != "") {
		RegisterUser(FLAGS_registeruser);
	}
	return 0;
}
