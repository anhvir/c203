#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN_MAX 8

int main(int argc, char *argv[]) {
	char friends[][NAME_LEN_MAX+1]= {	
		"Jack",	"William",	"Noah",	"Ethan",	"Oliver", 
		"Thomas",	"Cooper",	"James",	"Lucas",	"Lachlan",
		"Olivia",	"Charlotte",	"Mia",	"Ava",	"Chloe",
		"Amelia",	"Sophie",	"Emily",	"Ruby",	"Ella"
	};
	int n= 50;
	char *someone;
	int r;
	int i;
	
	printf("My friends are:\n");	
    for (i=0; i<n; i++) {
		printf("%s, ", friends[i]);	
	}

	r= rand() % n;	
	strcpy(someone, friends[r]);
	
	printf("\n\nYou want to talk with a random friend of mine?\n");
	printf("A random friend is %s\n", someone); 		 
	
	
    return 0;
}
