#include <time.h>
#include <interrupts.h>

#define TICKSPERSECOND 18

static unsigned long ticks = 0;

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / TICKSPERSECOND;
}

void tSleep(int secs){
	int final_ticks = ticks + secs*TICKSPERSECOND;
	while(ticks <= final_ticks)
		_hlt();
}
