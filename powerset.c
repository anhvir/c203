/* 
   Skeleton Program for 
   computing, storing and printing out in binary format the powerset
   of an alphabet having size of at least 1 and at most N_MAX 
*/
   
   
  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N_MAX 10

void build_pset(char **ps, char a[],int i, int n);
void print_pset(char **ps, int num);

int main(int argc, char *argv[]) {
	int n;     /* size of alphabet */
	int pn;    /* =2^n, number of elements in powerset array ps[] */
    // FIXME: the next 2 lines contain errors
	char a,   /* string for containing the current set of powerset ps[] */  
	 	 ps; /* the powerset, which is array of 2^n strings,
                        each string is of lenght n */
	int i;

    /* ------- processing arg line -------------------------------------- */
	if (argc != 2 || atoi(argv[1])<1 || atoi(argv[1])>N_MAX ) {
		printf ("Usage: %s size_of_alphbet\n", argv[0]);
		printf ("       where size_of_alphabet is between 1 and %d\n", N_MAX);
		exit(EXIT_FAILURE);
	}

	n= atoi(argv[1]);
	pn= 1 << n;   /* that is, pn = 2^n  
                     can also use pn= (int) pow(2,n)  */

    /* ---FIXME: How to allocate memory  ------------------------- */
    a= malloc(?)       
    ps= malloc ( ? );   /* first, allocate memory so that
                           ps can hold pn pointer to char, ie pn string */
	for (i=0; i<pn; i++) {
		?;
                        
    }

    /* ------- main job           -------------------------------------- */
	build_pset(ps, a, 0, n); /* building array ps[], by building
             each of its member into string a, starting from a[0],
             final length of each member is n */	

	print_pset(ps, pn);       /* print the arry ps[] of pn elements */  

    /* ------- free memory       -------------------------------------- */
    /* A good rule for doing "free" is "1 free for 1 malloc"
       FIXME: how o do that?                                       */



	return 0;
}



/* ------------------------------- sub-function zone -------------------------- */
/* 
	building array ps[], by building each of its member	
	 into string a, starting from a[0], final length of
	 each member is n
*/
/* Note: this function is recursive
         and also use a static variable   
*/	
void build_pset(char **ps, char a[],int i, int n) {
	static int pi= 0;
	if (i==n) {             /* when i==n, we finish one subset in a  */    
		a[n]= '\0';
		strcpy( ps[pi], a); /* so, we copy it to ps[pi], and         */         
        pi++;               /*    increase pi for next use           */
		return;
	}
	a[i]= '0'; build_pset(ps, a, i+1, n); 
                            /* if i<n, we first set a[i]= '0' and continue 
                                to build a from next position  */
	a[i]= '1'; build_pset(ps, a, i+1, n);   
                            /* then, we set a[i] to '1'
                                  and do similar thing         */
}
 
/* just print out all "num" strings of ps[] */
void print_pset(char **ps, int num) {
	for (int i=0; i<num; i++)
		printf("powerset[%d]= %s\n", i, ps[i]);
}

