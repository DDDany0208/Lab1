#include "string.h"

int strln(const char* s) {
	int i = 0;
	if (s) while (s[i] != '\0') ++i;
	return i;
}
void strcpy(char *s1, const char* s2, int n) {
	for (int i = 0; i < n; ++i)
		s1[i] = s2[i];
}
char* read(const char *s) {
	int i;
	char *ptr;
	char c[MAX_SIZE];
	std::cout << s;
	for (i = 0; ((c[i] = std::cin.get()) != '\n'); ++i);
	c[i] = '\0';
	ptr = new char[i + 1];
	do {
		ptr[i] = c[i];
	} while (i--);
	return ptr;
}
