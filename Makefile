	CFLAGS = -g -c -Wall -pedantic

all: trab2

trab2: lists.o characters.o tree.o fight.o
	gcc -g -o trab2 main.c lists.o characters.o tree.o fight.o -Wall -pedantic

fight.o: fight.c fight.h log.h
	gcc $(CFLAGS) fight.c 

tree.o: tree.c tree.h
	gcc $(CFLAGS) tree.c 

log.o: log.c log.h characters.h
	gcc $(CFLAGS) log.c 

characters.o: characters.c characters.h lists.h
	gcc $(CFLAGS) characters.c 

lists.o: lists.c lists.h characters.h
	gcc $(CFLAGS) lists.c 