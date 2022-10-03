#include <err.h>
#include <stdio.h>

#define meta "$STR$"

#define DECL_MAIN() \
  int main(void) {  \
    write_file();   \
    return 0;       \
  }

#define WRITE_FILE(filename)             \
  void write_file(void) {                \
    FILE *handle = fopen(filename, "w"); \
                                         \
    if (handle == NULL) err(1, "fopen"); \
    fprintf(handle, $ARG$);              \
  }

/*
  ANYWAY IT WORKS!
*/
WRITE_FILE("Grace_kid.c")
DECL_MAIN()