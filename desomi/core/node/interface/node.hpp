#pragma once

#include <memory>
#include <vector>

#include "core/renderer/interfaces/render_api.hpp"

namespace desomi::core::interfaces {

class Inode : public std::enable_shared_from_this<Inode> {
 public:
  using node_ptr = std::shared_ptr<Inode>;
  using node_weak_ptr = std::weak_ptr<Inode>;

 protected:
  std::vector<node_ptr> children_;
  node_weak_ptr parent_;

 public:
  virtual ~Inode() = default;
  virtual void render(IrendererAPI* renderer) = 0;

  inline void set_parent(Inode* parent) {
    if (parent == nullptr) {
      return;
    }
    parent_ = parent->weak_from_this();
  }

  // Seems that these methods don't need to be virtual.
  inline node_ptr add_child(Inode* child) {
    children_.push_back(child->shared_from_this());
    child->set_parent(this);
    return this->shared_from_this();
  }
  inline node_ptr add_child(const node_ptr& child) {
    children_.push_back(child);
    child->set_parent(this);
    return this->shared_from_this();
  }
  inline node_ptr add_scope(Inode* child) {
    children_.push_back(child->shared_from_this());
    child->set_parent(this);
    return child->shared_from_this();
  }
  inline node_ptr add_scope(const node_ptr& child) {
    children_.push_back(child);
    child->set_parent(this);
    return child->shared_from_this();
  }
  inline node_ptr end() { return parent_.lock(); }

  // TODO: add a way to remove a child
  inline virtual std::vector<node_ptr>& children() { return children_; };
  inline virtual node_weak_ptr parent() { return parent_; };

  // TODO: Think another way to do this.
  node_ptr root() {
    auto parent = parent_.lock();
    if (parent == nullptr) {
      return shared_from_this();
    }
    return parent->root();
  }

  template <typename T>
  inline static node_ptr create(auto... args) {
    return std::make_shared<T>(args...);
  }
};

}  // namespace desomi::core::interfaces
