#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define COLS 60
#define ROWS 30

int main() {
  // Hide cursor
  printf("\e[?25l");

  // Switch to canonical mode, disable echo
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  int x[1000], y[1000];  // Snake position
  int quit = 0;

  while (!quit) {  // Render the arena
    printf("┌");
    for (int i = 0; i < COLS; i++) printf("─");
    printf("┐\n");

    for (int j = 0; j < ROWS; j++) {
      printf("│");
      for (int i = 0; i < COLS; i++) printf("·");
      printf("│\n");
    }

    printf("└");
    for (int i = 0; i < COLS; i++) printf("─");
    printf("┘\n");

    // Move cursor back to top
    printf("\e[%iA", ROWS + 2);

    int head = 0, tail = 0;

    // Place snake in the middle
    x[head] = COLS / 2;
    y[head] = ROWS / 2;

    int gameover = 0;
    int xdir = 1, ydir = 0;
    int applex = -1, appley;

    while (!quit && !gameover) {
      // Create new apple
      if (applex < 0) {
        applex = rand() % COLS;
        appley = rand() % ROWS;

        for (int i = tail; i != head; i = (i + 1) % 1000)
          if (x[i] == applex && y[i] == appley) applex = -1;

        // Draw apple
        if (applex >= 0) printf("\e[%i;%iH*", appley + 2, applex + 2);
      }

      // Move snake
      x[head] += xdir;
      y[head] += ydir;

      // Check for collision
      for (int i = 0; i < head; i = i + 1 % 1000)
        if (x[i] == x[head] && y[i] == y[head]) gameover = 1;

      // draw snake
      printf("\e[%i;%iH@", y[head] + 2, x[head] + 2);

      // Move cursor back to top
      printf("\e[%iA", ROWS + 2);

      // Read input
      char c = getchar();
      if (c == 'q')
        quit = 1;
      else if (c == 'w' && ydir != 1) {
        xdir = 0;
        ydir = -1;
      } else if (c == 'a' && xdir != 1) {
        xdir = -1;
        ydir = 0;
      } else if (c == 's' && ydir != -1) {
        xdir = 0;
        ydir = 1;
      } else if (c == 'd' && xdir != -1) {
        xdir = 1;
        ydir = 0;
      }
    }
  }

  if (quit) {
    // Show Game Over
    printf("\e[%iB\e[%iC Game Over! ", ROWS / 2, COLS / 2 - 5);
    printf("\e[%iF", ROWS / 2);
    fflush(stdout);
    getchar();
  }

  // Show cursor
  printf("\e[?25h");

  // Switch back to normal mode
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return 0;
}