/* Simple signal demo */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
// sleep
#include <unistd.h>

int n;

void handler(int signum)
{
  printf("signal %d received - counter reset\n", signum);
  n = 0;
}

main()
{
  signal(SIGINT, handler);
  signal(SIGQUIT, SIG_IGN); // kill -QUIT $(pgrep simplehandler)
  signal(SIGTERM, SIG_IGN); // kill -TERM $(pgrep simplehandler)
  while(1) {
    printf("Workingn %d\n", n++);
    sleep(1);
  }
}
