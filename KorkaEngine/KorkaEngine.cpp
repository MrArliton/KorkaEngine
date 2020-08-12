
#include "LoadOBJ.h"
#include "Object.h"
#include "Window.h"
#include "RawCamera.h"
//debug
#include "TestInput.h"
#include "iostream"
int main()
{
	GLuint vao;
	Window win(0, 0, 600, 400, false, "Test");
	glGenVertexArrays(1, &vao);

	RawObject* rObj = loadObj("C:/Users/MrArl/Documents/Cube.obj");
	Object* obj = new Object(rObj, &vao);
	Shader shader("C:/Users/MrArl/source/repos/KorkaEngine/x64/Debug/Data/testShader.vs", "C:/Users/MrArl/source/repos/KorkaEngine/x64/Debug/Data/testShader.fs");
	RawCamera cam(600,400);
	cam.transformPosition(4.0f, 3.0f, 3.0f);
	cam.updateMatrix();
	obj->transformModel(translate(vec3(0.0f,0.0f,0.0f)));
	obj->setShaderProgram(&shader);
	TestInput* input = new TestInput();
	input->setHandleInput(win.getWindow());
	do {
		cam.transformPosition(4.0f, 3.0f, 3.0f);
		cam.updateMatrix();
		win.update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//obj->transformModel(rotate(0.001f,vec3(0.5f,0.5f,0.5f)));
		obj->update(cam.getMatrixVP());
		obj->draw();
		glfwSwapBuffers(win.getWindow());
		glfwPollEvents();
	} while (true);

}

