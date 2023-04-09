
#include "core/renderer/api/sdl_api.hpp"

#include "core/utils/color.hpp"

using desomi::core::render::SDL_RenderAPI;
using color = desomi::core::utils::Color;

void SDL_RenderAPI::clear() { SDL_RenderClear(renderer_.get()); }

void SDL_RenderAPI::present() { SDL_RenderPresent(renderer_.get()); }

void SDL_RenderAPI::flush() { SDL_RenderFlush(renderer_.get()); }

uint32_t SDL_RenderAPI::get_driver_count() { return SDL_GetNumRenderDrivers(); }

void SDL_RenderAPI::set_draw_color(const utils::Color& color_) {
  SDL_SetRenderDrawColor(renderer_.get(), color_.red(), color_.green(),
                         color_.blue(), color_.alpha());
}
void SDL_RenderAPI::default_draw_color() {
  SDL_SetRenderDrawColor(renderer_.get(), 255, 255, 255, 255);
}

color SDL_RenderAPI::get_draw_color() {
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
  uint8_t a = 0;
  SDL_GetRenderDrawColor(renderer_.get(), &r, &g, &b, &a);
  return utils::Color(r, g, b, a);
}

void SDL_RenderAPI::draw_point(int x_, int y_) {
  SDL_RenderDrawPoint(renderer_.get(), x_, y_);
}

void SDL_RenderAPI::draw_line(int x1_, int y1_, int x2_, int y2_) {
  SDL_RenderDrawLine(renderer_.get(), x1_, y1_, x2_, y2_);
}

void SDL_RenderAPI::draw_rect(const utils::Rect& rect_) {
  auto rect = rect_.sdl_rect();
  SDL_RenderDrawRect(renderer_.get(), &rect);
}

void SDL_RenderAPI::draw_rects(const std::vector<utils::Rect>& rects_) {
  std::vector<SDL_Rect> sdl_rects;
  sdl_rects.reserve(rects_.size());
  for (const auto& rect : rects_) {
    sdl_rects.push_back(rect.sdl_rect());
  }
  SDL_RenderDrawRects(renderer_.get(), sdl_rects.data(),
                      static_cast<int>(sdl_rects.size()));
}

void SDL_RenderAPI::fill_rect(const utils::Rect& rect_) {
  auto rect = rect_.sdl_rect();
  SDL_RenderFillRect(renderer_.get(), &rect);
}

void SDL_RenderAPI::fill_rects(const std::vector<utils::Rect>& rects_) {
  std::vector<SDL_Rect> sdl_rects;
  sdl_rects.reserve(rects_.size());
  for (const auto& rect : rects_) {
    sdl_rects.push_back(rect.sdl_rect());
  }
  SDL_RenderFillRects(renderer_.get(), sdl_rects.data(),
                      static_cast<int>(sdl_rects.size()));
}
