#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int colour[100] = {0};
int queue[1000];
int tail = 0;
int head= 0;
int N,E,s;
int isempty()
 {
 if(tail == head) return 1;
 else return 0;
 }
void enqueue(int key)
 {
 queue[tail] = key;
 tail++;
 }
int dequeue()
 {
 int key = queue[head];
 head++;
 return key;
 }

void bfs(int graph[][N])
{
 int v;
 enqueue(s);
 colour[s] = 1;
 printf("%d",s);
 while(!isempty())
  {
  int u = dequeue();
  for(v=0;v<N;v++)
   {
    if(graph[u][v] == 1 && colour[v] == 0)
    {
     enqueue(v);
     colour[v] = 1;
     printf(" %d",v);
    }
   }
  colour[u] = 2;
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
 int graph[N][N];
 memset(graph,0,sizeof(graph));
 fscanf(fp,"%d",&E);
 int i = 0;
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
  bfs(graph);
  printf("\n");
return 0;
}
