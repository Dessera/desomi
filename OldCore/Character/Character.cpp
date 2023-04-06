#include "Character.hpp"

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <utility>

Character::~Character() { SDL_DestroyTexture(chara_texture); }
Character::Character(const SDL_Rect &rect, const SDL_Color &color,
                     std::string path)
    : chara_rect(rect), chara_color(color), path(std::move(path)) {}

void Character::render(SDL_Renderer *renderer) {
  chara_rect.x += speed_x;
  chara_rect.y += speed_y;
  angle += rotate_speed;
  if (chara_texture == nullptr) {
    SDL_SetRenderDrawColor(renderer, chara_color.r, chara_color.g,
                           chara_color.b, chara_color.a);
    SDL_RenderFillRect(renderer, &chara_rect);
  } else {
    SDL_RenderCopyEx(renderer, chara_texture, nullptr, &chara_rect, angle,
                     nullptr, SDL_FLIP_NONE);
  }
}

bool Character::on_quit(const SDL_Event & /*event*/) { return false; }
bool Character::on_locale_changed(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_clipboard_update(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_sensor_update(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_app_terminating(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_app_low_memory(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_app_will_enter_background(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_app_did_enter_background(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_app_will_enter_foreground(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_app_did_enter_foreground(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_display_event(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_window_event(const SDL_Event & /* event */) { return false; }
bool Character::on_system_event(const SDL_Event & /* event */) { return false; }

bool Character::on_key_down(const SDL_Event & /* event */) { return false; }
bool Character::on_key_up(const SDL_Event & /* event */) { return false; }
bool Character::on_text_editing(const SDL_Event & /* event */) { return false; }
bool Character::on_text_input(const SDL_Event & /* event */) { return false; }
bool Character::on_keymap_changed(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_mouse_down(const SDL_Event & /* event */) { return false; }
bool Character::on_mouse_up(const SDL_Event & /* event */) { return false; }
bool Character::on_mouse_motion(const SDL_Event & /* event */) { return false; }
bool Character::on_mouse_wheel(const SDL_Event & /* event */) { return false; }

bool Character::on_joystick_axis_motion(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_joystick_ball_motion(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_joystick_hat_motion(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_joystick_button_down(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_joystick_button_up(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_joystick_device_added(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_joystick_device_removed(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_controller_axis_motion(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_button_down(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_button_up(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_device_added(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_device_removed(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_device_remapped(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_touchpad_motion(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_touchpad_down(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_touchpad_up(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_controller_sensor_update(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_touch_finger(const SDL_Event & /* event */) { return false; }
bool Character::on_multi_gesture(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_dollar_gesture(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_dollar_record(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_drop_file(const SDL_Event & /* event */) { return false; }
bool Character::on_drop_text(const SDL_Event & /* event */) { return false; }
bool Character::on_drop_begin(const SDL_Event & /* event */) { return false; }
bool Character::on_drop_complete(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_audio_device_added(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_audio_device_removed(const SDL_Event & /* event */) {
  return false;
}

bool Character::on_render_targets_reset(const SDL_Event & /* event */) {
  return false;
}
bool Character::on_render_device_reset(const SDL_Event & /* event */) {
  return false;
}
