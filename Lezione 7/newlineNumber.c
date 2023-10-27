#include <stdio.h>

int main() {
  // Scan the standard input and count the number of newlines
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n') ++nl;

  printf("Number of newlines: %d\n", nl);

  return 0;
}