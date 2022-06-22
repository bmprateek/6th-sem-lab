#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
static void charatatime(char*);

int main(void)
{
  pid_t pid;
  if ((pid = fork()) < 0)
  {
    printf("fork error");
  }
  else if (pid == 0)
  {
    charatatime("output from childccccccccccccccccccccccccccccccccc\n");
  }
  else
  {
    charatatime("output from parentpppppppppppppppppppppppp\n");
  }
  exit(0);
}

static void charatatime(char* str)
{
char *ptr;
int c;
setbuf(stdout , NULL);
for(ptr = str ; (c = *ptr++)!=0;)
//putc(c , stdout);
printf("%c" , c);
}
