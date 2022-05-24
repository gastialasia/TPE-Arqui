#include <stdlib.h>
#include <syscallslib.h>
#include <stdint.h>

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

uint64_t hex2int(char *hex, int *ok) {
    uint64_t val = 0;
    while (*hex) {
        // get current character then increment
        uint8_t byte = *hex++;
        
        if (!(byte >= '0' && byte <= '9') && !(byte >= 'a' && byte <= 'f') && !(byte >= 'A' && byte <= 'F')) {
          *ok = 0;
          return 0;
        }
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;    
        // shift 4 to make space for new digit, and add the 4 bits of the new digit 
        val = (val << 4) | (byte & 0xF);
    }
    return val;
}


