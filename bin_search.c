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
	printf("*   Performing BINARY SEARCH in a sorted array of int  *\n");
	printf("********************************************************\n");
	printf("\n");
}

/*  performs a sequential search in array A[] 
	returns the index if found, and NOT_FOUND otherwise
	also set *cmps to number of key comparison
*/ 
int search(int searchkey, int *A, int n, int *cmps) { 
	int start =0;
	int end = n-1;
	int mid;

	*cmps= 0;
  
	while(start <= end){
		(*cmps)++;
		mid =(start + end )/2;    //DIVIDE: Get the middle position
		if(A[mid]==searchkey)
			return mid;
		
		// If middle element smaller than key, 
		//    then update the end, discard A[mid,..,end]
		if(searchkey < A[mid])
			end = mid-1;
		else  // otherwise, update the beggining and discard A[start,..,mid]
			start = mid+1;
	}

	return NOT_FOUND;
}
