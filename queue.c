/* 
   	Anh Vo, anhvir@gmail.com
	Simple implementation of queues

	SUGGESTIONS:
		- blindly emply this implementation by just looking at queue.h
		- when having time, build this file from scratch
          and/or study this implementation
*/

#include "queue.h"

//---- queue functions ----------------------
queue_t createQ(){
	queue_t q= {NULL, NULL, 0};
	return q;
}

void enQ(queue_t *pq, qdata_t x) {
	qnode_t *node= malloc(sizeof(*node));
	node->data= x;
	node->next= NULL;
	if (pq->n == 0) {
		pq->n= 1;
		pq->front = pq->rear = node;
	} else {
		(pq->rear)->next = node;
		pq->rear= node;
		pq->n++;
	}
}
 
qdata_t deQ(queue_t *pq){
	assert(pq->n > 0);
	qnode_t *tmp= pq->front;
	qdata_t result= tmp->data;
	pq->front= tmp->next;
	if (!(pq->front)) {
		pq->rear= pq->front;
	}
	pq->n--;
	free(tmp);
	return result;
}

int nQ(queue_t q) {
	return q.n;
}



