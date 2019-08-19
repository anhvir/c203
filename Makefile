# define C compiler & flags
CC = gcc
CFLAGS = -Wall -g
#    flag "-g" added for using with "gdb" and "valgrind"          

# define libraries to be linked (for example -lm)
LIB = 


HDR = intArray.h search.h
SRC1 = intArray.c main.c seq_search.c
SRC2 = intArray.c main.c bin_search.c
SRC3 = random_friend.c
# OBJ? is the same as SRC?, just sustitute ".c" with ".o"
OBJ1     = $(SRC1:.c=.o)
OBJ2     = $(SRC2:.c=.o)
OBJ3     = $(SRC3:.c=.o)

# the executable name
EXE1 = seq_search
EXE2 = bin_search
EXE3 = afriend

all: $(EXE1) $(EXE2) $(EXE3)

$(EXE1): $(HDR) $(OBJ1) Makefile
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB)

$(EXE2): $(HDR) $(OBJ2) Makefile
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ2) $(LIB)

$(EXE3): $(OBJ3) Makefile
	$(CC) $(CFLAGS) -o $(EXE3) $(OBJ3) $(LIB) 


clean: 
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(EXE1) $(EXE2) $(EXE3)

$(OBJ1): $(HDR)
$(OBJ2): $(HDR)
