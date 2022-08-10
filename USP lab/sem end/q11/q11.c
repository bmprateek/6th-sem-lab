#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction sig;

void handler()
{
        printf("Interrupt recieved\n");
        sig.sa_handler = SIG_DFL;
        sigaction(SIGINT , &sig , 0);
}
void main(){
        sig.sa_flags =0;
        sigemptyset(&sig.sa_mask);
        sigaddset(&sig.sa_mask , SIGINT);
        sig.sa_handler = handler;
        sigaction(SIGINT , &sig , 0);

        while(1)
        {
                printf("Progress is Happiness!\n");
                sleep(1);
        }
}
