#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void deamonize()
{
	pid_t pid  = fork();

	if(pid<0)
	{
		printf("Error forking \n");
	}
	else if(pid)
	{
		printf("PID of child %d \n" , pid);
		exit(0);
	}
	umask(0);
	if(chdir("/") < 0)
		printf("Error changing directory \n");
	if(setsid()<0)
		printf("Error creating a session \n");
	printf("Daemon Created! \n");
}

int main()
{
	deamonize();
	system("ps -axj");
	return 0;
}
