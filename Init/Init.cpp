#include "init.hpp"

#include "Draggable.hpp"

// User code begins here
int WidgetInit::init() {
  // Create a DraggableWidget
  auto *draggable_widget = new Draggable();
  main_widget->add_character(draggable_widget);

  main_widget->loop();
  return 0;
}