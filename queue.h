/* anhvir@gmail.com: *) This file was a part of p.7.1.c 
                        which was posted in LMS for Workshop Week 8
                     *) Some small changes have beed introduced
*/ 


#ifndef QUEUE_H
#define QUEUE_H

/* -----------    DECLARATION OF QUEUE  ---------------------- */ 
// The queue itself includes:
//    - a structure "struct qnode" to keep queue's elements, which is
//      a linked list in this case, 
//      NOTE: the data part of this struct qnode
//            happens to be a sorted linked list
//    - a structure "struct queue" that keeps track
//      of the front and rear of the queue

struct qnode {
	struct linkedList *list;    // data of queue's node: a sorted list
	struct qnode *next;         // links to next node of the queue
};

struct queue {
    struct qnode *front;
	struct qnode *rear;
};
/* ----------------------------------------------------------- */



void init_queue(struct queue *q);

void enqueue(struct queue *q, struct linkedList *list);

struct linkedList *dequeue(struct queue *queue);

int is_empty( struct queue *q);

#endif
