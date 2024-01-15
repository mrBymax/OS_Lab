#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("%s", "executing ls command...\n");
  execl("/bin/ls", "ls", "-l", NULL);

  printf("%s", "This line will not be executed\n");
  for (int i = 0; i < 10; i++) printf("%s", "You'll never enter this loop\n");

  return 1; // The call to execl() has failed
}