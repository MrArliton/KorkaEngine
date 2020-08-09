#pragma once
#include "OpenGL.h"
class Shader
{
private:
	GLuint shaderProgram;
	GLuint* attribPos;
	GLuint* uniformMVP;
public:
	Shader(const char* pathVertexShader);
	Shader(const char* pathVertexShader,const char* patFragmentShader);
	GLuint getShaderProgram();
	GLuint getAttribPos();
	GLuint getUniformMVP();

	void dispose();
};

