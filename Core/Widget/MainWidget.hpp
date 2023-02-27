#pragma once
#include <SDL2/SDL.h>

#include <memory>
#include <string>

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
  // SDL Core variables
  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};

  // Config (edit this variable can not change the widget)
  WidgetConfig config{};

  // Managers
  std::unique_ptr<ResourcesManager> resources_manager{nullptr};
  std::unique_ptr<EventHandler> event_handler{nullptr};
  std::unique_ptr<CharacterManager> character_manager{nullptr};

  // Other element of the widget
  SDL_Cursor* cursor{nullptr};
 public:
  explicit MainWidget(const WidgetConfig& config);
  ~MainWidget();

  #pragma region Deleted functions
  MainWidget() = delete;
  MainWidget(const MainWidget&) = delete;
  MainWidget& operator=(const MainWidget&) = delete;
  MainWidget(MainWidget&&) = delete;
  MainWidget& operator=(MainWidget&&) = delete;
  #pragma endregion

  // Main loop here
  int loop();

  inline CharacterManager* get_character_manager() { return character_manager.get(); }
  inline ResourcesManager* get_resources_manager() { return resources_manager.get(); }
  inline EventHandler* get_event_handler() { return event_handler.get(); }

	void set_cursor(const std::string& path);
  void add_character(Character* character, const std::string& path = "");

 private:
  void render();
  [[nodiscard]] bool frame_adjust() const;
};
