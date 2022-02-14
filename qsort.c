#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}
int main()
{
   int i;
   int int_array[] = {99,66,10,21,250};
   printf("\nArray Before Sorting:");
   for(i=0;i<5;i++)
      printf("%d\t", int_array[i]);
      qsort(int_array,5,sizeof(int),cmpfunc);
      
   printf("\nArray After Sorting:");
   for(i=0;i<5;i++)
      printf("%d\t", int_array[i]);
}      
