#include <keyboard.h>
#include <naiveConsole.h>
#include <lib.h>

unsigned char key = 0;

unsigned char readKey(){
	// Agregar chequeo de tecla
	unsigned char aux = key;
	key = 0;
	return aux;
}

void keyboard_handler() {
	key = ASCIITable[getKey()];
}