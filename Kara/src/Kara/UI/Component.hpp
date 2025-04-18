#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Types.hpp"
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

  //! Public APIs
  inline Rect GetRect() const { return mRect; }
  inline Core::Size GetSize() const { return mRect.GetSize(); }

  //! ComponentManager related APIs
  const Core::Ref<RenderObject> &GetRenderProp() const { return mRenderProp; };

  void AddChild(const ComponentRef aChild);
  void RemoveChild(const ComponentRef aChild);

  inline void SetParent(const ComponentRef aParent) { mParent = aParent; }

  //! @brief Graphics primitives APIs
  inline void SetColor(const glm::vec4 &aColor) {
    mRenderProp->Material->SetColor(aColor);
  }

protected:
  void SetRenderPropMaterial(const Core::Ref<Graphics::Material> &aMaterial) {
    mRenderProp->Material = aMaterial;
  }

  // Render Properties
  Core::Ref<RenderObject> mRenderProp;

private:
  void SetupRenderPrimitives();

  // Structural Data
  ComponentRef mParent;
  std::vector<ComponentRef> mChildren;

  // Data Properties
  Rect mRect;
};
} // namespace UI
} // namespace Kara