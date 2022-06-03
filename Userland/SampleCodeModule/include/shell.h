#ifndef _shell_
#define _shell_

void shell(void);
void parser(char * buffer);
void simpleScreenWrapper(char(*fn)(void));
void SplitScreenWrapper(char(*fn1)(void),char(*fn2)(void));
uint64_t getFuncFromString(char*str);
#endif
