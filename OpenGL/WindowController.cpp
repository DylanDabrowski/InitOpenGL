#include "WindowController.h"

WindowController::WindowController()
{
	m_window = nullptr;
}

WindowController::~WindowController()
{
	if (m_window != nullptr)
	{
		glfwTerminate();
		m_window = nullptr;
	}
}

void WindowController::NewWindow()
{
	M_ASSERT(glfwInit(), "Failed to initialize GLFW.\n"); // Initialize GLFW

	// Open a window and create its OpenGL context
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	M_ASSERT((m_window = glfwCreateWindow(1024, 768, "A sample scene", NULL, NULL)) != nullptr, "Failed to open GLFW window.\n");
	glfwMakeContextCurrent(m_window); // Initialize GLEW

}

Resolution WindowController::GetResolution()
{
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	return Resolution(mode->width, mode->height);
}