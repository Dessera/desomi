#pragma once

#include <SDL2/SDL_events.h>
#include <memory>
#include <string>

#include "object/element.hpp"
#include "utils/class_modify.hpp"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600
#define DEFAULT_WINDOW_TITLE "Window"
#define DEFAULT_WINDOW_FRAME_TIME 60

using WindowConfig = struct wconfig {
  int width{DEFAULT_WINDOW_WIDTH};
  int height{DEFAULT_WINDOW_HEIGHT};
  int frame_time{DEFAULT_WINDOW_FRAME_TIME};
  std::string title{DEFAULT_WINDOW_TITLE};
};

class Window {
 public:
  DELETE_COPY_AND_MOVE(Window);

  explicit Window(const WindowConfig& config);
  explicit Window() : Window(WindowConfig()) {}
  ~Window();

  int run();

  void load_texture(const std::string& path);
  void load_surface(const std::string& path);

  void add_element(std::shared_ptr<WindowElement> element);
  std::size_t event_register(SDL_EventType event_type,
                             const std::function<void(SDL_Event&)>& callback);
  void event_unregister(SDL_EventType event_type, std::size_t eid);

 private:
  class WindowImpl;
  std::unique_ptr<WindowImpl> impl_;
};
