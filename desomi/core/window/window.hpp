#pragma once

#include <SDL2/SDL_video.h>

#include <functional>
#include <memory>
#include <string>

#include "core/node/node.hpp"
#include "core/window/renderer.hpp"

namespace desomi::core {

class window {
 public:
  using WindowDeleter = struct wdeleter {
    void operator()(SDL_Window* window) const { SDL_DestroyWindow(window); }
  };

  using window_config = struct wconfig {
    static constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED;
    static constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED;
    static constexpr int DEFAULT_W = 800;
    static constexpr int DEFAULT_H = 600;
    static constexpr int DEFAULT_FRAMERATE = 60;
    static constexpr Uint32 DEFAULT_FLAGS = SDL_WINDOW_SHOWN;

    std::string title{"Desomi"};
    int x{DEFAULT_X};
    int y{DEFAULT_Y};
    int w{DEFAULT_W};
    int h{DEFAULT_H};
    int framerate{DEFAULT_FRAMERATE};
    Uint32 flags{DEFAULT_FLAGS};
  };

  using node_init_func =
      std::function<node::node_ptr(const window_config& config)>;

 private:
  std::unique_ptr<SDL_Window, WindowDeleter> window_;
  std::unique_ptr<renderer> renderer_;
  node::node_ptr root_;
  const window_config config_;

 public:
  window();
  explicit window(window_config config);
  explicit window(const node_init_func& root);
  window(window_config config, const node_init_func& root);
  ~window() = default;
  window(const window&) = delete;
  window(window&&) = delete;
  window& operator=(const window&) = delete;
  window& operator=(window&&) = delete;

  int run();
};

}  // namespace desomi::core