#include <stdbool.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }
  char current_char = 0;
  char prev_char = 0;
  int it = 0;

  for (int file = 1; file < argc; file++) {
    FILE *fp = fopen(argv[file], "r");
    while (true) {
      current_char = (char)fgetc(fp);
      if (current_char == EOF) {
        break;
      }
      if (prev_char == current_char || prev_char == 0) {
        it++;
      } else {
        fwrite(&it, 4, 1, stdout);
        fwrite(&prev_char, 1, 1, stdout);
        it = 1;
      }
      prev_char = current_char;
    }
  }

  fwrite(&it, 4, 1, stdout);
  fwrite(&prev_char, 1, 1, stdout);

  return 0;
}
