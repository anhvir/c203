/* 

	SUGGESTIONS:
		- blindly emply this implementation by just looking at list.h
		  (ie ignore list.c)
		- when having time, build this file from scratch
          and/or study this implementation

   	Anh Vo, anhvir@gmail.com
	Simple implementation of lists and queues
*/

#include "list.h"

//---- list function
list_t createL() {
	return NULL;
}

void insertL(list_t *pl, int key) {
	list_t node= malloc(sizeof(*node));
	node->key= key;
	node->next= *pl;
	*pl= node;
}

void freeL(list_t l) {
	list_t tmp;
	while (l) {
		tmp= l;
		l= l->next;
		free(tmp);
	}
}

// note: this function works only when key is int
void printL(list_t l) {
	while (l) {
		printf("%d", l->key);
		l= l->next;
		printf("%s", l? " -> " :  "");
	}
	printf("\n");
}

