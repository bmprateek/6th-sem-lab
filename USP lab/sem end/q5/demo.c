#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utime.h>
#include <time.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
	int fd;
	struct stat st1;
	struct stat st2;
	struct utimbuf times;
	
	if(stat(argv[1] , &st1) <0)
		printf("error\n");
	if(stat(argv[2] , &st2) <0)
                printf("error\n");
	printf("Before copying..\n");
	printf("Access time %s \n Modification time %s \n" , ctime(&st1.st_atime) , ctime(&st1.st_mtime));
	
	times.modtime = st2.st_mtime;
	times.actime = st2.st_atime;
	
	if(utime(argv[1] , &times) < 0)
		printf("Error copying\n");
	
	if(stat(argv[1] , &st1) < 0)
		printf("Error in stat structure after copying \n");
	printf("after copying\n");

	printf("Access Time %s\nModification Time%s\n", ctime(&st1.st_atime),
ctime(&st1.st_mtime));
}
