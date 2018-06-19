#include<stdio.h>
#include<string.h>
#include<time.h>

int main()
 {
  FILE *fp;
  clock_t start,stop;
  double runtime;
  char key[20],temp[20];
  int i,j,n,k;
  start=clock();
  fp=fopen("sort.txt","r");
  
  if(fp==NULL)
    printf("cannot open file\n");
  else
  
  fscanf(fp,"%d",&n);
  char a[n][20];
  for(i=0;i<n;i++)
   {
    fscanf(fp,"%s",a[i]);
   }
  printf("\nrecieved input from file to be lexicographical selection sorted:\n");
  for(i=0;i<n;i++)
   {
    printf("%s\n",a[i]);
   }
  for(i=0;i<n-1;i++)
   {
    strcpy(key,a[i]);
    k=i;
    for(j=i+1;j<n;j++)
     {
      if(strcmp(key,a[j])>0) /*greater than zero,then str2 is alphabetically above str1*/
	{
         strcpy(key,a[j]);
 	 k=j;
	}
     }  
    if(i!=k)
     {
      strcpy(temp,a[i]);
      strcpy(a[i],a[k]);
      strcpy(a[k],temp);
     }
   }
  printf("\nlexicographical selection sorted output is:\n");
  for(i=0;i<n;i++)
  {
   printf("%s\n",a[i]);
  }
  fclose(fp);
  stop=clock();
  runtime=(double)(stop-start)/CLOCKS_PER_SEC;
  printf("Running time: %f sec\n",runtime);
  fp=fopen("sort.txt","w");
  for(i=0;i<n;i++)
   {
    fprintf(fp,"%s\n",a[i]);
   }
  fprintf(fp,"Running time: %lf sec",runtime);
  fclose(fp);
 }
