#include <syscalls.h>
#include <stdint.h>
#include <stddef.h>
#include <syscalls.h>
#include <naiveConsole.h>

static int syscallnumber;

void syscallsetter(int64_t syscall){
	syscallnumber = syscall;
}

int64_t syscallDispatcher(int64_t arg0, int64_t arg1, int64_t arg2) {
    switch (syscallnumber)
    {
    case 1:
        return read((int) arg0, (char*) arg1, (size_t) arg2);
    case 2:
        return write((int) arg0, (const char*) arg1, (size_t) arg2);
    case 3:
        clear();
        return;
    case 4:
	   return printMem((uint64_t) arg0);
    case 6:
        return date((char)arg0);
    default:
        return -1;
    }
    return -1;
}
