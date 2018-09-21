/*
	anhvir@gmail.com
    
    A simplest implementation of heap
	For comp20003 Week 9 - extended lab 

    IMPORTANT NOTE:
	   In this implementation the root is in position 0 of the heap array
	   (in the lecture position 0 is not used, and root is in index 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"


// using dynamic memory allocation for the heap array
//    the array size might grow up during the use of the heap
#define MIN_HEAP_SIZE 8


// creating a new heap
//    returns a pointer to that new, empty heap
heap_t *createHeap() { 
	heap_t *h = malloc(sizeof(*h));
	assert(h);
	// preparing the heap array with initial size  
	h->H   = malloc(sizeof(*h->H)*MIN_HEAP_SIZE);
    h->size= MIN_HEAP_SIZE;
    h->n   = 0;
    return h;
}                               

//  enlarge the heap array by doubling its size
//
void enlargeHeap(heap_t *h) {
	// FIXME: write to code here
	h->size *= 2;
    h->H = realloc(h->H, sizeof(*h->H) * h->size );
	assert(h->H);
}

// swap elements at position a and b of the heap
// assuming h != NULL
void swap (heap_t *h, int a, int b) {
	 heapItem_t t = h->H[a];    
	 h->H[a] = h->H[b];       
	 h->H[b] = t;             
}


// upHeap element at position "n" in the heap array
//   
void upHeap(heap_t *h, int n) {
    int child  = n;
    int parent = (child - 1) / 2;
    while ((child > 0) && (h->H[parent].key > h->H[child].key)) {
        swap(h, parent, child);
        child = parent;
        parent = (child - 1) / 2;
    }
}

// returns the position of the smllest-weight child of p
//        -1 if not exists (ie element [p] has no child)
int minChild(heap_t *h, int p) {
	int c= 2*p+1;       // supposing left child is the min child
	if ( c < h->n ) {   // if (having_left_child)
        /* ??? */
	} else 
		c= -1;          // this case: node p has no child
	return c;
}

// assumes h != NULL
void downHeap(heap_t *h, int n) {
	int parent = n, child;
	child= minChild(h, parent);
	while (/* having child and not in order*/) {
		/* ??? */
	}
}

// inserts a new key into heap
//   (equivalent to enPQ)
void enHeap(heap_t *h, int key) { 

    if (h->n == h->size) {
		enlargeHeap(h);
    }
    h->H[h->n].key = key;
    h->n += 1;
    upHeap(h, h->n - 1); 
}     

// returns the key of the root.
// or -1 if no data in heap
int peek(heap_t *h) { 
	assert(h->n > 0);
    return h->H[0].key;
}

// removes the root, returns the data index to it, and re-heapifies 
int deleteMin(heap_t *h) { 
	assert(h->n > 0);
 	int key= h->H[0].key;
	if (!h) return -1;

	swap(h, 0, h->n-1);
	h->n--;
  	downHeap(h, 0);
	return key;
}                           

// free any memory you might of alloced in heap creation
void emptyHeap(heap_t *h) {
    if (h == NULL) return;
    if (h->size > 0) {
        free(h->H);
    }
    free(h);
}

// debug
void printHeap(heap_t *h) {
    if (h == NULL) return;

    int i;
    printf("---------------------------\n");
    printf("heap keys: ");
    for(i = 0 ; i < h->n ; i++)
        printf("%d ", h->H[i].key);
    printf("\n");
}
