#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void *my_malloc(size_t n);
void *my_realloc(void *old, size_t n);
FILE *my_fopen(const char *fname, const char *mode);
char *my_strdup(char *);

#endif
