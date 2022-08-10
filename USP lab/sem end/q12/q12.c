#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void callback(){
	printf("Interrupt Received !\n");
	signal(SIGINT , SIG_DFL);
}

void main(){
	int ch , i =0;
	printf("Enter choice 1: call handler and default\n2: ignore first time and default\n");
	scanf("%d",&ch);
	switch(ch){
	case 1: signal(SIGINT , callback);
	break;
	case 2: signal (SIGINT , SIG_IGN);
	break;
	}

	while(1)
	{
	sleep(1);
	printf("Press CTRL+C ...\n");
	i++;
	if(ch == 2 && i == 5)
		signal(SIGINT , SIG_DFL);
	}
}
