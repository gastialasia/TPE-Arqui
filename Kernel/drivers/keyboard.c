#include <keyboard.h>
#include <naiveConsole.h>
#include <lib.h>

void keyboard_handler() {
	unsigned char key = ASCIITable[getKey()];
	if (key==8){
		ncDeleteChar();
	} else if(key){
		ncPrintChar(key);
	}
}