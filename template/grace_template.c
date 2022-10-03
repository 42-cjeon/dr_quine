#include <stdio.h>
#define DECL_MAIN() int main(void) { printf($ARG$); return 0; }

const char *meta = "$STR$";

/*
  ANYWAY IT WORKS!
*/
DECL_MAIN()