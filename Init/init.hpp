#include "Draggable.hpp"
#include "Widget/MainWidget.hpp"
void WidgetInit(MainWidget& widget) {
  auto* character = new Draggable();
  widget.get_character_manager()->add_character(character);
}