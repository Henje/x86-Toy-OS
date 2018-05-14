#include "video.h"

extern "C" void test_lambda() {
	int line = 1;
	auto print = [&line](const char* msg) {
		char* buffer = (char*)0xb8000;
		for(int i = 0; msg[i]; i++) {
			buffer[(i + 80*line)*2] = msg[i];
			buffer[(i + 80*line)*2 + 1] = 0x07;
		}
		line++;
	};
	print("Hello");
	print("From C++ lambda");
}

extern "C" void test_video() {
	print("\n\n\n");
	print("Hallo", 42, "geht das hier?", 'y');
}
