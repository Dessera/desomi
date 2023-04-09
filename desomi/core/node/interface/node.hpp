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

  inline virtual void set_parent(Inode* parent) {
    if (parent == nullptr) {
      return;
    }
    parent_ = parent->weak_from_this();
  }

  inline Inode& add_child(Inode* child) {
    children_.push_back(child->shared_from_this());
    child->set_parent(this);
    return *this;
  }
  inline Inode& add_scope(Inode* child) {
    children_.push_back(child->shared_from_this());
    child->set_parent(this);
    return *child;
  }
  inline Inode& end() { return *parent_.lock(); }
  // TODO: add a way to remove a child
  inline virtual std::vector<node_ptr>& children() { return children_; };
  inline virtual node_weak_ptr parent() { return parent_; };
};

}  // namespace desomi::core::interfaces
