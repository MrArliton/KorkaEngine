#pragma once
// ����� ���� block 2
#include "OpenGL.h"
#include "RawInputControll.h"
// 
#define CURSOR_NORMALL 0
#define CURSOR_DISABLE 1
#define CURSOR_HIDE 2
#define STICKY_MOUSE_BUTTONS_TRUE 1
#define STICKY_MOUSE_BUTTONS_FALSE 0
#define STICKY_KEYS_TRUE 1
#define STICKY_KEYS_FALSE 0
#define LOCK_KEY_MODS_TRUE 3
#define LOCK_KEY_MODS_FALSE 2
//
class Window
{
private:
	GLfloat delta = 0;
	GLfloat last_time = 0;
	GLFWwindow* window = NULL; // ����� ���� �� GLWF
	//���� ������
	Int_InputController* inputC; 
	//
public:
	Window(GLint x,GLint y,GLint width,GLint height,bool fullscreen,const GLchar* title); // �������� ���������� ����
	GLfloat update(); // ��������� ������� ������
	GLFWwindow* getWindow();
	// ���� ������
	bool getPressButton(int key);
	bool getReleaseButton(int key);
	void setModeKeyboard(GLushort mode); // ������������ ������� ������������� �����
	bool getPressButtonMouse(int key);
	void setModeMouseButton(GLushort mode);
	bool getReleaseButtonMouse(int key);
	glm::vec2 getCursorPosition();
	void setModeCursor(GLushort mode); // ������������ ������� �������
	//
};

