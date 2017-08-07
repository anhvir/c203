
OBJ = intArray.o prime.o main.o
EXE = toy

CC = gcc
CFLAGS = -Wall

$(EXE): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
clean: 
	rm -f $(OBJ) $(EXE)
