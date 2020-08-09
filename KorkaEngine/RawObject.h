#pragma once
#include "OpenGL.h"
class RawObject
{
private:
	GLfloat* vertex; // �������
	GLfloat* colors; // ���� ������������ ����
	GLfloat* UV; // ��� �������
	GLuint triangleAmount;
	bool color = false;
public:
	RawObject(GLfloat *vertex, GLuint triangleAmount);
	//RawObject(GLfloat* vertex,GLfloat* color);
	RawObject(GLfloat* vertex, GLfloat* UV, GLuint triangleAmount);
	

	void dispose(); // ������� �������
	GLfloat* getVertex();
	GLuint getTriangleAmount();
};

