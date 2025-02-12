#pragma once

#include "Kara/Log/Logger.hpp"

#define KARA_CLIENT_ERROR(...)                                                 \
  ::Kara::Log::Logger::GetClientLogger()->error(__VA_ARGS__);
#define KARA_CLIENT_WARN(...)                                                  \
  ::Kara::Log::Logger::GetClientLogger()->warn(__VA_ARGS__);
#define KARA_CLIENT_INFO(...)                                                  \
  ::Kara::Log::Logger::GetClientLogger()->info(__VA_ARGS__);
#define KARA_CLIENT_TRACE(...)                                                 \
  ::Kara::Log::Logger::GetClientLogger()->trace(__VA_ARGS__);

#ifdef KARA_ENABLE_ASSERTS
#define KARA_CLIENT_ASSERT(x, ...)                                             \
  {                                                                            \
    if (!(x)) {                                                                \
      KARA_CLIENT_ERROR("Assert Failed: {0}", __VA_ARGS__);                    \
      __debugbreak;                                                            \
    }                                                                          \
  }
#else
#define KARA_CLIENT_ASSERT(x, ...)
#endif