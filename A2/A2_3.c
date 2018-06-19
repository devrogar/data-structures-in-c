#include<stdio.h>
#include<time.h>

int main()
 {
  FILE *fp;
  clock_t start,stop;
  double runtime;
  int i,j,n;
  start=clock();
  fp=fopen("sort.txt","r");
  if(fp==NULL)
    printf("cannot open file\n");
  else
  
  fscanf(fp,"%d",&n);
  float a[n],key;
  for(i=0;i<n;i++)
   {
    fscanf(fp,"%f",&a[i]);
   }
  printf("elements given as input from file are:\n");
  for(i=0;i<n;i++)
   {
    printf("%f\n",a[i]);
   } 
  printf("\n");
  
  for(j=1;j<n;j++)
   {
    i=j-1;
    key=a[j];
    while(i>=0 && key<a[i])
      {
         a[i+1]=a[i];
         i--;
      }
    a[i+1]=key;
   }
 printf("after implementing the insertion sort:\n"); 
 for(i=0;i<n;i++)
   {
    printf("%f\n",a[i]);
   }
 fclose(fp);
 stop=clock();
 runtime=(double)(stop-start)/CLOCKS_PER_SEC;
 printf("Running time: %f\n",runtime);
 fp=fopen("sort.txt","w");
 for(i=0;i<n;i++)
  {
   fprintf(fp,"%f\n",a[i]);
  }
 fprintf(fp,"Running time: %f sec.",runtime);
 fclose(fp);
 }

