#include "file.h"
#include "color_codes.h"
#include <stdio.h>
#include <stdlib.h>

char *getFileContents(const char *filepath) {
#ifndef NDEBUG
    fprintf(stderr, "Trying to read content from file %s...\n", filepath);
#endif
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, RED"Couldn't find file %s.\n"reset, filepath);
        abort();
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buf = malloc(size + 1);
    if (!fread(buf, 1, size, fp)) {
        fprintf(stderr, RED"Couldn't read from file %s.\n"reset, filepath);
        abort();
    }
    fclose(fp);
    return buf;
}