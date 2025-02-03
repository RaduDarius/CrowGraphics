#pragma once

#include "pch.hpp"

#if KARA_PLATFORM_WINDOWS
#ifdef KARA_BUILD_DLL
#define KARA_API __declspec(dllexport)
#else
#define KARA_API __declspec(dllimport)
#endif
#else
#error Only windows support available !
#endif  // KR_PLATFORM_WINDOWS
