/* Tools for working with prime numbers.
*/

#include "prime.h"


/* Determine whether n is prime. */
int
isPrime(int n) {
	int divisor;
	if (n<2) {
		return 0;
	}
	for (divisor=2; divisor*divisor<=n; divisor++) {
	       if (n%divisor==0) {
		       /* factor found, so can't be prime */
		       return 0;
		}
	}
	/* no factors, so must be prime */
	return 1;
}

int
nextPrime(int n) {
	n = n+1;
	while (!isPrime(n)) {
		n = n+1;
	}
	return n;
}

/* =====================================================================
   Program written by Alistair Moffat, as an example for the book
   "Programming, Problem Solving, and Abstraction with C", Pearson
   Custom Books, Sydney, Australia, 2002; revised edition 2012,
   ISBN 9781486010974.

   See http://people.eng.unimelb.edu.au/ammoffat/ppsaa/ for further
   information.

   Prepared December 2012 for the Revised Edition.
   ================================================================== */
