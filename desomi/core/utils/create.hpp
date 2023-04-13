#pragma once

#include <memory>
namespace desomi::core::utils {

template <typename TYPE>
class UseUniqueCreate {
 public:
  inline static std::unique_ptr<TYPE> create(auto... args) {
    return std::make_unique<TYPE>(args...);
  }
};

template <typename TYPE>
class UseSharedCreate {
 public:
  inline static std::shared_ptr<TYPE> create(auto... args) {
    return std::make_shared<TYPE>(args...);
  }
};

template <typename TYPE>
class UseSingletonCreate {
 public:
  inline static TYPE* create(auto... args) {
    static TYPE* instance = new TYPE(args...);
    return instance;
  }
};

}  // namespace desomi::core::utils
