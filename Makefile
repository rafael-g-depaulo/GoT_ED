all: trab2

trab2: lists.o characters.o tree.o fight.o
	gcc -g -o trab2 main.c lists.o characters.o tree.o fight.o -Wall -pedantic

fight.o: fight.c fight.h log.h
	gcc -g -c fight.c -Wall -pedantic

tree.o: tree.c tree.h
	gcc -g -c tree.c -Wall -pedantic

log.o: log.c log.h characters.h
	gcc -g -c log.c -Wall -pedantic

characters.o: characters.c characters.h lists.h
	gcc -g -c characters.c -Wall -pedantic

lists.o: lists.c lists.h characters.h
	gcc -g -c lists.c -Wall -pedantic