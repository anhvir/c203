/* main.c:
   prints out n! using function factorial which 
       is defined and implemented in factorial.h and factorial.c
*/

#include <stdio.h>
#include "factorial.h"

int main(int argc, char *argv[]) {
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("%d! = %d\n", n, factorial(n));
	return 0;
}
	


