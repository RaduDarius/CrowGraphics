#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Events/Event.hpp"

namespace Kara {
namespace Layers {
class Layer {
public:
  Layer() = default;
  Layer(const std::string &aName) : mName{aName} {}
  virtual ~Layer() = default;

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate() {}
  virtual void OnRender() {}
  virtual void OnEvent(Events::Event &aEvent) {}

private:
  std::string mName{"Layer"};
};
} // namespace Layers
} // namespace Kara