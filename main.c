/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "linked_list.h"
#include "bu_msort.h"

/* 8 is a power of 2, so should be the least trouble. */
/* Try 7 to have to deal with an empty list */
#define SIZE 8

int main(int argc, char **argv){
    int inputs[SIZE];
    int i;
    
    struct linkedList *list = NULL;
    struct linkedList *current;
    
    /* Initialise random number generator. */
    time_t t;
    srand((unsigned) time(&t));
    
    printf("Original Array: ");
    for(i = 0; i < SIZE; i++){
        /* values between 0 and 99 are easier to read. */
        inputs[i] = rand() % 100;
        printf("%d ",inputs[i]);
    }
    
    printf("\n");
    
    printf("Adding all inputs to linked list.\n");
    for(i = 0; i < SIZE; i++){
        //list = prepend(list, inputs[i]);
        list = append(list, inputs[i]);
    }
    
    printf("Mergesorting.\n");
    list = mergeSort(list);
    printf("MergeSorted list: ");
    current = list;
    while(current){
        printf("%d ",current->item);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}
