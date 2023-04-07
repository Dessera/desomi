#include "core/node/node.hpp"

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <algorithm>
#include <memory>

#include "core/window/window.hpp"

using desomi::core::node;
using node_color = desomi::core::utils::color;
using node_rect = desomi::core::utils::rect;

node::node(node_rect rect, node_color color) : rect_{rect}, color_{color} {}
node::node(node_rect rect) : rect_{rect} {}

node::node(const node& other) : rect_{other.rect_}, color_{other.color_} {}
node::node(node&& other) noexcept : rect_(other.rect_), color_(other.color_) {}
node& node::operator=(const node& other) {
  if (this == &other) {
    return *this;
  }
  rect_ = other.rect_;
  color_ = other.color_;
  return *this;
}
node& node::operator=(node&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  rect_ = other.rect_;
  color_ = other.color_;
  return *this;
}

node& node::add_child(const node_ptr& child) {
  child->set_parent(weak_from_this());
  children_.push_back(child);
  return *this;
}
node& node::add_child_and_deepen(const node_ptr& child) {
  child->set_parent(weak_from_this());
  children_.push_back(child);
  return *child;
}
node& node::end() {
  if (auto parent = parent_.lock()) {
    return *parent;
  }
  return *this;
}
node& node::remove_child(const node_ptr& child) {
  children_.erase(std::remove(children_.begin(), children_.end(), child),
                  children_.end());
  return *this;
}

node::node_ptr node::return_to_root() {
  if (auto parent = parent_.lock()) {
    return parent->return_to_root();
  }
  return shared_from_this();
}

/**
 * @brief Render the node
 *
 * @param renderer Raw SDL_Renderer pointer
 *  TODO: change logic of delivery for renderer
 *  TODO: Although node_rect defines angle and rotation_speed, they are not used
 * because only texture can be rotated
 */
void node::render(SDL_Renderer* renderer) {
  // movement
  rect_.move();

  // render
  auto rect = rect_.sdl_rect();
  SDL_SetRenderDrawColor(renderer, color_.red(), color_.green(), color_.blue(),
                         color_.alpha());
  SDL_RenderFillRect(renderer, &rect);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

// TODO: width and height should be no-static, but not it is defined bu default
// value
node::node_ptr node::create_root(int32_t width, int32_t height) {
  using color = core::utils::color;
  using rect = core::utils::rect;
  return std::make_shared<node>(rect(0, 0, width, height, 0, 0, 0, 0),
                                color(color::WHITE));
}

node::node_ptr node::create_node(int32_t posx, int32_t posy, int32_t width,
                                 int32_t height, uint32_t color) {
  return std::make_shared<node>(
      core::utils::rect(posx, posy, width, height, 0, 0, 0, 0),
      core::utils::color(color));
}
