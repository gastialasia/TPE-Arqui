#ifndef _syscalls_
#define _syscalls_

#include <stdint.h>
#include <stddef.h>
#include <naiveConsole.h>
#include <keyboard.h>
#include <interrupts.h>
#include <time.h>
#include <lib.h>
#include <tools.h>

int64_t write(int fd, const char * buffer, size_t count);

int64_t read(int fd, char * buffer, size_t count);

void clear();

void inforeg(registersT* regs);

int64_t date(char value);

void sleep(int ms);

void setScreenMode(int mode);

void storeProgram(char*p1, char*p2);

char * getProgram(char id);

int64_t getLast();

//void saveBackup();

void saveRegisters(registersT* registers);

void loadBackup(registersT* regs, registersT* backup);

void snapshotRegs();

void printMem(uint64_t pointer, unsigned char * buf);

#endif
