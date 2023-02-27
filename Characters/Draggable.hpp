#pragma once
#include <SDL2/SDL_rect.h>
#include "Character/Character.hpp"

class Draggable : public Character {
 private:
  bool is_dragging{false};
	SDL_Point mouse_offset{};

 public:
	Draggable() = default;
   ~Draggable() override = default;

	bool on_mouse_down(const SDL_Event &event) override;
	bool on_mouse_up(const SDL_Event &event) override;
	bool on_mouse_motion(const SDL_Event &event) override;
};
