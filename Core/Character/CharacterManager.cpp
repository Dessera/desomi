#include "CharacterManager.hpp"

CharacterManager::~CharacterManager() {
  for (auto *character : characters) {
    delete character;
  }
}

void CharacterManager::render(SDL_Renderer *renderer) {
  for (auto *character : characters) {
    character->render(renderer);
  }
}

void CharacterManager::add_character(Character *character) {
  characters.push_back(character);
}

void CharacterManager::remove_character(Character *character) {
  for (auto it = characters.begin(); it != characters.end(); ++it) {
    if (*it == character) {
      characters.erase(it);
      delete character;
      break;
    }
  }
}

void CharacterManager::on_mouse_down(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_mouse_down(event)) {
      break;
    }
  }
}

void CharacterManager::on_mouse_up(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_mouse_up(event)) {
      break;
    }
  }
}

void CharacterManager::on_mouse_motion(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_mouse_motion(event)) {
      break;
    }
  }
}

void CharacterManager::on_quit(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_quit(event)) {
      break;
    }
  }
}

void CharacterManager::on_locale_changed(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_locale_changed(event)) {
      break;
    }
  }
}

void CharacterManager::on_clipboard_update(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_clipboard_update(event)) {
      break;
    }
  }
}

void CharacterManager::on_sensor_update(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_sensor_update(event)) {
      break;
    }
  }
}

void CharacterManager::on_app_terminating(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_app_terminating(event)) {
      break;
    }
  }
}

void CharacterManager::on_app_low_memory(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_app_low_memory(event)) {
      break;
    }
  }
}

void CharacterManager::on_app_will_enter_background(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_app_will_enter_background(event)) {
      break;
    }
  }
}

void CharacterManager::on_app_did_enter_background(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_app_did_enter_background(event)) {
      break;
    }
  }
}

void CharacterManager::on_app_will_enter_foreground(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_app_will_enter_foreground(event)) {
      break;
    }
  }
}

void CharacterManager::on_app_did_enter_foreground(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_app_did_enter_foreground(event)) {
      break;
    }
  }
}

void CharacterManager::on_display_event(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_display_event(event)) {
      break;
    }
  }
}

void CharacterManager::on_window_event(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_window_event(event)) {
      break;
    }
  }
}

void CharacterManager::on_system_event(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_system_event(event)) {
      break;
    }
  }
}

void CharacterManager::on_key_down(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_key_down(event)) {
      break;
    }
  }
}

void CharacterManager::on_key_up(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_key_up(event)) {
      break;
    }
  }
}

void CharacterManager::on_text_editing(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_text_editing(event)) {
      break;
    }
  }
}

void CharacterManager::on_text_input(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_text_input(event)) {
      break;
    }
  }
}

void CharacterManager::on_keymap_changed(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_keymap_changed(event)) {
      break;
    }
  }
}

void CharacterManager::on_mouse_wheel(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_mouse_wheel(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_axis_motion(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_axis_motion(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_ball_motion(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_ball_motion(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_hat_motion(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_hat_motion(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_button_down(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_button_down(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_button_up(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_button_up(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_device_added(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_device_added(event)) {
      break;
    }
  }
}

void CharacterManager::on_joystick_device_removed(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_joystick_device_removed(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_axis_motion(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_axis_motion(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_button_down(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_button_down(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_button_up(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_button_up(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_device_added(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_device_added(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_device_removed(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_device_removed(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_device_remapped(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_device_remapped(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_touchpad_down(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_touchpad_down(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_touchpad_motion(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_touchpad_motion(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_touchpad_up(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_touchpad_up(event)) {
      break;
    }
  }
}

void CharacterManager::on_controller_sensor_update(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_controller_sensor_update(event)) {
      break;
    }
  }
}

void CharacterManager::on_touch_finger(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_touch_finger(event)) {
      break;
    }
  }
}

void CharacterManager::on_multi_gesture(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_multi_gesture(event)) {
      break;
    }
  }
}

void CharacterManager::on_dollar_gesture(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_dollar_gesture(event)) {
      break;
    }
  }
}

void CharacterManager::on_dollar_record(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_dollar_record(event)) {
      break;
    }
  }
}

void CharacterManager::on_drop_file(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_drop_file(event)) {
      break;
    }
  }
}

void CharacterManager::on_drop_text(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_drop_text(event)) {
      break;
    }
  }
}

void CharacterManager::on_drop_begin(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_drop_begin(event)) {
      break;
    }
  }
}

void CharacterManager::on_drop_complete(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_drop_complete(event)) {
      break;
    }
  }
}

void CharacterManager::on_audio_device_added(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_audio_device_added(event)) {
      break;
    }
  }
}

void CharacterManager::on_audio_device_removed(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_audio_device_removed(event)) {
      break;
    }
  }
}

void CharacterManager::on_render_targets_reset(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_render_targets_reset(event)) {
      break;
    }
  }
}

void CharacterManager::on_render_device_reset(const SDL_Event &event) {
  for (auto *character : characters) {
    if (!character->on_render_device_reset(event)) {
      break;
    }
  }
}
