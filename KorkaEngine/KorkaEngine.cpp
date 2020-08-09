
#include "LoadOBJ.h"
#include "Object.h"
#include "Window.h"
#include <iostream>
#include "Camera.h"
int main()
{
	GLuint vao;
	Window win(0, 0, 600, 400, false, "Test");
	glGenVertexArrays(1, &vao);

	RawObject* rObj = loadObj("C:/Users/MrArl/Documents/cube.obj");
	Object* obj = new Object(rObj, &vao);
	Shader shader("C:/Users/MrArl/source/repos/KorkaEngine/x64/Debug/Data/testShader.vs", "C:/Users/MrArl/source/repos/KorkaEngine/x64/Debug/Data/testShader.fs");
	Camera cam(600,400);
	cam.transformPosition(4.0f, 3.0f, 3.0f);
	cam.updateMatrix();
	obj->setShaderProgram(&shader);
	do {
		win.update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		obj->update(cam.getMatrixVP());
		obj->draw();
		glfwSwapBuffers(win.getWindow());
		glfwPollEvents();
	} while (true);

}

