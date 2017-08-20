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


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


stack_adt *createStack() {
	stack_adt *ps;	
	ps= (stack_adt *) malloc(sizeof(*ps));   // and assert(…
	ps->size= INIT_SIZE;
	ps->a= malloc( ps->size * sizeof(int) ); // assert
	ps->head= 0;
	return ps;
}

void push( stack_adt *ps, int x) {
	if ( ps->head == ps->size ) {
		ps->size *= 2;
		ps->a= realloc( ps->a, ps->size * sizeof(int) ); //assert
	}
	ps->a[ ps->head++ ]= x;
}  	

int pop( stack_adt *ps ) {
	assert( ps->head > 0 );
	return ps->a[ --ps->head ];
}

void deleteStack( stack_adt *ps )  {  
	free( ps->a );
	free(ps);
}
			 
int countStack( stack_adt *ps) {
	return ps->head;
}
