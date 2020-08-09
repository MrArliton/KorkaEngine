#pragma once
// ����� ���� block 2
#include "OpenGL.h"
class Window
{
private:
	GLushort delta;
	GLulong last_time;
	GLFWwindow* window; // ����� ���� �� GLWF
public:
	Window(GLint x,GLint y,GLint width,GLint height,bool fullscreen,const GLchar* title); // �������� ���������� ����
	GLushort update(); // ��������� ������� ������
	GLFWwindow* getWindow();
};

