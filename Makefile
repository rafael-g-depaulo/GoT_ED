all: trab2

trab2: lists.o characters.o tree.o fight.o
	gcc -g -o trab2 main.c lists.o characters.o tree.o fight.o

fight.o: fight.c fight.h
	gcc -g -c fight.c

tree.o: tree.c tree.h
	gcc -g -c tree.c

characters.o: characters.c characters.h lists.h
	gcc -g -c characters.c

lists.o: lists.c lists.h characters.h
	gcc -g -c lists.c