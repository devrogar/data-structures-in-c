#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
int data;
struct Node *next;
struct Node *prev;
}node;
void insert(node *ptr, int data)
{
 while(ptr->next!=NULL)
   {
    ptr=ptr->next;
   }
 ptr->next=(node *)malloc(sizeof(node));
 (ptr->next)->prev=ptr;
 ptr=ptr->next;
 ptr->data=data;
 ptr->next=NULL;
}

void delete(node *ptr)
{
 if(ptr==NULL)
  {
   return;
  }
 else
  {
   ptr->next=(ptr->next)->next;
   (ptr->next)->prev=ptr;
   free(ptr->next);
  }
 delete(ptr->next);
}

void show(node *ptr)
{
 if(ptr==NULL)
   {
    return; 
   }
 printf("%d ",ptr->data);
 show(ptr->next);
}

int main()
{
 int n,i;
 node *head,*temp;
 head=(node *)malloc(sizeof(node));
 temp=head;
 temp->next=NULL;
 temp->prev=NULL;
 FILE *fp;
 fp=fopen("input.txt","r+");
 if(fp==NULL)
  printf("cannot open file\n");
 else
 
  fscanf(fp,"%d",&n);
  for(i=0;i<n;i++)
   {
    int data;
    fscanf(fp,"%d",&data);
    insert(head,data);
   }
  printf("file input as doubly liked list: ");
  show(head->next);
  printf("\n");
  delete(head->next);
  printf("after deleting alternate nodes from doubly linked list: ");
  show(head->next);
  printf("\n");
}
