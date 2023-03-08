#include "Ice/Core/Application.h"
#include <Ice/Events/ApplicationEvent.h>
#include <Ice/Events/KeyEvent.h>
#include "Ice/Core/Log.h"

namespace Ice {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ICE_TRACE(e);
		}
		
		if (e.IsInCategory(EventCategoryInput)) {
			ICE_TRACE(e);
		}
		while (true);
	}
}
