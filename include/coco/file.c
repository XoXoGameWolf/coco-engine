#pragma once

#include <stdio.h>

void readFile(char* buf, char* path) {
    FILE* file = fopen(path, "rb");
    fread(buf, 1, 75497472, file);
    fclose(file);
}