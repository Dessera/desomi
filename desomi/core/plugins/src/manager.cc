#include "core/plugins/templates/manager.hpp"

namespace desomi::core::plugins {

void PluginManager::on_window_create(interfaces::Inode::node_ptr& root) {
  for (auto& plugin : plugins_) {
    plugin->on_window_create(root);
  }
}

void PluginManager::on_window_destroy(interfaces::Inode::node_ptr& root) {
  for (auto& plugin : plugins_) {
    plugin->on_window_destroy(root);
  }
}

void PluginManager::on_window_run(interfaces::Inode::node_ptr& root) {
  for (auto& plugin : plugins_) {
    plugin->on_window_run(root);
  }
}

void PluginManager::on_frame_start(interfaces::Inode::node_ptr& root) {
  for (auto& plugin : plugins_) {
    plugin->on_frame_start(root);
  }
}

void PluginManager::on_frame_end(interfaces::Inode::node_ptr& root) {
  for (auto& plugin : plugins_) {
    plugin->on_frame_end(root);
  }
}

}  // namespace desomi::core::plugins
