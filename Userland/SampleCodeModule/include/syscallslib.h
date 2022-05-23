#ifndef _syscallslib_
#define _syscallslib_

#include <stddef.h>

void sys_write(int fd, const char * buffer, size_t count);
int sys_read(int fd, char * buffer, size_t count);

#endif