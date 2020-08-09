#include "Object.h"
#include "string.h"
#include"iostream"
Object::Object(RawObject* obj,GLuint* vao) { // �������� ����� ������ - �� ������������ ��� ��������� ���������
	printDebug("Creating object\n");
	this->triangleAmount = obj->getTriangleAmount();
	meshVbo = new GLuint();
	Model = new glm::mat4();
	*Model = glm::mat4(1.0f);
	this->meshVao = vao;
	glGenBuffers(1, meshVbo); // ������ vbo ***
	// �������� � ������ ������ � ��������
	glBindBuffer(GL_ARRAY_BUFFER,*meshVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*3*3*triangleAmount, obj->getVertex(), GL_STATIC_DRAW);
	
}

void Object::setShaderProgram(Shader* shaderProgram) { // ������������� ��������� ���������
	this->shaderProgram = shaderProgram;
	glUseProgram(shaderProgram->getShaderProgram());
	glBindVertexArray(*meshVao);
	//������������� �������� VAO � �������
	if (shaderProgram->getAttribPos() != -1)
	{
		glVertexAttribPointer(shaderProgram->getAttribPos(), 3, GL_FLOAT, GL_FALSE, 12, (GLvoid*)0);
		glEnableVertexAttribArray(shaderProgram->getAttribPos());
	}
	else
	{
		printError("Error with getAttribLocation\n");
	}
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//
}
void Object::update(glm::mat4 VP) {
	glUseProgram(shaderProgram->getShaderProgram());
	glBindVertexArray(*meshVao);
	glBindBuffer(GL_ARRAY_BUFFER, *meshVbo);
	glm::mat4 MVP = VP**Model;
	if (shaderProgram->getUniformMVP() != -1) {
		glUniformMatrix4fv(shaderProgram->getUniformMVP(), 1, GL_FALSE,&MVP[0][0]);
	}
}
void Object::draw() { // ������ ������
	glUseProgram(shaderProgram->getShaderProgram());
	glBindVertexArray(*meshVao);
	glBindBuffer(GL_ARRAY_BUFFER,*meshVbo);

	glDrawArrays(GL_TRIANGLES, 0, triangleAmount*3); // ������ �������
}

void Object::dispose() { // �������
	if (meshVbo != NULL)
	{
		glDeleteBuffers(1, meshVbo);
		delete meshVbo;
		meshVbo = NULL;
	}
	if (Model != NULL)
	{
		delete Model;
		Model = NULL;
	}
}