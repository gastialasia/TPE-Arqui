#include <stdlib.h>
#include <syscallslib.h>

#define STDIN 1
#define MAXBUFFER 100

int strlen(const char * str) {
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

void printf(const char * str) {
    sys_write(STDIN, str, strlen(str)); //se puede romper aca
}

int scanf(char * buffer) {
    return sys_read(STDIN,buffer,MAXBUFFER);
}