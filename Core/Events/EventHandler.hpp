#pragma once

#include <SDL2/SDL_events.h>

#include "Character/CharacterManager.hpp"
class EventHandler {
 public:
  EventHandler() = default;
  ~EventHandler() = default;

  EventHandler(const EventHandler&) = delete;
  EventHandler& operator=(const EventHandler&) = delete;
  EventHandler(EventHandler&&) = delete;
  EventHandler& operator=(EventHandler&&) = delete;

  int handler(CharacterManager& character_manager);

 private:
  // TODO: Add Event Hooks like the function below
  void mouse_down_handler(const SDL_Event& event,
                          CharacterManager& character_manager);
	void mouse_up_handler(const SDL_Event& event,
													CharacterManager& character_manager);
	void mouse_motion_handler(const SDL_Event& event,
														CharacterManager& character_manager);
};
