#pragma once

#include "Kara/Core/Core.hpp"
#include "spdlog/spdlog.h"

namespace Kara {
namespace Log {
class KARA_API Logger {
 public:
  static void Init();

  static std::shared_ptr<spdlog::logger>& GetClientLogger() {
    return smClientLogger;
  }
  static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
    return smCoreLogger;
  }

 private:
  static std::shared_ptr<spdlog::logger> smClientLogger;
  static std::shared_ptr<spdlog::logger> smCoreLogger;
};
}  // namespace Log
}  // namespace Kara

#define KARA_CORE_ERROR(...) \
  ::Kara::Log::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define KARA_CORE_WARN(...) \
  ::Kara::Log::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define KARA_CORE_INFO(...) \
  ::Kara::Log::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define KARA_CORE_TRACE(...) \
  ::Kara::Log::Logger::GetCoreLogger()->trace(__VA_ARGS__);
