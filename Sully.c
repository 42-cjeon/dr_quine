#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <err.h>

char out_code_name[42];
char out_exec_name[42];
char out_bytes[100000];

const char * s = "#include <stdio.h>%c#include <unistd.h>%c#include <sys/wait.h>%c#include <fcntl.h>%c#include <string.h>%c%cchar out_code_name[42];%cchar out_exec_name[42];%cchar out_bytes[100000];%c%cconst char * s = %c%s%c;%c%cint fork_execve(const char *fullpath, const char *argv[]) {%c  pid_t pid = fork();%c  int status = 1;%c  if (pid == -1) {%c    return 2;%c  } else if (pid == 0) {%c    execvp(fullpath, (char **)argv);%c    return 3;%c  } else {%c    waitpid(pid, &status, 0);%c    return status;%c  }%c}%c%cint printf(const char*,...);%cint main(void) {%c  int i=%d;%c  i=i<=0?0:i-1;%c  sprintf(out_code_name, %c/Users/cjeon/projects/dr_quine/Sully_%cd.c%c, i);%c  sprintf(out_exec_name, %c/Users/cjeon/projects/dr_quine/Sully_%cd%c, i);%c  sprintf(out_bytes, s, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, i, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 10, 10, 10, 34, 34, 34, 34, 34, 34, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10);%c%c  const char *argv[] = {%c    %c-Wall%c, %c-Wextra%c,%c-Werror%c, %c-o%c, out_code_name, out_exec_name%c  };%c%c  if (i == 0) {%c    return 0;%c  }%c  else {%c    int fd = open(out_code_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c    write(fd, out_bytes, strlen(out_bytes));%c    fork_execve(%cclang%c, argv);%c    execvp(out_exec_name, NULL);%c  }%c}";

// void pargv(const char *argv[]) {

// }

int fork_execve(const char *fullpath, const char *argv[]) {
  pid_t pid = fork();
  int status = 1;
  if (pid == -1) {
    return 2;
  } else if (pid == 0) {
    execvp(fullpath, (char **)argv);
    return 3;
  } else {
    waitpid(pid, &status, 0);
    return status;
  }
}

int printf(const char*,...);
int main(void) {
  int i=5;
  i=i<=0?0:i-1;
  sprintf(out_code_name, "/Users/cjeon/projects/dr_quine/Sully_%d.c", i);
  sprintf(out_exec_name, "/Users/cjeon/projects/dr_quine/Sully_%d", i);
  sprintf(out_bytes, s, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, i, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 10, 10, 10, 34, 34, 34, 34, 34, 34, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10);

  const char *argv[] = {
    "-Wall", "-Wextra","-Werror", "-o", out_exec_name, out_code_name, NULL
  };

  if (i == 0) {
    return 0;
  }
  else {
    int fd = open(out_code_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, out_bytes, strlen(out_bytes));
    int k = fork_execve("clang", argv);
    if (k)
      err(k, "inner");
    execvp(out_exec_name, NULL);
    err(5, "excvp");
  }
}