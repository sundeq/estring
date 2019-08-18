CC=gcc
CFLAGS=-I

mainmake: main.c
	$(CC) -o main.o main.c estring.c
