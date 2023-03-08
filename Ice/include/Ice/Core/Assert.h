#ifndef ASSERT_H
#define ASSERT_H

#include "Ice/Core/Base.h"
#include "Ice/Core/Log.h"
#include <filesystem>

#ifdef ICE_ENABLE_ASSERTS

	#define ICE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { ICE##type##ERROR(msg, __VA_ARGS__); ICE_DEBUGBREAK(); } }
	#define ICE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ICE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define ICE_INTERNAL_ASSERT_NO_MSG(type, check) ICE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ICE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define ICE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define ICE_INTERNAL_ASSERT_GET_MACRO(...) ICE_EXPAND_MACRO( ICE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ICE_INTERNAL_ASSERT_WITH_MSG, ICE_INTERNAL_ASSERT_NO_MSG) )

	#define ICE_ASSERT(...) ICE_EXPAND_MACRO( ICE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define ICE_CORE_ASSERT(...) ICE_EXPAND_MACRO( ICE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define ICE_ASSERT(...)
	#define ICE_CORE_ASSERT(...)
#endif

#endif