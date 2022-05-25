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

void putchar(const char c){
    sys_write(STDIN, &c, 1);
}

void printf(const char * str) {
    sys_write(STDIN, str, strlen(str)); //se puede romper aca
}

uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
    char *p = buffer;
    char *p1, *p2;
    uint32_t digits = 0;

    //Calculate characters for each digit
    do
    {
        uint32_t remainder = value % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        digits++;
    }
    while (value /= base);

    // Terminate string in buffer.
    *p = 0;

    //Reverse string in buffer.
    p1 = buffer;
    p2 = p - 1;
    while (p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }

    return digits;
}

void printInt(int num){
    char buffer[10];
    int len = uintToBase(num,buffer,10);
    sys_write(STDIN, buffer, len);
}

char getchar(){
    char c;
    sys_read(STDIN,&c,1);
    return c;
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

void clear(){
    sys_clear();
}


void printdate(){
    int values[5] = {7,8,9,4,2}; //En orden: D, M, Y, H, M
    //char * separators[5] = {" "," "," "," "};
    char buffer[2]; // Cada numero de la fecha no va a tener más de dos digitos
    for (int i=0;i<5;i++){
        char num = sys_date(values[i]);
        uintToBase(num,buffer,16);
        printf(buffer);
        if (i<2){
            printf("/");
        } else if (i==3){
            printf(":");
        } else {
            printf(" ");
        }
    }
    printf("UTC\n");
}

// Devuelve 1 si son iguales, 0 sino
int strcmp(const char *str1, const char *str2){
    int pos=0;
    while(str1[pos]&&str2[pos]){
        if (str1[pos]!=str2[pos]){
            return 0;
        }
        pos++;
    }
    if(str1[pos]||str2[pos]){
        return 0;
    }
    return 1;
}


