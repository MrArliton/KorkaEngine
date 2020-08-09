#include "RawObject.h"


RawObject::RawObject(GLfloat* vertex,GLuint triangleAmount) {
	this->vertex = vertex;
	this->triangleAmount = triangleAmount;
}
GLfloat* RawObject::getVertex() {
	return vertex;
}
GLuint RawObject::getTriangleAmount() {
	return this->triangleAmount;
}
void RawObject::dispose() {
	if (vertex != NULL)
	{
		delete[]vertex;
		vertex = NULL;
	}
	if (colors != NULL)
	{
		delete[]colors;
		colors = NULL;
	}
	if (UV != NULL)
	{
		delete[]UV;
		UV = NULL;
	}
}