#include kvmap.h

void Kvmap::put(std::string key, std::string value) {
  std::pair<std::string, std::string> pair(key, value);
  map_.insert(pair);
  return;
}

std::optional<string> Kvmap::get(std::string key) {
  auto it = map_.find(key);
  if (it == map_end()) {
    return std::nullopt;
  } else {
    return it->second;
  }
}

bool Kvmap::remove() {
  auto it = map_.find(request->key());
  if (it == map_end()) {
    return false;
  else {
    map_.erase(it);
    return true;
  }
}
