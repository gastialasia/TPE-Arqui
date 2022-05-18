#include <keyboard.h>
#include <naiveConsole.h>
#include <lib.h>

void keyboard_handler() {
	char key = kbd_US[getKey()];
	if (key==8){
		ncDeleteChar();
	} else if(key){
		ncPrintChar(key);
	}
}