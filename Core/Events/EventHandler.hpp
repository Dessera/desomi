#pragma once

#include <SDL2/SDL_events.h>

#include "Character/CharacterManager.hpp"
class EventHandler {
 public:
  EventHandler() = default;
  ~EventHandler() = default;

  EventHandler(const EventHandler&) = delete;
  EventHandler& operator=(const EventHandler&) = delete;
  EventHandler(EventHandler&&) = delete;
  EventHandler& operator=(EventHandler&&) = delete;

  static int handler(CharacterManager& character_manager);

 private:
  static inline void on_quit(const SDL_Event& event,
                             CharacterManager& character_manager) {
    character_manager.on_quit(event);
  }
  static inline void on_locale_changed(const SDL_Event& event,
                                       CharacterManager& character_manager) {
    character_manager.on_locale_changed(event);
  }
  static inline void on_clipboard_update(const SDL_Event& event,
                                         CharacterManager& character_manager) {
    character_manager.on_clipboard_update(event);
  }
  static inline void on_sensor_update(const SDL_Event& event,
                                      CharacterManager& character_manager) {
    character_manager.on_sensor_update(event);
  }

#pragma region App Events
  static inline void on_app_terminating(const SDL_Event& event,
                                        CharacterManager& character_manager) {
    character_manager.on_app_terminating(event);
  }
  static inline void on_app_low_memory(const SDL_Event& event,
                                       CharacterManager& character_manager) {
    character_manager.on_app_low_memory(event);
  }
  static inline void on_app_will_enter_background(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_app_will_enter_background(event);
  }
  static inline void on_app_did_enter_background(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_app_did_enter_background(event);
  }
  static inline void on_app_will_enter_foreground(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_app_will_enter_foreground(event);
  }
  static inline void on_app_did_enter_foreground(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_app_did_enter_foreground(event);
  }
#pragma endregion

#pragma region Window Events
  static inline void on_display_event(const SDL_Event& event,
                                      CharacterManager& character_manager) {
    character_manager.on_display_event(event);
  }
  static inline void on_window_event(const SDL_Event& event,
                                     CharacterManager& character_manager) {
    character_manager.on_window_event(event);
  }
  static inline void on_system_event(const SDL_Event& event,
                                     CharacterManager& character_manager) {
    character_manager.on_system_event(event);
  }
#pragma endregion

#pragma region Keyboard Events
  static inline void on_key_down(const SDL_Event& event,
                                 CharacterManager& character_manager) {
    character_manager.on_key_down(event);
  }
  static inline void on_key_up(const SDL_Event& event,
                               CharacterManager& character_manager) {
    character_manager.on_key_up(event);
  }
  static inline void on_text_editing(const SDL_Event& event,
                                     CharacterManager& character_manager) {
    character_manager.on_text_editing(event);
  }
  static inline void on_text_input(const SDL_Event& event,
                                   CharacterManager& character_manager) {
    character_manager.on_text_input(event);
  }
  static inline void on_keymap_changed(const SDL_Event& event,
                                       CharacterManager& character_manager) {
    character_manager.on_keymap_changed(event);
  }
#pragma endregion

#pragma region Mouse Events
  static inline void on_mouse_down(const SDL_Event& event,
                                   CharacterManager& character_manager) {
    character_manager.on_mouse_down(event);
  }
  static inline void on_mouse_up(const SDL_Event& event,
                                 CharacterManager& character_manager) {
    character_manager.on_mouse_up(event);
  }
  static inline void on_mouse_motion(const SDL_Event& event,
                                     CharacterManager& character_manager) {
    character_manager.on_mouse_motion(event);
  }
  static inline void on_mouse_wheel(const SDL_Event& event,
                                    CharacterManager& character_manager) {
    character_manager.on_mouse_wheel(event);
  }
#pragma endregion

#pragma region Joystick Events
  static inline void on_joystick_axis_motion(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_axis_motion(event);
  }
  static inline void on_joystick_ball_motion(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_ball_motion(event);
  }
  static inline void on_joystick_hat_motion(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_hat_motion(event);
  }
  static inline void on_joystick_button_down(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_button_down(event);
  }
  static inline void on_joystick_button_up(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_button_up(event);
  }
  static inline void on_joystick_device_added(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_device_added(event);
  }
  static inline void on_joystick_device_removed(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_joystick_device_removed(event);
  }
#pragma endregion

#pragma region Game Controller Events
  static inline void on_controller_axis_motion(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_axis_motion(event);
  }
  static inline void on_controller_button_down(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_button_down(event);
  }
  static inline void on_controller_button_up(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_button_up(event);
  }
  static inline void on_controller_device_added(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_device_added(event);
  }
  static inline void on_controller_device_removed(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_device_removed(event);
  }
  static inline void on_controller_device_remapped(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_device_remapped(event);
  }
  static inline void on_controller_touchpad_down(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_touchpad_down(event);
  }
  static inline void on_controller_touchpad_up(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_touchpad_up(event);
  }
  static inline void on_controller_touchpad_motion(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_touchpad_motion(event);
  }
  static inline void on_controller_sensor_update(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_controller_sensor_update(event);
  }
#pragma endregion

#pragma region Touch Events
  static inline void on_touch_finger(const SDL_Event& event,
                                     CharacterManager& character_manager) {
    character_manager.on_touch_finger(event);
  }
  static inline void on_multi_gesture(const SDL_Event& event,
                                      CharacterManager& character_manager) {
    character_manager.on_multi_gesture(event);
  }
  static inline void on_dollar_gesture(const SDL_Event& event,
                                       CharacterManager& character_manager) {
    character_manager.on_dollar_gesture(event);
  }
  static inline void on_dollar_record(const SDL_Event& event,
                                      CharacterManager& character_manager) {
    character_manager.on_dollar_record(event);
  }
#pragma endregion

#pragma region Drop Events
  static inline void on_drop_file(const SDL_Event& event,
                                  CharacterManager& character_manager) {
    character_manager.on_drop_file(event);
  }
  static inline void on_drop_text(const SDL_Event& event,
                                  CharacterManager& character_manager) {
    character_manager.on_drop_text(event);
  }
  static inline void on_drop_begin(const SDL_Event& event,
                                   CharacterManager& character_manager) {
    character_manager.on_drop_begin(event);
  }
  static inline void on_drop_complete(const SDL_Event& event,
                                      CharacterManager& character_manager) {
    character_manager.on_drop_complete(event);
  }
#pragma endregion

  static inline void on_audio_device_added(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_audio_device_added(event);
  }
  static inline void on_audio_device_removed(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_audio_device_removed(event);
  }

  static inline void on_render_targets_reset(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_render_targets_reset(event);
  }
  static inline void on_render_device_reset(
      const SDL_Event& event, CharacterManager& character_manager) {
    character_manager.on_render_device_reset(event);
  }

  //   void on_poll_sentinel(const SDL_Event& event,
  // CharacterManager& character_manager);

  //   void on_user_event(const SDL_Event& event,
  // CharacterManager& character_manager);
};
