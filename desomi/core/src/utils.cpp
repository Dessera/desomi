#include <SDL2/SDL_pixels.h>

#include <cstdint>

#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"

using desomi::core::utils::color;
using desomi::core::utils::rect;

color::color(uint32_t color)
    : red_((color & static_cast<uint32_t>(color_mask::red)) >>
           static_cast<uint8_t>(color_shift::red)),
      green_((color & static_cast<uint32_t>(color_mask::green)) >>
             static_cast<uint8_t>(color_shift::green)),
      blue_((color & static_cast<uint32_t>(color_mask::blue)) >>
            static_cast<uint8_t>(color_shift::blue)),
      alpha_(color & static_cast<uint32_t>(color_mask::alpha)) {}
color::color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : red_(red), green_(green), blue_(blue), alpha_(alpha) {}

rect::rect(int32_t x, int32_t y, int32_t width, int32_t height, int32_t speed_x,
           int32_t speed_y, double angle, double rotation_speed)
    : x_(x),
      y_(y),
      width_(width),
      height_(height),
      speed_x_(speed_x),
      speed_y_(speed_y),
      angle_(angle),
      rotation_speed_(rotation_speed) {}

void rect::move() {
  x_ += speed_x_;
  y_ += speed_y_;
  angle_ += rotation_speed_;
  if (angle_ > 360.0) {
    angle_ -= 360.0;
  }
}
