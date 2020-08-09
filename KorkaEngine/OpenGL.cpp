#include "OpenGL.h"
// block 1
char* gl_getShader(const char* path) { // Функция получения шейдера из файла
	char* buffer;
	std::ifstream file(path, std::ios::in);
	if (file.is_open()) {
		file.seekg(0, std::ios_base::end);
		int len = file.tellg();
		buffer = new char[len + 1];
		file.seekg(0, std::ios_base::beg);
		file.read(buffer, len);
		buffer[len] = 0;
	}
	else {
		printError("Error in load shader: block 1\n");
		return 0;
	}
	file.close();
	return buffer; // После создания обязательно удалять
}
