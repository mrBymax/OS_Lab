#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid = fork();

  switch (pid) {
    case -1:
      printf("%s\n", "Error");
      break;
    case 0:
      printf("%s %d\n", "Child process with PID ", (int)getpid());
      printf("%s", "executing ls command...\n");
      execl("/bin/ls", "ls", "-l", NULL);
      printf("%s", "This line will not be executed\n");
      for (int i = 0; i < 10; i++)
        printf("%s", "You'll never enter this loop\n");
      break;
    default:
      printf("%s %d\n", "Parent process with PID ", (int)getpid());
      break;
  }

  return 0;
}