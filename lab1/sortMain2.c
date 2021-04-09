#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])

{
 	int arr[100000];
	int arrItems; 
	int i; 
 
 	if(argc == 1){

    /* Test arr */ 
    arrItems = 4; 
    arr[0] = 10; 
    arr[1] = 20; 
    arr[2] = 30; 
    arr[3] = 40; 

    mySort(arr, arrItems); 
	printf("\n The sorted array is being printed out from Original data array:\n");
	 for(i = 0; i < arrItems; i++) { 
        printf("%d\n", arr[i]); 
 	 }
	}
  	else if(argc > 1){
	  arrItems = argc-1;
	      /* Test if array is sorted. */ 
    for(i =1; i < argc; i++){
		arr[i-1] = atoi(argv[i]); // array starts from zero and argv[i] goes up from argv[1])
	}		
		 
      
		mySort(arr,arrItems);
    

		printf("\n The sorted array is being printed out from data picked by user:\n");

        for(i = 0; i < arrItems; i++) { 
		printf("%d\n", arr[i]); }

      }	
  exit(0);
} 
