/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   bst*.[c,h]: demonstrating how to manipulate binary tree and BST

   NOTES:
	- You can use this code for study purpose, 
	  and make references appropriately.
	- There is no warantee that the code(s) will work,
	  and Anh Vo will not be responsible for any damage
	  resulting from using the code. 
	
*/


#ifndef _BST_H_
#define _BST_H_

 


#define PREORDER  0
#define INORDER   1
#define POSTORDER 2



/* change key_t here to suit your need,
   to use print_tree, however, key_t must be defined as int
                               and all key must be in between -9 and 99
   Note: if you want a nicer printed tree, you can define
         key_t as char and make a little change to print_tree	
*/
typedef int key_t;
#define NO_KEY -1000    /* this value can't be a key :-)  */



/* tree_t is data type for any binary tree, including BST */
typedef struct node_t *tree_t;

struct node_t {
	key_t key;			/* here key is the only data in tree node   */
    tree_t left;        /* pointer to left sub-tree (left child)    */
    tree_t right;       /* pointer to right sub-tree (right child)  */
};


/* free all memory used by tree "bst" ----------------------------- */
void bst_free(tree_t bst);

/* insert a data item "elem" into the BST "bst" if possible;
   Returning:
		-1 if not successful ("elem" already on tree) 
		>=0 : number of comparison used
------------------------------------------------------------------- */  	
int bst_insert(tree_t *bst, key_t elem);

/* delete the node with data "elem" from the BST "bst" if possible;
   Returning:
		-1 if not successful ("elem" already on tree) 
		>=0 : number of comparison used
------------------------------------------------------------------- */  	
int bst_delete(tree_t *bst, key_t elem);

/* delete the node with data "elem" from the BST "bst" if possible;
   Returning:
		-1 if not successful ("elem" already on tree) 
		>=0 : number of comparison used
------------------------------------------------------------------- */  	
int bst_search(tree_t *bst, key_t elem);

/* traversal
	Treverse tree "t" and,
	      with a node "n" in tree, apply function process(n)   
------------------------------------------------------------------- */
void tree_preorder(tree_t t,void (*process)(tree_t));
void tree_inorder(tree_t t,void (*process)(tree_t));
void tree_postorder(tree_t t,void (*process)(tree_t));

/* tree_print: 
   print a tree, level by level,
   supposing that key_t is char
   and that the tree high is at most 5 
------------------------------------------------------------------- */		
void tree_print(tree_t tree);



#endif
