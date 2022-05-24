#ifndef _sdtlib_
#define _sdtlib_

#include <stdint.h>

int strlen(const char *);

void printf(const char *);

int scanf(char * buffer);

uint64_t hex2int(char *hex, int *ok);

#endif