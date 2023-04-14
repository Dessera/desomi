#pragma once

#include <iostream>

#include "SDL2/SDL_timer.h"
#include "core/plugins/interfaces/plugin.hpp"
#include "core/utils/create.hpp"

namespace desomi::core::plugins {

class VsyncController final
    : public interfaces::Iplugin,
      public utils::UseSharedCreate<VsyncController> {
 public:
  VsyncController() = default;
  explicit VsyncController(uint32_t fps) : fps_(fps) {}
  ~VsyncController() final = default;

  VsyncController(const VsyncController&) = delete;
  VsyncController& operator=(const VsyncController&) = delete;

  VsyncController(VsyncController&&) = delete;
  VsyncController& operator=(VsyncController&&) = delete;

  void on_window_run(interfaces::Inode::node_ptr& /*root*/) final { enable(); }
  void on_frame_end(interfaces::Inode::node_ptr&  /*root*/) final { wait(); }

  void on_window_create(interfaces::Inode::node_ptr& root) final {}
  void on_window_destroy(interfaces::Inode::node_ptr& root) final {}
  void on_frame_start(interfaces::Inode::node_ptr& root) final {}

  inline void enable() {
    enabled_ = true;
    last_tick_ = SDL_GetTicks();
  }
  inline void disable() { enabled_ = false; }
  inline void toggle() { enabled_ = !enabled_; }
  inline void set_fps(uint32_t fps) { fps_ = fps; }

  void wait() {
    if (!enabled_) {
      return;
    }
    uint32_t cost = SDL_GetTicks() - last_tick_;
    uint32_t frame_expected_ = 1000 / fps_;
    if (cost < frame_expected_) {
      SDL_Delay(frame_expected_ - cost);
    }
    last_tick_ = SDL_GetTicks();
  }

 private:
  bool enabled_{false};
  uint32_t last_tick_{SDL_GetTicks()};
  uint32_t fps_{60};
};

}  // namespace desomi::core::plugins
