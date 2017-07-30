/* tools for working with arrays of int 
*/

#ifndef _INTARRAY_H_
#define _INTARRAY_H_  



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE_MAX 20

/* populates array a with random numbers from a to b inclusive */	
void arrayGenRandom(int a[], int n, int l, int r);

/* print the elements that are prime, of array a,
   also prints the percentage of prime numbers in a */  
void arrayPrintPrime(int a[], int n);




#endif
