#ifndef _sdtlib_
#define _sdtlib_

#include <stdint.h>

int strlen(const char *);

void putchar(const char c);

void printf(const char *);

void printInt(int num);

int scanf(char * buffer);

void clear();

void printdate();

char getchar();

int strcmp(const char *str1, const char *str2);

//uint64_t hex2int(char *hex, int *ok);

#endif