
factorial: main.o factorial.o
	gcc -Wall -o factorial factorial.o main.o


clean:
	rm -f *.o factorial
 
main.o: factorial.h

factorial.o: factorial.h


