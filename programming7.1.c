#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "merge.h"
#include "ll.h"

/* 8 is a power of 2, so should be the least trouble. */
/* Try 7 to have to deal with an empty list */

int main(int argc, char **argv){
    int *inputs;
    int i;
    
    struct linkedList *list = NULL;
    struct linkedList *current;
    
    /* Initialise random number generator. */
    time_t t;
    srand((unsigned) time(&t));

    int size;
    assert(scanf("%d", &size) == 1);
    inputs = (int *) malloc(sizeof(int) * size);
    assert(inputs);
    
    printf("Original Array: \n");
    for(i = 0; i < size; i++){
        /* values between 0 and 99 are easier to read. */
        inputs[i] = rand() % 100;
        printf("%d ",inputs[i]);
    }
    
    printf("\n");
    
    printf("Adding all inputs to linked list.\n");
    for(i = 0; i < size; i++){
        list = prepend(list, inputs[i]);
    }
    /* Done with adding inputs. */
    free(inputs);
    
    printf("Mergesorting.\n");
    list = mergeSort(list);
    printf("MergeSorted list: \n");
    current = list;
    while(current){
        printf("%d ",current->item);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}
