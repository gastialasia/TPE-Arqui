#ifndef _sdtlib_
#define _sdtlib_

#include <stdint.h>

int strlen(const char *);

int strcmp(const char *str1, const char *str2);

void putchar(const char c);

void printf(const char *);

void inforeg(void);

void printInt(int num);

char getchar();

int scanf(char * buffer);

void clear();

void printdate();

void sleep(int secs);

void divzero();

void opcode();

int strcpy(char *dest, const char *src);

char getDateComponent(int value);

void setScreenMode(int mode);

//uint64_t hex2int(char *hex, int *ok);

#endif
