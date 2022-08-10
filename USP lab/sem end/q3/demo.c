#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc , char* argv[]){
	DIR *dp;
	struct dirent *dirp;
	struct stat st;
	dp = opendir(".");
	while((dirp = readdir(dp))!= NULL)
	{
		if(lstat(dirp->d_name , &st) == -1)
		{
			printf("stat error");
			exit(0);
		}
		printf("%s \n" , dirp->d_name);
		printf("I-node number:%ld\n", (long) st.st_ino);
		printf("Link count:%ld\n", (long) st.st_nlink);
		printf("Ownership:UID=%ld GID=%ld\n",(long) st.st_uid, (long) st.st_gid);
		printf("File size:%lld bytes\n",(long long) st.st_size);
		printf("Last file access:%s", ctime(&st.st_atime));
		printf("Last file modification:%s", ctime(&st.st_mtime));
		printf("\n\n");
	}
	closedir(dp);
	return 0;
}
