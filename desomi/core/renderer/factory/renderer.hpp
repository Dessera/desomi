#pragma once

#include <memory>

#include "core/renderer/interfaces/renderer.hpp"

template <typename T, typename A>
class RendererFactory {
 private:
  using Irenderer = desomi::core::interfaces::Irenderer;

 public:
  static inline std::unique_ptr<Irenderer> create(auto... args) {
    A* api = new A(args...);
    return std::make_unique<T>(api);
  }
};