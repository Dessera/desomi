#include "EventHandler.hpp"
#include <SDL2/SDL_events.h>

int EventHandler::handler(CharacterManager& character_manager) {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEBUTTONDOWN:
				mouse_down_handler(character_manager);
				break;
			default:
				break;
		}
	}
	return 0;
}

void EventHandler::mouse_down_handler(CharacterManager& character_manager) {
	// TODO: call hook in the character_manager
	// character_manager
}
