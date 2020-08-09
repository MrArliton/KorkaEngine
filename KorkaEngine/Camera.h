#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
class Camera
{
private:
	float FOV = 45.0f; // ����� ������
	int width, height; // ������� ������
	float minView = 0.1f; // ������� ������� ��������
	float maxView = 100.0f; // ������� ������� ��������
	float posX = 0, posY = 0, posZ = 1;// ������� ������ default 0 0 1
	float tarX = 0,tarY = 0,tarZ = 0; // ����������� ������ default 0 0 0
	float rotX=0, rotY=1, rotZ=0; // ������� ������ ������ ����� ��� default 0 1 0
	mat4 VP;
public:
	Camera(int width,int height);
	mat4 getMatrixVP(); // ��������� ������� �������� � ���� ������
	void resolutionResize(int width,int height); // ��������� ���������� ������
	void transformPosition(float x,float y,float z);
	void transformPosition(vec3 xyz);
	vec3 getPosition();
	void updateMatrix();
};

