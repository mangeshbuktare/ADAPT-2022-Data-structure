#include<stdlib.h>
#include<stdio.h>

#define STACK_SIZE 10

int push(int item, int *top, int s[])
{
   if(*top == STACK_SIZE-1)
   {
     printf("\nStack full");
     return 0;
   }
   //increament the stack pointer and then insert
   s[++(*top)] = item;
   return 0;
}
int pop(int *top, int s[])
{
   int item;
   if(*top == -1)
   {
     printf("\nStack Empty");
     return 0;
   }
   //pop the element and decrement the stack pointer
   item =s[(*top)--];
   return item;
}
int display(int *top, int s[]) 
{
   int i;
   if(*top == -1)
   {
     printf("\nStact Empty");
     return 0;
   }
   printf("Contents Of the stack are:\n");
   for(i=0;i<=(*top);i++)
   {
     printf("%d\n",s[i]);
   }
   return 0;
}
int main()
{
       int top;
       int s[STACK_SIZE];
       int input;
       int item;
       top = -1;
       for(;;)
       { 
             printf("\n1 Enter to push the element");
             printf("\n2 Enter to pop the element");
             printf("\n3 Enter to Display the Elements");
             printf("\n4 to exit");
             printf("\n Enter the choice");
             scanf("%d", &input);
          switch(input)
          {
            case 1 : printf("\n Enter the Element to be pushed:");
                     scanf("%d", &item);
                     push(item, &top, s);
                     display(&top, s);
                     break;
            case 2 : item = pop(&top, s);
                     if(item!=0)
                      printf("item %d is popped from the stack",item);
                     display(&top, s);
                     break;
            case 3 : display(&top, s);
                     break;       
            case 4 : exit(0);
            default:printf("\nincorrect choice");
            continue;
          }
       }
}                                     
       
