#ifndef _syscalls_
#define _syscalls_

#include <stdint.h>
#include <stddef.h>

int64_t write(int fd, const char * buffer, size_t count);

#endif
