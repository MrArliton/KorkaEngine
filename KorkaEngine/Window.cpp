#include "Window.h"
//block 2
Window::Window(GLint x, GLint y, GLint width, GLint height, bool fullscreen, const GLchar* title) { // Создание окна
	printDebug("Create window\n");
	if (glfwInit() != GLFW_TRUE) 
	{ // Инициализируем glfw
		printError("Error with initGLFW: block 2\n");
		glfwTerminate();
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == NULL) 
	{
		printError("Error with create GLWFWindow: block 2\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window); // Создаём контекст для нашего окна

	GLenum buff = glewInit();
	if (buff != GLEW_OK)
	{
		printError("Error with init GLEW: block 2",(char*)glewGetErrorString(buff));
		glfwTerminate();
		return;
	}
	last_time = glfwGetTime();
	delta = glfwGetTime() - last_time;
	printDebug("Window create succesfull\n");
}
GLFWwindow* Window::getWindow() {
	return window;
}
GLushort Window::update() { // Обновление кадра
	delta = glfwGetTime() - last_time;
	last_time = glfwGetTime();
	return delta;
}