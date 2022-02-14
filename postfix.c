#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define STACK_SIZE 10

typedef struct _stack
{
        int top;
        double items[STACK_SIZE];
}stack;

int push(double item, stack *s)
{
        if(s->top == STACK_SIZE-1)
    {
        printf("Stack Overflow\n");
        return 0;
    }
        s->top++;
        s->items[s->top] = item;
        return 0;
}
double pop(stack *s)
{
       double item;
       if(s->top == -1)
       {
             printf("stack underfow\n");
             return item;
       }
       
       item = s->items[s->top];
       s->top--;
       return item;
}
double op(char symbol,double op1, double op2)
{
       switch(symbol)
       {     
             case '+' : return      op1 + op2;
             case '-' : return      op1 - op2;
             case '*' : return      op1 * op2;
             case '/' : return      op1 / op2;
             case '^' : return pow(op1 , op2);
             default : printf("Invalid operator"); 
             exit(0);
       }      
}
int isdigit(char symbol)
{
       return(symbol >= '0' && symbol <= '9');
}
int main()
{      int i;
       double result, op1, op2;
       char symbol,postfix[20];
       stack s;
       s.top=-1;
       
       printf("Enter the postfix expresion:");
       scanf("%s", postfix);
       
       for(i=0;i<strlen(postfix);i++)
       {
             symbol = postfix[i];
             if(isdigit(symbol))
              {
                 push(symbol-'0',&s);
              }
             else
               {
                 op2 = pop(&s);
                 op1 = pop(&s);
                 result = op(symbol,op1,op2);
                 push(result,&s);
               }
              
       }      
        result = pop(&s);
        printf("The final result of the potfix expression is %f\n",result);
        return 0;
}
