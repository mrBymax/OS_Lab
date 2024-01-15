#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MSGSIZE 14

int main() {
  int pipes[2] = {};
  if (pipe(pipes) == -1) perror("pipe call");

  char msg[MSGSIZE] = {};
  pid_t pid = fork();

  switch (pid) {
    case -1:
      perror("fork call");
      return 2;
    case 0:
      close(pipes[0]);
      write(pipes[1], "Hello World!", MSGSIZE);
      break;
    default:
      close(pipes[1]);
      read(pipes[0], msg, MSGSIZE);
      printf("%s\n", msg);
      wait(NULL);
  }

  return 0;
}