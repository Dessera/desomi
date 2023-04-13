#include "core/plugins/templates/vsync.hpp"

using desomi::core::plugins::VeriticalVsyncController;

void VeriticalVsyncController::on_window_run() { enable(); }

void VeriticalVsyncController::on_frame_end() { wait(); }
