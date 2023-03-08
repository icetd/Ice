#ifndef APPLICATION_H
#define APPLICATION_H

#include "icepch.h"
#include "Window.h"

namespace Ice {

	class Application {
	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be define in CLIENT
	Application *CreateApplication();
}

#endif