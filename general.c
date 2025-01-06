#include <stdio.h>

void* safeRealloc(void* base, size_t newByteCount) {
	void* temp = realloc(base, newByteCount);
	if (!temp)
		free(base);
	return temp;
}


void clearBuffer(char* str)
{
	int c;
	if (strchr(str, '\n') == NULL) {
		while ((c = getchar()) != '\n' && c != EOF);
	}
}