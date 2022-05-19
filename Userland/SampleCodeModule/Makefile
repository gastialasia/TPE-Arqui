include Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
#SOURCES_ASM=$(wildcard *.asm)
#OBJECT_ASM=$(SOURCES_ASM: .asm=.o)

all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -c sampleCodeModule.ld _loader.c $(SOURCES) -o ../$(MODULE) 
	$(GCC) $(GCCFLAGS) -I./include -T sampleCodeModule.ld -Wl,--oformat=elf64-x86-64 _loader.c $(SOURCES) -o ../$(MODULE) -o ../0000-sampleCodeModule.elf

#%.o : %.asm
#	$(ASM) $(ASMFLAGS) $< -o $@
#%.o: %.c
#	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@

clean:
	rm -rf *.o

.PHONY: all clean print
