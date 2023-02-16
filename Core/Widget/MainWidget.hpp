#pragma once
#include <SDL2/SDL.h>

#include <memory>

#include "Character/CharacterManager.hpp"
#include "Events/EventHandler.hpp"
#include "Resource/Resource.hpp"

#define WIDGET_FRAME_TIME 60
#define WIDGET_WIDTH 800
#define WIDGET_HEIGHT 600

using WidgetConfig = struct wconfig {
  int frame_time{WIDGET_FRAME_TIME};
  int width{WIDGET_WIDTH};
  int height{WIDGET_HEIGHT};
};

class MainWidget {
 private:
  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};

  std::unique_ptr<ResourcesManager> resources_manager{nullptr};
  std::unique_ptr<EventHandler> event_handler{nullptr};
  std::unique_ptr<CharacterManager> character_manager{nullptr};

  WidgetConfig config{};

 public:
  explicit MainWidget(const WidgetConfig& config);
  ~MainWidget();

  MainWidget() = delete;
  MainWidget(const MainWidget&) = delete;
  MainWidget& operator=(const MainWidget&) = delete;
  MainWidget(MainWidget&&) = delete;
  MainWidget& operator=(MainWidget&&) = delete;

  int loop();

 private:
  void render();
  [[nodiscard]] bool frame_adjust() const;
};
