/* Anh Vo, avo@unimelb.edu.au, for unimelb.COMP20003.Workshop.Week3 */

/* function search() is copied from Nir's Week 2 lecture slides
   with some trivial changes (just to fit the code into a function)
*/

#include <stdio.h>
#include "search.h"

/*  prints out background 
*/
void info() {
	printf("********************************************************\n");
	printf("*  Performing SEQUENTIAL SEARCH in an array of int     *\n");
	printf("********************************************************\n");
	printf("\n");
}

/*  performs a sequential search in array A[] 
	returns the index if found, and NOT_FOUND otherwise
	also set *cmps to number of key comparison
*/ 
int search(int searchkey, int *A, int n, int *cmps) { 
	int i;
	*cmps= 0;  
	for(i=0; i<n ; i++) { /*A[] is an array of integers */
		(*cmps)++;
		if (A[i] == searchkey) {
			return i;   // just returns the index 
		}
	}
	return NOT_FOUND;
}
