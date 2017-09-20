/* 
   	Anh Vo, anhvir@gmail.com
	Simple implementation of queues

	SUGGESTIONS:
		- blindly emply this implementation by just looking at queue.h
		  (ie ignoring queue.c)
		- when having time, build this file from scratch
          and/or study this implementation
*/

#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.h"

// define data for queue element, and queue_t
typedef list_t qdata_t;		// change this for other type

typedef struct qnode{
	qdata_t data;
	struct qnode *next;
} qnode_t;

typedef struct queue {
	qnode_t *front;
	qnode_t *rear;
	int n;
} queue_t;



// create and return empty queue
queue_t createQ();              
// enqueue list x to queue *pq
void enQ(queue_t *pq, qdata_t x);
// dequeue from queue *pq and return the removed element
qdata_t deQ(queue_t *pq);
// return number of element in queue q
int nQ(queue_t q);

// you might want to add function freeQ



#endif
