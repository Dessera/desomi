#include "Character/Character.hpp"
#include "Widget/MainWidget.hpp"
void WidgetInit(MainWidget& widget) {
  auto* character = new Character();
  widget.get_character_manager()->add_character(character);
}