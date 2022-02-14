#include<stdio.h>

int binary_search(int item, int n, int a[])
{
    int low;
    int high;
    int mid;
  
    for(low=0,high=n-1;low<=high;)
    {
        mid =(low+high)/2;
        if(item == a[mid]) 
        return mid+1;
        else if(item<a[mid])
            high =mid-1;
        else
            low = mid+1;    
    }
    return 0;
}
int main()
{
    int i,n,key,position,a[20];
    
    printf("Enter the no of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter the key element to be searched\n");
    scanf("%d", &key);
    printf("Enter the array values:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    position = binary_search(key,n,a);
    if (position == 0)
        printf("search uncessful\n");
    else 
        printf("key element - %d found at location %d\n", key,position);
}
            
    
