#pragma once

#include <SDL2/SDL_render.h>

#include <memory>
#include <queue>

#include "core/node/node.hpp"

namespace desomi::core {

class renderer {
 public:
  using RendererDeleter = struct rdeleter {
    void operator()(SDL_Renderer* renderer) const {
      SDL_DestroyRenderer(renderer);
    }
  };

 private:
  std::unique_ptr<SDL_Renderer, RendererDeleter> renderer_;
  std::queue<node*> render_queue_{};

 public:
  renderer(SDL_Window* window, int index, Uint32 flags);
  ~renderer() = default;
  renderer(const renderer&) = delete;
  renderer(renderer&&) = delete;
  renderer& operator=(const renderer&) = delete;
  renderer& operator=(renderer&&) = delete;

  void render(node* node);
  void clear();
  void present();
};

} // namespace desomi::core
