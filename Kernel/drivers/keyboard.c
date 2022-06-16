#include <keyboard.h>
#include <naiveConsole.h>
#include <lib.h>
#include <syscalls.h>

unsigned char key = 0;
extern unsigned char last;

unsigned char readKey(){
	// Agregar chequeo de tecla
	unsigned char aux = key;
	key = 0;
	return aux;
}

void keyboard_handler() {
	key = ASCIITable[getKey()];
	if(key != 0)
		last = key;
}
