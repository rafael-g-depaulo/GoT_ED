### Makefile do trabalho final de ED ###

# variaveis
CC      = gcc
FLAGS  = -g -c -Wall
HEADERS = $(wildcard *.h)

# all
all: TrunfoGoT

# executavel
TrunfoGoT: log.o fight.o characters.o lists.o tree.o $(HEADERS)
	$(CC) -o -g -Wall main.c log.o fight.o characters.o lists.o tree.o


# .o's
fight.o: $(HEADERS) fight.c
	$(CC) $(FLAGS) fight.c

characters.o: $(HEADERS) characters.c
	$(CC) $(FLAGS) characters.c

lists.o: $(HEADERS) lists.c
	$(CC) $(FLAGS) lists.c

tree.o: $(HEADERS) tree.c
	$(CC) $(FLAGS) tree.c

log.o: $(HEADERS) log.c
	$(CC) $(FLAGS) log.c