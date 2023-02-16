#include "Resource.hpp"
#include <SDL2/SDL_image.h>

ResourcesManager::~ResourcesManager() {
  for (auto& [path, texture] : textures) {
    SDL_DestroyTexture(texture);
  }
}

SDL_Texture* ResourcesManager::get_texture(const std::string& path) {
	if (textures.find(path) == textures.end()) {
		return nullptr;
	}
	return textures[path];
}

SDL_Texture* ResourcesManager::operator[](const std::string& path) {
	return get_texture(path);
}

bool ResourcesManager::load_texture(const std::string& path, SDL_Renderer* renderer) {
	if (textures.find(path) != textures.end()) {
		return false;
	}
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr) {
		return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr) {
		return false;
	}
	textures[path] = texture;
	return true;
}

bool ResourcesManager::unload_texture(const std::string& path) {
	if (textures.find(path) == textures.end()) {
		return false;
	}
	SDL_DestroyTexture(textures[path]);
	textures.erase(path);
	return true;
}
