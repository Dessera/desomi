#include "core/window/window.hpp"

#include <SDL2/SDL.h>

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_timer.h"
#include "core/node/templates/root.hpp"
#include "core/plugins/manager.hpp"
#include "core/renderer/api/sdl_api.hpp"
#include "core/renderer/factory/renderer.hpp"
#include "core/renderer/template/bfs.hpp"

using desomi::core::Window;

Window::Window(WindowConfig config, const root_init_func& root,
               const plugin_init_func& plugin)
    : config_{std::move(config)} {
  // TODO: This should be non-static.
  renderer_ =
      RendererFactory<render::RendererBFS, render::SDL_RenderAPI>::create(
          config_);
  root_ = root(config_);
  plugins_ = plugin();

  plugins_->on_window_create(root_);
}
Window::Window(WindowConfig config)
    : Window{std::move(config),
             [](const WindowConfig& config) {
               return node::Root::create(config.w, config.h);
             },
             []() { return plugins::PluginManager::create(); }} {}
Window::Window(const root_init_func& root)
    : Window{WindowConfig{}, root,
             []() { return plugins::PluginManager::create(); }} {}

Window::Window(const root_init_func& root, const plugin_init_func& plugin)
    : Window{WindowConfig{}, root, plugin} {}

// TODO: This is a temporary implementation. It should be replaced with a
//       proper event loop.
// TODO: Pre-tasks and post-tasks should be encapsulated.
int Window::run() {
  plugins_->on_window_run(root_);
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    plugins_->on_frame_start(root_);
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    renderer_->render(root_.get());
    plugins_->on_frame_end(root_);
  }
  plugins_->on_window_destroy(root_);
  return 0;
}
