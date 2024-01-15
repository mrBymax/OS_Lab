#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc < 3) printf("Usage: %s <file1> <file2>\n", argv[0]);

  // Open the two files
  FILE* f1 = fopen(argv[1], "r");
  FILE* f2 = fopen(argv[2], "r");

  if (f1 == NULL || f2 == NULL) {
    perror("Error, cannot open file");
    exit(EXIT_FAILURE);
  }

  // Read file
  char c1, c2;
  while ((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF) {
    // if the two characters are different, print the whole line and exit
    if (c1 != c2) {
      while (c1 != '\n' && c1 != EOF) {
        printf("%c", c1);
        c1 = fgetc(f1);
      }
      exit(EXIT_SUCCESS);
    }
  }

  return 0;
}