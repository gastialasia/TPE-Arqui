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
	ncPrint("ZERO DIVISION ERROR!\n");
}

static void opcode(){
	ncPrint("OPCODE EXCEPTION!\n");
}
void rebootTerm(){

	ncPrint("Presione cualquier tecla para volver a la shell");

	while(1){
	_hlt();

	unsigned char key = readKey();
	if(key != 0){
		break;
	}

	}
	ncClear();

}
