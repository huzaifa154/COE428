#include "mySort.h"


void merge(int arr[], int first, int middle, int last) {

int temp[MAX_SIZE_N_TO_SORT];
    int f,m,n,l,temp_value;
    f = first;
    m = middle;
    n = middle+1;
    l = last;
    temp_value = 0;

    while(f < m+1 && n < l+1) 
/* first (f) is the first half of the array and therefore must be less than the second half(m+1).
the second half (n) must be less than the last element or else it will be outside of array. 
*/
    {
// if the difference is less than zero, meaning if they are not equal to each other since arr[f] is
// first half of original array and arr[n] is the second half of original array, it will copy the values
//for incremental f and well as the temp_value. The "&" refers to a pointer.
        if(myCompare(arr[f],arr[n]) < 0) {
            myCopy(&arr[f++],&temp[temp_value]);
        }
        else {
            myCopy(&arr[n++],&temp[temp_value]);
// if arr[f] and arr[n] are equal to each other, it will copy incremental n values as well as the temp_value
//wil 
        }
        temp_value++;
    }

    while(f < m+1) {// if elements are the first half values of array
        myCopy(&arr[f++],&temp[temp_value++]);
    }
    while(n < l+1) {//if elements are second half of array
        myCopy(&arr[n++],&temp[temp_value++]);
    }
	
	int i; 
	int a;

    for (i=0, a=first; a <= l; i++, a++) {
        mySwap(&arr[a],&temp[i]);
    }
}

void mySort(int array[], unsigned int first,unsigned int last)
{ 

    if(first < last)
    {
       int middle = (first + last)/2;
       mySort(array,first,middle);
	   mySort(array,middle+1,last);
	   merge(array,first, middle, last);
    }
}

