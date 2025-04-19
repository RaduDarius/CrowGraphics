#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Core/Types.hpp"
#include "Kara/Graphics/Material.hpp"
#include "Kara/UI/Utils.hpp"

#include <functional>
#include <vector>

namespace Kara {
namespace UI {
class Component {
public:
  using ComponentRef = Component *;
  using TraverseFunc = std::function<void(Component &)>;
  struct Params {};

  Component(const ComponentRef aParent, const Rect &aRect,
            const Params &aParams);

  //! Public APIs
  inline Rect GetRect() const { return mRect; }
  inline Core::Size GetSize() const { return mRect.GetSize(); }

  //! ComponentManager related APIs
  void AddChild(ComponentRef aChild);
  void RemoveChild(const ComponentRef aChild);
  void TraverseReverse(const TraverseFunc &aFunc);

  inline void SetParent(const ComponentRef aParent) { mParent = aParent; }

  virtual void OnRender();

  inline void SetColor(const Graphics::Color &aColor) {
    mMaterial->SetColor(aColor);
  }
  inline void MakeTransparent() { mMaterial->MakeTransparent(); }

private:
  // Structural Data
  ComponentRef mParent;
  std::vector<ComponentRef> mChildren;

  // Data Properties
  Rect mRect;
  Core::Ref<Graphics::Material> mMaterial;
};
} // namespace UI
} // namespace Kara