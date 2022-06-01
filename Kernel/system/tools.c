#include <tools.h>

#define DIFF 'A'-'a'
#define MIN 'a'
#define MAX 'z'

char toMayusc(char c){
    if(isAlpha)
        return c + DIFF;
    return c;
}

char isAlpha(char c){
    return c >= MIN && c <= MAX;
}
