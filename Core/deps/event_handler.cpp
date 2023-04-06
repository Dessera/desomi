#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include <cstddef>
#include <cstdint>

#include "event/handler.hpp"

EventHandler::EventHandler() { SDL_Init(SDL_INIT_EVENTS); }

bool EventHandler::event_handle() {
  while (SDL_PollEvent(&event_) != 0) {
    if (event_.type == SDL_QUIT) {
      return false;
    }
    if (!event_map_.contains(static_cast<SDL_EventType>(event_.type))) {
      continue;
    }
    for (auto& callback :
         event_map_.at(static_cast<SDL_EventType>(event_.type))) {
      callback(event_);
    }
  }
  return true;
}

std::size_t EventHandler::event_register(
    SDL_EventType event_type, std::function<void(SDL_Event&)> callback) {
  event_map_[event_type].push_back(std::move(callback));
  return event_map_[event_type].size() - 1;
}

void EventHandler::event_unregister(SDL_EventType event_type,
                                    std::size_t event_id) {
  event_map_[event_type].erase(event_map_[event_type].begin() +
                               static_cast<int64_t>(event_id));
}
