/**
 * This program counts the number of edits made in the file during a specific
 * time interval (in seconds).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: %s <file> <seconds>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the file
  FILE* f = fopen(argv[1], "r");

  if (f == NULL) {
    perror("Error, cannot open file");
    exit(EXIT_FAILURE);
  }

  // Store a copy of the file
  FILE* f_copy = fopen("temp.txt", "w");
  int c;

  if (f_copy == NULL) {
    perror("Error, cannot open file");
    exit(EXIT_FAILURE);
  } else {
    do {
      c = fgetc(f);
      fputc(c, f_copy);
      printf("%c", c);
    } while (c != EOF);
  }

  // Close the files
  fclose(f);

  printf("%s", "File copied\n");

  sleep(atoi(argv[2]));

  // Compare the two files
  int edits = 0;

  f = fopen(argv[1], "r");
  f_copy = fopen("temp.txt", "r");

  while ((c = fgetc(f)) != EOF && (c = fgetc(f_copy)) != EOF) {
    if (c != fgetc(f_copy)) edits++;
  }

  printf("Number of edits: %d\n", edits);

  fclose(f);
  fclose(f_copy);

  // Remove the copy
  remove("temp.txt");

  return 0;
}