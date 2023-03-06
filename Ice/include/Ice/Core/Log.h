#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <memory>

#define ICE_CORE_TRACE(...) ::Ice::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ICE_CORE_INFO(...)  ::Ice::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ICE_CORE_WARN(...)  ::Ice::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ICE_CORE_ERROR(...) ::Ice::Log::GetCoreLogger()->error(__VA_ARGS__)


#define ICE_TRACE(...) ::Ice::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ICE_INFO(...)  ::Ice::Log::GetClientLogger()->info(__VA_ARGS__)
#define ICE_WARN(...)  ::Ice::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ICE_ERROR(...) ::Ice::Log::GetClientLogger()->error(__VA_ARGS__)


namespace Ice {
	class Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#endif