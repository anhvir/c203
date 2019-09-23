#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//
//   merge sorted a[] of n elements, b[] of n elements
//   into sorted c

void merge( int a[], int b[], int c[], int m, int n ) {
	int i = 0, j = 0, k = 0;
	for (k=0; k<m+n; k++) {
		if (i==m)                c[k]= b[j++];
		else if (j==n)           c[k]= a[i++];
		else if ( a[i] <= b[j] ) c[k]= a[i++];
		else                     c[k]= b[j++];
	}
}


//
// bottom-up merge sort array a of n elements
 
void merge_sort( int a[], int n ) {
	int i, size, s1, s2, *tmp;
	tmp = calloc( n, sizeof(int) );
	assert(tmp);
	// tmp is used for "merge"

	// "size" is the run length= common size of 2 arrays we want to merge 
	for( size = 1; size < n; size *= 2 ) {
		for( i = 0; i < n; i+= s1+s2) {
			// computing s1 and s2: the actual length of 1st and 2nd runs
			s1= s2= size;       // - standard case: both runs are full
			if (i+size > n) {   // - when 2nd run is empty
				s1= n-i;
				s2= 0;
			} 
			else if (i+size+size>n) { // - when 2nd run not full 
				s2= n -i - size;
			}
				
			merge(a + i, a + i + s1, tmp + i, s1, s2);
		}

		for ( i = 0; i < n; i++) a[i] = tmp[i];
	}
	free(tmp);
}

void aprint(int a[], int n, char *title) {
	int i;
	printf("%s\n-------------------------------\n",title);
	for (i=0; i<n; i++) printf("%d ",a[i]);
	printf("\n");
}

#define N 1000

int main(int argc, char *argv[]) {
	int i, n, *a;
	printf("\nRunning bottom-up mergesort in an array of n integers\n");
	printf("Enter value of n= ");
	scanf("%d", &n);
	assert( n>0 && n<= N);

	a= malloc( n * sizeof(*a) );
	assert(a);
	srand(time(NULL));
	for (i=0; i<n; i++) a[i]= rand()%n;

	aprint(a, n, "Array before sorting:");
	merge_sort(a, n);
	aprint(a, n, "Array after sorting:");

	free(a);
	return 0;
}
