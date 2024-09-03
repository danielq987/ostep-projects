#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void find(char *pattern, FILE *fp) {
  size_t bufsize;
  char *lineptr = NULL;
  size_t pattern_len = strlen(pattern);

  while (getline(&lineptr, &bufsize, fp) != -1) {
    bool isMatch = false;
    for (int line_idx = 0; line_idx < bufsize - pattern_len; line_idx++) {
      int pattern_idx;
      for (pattern_idx = 0; pattern_idx < pattern_len; pattern_idx++) {
        if (lineptr[line_idx + pattern_idx] != pattern[pattern_idx]) {
          break;
        }
      }
      if (pattern_idx == pattern_len) {
        isMatch = true;
        break;
      }
    }

    if (isMatch) {
      printf("%s", lineptr);
    }
    memset(lineptr, 0, strlen(lineptr));
  }

  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }

  char *search = argv[1];

  for (int file = 2; file < argc; file++) {
    FILE *fp = fopen(argv[file], "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file\n");
      return 1;
    }
    find(search, fp);
  }

  if (argc == 2) {
    find(search, stdin);
  }
  return 0;
}
