#include <naiveConsole.h>
#include "../include/keyboard.h"

#define ZERO_EXCEPTION_ID 0

static void zero_division();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
}

static void zero_division() {
	ncPrint("ZERO DIVISION ERROR!");
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
