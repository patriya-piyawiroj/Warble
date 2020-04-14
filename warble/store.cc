//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//

#include "store.h"



void Kvmap::put(std::string key, std::string value) {
  std::unique_lock<std::mutex> lock(mu_);
  std::pair<std::string, std::string> pair(key, value);
  map_.insert(pair);
  return;
}

std::optional<std::string> Kvmap::get(std::string key) {
  std::unique_lock<std::mutex> lock(mu_);
   auto it = map_.find(key);
  if (it == map_.end()) {
    return std::nullopt;
  } else {
    return it->second;
  }
}

bool Kvmap::remove(std::string key) {
  std::unique_lock<std::mutex> lock(mu_);
  auto it = map_.find(key);
  if (it == map_.end()) {
    return false;
  } else {
    map_.erase(it);
    return true;
  }
}
