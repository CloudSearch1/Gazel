#pragma once

#include"Base.h"
#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"
#include"spdlog/sinks/stdout_color_sinks.h"

namespace Gazel {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
		
	};
}

#define GZ_CORE_TRACE(...)	::Gazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GZ_CORE_INFO(...)	::Gazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GZ_CORE_WARN(...)	::Gazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GZ_CORE_ERROR(...)	::Gazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GZ_CORE_FATAL(...)	::Gazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define GZ_TRACE(...)	::Gazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GZ_INFO(...)	::Gazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define GZ_WARN(...)	::Gazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GZ_ERROR(...)	::Gazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define GZ_FATAL(...)	::Gazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
