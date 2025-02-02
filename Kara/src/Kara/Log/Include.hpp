#pragma once

#include "Kara/Log/Logger.hpp"

#define KARA_CLIENT_ERROR(...) \
  ::Kara::Log::Logger::GetClientLogger()->error(__VA_ARGS__);
#define KARA_CLIENT_WARN(...) \
  ::Kara::Log::Logger::GetClientLogger()->warn(__VA_ARGS__);
#define KARA_CLIENT_INFO(...) \
  ::Kara::Log::Logger::GetClientLogger()->info(__VA_ARGS__);
#define KARA_CLIENT_TRACE(...) \
  ::Kara::Log::Logger::GetClientLogger()->trace(__VA_ARGS__);
