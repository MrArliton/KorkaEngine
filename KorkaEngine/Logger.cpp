#include "Logger.h"
#include <iostream>
bool debug = true; // Дебаг
void printError(const char* buff) {
	std::cout << "Error: " << buff;
}
void printError(const char* buff, const char* error) {
	std::cout << "Error: " << buff << " error :"<<error << "\n";
}
void printDebug(const char* buff) {
	if(debug)
	std::cout << "debug: " << buff;
}