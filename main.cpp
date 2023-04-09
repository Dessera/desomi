#include <iostream>
#include <memory>

#include "core/node/interface/node.hpp"
#include "core/node/templates/rect_node.hpp"
#include "core/node/templates/root.hpp"
#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"
#include "core/window/window.hpp"

int main() {
  using desomi::core::interfaces::Inode;
  using desomi::core::node::RectNode;
  using desomi::core::node::Root;
  using desomi::core::utils::Color;
  using desomi::core::utils::Rect;

  desomi::core::Window win{
      [](const desomi::core::Window::window_config& config) {
        return Root::create<Root>(config.w, config.h)
            ->add_child(Inode::create<RectNode>(Rect{0, 0, 100, 100},
                                                Color(Color::RED)))
            ->add_child(Inode::create<RectNode>(Rect{100, 100, 100, 100},
                                                Color(Color::GREEN)))
            ->add_scope(Inode::create<RectNode>(Rect{200, 200, 500, 500},
                                                Color(Color::BLUE)))
            ->add_child(Inode::create<RectNode>(Rect{200, 200, 100, 100},
                                                Color(Color::YELLOW)))
            ->end()
            ->root();
      }};

  return win.run();
}
