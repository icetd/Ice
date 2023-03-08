#ifndef BASE_H
#define BASE_H

#include <memory>


#ifdef ICE_DEBUG
	#if defined(ICE_PLATFORM_WINDOWS)
		#define ICE_DEBUGBREAK() __debugbreak()
	#elif defined(HZ_PLATFORM_LINUX)
		#include <signal.h>
		#define ICE_DEBUGBREAK() raise(SIGTRAP)
	#else
	
	#endif
	#define ICE_ENABLE_ASSERTS
#else
	#define HZ_DEBUGBREAK()
#endif

#define ICE_EXPAND_MACRO(x) x
#define ICE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)


namespace Ice {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Ice/Core/Log.h"
#include "Ice/Core/Assert.h"

#endif