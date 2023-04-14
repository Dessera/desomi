#pragma once

#include <cstdint>
#include <vector>

#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"

namespace desomi::core::interfaces {

class IrendererAPI {
 private:
  using Rect = core::utils::Rect;
  using Color = core::utils::Color;

 public:
  virtual ~IrendererAPI() = default;
  virtual void clear() = 0;
  virtual void present() = 0;
  virtual void flush() = 0;

  // driver info
  virtual uint32_t get_driver_count() = 0;
  // TODO: implement a function returns driver info
  // TODO: implement a function returns renderer info
  // TODO: implement texture behavior
  // TODO: implement render logic scale behavior
  // TODO: implement render scale behavior
  // TODO: implement render viewport behavior
  // TODO: implement render clip behavior

  virtual void set_draw_color(const Color& color_) = 0;
  virtual void default_draw_color() = 0;
  virtual Color get_draw_color() = 0;

  // TODO: implement render draw blend mode behavior

  // TODO: convert into a point class
  virtual void draw_point(int x_, int y_) = 0;
  // TODO: implement draw points behavior

  // TODO: Convert into a line class
  virtual void draw_line(int x1_, int y1_, int x2_, int y2_) = 0;
  // TODO: implement draw lines behavior

  virtual void draw_rect(const Rect& rect_) = 0;
  virtual void draw_rects(const std::vector<Rect>& rects_) = 0;

  virtual void fill_rect(const Rect& rect_) = 0;
  virtual void fill_rects(const std::vector<Rect>& rects_) = 0;

  // TODO: implement render copy behavior (need a texture class)
  // TODO: implement render copy ex behavior (need a texture class)
  // TODO: implement render triangle behavior
};

}  // namespace desomi::core::interfaces
