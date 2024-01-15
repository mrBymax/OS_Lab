#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc != 2) printf("Usage: %s <file>\n", argv[0]);

  FILE* f = fopen(argv[1], "r");

  if (f == NULL) {
    perror("Error, cannot open file");
    exit(EXIT_FAILURE);
  }

  // Read file
  char c;
  while ((c = fgetc(f)) != EOF) {
    printf("%c", c);
  }

  fclose(f);

  return 0;
}