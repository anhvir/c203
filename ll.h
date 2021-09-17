#ifndef LINKEDLIST_STRUCT
#define LINKEDLIST_STRUCT
struct linkedList {
    struct linkedList *next;
    int item;
};
#endif

/* Add a linked list item before the head of the given item. */
struct linkedList *prepend(struct linkedList *head, int item);

/* Add a linked list item to the end of the list, traversing all items. */
struct linkedList *append(struct linkedList *head, int item);
