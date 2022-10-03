#include <stdio.h>

/*
  OUTSIDE!
*/
const char *meta = "#include <stdio.h>%c%c/*%c  OUTSIDE!%c*/%cconst char *meta = %c%s%c;%c%cvoid ft(void) {%c  printf(meta, 10, 10, 10, 10, 10, 34, meta, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main(void) {%c  /*%c    INSIDE!%c  */%c  ft();%c  return 0;%c}%c";

void ft(void) {
  printf(meta, 10, 10, 10, 10, 10, 34, meta, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main(void) {
  /*
    INSIDE!
  */
  ft();
  return 0;
}
