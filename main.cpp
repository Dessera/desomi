#include <iostream>

#include "Init/init.hpp"
#include "Widget/MainWidget.hpp"

int main() {
  auto widget = MainWidget(WidgetConfig{});
  WidgetInit(widget);
  return widget.loop();
}
