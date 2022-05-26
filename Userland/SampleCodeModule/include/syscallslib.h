#ifndef _syscallslib_
#define _syscallslib_

#include <stddef.h>
#include <stdint.h>

void sys_write(int fd, const char * buffer, size_t count);
int sys_read(int fd, char * buffer, size_t count);
void sys_printMem(uint64_t pointer);
void sys_clear();
char sys_date(char value);

#endif