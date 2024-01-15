#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("%s", "\nStandard version\n");

  // Open /dev/urandom
  FILE* f = fopen("/dev/urandom", "rb");

  if (f == NULL) {
    perror("Error, cannot open file");
    exit(EXIT_FAILURE);
  }

  // Read 10 random numbers
  int i;
  for (i = 0; i < 10; i++) {
    int n;
    fread(&n, sizeof(int), 1, f);
    printf("%d\n", n);
  }

  fclose(f);

  /**
   *POSIX version
   */

#include <fcntl.h>

  printf("%s", "\nPOSIX version\n");

  // Open /dev/urandom
  int fd = open("/dev/urandom", O_RDONLY);

  if (fd == -1) {
    perror("Error, cannot open file");
    exit(EXIT_FAILURE);
  }

  // Read 10 random numbers
  for (i = 0; i < 10; i++) {
    int n;
    read(fd, &n, sizeof(int));
    printf("%d\n", n);
  }

  // Close file
  close(fd);

  return 0;
}