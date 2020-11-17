CC=gcc

CFLAGS=-O2 -ansi -Wall -pedantic
#CFLAGS=-g -Wall -D_REENTRANT
MATH_FLAGS=-lm
SOURCES=main.c funcoes.c Globais.c
OBJECTS=main.o funcoes.o Globais.o
BINARIES=main

all: $(BINARIES)

main: main.o funcoes.o Globais.o
	$(CC) -o main main.o funcoes.o Globais.o $(CFLAGS) $(MATH_FLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS) $(MATH_FLAGS)

funcoes.o: funcoes.c
	$(CC) -c funcoes.c $(CFLAGS) $(MATH_FLAGS)
	
Globais.o: Globais.c
	$(CC) -c Globais.c $(CFLAGS) $(MATH_FLAGS)
	
clean:
	rm -rf *.o *.exe *.bak *.c~ $(BINARIES) core a.out

limpa:
	del *.o *.exe *.bak *.c~ $(BINARIES) core


