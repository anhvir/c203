
OBJ = powerset.o
EXE = powerset

CC = gcc
CFLAGS = -Wall

$(EXE): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
clean: 
	rm -f $(OBJ) $(EXE)
