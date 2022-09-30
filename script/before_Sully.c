#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

char out_code_name[42];
char out_exec_name[42];
char out_bytes[100000];

const char * s = "$";

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
  sprintf(out_bytes, `);

  const char *argv[] = {
    "-Wall", "-Wextra","-Werror", "-o", out_code_name, out_exec_name
  };

  if (i == 0) {
    return 0;
  }
  else {
    int fd = open(out_code_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, out_bytes, strlen(out_bytes));
    fork_execve("clang", argv);
    execvp(out_exec_name, NULL);
  }
}