#pragma once

#include "core/node/interface/node.hpp"
#include "core/utils/color.hpp"
#include "core/utils/create.hpp"
#include "core/utils/rect.hpp"

namespace desomi::core::node {

class Root final : public interfaces::Inode,
                   public utils::UseSharedCreate<Root> {
 private:
  utils::Rect viewport_;

 public:
  Root(int32_t width, int32_t height) : viewport_(0, 0, width, height) {}

  ~Root() final = default;
  void render(interfaces::IrendererAPI* renderer) final;

  Root(const Root&) = delete;
  Root& operator=(const Root&) = delete;
  Root(Root&&) = delete;
  Root& operator=(Root&&) = delete;
};

}  // namespace desomi::core::node