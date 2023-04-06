#include "object/element.hpp"

void WindowElement::render(SDL_Renderer *renderer, ResourceManager *resources) {
  rect_.x += speed_x_;
  rect_.y += speed_y_;
  angle_ += rotate_speed_;
  if (texture_path_.empty()) {
    SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
    SDL_RenderFillRect(renderer, &rect_);
  } else {
    auto *resource = resources->get_texture(texture_path_).get();
    SDL_RenderCopyEx(renderer, resource, nullptr, &rect_, angle_, nullptr,
                     SDL_FLIP_NONE);
  }
}

void WindowElement::on_click(SDL_Event &event) {
  rect_.x = event.button.x;
  rect_.y = event.button.y;
}
