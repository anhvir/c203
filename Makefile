# define C compiler & flags
CC = gcc
CFLAGS = -Wall -g
#              -g flag is added so that we can run gdb and valgrind

all: list_abc llist afriend
list_abc: list_abc.c Makefile
	${CC} $(CFLAGS) -o list_abc list_abc.c

llist: llist.c Makefile
	${CC} $(CFLAGS) -o llist llist.c

afriend: random_friend.c
	${CC} $(CFLAGS) -o afriend random_friend.c

clean:
	rm -f list_abc llist afriend
