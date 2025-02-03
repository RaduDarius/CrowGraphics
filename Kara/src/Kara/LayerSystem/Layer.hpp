#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/Event.hpp"

namespace Kara {
namespace LayerSystem {
class KARA_API Layer {
public:
  virtual ~Layer() = default;

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate() {}
  virtual void OnEvent(EventSystem::Event &aEvent) {}
};
} // namespace LayerSystem
} // namespace Kara