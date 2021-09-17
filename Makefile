programming7.1: programming7.1.o merge.o ll.o queue.o
	gcc -Wall -o programming7.1 programming7.1.o merge.o ll.o queue.o

programming7.1.o: programming7.1.c merge.h ll.h queue.h
	gcc -Wall -o programming7.1.o programming7.1.c -g -c
	
merge.o: merge.c merge.h ll.h
	gcc -Wall -o merge.o merge.c -g -c

ll.o: ll.c ll.h
	gcc -Wall -o ll.o ll.c -g -c

queue.o: queue.c queue.h
	gcc -Wall -o queue.o queue.c -g -c
