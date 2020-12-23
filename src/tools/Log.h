#pragma once
#include "spdlog/spdlog.h"
#include <memory>

namespace MemoGL {
    class Log {
        public:
            static inline Log* Log::getInstance() {
                if (!instance) {
                    instance = new Log();
                }
                return instance;
            }

            inline std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
            inline std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

        private:
            Log();
            
            static Log* instance;
            std::shared_ptr<spdlog::logger> coreLogger = nullptr;
            std::shared_ptr<spdlog::logger> clientLogger = nullptr;
    };
}

// Core Log Macro
#ifdef _DEBUG
    #define MEMOGL_LOG_TRACE(...)      ::MemoGL::Log::getInstance()->getCoreLogger()->trace(__VA_ARGS__);
    #define MEMOGL_LOG_INFO(...)       ::MemoGL::Log::getInstance()->getCoreLogger()->info(__VA_ARGS__);
    #define MEMOGL_LOG_WARNING(...)    ::MemoGL::Log::getInstance()->getCoreLogger()->warn(__VA_ARGS__);
    #define MEMOGL_LOG_ERROR(...)      ::MemoGL::Log::getInstance()->getCoreLogger()->error(__VA_ARGS__);
    #define MEMOGL_LOG_FATAL(...)      ::MemoGL::Log::getInstance()->getCoreLogger()->fatal(__VA_ARGS__);
#else
    #define MEMOGL_LOG_TRACE(...)
    #define MEMOGL_LOG_INFO(...)
    #define MEMOGL_LOG_WARNING(...)
    #define MEMOGL_LOG_ERROR(...)
    #define MEMOGL_LOG_FATAL(...)
#endif