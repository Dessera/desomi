#pragma once

#include <SDL2/SDL_pixels.h>

#include <cstdint>
namespace desomi::core::utils {

class Color {
 public:
  enum class color_mask : uint32_t {
    red = 0xFF000000,
    green = 0x00FF0000,
    blue = 0x0000FF00,
    alpha = 0x000000FF,
  };
  enum class color_shift : uint8_t {
    red = 24,
    green = 16,
    blue = 8,
  };

  Color() = default;
  explicit Color(uint32_t color);
  explicit Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

  [[nodiscard]]

  inline SDL_Color sdl_color() {
    return SDL_Color{red_, green_, blue_, alpha_};
  }

  [[nodiscard]] inline uint8_t red() const { return red_; }
  [[nodiscard]] inline uint8_t green() const { return green_; }
  [[nodiscard]] inline uint8_t blue() const { return blue_; }
  [[nodiscard]] inline uint8_t alpha() const { return alpha_; }

 private:
  uint8_t red_{0};
  uint8_t green_{0};
  uint8_t blue_{0};
  uint8_t alpha_{0xFF};

 public:
  static constexpr uint32_t WHITE = 0xFFFFFFFF;
  static constexpr uint32_t BLACK = 0x000000FF;
  static constexpr uint32_t RED = 0xFF0000FF;
  static constexpr uint32_t GREEN = 0x00FF00FF;
  static constexpr uint32_t BLUE = 0x0000FFFF;
  static constexpr uint32_t YELLOW = 0xFFFF00FF;
  static constexpr uint32_t MAGENTA = 0xFF00FFFF;
  static constexpr uint32_t CYAN = 0x00FFFFFF;
};

}  // namespace desomi::core::utils