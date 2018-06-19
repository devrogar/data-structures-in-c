#include<stdio.h>
#include<time.h>

int main()
 {
  FILE *fp;
  int i,n,key,v=-1;
  double runtime;
  clock_t start,stop;
  start=clock();
  fp=fopen("search.txt","r");
  if(fp==NULL)
    printf("cannot open file\n");
  else
  
  fscanf(fp,"%d",&n);
  int temp[n];
  for(i=0;i<n;i++)
   {
    fscanf(fp,"%d",&temp[i]);
   }
  fscanf(fp,"%d",&key);
  printf("number to be searched given from file is: %d\n",key);
  binary_search(&temp,0,n-1,key,&v);
  printf("\n");
  fclose(fp);
  stop=clock();
  runtime=(double)(stop-start)/CLOCKS_PER_SEC;
  printf("Running time: %f sec\n",runtime);
  fp=fopen("search.txt","w");
  for(i=0;i<n;i++)
   {
    fprintf(fp,"%d\n",temp[i]);
   }
  fprintf(fp,"searched number found at index: %d",v);
 }
 
 int binary_search(int *p,int i,int j,int key,int *v)
  {
   int mid;
   mid=(i+j)/2;

      if(key==p[mid])
        {(*v)=mid;
        printf("found at index: %d",mid);}
      else if(i<j)
     {
      if(key<p[mid])
        binary_search(&*p,i,mid-1,key,&*v);

      if(key>p[mid])
        binary_search(&*p,mid+1,j,key,&*v);
     }
    else
     printf("found at index: -1");
  }
