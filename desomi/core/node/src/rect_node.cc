#include "core/node/templates/rect_node.hpp"

using desomi::core::node::RectNode;

RectNode::RectNode(utils::Rect rect, utils::Color color)
    : rect_(rect), color_(color) {}
RectNode::RectNode(int32_t x, int32_t y, int32_t width, int32_t height,
                   utils::Color color)
    : rect_(x, y, width, height), color_(color) {}
RectNode::RectNode(utils::Rect rect) : rect_(rect), color_(0, 0, 0, 255) {}

void RectNode::render(interfaces::IrendererAPI* renderer) {
  rect_.move();
  renderer->set_draw_color(color_);
  renderer->fill_rect(rect_);
  renderer->default_draw_color();
}
