#include "core/window/window.hpp"

#include <utility>

#include "SDL2/SDL_events.h"
#include "core/node/node.hpp"

using desomi::core::window;

window::window(window_config config) : config_{std::move(config)} {
  window_ = std::unique_ptr<SDL_Window, WindowDeleter>{
      SDL_CreateWindow(config_.title.c_str(), config_.x, config_.y, config_.w,
                       config_.h, config_.flags),
      WindowDeleter{}};
  if (!window_) {
    throw std::runtime_error{SDL_GetError()};
  }
  renderer_ =
      std::make_unique<renderer>(window_.get(), -1, SDL_RENDERER_ACCELERATED);
  root_ = node::create_root(config_.w, config_.h);
}

window::window(const node_init_func& root) : window{window_config{}} {
  root_ = root(config_);
}
window::window(window_config config, const node_init_func& root)
    : window{std::move(config)} {
  root_ = root(config_);
}
window::window() : window{window_config{}} {}

// TODO: This is a temporary implementation. It should be replaced with a
//       proper event loop.
// TODO: Frame rate control.
int window::run() {
  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;
        default:
          break;
      }
    }
    renderer_->render(root_.get());
  }
  return 0;
}
