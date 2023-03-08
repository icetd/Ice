#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include "Ice/Core/Window.h"
#include "GLFW/glfw3.h"

namespace Ice {
	class WindowsWindow : public Window {
	public :
		WindowsWindow(const WindowProps &props);
		
		virtual ~WindowsWindow();

		void OnUpdate() override;
		uint32_t GetWidth() const override { return m_Data.Width; }
		uint32_t GetHeight() const override { return m_Data.Height; }
		
		void SetEventCallback(const EventCallbackFn &callback) override 
		{
			m_Data.EventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void *GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProps &props);
		virtual void Shutdown();
	private:
		GLFWwindow *m_Window;
		
		struct WindowData {
			std::string Titile;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}
#endif