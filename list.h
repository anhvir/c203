/* 
   	Anh Vo, anhvir@gmail.com
	Simple implementation of list

	SUGGESTIONS:
		- blindly emply this implementation by just looking at list.h
		- when having time, build this file from scratch
          and/or study this implementation
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// defs for list_t ---------------------
typedef struct node {
	int key;             // change this for other data type
	struct node *next;
} node_t;

typedef node_t* list_t;


// creates & return empty list
list_t createL();   
// insert a new element {key} into the front of the list
void insertL(list_t *pl, int key); 
void freeL(list_t l);
// print list
void printL(list_t l);

#endif
