#include <stdio.h>
#include <unistd.h>

int main() {
  printf("%s %d\n", "Generate a single process with PID ", (int)getpid());

  printf("%s\n", "fork() Call....");

  pid_t pid = fork();

  if (pid == 0)
    printf("%s %d\n", "Child process with PID ", (int)getpid());
  else if (pid > 0)
    printf("%s %d\n", "Parent process with PID ", (int)getpid());
  else
    printf("%s\n", "Error");

  return 0;
}