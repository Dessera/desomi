#include "Character.hpp"

#include <SDL2/SDL_rect.h>

Character::Character() {
  chara_rect = SDL_Rect{0, 0, 100, 100};
  chara_color = SDL_Color{255, 0, 0, 255};
}

Character::~Character() { SDL_DestroyTexture(chara_texture); }

void Character::render(SDL_Renderer *renderer) {
  if (chara_texture == nullptr) {
    SDL_SetRenderDrawColor(renderer, chara_color.r, chara_color.g,
                           chara_color.b, chara_color.a);
    SDL_RenderFillRect(renderer, &chara_rect);
  } else {
    SDL_RenderCopy(renderer, chara_texture, nullptr, &chara_rect);
  }
}

void Character::on_mouse_down(const SDL_Event &event) {}

void Character::on_mouse_up(const SDL_Event &event) {}

void Character::on_mouse_motion(const SDL_Event &event) {}
