/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   bst*.[c,h]: skeleton program
               demonstrating how to manipulate binary tree and BST

	
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bst.h"


/* --------------- utilities -----------------------------*/
/* safe allocating memory for "n" cells, "size" bytes each */ 
void *safe_malloc(int size) {
	void *p= malloc(size);
	if ( !p ) {
		fprintf(stderr, "malloc() FAILED to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

void *safe_calloc(int n, int size) {
	void *p= calloc(n, size);
	if ( !p ) {
		fprintf(stderr, "calloc() FAILED to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
/*----------------------------------------------------------*/




/* free all memory used by tree "bst" ----------------------------- */
void node_free(tree_t n) {      /* this free mem for a single node */
	free(n);
}

void bst_free(tree_t bst){     /* this apply node_free to all node,
									using postorder trversal        */
	fprintf(stderr, "bst_free: IMPLEMENT ME FIRST!\n\n");
	exit(EXIT_FAILURE);
}

/* insert a data item "elem" into the BST "bst" if possible;
   Returning:
		EXIT_SUCCESS: if succesful
		EXIT_FAILURE: if not successful ("elem" already on tree) 
------------------------------------------------------------------- */  	
int bst_insert(tree_t *bst, key_t elem){
	fprintf(stderr, "bst_insert: IMPLEMENT ME FIRST!\n\n");
	exit(EXIT_FAILURE);
}
 

/* delete the node with data "elem" from the BST "bst" if possible;
------------------------------------------------------------------- */  	
int bst_delete(tree_t *bst, key_t elem){
	fprintf(stderr, "bst_delete: IMPLEMENT ME FIRST!\n\n");
	exit(EXIT_FAILURE);
}

/* return the node that has key == elem 
------------------------------------------------------------------- */  	
tree_t bst_search(tree_t *bst, key_t elem){
	fprintf(stderr, "bst_find: IMPLEMENT ME FIRST!\n\n");
	exit(EXIT_FAILURE);
}

/* traversal
	Treverse tree "t" and,
	      with a node "n" in tree, apply function process(n)   
------------------------------------------------------------------- */
void tree_preorder(tree_t t,void (*process)(tree_t)){
	fprintf(stderr, "tree_preorder: IMPLEMENT ME FIRST!\n\n");
	exit(EXIT_FAILURE);
}
void tree_inorder(tree_t t,void (*process)(tree_t)){
	fprintf(stderr, "tree_inorder: IMPLEMENT ME FIRST!\n\n");
	exit(EXIT_FAILURE);
}
void tree_postorder(tree_t t,void (*process)(tree_t)) {
	if (t) {
		tree_postorder(t->left, process);
		tree_postorder(t->right, process);
		process(t);
	}
}

/* tree_print: 
   print a tree, level by level,
   supposing that key_t is char
   and that the tree high is at most 5
NOTES:	 
   - tree_print employs tree2keys() which is a kind of preorder traversal
   - at this stage, if you understand tree_print(), that's great,
 	 but if not, no worries at all, as you will learn about
     the underlined techniques at some stage anyway 

------------------------------------------------------------------- */		

#define NO_KEY -1000	
#define MAX_LEVEL 5
#define MAX_N ( (1<<MAX_LEVEL)-1 ) 
#define MAX_LEAVES (  1<<(MAX_LEVEL-1) ) 
void tree2array(tree_t t, int pos, int keys[]) {
	if (t) {
		keys[pos]= t->key;
		tree2array(t->left, 2*pos+1, keys);
		tree2array(t->right, 2*pos+2, keys);
	}
}

void tree_print(tree_t t){
	int keys[MAX_N];      /* array of key to be printed, in order */
	int i, j, level, left, right;
 
 	if (!t) {
		printf("The tree is empty, nothing printed!\n\n");
	}
	/* first, read tree nodes and flattern them into keys, 
       in order required by orinting */
	for (i=0; i<MAX_N; i++) keys[i]= NO_KEY;
	tree2array(t,0,keys);

	/* then, print from level 1 to MAX_LEVEL */
	left= right= 0;				/* next level is in keys[left..right */
	for (level= 1; level <= MAX_LEVEL; level++) {
		int leaves = 1<< (level-1);
		float spaces = (MAX_LEAVES * 3 - 3*leaves)/(leaves+1);
		// gee, we have 16*3 positions in one line
		// printing the branches
		if (level>1) {
			int finish= 1;
			for (i=left; i<=right; i++) {
				for (j=0; j<spaces; j++) printf(" ");
				if (keys[i] != NO_KEY) {
					finish= 0;
					if ( i%2 ) printf ("  /"); else printf (" \\ ");
				} else printf("   ");
			}
			printf("\n");
			if (finish) return;
		}
		// printing the keys
		spaces = (MAX_LEAVES * 3 - 3*leaves)/(leaves+1);
		for (i=left; i<=right; i++) {
			for (j=0; j<spaces; j++) printf(" ");
			if (keys[i] != NO_KEY) {
				if ( i%2 ) printf ("%2d ",keys[i]); 
				else printf ("%3d", keys[i]);
			} else printf("   ");
		}
		printf("\n");
		
		left= 2*left+1;
		right= 2*right+2;
	}
	printf("\n");
	return;
}
	
	  	
