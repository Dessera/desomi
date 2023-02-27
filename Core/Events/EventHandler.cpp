#include "EventHandler.hpp"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_joystick.h>

int EventHandler::handler(CharacterManager& character_manager) {
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    switch (event.type) {
      case SDL_QUIT:
        return 1;
      case SDL_LOCALECHANGED:
        on_locale_changed(event, character_manager);
        break;
      case SDL_CLIPBOARDUPDATE:
        on_clipboard_update(event, character_manager);
        break;
      case SDL_SENSORUPDATE:
        on_sensor_update(event, character_manager);
        break;
      case SDL_APP_TERMINATING:
        on_app_terminating(event, character_manager);
        break;
      case SDL_APP_LOWMEMORY:
        on_app_low_memory(event, character_manager);
        break;
      case SDL_APP_WILLENTERBACKGROUND:
        on_app_will_enter_background(event, character_manager);
        break;
      case SDL_APP_DIDENTERBACKGROUND:
        on_app_did_enter_background(event, character_manager);
        break;
      case SDL_APP_WILLENTERFOREGROUND:
        on_app_will_enter_foreground(event, character_manager);
        break;
      case SDL_APP_DIDENTERFOREGROUND:
        on_app_did_enter_foreground(event, character_manager);
        break;
      case SDL_DISPLAYEVENT:
        on_display_event(event, character_manager);
        break;
      case SDL_WINDOWEVENT:
        on_window_event(event, character_manager);
        break;
      case SDL_SYSWMEVENT:
        on_system_event(event, character_manager);
        break;
      case SDL_KEYMAPCHANGED:
        on_keymap_changed(event, character_manager);
        break;
      case SDL_MOUSEWHEEL:
        on_mouse_wheel(event, character_manager);
        break;
      case SDL_MOUSEBUTTONDOWN:
        on_mouse_down(event, character_manager);
        break;
      case SDL_MOUSEBUTTONUP:
        on_mouse_up(event, character_manager);
        break;
      case SDL_MOUSEMOTION:
        on_mouse_motion(event, character_manager);
        break;
      case SDL_KEYDOWN:
        on_key_down(event, character_manager);
        break;
      case SDL_KEYUP:
        on_key_up(event, character_manager);
        break;
      case SDL_TEXTINPUT:
        on_text_input(event, character_manager);
        break;
      case SDL_TEXTEDITING:
        on_text_editing(event, character_manager);
        break;
      case SDL_JOYAXISMOTION:
        on_joystick_axis_motion(event, character_manager);
        break;
      case SDL_JOYBALLMOTION:
        on_joystick_ball_motion(event, character_manager);
        break;
      case SDL_JOYHATMOTION:
        on_joystick_hat_motion(event, character_manager);
        break;
      case SDL_JOYBUTTONDOWN:
        on_joystick_button_down(event, character_manager);
        break;
      case SDL_JOYBUTTONUP:
        on_joystick_button_up(event, character_manager);
        break;
      case SDL_JOYDEVICEADDED:
        on_joystick_device_added(event, character_manager);
        break;
      case SDL_JOYDEVICEREMOVED:
        on_joystick_device_removed(event, character_manager);
        break;
      case SDL_CONTROLLERAXISMOTION:
        on_controller_axis_motion(event, character_manager);
        break;
      case SDL_CONTROLLERBUTTONDOWN:
        on_controller_button_down(event, character_manager);
        break;
      case SDL_CONTROLLERBUTTONUP:
        on_controller_button_up(event, character_manager);
        break;
      case SDL_CONTROLLERDEVICEADDED:
        on_controller_device_added(event, character_manager);
        break;
      case SDL_CONTROLLERDEVICEREMOVED:
        on_controller_device_removed(event, character_manager);
        break;
      case SDL_CONTROLLERDEVICEREMAPPED:
        on_controller_device_remapped(event, character_manager);
        break;
      case SDL_CONTROLLERTOUCHPADDOWN:
        on_controller_touchpad_down(event, character_manager);
        break;
      case SDL_CONTROLLERTOUCHPADMOTION:
        on_controller_touchpad_motion(event, character_manager);
        break;
      case SDL_CONTROLLERTOUCHPADUP:
        on_controller_touchpad_up(event, character_manager);
        break;
      case SDL_CONTROLLERSENSORUPDATE:
        on_controller_sensor_update(event, character_manager);
        break;
      case SDL_FINGERDOWN:
      case SDL_FINGERUP:
      case SDL_FINGERMOTION:
        on_touch_finger(event, character_manager);
        break;
      case SDL_MULTIGESTURE:
        on_multi_gesture(event, character_manager);
        break;
      case SDL_DOLLARGESTURE:
        on_dollar_gesture(event, character_manager);
        break;
      case SDL_DOLLARRECORD:
        on_dollar_record(event, character_manager);
        break;
      case SDL_DROPFILE:
        on_drop_file(event, character_manager);
        break;
      case SDL_DROPTEXT:
        on_drop_text(event, character_manager);
        break;
      case SDL_DROPBEGIN:
        on_drop_begin(event, character_manager);
        break;
      case SDL_DROPCOMPLETE:
        on_drop_complete(event, character_manager);
        break;
      case SDL_AUDIODEVICEADDED:
        on_audio_device_added(event, character_manager);
        break;
      case SDL_AUDIODEVICEREMOVED:
        on_audio_device_removed(event, character_manager);
        break;
      case SDL_RENDER_TARGETS_RESET:
        on_render_targets_reset(event, character_manager);
        break;
      case SDL_RENDER_DEVICE_RESET:
        on_render_device_reset(event, character_manager);
        break;
      default:
        break;
    }
  }
  return 0;
}
