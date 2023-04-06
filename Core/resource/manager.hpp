#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils/class_modify.hpp"

class ResourceManager {
 public:
  using SharedTexture = std::shared_ptr<SDL_Texture>;
  using SharedSurface = std::shared_ptr<SDL_Surface>;

  DELETE_COPY_AND_MOVE(ResourceManager);

 private:
  std::unordered_map<std::string, SharedSurface> surfaces;
  std::unordered_map<std::string, SharedTexture> textures;

 public:
  ResourceManager() = default;
  ~ResourceManager() = default;

  void load_texture(const std::string& path, SDL_Renderer* renderer);
  void load_surface(const std::string& path);

  SharedTexture get_texture(const std::string& path);
  SharedSurface get_surface(const std::string& path);
};
