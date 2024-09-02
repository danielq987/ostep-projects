#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int output_file(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH] = {0};
    
    while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
        printf(buffer);
    }

    fclose(fp);
    return 0;
}

int main(int argc, char** argv) {
    for (int file = 1; file < argc; file++) {
        int out = output_file(argv[file]);
        if (out != 0) {
            return 1;
        }
    }
    return 0;
}
