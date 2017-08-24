# Sample Makefile with multiple goals
# You can copy this Makefile to use with any other project

# define C compiler & flags
CC = gcc
CFLAGS = -Wall

# define libraries to be linked (for example -lm)
LIB = 


HDR1 = bst.h
SRC1 = bst.c bst_main.c

HDR2 = stack.h
SRC2 = stack.c postfix.c

# OBJ is the same as SRC, just replace .c with .h
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# the executable name
EXE1 = bst
EXE2 = postfix

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1) Makefile
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB) 

$(EXE2): $(OBJ2) Makefile
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ2) $(LIB) 


clean: 
	rm -f $(OBJ1) $(EXE1) $(OBJ2) $(EXE2)

$(OBJ1): $(HDR1)
$(OBJ2): $(HDR2)
