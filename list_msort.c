/* anhvir@gmail.com: *) This file was a part of p.7.1.c 
                        which was posted in LMS for Workshop Week 8
                     *) Some small changes have beed introduced

   NOTE: This is the solution we worked out together in 1 of the classes
         After the class, Anh added some more comments
		

*/ 

#include <stdlib.h>
#include "linked_list.h" 
#include "list_msort.h"
#include "queue.h"


struct linkedList *merge(struct linkedList *l1, struct linkedList *l2) {
    /* merge 2 sorted list l1 and l2 
         into a sorted list l and return it */

	struct linkedList *l;
	if (l1 == NULL) return l2;    // trivial cases
	if (l2 == NULL) return l1;

	// from this point, both lists l1 and l2 are non-empty
	if (l1->item < l2->item) {    
		l= l1;                   // The 1st elem of l1 becomes 
                                 //    the head of the merged list 
		l->next= merge(l1->next, l2);
		                         // The head connects with the rest,
		                         //    which is actually the result
		                         //    of merging l1->next with l2
		return l;
	} else {
		l= l2;                   // Similar to the previous case
		l->next= merge(l1, l2->next);
		return l;
	}

	return NULL;            // Obviously we can delete this line
	                        // OR replace it by "return l"
	                        //   and delete two previous "return l" lines  
}



struct linkedList *mergeSort(struct linkedList *list){
    /* FILL IN SETUP FOR Linked List BOTTOM-UP mergesort 
       using queue facilities and
       using function merge above */

	// STEP 0:
	// prepare queue, we need to look at queue.h to see how to init queue
	struct queue q;
	init_queue( &q );      // queue.h says that the prototype for
	                       //   init is int_queue(struct queue *)
	                       //   so we send the address &q to it


	// STEP 1:
	// break the list into single-element lists and
	//  push them the queue
	while (list) {
		struct linkedList *p= list;   // p is the member broken out  
		list= list->next;             // Advance "list" to the next elem

		// Now, process the element p:
		p->next= NULL;                // Setting NULL to cut the connection
		                              //   from p to the rest of the list
		                              //   and make p be a single-member
		                              //   list   
		enqueue( &q, p);              // Here we push that p into queue q
		                              //   again, looke at the syntax
		                              //   required for enqueue in queue.h
	}

	// Declaring some variables for step 2
	// Conservative people (like myself) want you to put this line
	//    at the beginning of the functions 
	//    but they cannot deduct marks for not doing so :-) 
	struct linkedList *l1, *l2, *l;


	// STEP 2: 
	// Processing the queue until having just 1 element in it

	while(  !is_empty(&q)   ) {      // queue.h just has function is_empty
	                                 //   so we use that 
		l1= dequeue( &q );           // remove l1 from the queue			
		if ( is_empty(&q) ) {        // Empty means l1 is the only element
		                             //   in the queue, so it must be
			return l1;               //   the resulted merged list!
		}
		l2= dequeue( &q );           // Otherwise we remove l2 from queue
		l= merge(l1, l2);            //  and merge l1 (with is sorted list)
		                             //  with l2 (which is a sorted list)
		                             //  to get a sorted list l
		enqueue( &q, l);             // Then push that sorted list l
		                             //  to the queue
		                             //  and continue the loop
		
	}
	
	return NULL;                     // We cannot remove this line
	                                 // because there is a case when 
	                                 // this line is actually executed
	                                 // (which case?)  
}

// Anh: I hope that you can compare the function here with the theory
//      about bottom-up mergesort
//	    And that you can rebuild this file from scratch!
//      Happy coding
