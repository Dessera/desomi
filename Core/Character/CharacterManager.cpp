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
      break;
    }
  }
}

void CharacterManager::on_mouse_down(const SDL_Event &event) {
  for (auto *character : characters) {
    character->on_mouse_down(event);
  }
}
