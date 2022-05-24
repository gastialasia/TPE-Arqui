#ifndef _syscalls_
#define _syscalls_

#include <stdint.h>
#include <stddef.h>

int64_t write(int fd, const char * buffer, size_t count);

int64_t read(int fd, char * buffer, size_t count);

void clear();

char date(char value);

#endif
