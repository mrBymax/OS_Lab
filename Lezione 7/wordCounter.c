#include <stdio.h>

/**
 * This program counts the number of lines, words and characters in the input.
 * It takes no arguments and reads from standard input.
 * It prints the number of lines, words and characters to standard output.
 */
int main(int argc, char const *argv[]) {
  int inChar, newlineCounter, wordCounter, charCounter, inWord;

  newlineCounter = wordCounter = charCounter = inWord = 0;

  while ((inChar = getchar()) != EOF) {
    ++charCounter;
    if (inChar == '\n') {
      ++newlineCounter;
    }
    if (inChar == ' ' || inChar == '\n' || inChar == '\t') {
      inWord = 0;
    } else if (inWord == 0) {
      inWord = 1;
      ++wordCounter;
    }
  }

  printf("Lines: %d\nWords: %d\nCharacters: %d\n", newlineCounter, wordCounter,
         charCounter);

  return 0;
}