// NOTES:
// This file copied from LMS -> Workshop -> Week 4 -> Week 04 - Workshop.ipynb -> script of question 3.1
// No change has been made. 
      

/* llqueue.h */
/* This is used for printing the tree. It is an implementation of an abstract 
    data structure called a queue, which we will cover next week. You can ignore 
    llqueue.h and llqueue.c for the moment and trust they do what they say
    they do. */
struct llqueue;

/* Creates a new, empty queue. */
struct llqueue *newQueue();

/* Adds the given item to the queue, allocating if needed. */
void queue(struct llqueue **queue, void *item);

/* Takes the next item from the queue. */
void *dequeue(struct llqueue *queue);

/* Returns 1 if the queue is empty, 0 otherwise. */
int empty(struct llqueue *queue);

/* llqueue.c  */
#include <stdio.h>
#include <stdlib.h>
/* #include "llqueue.h" */
#include <assert.h>

struct llqueue {
    struct llitem *first;
    struct llitem *last;
};

struct llitem {
    struct llitem *next;
    void *item;
};

struct llqueue *newQueue(){
    struct llqueue *ret = (struct llqueue *) malloc(sizeof(struct llqueue));
    assert(ret);

    ret->first = NULL;
    ret->last = NULL;
    return ret;
}

/* Adds the given item to the queue, allocating if needed. */
void queue(struct llqueue **queue, void *item){
    if(!queue){
        return;
    }
    if(!*queue){
        *queue = newQueue();
    }
    struct llitem *newItem = (struct llitem *) malloc(sizeof(struct llitem));
    assert(newItem);
    newItem->next = NULL;
    newItem->item = item;
    if(!(*queue)->first){
        (*queue)->first = newItem;
    } else {
        (*queue)->last->next = newItem;
    }
    (*queue)->last = newItem;
}

void *dequeue(struct llqueue *queue){
    if(!queue || !queue->first){
        fprintf(stderr, "Failed to take item from queue, queue empty.\n");
    }
    void *retItem = queue->first->item;

    struct llitem *newFirst = queue->first->next;

    if(queue->first->next == NULL){
        queue->last = NULL;
    }

    free(queue->first);

    queue->first = newFirst;

    return retItem;
}

int empty(struct llqueue *queue){
    if(! queue || ! queue->first){
        return 1;
    } else {
        return 0;
    }
}

/* bst.h */
struct bst;

/* 
    The function you are to write. Takes a parent pointer (null for the root),
    and returns the tree with the child in the right position. Returns the
    item in a new tree with null left/right pointers.
*/
struct bst *bstInsert(struct bst *parent, int data);

/* Draws the tree. You will need to change this if your bst uses different names. */
/* You needn't understand how this works, but you're welcome to try. */
void drawTree(struct bst *parent);

/* 
    Frees the given tree, doing nothing on an empty tree, freeing child trees 
    (recursively) first, then freeing the passed parent.
*/
void freeTree(struct bst *parent);

/* bst.c */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* #include "llqueue.h" */
/* #include "bst.h" */

struct bst {
    struct bst *left;
    struct bst *right;
    int data;
};

/* 
    The function you are to write. Takes a parent pointer (null for the root),
    and returns the tree with the child in the right position. Returns the
    item in a new tree with null left/right pointers.
*/
struct bst *bstInsert(struct bst *parent, int data){
    /* Write this function. */
    
    
    
    
    
    
}

void freeTree(struct bst *parent){
    if(! parent){
        return;
    }
    /* Fill in function according to function description. */
}

/* Calculate the number of spaces which need to appear before and after the 
    data point at a given depth to allow a single character to occur in all 
    children below it. */
int spacesAtDepth(int depth);

/* Calculate the depth to the deepest child of a given node. */
int countDepth(struct bst *parent);

/* Draws the tree. You will need to change this if your bst uses different names. */
/* You needn't understand how this works, but you're welcome to try. */
void drawTree(struct bst *parent){
    int i;
    if(!parent){
        /* Done, no tree to print. */
        return;
    }
    
    struct llqueue *currentQueue = newQueue();
    struct llqueue *nextQueue = newQueue();
    /* Used for swapping. */
    struct llqueue *tempQueue;
    /* Current node being processed */
    struct bst *current;
    
    /* The depth of the parent, used to work out where to place the value. */
    int depth = countDepth(parent);

    /* The number of spaces needed at the current level before and after each
        data value. */
    int spaces = spacesAtDepth(depth);

    
    /* Add the parent node to the queue. */
    queue(&currentQueue, parent);
    
    while(!empty(currentQueue) && depth >= 0){
        current = (struct bst *) dequeue(currentQueue);
        for(i = 0; i < spaces; i++){
            printf("  ");
        }
        if(current){
            printf("%2d",current->data);
        } else {
            printf("  ");
        }
        for(i = 0; i < spaces; i++){
            printf("  ");
        }
        /* Account for parent's space */
        printf("  ");

        /* Queue any children for next row */
        if(current && current->left){
            queue(&nextQueue, current->left);
        } else {
            /* Mark empty space so spacing stays consistent. */
            queue(&nextQueue, NULL);
        }

        if(current && current->right){
            queue(&nextQueue, current->right);
        } else {
            /* Mark empty space so spacing stays consistent. */
            queue(&nextQueue, NULL);
        }
        
        if(empty(currentQueue)){
            /* Start new row. */
            printf("\n");
            /* Update depth information. */
            depth--;
            spaces = spacesAtDepth(depth);
            
            /* Swap the new row to the current row. */
            tempQueue = currentQueue;
            currentQueue = nextQueue;
            nextQueue = tempQueue;
        }
    }
    /* If we reach depth 0, the queue may still have contents
        we must empty first. */
    while(!empty(currentQueue)){
        current = (struct bst *) dequeue(currentQueue);
    }
    if(tempQueue){
        free(nextQueue);
    }
    if(currentQueue){
        free(currentQueue);
    }
}

int countDepth(struct bst *parent){
    int leftDepth;
    int rightDepth;
    if(!parent){
        /* Here we assume a leaf node is at depth -1, other choices are possible. */
        return -1;
    }
    leftDepth = countDepth(parent->left);
    rightDepth = countDepth(parent->right);
    if(leftDepth > rightDepth){
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}

int spacesAtDepth(int depth){
    int cDepth = depth;
    int result = 1;
    while(cDepth > 0){
        result = 2*result + 1;
        cDepth--;
    }
    return result;
}

/* main.c */
//%stdin: "8 4 9 11 6 7 1 5 3 14 10 13 2"
#include <stdio.h>
#include <stdlib.h>
/* #include "bst.h" */

int main(int argc, char **argv){
    int inputData;
    struct bst *bst = NULL;
    while(scanf("%d",&inputData) > 0){
        bst = bstInsert(bst, inputData);
    }

    drawTree(bst);
    
    freeTree(bst);

    return 0;
}
