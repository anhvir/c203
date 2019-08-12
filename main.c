/* Anh Vo, avo@unimelb.edu.au, for unimelb.COMP20003.Workshop.Week3 */

/* This file is a driver for "search", which is 
   a toy multiple-file project, demonstrating the use of:
   - generating a sorted array of integers,
   - sequential and binary search,
   - timing and
   - ouputing indicators of efficiency performance 
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "intArray.h"
#include "search.h"


#define STD_SIZE 10000       /* default size of the array-dictionnary */ 
#define STD_SEARCHES 100     /* default number of searches performed  */
double timer();              /* function for timing                   */

int main(int argc, char *argv[]) {
	int *A, n= STD_SIZE;      // A[n] represents a simplified dictionnary
	int *B, m= STD_SEARCHES;  // B[m] is array of keys to be searched for
	
	/****** Display info and checking arguments for validity ***/
	if (argc>1) n= atoi(argv[1]);
	if (argc>2) m= atoi(argv[2]);
	info();
	if (n<MIN_N || n>MAX_N || m<MIN_N || n>MAX_N) {
		printf("Usage: %s [n [m]]\n"
			   "  where %d <= n, m <= %d\n", argv[0],MIN_N,MAX_N);
		exit(EXIT_FAILURE);
	}   	
	
	/****** Creating dictionnary and a set of search keys ***/ 
	A= createSortedArray(n);
	B= createRandomArrayFromA(m,A,n); // B[] contains m random values of A[]

	/****** Performing searches and timing *****/
	double msec=0; 		 // total search time in microsecond
	double total_cmps=0; // total number of key comparison
	double founds=0; 	 // total number of successful searches
	int i, cmps; 		 // just buddy variables

	timer();			 // starts timing
	for (i=0; i<m; i++) {
		founds += (search(B[i],A,n,&cmps) != NOT_FOUND);
		total_cmps += cmps;
	}
	msec= timer();       // end timing 

	/****** Printing statistics       ******/
	printf("Dictionnary size n= %d\n", n);
	printf("Number of searches performed = %d\n", m);
	printf("Number of successful searches = %.0f\n", founds);
	printf("Average comparison per search= %.1f\n", total_cmps/m);
	printf("Notes: n/2= %.1f, log(n)= %.1f\n",
	        n/2.0, log(n)/log(2.0));
	printf("Average time per search (microseconds)= %.3f\n", msec/m);
 
	
	/****** Sanity: freeing all dynamic memory *******/ 
	deleteArray(&A);
	deleteArray(&B);
	return 0;
} 




/********************** TIMING TOOLS ***************************/	
#define SEC_2_MU_SEC 1000000

// timer: function for measuring time 
//   returns micro-seconds passed since the previous call to the function
double timer() {
	static clock_t start= 0;
		// Forgot about static variables? Ask our friend Google first.
	double mu_sec;

	mu_sec= ((double) (clock() - start)) / CLOCKS_PER_SEC * SEC_2_MU_SEC;
	start= clock();
	return mu_sec;
}


