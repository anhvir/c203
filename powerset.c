/* Anh Vo anhvir@gmail.com for COMP20003 @unimelb   
   Program for computing, storing and printing out in binary format the powerset
   of an alphabet having size of at least 1 and 
            at most 30 (max value for N_MAX in line 20 can be 30) .
   Why 30? Because it's big enough, and because I use 1<<n  (n  <= N_MAX ).
   Can we make it to 63? Yes, use long long unsigned int instead of int
   Can we make it larger than 63, yes, but with a little bit of change,
     and after all that big value is usless (impractical) here!
 
   Approach: Recursive function is usd for computing powerset.
*/
   
   
  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N_MAX 25

void build_pset(char **ps, char a[],int i, int n);
void print_pset(char **ps, int num);

int main(int argc, char *argv[]) {
	int n;           /* size of alphabet */
	int pn;          /* =2^n, number of elements in powerset array ps[] */
	char *a,         /* string for containing the current set of powerset ps[] */  
	 	 **ps;       /* the powerset, which is array of 2^n strings,
                        each string is of lenght n */
	int i;

    /* ------- processing arg line -------------------------------------- */
	if (argc != 2 || atoi(argv[1])<1 || atoi(argv[1])>N_MAX ) {
		printf ("Usage: %s size_of_alphbet\n", argv[0]);
		printf ("       where size_of_alphabet is an integer between 0 and %d\n", N_MAX);
		exit(EXIT_FAILURE);
	}

	n= atoi(argv[1]);
	pn= 1<<n;   /* that is, pn = 2^n, we also can use pn= (int) pow(2,n)
                   in math library  */

    /* ------- allocating memory  -------------------------------------- */
    a= malloc((n+1)*sizeof(*a));       
    ps= malloc ( pn * sizeof (*ps));   /* first, allocate memory so that
										  ps can hold pn pointer to char, ie pn string */
	for (i=0; i<pn; i++) {
		ps[i]= (char*) malloc((n+1) * sizeof(**ps));
                                       /* then, allocate memory for each string ps[i] */
    }

    /* ------- main job           -------------------------------------- */
	build_pset(ps, a,0,n);	  /* building array ps[], by building each of its member	
								 into string a, starting from a[0], final length of
								 each member is n */	

	print_pset(ps, pn);       /* print the arry ps[] of pn elements */  

    /* ------- free memory       -------------------------------------- */
    /* A good rule for doing "free" is "1 free for 1 malloc"
       I actually copy and paste all the malloc statements and loops here, but
         in reversed order of appearance (that's important most of the time),
         then replace malloc by free. Doing this way we can save some of our
         brain nerves :-)                                                     */

	for (i=0; i<pn; i++) {
		free (ps[i]);         /* free memory for each string ps[i] */
    }
	free(ps);                 /* then, free memory for ps itself   */
	free(a);                  /* free memory of a                  */


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
	static int pi= 0;          /* "static" means pi=0 is executed only when
                                  build_pset() is first called,
                                  the current value of pi will retain for
                                  the subsequent calls */
	if (i==n) {                /* when i==n, we finish one subset in a  */    
		a[n]= '\0';
		strcpy( ps[pi], a);    /* so, we copy it to ps[pi], and         */         
        pi++;                      /*    increase pi for next use           */
		return;
	}
	a[i]= '0'; build_pset(ps, a, i+1, n); /* if i<n, we first set a[i]= '0' and continue 
                                            to build a from next position  */
	a[i]= '1'; build_pset(ps, a, i+1, n);   /* then, we set a[i] to '1'
                                            and do similar thing         */
}
 
/* just print out all "num" strings of ps[] */
void print_pset(char **ps, int num) {
	for (int i=0; i<num; i++)
		printf("%s\n", ps[i]);
}

