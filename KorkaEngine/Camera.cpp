#include "Camera.h"

Camera::Camera(int width,int height) {
	this->width = width;
	this->height = height;
	VP = perspective(FOV, ((float)width) / height, minView, maxView) * lookAt(
		vec3(posX, posY, posZ),
		vec3(tarX, tarY, tarZ),
		vec3(rotX, rotY, rotZ));
}
mat4 Camera::getMatrixVP() { // Расчёт и возврат матрицы
	return VP;
}
void Camera::updateMatrix() { // Обновляем матрицу камеры
	VP = perspective(FOV, ((float)width) / height, minView, maxView)* lookAt(
		vec3(posX, posY, posZ),
		vec3(tarX, tarY, tarZ),
		vec3(rotX, rotY, rotZ));
}

void Camera::resolutionResize(int width,int height){
	this->width = width;
	this->height = height;
}
vec3 Camera::getPosition() {
	return vec3(posX,posY,posZ);
}
void Camera::transformPosition(vec3 xyz) {
	posX = xyz.x;
	posY = xyz.y;
	posZ = xyz.z;
}
void Camera::transformPosition(float x,float y,float z) {
	posX = x;
	posY = y;
	posZ = z;
}