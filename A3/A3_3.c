#include<stdio.h>
#include <stdlib.h>
struct pq{
   int data;
   int pr;	
  }a[50];
int n;
int length=0;

int left(int a)
{
 return 2*a;
}

int right(int a)
{
 return (2*a+1);
}

int exchange(int *a, int *b)
  {
   int temp=0;
   temp=*a;
   *a=*b;
   *b=temp;
  }

int max_heapify(struct pq a[], int i)
{
 int l,r,p,largest;
 l = left(i);
 r = right(i);
 largest=i;
 if(l<=n && a[l].pr>a[largest].pr)
	 largest=l;
		
 if(r<=n && a[r].pr>a[largest].pr)
	 largest=r;
			
 if(largest!=i)
  {
   exchange(&a[i].pr,&a[largest].pr);
   exchange(&a[i].data,&a[largest].data);
   max_heapify(a,largest);
  }
}	


int build_heap(struct pq a[])
 {
  int i;
  n=length-1;
  for(i=length/2;i>=0;i--)
     max_heapify(a,i);
 }

void bsh(struct pq a[])
 {
  int i;
  build_heap(a);
  for(i=length-1; i>=0; i--)
    {
     exchange(&a[0].pr,&a[i].pr);
     exchange(&a[0].data,&a[i].data);
     n -= 1;
     max_heapify(a,0);
    }
 }

void insert(struct pq a[],struct pq p)
  {
   int i;	
   a[length].data=p.data;
   a[length].pr=p.pr;
   length=length+1;
   bsh(a);
  }

struct pq del(struct pq a[])
 {	
  struct pq temp;
  int  i;
  if(length!=0)
    {
     temp.data=a[0].data;	
     temp.pr=a[0].pr;
     for(i=0;i<length-1;i++)
	a[i]=a[i+1];
	bsh(a);
	length--;
	return temp;
    }
   else 
     {
      temp.data=-1;
      temp.pr=-1;
      printf("EMPTY\n");
      return temp;
     }
 }

int peek(struct pq a[])
 {
  if(length!=0)
    return (a[0].data);
  else
    {
     printf("EMPTY\n");
     return -1;
    }
 }

void inc_priority(struct pq a[],int p,int np)
 {
  int i;	
  for(i=0;i<length;i++)
   {
    if(a[i].data==p)
      a[i].pr=np;
   }
  bsh(a);
 }

int main(int c, char *v[])
{
 FILE *fp;
 int i,temp,p,tempdata,ins,pri,temp2;
 struct pq  elem,temp1;
 fp=fopen("input.txt","r");
 if(fp==NULL)
    printf("cannot open file\n");
 else
   
   while(1)
     {
	fscanf(fp,"%d",&p);
	if(p==0)
	  exit(0);
	else
           {
	    if(p==1) 
             {
	      fscanf(fp,"%d",&ins);
	      fscanf(fp,"%d",&pri);	
	      elem.data=ins;
	      elem.pr=pri;
	      insert(a,elem);
	      printf("\n");
             }
            if(p==2)
             {
	      temp1=del(a);
	      if(temp1.data!=-1)
                {
	         printf("%d (%d)\n",temp1.data,temp1.pr);			
	        }
	     }	
	    if(p==3)
             {
	      temp2=peek(a);
	      if(temp2!=-1)
	       printf("%d (%d) \n",a[0].data,a[0].pr);
	     }
	    if(p==4)			
	     {
              fscanf(fp,"%d",&ins);
	      fscanf(fp,"%d",&pri);
	      inc_priority(a,ins,pri);
	      printf("\n");
	     }		
	   }
     }	
 return 0;
}
