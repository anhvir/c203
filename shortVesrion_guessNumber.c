/* Anh Vo, anhvir@gmail.com, for unimelb.COMP20005.Workshop.Week2 */

/* This program asks your name, greets you, and then
	asks you to guess a number from 0 to 4,
	the program will terminate only after you give
	the right guess
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5	
#define MY_NAME "Anh"

int main(int argc, char *argv[]) {
	int answer,	
		guess,		
		count= 0;
	char name[50];		

	printf("Hi! My name's %s. \nWhat's your name? ", MY_NAME);
	scanf("%s", name);
	printf("\nGreat, %s! Very nice to meet you!\n\n", name);
	
	srand(time(NULL)); 
	answer= rand() % MAX; 
	
	printf("Now, let's start a game\n"
			"I have in my mind a secret number  between 0 and %d,\n"
			"you have to guess that number.\n"
			"The game will end after you give a correct guess!\n\n",
			MAX);
	guess = -1; 
	while (guess != answer) {
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

		
	
