#include <stdio.h>
#include <signal.h>
// read, pipe
#include <unistd.h>
// errno
#include <errno.h>

void myhandler(int sigtype)
{
  printf("got signal %d\n", sigtype);
}

void main()
{
  struct sigaction action;
  int  n, p[2];
  char buf[1000];

  pipe(p);

  action.sa_handler = myhandler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = SA_RESTART;
  // read will return -1
  // action.sa_flags = 0;

  sigaction(SIGINT, &action, NULL);

  while(1) {
    n = read(p[0], buf, 1000);
    printf("read returned %d, errno = %d\n", n, errno);
  }
}
