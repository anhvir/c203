/* Anh Vo, avo@unimelb.edu.au, for unimelb.COMP20003.Workshop.Week3 */

/* This module intArray.? supply tools for:
	- creating a sorted array of int, and delete it when needed
	- creating a array consisting of random elements of a given array
	- ...   (you might want to add more) 
*/

#include <stdlib.h>			/* for using rand(), srand()	*/
#include <assert.h>
#include <time.h>			/* for using time(NULL)         */
#include <limits.h>
#include "intArray.h"		



/*  Creates an array of n integers
	and populates it random numbers, in strictly increasing order 
*/
int *createSortedArray(int n) {
	static int need_srand=1;
	int *A; 
	int i;
	if (need_srand) {
		srand(time(NULL));    	/* this command runs only ONCE */
		need_srand= 0;
	}
	assert( (n>=MIN_N && n <= MAX_N)  && "Wrong call to createSortedArray");	

	// allocate memory for A
	A= malloc( n* sizeof(*A) );
	assert(A && "intArray.c failed to malloc");
	
	A[0]= 1;			// always sets A[0]= 1						
	for (i=1; i<n; i++) {
		int delta= (INT_MAX - A[i])/n;
		assert (delta>0 && "Internal error in createArray");
		A[i]= A[i-1] + 1 + rand() % delta;	
	} 
	// Question? Ask google for rand() in C
	return A;
}


/*  Creates an array of m integers,
    and populates it with random elements of array A[n] 
*/
int *createRandomArrayFromA(int m, int *A, int n) {
	int *B; 
	int i;
	assert( (m>=MIN_N && m <= MAX_N) 
			&& "Wrong call to createRandomArrayFromA");	

	// allocate memory for B
	B= malloc( m* sizeof(*B) );
	assert(B && "intArray.c failed to malloc");
	
	for (i=0; i<m; i++) {
		B[i]= A[ rand() % n ];
	} 
	return B;
}

/* free aray *A[] and set *A to NULL 
*/
void deleteArray(int **A) {
	free(*A);
	*A= NULL;
	// Question: Do I actually need "int **A"? Why not just "int *A"?
}
