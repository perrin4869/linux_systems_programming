#include <fcntl.h>
// warning: implicit declaration of function ‘write’ [-Wimplicit-function-declaration]
// warning: implicit declaration of function ‘close’ [-Wimplicit-function-declaration]
#include <unistd.h>

void main()
{
  int fd;
  fd = open("foo", O_WRONLY | O_CREAT, 0644);
  write(fd, "hello world", 11);
  close(fd);
}
