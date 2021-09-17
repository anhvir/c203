#include <stdlib.h>
#include <assert.h>
#include "ll.h"

struct linkedList *prepend(struct linkedList *head, int item){
    /* FILL IN if using. */
	struct linkedList *newHead = (struct linkedList *) 
		malloc(sizeof(struct linkedList));
	newHead->next = head;
	newHead->item = item;
	assert(newHead);
    return newHead;
}

/* Add a linked list item to the end of the list, traversing all items. */
struct linkedList *append(struct linkedList *head, int item){
    /* FILL IN if using. */
	struct linkedList **current = &head;
	while(*current){
		current = &((*current)->next);
	}
	*current = (struct linkedList *) malloc(sizeof(struct linkedList));
	assert(*current);
	(*current)->next = NULL;
	(*current)->item = item;
    return head;
}
