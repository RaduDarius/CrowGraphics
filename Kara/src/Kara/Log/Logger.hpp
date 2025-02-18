#pragma once

#include "spdlog/spdlog.h"

#include <memory>

namespace Kara {
namespace Log {
class Logger {
public:
  static void Init();

  static std::shared_ptr<spdlog::logger> &GetClientLogger() {
    return smClientLogger;
  }
  static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
    return smCoreLogger;
  }

private:
  static std::shared_ptr<spdlog::logger> smClientLogger;
  static std::shared_ptr<spdlog::logger> smCoreLogger;
};
} // namespace Log
} // namespace Kara

#define KARA_CORE_ERROR(...)                                                   \
  ::Kara::Log::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define KARA_CORE_WARN(...)                                                    \
  ::Kara::Log::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define KARA_CORE_INFO(...)                                                    \
  ::Kara::Log::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define KARA_CORE_TRACE(...)                                                   \
  ::Kara::Log::Logger::GetCoreLogger()->trace(__VA_ARGS__);

#ifdef KARA_ENABLE_ASSERTS
#define KARA_CORE_ASSERT(x, ...)                                               \
  {                                                                            \
    if (!(x)) {                                                                \
      KARA_CORE_ERROR("Assert Failed: {0}", __VA_ARGS__);                      \
      __debugbreak();                                                          \
    }                                                                          \
  }
#else
#define KARA_CORE_ASSERT(x, ...)
#endif