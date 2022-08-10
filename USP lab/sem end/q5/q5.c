#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utime.h>
#include <time.h>
#include <fcntl.h>

int main(int argc , char* argv[])
{
int fd;
struct stat statbuf_1;
struct stat statbuf_2;
struct utimbuf times;

if(stat(argv[1] , &statbuf_1) < 0)
printf("Error\n");
if(stat(argv[2] , &statbuf_2) < 0)
printf("Erro \n");
printf("Before copying \n");
printf("Access time %s \n Modification time %s \n" , ctime(&statbuf_1.st_atime) , ctime(&statbuf_1.st_mtime));
times.modtime = statbuf_2.st_mtime;
times.actime = statbuf_2.st_atime;
if(utime(argv[1] , &times) < 0)
printf("error\n");
if(stat(argv[1] , &statbuf_1) <0)
printf("error\n");
printf("After copying \n");
printf("Access time %s \n Modification time %s \n" , ctime(&statbuf_1.st_atime) , ctime(&statbuf_1.st_mtime));

}
