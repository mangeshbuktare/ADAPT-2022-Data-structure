#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

struct queue
{
       int items[QUEUE_SIZE];
       int front;
       int rear;
};
typedef struct queue QUEUE;




int insert_rear(int item,QUEUE *q)
{
      if(q->rear == QUEUE_SIZE-1)
      {
            printf("\nQueue full, insertion at rear end not possible");
            return 0;
      }
      (q->rear)++;
             q->items[q->rear]=item;
             return 0;
}




int delete_front(QUEUE *q)
{
      if(q->front > q->rear)
      {     printf("\nQueue is empty, deletion is not possible");
            return 0;
      }
          printf("The element deleted is %d\n", q->items[q->front]);
          (q->front)++;
      if(q->front > q->rear)
      {
            q->front = 0;
            q->rear  =-1;
      } 
    return 0;  
}




int insert_front(int item, QUEUE *q)
{
      if(q->front == 0 && q->rear == -1)
           //increament rear and then insert item
           q->items[++(q->rear)] = item;
      else if(q->front!=0)
           q->items[--(q->front)] = item;
      else
          printf("\nInsertion at the front end not possible");
          return 0;    
}



int delete_rear(QUEUE *q)
{
      if(q->front > q->rear)
      {
  printf("\nQueue is empty, deletion at a rear end is not possible");
            return 0;
      }
            printf("The deleted element is %d\n", q->items[q->rear]);
            (q->rear)--;
      if(q->front > q->rear)
      {
      q->front = 0;
      q->rear = -1;
      }
      return 0;
}




int display(QUEUE *q)
{
      int i;
      if(q->front > q->rear)
      {
           printf("\nQueue is empty, cannot display the contents");
           return 0;
      }
           printf("\nThe Queue contents are:\n");
        for(i=q->front;i<=q->rear;i++)
           printf("%d\t",q->items[i]); 
           return 0;                    
}




int main()
{
      QUEUE q;
      q.front=0;
      q.rear=-1;
      int input,item;
       for(;;)
      {
        printf("\n1 to insert rear\n");
        printf("\n2 to delete front");
        printf("\n3 to insert front");
        printf("\n4 to delete rear");
        printf("\n5 to display the contents of the queue");           
        printf("\n6 Exit");
        printf("\nenter the choice");
        scanf("%d", &input);
      switch(input)
        {  
          case 1 : printf("\nEnter the item to be inserted:");
                   scanf("%d", &item);
                   insert_rear(item,&q);
                   display(&q);
                   break;        
          case 2 : delete_front(&q);
                   display(&q);
                   break;
          case 3 : printf("\nEnter the item to be inserted:");
                   scanf("%d", &item);
                   insert_front(item,&q);
                   display(&q);
                   break;        
          case 4 : delete_rear(&q);
                   display(&q);
                   break; 
          case 5 : display(&q);
                   break;
          case 6 : exit(0);
          default:printf("\nInvalid Choice");
          continue;
        }
      }   
}      
      
      
