#pragma once
#include "OpenGL.h"
class RawObject
{
private:
	GLfloat* vertex; // Вершины
	GLfloat* colors; // Если используется цвет
	GLfloat* UV; // Для текстур
	GLuint triangleAmount;
	bool color = false;
public:
	RawObject(GLfloat *vertex, GLuint triangleAmount);
	//RawObject(GLfloat* vertex,GLfloat* color);
	RawObject(GLfloat* vertex, GLfloat* UV, GLuint triangleAmount);
	

	void dispose(); // Очищаем ресурсы
	GLfloat* getVertex();
	GLuint getTriangleAmount();
};

