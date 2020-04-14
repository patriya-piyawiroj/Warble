#include <optional>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "kvstore_client.h"

DEFINE_string(store, "", "Stores to the given file name");
DEFINE_string(key, "", "Stores key to kvstore");
DEFINE_string(value, "", "Stores value to kvstore");

int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

  if (FLAGS_store.empty()) {
    std::string key(FLAGS_key);
    std::string value(FLAGS_value);
    LOG(INFO) << "Put (" << key << ", " << value << ")";
    client.Put(key, value, std::nullopt);
  } else {
    std::string key(FLAGS_key);                                                                                             std::string value(FLAGS_value);                                                                                         std::string filename(FLAGS_store);
    LOG(INFO) << "Put (" << key << ", " << value << ") file: " << filename;
    client.Put(key, value, filename);
  }
}
