#include <stdio.h>

/*
  OUTSIDE!
*/
const char *meta = "$STR$";

void ft(void) {
  printf($ARG$);
}

int main(void) {
  /*
    INSIDE!
  */
  ft();
  return 0;
}
