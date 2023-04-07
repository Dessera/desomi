#include <iostream>
#include <memory>

#include "core/node/node.hpp"
#include "core/window/window.hpp"

int main() {
  using desomi::core::node;
  using desomi::core::utils::color;

  desomi::core::window win{
      [](const desomi::core::window::window_config& config) {
        return node::create_root(config.w, config.h)
            ->add_child(node::create_node(0, 0, 50, 50, color::RED))
            .add_child(node::create_node(50, 50, 50, 50, color::GREEN))
            .add_child(node::create_node(100, 100, 50, 50, color::BLUE))
            .add_child(node::create_node(150, 150, 50, 50, color::YELLOW))
            .add_child(node::create_node(200, 200, 50, 50, color::MAGENTA))
            .add_child(node::create_node(250, 250, 50, 50, color::CYAN))
            .add_child(node::create_node(300, 300, 50, 50, color::WHITE))
            .add_child(node::create_node(350, 350, 50, 50, color::BLACK))
            .return_to_root();
      }};

  return win.run();
}
