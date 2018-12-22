#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Util
{
    class Log
    {
    private:
        static std::shared_ptr<spdlog::logger> core_logger;
        static std::shared_ptr<spdlog::logger> client_logger;
    public:
        static void init();
        inline static std::shared_ptr<spdlog::logger>& get_core_logger()
        { return core_logger;}
        inline static std::shared_ptr<spdlog::logger>& get_client_logger()
        { return client_logger; }
    };
}

// Defining macros for easy use of logging

#define PUK_INIT Util::Log::init

#define PUK_CORE_TRACE(...) Util::Log::get_core_logger()->trace(__VA_ARGS__)
#define PUK_CORE_INFO(...)  Util::Log::get_core_logger()->info(__VA_ARGS__)
#define PUK_CORE_WARN(...)  Util::Log::get_core_logger()->warn(__VA_ARGS__)
#define PUK_CORE_ERROR(...) Util::Log::get_core_logger()->error(__VA_ARGS__)
#define PUK_CORE_FATAL(...) Util::Log::get_core_logger()->fatal(__VA_ARGS__)

#define PUK_CLIENT_TRACE(...)   Util::Log::get_client_logger()->trace(__VA_ARGS__)
#define PUK_CLIENT_INFO(...)    Util::Log::get_client_logger()->info(__VA_ARGS__)
#define PUK_CLIENT_WARN(...)    Util::Log::get_client_logger()->warn(__VA_ARGS__)
#define PUK_CLIENT_ERROR(...)   Util::Log::get_client_logger()->error(__VA_ARGS__)
#define PUK_CLIENT_FATAL(...)   Util::Log::get_client_logger()->fatal(__VA_ARGS__)