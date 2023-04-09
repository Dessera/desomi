
#include "core/node/interface/node.hpp"
#include "core/utils/color.hpp"
#include "core/utils/rect.hpp"

namespace desomi::core::node {

class Root final : public interfaces::Inode {
 private:
  utils::rect viewport_;

 public:
  explicit Root(utils::rect viewport) : viewport_(viewport) {}

  ~Root() final = default;
  void render(interfaces::IrendererAPI* renderer) final;

  Root(const Root&) = delete;
  Root& operator=(const Root&) = delete;
  Root(Root&&) = delete;
  Root& operator=(Root&&) = delete;
};

}  // namespace desomi::core::node