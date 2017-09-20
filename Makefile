# define C compiler & flags
CC = gcc
CFLAGS = -Wall -g

# define libraries to be linked (for example -lm)
LIB = 


HDR1 = list.h queue.h
SRC1 = list.c queue.c list_mergesort.c

# OBJ is the same as SRC, just replace .c with .h
OBJ1 = $(SRC1:.c=.o)

# the executable name
EXE1 = list_mergesort

all: $(EXE1) 

$(EXE1): $(OBJ1) Makefile
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB) 

clean: 
	rm -f $(OBJ1) $(EXE1) 

$(OBJ1): $(HDR1) Makefile
