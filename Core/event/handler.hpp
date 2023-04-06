#pragma once

#include <SDL2/SDL_events.h>

#include <cstddef>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils/class_modify.hpp"

class EventHandler {
 public:
  using EventMap =
      std::unordered_map<SDL_EventType,
                         std::vector<std::function<void(SDL_Event&)>>>;
  DELETE_COPY_AND_MOVE(EventHandler);

 private:
  EventMap event_map_{};
  SDL_Event event_{};

 public:
  EventHandler();
  ~EventHandler() = default;

  std::size_t event_register(SDL_EventType event_type,
                            std::function<void(SDL_Event&)> callback);

  void event_unregister(SDL_EventType event_type, std::size_t event_id);

  bool event_handle();
};
