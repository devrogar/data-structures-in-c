#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
int data;
struct Node *next;
}node;
void push(node *ptr,int data)
{
  while(ptr->next!=NULL)
   {
    ptr=ptr->next;
   }
  ptr->next=(node *)malloc(sizeof(node));
  ptr=ptr->next;
  ptr->data=data;
  ptr->next=NULL;
}
void pop(node *ptr)
{
  if(ptr==NULL)
  {
   printf("EMPTY\n");
   return;
  }
 else
  {
   while((ptr->next)->next!=NULL)
     {
      1;
     }
   printf("%d",(ptr->next)->data);
   free(ptr->next);
  }
}
void peek(node *ptr)
{
 if(ptr==NULL)
  {
   printf("EMPTY\n");
   return;
  }
 else
  {
   while(ptr->next!=NULL)
     {
      1;
     }
   printf("%d",ptr->data);
  }
}
void show(node *ptr)
{
if(ptr==NULL)
  {
   printf("EMPTY\n");
   return;
  }
else
  {
   printf("%d ",ptr->data);
   show(ptr->next);
  }
}
int main()
{
 int p,data;
 node *head;
 head=(node *)malloc(sizeof(node));
 head->next=NULL;
 printf("enter the stack operation:\n//type 0 to exit//\n");
 scanf("%d",&p);
 if(p==1)
   {
    scanf("%d",&data);
    push(head,data);
    main();
   }
  
  if(p==2)
   {
    pop(head->next);
    main();
   }
  if(p==3)
   {
    peek(head->next);
    main();
   }
  if(p==4)
  {
   show(head->next);
   main();
  }

  if(p==0)
   {
    exit(0);
   }
  if(p>4)
   {
    main();
   }
}
