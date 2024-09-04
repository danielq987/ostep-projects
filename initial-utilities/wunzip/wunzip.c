#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  }

  int reps = 0;
  char c = 0;

  for (int file = 1; file < argc; file++) {
    FILE *fp = fopen(argv[file], "r");
    size_t ret;
    while (true) {
      ret = fread(&reps, 4, 1, fp);
      if (ret != 1) {
        break;
      }
      ret = fread(&c, 1, 1, fp);
      if (ret != 1) {
        break;
      }

      char *str = malloc(sizeof(char) * (reps + 1));
      memset(str, c, reps);
      str[reps] = '\0';
      printf("%s", str);
      free(str);
    }
  }

  return 0;
}
