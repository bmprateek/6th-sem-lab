#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
        int fd1=0,fd2=0;
        char buff[50];
        if((fd1=open("t12.txt",O_RDWR,0))<0){
                printf("file open error");
                exit(0);
        }
        fd2=dup2(fd1,10);
        printf("%d %d\n",fd1,fd2);
        read(fd1,buff,10);
        lseek(fd1,0,SEEK_END);
        write(fd2,buff,10);
        printf("%s\n",buff);
        return 0;
}
