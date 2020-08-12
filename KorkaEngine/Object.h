#pragma once
#include "RawObject.h"
#include "Shader.h"
class Object // ��������� ������ � ����������� VBO
{
private:
	GLuint* meshVao, // Vao
		* meshVbo; // Vbo
	Shader* shaderProgram;
	glm::mat4 *Model; // ������� ������
	GLuint triangleAmount = 0;
public:
	Object(RawObject* obj,GLuint* vao);
	void setShaderProgram(Shader* shaderProgramm); // ��������� ��������� ��������� *�����������
	void update(glm::mat4 VP); // ���������� MVP
	void transformModel(glm::mat4 transform); // �������� ������� ������
	void draw();
	void dispose();
};

