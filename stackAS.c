#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 5

typedef struct _STACK
{
   int items[STACK_SIZE];
   int top;
}stack;
   
int push(int item, stack *s)
{
   if(s->top == STACK_SIZE-1)
   {
     printf("Stack Full");
     return 0;
   }
   s->top++;
   s->items[s->top] =item;
   return 0;
}
int pop(stack *s)
{
   int item;
   if(s->top == -1)
   {
     printf("\nStack Empty");
     return 0;
   }
   //pop the element and decrement the stack pointer
   item =s->items[s->top];
   s->top--;
   return item;
}
int display(stack *s) 
{
   int i;
   if(s->top == -1)
   {
     printf("\nStact Empty");
     return 0;
   }
   printf("Contents Of the stack are:\n");
   for(i=0;i<=s->top;i++)
   {
     printf("%d\n",s->items[i]);
   }
   return 0;
}
int main()
{
       int top;
       stack s;
       int input;
       int item;
      
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
                     push(item, &s);
                     display(&s);
                     break;
            case 2 : item = pop(&s);
                     if(item!=0)
                      printf("item %d is popped from the stack",item);
                     display(&s);
                     break;
            case 3 : display(&s);
                     break;       
            case 4 : exit(0);
            default:printf("\nincorrect choice");
            continue;
          }
       }
}                                     
       
