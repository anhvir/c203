/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   msa_queue.c: skeleton for implementing natural mergesort
                on an array of int,
                using queue  (in isupplied lqueue.[c,h])

   NOTES:
    - The merge() function  is extracted from
         www.algorithmist.com/index.php/Merge_sort.c
    - You can use this code for study purpose, 
      and make references appropriately.
    - There is no warantee that the code(s) will work,
      and Anh Vo will not be responsible for any damage
      resulting from using the code. 
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lqueue.h"


/* The merge() functions below is extracted from
         www.algorithmist.com/index.php/Merge_sort.c
   
*/

//
//   merge sorted a[] of n elements, b[] of n elements
//   into sorted c[]

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

// IMPLEMENT ME: you need to implement only this function (merge_sort)
//               for natural merge sorting
//
// in this merge_sort, you will use queues
// you can use queue implementation in supplied lqueue.c and lqueue.h
// and complile your program with
//    gcc -o msa msa_queue.c lqueue.c
//  (build Makefile if you like)
//
// ALTERNATIVELY, you can build your own queue, or using
//   queue implementation from somewhere else 

// Hint: You can implement the standard merge sort first,
//		 make sure it works properly, and measure its efficiency;
//       Then, change from standard to natural merge sort
//
// bottom-up merge sort array a of n elements
// returns number of elemenst examined by the merge process
 
int merge_sort( int a[], int n )
{
  int i, s1, s2, *tmp;
  int count= 0;   // number of elements examined by merge
  lqueue_t q= ....     // creating a queue, 
		// q will be use to manage the merging process
		// an element of q will contains the number of elements
 		//    of a to-be-merged array 
		// for example, if a[]= {1,2,4,  2,5}
		//    then intinially we enqueue 3 and 2
		//    which means that to-be-sorted arrays are:
		//    a[0..2] (3 elements) and a[3..4] (2 elements)
		// 	
  tmp = safe_malloc( n * sizeof(int) );
  		// tmp is used for "merge"

  // first, init the queue using initial array a[]
  ...
  
  // then, loop (based on q), the job finishes when there is only
  //    one element in queue (and it must be n)
  while (!is_singleton(q)) {

    // .........     

    // remember to update "count" when calling merge()
	
	// copying tmp[] back to a[], prepare for next round 
    for ( i = 0; i < n; i++) a[i] = tmp[i];
  }

  free(tmp);
  
  // delete queue here!
  ......

  return count;
 
}

void aprint(int a[], int n, char *title) {
	int i;
	if (title) printf("%s\n",title);
	for (i=0; i<n; i++) printf("%d ",a[i]);
	printf("\n");
}

#define N 200
#define N_MIN 10
#define CHUNK_MAX 10
int main(int argc, char *argv[]) {
	int a[N];
	int i, n= N, chunk=0;
	int count;
	
	printf("Enter n between %d and %d:",N_MIN,N);
	while (scanf("%d", &n)==1 && n>=N_MIN && n<=N) {

		// build a as a sequence of increasing subsequences
		for (i=0; i<n; i++) {
			if (chunk==0) {
				a[i]= rand() % (n/2);
				chunk= rand()%CHUNK_MAX;
			} else { 
 				a[i]= a[i-1] + rand() % n;
				chunk--;
			}
		}

   		// sorting
		aprint(a, n, "Before sorting, array=");
		count= merge_sort(a, n);
		aprint(a, n, "After sorting, array=");
		printf ("elements examined by merge= %d\n"
			    "                n * log2n = %d\n\n",
				count, (int) ceil( (n * log(n)/log(2) )) );

		printf("Enter n between %d and %d:",N_MIN,N);
	}
	return 0;
}













// DON'T LOOK FURTHER BEFORE COMPLETING YOUR PROGRAM
//   the rest contains solution
































#if 0
// THIS IS A SOLUTION FOR standard merge_sort, not natural merge_sort
//
// bottom-up merge sort array a of n elements
// returns number of elemenst examined by the merge process
 
int merge_sort( int a[], int n )
{
  int i, size, s1, s2, m, *tmp;
  int count= 0;   // number of elements examined by merge
  lqueue_t q= create_lqueue();
		// q will be use to manage the merging process
		// an element of q will contains the number of elements
 		//    of a to-be-merged array 
		// for example, if a[]= {1,2,4,  2,5}
		//    then intinially we enqueue 3 and 2
		//    which means that to-be-sorted arrays are:
		//    a[0..2] (3 elements) and a[3..4] (2 elements)
		// 	
  tmp = safe_malloc( n * sizeof(int) );
  		// tmp is used for "merge"

  // first, init the queue using initial array a[]
  //   for natural mergesort, you need to change the next line
  for (i=0; i<n; i++) enqueue(1, q);

  
  // then, loop (based on q)
  while (!is_singleton(q)) {
	for (i=0; i<n; i += s1 + s2) {  
		s1= dequeue(q);
		if (i+s1 < n) {
			s2= dequeue(q);
      		merge(a + i, a + i + s1, tmp + i, s1, s2);
			count += s1+s2;
		} else s2= 0;
		enqueue(s1+s2, q);
    }
    for ( i = 0; i < n; i++) a[i] = tmp[i];
  }

  free(tmp);
  
  // delete queue here!
  delete_lqueue(q);

  return count;
 
}

#endif
