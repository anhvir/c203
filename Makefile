
factorial: main.o factorial.o
	gcc -Wall -o factorial factorial.o main.o


clean:
	rm -f *.o factorial
 
main.o: main.c factorial.h
	gcc -Wall -c -o main.o main.c

factorial.o: factorial.c factorial.h
	gcc -Wall -c -o factorial.o factorial.c



