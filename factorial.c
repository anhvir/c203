/* factorial.c
   implementation of function factorial
*/

#include <assert.h>
#include "factorial.h"

int factorial(int n) {
	assert(n>0 && n<= MAX_N);

	int i, fact=1;
	for (i=1; i<=n; i++) {
		fact *= i;
	}
	return fact;
}


