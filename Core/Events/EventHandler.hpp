#pragma once

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
  void mouse_down_handler(CharacterManager& character_manager);
};
