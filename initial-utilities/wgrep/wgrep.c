#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int find(char *filename, char *search) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("wgrep: cannot open file\n");
    return 1;
  }
  size_t bufsize;
  char *lineptr = NULL;

  while (getline(&lineptr, &bufsize, fp)) {
    printf("%s");
  }

  fclose(fp);
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]");
    return 1;
  }

  char *search = argv[1];

  for (int file = 2; file < argc; file++) {
    int out = find(argv[file], search);
    if (out != 0) {
      return 1;
    }
  }
  return 0;
}
