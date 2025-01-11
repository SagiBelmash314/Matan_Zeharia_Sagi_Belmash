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


void clearBuffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void deleteExcessSpaces(char* str)
{
	while (str[0] == ' ')
		strcpy(str, str + 1);
	while (str[strlen(str) - 1] == ' ')
		str[strlen(str) - 1] = '\0';
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
		for (int i = 0; i < strlen(temp); i++)
			if (temp[i] == '\n')
				temp[i] = '\0';
		deleteExcessSpaces(temp);
	} while (!strlen(temp));
	temp = (char*)safeRealloc(temp, (strlen(temp) + 1) * sizeof(char));
	return temp ? temp : NULL;
}