/*
	anhvir@gmail.com
    
    A simplest implementation of heap
	For comp20003 Week 9 - extended lab 

    In this implementation:
	   - the heap is a min Heap, with keys are integers 
	   - one data item in heap is just an integer, and is used as the key
	   - operation "changeWeight" is not implemented,
	     in fact, it cannot be implemented in an efficient way 

*/
typedef struct item {
    int key;         // the key for deciding position in heap
	                 // there might be some additional components
} heapItem_t;

typedef struct heap {
    heapItem_t *H;   // the underlying heap array
    int    n;        // the number of items currently in the heap
    int    size;     // the maximum number of items allowed in the heap
} heap_t;


heap_t *createHeap(void);         // returns a pointer to a new, empty heap
void enHeap(heap_t *h, int key);   // inserts dataIndex into h
int deleteMin(heap_t *h);         // removes the root, returns the its key 
int peek(heap_t *h);              // returns the the root's key 
void emptyHeap(heap_t *h);        // frees any memory associated with heap

void buildHeap(heap_t *h, int a[], int n);
                                  // builds heaps with "n" keys taken from
                                  //   array "a"
void printHeap(heap_t *h);        // prints the heap array
