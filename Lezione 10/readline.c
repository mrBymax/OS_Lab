#include <stdio.h>
#include <string.h>

/**
 * readline: reads a line from the standard input and stores it in a string
 *
 * @param s: string to store the line
 * @param size: size of the string
 */
int readline(char* line, unsigned len) {
  char c;
  unsigned i = 0;

  printf("%s", "Insert a string: ");
  while ((c = getchar()) != '\n' && i < len && c != EOF) {
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}

/**
 * Checks if a string is terminated with a null character.
 * 
 * @param string The string to check.
 * @param len The length of the string.
 * @return 1 if the string is terminated with a null character, 0 otherwise.
 */
int checkStringTermination(char* string, unsigned len) {
    for (unsigned i = 0; i < len; i++) {
        if (string[i] == '\0') {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("%s", "ERROR! - Usage: ./readline <string>\n");
    return 1;
  };

  char line[100];
  int e = readline(line, 100);

  if (e == 0) {
    printf("ERROR! - Usage: ./readline <string>\n");
    return 1;
  } else if (checkStringTermination(line, 100)) {
    printf("ERROR! - String too long\n");
    return 1;
  }

  printf("Line updated: %s\n", line);
  printf("Read %d characters\n", e);

  printf("%s", "String is terminated correctly.\n");

  return 0;
}