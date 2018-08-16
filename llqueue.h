// NOTES:
// This file was extracted from LMS -> Workshop -> Week 4 -> Week 04 - Workshop.ipynb
//   anhvir@gmail.com might enter some very tiny changes
//   in such cases " /*tiny change*/ " is added at the end of changed lines
      
/* llqueue.h */
/* This is used for printing the tree. It is an implementation of an abstract 
    data structure called a queue, which we will cover next week. You can ignore 
    llqueue.h and llqueue.c for the moment and trust they do what they say
    they do. */
struct llqueue;

/* Creates a new, empty queue. */
struct llqueue *newQueue();

/* Adds the given item to the queue, allocating if needed. */
void queue(struct llqueue **queue, void *item);

/* Takes the next item from the queue. */
void *dequeue(struct llqueue *queue);

/* Returns 1 if the queue is empty, 0 otherwise. */
int empty(struct llqueue *queue);


