#include <memory>
#include "Draggable.hpp"
#include "Widget/MainWidget.hpp"

class WidgetInit {
 private:
 std::unique_ptr<MainWidget> main_widget;

 public:
  WidgetInit();
  ~WidgetInit() = default;

  int init();
};