// Unit tests for kvstore functions

#include <gtest/gtest.h>
#include <grpc/grpc.h>

#include "kvstore_client.h"

TEST(GetTest, GetValueFromPut) {
  KvstoreClient kvstore(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));
  std::string key("key");
  std::string value("value");
  kvstore.Put(key, value);
  std::optional<std::string> replyValue  = kvstore.Get(key);
  EXPECT_EQ(value, replyValue.value());
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
