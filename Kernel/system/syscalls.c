#include <naiveConsole.h>
#include <keyboard.h>
#include <interrupts.h>
#include <syscalls.h>
#include <lib.h>

int64_t write(int fd, const char * buffer, size_t count){
	switch(fd){
		case 1:
			for(int i = 0; i < count; i++){
				ncPrintChar(buffer[i]);
			}
			return count; //placeholder
		default:
			return -1;
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
	return -1;

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

//int date(char value)

/*char * date(){ //falta arreglar hexa y concatenar todo para el out.
	char out[16];
	char * sec = rtcGetter(0);
	char * min = rtcGetter(2);
	char * hour= rtcGetter(4);
	char * day = rtcGetter(7);
	char * month = rtcGetter(8);
	char * day = rtcGetter(9);
	out[0] = month;
	out[2] = '/'
	out[3] = day;
	out[6] = '/'
	out[7] = year;
	out[9] = ' '
	out[10] = hour;
	out[12] = '/'
	out[13] = min;
	
}*/
