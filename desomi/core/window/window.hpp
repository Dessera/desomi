#pragma once

#include <SDL2/SDL_video.h>

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

#include "core/node/interface/node.hpp"
#include "core/renderer/interfaces/renderer.hpp"
#include "core/utils/timer.hpp"

namespace desomi::core {

/**
 * @brief The window class
 *        The window class is encapsulating the SDL_Window and the renderer.
 *        renderer is another encapsulation of SDL_Renderer, I am considering
 *        make SDL_Window and SDL_Renderer corresponding to the window and
 *        renderer class.
 */
class Window {
 public:
  /**
   * @brief Custom deleter for SDL_Window
   *
   */
  using WindowDeleter = struct wdeleter {
    void operator()(SDL_Window* window) const { SDL_DestroyWindow(window); }
  };

  /**
   * @brief The window_config struct
   *        The window_config struct is used to configure the window.
   *        The default value is set as static constexpr member.
   */
  using window_config = struct wconfig {
    static constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED;
    static constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED;
    static constexpr int DEFAULT_W = 800;
    static constexpr int DEFAULT_H = 600;
    static constexpr uint32_t DEFAULT_FRAMERATE = 60;
    static constexpr Uint32 DEFAULT_FLAGS = SDL_WINDOW_SHOWN;

    std::string title{"Desomi"};
    int x{DEFAULT_X};
    int y{DEFAULT_Y};
    int w{DEFAULT_W};
    int h{DEFAULT_H};
    uint32_t framerate{DEFAULT_FRAMERATE};
    Uint32 flags{DEFAULT_FLAGS};
  };

  /**
   * @brief The node_init_func type
   *        The node_init_func type is used to initialize the root node.
   *        The function should return a node::node_ptr.
   */
  using node_init_func =
      std::function<interfaces::Inode::node_ptr(const window_config& config)>;

 private:
  std::unique_ptr<SDL_Window, WindowDeleter> window_;
  std::unique_ptr<interfaces::Irenderer> renderer_;
  interfaces::Inode::node_ptr root_;
  
  core::utils::timer::VerticalSyncController vsync_;
  const window_config config_;

 public:
  explicit Window(window_config config);
  explicit Window(const node_init_func& root);
  Window(window_config config, const node_init_func& root);

  ~Window() = default;
  
  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  int run();
};

}  // namespace desomi::core