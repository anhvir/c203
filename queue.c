/* anhvir@gmail.com: *) This file is NOT a part of p.7.1.c 
                        
                     *) The queue implementation here is not the same
                        as the one in p.7.1.c
                        p.7.1.c only keeps track of FRONT of a queue
                        here, both FRONT and REAR are monitored
*/ 



#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"
#include "queue.h" 

void init_queue( struct queue *q) {
	q->front= NULL;
	q->rear=  NULL;
}

void enqueue(struct queue *q, struct linkedList *list){
	// (1) malloc and set data for a new queue node
	struct qnode *new= malloc(sizeof(*new));
	assert(new);
	new->list= list;  // remember: this is just the data part of qnode
	new->next= NULL;

	// (2) if queue is empty, then new is the only member of queue
	if (q->front==NULL) {
		q->front= q->rear= new;
		return;
	}

	// (3) otherwise, adding new to the rear:
	q->rear->next= new;     // links last element to new
	q->rear= new;           // and new become the new rear
}

struct linkedList *dequeue(struct queue *q){
	assert( q->front && "Queue is empty" );

	// Keep track of the front node and its data
	struct qnode *front_node= q->front;
    struct linkedList *res = front_node->list;  // the data, to be returned

	// Delete the element at front in 2 steps:
	// Step 1: remove it sfrom the queue
	q->front = front_node->next;  // front now points to the next node
	if ( q->front == NULL ) {     // If the queue becomes empty
    	q->rear= NULL;            //   then we need to reset rear 
	}                       
    
	// Step 2: Delete the removed qnode
	free( front_node );

   
	// Finish: return the data part 
    return res;
}

int is_empty( struct queue *q) {
	return (q->front == NULL);
}

