#include "LoadOBJ.h"

std::vector<std::string> split(std::string str, char raz) { // Делит строку 
	std::vector<std::string> otv;
	std::string buff;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i)!=raz)
		{
			buff += str.at(i);
		}
		else {
			otv.push_back(buff);
			buff = "";
		}
		}
	otv.push_back(buff);
	return otv;
}

RawObject* loadObj(const char* path) { 
	std::vector<GLfloat> vertex;
	std::vector<GLint> triangles;
	printDebug("Load Obj Format file\n");
	std::ifstream file(path);
	if (!file.is_open()) 
	{
		printError("Error with load Obj format: not file open\n");
		return NULL;
	}
	std::string buff;
	std::vector<std::string> vbuff;
	while (!file.eof()) {
		buff = "";
		std::getline(file, buff);
		if (buff.length() > 0) {
			if (buff.at(0) == 'v')  // Загружаем вершины
			{
				vbuff = split(buff, ' ');
				if (vbuff.size() != 4)
				{
					printError("Error with load Obj format: not correct file\n");
					return NULL;
				}
				try
				{
					for (int i = 1; i < 4; i++) {
						vertex.push_back(atof(vbuff.at(i).c_str()));
					}

				}
				catch (std::exception e) {
					printError("Error with load Obj format: not correct file\n");
					return NULL;
				}
			}
			else if (buff.at(0) == 'f')  // Загружаем номера вершин для треугольников
				{
					vbuff = split(buff, ' ');
					if (vbuff.size() != 4
						) {
						printError("Error with load Obj format: not correct file\n");
						return NULL;
					}
					try
					{
						for (int i = 1; i < 4; i++) {
							triangles.push_back(atof(vbuff.at(i).c_str()));
						}
					}
					catch (std::exception e) {
						printError("Error with load Obj format: not correct file\n");
						return NULL;
					}
			}
		}
	}
	GLfloat* trianglVertex = new GLfloat[triangles.size()*3];
	int o = 0;
	for (int i = 0; i < triangles.size();i++) {
		for (int p = 0; p < 3; p++) {
			trianglVertex[o] = vertex.at(triangles.at(i) * 3 - 3 + p);
			o++;
		}
	}
	return new RawObject(trianglVertex,triangles.size()/3);
}