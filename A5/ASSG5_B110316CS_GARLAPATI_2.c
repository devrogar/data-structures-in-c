#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int colour[100] = {0};
int N,E,s;

void dfs(int graph[][N],int u)
 {
  colour[u]=1;
  printf("%d ",u);
  int v=0;
  while(v<N)
   {
    if(graph[u][v]==1 && colour[v]==0)
      {
       dfs(graph,v);
      }
      v++;
   }
   colour[u]=2;
  return;
 }

int main()
{
 FILE *fp;
 fp=fopen("s.txt","r");
 if(fp==NULL)
   printf("cannot open file\n");
 else
   
 fscanf(fp,"%d",&N);
 int graph[N][N];
 memset(graph,0,sizeof(graph));
 fscanf(fp,"%d",&E);
 int i=0;
 while(i<E)
  {
  int u,v,cost;
  fscanf(fp,"%d %d %d",&u,&v,&cost);
  graph[u][v] = 1;
  graph[v][u] = 1;
  i++;
  }
  printf("Enter source vertex: ");
  scanf("%d",&s);
  dfs(graph,s);
  printf("\n");
return 0;
}
