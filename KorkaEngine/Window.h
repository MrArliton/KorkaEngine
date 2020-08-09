#pragma once
// Класс окна block 2
#include "OpenGL.h"
class Window
{
private:
	GLushort delta;
	GLulong last_time;
	GLFWwindow* window; // Класс окна от GLWF
public:
	Window(GLint x,GLint y,GLint width,GLint height,bool fullscreen,const GLchar* title); // Создание экземпляра окна
	GLushort update(); // Обновляем события экрана
	GLFWwindow* getWindow();
};

