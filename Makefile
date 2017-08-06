# You can copy this Makefile to use with any other project
# The only things you should change are:
#   - line 11, if you want to add flags, for example, -g for debugging    
#   - line 14, where you add library, for example: LIB = -lm
#   - line 17: replace the .h files by new .h files 
#   - line 18: replace the .c files by new .c files
#   - line 23: replace "toy" by the name for the executable file

# define C compiler & flags
CC = gcc
CFLAGS = -Wall

# define libraries to be linked (for example -lm)
LIB = 


HDR = prime.h intArray.h
SRC = intArray.c prime.c main.c
# OBJ is the same as SRC, just replace .c with .h
OBJ     = $(SRC:.c=.o)
$(OBJ): $(HDR)


 
# the executable name
EXE = toy

$(EXE): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LIB)
clean:: 
	rm -f $(OBJ) $(EXE)

