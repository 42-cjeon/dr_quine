#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define OUT_FILE_NAME_BASE "Sully"
#define COMPILER "clang"
#define COMPILE_FLAG "-x c -Wall -Wextra -Werror"

#define GET_FILENAME() strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__

const char *meta = "$STR$";

char out_source_name[64];
char out_binary_name[64];
char compile_cmd[(1<<7)];

int main(void) {
  int i = 5;

  if (i <= 0)
    return 0;

  if (strcmp(GET_FILENAME(), "Sully.c"))
    --i;

  sprintf(out_source_name, "./Sully_%d.c", i);
  sprintf(out_binary_name, "./Sully_%d", i);
  
  FILE *outfile = fopen(out_source_name, "w");
  if (outfile == NULL)
    err(1, "fopen");

  fprintf(outfile, $ARG$);

  fclose(outfile);

  sprintf(compile_cmd, COMPILER " " COMPILE_FLAG " -o %s %s", out_binary_name, out_source_name);
  int shell_result = system(compile_cmd);

  if (shell_result == -1)
    err(2, "system");
  
  if (shell_result != 0) {
    fprintf(stderr, "system: shell exited with non-zero value: %d%c", shell_result, 10);
    exit(3);
  }

  execlp(out_binary_name, NULL);
  err(4, "exec: `%s`", out_binary_name);
}
