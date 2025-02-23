#pragma once

namespace Kara {
namespace UI {
class IUpdatable {
public:
  virtual void OnUpdate() = 0;
};
} // namespace UI
} // namespace Kara