/* Anh Vo, avo@unimelb.edu.au, for unimelb.COMP20003.Workshop.Week3 */

/* tools for working with arrays of int 
*/

#ifndef _INTARRAY_H_
#define _INTARRAY_H_  

/* When we have a multiple-file projects, it is important that:
   - each .c file has its own header (.h) file, and each .h file should
   - have the first 2 #commands and the last #command similar to
     the one in this example. Google "#ifndef" for more info.
*/ 

#define MIN_N 1
#define MAX_N 1000000000

#ifndef NOT_FOUND       /* if NOT_FOUND not yet #define-d elsewhere */
  #define NOT_FOUND -1  /* then #define it with safe value -1       */ 
#endif

/*  Creates an array of n integers
    and populates it random numbers, in strictly increasing order     */
int *createSortedArray(int n);

/*  Creates an array of m integers,
    and populates it with random elements of array A[n] */
int *createRandomArrayFromA(int m, int *A, int n);

/* free aray *A[] and set *A to NULL */
void deleteArray(int **A);

#endif      /* this is the end of the topmost #ifndef */
