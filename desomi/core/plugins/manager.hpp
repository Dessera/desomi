#pragma once

#include <memory>
#include <vector>

#include "core/plugins/api/plugin.hpp"
namespace desomi::core::plugins {

class PluginManager final : public interfaces::Iplugin {
 public:
  PluginManager() = default;
  ~PluginManager() final = default;

  PluginManager(const PluginManager&) = delete;
  PluginManager& operator=(const PluginManager&) = delete;

  PluginManager(PluginManager&&) = delete;
  PluginManager& operator=(PluginManager&&) = delete;

 private:
  using plugin_ptr = std::unique_ptr<interfaces::Iplugin>;

  std::vector<plugin_ptr> plugins_{};

 public:
  inline PluginManager& add_plugin(plugin_ptr plugin) {
    plugins_.push_back(std::move(plugin));
    return *this;
  }

  void on_window_create() final;
  void on_window_destroy() final;
  void on_window_run() final;
  void on_frame_start() final;
  void on_frame_end() final;

  static inline std::unique_ptr<PluginManager> create() {
    return std::make_unique<PluginManager>();
  }
};

}  // namespace desomi::core::plugins
