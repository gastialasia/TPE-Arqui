#include <naiveConsole.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
//static uint8_t * currentVideoR = video + width + 2; //posicion inicial de la division de pantalla (el + 2 es para que este en la mitad mas 1 a la der)
//static uint8_t * currentVideoL = video;   //posicion inicial izq de la division de pantalla
static const uint32_t width = 80;
static const uint32_t height = 25 ;

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintChar(char character)
{
	if(currentVideo==(video+(width*height)*2)){
		ncMoveLines();
	}

	if(character == '\n') {
		ncNewline();
		return;
	}

	*currentVideo = character;
	currentVideo += 2;
}

void ncDeleteChar(){
	currentVideo -=2;
	*currentVideo = ' ';
}

void ncMoveLines(){
	for(int i=0;i<height*width*2;){
		if (i>=(height-1)*width*2){
			video[i]=' ';
			i+=2;
		} else {
			video[i]=video[i+width*2];
			i++;
		}
	}
	currentVideo=currentVideo-(width*2);
}

void ncPrintCharAt(char character, uint32_t x, uint32_t y){
	// No tengo en cuenta currentVideo, simplemente inserto en char en el punto(x,y)
	video[(width*y+x)*2]=character;
}

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
