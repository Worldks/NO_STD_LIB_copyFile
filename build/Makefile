LD = ld
CC = gcc
CFLAGS = -m32 -fno-stack-protector -Wall -g -ansi -pedantic

remove:
	rm start.o calls.o number_convert.o main.o prog
clear:
	rm start.o calls.o number_convert.o main.o
start.o: ../asm_module/start.asm
	nasm -f elf ../asm_module/start.asm -o start.o
calls.o: ../asm_module/calls.asm
	nasm -f elf ../asm_module/calls.asm -o calls.o
number_convert.o:
	$(CC) $(CFLAGS) -c ../src/number_convert.c -o number_convert.o
main.o: ../src/main.c
	$(CC) $(CFLAGS) -c ../src/main.c -o main.o
prog: main.o number_convert.o start.o calls.o
	$(LD) -m elf_i386 main.o start.o calls.o number_convert.o -o prog
