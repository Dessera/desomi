#include <SDL2/SDL_rect.h>
#include "Character/Character.hpp"

class Draggable : public Character {
 private:
  bool is_dragging{false};
	SDL_Point mouse_offset{};

 public:
	Draggable() = default;
  virtual ~Draggable() = default;

	void on_mouse_down(const SDL_Event &event) override;
	void on_mouse_up(const SDL_Event &event) override;
	void on_mouse_motion(const SDL_Event &event) override;
};
