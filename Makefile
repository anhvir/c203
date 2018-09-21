# an example of Makefile with 2 main targets

# define C compiler & flags
CC = gcc 
CFLAGS = -Wall
# the above flag is for testing your program, 
# for doing experiments you should cahned it to:
# CFLAGS = -Wall -O3
 

# define libraries to be linked (for example -lm)
LIB = 


HDR1 = bu_msort.h linked_list.h queue.h
SRC1 = main.c bu_msort.c linked_list.c queue.c

HDR2 = heap.h
SRC2 = heap.c heapMain.c 

# OBJ is the same as SRC, just replace .c with .h
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# the executable name
EXE1 = bu_msort
EXE2 = heaptest


# we have 2 tagets defined as $(EXE1) and $(EXE2) in lines 36 and 39 
#   here we add another handy target "all" with include both,
#   so that when yopu run "make all", both targets will be excecuted

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1) Makefile
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB) 

$(EXE2): $(OBJ2) Makefile
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ2) $(LIB) 

clean: 
	rm -f $(OBJ1) $(EXE1) $(OBJ2) $(EXE2)

# the dependencies of $(OBJ1) and $(OBJ2)
$(OBJ1): $(HDR)
$(OBJ2): $(HDR2)
