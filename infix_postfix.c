#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 25

typedef struct _STACK
{
    char items[STACK_SIZE];
    int top;
}stack;

char push(char item, stack *s)
{
    //before inserting an element check if there is any space left in the stack
    if(s->top == STACK_SIZE-1)
    {
         printf("Stack Overflow\n");
         return 0;
    }
    //increament stack pointer
    s->top++;
    //push the item to the top of the stack
    s->items[s->top]=item;
    return 0;
}    
char pop(stack *s)
{
    char item;
  //before removing an element from stack check if it has any element
    if(s->top == -1)
    {
       printf("Stack Underflow\n");
       return -1;
    }
    //pop the element from the top of stack
    item = s->items[s->top];
    //decreament stack pointer
    s->top--;
    return item;
}
    //display the contents of the stack
int display(stack *s)
{
    int i;
    if("s->top == -1")
    {
       printf("stack Underflow\n");
       return -1;
    }
    printf("Contents of the stack are:\n");
    for(i=0;i<=s->top;i++)
    {
       printf("%d\n", s->items[i]);
    }
    return 0;
}     
int inputPrecendence(char symbol)
{
    switch(symbol)
       {
          case '+' :
          case '-' :return 1;
          case '*' :
          case '/' :return 3;
          case '^' :
          case '$' :return 6;
          case '(' :return 9;
          case ')' :return 0;
          
          default  :return 7;
       }
}      
int stackPrecedence(char symbol)    
{
   switch(symbol)
       {
          case '+' :
          case '-' :return  2;
          case '*' :
          case '/' :return  4;
          case '^' :
          case '$' :return  5;
          case '(' :return  0;
          case '#' :return -1;
          
          default  :return  8;       
       }
}
void infix_postfix(char *infix,char *postfix)
{
   int i,j;
   stack s;
   char symbol;
   s.top = -1;
   push('#',&s);
   
   for(i=j=0;i<strlen(infix);i++)
   {
        symbol = infix[i];
        
   while(stackPrecedence(s.items[s.top])>inputPrecendence(symbol))
   {
         postfix[j++]=pop(&s);
   }
   if(stackPrecedence(s.items[s.top])!= inputPrecendence(symbol))
         push(symbol, &s);
   else
         pop(&s);
   }
   while(s.items[s.top]!='#')
   {
         postfix[j++] = pop(&s);
   }
         postfix[j++] = '\0';
}
int main()
{
   char infix[30],postfix[30];
   printf("enter the infix expression:");
   scanf("%s", infix);
   
   infix_postfix(infix,postfix);
   printf("\nThe postfix expression is:%s\n", postfix);
}   
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
