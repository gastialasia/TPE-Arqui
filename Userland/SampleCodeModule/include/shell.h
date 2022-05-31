#ifndef _shell_
#define _shell_

void shell(void);
void parser(char * buffer);
void simpleScreenWrapper(uint64_t(*fn)(void));

#endif
