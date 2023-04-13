#pragma once

namespace desomi::core::interfaces {

class Iplugin {
 public:
  virtual ~Iplugin() = default;

  virtual void on_window_create() = 0;
  virtual void on_window_destroy() = 0;
  virtual void on_window_run() = 0;
  virtual void on_frame_start() = 0;
  virtual void on_frame_end() = 0;
};

}  // namespace desomi::core::interfaces
