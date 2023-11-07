#include <stdio.h>

int main() {
  int n = 0, sum = 0;  // n is the current integer read from standard input, sum
                       // is the sum of all integers read so far.

  // This code reads integers from standard input until the end of file is
  // reached and calculates their sum.
  while (scanf("%d", &n) != EOF) {
    sum += n;
  }

  // Print the sum of all integers read from standard input.
  printf("%d\n", sum);

  return 0;
}