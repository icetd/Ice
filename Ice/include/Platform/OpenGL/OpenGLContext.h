#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include "Ice/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Ice {
	class OpenGLContext : public GraphicsContext {
		OpenGLContext(GLFWwindow *windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow *m_WindowHandle;
	};
}

#endif