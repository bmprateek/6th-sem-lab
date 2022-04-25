#include<stdio.h>
#include<stdlib.h>
static void my_exit1(void);
static void my_exit2(void);

int main(int argc , char *argv[])
{
    int i;
    for(i=0;i<argc;i++)
        printf("argv[%d]:%s \n" , i , argv[i]);
}
