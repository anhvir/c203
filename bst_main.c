/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   bst*.[c,h]: demonstrating how to manipulate binary tree and BST

   YOUR TASK for PROGAMMING TASK 4.1:
     1: a) implement function bst_insert() in bst.c
           remember to use safe_malloc or safe_calloc
       	b) run "make" to compile the program
 		c) use gdb and valgrind to debug if needed

     2: implement other functions (and add some lines to main() so
        that you can test. You can start from implementing bst_search

     3: inspect & understand other pieces of bst.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bst.h"
	
int main() {
	tree_t t= NULL;
	int k;
	while (scanf("%d ",&k)==1 && k != NO_KEY ) {
		bst_insert(&t,k);

	}
	tree_print(t);
	// bst_free(t);
	exit(0);
}
	  	
