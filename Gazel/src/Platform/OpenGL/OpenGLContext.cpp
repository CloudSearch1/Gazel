#include"gzpch.h"
#include"OpenGLContext.h"
#include"GLFW/glfw3.h"
#include"glad/glad.h"

namespace Gazel
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:  m_WindowHandle(windowHandle)
	{

	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		//status = 1 means success 
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GZ_CORE_ASSERT(status, "Faild to initialize Glad!");
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);

	}
}