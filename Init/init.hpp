#pragma once
#include "Widget/MainWidget.hpp"
#include <memory>

class WidgetInit {
 private:
 std::unique_ptr<MainWidget> main_widget;

 public:
  WidgetInit();
  ~WidgetInit() = default;

  int init();
};