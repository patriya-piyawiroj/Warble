#include <unordered_map>
#include <string>

class Kvmap() {

 private:
  std::unordered_map map_;
  std::mutex mu_;

 public:
  void put(std::string key, std::string value) {}
  std::optional<string> get(std::string key) {}
  bool remove() {}
}
