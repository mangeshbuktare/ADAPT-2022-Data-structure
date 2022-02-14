#include<stdio.h>
#include<stdlib.h>

void selection_sort(int a[], int n)
{
   int i,j;
   int pos;
   int small;
   int temp;
     for(i=0;i<n-1;i++)
  {
      small = a[i];
      pos = i;
      for(j=i+1;j<n;j++)
     {
          if(a[j]<small)
          {
             small = a[j];
             pos = j;
          }

     }        
    //swapping a[iI] and a[pop]
      temp  =a[pos];
      a[pos]=  a[i];
      a[i]  =  temp; 
  }
}
    int main()
    {
     int i, n, a[20];
       printf("\nenter the no of elements to sort:");
       scanf("%d", &n);
     
     printf("\nEnter the array elements:");
     for(i=0;i<n;i++)
       scanf("%d", &a[i]);
       selection_sort(a,n);       
       printf("The sorted elements are:\n");
       for(i=0;i<n;i++)
       printf("%d\t", a[i]);
    }     
