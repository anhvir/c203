#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node *list_t; 
struct node {
	int data;
	list_t next;
};
	
void *safe_malloc(int n); 
list_t new_node(int data);
void print_list( list_t head ); 
list_t insert_front(list_t list, int data);
int delete_kth(list_t *, int k);

int main(int argc, char *argv[]) {
	list_t head= NULL;     // head of the list, list is empty now
	int i, data, k, ks[]={5,9,1,10};
	// using insert_front to make list 1 -> 2 -> 3 -> ... -> 10
	for (i=10; i>0; i--) {
		head= insert_front(head, i);
	}
	printf("List after inserting 10 elements:\n list= ");
	print_list(head);

	// using delete_kth to delete the k-th elements from ks[]
	for (k=0; k<sizeof(ks)/sizeof(*ks); k++) {
		printf("Deleting the %d-th element...\n",ks[k]);
		fflush(stdout);
		data = delete_kth(&head, ks[k]);
		printf("The element deletted is %d\n", data);
		printf("List becomes:\nlist=");
		print_list(head);
		fflush(stdout);
	}		
	return 0;
}

list_t new_node(int data) {
	list_t node= safe_malloc(sizeof(*node));
	node->data= data;
	node->next= NULL;
	return node;
}

// inserts a node with "data" to the front of the list
// returns the changed list
list_t insert_front(list_t list, int data){
	list_t node= new_node(data);
	node->next= list;     // makes the link from "node" to the list
	return node;          // now node becomes the extended list!
}

// delete the k-th element of a list and return the data
// Here, the list (ie its head) could be changed
//       that's why plist is declared as "pointer to list_t"
// Warning: the function is INCORRECT, try to get it to trouble and 
//        use gdb/valgrind to debug
// Note: this function is a bit hard to understand, mostly because of the use
// of " list_t *p "
// You can certainly use "list_t p" and change the function accordingly. 
int delete_kth(list_t *plist, int k) {
	// plist is declared as (list_t *)
	//   so with the call delete_kth(&list,...)
	//   "*plist" and "list" refer to the same object 
	list_t *p;
	int data;
	// skips k-1 element
	for (p= plist; k>1; k--) {
		p= &( (*p)->next );
		// now "*p" is the same as the previous "next"
		//    and if we change "*p"
		//    that just means we change the previous "next" pointert
	}
	// keeps the returned data, which is of the element *after* "*p"
	data= (*p)->data;
	// makes link from *p to its 2nd next element
	*p= (*p)->next;  // before asignment:
					 //   "*p" is the same as the previous "next" pointer 
                     //   ie "*p" points to the current element 
					 //   (which will be deleted)
				     //   "(*p)->next" is the address of the next element    
	// done, but there are some errors here perhaps.	
	return data;	
}

// Recursive function to print out a list
// Obviously, we can write it as an iterative function (try!)
void print_list( list_t head ) {
	if ( !head ) {    // base case, when the list is empty
		printf(" <NULL>\n");
		return;
	}
		         // general case, when list is not empty
	printf(" %d -->", head->data);
	print_list( head->next );
}

/** ------------ buddy friends -------------------  **/ 
void *safe_malloc(int n) {
	void *mem= malloc(n);
	assert(mem && "Cannot malloc");
	return mem;
}	

