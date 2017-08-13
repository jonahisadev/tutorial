#include <cstdio>
#include <cstdlib>

#include <Tutorial/Display.h>

using namespace Tutorial;

int main(int argc, char** argv) {
	Display window(1280, 720, "Our Game");
	window.start();
	
	return 0;
}