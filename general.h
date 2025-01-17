#pragma once
#include <ctype.h>
#define MAX_LEN 255

void* safeRealloc(void* base, size_t newByteCount);
void clearBuffer(const char* str);
char* getStrFromUser(const char* msg);