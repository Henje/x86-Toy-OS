#ifndef VIDEO_H
#define VIDEO_H

extern void print(const char*);
extern void print(char);
extern void print(int);

template<class ...Args>
void print(Args... args) {
	((print(args), print(' ')), ..., print('\b'));
}

#endif
