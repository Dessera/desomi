#pragma once
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include <vector>

#include "Character/Character.hpp"

class CharacterManager {
 private:
  std::vector<Character *> characters{};

 public:
  CharacterManager() = default;
  ~CharacterManager();

  CharacterManager(const CharacterManager &) = delete;
  CharacterManager &operator=(const CharacterManager &) = delete;
  CharacterManager(CharacterManager &&) = delete;
  CharacterManager &operator=(CharacterManager &&) = delete;

  void render(SDL_Renderer *renderer);

  void add_character(Character *character);
  void remove_character(Character *character);

  void on_quit(const SDL_Event &event);
  void on_locale_changed(const SDL_Event &event);
  void on_clipboard_update(const SDL_Event &event);
  void on_sensor_update(const SDL_Event &event);

#pragma region App Events
  void on_app_terminating(const SDL_Event &event);
  void on_app_low_memory(const SDL_Event &event);
  void on_app_will_enter_background(const SDL_Event &event);
  void on_app_did_enter_background(const SDL_Event &event);
  void on_app_will_enter_foreground(const SDL_Event &event);
  void on_app_did_enter_foreground(const SDL_Event &event);
#pragma endregion

#pragma region Window Events
  void on_display_event(const SDL_Event &event);
  void on_window_event(const SDL_Event &event);
  void on_system_event(const SDL_Event &event);
#pragma endregion

#pragma region Keyboard Events
  void on_key_down(const SDL_Event &event);
  void on_key_up(const SDL_Event &event);
  void on_text_editing(const SDL_Event &event);
  void on_text_input(const SDL_Event &event);
  void on_keymap_changed(const SDL_Event &event);
#pragma endregion

#pragma region Mouse Events
  void on_mouse_down(const SDL_Event &event);
  void on_mouse_up(const SDL_Event &event);
  void on_mouse_motion(const SDL_Event &event);
  void on_mouse_wheel(const SDL_Event &event);
#pragma endregion

#pragma region Joystick Events
  void on_joystick_axis_motion(const SDL_Event &event);
  void on_joystick_ball_motion(const SDL_Event &event);
  void on_joystick_hat_motion(const SDL_Event &event);
  void on_joystick_button_down(const SDL_Event &event);
  void on_joystick_button_up(const SDL_Event &event);
  void on_joystick_device_added(const SDL_Event &event);
  void on_joystick_device_removed(const SDL_Event &event);
#pragma endregion

#pragma region Game Controller Events
  void on_controller_axis_motion(const SDL_Event &event);
  void on_controller_button_down(const SDL_Event &event);
  void on_controller_button_up(const SDL_Event &event);
  void on_controller_device_added(const SDL_Event &event);
  void on_controller_device_removed(const SDL_Event &event);
  void on_controller_device_remapped(const SDL_Event &event);
  void on_controller_touchpad_down(const SDL_Event &event);
  void on_controller_touchpad_up(const SDL_Event &event);
  void on_controller_touchpad_motion(const SDL_Event &event);
  void on_controller_sensor_update(const SDL_Event &event);
#pragma endregion

#pragma region Touch Events
  void on_touch_finger(const SDL_Event &event);
  void on_multi_gesture(const SDL_Event &event);
  void on_dollar_gesture(const SDL_Event &event);
  void on_dollar_record(const SDL_Event &event);
#pragma endregion

#pragma region Drop Events
  void on_drop_file(const SDL_Event &event);
  void on_drop_text(const SDL_Event &event);
  void on_drop_begin(const SDL_Event &event);
  void on_drop_complete(const SDL_Event &event);
#pragma endregion

  void on_audio_device_added(const SDL_Event &event);
  void on_audio_device_removed(const SDL_Event &event);

  void on_render_targets_reset(const SDL_Event &event);
  void on_render_device_reset(const SDL_Event &event);

  //   void on_poll_sentinel(const SDL_Event &event);

  //   void on_user_event(const SDL_Event &event);
};
