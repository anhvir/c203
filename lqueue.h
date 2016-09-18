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


#ifndef _LQUEUE_H_
#define _LQUEUE_H_

// standard defs for list, supposing data type is int 
typedef struct node *list_t;	
typedef struct node{
	int key;    /* supposing that list’s elements are int */ 
	list_t next;
} node_t; 	

// defs for queue
typedef struct {
	list_t head;       		// head of queue, where dequeue happens
	list_t tail;       		// tail of queue, where enqueue happens
} lqueue_elem;
typedef lqueue_elem *lqueue_t;  // defines lqueue_t as pointer just
                               //   for convenient use 

lqueue_t create_lqueue(); 

void delete_lqueue(lqueue_t q);

// enqueue data x into queue q
void enqueue(int x, lqueue_t q);

// dequeue and return data
int dequeue( lqueue_t q );


// returns 1 if queue is empty, 0 otherwise
int is_empty(lqueue_t q);
 
// returns 1 if queue has only 1 element, 0 otherwise
//   note: this function is not popular 
int is_singleton(lqueue_t q); 
			 

// ===== Other tools. technically not belonging to lqueue 
void error_stop(char *msg); 
void *safe_malloc(int size); 

#endif
