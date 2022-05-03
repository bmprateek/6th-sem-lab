#include<stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
        char buff[20];
        read(0,buff,10);
        int count = 0,i=0;
        printf("len: %d\n",strlen(buff));
        for(i=0;i<strlen(buff);i++){
                if((buff[i]-' ')>=0 && buff[i]!='\0'){
                        count++;
                        printf("%c \n",buff[i]);
                }
        }
        char c[] = {count+'0'};
        write(1,c,1);
        return 0;
}
