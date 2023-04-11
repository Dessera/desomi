#include <iostream>
#include <memory>

#include "core/node/interface/node.hpp"
#include "core/node/templates/rect_node.hpp"
#include "core/node/templates/root.hpp"
#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"
#include "core/window/window.hpp"

int main() {
  using desomi::core::Window;
  using desomi::core::interfaces::Inode;
  using desomi::core::node::RectNode;
  using desomi::core::node::Root;
  using desomi::core::utils::Color;
  using desomi::core::utils::Rect;

  auto* win = Window::create([](const Window::WindowConfig& config) {
    return Inode::create<Root>(config.w, config.h)
        ->add_child(Inode::create<RectNode>(Rect{0, 0, 100, 100}, Color::RED))
        ->add_scope([]() {
          return Inode::create<RectNode>(Rect{100, 100, 100, 100}, Color::BLUE)
              ->add_child(
                  Inode::create<RectNode>(Rect{100, 100, 50, 50}, Color::GREEN))
              ->add_child(Inode::create<RectNode>(Rect{150, 150, 50, 50},
                                                  Color::YELLOW));
        })
        ->root();
  });

  return win->run();
}
