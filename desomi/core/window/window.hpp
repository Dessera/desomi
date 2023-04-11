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
   * @brief The window_config struct
   *        The window_config struct is used to configure the window.
   *        The default value is set as static constexpr member.
   */
  using WindowConfig = struct wconfig {
    static constexpr int32_t DEFAULT_X = 0x2FFF0000u | 0;
    static constexpr int32_t DEFAULT_Y = 0x2FFF0000u | 0;
    static constexpr int32_t DEFAULT_W = 800;
    static constexpr int32_t DEFAULT_H = 600;
    static constexpr uint32_t DEFAULT_FRAMERATE = 60;
    static constexpr uint32_t DEFAULT_FLAGS = SDL_WINDOW_SHOWN;

    std::string title{"Desomi"};
    int32_t x{DEFAULT_X};
    int32_t y{DEFAULT_Y};
    int32_t w{DEFAULT_W};
    int32_t h{DEFAULT_H};
    uint32_t framerate{DEFAULT_FRAMERATE};
    uint32_t flags{DEFAULT_FLAGS};
  };

  /**
   * @brief The node_init_func type
   *        The node_init_func type is used to initialize the root node.
   *        The function should return a node::node_ptr.
   */
  using root_init_func =
      std::function<interfaces::Inode::node_ptr(const WindowConfig& config)>;

 private:
  std::unique_ptr<interfaces::Irenderer> renderer_;
  interfaces::Inode::node_ptr root_;

  core::utils::timer::VerticalSyncController vsync_;
  const WindowConfig config_;

  explicit Window(WindowConfig config);
  explicit Window(const root_init_func& root);
  Window(WindowConfig config, const root_init_func& root);

 public:
  ~Window() = default;

  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  int run();

  static Window* create(auto... args) {
    static auto *window = new Window(std::forward<decltype(args)>(args)...);
    return window;
  }
};

}  // namespace desomi::core