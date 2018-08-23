/* Anh Vo, anhvir@gmail.com, for COMP20003 @ unimelb
   stack.[c,h], postfix.c: demonstrating the use of stack
                           in evaluating postfix expression 
                           (reverse Polish notation)
   CONCEPTS: Postfix expression is an (here, arithmetic) expression
             where operators follow operands, for example:
               3 5 +       means 3+5
               2 3 5 + *   means 2 * ( 3 + 5 )
             Here, we use stack to evaluate the expression, for example,
             the second expression is evaluated as:
				read 2
				push 2
				read 3
				push 3
				read 5
				push 5
				read +  (which is an operator requiring 2 operands)
				pop (=5)   
				pop (=3)
				push 3*5 
				read *  (which is an operator requiring 2 operands)
                pop (=15)
				pop (=2)
				push 2*15
                as input finishes, pop (=30) gives the final value
	  

   NOTES:
    - You can use this code for study purpose, 
      and make references appropriately.
    - There is no warantee that the code(s) will work,
      and Anh Vo will not be responsible for any damage
      resulting from using the code. 
    
*/

#define ARRAY_STACK


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#ifdef ARRAY_STACK
  #include "stack.h"
#else
  #include "listStack.h"
#endif 

#define MAX_STRLEN 255

int main(int argc, char *argv[]) {
	char s[MAX_STRLEN+1];
	char *p;
	int a, b, c;
	stack_adt *st= createStack();

	while (fgets(s, MAX_STRLEN, stdin)) {   // read new expression to s
		printf("Expression: %s ", s);
		for (p=s; *p; p++) {
			if (isdigit(*p)) {              // gets a number
				for (a= 0; *p && isdigit(*p); p++) a= a*10 + (*p-'0');
				push(st, a);
				continue;
			} else if (isspace(*p)) continue;
			/* now, *p must be a binary operator (a limit of this prog) */
			if (countStack(st)<2) { // should have at least 2 operands      
				printf("\nToo few operands in expression\n");
				exit(EXIT_FAILURE);
			}
			a= pop(st);    // now takes 2 operands & perform calculation
			b= pop(st);
			switch (*p) {
				case '+': c= a+b; break;
				case '-': c= a-b; break;
				case '*': c= a*b; break;
				case '/': c= a/b; break;
				default:
					printf("\nUnrecognzed operator in expression\n");
					exit(EXIT_FAILURE);
			}
			push(st, c);
		}

		if (countStack(st) != 1) {
				printf("\nWrong balance between operators and operands in expression\n");
				exit(EXIT_FAILURE);
		}
		printf("   Value= %d\n", pop(st));	
	}
	deleteStack(st);
} 
