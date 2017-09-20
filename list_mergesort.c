/*
	Anh Vo, anhvir@gmail.com
	implementation of linked-list-based bottom-up mergsort

    NOTES:
      - use the accompanied Makefile for compilation
      - modules list and queue are already implemented for you
        just use them as ADTs
 
    SUGGESTIONS:
	  - use this skeleton for implementing list-based mergesort
        note that you don't need to input data: they are randomly generated
      - when implementing list_mergesort, 
        browse list.h and queue.h to know the interfaces for
        working with list and queue, and
        do not look at list.c and queeu.c
      - a full version of implementation is attached at the end of
        this file, you are advised not to look at that before
        completing your own implementation 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "queue.h"

#define N 15      // number of elems in the list 
#define MIN 1     // MIN & MAX of randomly generated data (keys)
#define MAX N

void list_mergesort(list_t *pl);

int main(int argc, char *argv[]) {
	int n= N;
	int i, key;
	list_t l= createL();            // list to be sorted 
	// starts using random number
	srand(time(NULL));

	// (1) insert n random-elements into the list
	for (i=0; i<n; i++) {
		key= MIN + ( rand() % (MAX-MIN+1) );
		// insert "key" into the list
        // FIX ME
	}	
    // print original list
	printf("Original list:\n");
	printL(l);
    
    list_mergesort(&l);

    // print sorted list
	printf("\nSorted list:\n");
	printL(l);
    printf("\n");

	freeL(l);

	return 0;
}



// merge sorted lists a and b into a sorted list
//     and returns the merged list 
list_t mergeL(list_t a, list_t b) {
	// FIX ME
	return NULL;
}  


// FIX ME
void list_mergesort(list_t *pl) {
	// (0) create an empty queue
	queue_t q= createQ();

    printf("------ list_mergesort not yet implemented! Do it! \n");
	// (1) break the list into n single list and put them into the queue	
	list_t l= *pl;   // temporal variable to replace *pl
 
    // (2) process queue until having single element
	while ( 0  /* FIX ME */) {
		// take 2 items from queue, merge them, and 
        //   then put the merged list into the queeu
	}

	// (3) single element in queue is the final sorted list, 
	//    take it out and make it the sorted list!
	*pl= deQ(&q);
}











// don't look further!
// after this line is a worked implementation
// you should have a look at that only after finishing your own implementation

#if 0
int main(int argc, char *argv[]) {
	int n= N;
	int i, key;
	list_t l= createL();  
	// starts using random number
	srand(time(NULL));

	// insert n random-element into the list
	for (i=0; i<n; i++) {
		key= MIN + ( rand() % (MAX-MIN+1) );
		insertL(&l, key);
	}	
    // print original list
	printf("Original list:\n");
	printL(l);
    
    list_mergesort(&l);

    // print sorted list
	printf("\nSorted list:\n");
	printL(l);
    printf("\n");

	freeL(l);

	return 0;
}




list_t mergeL(list_t a, list_t b) {
	if (a==NULL) return b;
	if (b==NULL) return a;
	if (a->key <= b->key) {
		a->next = mergeL( a->next, b);
		return a;
	} else {
		b->next = mergeL( a, b->next);
		return b;
	}
}  



void list_mergesort(list_t *pl) {
	queue_t q= createQ();

	// (1) break the list into n single list and put them in queue	
	list_t l= *pl;   // temporal variable to replace *pl
	list_t tmp;	
	while ( l ) {
		tmp= l;
		l= l->next;
		tmp->next= NULL;  // make tmp a single-element list
		enQ(&q, tmp);
	}
 
    // (2) process queue until having single element
	while (nQ(q) > 1) {
		list_t l1= deQ(&q);
		list_t l2= deQ(&q);
		enQ(&q, mergeL(l1, l2));
	}

	// (3) single element in queue is the final sorted list
	*pl= deQ(&q);
}


#endif

 








	
	


