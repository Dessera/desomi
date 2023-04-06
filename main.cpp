#include <SDL2/SDL_events.h>

#include <functional>
#include <iostream>
#include <memory>

#include "object/element.hpp"
#include "window/window.hpp"

int main() {
  Window win;
  win.load_texture("./assets/avatar.png");
  auto element = std::make_shared<WindowElement>();
  element->set_texture_path("./assets/avatar.png");

  bool enable_drag = false;
  int original_offset_x = 0;
  int original_offset_y = 0;

  win.add_element(element);

  win.event_register(
      SDL_MOUSEBUTTONDOWN, [element, &enable_drag, &original_offset_x,
                            &original_offset_y](SDL_Event& event) {
        enable_drag = true;
        original_offset_x = event.button.x - element->get_rect().x;
        original_offset_y = event.button.y - element->get_rect().y;
      });

  win.event_register(
      SDL_MOUSEBUTTONUP,
      [element, &enable_drag](SDL_Event& /*event*/) { enable_drag = false; });

  win.event_register(
      SDL_MOUSEMOTION, [element, &enable_drag, &original_offset_x,
                        &original_offset_y](SDL_Event& event) {
        if (enable_drag) {
          element->set_rect({event.motion.x - original_offset_x,
                             event.motion.y - original_offset_y,
                             element->get_rect().w, element->get_rect().h});
        }
      });

  return win.run();
}
