#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
//Insertion sort inspired from lab1 mySort
    { 
   	 int i, key, j;  /* instance variables*/
   	 for (j = first; j <= last; j++) 
    	{  
      	  key = array[j];  
       	  i = j - 1;  
  
        
       	 while (i >=0 && (myCompare(array[i],key) > 0)) // if array[i] and key have a difference or greater than 
//zero, then the second numbe will swap places with the number infront until the array is sorted
       	 { 
            mySwap(&array[i + 1], &array[i]);  
            i = i - 1;  
       	 }  
        myCopy(&key,&array[i + 1]);  // will copy the amount of times key and array are switched. 
    }  
}  
   
