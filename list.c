/* linked lists, as defined in the lectures */

#include <stdio.h>

typedef struct node {
	int key;
	struct node *next;
} node_t;

typedef node_t* node_ptr;

int main(int argc, char *argv[]) {
	node_ptr listhead= NULL;
	node_ptr p= listhead;


    while (p) {
		printf("%d\n", p->key);
		p= p->next;
	}
       
}
