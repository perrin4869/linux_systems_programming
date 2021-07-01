/* Exit Status Demo */

#include <stdio.h>
#include <stdlib.h>
// sleep
#include <unistd.h>
// wait
#include <sys/wait.h>

int main()
{
  int status;
  if (fork()) {
    /* Parent */
    printf("parent waiting for child ...\n");
    wait(&status);
    if (WIFEXITED(status))
      printf("child ended normally, exit status = %d\n", WEXITSTATUS(status));
    if (WIFSIGNALED(status))
      printf("child terminated by signal = %d\n", WTERMSIG(status));
  } else  {
    /* Child */
    printf("child running -- PID is %d\n", getpid());
    // *(int *)0 = 10;
    // sleep(500);
    sleep(5);
    exit(3);
  }
}
