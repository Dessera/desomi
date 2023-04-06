#include "Resource.hpp"
#include <SDL2/SDL_image.h>

ResourcesManager::~ResourcesManager() {
  for (auto& [path, texture] : textures) {
    SDL_DestroyTexture(texture);
  }
  for (auto& [path, surface] : surfaces) {
    SDL_FreeSurface(surface);
  }
}

SDL_Texture* ResourcesManager::get_texture(const std::string& path) {
	if (textures.find(path) == textures.end()) {
		return nullptr;
	}
	return textures[path];
}

SDL_Surface* ResourcesManager::get_surface(const std::string& path) {
  if (surfaces.find(path) == surfaces.end()) {
    return nullptr;
  }
  return surfaces[path];
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

bool ResourcesManager::load_surface(const std::string& path) {
  if (surfaces.find(path) != surfaces.end()) {
    return false;
  }
  SDL_Surface* surface = IMG_Load(path.c_str());
  if (surface == nullptr) {
    return false;
  }
  surfaces[path] = surface;
  return true;
}

bool ResourcesManager::unload_surface(const std::string& path) {
  if (surfaces.find(path) == surfaces.end()) {
    return false;
  }
  SDL_FreeSurface(surfaces[path]);
  surfaces.erase(path);
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
