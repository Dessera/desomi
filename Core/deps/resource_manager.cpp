#include <SDL2/SDL_image.h>

#include <cstddef>
#include <error/error.hpp>

#include "resource/manager.hpp"

void ResourceManager::load_texture(const std::string &path,
                                   SDL_Renderer *renderer) {
  if (textures.find(path) != textures.end()) {
    return;
  }

  SharedTexture texture =
      SharedTexture(IMG_LoadTexture(renderer, path.c_str()),
                    [](SDL_Texture *texture) { SDL_DestroyTexture(texture); });

  if (texture == nullptr) {
    throw WindowException("Failed to create texture from surface");
  }

  textures[path] = texture;
}

void ResourceManager::load_surface(const std::string &path) {
  if (surfaces.find(path) != surfaces.end()) {
    return;
  }

  SharedSurface surface =
      SharedSurface(IMG_Load(path.c_str()),
                    [](SDL_Surface *surface) { SDL_FreeSurface(surface); });

  if (surface == nullptr) {
    throw WindowException("Failed to load surface");
  }

  surfaces[path] = surface;
}

ResourceManager::SharedTexture ResourceManager::get_texture(
    const std::string &path) {
  if (textures.find(path) == textures.end()) {
    throw WindowException("Texture not found");
  }

  return textures[path];
}

ResourceManager::SharedSurface ResourceManager::get_surface(
    const std::string &path) {
  if (surfaces.find(path) == surfaces.end()) {
    throw WindowException("Surface not found");
  }

  return surfaces[path];
}
