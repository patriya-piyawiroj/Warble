//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
//  This executable should be run on startup. It hooks Warble functions to func.

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "func_client.h"

int main(int argc, char** argv) {
  FuncClient client(grpc::CreateChannel("localhost:50000", grpc::InsecureChannelCredentials()));
  client.Hook(1, "register");
  client.Hook(2, "create");
  client.Hook(3, "follow");
  client.Hook(4, "read");
  client.Hook(5, "profile");
}

