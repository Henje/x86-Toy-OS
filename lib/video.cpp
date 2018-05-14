#include "video.h"

void new_line();
void carriage_return();
void tabulator();
void scroll();

char *const video_buffer = reinterpret_cast<char*>(0xB8000);
const int screen_width = 80;
const int screen_height = 25;

int x = 0;
int y = 0;

char color = 0x07;

void clear() {
	for(int i = 0; i < screen_width*screen_height; i++) {
		video_buffer[2 * i] = ' ';
		video_buffer[2 * i + 1] = color;
	}
}

void print(char c) {
	switch(c) {
	case '\n':
		new_line();
		break;
	case '\r':
		carriage_return();
		break;
	case '\t':
		tabulator();
		break;
	case '\b':
		x -= 1;
		if(x < 0) {
			y -= 1;
			x += screen_width;
		}
		break;
	default:
		int pos = 2 * (x + screen_width*y);
		video_buffer[pos] = c;
		video_buffer[pos + 1] = color;
		x += 1;
		if(x >= screen_width) {
			new_line();
		}
	}
}

void print(const char* msg) {
	for(int i = 0; msg[i]; i++) {
		print(msg[i]);
	}
}

void print(int number) {
	char buffer[15];
	int pos = 0;
	if(number == 0) {
		print('0');
		return;
	} else if(number < 0) {
		print('-');
		number *= -1;
	}
	while(number > 0) {
		buffer[pos++] = (number % 10) + '0';
		number /= 10;
	}
	for(int i = --pos; i >= 0; i--) {
		print(buffer[i]);
	}
}

void new_line() {
	x = 0;
	y += 1;
	if(y >= screen_height) {
		scroll();
		y -= 1;
	}
}

void carriage_return() {
	x = 0;
}

void tabulator() {
	x += 4 - (x % 4);
	if(x >= screen_width) {
		new_line();
	}
}

void scroll() {
	for(int i = screen_width; i < screen_width * screen_height; i++) {
		video_buffer[2 * i] = video_buffer[2 * (i + screen_width)];
		video_buffer[2 * i + 1] = video_buffer[2 * (i + screen_width) + 1];
	}
}
