#include <stdio.h>
#include <stdlib.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
static int top = 1;
static int bottom = 1;
static int heap[100];
static int size = 0; 

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	int thing2delete;
    thing2delete = heap[heapSize()];
    size--;
    return thing2delete;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */

void addHeap(int thing2add)
{
	heap[top++] = thing2add;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */

int heapSize()
{
  return top-bottom;  //A dummy return statement
}

void heapify(int node)
{
  if(node <= heapSize()) {
    fprintf(stderr, "<node id=\"%d\">", heap[node]);
	heapify(2*node);
	heapify(2*node + 1);
	fprintf(stderr, "</node>");  
  }
}
