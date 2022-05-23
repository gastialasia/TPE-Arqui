#include <stdlib.h>
#include <syscallslib.h>

int strlen(const char * str) {
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

void printf(const char * str) {
    sys_write(1, str, strlen(str)); //se puede romper aca
}