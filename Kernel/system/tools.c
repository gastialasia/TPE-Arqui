#include <tools.h>

#define DIFF 'A'-'a'
#define MIN 'a'
#define MAX 'z'
#define PIPE_KEY 125
#define PIPE_ASCII 124

char toMayusc(char c){
    if(isAlpha(c)){
        return c + DIFF;
    } else if (isPipe(c)) {
        return PIPE_ASCII;
    }
    return c;
}

char isAlpha(char c){
    return c >= MIN && c <= MAX;
}

char isPipe(char c){
    return c==PIPE_KEY;
}
