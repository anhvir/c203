/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   lqueue.[c,h]: simple implementation of list-based queue
				 supposing that data is of type int

   NOTES:
    - You can use this code for study purpose, 
      and make references appropriately.
    - There is no warantee that the code(s) will work,
      and Anh Vo will not be responsible for any damage
      resulting from using the code. 
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "lqueue.h"


lqueue_t create_lqueue() {
	lqueue_t q=safe_malloc(sizeof(*q));
	q->head= q->tail= NULL;
	return q;
}

void delete_lqueue(lqueue_t q) {
	list_t p= q->head;
	while (p) {
		p= p->next;
		free(q->head);
		q->head= p;
	}
	free(q);
}

// enqueue data x into queue q
void enqueue(int x, lqueue_t q) {
	list_t p= safe_malloc(sizeof(*p)); // creats a new node
	p->key = x;
	p->next = NULL;
    if (q->tail==NULL) {   // queue is empty 
		q->head= q->tail= p;
		return;
 	}
	q->tail->next = p;     	// links new element to queue
	q->tail= p;				//  then, repairs q->tail
}

// dequeue and return data
int dequeue( lqueue_t q ) {
	int x;
	list_t p= q->head;
	if (p==NULL) error_stop("Trouble: queue is empty when dequeuing!");
	x= p->key;
	q->head= p->next;  		// repairs head, same as q->head= q->head->next 
	free(p);				
	if (q->head==NULL) q->tail= NULL;    // case of empty queue
	return x;
}

// returns 1 if queue is empty, 0 otherwise
int is_empty(lqueue_t q) {
	return (q->head==NULL);
} 	   

// returns 1 if queue has only 1 element, 0 otherwise
//   note: this function is not popular
int is_singleton(lqueue_t q) {
	return (q->head && q->head==q->tail);
} 


// ===== Other tools. technically not belonging to lqueue 

// --------------------------------------------------------- //
// error and malloc utilities
void error_stop(char *msg) {
	fprintf(stderr, "ERROR: %s.\n", msg);
	exit (EXIT_FAILURE);
}
void *safe_malloc(int size) {
	void *p= malloc(size);
	if (p==NULL) error_stop("Cannot malloc");
	return p;
}

