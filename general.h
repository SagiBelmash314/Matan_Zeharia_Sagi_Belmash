#pragma once
#include <stdlib.h>

void* safeRealloc(void* base, size_t newByteCount);

void clearBuffer(char* str);