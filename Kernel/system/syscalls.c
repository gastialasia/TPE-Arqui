#include <naiveConsole.h>
#include <syscalls.h>
#include <keyboard.h>
#include <interrupts.h>

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
			if (key){
				ncPrintDec(1);
				ncPrintChar(key);
				buffer[k++]=key;
			}
		}
		if (key!='\n'){
			ncNewline();
		}
		buffer[k]=0;
		return k; //placeholder
	}
	return -1;

}



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
