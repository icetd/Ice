#ifndef APPLICATION_H
#define APPLICATION_H

namespace Ice {

	class Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be define in CLIENT
	Application *CreateApplication();
}

#endif