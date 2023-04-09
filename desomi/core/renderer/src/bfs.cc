#include "core/renderer/template/bfs.hpp"

using desomi::core::render::RendererBFS;

void RendererBFS::render(interfaces::Inode* node) {
  renderer_api_->clear();
  render_queue_.push(node);
  while (!render_queue_.empty()) {
    auto* current_node = render_queue_.front();
    render_queue_.pop();

    current_node->render(renderer_api_.get());
    for (auto& child : current_node->children()) {
      render_queue_.push(child.get());
    }
  }
  renderer_api_->present();
}
