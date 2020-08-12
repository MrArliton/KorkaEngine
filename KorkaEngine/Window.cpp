#include "Window.h"
//block 2
Window::Window(GLint x, GLint y, GLint width, GLint height, bool fullscreen, const GLchar* title) { // �������� ����
	printDebug("Create window\n");
	if (glfwInit() != GLFW_TRUE) 
	{ // �������������� glfw
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
	glfwMakeContextCurrent(window); // ������ �������� ��� ������ ����

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
GLfloat Window::update() { // ���������� �����
	delta = glfwGetTime() - last_time;
	last_time = glfwGetTime();
	return delta;
}
//���� ������ 
glm::vec2 Window::getCursorPosition() {
	GLdouble x, y;
	glfwGetCursorPos(window, &x, &y);
	return glm::vec2(x, y);
}


void Window::setModeCursor(GLushort mode) {
	if (mode == CURSOR_NORMALL) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); // ����������� ������
	}
	else if(mode == CURSOR_HIDE){
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); // ������� ������
	}
	else if(mode == CURSOR_DISABLE){
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // ������ ��� ����� ����������� ����
	}
	}
bool Window::getPressButton(int key) { // ���������� ������� ������
	if (glfwGetKey(window, key) == GLFW_PRESS)
		return true;
	return false;
}
void Window::setModeMouseButton(GLushort mode) {
	if(mode)
		glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	else
		glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_FALSE);
}
bool Window::getReleaseButton(int key){ // ���������� ������� ������
	if (glfwGetKey(window, key) == GLFW_RELEASE)
		return true;
	return false;
}
void Window::setModeKeyboard(GLushort mode){
	if (mode == STICKY_KEYS_TRUE) {
		glfwSetInputMode(window,GLFW_STICKY_KEYS,GLFW_TRUE);
	}
	else if (mode == STICKY_KEYS_FALSE) {
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
	}
	else if (mode == LOCK_KEY_MODS_TRUE) {
		glfwSetInputMode(window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);
	}
	else if (mode == LOCK_KEY_MODS_FALSE) {
		glfwSetInputMode(window, GLFW_LOCK_KEY_MODS, GLFW_FALSE);
	}
}
bool Window::getPressButtonMouse(int key){
	if (glfwGetMouseButton(window,key) == GLFW_PRESS)
		return true;
	return false;
}
bool Window::getReleaseButtonMouse(int key){
	if (glfwGetMouseButton(window, key) == GLFW_RELEASE)
		return true;
	return false;
}