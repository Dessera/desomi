#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "core/renderer/interfaces/render_api.hpp"

namespace desomi::core::interfaces {

class Inode : public std::enable_shared_from_this<Inode> {
 public:
  using node_ptr = std::shared_ptr<Inode>;
  using node_weak_ptr = std::weak_ptr<Inode>;
  using node_init_func = std::function<node_ptr()>;

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
  /**
   * @brief Insert a child to the node.
   *
   * @param child Raw pointer to the child.
   * @return node_ptr Pointer to current node for chaining.
   */
  inline node_ptr add_child(Inode* child) {
    children_.push_back(child->shared_from_this());
    child->set_parent(this);
    return this->shared_from_this();
  }

  /**
   * @brief Insert a child to the node.
   *
   * @param child Shared pointer to the child.
   * @return node_ptr Pointer to current node for chaining.
   */
  inline node_ptr add_child(const node_ptr& child) {
    children_.push_back(child);
    child->set_parent(this);
    return this->shared_from_this();
  }

  /**
   * @brief Insert a Node Tree to the node.
   *
   * @param scope Function that returns a node_ptr.
   * @return node_ptr Pointer to current node for chaining.
   */
  inline node_ptr add_scope(const node_init_func& scope) {
    auto child = scope();
    children_.push_back(child);
    child->set_parent(this);
    return this->shared_from_this();
  }

  /**
   * @brief Return to the parent node.
   *
   * @return node_ptr Pointer to the parent node.
   */
  inline node_ptr end() { return parent_.lock(); }

  // TODO: add a way to remove a child
  inline std::vector<node_ptr>& children() { return children_; };
  inline node_weak_ptr parent() { return parent_; };

  // TODO: Think another way to do this.
  node_ptr root() {
    // auto parent = parent_.lock();
    // if (parent == nullptr) {
    //   return shared_from_this();
    // }
    // return parent->root();

    // implement a loop instead of recursion
    auto parent = parent_.lock();
    auto current = shared_from_this();
    while (parent != nullptr) {
      current = parent;
      parent = parent->parent_.lock();
    }
    return current;
  }

  template <typename T>
  inline static node_ptr create(auto... args) {
    return std::make_shared<T>(args...);
  }
};

}  // namespace desomi::core::interfaces
