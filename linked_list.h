/* anhvir@gmail.com: *) This file was a part of p.7.1.c 
                        which was posted in LMS for Workshop Week 8
                     *) Some small changes have beed introduced
*/ 

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linkedList {
    struct linkedList *next;
    int item;
};

/* Add a linked list item before the head of the given item. */
struct linkedList *prepend(struct linkedList *head, int item);

/* Add a linked list item to the end of the list, traversing all items. */
struct linkedList *append(struct linkedList *head, int item);

#endif
