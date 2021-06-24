#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
// warning: implicit declaration of function ‘write’ [-Wimplicit-function-declaration]
// warning: implicit declaration of function ‘close’ [-Wimplicit-function-declaration]
#include <unistd.h>

void main()
{
  int fd;
  // bar should have 0444 permissions to make this fail
  fd = open("bar", O_WRONLY | O_CREAT, 0644);
  if (fd < 0) {
    printf("error number %d\n", errno);
    perror("bar");
    exit(1);
  }
  write(fd, "hello world", 11);
  close(fd);
}

