#include "RawCamera.h"

RawCamera::RawCamera(int width, int height) {
	this->width = width;
	this->height = height;
	VP = perspective(FOV, ((float)width) / height, minView, maxView) * lookAt(
		vec3(posX, posY, posZ),
		vec3(tarX, tarY, tarZ),
		vec3(rotX, rotY, rotZ));
}
mat4 RawCamera::getMatrixVP() { // Расчёт и возврат матрицы
	return VP;
}
void RawCamera::updateMatrix() { // Обновляем матрицу камеры
	VP = perspective(FOV, ((float)width) / height, minView, maxView) * lookAt(
		vec3(posX, posY, posZ),
		vec3(tarX, tarY, tarZ),
		vec3(rotX, rotY, rotZ));
}

void RawCamera::resolutionResize(int width, int height) {
	this->width = width;
	this->height = height;
}
vec3 RawCamera::getPosition() {
	return vec3(posX, posY, posZ);
}
vec3 RawCamera::getRotation() {
	return vec3(rotX, rotY, rotZ);
}
vec3 RawCamera::getTarget() {
	return vec3(rotX, rotY, rotZ);
}
// Различные трансформации матрицы
void RawCamera::transformPosition(vec3 xyz) {
	posX = xyz.x;
	posY = xyz.y;
	posZ = xyz.z;
}
void RawCamera::transformPosition(float x, float y, float z) {
	posX = x;
	posY = y;
	posZ = z;
}
void RawCamera::transformTarget(float x, float y, float z) {
	tarX = x;
	tarY = y;
	tarZ = z;
}
void RawCamera::transformTarget(vec3 xyz) {
	tarX = xyz.x;
	tarY = xyz.y;
	tarZ = xyz.z;
}
void RawCamera::transformRotation(float x, float y, float z) {
	rotX = x;
	rotY = y;
	rotZ = z;
}
void RawCamera::transformRotation(vec3 xyz) {
	rotX = xyz.x;
	rotY = xyz.y;
	rotZ = xyz.z;
}