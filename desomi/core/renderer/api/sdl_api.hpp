#pragma once

#include <SDL2/SDL_render.h>

#include <memory>

#include "core/renderer/interfaces/render_api.hpp"
#include "core/renderer/interfaces/renderer.hpp"

namespace desomi::core::render {

class SDL_RenderAPI final : public interfaces::IrendererAPI {
 private:
  using SDL_RendererDeleter = struct rdeleter {
    void operator()(SDL_Renderer* renderer) const {
      SDL_DestroyRenderer(renderer);
    }
  };

  std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> renderer_;

 public:
  explicit SDL_RenderAPI(SDL_Renderer* renderer) : renderer_(renderer) {}
  ~SDL_RenderAPI() final = default;

  SDL_RenderAPI(const SDL_RenderAPI&) = delete;
  SDL_RenderAPI(SDL_RenderAPI&&) = delete;
  SDL_RenderAPI& operator=(const SDL_RenderAPI&) = delete;
  SDL_RenderAPI& operator=(SDL_RenderAPI&&) = delete;

  void clear() final;
  void present() final;
  void flush() final;

  uint32_t get_driver_count() final;
  void set_draw_color(const utils::color& color_) final;
  utils::color get_draw_color() final;

  void draw_point(int x_, int y_) final;
  void draw_line(int x1_, int y1_, int x2_, int y2_) final;

  void draw_rect(const utils::rect& rect_) final;
  void draw_rects(const std::vector<utils::rect>& rects_) final;

  void fill_rect(const utils::rect& rect_) final;
  void fill_rects(const std::vector<utils::rect>& rects_) final;
};

}  // namespace desomi::core::render