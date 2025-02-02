#include "Logger.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kara {
	namespace Log {
		std::shared_ptr<spdlog::logger> Logger::smClientLogger;
		std::shared_ptr<spdlog::logger> Logger::smCoreLogger;

		void Logger::Init() {
			spdlog::set_pattern("%^[%T] %n: %v%$");
			smClientLogger = spdlog::stdout_color_mt("Client");
			smClientLogger->set_level(spdlog::level::trace);
			smCoreLogger = spdlog::stdout_color_mt("Core");
			smCoreLogger->set_level(spdlog::level::trace);

			KR_CORE_INFO("Logger initialized successfully !");
		}
	}
}
