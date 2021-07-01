#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// wait
#include <sys/wait.h>

/* A minimal shell */
main() {
  char line[100];

  /* Main command loop */
  while (printf("> "), gets(line) != NULL) {
    if (fork() == 0) { /* Child */

      execlp(line, line, (char *)0);

      /* Don't come here unless execlp fails */
      printf("%s: not found\n", line);
      exit(1);
    }
    else wait(0); /* Parent */

    /* Now loop back and prompt again */
  }
}
