#pragma once
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include <vector>

#include "Character/Character.hpp"

class CharacterManager {
 private:
  std::vector<Character*> characters{};

 public:
  CharacterManager() = default;
  ~CharacterManager();

  CharacterManager(const CharacterManager&) = delete;
  CharacterManager& operator=(const CharacterManager&) = delete;
  CharacterManager(CharacterManager&&) = delete;
  CharacterManager& operator=(CharacterManager&&) = delete;

  void render(SDL_Renderer* renderer);

  void add_character(Character* character);
  void remove_character(Character* character);

	// TODO: add hooks for events
  void on_mouse_down(const SDL_Event& event);
	void on_mouse_up(const SDL_Event& event);
	void on_mouse_motion(const SDL_Event& event);
};
