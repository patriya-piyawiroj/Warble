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

class Kvmap {

 private:
  std::unordered_map<std::string, std::string> map_;
  std::mutex mu_;

 public:
  void put(std::string key, std::string value); 
  std::optional<std::string> get(std::string key); 
  bool remove(std::string key); 
};
#endif // WARBLE_STORE_H_
