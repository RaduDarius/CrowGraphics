#include "pch.hpp"

#include "Window.hpp"

#include "Kara/Log/Logger.hpp"

namespace Kara {
namespace Core {
Window::~Window() { delete mContext; }

void Window::SetContext(Context *aContext) {
  // Preconditions
  KARA_CORE_ASSERT(aContext,
                   "Preconditions unsatisfied: aContext argument is NULL!");
  KARA_CORE_ASSERT(!mContext, "There is already a context set ! We support "
                              "only one context per window !");
  mContext = aContext;
}
} // namespace Core
} // namespace Kara