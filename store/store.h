#include <unordered_map>
#include <string>
#include <optional>
#include <mutex>

#include <glog/logging.h>

// The map class used to store kvstore data. Used by kvstore/kvstore_client.h
class Kvmap {

 private:
  std::unordered_map<std::string, std::string> map_;
  std::mutex mu_;

 public:
  // Map put key and value
  void put(std::string key, std::string value); 

  // Map get key
  std::optional<std::string> get(std::string key); 

  // Map remove key
  bool remove(std::string key); 
};
