#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void){
	int pid ;
	if((pid = fork()) < 0){
		printf("Fork error\n");
		exit(0);
	}
	else if(pid == 0){
		 printf("first child, parent pid = %ld \n", (long) getppid());
		 printf("first child pid = %ld  before fork\n", (long) getpid());
		if((pid = fork()) < 0){
			printf("Fork error\n");
                	exit(0);
		}
		else if(pid>0){
			printf("first child pid = %ld after fork\n", (long) getpid());
			exit(0);
		}
		sleep(2);
		printf("second child, parent pid = %ld \n", (long) getppid());
		exit(0);
	}
	if(waitpid(pid , NULL, 0)!= pid)
		printf("waitpid error \n");
	exit(0);
}
