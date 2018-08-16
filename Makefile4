
# define C compiler & flags
CC = gcc
CFLAGS = -Wall -std=c99 -g

# define libraries to be linked (for example -lm)
LIB = 


HDR = prime.h int_array.h
SRC = prime.c int_array.c main.c
# OBJ is the same as SRC, just replace .c with .h
OBJ     = $(SRC:.c=.o)

# the executable name
EXE = toy

# this goal $(EXE) depends partly on the .o files listed in $(OBJ)
#     if the system cannot find any of them, say XXX.o, 
#     it will automatically issue a command:
#        gcc $(CFLAGS) -c -o XXX.o XXX.c
#     which actually compiles XXX.o from XXX.c
# then, it run the final gcc command to create $(EXE) from all the .o files      
# First target, can be run with "make toy" or just "make"
$(EXE): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LIB)

#second target, can be executed with "make all"
all: all.c Makefile
	$(CC) $(CFLAG) -o all all.c

# third target, can be run with "make clean"
clean: 
	rm -f $(OBJ) $(EXE) all

# the following line just states the dependency of .o files on the header files, we lput it here just because we don't ant it to be the first target!
$(OBJ): $(HDR)
