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
  virtual ~Character();

  inline SDL_Rect &get_rect() { return chara_rect; }
  inline SDL_Color &get_color() { return chara_color; }

  void render(SDL_Renderer *renderer);

  // Rewrite all events in SDL_EventType

  virtual void on_quit(const SDL_Event &event);

  virtual void on_locale_changed(const SDL_Event &event);

  virtual void on_clipboard_update(const SDL_Event &event);

  virtual void on_sensor_update(const SDL_Event &event);

#pragma region App Events
  virtual void on_app_terminating(const SDL_Event &event);
  virtual void on_app_low_memory(const SDL_Event &event);
  virtual void on_app_will_enter_background(const SDL_Event &event);
  virtual void on_app_did_enter_background(const SDL_Event &event);
  virtual void on_app_will_enter_foreground(const SDL_Event &event);
  virtual void on_app_did_enter_foreground(const SDL_Event &event);
#pragma endregion

#pragma region Window Events
  virtual void on_display_event(const SDL_Event &event);
  virtual void on_window_event(const SDL_Event &event);
  virtual void on_system_event(const SDL_Event &event);
#pragma endregion

#pragma region Keyboard Events
  virtual void on_key_down(const SDL_Event &event);
  virtual void on_key_up(const SDL_Event &event);
  virtual void on_text_editing(const SDL_Event &event);
  virtual void on_text_input(const SDL_Event &event);
  virtual void on_keymap_changed(const SDL_Event &event);
#pragma endregion

#pragma region Mouse Events
  virtual void on_mouse_down(const SDL_Event &event);
  virtual void on_mouse_up(const SDL_Event &event);
  virtual void on_mouse_motion(const SDL_Event &event);
  virtual void on_mouse_wheel(const SDL_Event &event);
#pragma endregion

#pragma region Joystick Events
  virtual void on_joystick_axis_motion(const SDL_Event &event);
  virtual void on_joystick_ball_motion(const SDL_Event &event);
  virtual void on_joystick_hat_motion(const SDL_Event &event);
  virtual void on_joystick_button_down(const SDL_Event &event);
  virtual void on_joystick_button_up(const SDL_Event &event);
  virtual void on_joystick_device_added(const SDL_Event &event);
  virtual void on_joystick_device_removed(const SDL_Event &event);
#pragma endregion

#pragma region Game Controller Events
  virtual void on_controller_axis_motion(const SDL_Event &event);
  virtual void on_controller_button_down(const SDL_Event &event);
  virtual void on_controller_button_up(const SDL_Event &event);
  virtual void on_controller_device_added(const SDL_Event &event);
  virtual void on_controller_device_removed(const SDL_Event &event);
  virtual void on_controller_device_remapped(const SDL_Event &event);
  virtual void on_controller_touchpad_down(const SDL_Event &event);
  virtual void on_controller_touchpad_up(const SDL_Event &event);
  virtual void on_controller_touchpad_motion(const SDL_Event &event);
  virtual void on_controller_sensor_update(const SDL_Event &event);
#pragma endregion

#pragma region Touch Events
  virtual void on_touch_finger(const SDL_Event &event);
  virtual void on_multi_gesture(const SDL_Event &event);
  virtual void on_dollar_gesture(const SDL_Event &event);
  virtual void on_dollar_record(const SDL_Event &event);
#pragma endregion

#pragma region Drop Events
  virtual void on_drop_file(const SDL_Event &event);
  virtual void on_drop_text(const SDL_Event &event);
  virtual void on_drop_begin(const SDL_Event &event);
  virtual void on_drop_complete(const SDL_Event &event);
#pragma endregion

  virtual void on_audio_device_added(const SDL_Event &event);
  virtual void on_audio_device_removed(const SDL_Event &event);

  virtual void on_render_targets_reset(const SDL_Event &event);
  virtual void on_render_device_reset(const SDL_Event &event);

  // virtual void on_poll_sentinel(const SDL_Event &event);

  // virtual void on_user_event(const SDL_Event &event);
};
