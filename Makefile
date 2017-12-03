### Makefile do trabalho final de ED ###

# variaveis
CC      = gcc
FLAGS  	= -g -c -Wall
HEADERS = $(wildcard *.h)
SRC		= $(wildcard *.c)
OBJ		= $(SRC .c=.o)

# all
all: TrunfoGoT

# executavel
TrunfoGoT: $(HEADERS) $(SRC) $(OBJ)
	$(CC) -g -o TrunfoGoT $(SRC) $(OBJ) -Wall

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