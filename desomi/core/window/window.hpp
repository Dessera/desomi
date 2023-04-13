#pragma once

/**
 * @file window.hpp
 * @author Dessera (1533653159@qq.com)
 * @brief Window class
 * @version 0.1
 * @date 2023-04-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

#include "core/node/interface/node.hpp"
#include "core/plugins/api/plugin.hpp"
#include "core/plugins/manager.hpp"
#include "core/renderer/interfaces/renderer.hpp"

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
   * TODO: Extract the WindowConfig to a separate file, and extract the Abstract
   *       Base Class.
   */
  using WindowConfig = struct wconfig {
    static constexpr int32_t DEFAULT_W = 800;
    static constexpr int32_t DEFAULT_H = 600;
    static constexpr uint32_t DEFAULT_FRAMERATE = 60;

    std::string title{"Desomi"};
    int32_t w{DEFAULT_W};
    int32_t h{DEFAULT_H};
    uint32_t framerate{DEFAULT_FRAMERATE};
  };

  /**
   * @brief The root_init_func type
   *        The root_init_func type is used to initialize the root node.
   *        The function should return a Inode::node_ptr.
   */
  using root_init_func =
      std::function<interfaces::Inode::node_ptr(const WindowConfig& config)>;

 private:
  /**
   * @brief Renderer that derived from Irenderer
   *        The renderer is used to render the scene.
   *        And Irenderer is an interface of the renderer, including all api and
   *        render method.
   */
  std::unique_ptr<interfaces::Irenderer> renderer_;

  /**
   * @brief Root node of the scene
   *        Root is a special derived class of Inode.
   */
  interfaces::Inode::node_ptr root_;

  /**
   * @brief Plugin manager
   *
   */
  std::unique_ptr<plugins::PluginManager> plugins_;

  /**
   * @brief A common config for the window
   *        Config cann
   *
   */
  const WindowConfig config_;

  /**
   * @brief Construct a new Window object
   *
   * @param config Configuration of the window
   * @param root Function to initialize the root node, please refer to
   *             root_init_func
   */
  Window(WindowConfig config, const root_init_func& root);

  /**
   * @brief Construct a new Window object
   *
   * @param config Configuration of the window
   * @note The root node will be initialized with node::Root initialized with
   *       config.w and config.h
   */
  explicit Window(WindowConfig config);

  /**
   * @brief Construct a new Window object
   *
   * @param root Function to initialize the root node, please refer to
   *             root_init_func
   * @note The window will be initialized with default config, please refer to
   * WindowConfig
   */
  explicit Window(const root_init_func& root);

 public:
  ~Window() = default;

  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  /**
   * @brief Run the window
   *        The run method will start the window and render the scene.
   *        The window will be closed when the SDL_QUIT is generated.
   * TODO: I need to extract event logic from the window class.
   *       so that the window class can be based on Abstract Base Class rather
   *       than SDL
   *
   * @return int 0 if the window is closed normally, otherwise -1
   */
  int run();

  /**
   * @brief Create a Window object
   *
   * @param args Constructor arguments of Window
   * @return Window* Only one window is allowed, so the create method will
   * return a static pointer defined in the create method.
   */
  static Window* create(auto... args) {
    static auto* window = new Window(std::forward<decltype(args)>(args)...);
    return window;
  }
};

}  // namespace desomi::core