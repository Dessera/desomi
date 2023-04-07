#pragma once

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"

namespace desomi::core {
class node : public std::enable_shared_from_this<node> {
 public:
  using node_ptr = std::shared_ptr<node>;
  using node_weak_ptr = std::weak_ptr<node>;

  static node_ptr create_root(int32_t width, int32_t height);
  static node_ptr create_node(int32_t posx, int32_t posy, int32_t width,
                              int32_t height, uint32_t color);

 private:
  using node_color = core::utils::color;
  using node_rect = core::utils::rect;

  node_weak_ptr parent_{};
  std::vector<node_ptr> children_{};
  node_rect rect_{};
  node_color color_{node_color::RED};

 public:
  node() = default;
  node(node_rect rect, core::utils::color color);
  explicit node(node_rect rect);
  virtual ~node() = default;

  node(const node&);
  node(node&&) noexcept;
  node& operator=(const node&);
  node& operator=(node&&) noexcept;

  [[nodiscard]] inline std::vector<node_ptr> children() const {
    return children_;
  }
  [[nodiscard]] inline node_weak_ptr parent() const { return parent_; }

  [[nodiscard]] inline SDL_Rect rect() { return rect_.sdl_rect(); }
  [[nodiscard]] inline node_color color() const { return color_; }

  [[nodiscard]] inline int x() const { return rect_.x(); }
  [[nodiscard]] inline int y() const { return rect_.y(); }
  [[nodiscard]] inline int width() const { return rect_.width(); }
  [[nodiscard]] inline int height() const { return rect_.height(); }

  [[nodiscard]] inline int r() const { return color_.red(); }
  [[nodiscard]] inline int g() const { return color_.green(); }
  [[nodiscard]] inline int b() const { return color_.blue(); }
  [[nodiscard]] inline int a() const { return color_.alpha(); }

  [[nodiscard]] inline int speed_x() const { return rect_.speed_x(); }
  [[nodiscard]] inline int speed_y() const { return rect_.speed_y(); }
  [[nodiscard]] inline double angle() const { return rect_.angle(); }
  [[nodiscard]] inline double speed_angle() const {
    return rect_.rotation_speed();
  }

  inline void set_parent(node_weak_ptr parent) { parent_ = std::move(parent); }

  virtual void render(SDL_Renderer* renderer);

  node& add_child(const node_ptr& child);
  node& add_child_and_deepen(const node_ptr& child);
  node& end();
  node_ptr return_to_root();
  node& remove_child(const node_ptr& child);
};
}  // namespace desomi::core
