#pragma once

#if KARA_PLATFORM_WINDOWS
#ifdef KARA_BUILD_DLL
#define KARA_API __declspec(dllexport)
#else
#define KARA_API __declspec(dllimport)
#endif
#else
#error Only windows support available !
#endif // KR_PLATFORM_WINDOWS

#include <memory>

namespace Kara {
namespace Core {
template <typename T> using Scope = std::unique_ptr<T>;

template <typename T> using Ref = std::shared_ptr<T>;
} // namespace Core
} // namespace Kara
