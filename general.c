#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"

void* safeRealloc(void* base, size_t newByteCount) {
	void* temp = realloc(base, newByteCount);
	if (!temp)
		free(base);
	return temp;
}


void clearBuffer(const char* str)
{
	int c;
	if (strchr(str, '\n') == NULL) {
		while ((c = getchar()) != '\n' && c != EOF);
	}
}

char* getStrFromUser(const char* msg)
{
	char* temp = (char*)malloc(MAX_LEN * sizeof(char));
	if (!temp)
		return NULL;
	do
	{
		puts(msg);
		fgets(temp, MAX_LEN, stdin);
		clearBuffer(temp);
		for (int i = 0; i < strlen(temp); i++)
			if (temp[i] == '\n')
				temp[i] = '\0';
	} while (!strlen(temp));
	temp = (char*)safeRealloc(temp, (strlen(temp) + 1) * sizeof(char));
	return temp ? temp : NULL;
}