#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int heapDelete();
extern void addHeap(int);
extern void heapify(int);

int main(int argc, char * argv[])
{
  int value;
  int heapArray[100];
  int i = 0;
  int j;
  int k = 0;
  int t = 0;
  int begin = 0;
  
  fprintf(stdout,"\n Please Enter the Nodes. Enter '-1' when finished entering nodes: \n \n");

  while (1) {

    	fprintf(stdout,"Enter the node number: ");
    	scanf("%d", &value);
    	if (value == -1)
    		break;
    	heapArray[i++] = value;
    }	  
	
  while(begin < i) {
	k = begin;

	for(j = begin; j < i; j++) {

		if(heapArray[j] > heapArray[k]) {
			k = j;
		}
	}

	addHeap(heapArray[k]);
	t = heapArray[begin];
	heapArray[begin] = heapArray[k];
	heapArray[k] = t;
	begin++;
  }

  fprintf(stderr, "\n");
  heapify(1);
  fprintf(stderr, "\n\n");

  for(i = 0; i < begin; i++) {
	push(heapDelete());
	}

  fprintf(stderr, "\n");

  for(i = 0; i < begin; i++) {
	fprintf(stderr, "%d\n", pop());
}     
 
  exit(0);
}
