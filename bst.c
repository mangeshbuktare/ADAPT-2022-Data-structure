#include<stdio.h>
#include<stdlib.h>

struct node
{
   int info;
   struct node *llink;
   struct node *rlink;
};

typedef struct node* NODE;

NODE insert(int item, NODE root)
{
   NODE temp, cur, prev;
   temp = (NODE) malloc(sizeof(struct node)); /* obtain a node */
   temp->info = item;
   temp->llink= NULL;
   temp->rlink= NULL;
   
   if(root == NULL) return temp;
   //find position to be inserted
   
   prev = NULL;
   cur  = root;
   while(cur!= NULL)
   {
         prev = cur;
         cur  = (item < cur -> info) ? cur->llink : cur->rlink;
   }
   if(item<prev->info)
      prev->llink = temp;
   else
      prev->rlink=temp;
   return root;
}

NODE search(int item, NODE root)
{
   if(root == NULL || item ==root->info) return root;
   
   if(item<root->info)
      return(search(item,root->llink));
      return(search(item,root->rlink));
}
int main()
{
   NODE root = NULL;
   int choice, item, flag;
   
   for(;;)
   {
         printf("1: Insert\n");
         printf("2: search\n");
         printf("3: Exit\n");
         printf("Enter the choice");
         
         scanf("%d", &choice);
         switch(choice)
         {
             case 1: printf("Enter the item to be inserted\n");
                     scanf("%d", &item);
                     root = insert(item,root);
                     break;
             case 2: if(root == NULL)
                         printf("Tree is empty\n");
                     else
                     {
                         printf("Enter the item to be searched:\n");
                         scanf("%d", &item);
                         root = search(item,root);
                     if(root == NULL)
                         printf("\nsearch uncessfull");
                     else    
                         printf("\nsearch sucessfull");
                         printf("\n");
                     }
                     break;
             case 3: exit(0);
             default:printf("\ninvalid choice");
             continue;
        }
   }                           
}   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
