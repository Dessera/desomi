#pragma once

#include <memory>

#include "core/node/interface/node.hpp"
#include "core/renderer/interfaces/render_api.hpp"

namespace desomi::core::interfaces {
class Irenderer {
 protected:
  std::unique_ptr<IrendererAPI> renderer_api_;

 public:
  explicit Irenderer(IrendererAPI* renderer_api)
      : renderer_api_(renderer_api) {}
  virtual ~Irenderer() = default;
  virtual void render(Inode* node) = 0;
};

}  // namespace desomi::core::interfaces