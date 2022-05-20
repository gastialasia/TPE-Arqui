#include <syscalls.h>
#include <stdint.h>
#include <stddef.h>
#include <syscalls.h>
#include <naiveConsole.h>

int64_t syscallDispatcher(int64_t syscallNumber, int64_t arg0, int64_t arg1, int64_t arg2) {
    switch (syscallNumber)
    {
    case 2:
        return write((int) arg0, (const char*) arg1, (size_t) arg2);
    default:
        return -1;
    }
    return -1;
}