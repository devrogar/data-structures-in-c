#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000000
typedef struct node{
 int p;
 int d;
 }node;
int N,E,s;


int pq(node *v[N])
 {
 int i=0,ver=-1,temp=10000000;
 while(i<N)
  {
   if(temp>v[i]->d)
    {
     if(v[i]->p==0)
      {
        temp=v[i]->d;
        ver=i;
      }
    }
    i++;
  }
 if(ver==-1)
 {
  int j=0;
  while(j<N)
    {
     printf("%d ",v[j]->d);
     j++;
    }
    exit(0);
 }
 v[ver]->p=1;
 return ver;
 }

void relax(int graph[][N],node *v[N],int u,int j)
 {
  if(v[j]->d > (graph[u][j]+v[u]->d))
    {
     v[j]->d=graph[u][j]+v[u]->d;
    }
 }
 
int dijkstras(int graph[][N],node *v[N],int s)
 {
  int i,j;
  int u;
  i=0;
  while(i<N)
   {
    u=pq(v);
    j=0;
    while(j<N)
     {
      if(graph[u][j]!=0)
       {
        relax(graph,v,u,j);
       }
       j++;
     }
     i++;
   }
 }
 
int main()
 {
  FILE *fp;
  fp=fopen("s.txt","r");
  if(fp==NULL)
   printf("cannot open file\n");
  else
   
   fscanf(fp,"%d",&N);
   int S[N];
   memset(S,0,sizeof(S));
   int graph[N][N];
   memset(graph,0,sizeof(graph));
   fscanf(fp,"%d",&E);
   int i=0;
   while(i<E)
     {
      int u,v,cost;
      fscanf(fp,"%d%d%d",&u,&v,&cost);
      graph[u][v]=cost;
      graph[v][u]=cost;
      i++;
     }
   printf("Enter source vertex: ");
   scanf("%d",&s);
   node *v[N];
   i=0;
   while(i<N)
    {
     if(i!=s)
      {
       v[i]->d=max;
       v[i]->p=0;
      }
      else
       {
        v[i]->d=0;
       }
       i++;
    }
   dijkstras(graph,v,s);
 }
