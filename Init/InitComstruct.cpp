#include <memory>

#include "Widget/MainWidget.hpp"
#include "init.hpp"

WidgetInit::WidgetInit() : main_widget(new MainWidget(WidgetConfig{})) {}
