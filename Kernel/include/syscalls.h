#ifndef _syscalls_
#define _syscalls_

#include <stdint.h>
#include <stddef.h>


int64_t write(int fd, const char * buffer, size_t count);

int64_t read(int fd, char * buffer, size_t count);

void clear();

void inforeg();

int64_t date(char value);

void sleep(int secs);

void setScreenMode(int mode);

#endif
