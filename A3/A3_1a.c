#include<stdio.h>
#include<stdlib.h>
#define max 100
int a[max],top=-1;
void push();
void pop();
void peek();
void show();
void main()
 {
  int p;
  int x;
  printf("\nenter the stack operation:\n //type 0 to exit//\n");
  scanf("%d",&p);
    
  if(p==1 && top<max-1)
   {
    push();
    main();
   }
  else
   {
	   if(p==1 && top>=max-1)
	   {
		   printf("stack overflow\n");
		   main();
	   }
   }
  if(p==2 && top>-1)
   {
    pop();
    main();
   }
  else
   {
    if(p==2 && top==-1)
      {
       printf("EMPTY\n");
       main();
      }
   }
  if(p==4 && top>-1)
   {
    show();
    main();
   }
  else
   {
    if(p==4 && top==-1)
      {
       printf("EMPTY\n");
       main();
      }
   }
  if(p==3 && top>-1)
  {
   peek();
   main();
  }
 else
   {
    if(p==3 && top==-1)
      {
       printf("EMPTY\n");
       main();
      }
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

void push()
  {
  if(top==-1)
   {
   scanf("%d",&a[top+1]);
   top++;
   }
  else
   {
    if(top>-1 && top<max)
      {
       scanf("%d",&a[top+1]);
       top++;
      }
   }
   return;
  }
void pop()
  {
  printf("%d",a[top]);
  top--;
  return;
  }
void peek()
{
 printf("%d",a[top]);
 return;
}
void show()
  {
   int i;
   if(top<0)
   {
	   printf("EMPTY\n");
   }
   else
   {
   for(i=top;i>=0;i--)
     {
      printf("%d ",a[i]);
     }
   }
   return;
  }	
