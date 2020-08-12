#pragma once
#include "RawObject.h"
#include "Shader.h"
class Object // Одиночный объект с собственным VBO
{
private:
	GLuint* meshVao, // Vao
		* meshVbo; // Vbo
	Shader* shaderProgram;
	glm::mat4 *Model; // Матрица модели
	GLuint triangleAmount = 0;
public:
	Object(RawObject* obj,GLuint* vao);
	void setShaderProgram(Shader* shaderProgramm); // Установка шейдерной программы *обязательно
	void update(glm::mat4 VP); // Обновление MVP
	void transformModel(glm::mat4 transform); // Изменяем матрицу модели
	void draw();
	void dispose();
};

