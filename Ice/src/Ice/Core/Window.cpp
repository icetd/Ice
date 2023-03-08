#include "icepch.h"
#include "Ice/Core/Window.h"

#ifdef ICE_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Ice {
	Scope<Window> Window::Create(const WindowProps &props)
	{
	#ifdef ICE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		ICE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
}