/**
 * This program draws a histogram of the lengths of the words in an array of
 * strings. The histogram is drawn using the '-' character, and the length of
 * the longest word determines the width of the histogram. The program takes an
 * array of strings as input, and prints the histogram to the console.
 *
 * @param words[] An array of strings to draw the histogram from.
 */

#include <stdio.h>
#include <stdlib.h>

void drawWordsHistogram(char* words[]) {
  // Count the number of words in the array
  int wordCounter = 0;

  while (words[wordCounter] != NULL) {
    wordCounter++;
  }

  int i, j, k, max = 0;

  // Calculate the length of each word and find the longest word in the array
  int* lengths = malloc(sizeof(int) * wordCounter);

  for (i = 0; i < wordCounter; i++) {
    lengths[i] = 0;
    while (words[i][lengths[i]] != '\0') {
      lengths[i]++;
    }
    if (lengths[i] > max) {
      max = lengths[i];
    }
  }

  // Draw the histogram
  for (i = 0; i < wordCounter; i++) {
    printf("%s", words[i]);
    // Print spaces to align the histogram
    for (j = 0; j < max - lengths[i]; j++) {
      printf(" ");
    }
    printf(" | ");
    // Print the histogram
    for (k = 0; k < lengths[i]; k++) {
      printf("-");
    }
    printf("\n");
  }
}

int main() {
  char* words[] = {"lorem",       "ipsum",      "dolor", "sit", "amet",
                   "consectetur", "adipiscing", "elit",  NULL};

  printf("Words histogram:\n\n");
  drawWordsHistogram(words);

  return 0;
}