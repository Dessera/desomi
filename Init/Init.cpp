#include "init.hpp"

#include "Draggable.hpp"

// User code begins here
int WidgetInit::init() {
  // Resources
  main_widget->load_texture("/home/dessera/Pictures/Icons/cpp.png");
  // Create a DraggableWidget
  auto *draggable_widget = new Draggable();
  draggable_widget->get_path() = "/home/dessera/Pictures/Icons/cpp.png";
  draggable_widget->get_rotate_speed() = 0.5;

  auto *draggable_widget2 = new Draggable{*draggable_widget};

  main_widget->add_character(draggable_widget);
  main_widget->add_character(draggable_widget2);

  return main_widget->loop();
}