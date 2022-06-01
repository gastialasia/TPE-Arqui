#ifndef _shell_
#define _shell_

void shell(void);
void parser(char * buffer);
void simpleScreenWrapper(char(*fn)(char*));
uint64_t getFuncFromString(char*str);

#endif
