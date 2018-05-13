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
