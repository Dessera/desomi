

#include "core/window/renderer.hpp"

using desomi::core::renderer;

renderer::renderer(SDL_Window* window, int index, Uint32 flags) {
  renderer_ = std::unique_ptr<SDL_Renderer, RendererDeleter>{
      SDL_CreateRenderer(window, index, flags), RendererDeleter{}};
  if (!renderer_) {
    throw std::runtime_error{SDL_GetError()};
  }
}

void renderer::render(node* node) {
  clear();
  render_queue_.push(node);

  while (!render_queue_.empty()) {
    auto* node = render_queue_.front();
    render_queue_.pop();
    node->render(renderer_.get());

    for (auto& child : node->children()) {
      render_queue_.push(child.get());
    }
  }
  present();
}

void renderer::clear() { SDL_RenderClear(renderer_.get()); }

void renderer::present() { SDL_RenderPresent(renderer_.get()); }
