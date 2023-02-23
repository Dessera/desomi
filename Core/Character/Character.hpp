#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <string>

class Character {
 private:
  SDL_Rect chara_rect{};
  SDL_Color chara_color{};
  SDL_Texture *chara_texture{nullptr};

 public:
  Character();
  // TODO: Complete the constructor
  ~Character();

	inline SDL_Rect& get_rect() { return chara_rect; }
	inline SDL_Color& get_color() { return chara_color; }

  void render(SDL_Renderer *renderer);

  virtual void on_mouse_down(const SDL_Event &event);
	virtual void on_mouse_up(const SDL_Event &event);
	virtual void on_mouse_motion(const SDL_Event &event);
};
