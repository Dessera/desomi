#pragma once

#include <memory>
#include <vector>

#include "core/plugins/interfaces/plugin.hpp"
#include "core/utils/create.hpp"
namespace desomi::core::plugins {

class PluginManager final : public interfaces::Iplugin,
                            public utils::UseSharedCreate<PluginManager>,
                            public std::enable_shared_from_this<PluginManager> {
 public:
  
  
  PluginManager() = default;
  ~PluginManager() final = default;

  PluginManager(const PluginManager&) = delete;
  PluginManager& operator=(const PluginManager&) = delete;

  PluginManager(PluginManager&&) = delete;
  PluginManager& operator=(PluginManager&&) = delete;

 private:
  std::vector<plugin_ptr> plugins_{};

 public:
  //  TODO: A temp solution for plugin manager
  inline plugin_ptr add_plugin(plugin_ptr plugin) {
    plugins_.push_back(std::move(plugin));
    return shared_from_this();
  }

  void on_window_create(interfaces::Inode::node_ptr& root) final;
  void on_window_destroy(interfaces::Inode::node_ptr& root) final;
  void on_window_run(interfaces::Inode::node_ptr& root) final;
  void on_frame_start(interfaces::Inode::node_ptr& root) final;
  void on_frame_end(interfaces::Inode::node_ptr& root) final;
};

}  // namespace desomi::core::plugins
