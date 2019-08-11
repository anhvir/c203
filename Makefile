# You can copy this Makefile to use with any other project
# The only things you should change are:
#   - line 11 (CFLAGS), you can add, for example, -g for debugging    
#   - line 14 (LIB) , where you add library, for example: LIB = -lm
#   - line 17 (HDR): replace the .h files by new .h files 
#   - line 18, 19 (SRC): replace the .c files by new .c files
#   - line 25, 26 (EXE): replace by new names for the executable files

# define C compiler & flags
CC = gcc
CFLAGS = -Wall

# define libraries to be linked (for example -lm)
LIB = 


HDR = intArray.h search.h
SRC1 = intArray.c main.c seq_search.c
SRC2 = intArray.c main.c bin_search.c
# OBJ? is the same as SRC?, just sustitute ".c" with ".o"
OBJ1     = $(SRC1:.c=.o)
OBJ2     = $(SRC2:.c=.o)

# the executable name
EXE1 = seq_search
EXE2 = bin_search

all: $(EXE1) $(EXE2)

$(EXE1): $(HDR) $(OBJ1) Makefile
	echo $(OBJ1)
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB)

$(EXE2): $(HDR) $(OBJ2) Makefile
	echo $(OBJ2)
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ2) $(LIB)

clean: 
	rm -f $(OBJ1) $(OBJ2) $(EXE1) $(EXE2)

$(OBJ1): $(HDR)
$(OBJ2): $(HDR)

