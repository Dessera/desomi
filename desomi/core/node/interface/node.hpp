#pragma once

/**
 * @file node.hpp
 * @author Dessera (1533653159@qq.com)
 * @brief Inode base class (or interface but not really).
 * @version 0.1
 * @date 2023-04-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <functional>
#include <memory>
#include <vector>

#include "core/renderer/interfaces/render_api.hpp"

namespace desomi::core::interfaces {

/**
 * @brief Base class for all nodes.
 *        To create a custom node, derive from this class and implement the
 * render method.
 */
class Inode : public std::enable_shared_from_this<Inode> {
 public:
  using node_ptr = std::shared_ptr<Inode>;
  using node_weak_ptr = std::weak_ptr<Inode>;
  using node_init_func = std::function<node_ptr()>;

 protected:
  /**
   * @brief Children of the node.
   *
   */
  std::vector<node_ptr> children_;

  /**
   * @brief Parent of the node.
   *
   */
  node_weak_ptr parent_;

 private:
  /**
   * @brief An implementation of add_child.
   *
   * @param child shared pointer to the child.
   * @return node_ptr self pointer for chaining.
   */
  inline node_ptr add_child_impl_(const node_ptr& child) {
    children_.push_back(child->shared_from_this());
    child->set_parent(this);
    return this->shared_from_this();
  }

 public:
  virtual ~Inode() = default;

  /**
   * @brief Render the node, Only render the node itself, not the children.
   *
   * @param renderer Renderer API derived from IrendererAPI.
   */
  virtual void render(IrendererAPI* renderer) = 0;

  /**
   * @brief Set the parent object, always use inside add_child.
   *
   * @param parent Parent node.
   */
  inline void set_parent(Inode* parent) {
    if (parent == nullptr) {
      return;
    }
    parent_ = parent->weak_from_this();
  }

  /**
   * @brief Insert a child to the node.
   *
   * @param child Raw pointer to the child.
   * @return node_ptr Pointer to current node for chaining.
   */
  inline node_ptr add_child(Inode* child) {
    return add_child_impl_(child->shared_from_this());
  }

  /**
   * @brief Insert a child to the node.
   *
   * @param child Shared pointer to the child.
   * @return node_ptr Pointer to current node for chaining.
   */
  inline node_ptr add_child(const node_ptr& child) {
    return add_child_impl_(child);
  }

  /**
   * @brief Insert a Node Tree to the node.
   *
   * @param scope Function that returns a node_ptr.
   * @return node_ptr Pointer to current node for chaining.
   */
  inline node_ptr add_scope(const node_init_func& scope) {
    auto child = scope();
    return add_child_impl_(child);
  }

  /**
   * @brief Remove a child from the node.
   *
   * @param child Target child.
   * @return node_ptr self pointer for chaining.
   */
  inline node_ptr remove_child(const node_ptr& child) {
    auto it = std::find(children_.begin(), children_.end(), child);
    if (it != children_.end()) {
      children_.erase(it);
    }
    return this->shared_from_this();
  }

  /**
   * @brief Return to the parent node.
   *
   * @return node_ptr Pointer to the parent node.
   */
  inline node_ptr end() { return parent_.lock(); }

  inline std::vector<node_ptr>& children() { return children_; };
  inline node_weak_ptr parent() { return parent_; };

  /**
   * @brief Return to the root node.
   *
   * @return node_ptr Root node.
   * @note This method was originally implemented by recursion, but now it is a
   *       cycle.
   */
  node_ptr root() {
    auto parent = parent_.lock();
    auto current = shared_from_this();
    while (parent != nullptr) {
      current = parent;
      parent = parent->parent_.lock();
    }
    return current;
  }
};

}  // namespace desomi::core::interfaces
