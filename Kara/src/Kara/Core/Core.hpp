#pragma once

#if KR_PLATFORM_WINDOWS
#ifdef KR_BUILD_DLL
#define KARA_API __declspec(dllexport)
#else
#define KARA_API __declspec(dllimport)
#endif
#else
#error Only windows support available !
#endif // KR_PLATFORM_WINDOWS
