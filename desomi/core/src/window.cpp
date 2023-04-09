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
#include "core/utils/timer.hpp"

using desomi::core::Window;

Window::Window(window_config config) : config_{std::move(config)} {
  window_ = std::unique_ptr<SDL_Window, WindowDeleter>{
      SDL_CreateWindow(config_.title.c_str(), config_.x, config_.y, config_.w,
                       config_.h, config_.flags),
      WindowDeleter{}};
  if (!window_) {
    throw std::runtime_error{SDL_GetError()};
  }
  // TODO: This should be non-static.
  // TODO: error check
  renderer_ =
      RendererFactory<render::RendererBFS, render::SDL_RenderAPI>::create(
          window_.get(), -1, SDL_RENDERER_ACCELERATED);
  vsync_.set_fps(config_.framerate);
}

Window::Window(const node_init_func& root) : Window{window_config{}} {
  root_ = root(config_);
}
Window::Window(window_config config, const node_init_func& root)
    : Window{std::move(config)} {
  root_ = root(config_);
}

// TODO: This is a temporary implementation. It should be replaced with a
//       proper event loop.
// TODO: Pre-tasks and post-tasks should be encapsulated.
int Window::run() {
  vsync_.enable();
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    renderer_->render(root_.get());
    vsync_.wait();
  }
  SDL_Quit();
  return 0;
}
