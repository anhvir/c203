#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

#define V 10
#define INITIAL_KEY 20

#define VARS_TIMING clock_t begin; 
#define START_TIMING begin= clock();
// return number of micro-seconds passed
#define MICSECS_SPENT ((double) (clock()-begin)*1000000.0/CLOCKS_PER_SEC)

int 
main(int argc, char *argv[]) {
    VARS_TIMING;   // for timing  

	START_TIMING
    heap_t *h = createHeap();
    int i;

	srand(time(NULL));
    for( i = 0 ; i < V ; i++) {
        enHeap(h, rand()%V);
        printHeap(h);
    }

    printHeap(h);
    printf("Min is with key %d\n", peek(h));

    i= deleteMin(h);
	printf("after deleteMin get result=%d:\n",i);
    printHeap(h);
    printf("Min is with key %d\n", peek(h));

    i= deleteMin(h);
	printf("after deleteMin get result=%d:\n",i);
    printHeap(h);
    printf("Min is with key %d\n", peek(h));


    emptyHeap(h);
	printf("Time spent= %.3f micro-seconds\n", MICSECS_SPENT);

    return EXIT_SUCCESS;
}
