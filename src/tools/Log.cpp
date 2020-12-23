#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace MemoGL {
	Log* Log::instance = nullptr;

	Log::Log() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		coreLogger = spdlog::stdout_color_mt("MEMOGL");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}
}