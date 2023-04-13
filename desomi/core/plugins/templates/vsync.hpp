#pragma once

#include "SDL2/SDL_timer.h"
#include "core/plugins/api/plugin.hpp"

namespace desomi::core::plugins {

class VeriticalVsyncController final : public interfaces::Iplugin {
 public:
  VeriticalVsyncController() = default;
  explicit VeriticalVsyncController(uint32_t fps) : fps_(fps) {}
  ~VeriticalVsyncController() final = default;

  VeriticalVsyncController(const VeriticalVsyncController&) = delete;
  VeriticalVsyncController& operator=(const VeriticalVsyncController&) = delete;

  VeriticalVsyncController(VeriticalVsyncController&&) = delete;
  VeriticalVsyncController& operator=(VeriticalVsyncController&&) = delete;

  void on_window_run() final;
  void on_frame_end() final;

  void on_window_create() final {}
  void on_window_destroy() final {}
  void on_frame_start() final {}

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
