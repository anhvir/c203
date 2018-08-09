/* Anh Vo, anhvir@gmail.com, for unimelb.COMP20003.Workshop.Week2 */

/* This file supplies some tools 
	for working with arrays of int
   The file is always in development
*/

#include <stdio.h>			/* for using printf		        */
#include <stdlib.h>			/* for using rand(), srand()	*/
#include <time.h>			/* for using time(NULL)         */
#include "intArray.h"		
#include "prime.h"			/* for using isPrime()          */


/* populates array a with random numbers from l to r inclusive */	
void arrayGenRandom(int a[], int n, int l, int r) {
	int i;
	srand(time(NULL));    	/* use this command only ONCE,
								for starting using rand()*/
	for (i=0; i<n; i++) {
		a[i]= l + rand() % (r-l+1);	
					/* Note: rand() returns a large random integer	*/
	} 
}

/* print the elements that are prime, of array a,
   also prints the percentage of prime numbers in a */  
void arrayPrintPrime(int a[], int n){
	int i;
	int count=0;
	printf ("Array has %d elements, of them the prime numbers are:\n", n);
	for (i=0; i<n; i++) {
		if (isPrime(a[i])) {
			count++;
			printf("a[%d]= %d\n", i, a[i]);
		}
	}
	printf("\nHence, %.2f%% elements of a are prime numbers\n", count*100.0/n);}
 
	



