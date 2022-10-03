#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define OUT_FILE_NAME_BASE "Sully"
#define COMPILER "clang"
#define COMPILE_FLAG "-x c -Wall -Wextra -Werror"

#define GET_FILENAME() strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__

const char *meta = "#include <stdio.h>%c#include <err.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <string.h>%c%c#define OUT_FILE_NAME_BASE %cSully%c%c#define COMPILER %cclang%c%c#define COMPILE_FLAG %c-x c -Wall -Wextra -Werror%c%c%c#define GET_FILENAME() strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__%c%cconst char *meta = %c%s%c;%c%cchar out_source_name[64];%cchar out_binary_name[64];%cchar compile_cmd[(1<<7)];%c%cint main(void) {%c  int i = %d;%c%c  if (i <= 0)%c    return 0;%c%c  if (strcmp(GET_FILENAME(), %cSully.c%c))%c    --i;%c%c  sprintf(out_source_name, %c./Sully_%cd.c%c, i);%c  sprintf(out_binary_name, %c./Sully_%cd%c, i);%c  %c  FILE *outfile = fopen(out_source_name, %cw%c);%c  if (outfile == NULL)%c    err(1, %cfopen%c);%c%c  fprintf(outfile, meta, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, 34, 10, 34, 34, 10, 10, 10, 10, 34, meta, 34, 10, 10, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 34, 37, 37, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 34, 37, 37, 34, 10, 10, 10, 10, 10, 34, 37, 34, 10, 10);%c%c  fclose(outfile);%c%c  sprintf(compile_cmd, COMPILER %c %c COMPILE_FLAG %c -o %cs %cs%c, out_binary_name, out_source_name);%c  int shell_result = system(compile_cmd);%c%c  if (shell_result == -1)%c    err(2, %csystem%c);%c  %c  if (shell_result != 0) {%c    fprintf(stderr, %csystem: shell exited with non-zero value: %cd%cc%c, shell_result, 10);%c    exit(3);%c  }%c%c  execlp(out_binary_name, NULL);%c  err(4, %cexec: `%cs`%c, out_binary_name);%c}%c";

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

  fprintf(outfile, meta, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, 34, 10, 34, 34, 10, 10, 10, 10, 34, meta, 34, 10, 10, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 34, 37, 37, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 34, 37, 37, 34, 10, 10, 10, 10, 10, 34, 37, 34, 10, 10);

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
