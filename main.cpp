#include <iostream>
#include <memory>

#include "core/node/templates/root.hpp"
#include "core/utils/rect.hpp"
#include "core/window/window.hpp"

int main() {
  using desomi::core::node::Root;
  using desomi::core::utils::color;
  using desomi::core::utils::rect;

  desomi::core::window win{
      [](const desomi::core::window::window_config& config) {
        rect viewport{0, 0, config.w, config.h, 0, 0, 0, 0};
        return desomi::core::interfaces::Inode::node_ptr{new Root(viewport)};
      }};

  return win.run();
}
