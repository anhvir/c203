/* Anh Vo, anhvir@gmail.com, for unimelb.COMP20003.Workshop.Week2 */

/* This file is a driver for toy,
	it calls functions in prime.c and intArray.c.
   Purpose: builds array of random values and 
			print the elements that are prime,
   			also prints the percentage of prime elements.  
*/

#include <stdio.h>			/* for using scanf/printf				 		*/
#include "intArray.h"

#define ARRAY_SIZE_MAX 100
#define MIN 1
#define MAX 100

int main(int argc, char *argv[]) {
	int a[ARRAY_SIZE_MAX];
	int n;
	
	printf ("Enter number of elements in array: ");
	scanf("%d", &n);
	
    arrayGenRandom(a, n, MIN, MAX);
	
	arrayPrintPrime(a, n);

	return 0;
} 
	



