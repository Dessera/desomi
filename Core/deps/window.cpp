#include "window/window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>

#include <cstddef>
#include <cstdint>
#include <error/error.hpp>
#include <memory>
#include <utility>
#include <vector>

#include "event/handler.hpp"
#include "object/element.hpp"
#include "resource/manager.hpp"
#include "utils/class_modify.hpp"
#include "utils/deleter.hpp"

#define FRAME_EXCHANGER(frame_time) 1000 / frame_time

class Window::WindowImpl {
  /**
   * @brief Construct and Destroy functions
   */
 public:
  DELETE_COPY_AND_MOVE(WindowImpl);
  /**
   * @brief Construct a new Window Impl object
   *
   * @param config config of the window
   * @throw WindowException if Any Initialization failed
   */
  explicit WindowImpl(WindowConfig config) : config_(std::move(config)) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      throw WindowException("SDL_Init failed: " + std::string(SDL_GetError()));
    }
    window_ = std::unique_ptr<SDL_Window, SDL_WindowDeleter>(SDL_CreateWindow(
        config_.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        config_.width, config_.height, SDL_WINDOW_SHOWN));
    if (window_ == nullptr) {
      throw WindowException("SDL_CreateWindow failed: " +
                            std::string(SDL_GetError()));
    }
    renderer_ = std::unique_ptr<SDL_Renderer, SDL_RendererDeleter>(
        SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED));
    if (renderer_ == nullptr) {
      throw WindowException("SDL_CreateRenderer failed: " +
                            std::string(SDL_GetError()));
    }

    event_handler_ = std::make_unique<EventHandler>();
    resource_manager_ = std::make_unique<ResourceManager>();
    elements_ = std::vector<std::shared_ptr<WindowElement>>();
  }
  /**
   * @brief Destroy the Window Impl object
   *
   * @note SDL_Quit() will be called in the destructor
   *       every SDL struct that was wrapped unique_ptr will be freed
   *       automatically macro defined in utils/deleter.hpp will automatically
   *       generate the deleter for SDL struct
   */
  ~WindowImpl() { SDL_Quit(); };

  /**
   * @brief Private utils for Window
   */
 private:
  /**
   * @brief Adjust the frame rate
   *
   * @note This function will be called in the run() function
   *       to adjust the frame rate
   */
  void frame_adjust() {
    uint32_t cost = SDL_GetTicks() - prev_tick_;
    uint32_t frame_expected = FRAME_EXCHANGER(config_.frame_time);
    if (frame_expected > cost) {
      SDL_Delay(frame_expected - cost);
    }
    prev_tick_ = SDL_GetTicks();
  }

  /**
   * @brief Render the window
   *
   */
  void render() {
    SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);
    SDL_RenderClear(renderer_.get());
    for (auto& element : elements_) {
      element->render(renderer_.get(), resource_manager_.get());
    }
    SDL_RenderPresent(renderer_.get());
  }

  /**
   * @brief Deleted functions
   */
 public:
  /**
   * @brief run the main loop
   *
   * @return int
   */
  int run() {
    SDL_Event event;
    while (true) {
      render();
      if (!event_handler_->event_handle()) {
        break;
      }
      frame_adjust();
    }
    return 0;
  }

  /**
   * @brief Load texture from path
   *
   * @param path resource path
   */
  inline void load_texture(const std::string& path) {
    resource_manager_->load_texture(path, renderer_.get());
  }

  /**
   * @brief Load surface from path
   *
   * @param path resource path
   */
  inline void load_surface(const std::string& path) {
    resource_manager_->load_surface(path);
  }

  /**
   * @brief Add element to the window
   *
   * @param element WindowElement or its derived class
   */
  inline void add_element(std::shared_ptr<WindowElement> element) {
    elements_.push_back(std::move(element));
  }

  /**
   * @brief Register event to the event handler
   *
   * @param event_type SDL_EventType
   * @param callback Function to be called when the event is triggered
   * @return std::size_t Index of the callback
   */
  inline std::size_t event_register(
      const SDL_EventType& event_type,
      const std::function<void(SDL_Event&)>& callback) {
    return event_handler_->event_register(event_type, callback);
  }

  /**
   * @brief Unregister event from the event handler
   *
   * @param event_type SDL_EventType
   * @param event_id Index of the callback
   */
  inline void event_unregister(SDL_EventType event_type, std::size_t event_id) {
    event_handler_->event_unregister(event_type, event_id);
  }

  /**
   * @brief Data members
   */
 private:
  WindowConfig config_;

  std::unique_ptr<SDL_Window, SDL_WindowDeleter> window_;
  std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> renderer_;
  std::unique_ptr<EventHandler> event_handler_;
  std::unique_ptr<ResourceManager> resource_manager_;

  std::vector<std::shared_ptr<WindowElement>> elements_;

  uint32_t prev_tick_{SDL_GetTicks()};
};

Window::Window(const WindowConfig& config)
    : impl_(std::make_unique<WindowImpl>(config)) {}
Window::~Window() = default;

int Window::run() { return impl_->run(); }
void Window::load_texture(const std::string& path) {
  impl_->load_texture(path);
}
void Window::load_surface(const std::string& path) {
  impl_->load_surface(path);
}
void Window::add_element(std::shared_ptr<WindowElement> element) {
  impl_->add_element(std::move(element));
}
std::size_t Window::event_register(
    SDL_EventType event_type, const std::function<void(SDL_Event&)>& callback) {
  return impl_->event_register(event_type, callback);
}
void Window::event_unregister(SDL_EventType event_type, std::size_t eid) {
  impl_->event_unregister(event_type, eid);
}
