#pragma once
#include "RawObject.h"
#include "OpenGL.h"
#include <vector>
#include <string>
// Загрузка obj файлов в Object
RawObject* loadObj(const char* path);
std::vector<std::string> split(std::string str,char raz);