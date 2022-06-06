#include <syscalls.h>

#define STDIN 1
#define LEFTSCREEN 2
#define RIGHTSCREEN 3
#define DEFAULT_RETVALUE -1

static char mayusc = 0;
unsigned char last;

static char screenMode = 1;
static char * runningPrograms[2] = {0,0};

void (*printCharPtr)(char*) = ncPrintChar;
void (*printPtr)(char*) = ncPrint;
void (*printHexPtr)(char*) = ncPrintHex;

char * getScreenModePtr(){
	return &screenMode;
}

char ** getRunningProgramPtr(int index){
	return &runningPrograms[index];
}

int64_t write(int fd, const char *buffer, size_t count)
{
	for (int i = 0; i < count; i++)
	{
		printCharPtr(buffer[i]);
	}
}

int64_t read(int fd, char *buffer, size_t count)
{
	if (fd == STDIN)
	{
		int k = 0;
		unsigned char key = 0;

		while (key != '\n' && k < count)
		{
			_hlt();
			key = readKey();
			switch (key)
			{
			case 0:
				break;
			case 8: // Borrado
			{
				if (k > 0)
				{
					ncDeleteChar();
					k--;
				}
				break;
			}
			case 14:
			case 15:
				mayusc = 1;
				break;
			case 170:
			case 182:
				mayusc = 0;
				break;
			default:
			{
				if (mayusc)
					key = toMayusc(key);
				printCharPtr(key);
				buffer[k++] = key;
			}
			}
		}
		if (key != '\n')
		{
			ncNewline();
		}
		buffer[k] = 0;
		return k; // placeholder
	}
	return DEFAULT_RETVALUE;
}

void printMem(uint64_t pointer)
{
	uint8_t *start = (uint8_t *)pointer;
	for (int i = 0; i < 32; i++)
	{
		printHexPtr(start[i]);
		printCharPtr(' ');
	}
	printCharPtr('\n');
}

void clear()
{
	ncClear();
}

int64_t date(char value)
{
	return rtcGetter(value);
}

void inforeg()
{
	registersT *regs;	   // Pasamos el puntero a la struct para llenarla con los valores de los registros
	regs = getRegisters(); // en la funcion fillRegisters de libasm
	printPtr("RAX: ");
	printHexPtr(regs->rax);
	printCharPtr('\n');

	printPtr("RBX: ");
	printHexPtr(regs->rbx);
	printCharPtr('\n');

	printPtr("RCX: ");
	printHexPtr(regs->rcx);
	printCharPtr('\n');

	printPtr("RDX: ");
	printHexPtr(regs->rdx);
	printCharPtr('\n');

	printPtr("RDI: ");
	printHexPtr(regs->rdi);
	printCharPtr('\n');

	printPtr("RSI: ");
	printHexPtr(regs->rsi);
	printCharPtr('\n');

	printPtr("RBP: ");
	printHexPtr(regs->rbp);
	printCharPtr('\n');

	printPtr("RSP: ");
	printHexPtr(regs->rsp);
	printCharPtr('\n');

	printPtr("R8: ");
	printHexPtr(regs->r8);
	printCharPtr('\n');

	printPtr("R9: ");
	printHexPtr(regs->r9);
	printCharPtr('\n');

	printPtr("R10: ");
	printHexPtr(regs->r10);
	printCharPtr('\n');

	printPtr("R11: ");
	printHexPtr(regs->r11);
	printCharPtr('\n');

	printPtr("R12: ");
	printHexPtr(regs->r12);
	printCharPtr('\n');

	printPtr("R13: ");
	printHexPtr(regs->r13);
	printCharPtr('\n');

	printPtr("R14: ");
	printHexPtr(regs->r14);
	printCharPtr('\n');

	printPtr("R15: ");
	printHexPtr(regs->r15);
	printCharPtr('\n');
}

int64_t getLast(){
    return last;
}

void sleep(int secs)
{
	tSleep(secs);
}

void setScreenMode(int mode)
{
	screenMode = mode;
	switch (mode)
	{
	case 2:
		ncSplit();
		printCharPtr = ncPrintCharL;
		printPtr = ncPrintL;
		printHexPtr = ncPrintHexL;
		break;
	case 3:
		ncSplit();
		printCharPtr = ncPrintCharR;
		printPtr = ncPrintR;
		printHexPtr = ncPrintHexR;
		break;
	default:
		ncUnSplit();
		printCharPtr = ncPrintChar;
		printPtr = ncPrint;
		printHexPtr = ncPrintHex;
	}
}

void storeProgram(char*p1, char*p2){
	runningPrograms[0] = p1;
	runningPrograms[1] = p2;
}

char * getProgram(char id){
	if (id>1||id<0){
		return 0;
	}
	//ncPrint("Getting program: ");
	//ncPrint(runningPrograms[id]);
	//ncPrint("\n");
	return runningPrograms[id];
}
