#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
       int info;
       struct node *link;
};
typedef struct node* NODE;

NODE insert_front(int item, NODE first)
{
       NODE newnode;
       newnode = (NODE)malloc(sizeof(struct node));
       if(newnode == NULL)
       {
            printf("out of memory\n");
            exit(1);
       }
       newnode->info=item;
       newnode->link=first;
       return newnode;
}

NODE delete_front(NODE first)
{
       NODE temp;
       if(first == NULL)
       {
           printf("\nList empty");
           return first;
       }
       temp = first;
       first = first->link;
       printf("The item deleted is:%d\n", temp->info);
       free(temp);
       return first;
}
int display(NODE first)
{        
       NODE temp;
       if(first == NULL)
       { 
            printf("\nList empty");
            return 0;
       }
       printf("\nThe Contents of the linked list are:\n");
       temp=first;
       while(temp!=NULL)
       {
            printf("%d\t",temp->info);
            temp=temp->link;
       }
       return 0;
}

int main()
{
       NODE first = NULL;
       int input, item;
       for(;;)
       { 
             printf("\n1 to insert front");
             printf("\n2 to delete front ");
             printf("\n3 to display the list of contents");
             printf("\n4 to exit");
             printf("\n Enter the input choice");
             scanf("%d", &input);
          switch(input)
          {
            case 1 : printf("\n Enter the item to be inserted:");
                     scanf("%d", &item);
                     first = insert_front(item,first);
                     display(first);
                     break;
            case 2 : first = delete_front(first);
                     display(first);
                     break;
            case 3 : display(first);
                     break;       
            case 4 : exit(0);
            default:printf("\nincorrect choice");
            continue;
          }
       }
}                                
        
       
       
       
       
       
       
       
        
