#include "core/window/window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <utility>

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_timer.h"
#include "core/renderer/api/sdl_api.hpp"
#include "core/renderer/factory/renderer.hpp"
#include "core/renderer/template/bfs.hpp"

using desomi::core::window;

window::window(window_config config) : config_{std::move(config)} {
  window_ = std::unique_ptr<SDL_Window, WindowDeleter>{
      SDL_CreateWindow(config_.title.c_str(), config_.x, config_.y, config_.w,
                       config_.h, config_.flags),
      WindowDeleter{}};
  if (!window_) {
    throw std::runtime_error{SDL_GetError()};
  }
  // TODO: This should be non-static.
  auto* api = SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED);
  renderer_ =
      RendererFactory<render::RendererBFS, render::SDL_RenderAPI>::create(api);
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
// TODO: Pre-tasks and post-tasks should be encapsulated.
int window::run() {
  lask_tick = SDL_GetTicks();
  SDL_Event event;
  while (true) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        return 0;
      }
    }
    renderer_->render(root_.get());
    frame_adjust();
  }
  SDL_Quit();
  return 0;
}

void window::frame_adjust() {
  uint32_t cost = SDL_GetTicks() - lask_tick;
  uint32_t frame_expected = 1000 / config_.framerate;
  if (frame_expected > cost) {
    SDL_Delay(frame_expected - cost);
  }
  lask_tick = SDL_GetTicks();
}
