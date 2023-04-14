
#include "core/node/templates/root.hpp"

namespace desomi::core::node {

void Root::render(interfaces::IrendererAPI* renderer) {
  renderer->set_draw_color(utils::Color::WHITE);
  renderer->draw_rect(viewport_);
}

}  // namespace desomi::core::node
