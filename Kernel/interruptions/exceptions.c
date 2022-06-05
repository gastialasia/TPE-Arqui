#include <syscalls.h>

#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 6

extern void (*printCharPtr)(char*);
extern void (*printPtr)(char*);
extern void (*printHexPtr)(char*);
extern char * getScreenModePtr();
extern char ** getRunningProgramPtr(int index);

void killRunningProgram();


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
	killRunningProgram();
}

static void opcode(){
	printPtr("OPCODE EXCEPTION!\n");
	killRunningProgram();
}

void killRunningProgram(){
	char screenMode = *getScreenModePtr();
	if (screenMode>=2) {
		**getRunningProgramPtr(screenMode-2)=0; // Le pongo un null terminated en el primer caracter para "arruinar el string"
	}
}

void rebootTerm(){

	if (*getScreenModePtr()==1){
		sleep(3);
	}



	//write(1,"Presione cualquier tecla para volver a la shell",48);



	//ncClear();
}
