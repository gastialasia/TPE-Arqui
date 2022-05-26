#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>

void ncPrint(const char * string);
void ncPrintChar(char character);
void ncPrintCharR(char character);
void ncPrintCharL(char character);

void ncDeleteChar();

void ncPrintCharAt(char character, uint32_t x, uint32_t y);

void ncNewline();
void ncNewLineL();
void ncNewLineR();

void ncPrintDec(uint64_t value);
void ncPrintDecL(uint64_t value);
void ncPrintDecR(uint64_t value);

void ncPrintHex(uint64_t value);
void ncPrintHexL(uint64_t value);
void ncPrintHexR(uint64_t value);

void ncPrintBin(uint64_t value);
void ncPrintBinL(uint64_t value);
void ncPrintBinR(uint64_t value);

void ncPrintBase(uint64_t value, uint32_t base);
void ncPrintBaseL(uint64_t value, uint32_t base);
void ncPrintBaseR(uint64_t value, uint32_t base);

void ncClear();

void ncSplit();

#endif