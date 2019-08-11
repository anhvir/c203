/*
   Complied by avo@unimelb.edu.au
*/

#ifndef _SEARCH_H_    /* What's that? see intArray.h */
#define _SEARCH_H_



#ifndef NOT_FOUND       /* if NOT_FOUND not yet #define-d elsewhere */
  #define NOT_FOUND -1 
#endif


/*  prints out background */
void info();

/*  performs a sequential search in array A[] 
	returns the index if found, and NOT_FOUND otherwise
	also set *cmps to number of key comparison
*/ 
int search(int searchkey, int *A, int n, int *cmps);
 

#endif
