#include <stdio.h>
#include <dirent.h>
int main(void) {
   DIR *dr;
   int count=0;
   struct dirent *en;
   dr = opendir("."); //open all or present directory
   if (dr) {
      while ((en = readdir(dr)) != NULL) {
         printf("%s\n", en->d_name); //print all directory name
        count++;
        }
      closedir(dr); //close all directory
   }
   printf("No of files: %d\n",count);
   return(0);
}
