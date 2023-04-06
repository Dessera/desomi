#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#define DEFINE_DELETER(name, raw_type, deleter)            \
  struct name {                                            \
    void operator()(raw_type* ptr) const { deleter(ptr); } \
  };

DEFINE_DELETER(SDL_WindowDeleter, SDL_Window, SDL_DestroyWindow)
DEFINE_DELETER(SDL_RendererDeleter, SDL_Renderer, SDL_DestroyRenderer)
