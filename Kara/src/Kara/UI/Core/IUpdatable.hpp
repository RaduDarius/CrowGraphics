#pragma once

namespace Kara {
namespace UI {
namespace Core {
class IUpdatable {
public:
  virtual void OnUpdate() = 0;
};
} // namespace Core
} // namespace UI
} // namespace Kara