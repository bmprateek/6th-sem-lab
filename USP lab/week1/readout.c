#include <unistd.h>
int main(){
        char buff[30];
        read(0,buff,30);
        write(1,buff,30);
        return 0;
}
