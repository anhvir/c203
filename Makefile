
OBJ = intArray.o prime.o main.o
SRC = intArray.c prime.c main.c
EXE = toy

CC = gcc
CFLAGS = -Wall

$(EXE): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
clean: 
	rm -f $(OBJ) $(EXE)
