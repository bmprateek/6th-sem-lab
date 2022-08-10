#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]){
	DIR *dp; struct dirent *dirp;
	struct stat st;
	dp = opendir(".");
	while((dirp = readdir(dp))!= NULL){
		int fd = open(dirp->d_name , O_RDWR , 0777);
		int n = lseek(fd , 0 , SEEK_END);
		if(!n)
			unlink(dirp->d_name);
	}
	return 0;
}
