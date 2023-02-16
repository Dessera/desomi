#include "MainWidget.hpp"

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
  // TODO: create character manager
  character_manager = std::make_unique<CharacterManager>();
}

MainWidget::~MainWidget() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int MainWidget::loop() {
  SDL_Event event;
  do {
    render();
  } while (frame_adjust() && event_handler->handler(*character_manager) == 0);
  return 0;
}

void MainWidget::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
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
