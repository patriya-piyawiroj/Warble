//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//

#ifndef WARBLE_STORE_H_
#define WARBLE_STORE_H_

#include <unordered_map>
#include <string>
#include <optional>
#include <mutex>

// A map class, same as the one present in kvstore/store.h . warble/mock_service.h uses this
// class to store
class Kvmap {

 private:
  std::unordered_map<std::string, std::string> map_;
  std::mutex mu_;

 public:
  // map put (key, value)
  void put(std::string key, std::string value); 
  
  // map get key
  std::optional<std::string> get(std::string key); 

  // map remove key
  bool remove(std::string key); 
};
#endif // WARBLE_STORE_H_
