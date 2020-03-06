#include <string>
#include <optional>

#include <grpcpp/grpcpp.h>

#include "kvstore_client.h"

class WarbleService {
 public:
  WarbleService();
  bool CheckWarble(std::string warbleID);
  void RegisterUser(std::string username);
  std::string CreateWarble(std::string username, std::string text, std::optional<string> warbleID);
  void Follow(std::string username, std::string userToFollow);
  void Read(std::string warbleID);
  std::string* Profile(std::string username);
 private:
  KvstoreClient kvstore_;
