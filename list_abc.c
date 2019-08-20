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


int main(int argc, char *argv[]) {
	list_t head= NULL;     // head of the list, list is empty now
	list_t a, b, c, d;
	printf("My list at the start:\nlist= ");
	print_list(head);
 
	a= new_node(10);       // a now is a node with data = 10
	head= a;               // now my list should have one element
	printf("My list after inserting 1 elements:\nlist= ");
	print_list(head);
 
	b= new_node(20);
	a->next= b;           // makes the link from a to b 

	c= new_node(30);
	b->next= c;           // makes the link from b to c

	printf("My list after linking 10 to 20 and 20 to 30:\nlist= ");
	print_list(head);

	printf("Now inserting 25 in between 20 and 30\n");
	d= new_node(25);      // First, creates a node with data 25
	b->next= d;	      // Then, links b to the new node
	d->next= c;           //    and, new node to c 		 
        
	printf("My list becomes \nlist= ");
	print_list(head);
        
	return 0;
}

list_t new_node(int data) {
	list_t node= safe_malloc(sizeof(*node));
	node->data= data;
	node->next= NULL;
	return node;
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

