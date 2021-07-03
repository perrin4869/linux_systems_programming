#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
// fork
#include <unistd.h>

main()
{
  int status;
  int a, b, c;

  if (fork())
  {
    /* Parent */
    wait(&status);
    if (WIFEXITED(status))
      printf("Child exited normally with exit status %d\n", WEXITSTATUS(status));
    if (WIFSIGNALED(status))
      printf("Child exited on signal %d: %s\n", WTERMSIG(status), strsignal(WTERMSIG(status)));
  }
  else
  {
    /* Child */
    printf("Child PID = %d\n", getpid());

    // Uncomment to cause a signal 11 exit
    // *(int *)0 = 99;

    // Uncomment to cause a signal 8 floating point exit
    // a = 1; b = 0; c = a/b;

    // Uncomment and send a signal 15 SIGTERM
    // kill -TERM {pid}
    // pause();

    sleep(3);
    exit(5);
  }
}
