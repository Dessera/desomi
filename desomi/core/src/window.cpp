#include "core/window/window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <atomic>
#include <utility>

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_timer.h"
#include "core/renderer/api/sdl_api.hpp"
#include "core/renderer/factory/renderer.hpp"
#include "core/renderer/template/bfs.hpp"
#include "core/utils/timer.hpp"

using desomi::core::Window;

Window::Window(WindowConfig config) : config_{std::move(config)} {
  // TODO: This should be non-static.
  renderer_ =
      RendererFactory<render::RendererBFS, render::SDL_RenderAPI>::create(
          config_);
  vsync_.set_fps(config_.framerate);
}

Window::Window(const root_init_func& root) : Window{WindowConfig{}} {
  root_ = root(config_);
}
Window::Window(WindowConfig config, const root_init_func& root)
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
