#include <Tutorial/Display.h>

namespace Tutorial {

	Display::Display(int width, int height, const char* title) {
		if (!glfwInit()) {
			printf("Couldn't initialize GLFW\n");
			exit(1);
		}
		
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		
		this->window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (!window) {
			glfwTerminate();
			printf("Couldn't create a window\n");
			exit(1);
		}
		
		glfwMakeContextCurrent(this->window);
		
		// OpenGL Setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	
	Display::~Display() {
		glfwDestroyWindow(this->window);
		glfwTerminate();
	}
	
	void Display::start() {
		while (!glfwWindowShouldClose(this->window)) {
			glfwSwapBuffers(this->window);
			glfwPollEvents();
			
			glClearColor(0, 1, 0.5f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}

}