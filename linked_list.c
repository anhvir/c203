/* anhvir@gmail.com: *) This file was a part of p.7.1.c 
                        which was posted in LMS for Workshop Week 8
                     *) Some changes have beed introduced
                        and all functions have been implemented
*/ 


#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

struct linkedList *prepend(struct linkedList *head, int item){
	struct linkedList *p= malloc(sizeof(*p));
	// Make a guess: what the next statement do?
	// Test your guess by using assert(0 && p && "Cannot...")
	assert(p && "Cannot malloc");

    p->item= item;   
	p->next= head;     // join new element to the head of the list
    return p;          // then, new element becomes the new head
}

/* Add a linked list item to the end of the list, traversing all items. */

/* Spend some time to study this function
   Then answer the question:
      - Why we need p to be "pointer to pointer"?
   If you can't answer, try to write the function 
      without using "pointer to pointer" (yes, it's possible)
*/
struct linkedList *append(struct linkedList *head, int item){
	struct linkedList **p= &head;   // "*p" is "head"
	while (*p) {              // LOOP_A 
		p= &( (*p)->next );   // moving towards the end of the list
	}
	// Now *p is the same as end->next
    //   where "end" is the last element of the list
 
	*p = malloc(sizeof(**p));
	//   A new element is allocated
	//      and "end->next" is pointing to that new element
	//   Note that if the original list "head" is empty
	//      then LOOP_A executes zero time
	//      and *p remained the same as "head"
	//      in this case now "head" points to the new element
  
	assert( *p && "Cannot malloc");
    (*p)->item= item;
	(*p)->next= NULL;      // this new element is the last element
    
    return head;
}

