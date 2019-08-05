#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NAME_LEN_MAX 8

int main(int argc, char *argv[]) {
	char friends[][NAME_LEN_MAX+1]= {	
		"Jack",	"William",	"Noah",	"Ethan",	"Oliver", 
		"Thomas",	"Cooper",	"James",	"Lucas",	"Lachlan",
		"Olivia",	"Charlotte",	"Mia",	"Ava",	"Chloe",
		"Amelia",	"Sophie",	"Emily",	"Ruby",	"Ella"
	};
	int n= 50;
	char *someone= NULL;
	int r;
	int i;

    srand(time(NULL));  /* if you want to use random numbers, you should
                           have this line one and only one time */  
	
	printf("My friends are:\n");	
    for (i=0; i<n; i++) {
		printf("%s, ", friends[i]);	
	}

	r= rand() % n;	    /* rand() returns a large random number
                           %n cuts the number down to range 0..n-1 
                           type "man rand" in Terminal to know more 
                           or asks Google  */
 
	strcpy(someone, friends[r]);
	
	printf("\n\nYou want to talk with a random friend of mine?\n");
	printf("Well, perhaps you want to talk with %s\n", someone); 		 
	
	
    return 0;
}
