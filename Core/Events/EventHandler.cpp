#include "EventHandler.hpp"

#include <SDL2/SDL_events.h>

int EventHandler::handler(CharacterManager& character_manager) {
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    switch (event.type) {
      case SDL_QUIT:
        return 1;
      case SDL_MOUSEBUTTONDOWN:
        mouse_down_handler(event, character_manager);
        break;
      case SDL_MOUSEBUTTONUP:
        mouse_up_handler(event, character_manager);
        break;
      case SDL_MOUSEMOTION:
        mouse_motion_handler(event, character_manager);
        break;
      default:
        break;
    }
  }
  return 0;
}

void EventHandler::mouse_down_handler(const SDL_Event& event,
                                      CharacterManager& character_manager) {
  character_manager.on_mouse_down(event);
}

void EventHandler::mouse_up_handler(const SDL_Event& event,
                                    CharacterManager& character_manager) {
  character_manager.on_mouse_up(event);
}

void EventHandler::mouse_motion_handler(const SDL_Event& event,
                                        CharacterManager& character_manager) {
  character_manager.on_mouse_motion(event);
}
