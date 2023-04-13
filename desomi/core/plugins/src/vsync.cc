#include "core/plugins/templates/vsync.hpp"

using desomi::core::plugins::VeriticalVsyncController;

void VeriticalVsyncController::on_window_run(
    interfaces::Inode::node_ptr& /*root*/) {
  enable();
}

void VeriticalVsyncController::on_frame_end(
    interfaces::Inode::node_ptr& /*root*/) {
  wait();
}
