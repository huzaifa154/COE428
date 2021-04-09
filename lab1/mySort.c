void mySort(int d[], unsigned int n)
{  
    int i, key, j;  /* instance variables*/
    for (j = 1; j < n; j++) 
    {  
        key = d[j];  
        i = j - 1;  
  
        /* for d[0..j-1], if element is greater than key, it will switch positions with the element infront  */
        while (i >=0 && d[i] > key) 
        { 
            d[i + 1] = d[i];  
            i = i - 1;  
        }  
        d[i + 1] = key;  
    }  
}  
