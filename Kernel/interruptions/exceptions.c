#include <naiveConsole.h>
#include <syscalls.h>
#include "../include/keyboard.h"

#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 6

extern void (*printCharPtr)(char*);
extern void (*printPtr)(char*);
extern void (*printHexPtr)(char*);

static void zero_division();
static void opcode();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	else if(exception == OPCODE_EXCEPTION_ID)
		opcode();
}

static void zero_division() {
	printPtr("ZERO DIVISION ERROR!\n");
}

static void opcode(){
	printPtr("OPCODE EXCEPTION!\n");
}

void rebootTerm(){

	sleep(5);

	write(1,"Presione cualquier tecla para volver a la shell",48);



	//ncClear();
}
