#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/EventSystem/Event.hpp"

namespace Kara {
namespace LayerSystem {
class KARA_API Layer {
public:
  Layer() = default;
  Layer(const std::string &aName) : mName{aName} {}
  virtual ~Layer() = default;

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate() {}
  virtual void OnRender() {}
  virtual void OnEvent(EventSystem::Event &aEvent) {}

private:
  std::string mName{"Layer"};
};
} // namespace LayerSystem
} // namespace Kara