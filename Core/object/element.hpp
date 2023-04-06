#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "resource/manager.hpp"
#include "utils/class_modify.hpp"

#define ELEMENT_DEFAULT_SIZE 0, 0, 100, 100
#define ELEMENT_DEFAULT_COLOR 255, 0, 0, 255

class WindowElement {
 public:
  DEFAULT_CLASS_METHOD(WindowElement);

  void render(SDL_Renderer *renderer, ResourceManager *resources);

 private:
  SDL_Rect rect_{ELEMENT_DEFAULT_SIZE};
  SDL_Color color_{ELEMENT_DEFAULT_COLOR};
  double angle_{0};

  int32_t speed_x_{0};
  int32_t speed_y_{0};
  double rotate_speed_{0};

  std::string texture_path_{};
  // std::vector<std::function<void(SDL_Event&)>> callback_list_{};
  std::vector<std::pair<std::size_t, std::function<void(SDL_Event &)>>>
      callback_list_{};

 public:
  inline void set_rect(const SDL_Rect &rect) { rect_ = rect; }
  inline void set_color(const SDL_Color &color) { color_ = color; }
  inline void set_angle(const double &angle) { angle_ = angle; }
  inline void set_speed_x(const int32_t &speed_x) { speed_x_ = speed_x; }
  inline void set_speed_y(const int32_t &speed_y) { speed_y_ = speed_y; }
  inline void set_rotate_speed(const double &rotate_speed) {
    rotate_speed_ = rotate_speed;
  }
  inline void set_texture_path(const std::string &texture_path) {
    texture_path_ = texture_path;
  }

  [[nodiscard]] inline SDL_Rect get_rect() const { return rect_; }
  [[nodiscard]] inline SDL_Color get_color() const { return color_; }
  [[nodiscard]] inline double get_angle() const { return angle_; }
  [[nodiscard]] inline int32_t get_speed_x() const { return speed_x_; }
  [[nodiscard]] inline int32_t get_speed_y() const { return speed_y_; }
  [[nodiscard]] inline double get_rotate_speed() const { return rotate_speed_; }
  [[nodiscard]] inline std::string get_texture_path() const {
    return texture_path_;
  }

  void on_click(SDL_Event& event);
};
