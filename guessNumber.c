/* Anh Vo, anhvir@gmail.com, for unimelb.COMP20005.Workshop.Week2 */

/* This program asks your name, greets you, and then
	asks you to guess a number from 0 to 4,
	the program will terminate only after you give
	the right guess
*/

#include <stdio.h>			/* this should be in all of your C files! 		*/
#include <stdlib.h>			/* this should be in most of your C files 		*/
#include <time.h>			/* this: for using time(NULL) in line 15  		*/

#define MAX 5				/* MAX is a const with value 5,
								think of MAX (remmember Lord Voldermort?) 
								as a mnemonic name for 5					*/
#define MY_NAME "Anh"		/* MY_NAME is a constant valued "Anh" 			*/

int main(int argc, char *argv[]) {
	int answer,				/* "answer" is a variable that can hold only
									integer value, at this moment it has an
									undefined value							*/
		guess,				/* "guess" is smimilar to "answer"   			*/
		count= 0;			/* "count" is also an interger variable,
		 						but it has an initial value of zero	    	*/
		 					/* Note: lines 19-23 are equivalent to
		 								"int answer, guess, count=0;", or
		 								"int answer, guess; int count= 0; " */
									
	char name[50];			/* "name" is a string variable, it can hold
								any string (string= sequence of characters)
								of up to 50-1= 49 chracters					*/
	
	printf("Hi! My name's %s. \nWhat's your name? ", MY_NAME);
	scanf("%s", name);		/* Note: for string (and only for string),
							   we should not use "&name" in scanf			*/
	printf("\nGreat, %s! Very nice to meet you!\n\n", name);
	
	srand(time(NULL));      /* start using random numbers 					*/
							/* get a random number from 0 to 7-1, ie. 6    	*/

	answer= rand() % MAX; /* rand() will give us a random integer number
							   (which xould be very big),
							   and "% MAX" cuts that number down to 
							   the range from 0 to 6 (why?)   				*/	  
	
	printf("Now, let's start a game\n"
			"I have in my mind a secret number  between 0 and %d,\n"
			"you have to guess that number.\n"
			"The game will end after you give a correct guess!\n\n",
			MAX);
									
							
	guess = -1;             /* a fake value for guess, just to make sure      
	                           that it's not equal to "answer"              */
	                           
	while (guess != answer) {	/* the next 3 statements will be repeated
									whenever "guess" differs from "answer"	*/
		printf ("Make a guess = ");
		scanf("%d", &guess);
		count= count + 1;
	}
	
	printf("\nYou've got the right anser after %d guesses.\n", count);
	if (count <= MAX/2) {
		printf ("You were so smart!\n");
	} else if (count < MAX) {
		printf ("You did well!\n");
	} else {
		printf ("Not bad!\n");
	}
	
	printf("\nHope that you enjoyed it. See you!\n\n");
	
	return 0;
}

		
	
