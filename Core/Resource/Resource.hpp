#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <string>
#include <unordered_map>

/**
 * @brief Resources Manager class for loading and unloading textures
 *
 */
class ResourcesManager {
 private:
  std::unordered_map<std::string, SDL_Texture*> textures{};

 public:
  ResourcesManager() = default;
  ~ResourcesManager();

  ResourcesManager(const ResourcesManager&) = delete;
  ResourcesManager& operator=(const ResourcesManager&) = delete;
  ResourcesManager(ResourcesManager&&) = delete;
  ResourcesManager& operator=(ResourcesManager&&) = delete;

  SDL_Texture* get_texture(const std::string& path);
  SDL_Texture* operator[](const std::string& path);
  bool load_texture(const std::string& path, SDL_Renderer* renderer);
  bool unload_texture(const std::string& path);
};
