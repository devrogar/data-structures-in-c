#include<stdio.h>
#include<stdlib.h>
int max,head=-1,tail=-1;
int enqueue();
int dequeue();
int peek();
int show();
int main()
{
printf("enter QUEUE capacity: ");
scanf("%d",&max);
int a[max];
queue_op(&a);
}

int queue_op(int *a)
{
int p;
int k;
printf("Enter QUEUE operation\n//type 0 to exit//\n");
scanf("%d",&p);
if(p==1 && tail<max-1)
  {
   printf("enter element: ");
   scanf("%d",&k);
   enqueue(&*a,k);
   queue_op(&*a);
  }
else
  {
   if(p==1 && tail>=max-1)
     {
      printf("OVERFLOW\n");
      queue_op(&*a);
     }
  }
if(p==2 && head!=tail)
  {
   dequeue(&*a);
   queue_op(&*a);
  }
else
  {
   if(p==2 && head==tail && head!=max)
    {
     printf("EMPTY\n");
     queue_op(&*a);
    }
   else
    {
     head=-1;
     tail=-1;
    }
  }
if(p==3 && head!=tail)
  {
   peek(&*a);
   queue_op(&*a);
  }
else
 {
  if(p==3 && head==tail)
    {
     printf("EMPTY\n");
     queue_op(&*a);
    }
 }
if(p==4 && head!=tail)
  {
   show(&*a);
   queue_op(&*a);
  }
else
 {
  if(p==4 && head==tail)
    {
     printf("EMPTY\n");
     queue_op(&*a);
    }
 }
if(p==0)
  {
   exit(0);
  }
if(p>4)
  {
   queue_op(&*a);
  }
}

int enqueue(int *a,int k)
{
 if(tail==-1 && head==-1)
   {
    a[tail+1]=k;
    head++;
    tail++;
   }
 else
   {
    if(tail>-1 && tail<max)
      {
       scanf("%d",&a[tail+1]);
       tail++;
      }
   }
return;
}

int dequeue(int *a)
{
    printf("%d",a[head]);
    head++;
    return;
}

int peek(int *a)
{
  printf("%d",a[head]);
  return;
}

int show(int *a)
{
 int i;
 for(i=head;i<=tail;i++)
  {
   printf("%d ",a[i]);
  }
 return;
}
