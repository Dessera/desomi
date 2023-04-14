#include <iostream>
#include <memory>

#include "core/node/interface/node.hpp"
#include "core/node/templates/rect_node.hpp"
#include "core/node/templates/root.hpp"
#include "core/plugins/templates/manager.hpp"
#include "core/plugins/templates/vsync.hpp"
#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"
#include "core/window/window.hpp"

int main() {
  using namespace desomi::core;

  auto* win = Window::create(
      [](const Window::WindowConfig& config) {
        using node::Root;
        using node::RectNode;
        return Root::create(config.w, config.h)
            ->add_child(RectNode::create(0, 0, 100, 100, utils::Color::RED));
      },
      []() {
        return plugins::PluginManager::create()->add_plugin(
            plugins::VsyncController::create());
      });

  return win->run();
}
