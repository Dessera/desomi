#include "core/plugins/manager.hpp"

using desomi::core::plugins::PluginManager;

void PluginManager::on_window_create() {
  for (auto& plugin : plugins_) {
    plugin->on_window_create();
  }
}

void PluginManager::on_window_destroy() {
  for (auto& plugin : plugins_) {
    plugin->on_window_destroy();
  }
}

void PluginManager::on_window_run() {
  for (auto& plugin : plugins_) {
    plugin->on_window_run();
  }
}

void PluginManager::on_frame_start() {
  for (auto& plugin : plugins_) {
    plugin->on_frame_start();
  }
}

void PluginManager::on_frame_end() {
  for (auto& plugin : plugins_) {
    plugin->on_frame_end();
  }
}
