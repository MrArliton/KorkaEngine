#pragma once
#include "OpenGL.h"
class Int_InputController // ��������� ��� ���������� ���������� 
{

	// ��������� ����� ����������� HANDLE ��� ������������� � C++
	// ��������� ����������� InputController-� 
private:
	static Int_InputController* handle;
	static void keyboard_callbackS(GLFWwindow* window, int key, int scancode, int action, int mods){
		handle->keyboard_callback(window,key,scancode,action,mods);
	}
	static void mouse_button_callbackS(GLFWwindow* window, int button, int action, int mods) {
		handle->mouse_button_callback(window,button,action,mods);
	}
	static void mouse_position_callbackS(GLFWwindow* window, double xpos, double ypos) {
		handle->mouse_position_callback(window,xpos,ypos);
	}
	static void scroll_callbackS(GLFWwindow* window, double xoffset, double yoffset) {
		handle->scroll_callback(window,xoffset,yoffset);
	}
public:
	virtual void setHandleInput(GLFWwindow* window) { 
		glfwSetKeyCallback(window,keyboard_callbackS);
		glfwSetMouseButtonCallback(window,mouse_button_callbackS);
		glfwSetCursorPosCallback(window,mouse_position_callbackS);
		glfwSetScrollCallback(window,scroll_callbackS);
		handle = this;
	}
	virtual void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods)=0; // ������� ����������� �������� � ����������
	virtual void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)=0; // ������� ��� ����� �������� � ������ ����
	virtual void mouse_position_callback(GLFWwindow* window, double xpos, double ypos)=0; //������� ��������� �������
	virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)=0; // ������� ������������ ������ ����

};

