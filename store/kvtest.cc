//
//  Pearl Piyawiroj
//  @patriya-piyawiroj
//
// This class can be used to manually test client
// Example: 
//     ./kvtest -key {key} -value {value}
//     Replace {} with desired parameters
// This will store key and value to server and will store to a file if -store is given to server
//

#include <optional>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "kvstore_client.h"

DEFINE_string(key, "", "Stores key to kvstore");
DEFINE_string(value, "", "Stores value to kvstore");

int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

  if (!FLAGS_key.empty() & !FLAGS_value.empty()) {
    std::string key(FLAGS_key);
    std::string value(FLAGS_value);
    LOG(INFO) << "Put (" << key << ", " << value << ")";
    client.Put(key, value);
  } 
}
