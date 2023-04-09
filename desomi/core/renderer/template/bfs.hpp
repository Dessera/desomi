#pragma once

#include <memory>
#include <queue>

#include "core/renderer/interfaces/render_api.hpp"
#include "core/renderer/interfaces/renderer.hpp"

namespace desomi::core::render {

class RendererBFS final : public interfaces::Irenderer {
 private:
  std::queue<interfaces::Inode*> render_queue_;

 public:
  explicit RendererBFS(interfaces::IrendererAPI* renderer_api)
      : Irenderer(renderer_api){};
  ~RendererBFS() final = default;

  RendererBFS(const RendererBFS&) = delete;
  RendererBFS(RendererBFS&&) = delete;
  RendererBFS& operator=(const RendererBFS&) = delete;
  RendererBFS& operator=(RendererBFS&&) = delete;

  void render(interfaces::Inode* node) final;
};

}  // namespace desomi::core::render
