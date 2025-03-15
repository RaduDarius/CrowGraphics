#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/UI/RenderObject.hpp"
#include "Kara/UI/Utils.hpp"

#include <glm/glm.hpp>

#include <set>

namespace Kara {
namespace UI {
class Component {
public:
  using ComponentRef = Core::Ref<Component>;

  struct Params {};

  Component(const ComponentRef aParent, const Rect &aRect,
            const Params &aParams);

  inline Core::Ref<Component> Self() {
    return std::make_shared<Component>(*this);
  }

  //! ComponentManager related APIs
  Core::Ref<RenderObject> GetRenderProp() { return mRenderProp; };

  void AddChild(const ComponentRef aChild);
  void RemoveChild(const ComponentRef aChild);

  inline void SetParent(const ComponentRef aParent) { mParent = aParent; }

  //! @brief Graphics primitives APIs
  inline void SetColor(const glm::vec4 &aColor) { mRenderProp->Color = aColor; }

private:
  void SetupRenderPrimitives();

  // Structural Data
  ComponentRef mParent;
  std::vector<ComponentRef> mChildren;

  // Data Properties
  Rect mRect;

  // Render Properties
  Core::Ref<RenderObject> mRenderProp;
};
} // namespace UI
} // namespace Kara