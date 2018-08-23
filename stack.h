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


#ifndef _STACK_H_
#define _STACK_H_

#define INIT_SIZE 8
typedef struct {
	int *a;    /* supposing that stack’s elements are int */ 
	int head;
	int size;
} stack_adt; 	
stack_adt *createStack(); 
void push( stack_adt *ps, int x); 
int pop( stack_adt *ps ); 
void deleteStack( stack_adt *ps );
int countStack( stack_adt *ps);

#endif    
			 

