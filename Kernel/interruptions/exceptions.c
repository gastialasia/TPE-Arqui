#include <naiveConsole.h>
#include "../include/keyboard.h"

#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 6

static void zero_division();
static void opcode();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	else if(exception == OPCODE_EXCEPTION_ID)
		opcode();
}

static void zero_division() {
	write(1,"ZERO DIVISION ERROR!\n",23);
}

static void opcode(){
	write(1,"OPCODE EXCEPTION!\n",20);
}

void rebootTerm(){

	sleep(5);

	write(1,"Presione cualquier tecla para volver a la shell",48);



	//ncClear();
}
