#pragma once

#include "core/node/interface/node.hpp"

namespace desomi::core::interfaces {

class Iplugin {
 public:
  virtual ~Iplugin() = default;

  virtual void on_window_create(interfaces::Inode::node_ptr& root) = 0;
  virtual void on_window_destroy(interfaces::Inode::node_ptr& root) = 0;
  virtual void on_window_run(interfaces::Inode::node_ptr& root) = 0;
  virtual void on_frame_start(interfaces::Inode::node_ptr& root) = 0;
  virtual void on_frame_end(interfaces::Inode::node_ptr& root) = 0;
};

}  // namespace desomi::core::interfaces
