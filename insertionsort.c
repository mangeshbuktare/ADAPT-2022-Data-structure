#include<stdio.h>

void insertion_sort(int a[], int n)
{
  int i, j, item;
  
  for(i=0;i<n;i++)
  {
    item=a[i];
    j=i-1;
    
    while(j>=0 && item < a[j])
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = item;
  }
}     
int main()
{
  int i, n, a[20];
  printf("\nEnter the number of elements to sort:");
  scanf("%d", &n);
  
  printf("\nEnter the array elements");
  for(i=0;i<n;i++)
       scanf("%d", &a[i]);
       insertion_sort(a,n);
       printf("The sorted elements are:");
       for(i=0;i<n;i++)
       printf("%d\t", a[i]);
}        
