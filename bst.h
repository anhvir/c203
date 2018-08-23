/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   bst*.[c,h]: skeleton program
               demonstrating how to manipulate binary tree and BST

	
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

int bst_insert(tree_t *bst, key_t elem);
int bst_delete(tree_t *bst, key_t elem);

tree_t bst_search(tree_t *bst, key_t elem);

void tree_preorder(tree_t t,void (*process)(tree_t));
void tree_inorder(tree_t t,void (*process)(tree_t));
void tree_postorder(tree_t t,void (*process)(tree_t));

void tree_print(tree_t tree);



#endif
