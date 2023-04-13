#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <memory>

#include "core/renderer/interfaces/render_api.hpp"
#include "core/renderer/interfaces/renderer.hpp"
#include "core/window/window.hpp"

namespace desomi::core::render {

class SDL_RenderAPI final : public interfaces::IrendererAPI {
 private:
  using SDL_RendererDeleter = struct rdeleter {
    void operator()(SDL_Renderer* renderer) const {
      SDL_DestroyRenderer(renderer);
    }
  };

  using SDL_WindowDeleter = struct wdeleter {
    void operator()(SDL_Window* window) const { SDL_DestroyWindow(window); }
  };

  std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> renderer_;
  std::unique_ptr<SDL_Window, SDL_WindowDeleter> window_;

 public:
  explicit SDL_RenderAPI(const core::Window::WindowConfig& config_);
  ~SDL_RenderAPI() final { SDL_Quit(); };

  SDL_RenderAPI(const SDL_RenderAPI&) = delete;
  SDL_RenderAPI(SDL_RenderAPI&&) = delete;
  SDL_RenderAPI& operator=(const SDL_RenderAPI&) = delete;
  SDL_RenderAPI& operator=(SDL_RenderAPI&&) = delete;

  void clear() final;
  void present() final;
  void flush() final;

  uint32_t get_driver_count() final;
  void set_draw_color(const utils::Color& color_) final;
  void default_draw_color() final;
  utils::Color get_draw_color() final;

  void draw_point(int x_, int y_) final;
  void draw_line(int x1_, int y1_, int x2_, int y2_) final;

  void draw_rect(const utils::Rect& rect_) final;
  void draw_rects(const std::vector<utils::Rect>& rects_) final;

  void fill_rect(const utils::Rect& rect_) final;
  void fill_rects(const std::vector<utils::Rect>& rects_) final;
};

}  // namespace desomi::core::render