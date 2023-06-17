#pragma once

#include <functional>
#include <memory>
#include <vector>

namespace domi::core {

class Enode {
 public:
  using EnodePtr = std::unique_ptr<Enode>;
  using EnodeRawPtr = Enode*;
  using EnodeComponentCtor = std::function<EnodePtr()>;

  [[nodiscard]] EnodePtr clone() const;

 protected:
  std::vector<EnodePtr> children_{};
  EnodeRawPtr parent_{nullptr};

 public:
  Enode() = default;
  virtual ~Enode() = default;

  Enode(const Enode& other);
  Enode& operator=(const Enode& other);

  Enode(Enode&& other) noexcept
      : children_(std::move(other.children_)), parent_(other.parent_) {}
  Enode& operator=(Enode&& other) noexcept;

  [[nodiscard]] inline EnodeRawPtr parent() const { return parent_; }
  
  inline EnodeRawPtr parent(EnodeRawPtr parent) {
    parent_ = parent;
    return parent_;
  }


  [[nodiscard]] inline const std::vector<EnodePtr>& children() const {
    return children_;
  }

  inline Enode& insert(EnodePtr child) {
    child->parent(this);
    children_.push_back(std::move(child));
    return *this;
  }

  inline Enode& insert(const EnodeComponentCtor& ctor) {
    return insert(ctor());
  }
};

}  // namespace domi::core
