#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

struct queue
{
     int f ;
     int r ;
     int items[QUEUE_SIZE] ;
     int count ;
};
typedef struct queue QUEUE;
  
int insert_rear(int item,QUEUE *q)
{      
       int r;     
       if(q->count == QUEUE_SIZE)
          {
           printf("\nQueue Full");
           return 0;
          }
           q->r = (q->r+1)%QUEUE_SIZE;
           q->items [q->r] = item;
           (q->count)++;
           return 0;
}
int delete_front(QUEUE *q)
{
       int f;
       if(q->count == 0)
          {
           printf("\nQueue Empty");
           return 0;
          }
           q->f = (q->f+1)%QUEUE_SIZE;
          (q->count)--;
          return 0;
}
int display(QUEUE *q)
{
     int i,j;
     if(q->count == 0)
    {
     printf("\nQueue Empty");
     return 0;
    }
     printf("Contents of the queue is:\n");
     i=q->f;
     for(j=1;j<=q->count;j++)
    {
     printf("%d\t",q->items[i]);
     i=(i+1) %QUEUE_SIZE;
    }
    return 0;
}
int main()
{
     int input,item;
     QUEUE q;
     q.f=0;
     q.r=-1;
     q.count=0;
     for(;;)
  {     
        printf("\n1 to insert rear \n");
        printf("\n2 to delete front ");
        printf("\n3 to display the contents of the queue");
        printf("\n4 to exit");
        printf("\nenter the choice:");
        scanf("%d", &input);
        switch(input)
        
     {
        case 1 : printf("\n Enter the item to be inserted:");
                 scanf("%d",&item);
                 insert_rear(item,&q);
                 display(&q);
                 break;
       case 2 :  delete_front(&q);
                 display(&q);
                 break;
       case 3 :  display(&q);
                 break;
       case 4 :  exit(0);
       default : printf("\ninvalid choice");
       continue;
     }
  }
}              
                
