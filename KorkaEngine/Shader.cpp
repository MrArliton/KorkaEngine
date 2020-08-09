#include "Shader.h"

Shader::Shader(const char* pathVertexShader) {
	GLuint  vertexShader;
	GLint status;
	char* bufferV =  gl_getShader(pathVertexShader);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	shaderProgram = glCreateProgram();
	glShaderSource(vertexShader, 1, &bufferV, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		printError("Error with compile vertexShader:",pathVertexShader);
		return;
	}
	glAttachShader(shaderProgram, vertexShader);
	glDeleteShader(vertexShader);
	glLinkProgram(shaderProgram);
	delete[] bufferV; // Удаляем буффера
}
Shader::Shader(const char* pathVertexShader, const char* pathFragmentShader) {
	GLuint  vertexShader,fragmentShader;
	GLint status;
	char* bufferV = gl_getShader(pathVertexShader);
	char* bufferF = gl_getShader(pathFragmentShader);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();

	glShaderSource(vertexShader, 1, &bufferV, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		printError("Error with compile vertexShader:", pathVertexShader);
	}
	else {
		glAttachShader(shaderProgram, vertexShader);
	}
	//
	glShaderSource(fragmentShader, 1, &bufferF, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		printError("Error with compile fragmentShader:", pathFragmentShader);
	}
	else {
		glAttachShader(shaderProgram, fragmentShader);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glLinkProgram(shaderProgram);
	attribPos = new GLuint();
	uniformMVP = new GLuint();
	*attribPos = glGetAttribLocation(shaderProgram, "position");
	*uniformMVP = glGetUniformLocation(shaderProgram,"MVP");
	delete[] bufferV; // Удаляем буффера
	delete[] bufferF;
}
GLuint Shader::getShaderProgram() {
	return shaderProgram;
}

GLuint Shader::getAttribPos() {
	return *attribPos;
}
GLuint Shader::getUniformMVP() {
	return *uniformMVP;
}
void Shader::dispose() {
	glDeleteProgram(shaderProgram);
	if (attribPos != NULL)
	{
		delete attribPos;
		attribPos = NULL;
	}
	if (uniformMVP != NULL)
	{
		delete uniformMVP;
		uniformMVP = NULL;
	}
}