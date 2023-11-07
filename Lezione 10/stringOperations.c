#include <stdio.h>
// #include <string.h>

/**
 * strchr: returns a pointer to the first occurrence of the character c in the
 *
 * @param s: string to be searched
 * @param c: character to be searched
 */
char *strchr(char *s, int c) {
  while (*s != '\0') {
    if (*s == c) {
      return s;
    }
    s++;
  }
  return NULL;
}

/**
 * strstr: returns a pointer to the first occurrence of the string pattern in
 *
 * @param s: string to be searched
 * @param pattern: string to be searched
 */
char *strstr(char *s, char *pattern) {
  while (*s != '\0') {
    char *p = pattern;
    char *q = s;

    while (*p != '\0' && *q != '\0' && *p == *q) {
      p++;
      q++;
    }

    if (*p == '\0') {
      return s;
    }

    s++;
  }
  return NULL;
}

int main() {
  char string[] = "This is is is is a string";

  // Test for strchr
  char *p = strchr(string, 's');

  if (p != NULL) {
    printf("Found at position %ld\n", p - string);
  } else {
    printf("Not found\n");
  }

  // Test for strstr
  char *p2 = strstr(string, "is");

  if (p2 != NULL) {
    printf("Found at position %ld\n", p2 - string);
  } else {
    printf("Not found\n");
  }

  return 0;
}