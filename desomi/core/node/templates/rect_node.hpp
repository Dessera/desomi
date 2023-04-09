#pragma once

#include <cstdint>

#include "core/node/interface/node.hpp"
namespace desomi::core::node {

class RectNode : public interfaces::Inode {
 private:
  utils::Rect rect_;
  utils::Color color_;

 public:
  RectNode(utils::Rect rect, utils::Color color);
  RectNode(int32_t x, int32_t y, int32_t width, int32_t height,
           utils::Color color);
  explicit RectNode(utils::Rect rect);

  ~RectNode() override = default;
  void render(interfaces::IrendererAPI* renderer) override;

  RectNode(const RectNode&) = default;
  RectNode& operator=(const RectNode&) = default;
  RectNode(RectNode&&) = default;
  RectNode& operator=(RectNode&&) = default;
};

}  // namespace desomi::core::node
