#include "TestInput.h"
#include "iostream" 
void TestInput::keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::cout << key << " " << action << "\n";
}
void TestInput::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
	std::cout << button << " " << action << "\n";
}
void TestInput::mouse_position_callback(GLFWwindow* window, double xpos, double ypos) {
	std::cout << xpos << " " << ypos << "\n";
}
void TestInput::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	std::cout << xoffset << " " << yoffset << "\n";
}