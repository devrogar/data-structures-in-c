#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
 int data;
 struct Node *next;
}node;
int c=0;
void insert(node *ptr, int data);
void show(node *ptr)
{
 if(ptr==NULL)
  {
   return;
  }
 else
  {
   printf("%d ",ptr->data);
   if(ptr->data > 10)
     {
      c++;
     }
   show(ptr->next);
  }
}
int main()
 {
  int n,i;
  node *head;
  head=(node *)malloc(sizeof(node));
  head->next=NULL;
  
  FILE *fp;
  fp=fopen("input.txt","r+");
  if(fp==NULL)
    printf("cannot open file\n");
  else
   
   fscanf(fp,"%d",&n);
   printf("total no. of nodes from file is: %d\n",n);
   
   for(i=0;i<n;i++)
    {
     int data;
     fscanf(fp,"%d",&data);
     insert(head,data);
    }
   fclose(fp);
   printf("file input in singly linked list: ");
   show(head->next);
   printf("\nno. of nodes with key > 10 :%d\n",c);
   
 }

void insert(node *ptr, int data)
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
