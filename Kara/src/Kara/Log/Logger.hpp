#pragma once

#include "Kara/Core/Core.hpp"

#include "spdlog/spdlog.h"

#include <memory>

namespace Kara {
	namespace Log {
		class Logger {
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return smClientLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return smCoreLogger; }

		private:
			static std::shared_ptr<spdlog::logger> smClientLogger;
			static std::shared_ptr<spdlog::logger> smCoreLogger;
		};
	}
}

#define KR_CORE_ERROR(...) ::Kara::Log::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define KR_CORE_WARN(...)  ::Kara::Log::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define KR_CORE_INFO(...)  ::Kara::Log::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define KR_CORE_TRACE(...) ::Kara::Log::Logger::GetCoreLogger()->trace(__VA_ARGS__);

#define KR_CLIENT_ERROR(...) ::Kara::Log::Logger::GetClientLogger()->error(__VA_ARGS__);
#define KR_CLIENT_WARN(...)  ::Kara::Log::Logger::GetClientLogger()->warn(__VA_ARGS__);
#define KR_CLIENT_INFO(...)  ::Kara::Log::Logger::GetClientLogger()->info(__VA_ARGS__);
#define KR_CLIENT_TRACE(...) ::Kara::Log::Logger::GetClientLogger()->trace(__VA_ARGS__);
