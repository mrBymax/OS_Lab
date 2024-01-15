#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
    return 1;
  }

  char* endptr = NULL;
  pid_t pid = strtoll(argv[1], &endptr, 10);

  if(*endptr != 0){
    fprintf(stderr, "You need to specify a valid PID\n");
  }

  if(kill(pid, SIGKILL) == -1){
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return 2;
  }

  return 0;
}