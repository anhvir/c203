/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   bst*.[c,h]: demonstrating how to manipulate binary tree and BST

   NOTES:
	- You can use this code for study purpose, 
	  and make references appropriately.
	- There is no warantee that the code(s) will work,
	  and Anh Vo will not be responsible for any damage
	  resulting from using the code. 
	
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
	  	
