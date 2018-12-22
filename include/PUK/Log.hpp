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

#define PUK_CORE_TRACE(args...) Util::Log::get_core_logger()->trace(args)
#define PUK_CORE_INFO(args...)  Util::Log::get_core_logger()->info(args)
#define PUK_CORE_WARN(args...)  Util::Log::get_core_logger()->warn(args)
#define PUK_CORE_ERROR(args...) Util::Log::get_core_logger()->error(args)
#define PUK_CORE_FATAL(args...) Util::Log::get_core_logger()->fatal(args)

#define PUK_CLIENT_TRACE(args...)   Util::Log::get_client_logger()->trace(args)
#define PUK_CLIENT_INFO(args...)    Util::Log::get_client_logger()->info(args)
#define PUK_CLIENT_WARN(args...)    Util::Log::get_client_logger()->warn(args)
#define PUK_CLIENT_ERROR(args...)   Util::Log::get_client_logger()->error(args)
#define PUK_CLIENT_FATAL(args...)   Util::Log::get_client_logger()->fatal(args)