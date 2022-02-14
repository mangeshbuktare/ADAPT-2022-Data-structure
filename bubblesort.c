#include<stdio.h>

void bubble_sort(int a[], int n)
{
   int i,j;
   int temp;
   for(j=1;j<n;j++)
     {
        for(i=0;i<n-1;i++)
           {
              if(a[i]>=a[i+1])
                     {
                       temp= a[i];
                       a[i]= a[i+1];
                       a[i+1]= temp;
                     }
           }
     }
}

   int main()
   {
     int i, n, a[20];
       printf("\nenter the no of elements to sort:\n");
       scanf("%d", &n);
     
       printf("\nEnter the array elements:\n");
     for(i=0;i<n;i++)
       scanf("%d", &a[i]);
       bubble_sort(a,n);
       printf("\nThe sorted elements are:\n");
     for(i=0;i<n;i++)
       printf("%d\t", a[i]);
   }     
