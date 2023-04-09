
#include "core/node/templates/root.hpp"

using desomi::core::node::Root;

void Root::render(interfaces::IrendererAPI* renderer) {
  renderer->set_draw_color(utils::color(utils::color::WHITE));
  renderer->draw_rect(viewport_);
}
