#include "MainWidget.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>

#include <exception>
#include <iostream>

MainWidget::MainWidget(const WidgetConfig& config) : config(config) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw std::runtime_error("SDL_Init failed: " + std::string(SDL_GetError()));
  }
  window =
      SDL_CreateWindow("Widget", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       config.width, config.height, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    throw std::runtime_error("SDL_CreateWindow failed: " +
                             std::string(SDL_GetError()));
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    throw std::runtime_error("SDL_CreateRenderer failed: " +
                             std::string(SDL_GetError()));
  }

  resources_manager = std::make_unique<ResourcesManager>();
  event_handler = std::make_unique<EventHandler>();
  character_manager = std::make_unique<CharacterManager>();
}

MainWidget::~MainWidget() {
  SDL_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_FreeCursor(cursor);
}

int MainWidget::loop() {
  do {
    render();
  } while (frame_adjust() && event_handler->handler(*character_manager) == 0);
  return 0;
}

void MainWidget::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  character_manager->render(renderer);

  SDL_RenderPresent(renderer);
}

bool MainWidget::frame_adjust() const {
  static uint32_t prev = SDL_GetTicks();
  uint32_t cost = SDL_GetTicks() - prev;
  uint32_t frame_expected = 1000 / config.frame_time;
  if (frame_expected > cost) {
    SDL_Delay(frame_expected - cost);
  }
  prev = SDL_GetTicks();
  return true;
}

void MainWidget::set_cursor(const std::string& path) {
  SDL_Surface* surface = resources_manager->get_surface(path);
  SDL_Cursor* cursor = SDL_CreateColorCursor(surface, 0, 0);
  SDL_SetCursor(cursor);
}

void MainWidget::add_character(Character* character) {
  character_manager->add_character(character);
  auto path = character->get_path();
  if (path.empty()) {
    return;
  }
  auto* texture = resources_manager->get_texture(path);
  if (texture == nullptr) {
    return;
  }
  character->set_texture(texture);
}

void MainWidget::load_texture(const std::string& path) {
  resources_manager->load_texture(path, renderer);
}
