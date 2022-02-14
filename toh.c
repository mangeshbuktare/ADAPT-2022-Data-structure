#include<stdio.h>

int count=0;

int towerofhanoi(int n, char source, char temp, char destination)
{
  if(n == 1)
    {
      printf("move disk-1 from %c to %c\n", source, destination);
      count++;
      return 0;
    }
  towerofhanoi(n-1,source,destination,temp);
  printf("move disc %d from %c to %c\n", n,source,destination);
  count++;
  
  towerofhanoi(n-1,temp,source,destination);
  return 0;
}
int main()
{
  int n;
  printf("enter no of discs:");
  scanf("%d", &n);
  towerofhanoi(n,'A', 'B', 'C');
  printf("Total moves are:%d\n", count);
}  
