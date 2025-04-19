#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/UI/Components/Desktop.hpp"
#include "Kara/UI/Component.hpp"

#include <type_traits>

namespace Kara {
namespace UI {
class ComponentManager {
public:
  ComponentManager(const ComponentManager &) = delete;
  ComponentManager &operator=(const ComponentManager &) = delete;
  ComponentManager(ComponentManager &&) = delete;
  ComponentManager &operator=(ComponentManager &&) = delete;

  static ComponentManager *Get();

  //! @brief This template should be used to create any UI component. Elements
  //! that are not created via this API will not be handled by the component
  //! system, so they will not be rendered at all.
  //! @tparam C MUST be a component subclass.
  //! @param aRect is used to now the position and dimension of the component
  //! that the consumer wants to render on the screen.
  //! @param ...aArgs will be forwarded to the C::Params in order to pass
  //! parameter to needed at the creation step of the UI component.
  //! @return a Ref to the created UI element for the consumer to make updates
  //! to it if needed.
  template <class C, typename... Args>
  static C *CreateComponent(Component *aParent, const Rect &aRect,
                            Args... aArgs) {
    return Get()->CreateComponentImpl<C>(aParent, aRect,
                                         std::forward<Args>(aArgs)...);
  }

  void CreateRootComponent();

  void Render();

private:
  ComponentManager() = default;

  template <class C, typename... Args>
  C *CreateComponentImpl(Component *aParent, const Rect &aRect, Args... aArgs) {
    static_assert(std::is_base_of<Component, C>::value,
                  "C must be an UI Component.");

    typename C::Params params{std::forward<Args>(aArgs)...};
    C *component = new C(aParent, aRect, params);
    if (aParent) {
      aParent->AddChild(component);
    }

    return component;
  }

  static ComponentManager *smInstance;

  //! Desktop is root of the all UI tree, so it must have a special handling.
  Core::Scope<Desktop> mDesktop;
};
} // namespace UI
} // namespace Kara