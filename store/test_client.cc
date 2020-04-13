#include "kvstore_client.h"

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  KvstoreClient client(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));
  std::string key("test-key");
  std::string value("test-value");
  LOG(INFO) << "Attempting put";
  std::cout << "cout put";
  client.Put(key,value);
}
