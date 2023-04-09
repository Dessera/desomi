#pragma once

#include <SDL2/SDL_rect.h>

#include <cstdint>
namespace desomi::core::utils {

class rect {
 public:
  rect() = default;
  rect(int32_t x, int32_t y, int32_t width, int32_t height, int32_t speed_x,
       int32_t speed_y,double angle , double rotation_speed);

  [[nodiscard]] inline SDL_Rect sdl_rect() const { return SDL_Rect{x_, y_, width_, height_}; }

  [[nodiscard]] inline int32_t x() const { return x_; }
  [[nodiscard]] inline int32_t y() const { return y_; }
  [[nodiscard]] inline int32_t width() const { return width_; }
  [[nodiscard]] inline int32_t height() const { return height_; }
  [[nodiscard]] inline int32_t speed_x() const { return speed_x_; }
  [[nodiscard]] inline int32_t speed_y() const { return speed_y_; }
  [[nodiscard]] inline double angle() const { return angle_; }
  [[nodiscard]] inline double rotation_speed() const { return rotation_speed_; }

  void move();

  constexpr static int32_t DEFAULT_X = 0;
  constexpr static int32_t DEFAULT_Y = 0;
  constexpr static int32_t DEFAULT_WIDTH = 100;
  constexpr static int32_t DEFAULT_HEIGHT = 100;

  constexpr static int32_t DEFAULT_SPEED_X = 0;
  constexpr static int32_t DEFAULT_SPEED_Y = 0;
  constexpr static double DEFAULT_ANGLE = 0.0;
  constexpr static double DEFAULT_ROTATION_SPEED = 0.0;

 private:
  int32_t x_{DEFAULT_X};
  int32_t y_{DEFAULT_Y};
  int32_t width_{DEFAULT_WIDTH};
  int32_t height_{DEFAULT_HEIGHT};

  int32_t speed_x_{DEFAULT_SPEED_X};
  int32_t speed_y_{DEFAULT_SPEED_Y};
  double angle_{DEFAULT_ANGLE};
  double rotation_speed_{DEFAULT_ROTATION_SPEED};
};

}  // namespace desomi::core::utils