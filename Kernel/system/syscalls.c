#include <naiveConsole.h>
#include <keyboard.h>
#include <interrupts.h>
#include <syscalls.h>
#include <lib.h>

#define STDIN 1
#define LEFTSCREEN 2
#define RIGHTSCREEN 3
#define DEFAULT_RETVALUE -1

int64_t write(int fd, const char * buffer, size_t count){
	switch(fd){
		case STDIN:
			ncUnSplit();
			for(int i = 0; i < count; i++){
				ncPrintChar(buffer[i]);
			}
			return count; //placeholder
		case LEFTSCREEN:
			ncSplit();
			for(int i = 0; i < count; i++){
				ncPrintCharL(buffer[i]);
			}
			return count;
		case RIGHTSCREEN:
			ncSplit();
			for(int i = 0; i < count; i++){
				ncPrintCharR(buffer[i]);
			}
			return count;
		default:
			return DEFAULT_RETVALUE;
	}
}

int64_t read(int fd, char * buffer, size_t count){
	if(fd==1){
		_sti();
		int k = 0;
		unsigned char key = 0;

		while(key!='\n'&&k<count){
			key = readKey();
			switch (key){
				case 0:
					break;
				case 8: //Borrado
				{ 
					ncDeleteChar();
					k--;
					break;
				}
				default:
				{
					ncPrintChar(key);
					buffer[k++]=key;
				}
			}
		}
		if (key!='\n'){
			ncNewline();
		}
		buffer[k]=0;
		_cli();
		return k; //placeholder
	}
	return DEFAULT_RETVALUE;

}

void printMem(uint64_t pointer){
	uint8_t *start = (uint8_t*) pointer;
	for(int i =0; i < 32;i++){
		ncPrintHex(start[i]);
		ncPrint(' ');
	}
	ncNewline();
}

void clear(){
	ncClear();
}

int64_t date(char value){
	return rtcGetter(value);
}

void inforeg(){
	registersT* regs; //Pasamos el puntero a la struct para llenarla con los valores de los registros
	regs=getRegisters();  //en la funcion fillRegisters de libasm
	ncPrint("RAX: ");
	ncPrintDec(regs->rax);
	ncNewline();
	ncPrint("RBX: ");
	ncPrintDec(regs->rbx);
	ncNewline();
	ncPrint("RCX: ");
	ncPrintDec(regs->rcx);
	ncNewline();
	ncPrint("RDX: ");
	ncPrintDec(regs->rdx);
	ncNewline();
	ncPrint("RDI: ");
	ncPrintDec(regs->rdi);
	ncNewline();
	ncPrint("RSI: ");
	ncPrintDec(regs->rsi);
	ncNewline();
	ncPrint("RBP: ");
	ncPrintDec(regs->rbp);
	ncNewline();
	ncPrint("RSP: ");
	ncPrintDec(regs->rsp);
	ncNewline();
	ncPrint("R8: ");
	ncPrintDec(regs->r8);
	ncNewline();
	ncPrint("R9: ");
	ncPrintDec(regs->r9);
	ncNewline();
	ncPrint("R10: ");
	ncPrintDec(regs->r10);
	ncNewline();
	ncPrint("R11: ");
	ncPrintDec(regs->r11);
	ncNewline();
	ncPrint("R12: ");
	ncPrintDec(regs->r12);
	ncNewline();
	ncPrint("R13: ");
	ncPrintDec(regs->r13);
	ncNewline();
	ncPrint("R14: ");
	ncPrintDec(regs->r14);
	ncNewline();
	ncPrint("R15: ");
	ncPrintDec(regs->r15);
	ncNewline();
}
