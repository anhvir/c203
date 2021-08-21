// Feel free to use these function in your code, but remember
//   to put reference: From github.com/anhvir/c203

#include "utils.h"

void *my_malloc(size_t n){
	assert(n>0);
	void *p= malloc(n);
	assert(p);
	return p;
} 

void *my_realloc(void *old, size_t n){
	assert(n>0);
	void *p= realloc(old, n);
	assert(p);
	return p;
} 

FILE *my_fopen(const char *fname, const char *mode) {
	FILE *f= fopen(fname, mode);
	assert(f);
	return f;
}

char *my_strdup(char *s) {
	char *t= strdup(s);
	assert(t);
	return t;
}
