#include <err.h>
#include <stdio.h>

#define meta "#include <err.h>%c#include <stdio.h>%c%c#define meta %c%s%c%c%c#define DECL_MAIN() %c%c  int main(void) {  %c%c    write_file();   %c%c    return 0;       %c%c  }%c%c#define WRITE_FILE(filename)             %c%c  void write_file(void) {                %c%c    FILE *handle = fopen(filename, %cw%c); %c%c                                         %c%c    if (handle == NULL) err(1, %cfopen%c); %c%c    fprintf(handle, meta, 10, 10, 10, 34, meta, 34, 10, 10, 92, 10, 92, 10, 92, 10, 92, 10, 10, 10, 92, 10, 92, 10, 34, 34, 92, 10, 92, 10, 34, 34, 92, 10, 92, 10, 10, 10, 10, 10, 10, 34, 34, 10);              %c%c  }%c%c/*%c  ANYWAY IT WORKS!%c*/%cWRITE_FILE(%cGrace_kid.c%c)%cDECL_MAIN()"

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
    fprintf(handle, meta, 10, 10, 10, 34, meta, 34, 10, 10, 92, 10, 92, 10, 92, 10, 92, 10, 10, 10, 92, 10, 92, 10, 34, 34, 92, 10, 92, 10, 34, 34, 92, 10, 92, 10, 10, 10, 10, 10, 10, 34, 34, 10);              \
  }

/*
  ANYWAY IT WORKS!
*/
WRITE_FILE("Grace_kid.c")
DECL_MAIN()