#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


/* The merge() and merge_sort() functions belows are downloaded from
         www.algorithmist.com/index.php/Merge_sort.c
   
*/

//
//   merge sorted a[] of n elements, b[] of n elements
//   into sorted c

void merge( int a[], int b[], int c[], int m, int n )
{
  int i = 0,    // let i walks through array a 
      j = 0,    // let j walks through array b
	  k = 0;    // choose the lesser of a[i], b[j] and copy to c[k]
  /* IMPLEMENT ME */
	 
}


//
// bottom-up merge sort array a of n elements
// currently it works only if n is a power of 2
// MAKE CHANGE  so that it accept any n
 
void merge_sort( int a[], int n )
{
  	int i, j, size, *tmp;
  	tmp = calloc( n, sizeof(int) );
  	assert(tmp);
  	// tmp is used for "merge"

    printf("merge_sort: Change me for working with any n\n");
  	// "size" is the common size of 2 arrays we want to merge 
  	for( size = 1; size < n; size *= 2 )
  	{
   		for( j = 0; j < (n - size); j += 2 * size )
      	{
			// at j-th element, so there are n-j more elements to process  
			
			// merge       size elems from a[j]
    		//       with  size elems from a[j+size]
			//    into tmp, from position j
        	merge(a + j, a + j + size, tmp + j, size, size);
      	}
		// copy tmp  to a
    	for ( i = 0; i < n; i++) a[i] = tmp[i];
  	}
 	free(tmp);
 
}

// print the array
void aprint(int a[], int n, char *title) {
	int i;
	if (title) printf ("%s\n", title);
	for (i=0; i<n; i++) printf("%d ",a[i]);
	printf("\n");
}

#define N 100
int main(int argc, char *argv[]) {
	int a[N];
	int i, n= N;
	srand(time(NULL));   // starts using rand() 

	printf ("Enter number of elements, between 1 and %d: ", N);
	while (scanf("%d", &n)==1 && n>0 && n<=N ) {
		for (i=0; i<n; i++) a[i]= rand() % n;
		aprint(a, n, "Before sort, a=");
		merge_sort(a, n);
		aprint(a, n, "After sort, a=");
		printf ("Enter number of elements, between 1 and %d: ", N);
	}
	return 0;
}




/* === DONT'T LOOK AT THE REST
       BECAUSE IT SHOWS PART OF THE SOLUTION
       READ IT ONLY AFTER YOU"VE DONE THE EXERCISE 
*/


















#if 0
void merge( int a[], int b[], int c[], int m, int n )
{
  int i = 0, j = 0, k = 0;
  while (i < m && j < n)
  {
    if( a[i] < b[j] )
    {
      c[k++] = a[i++];
    }
    else
    {
      c[k++] = b[j++];
    }
  }
 
  while ( i < m )
  {
    c[k++] = a[i++];
  }
 
  while ( j < n )
  {
    c[k++] = b[j++];
  }
}

#endif
