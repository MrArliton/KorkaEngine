#pragma once
#include "RawInputControll.h"
class TestInput : public Int_InputController
{
	 void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods); // ������� ����������� �������� � ����������
	 void mouse_button_callback(GLFWwindow* window, int button, int action, int mods); // ������� ��� ����� �������� � ������ ����
	 void mouse_position_callback(GLFWwindow* window, double xpos, double ypos); //������� ��������� �������
	 void scroll_callback(GLFWwindow* window, double xoffset, double yoffset); // ������� ������������ ������ ����
};

