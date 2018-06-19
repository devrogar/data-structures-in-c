#include<stdio.h>
#include<time.h>

int main()
  {
   FILE *fp;
   int i,m,n,j=0,key;
   clock_t start,stop;
   double runtime;
   start=clock();
   fp=fopen("search.txt","r+");
   if(fp==NULL)
     printf("Cannot open file\n");
   else
     
   fscanf(fp,"%d",&n);
   int temp[n];
   for(i=0;i<n;i++)
     {
      fscanf(fp,"%d",&temp[i]);
     }
   fscanf(fp,"%d",&key);
   printf("Number to be searched given from file is: %d\n",key);
   printf("Found at index: ");
   for(i=0;i<n;i++)
    {
     if(key==temp[i])
       {printf(" %d",i);
        m=i;}
     else
      j++;
    }
   if(j==n)
    printf("-1\n");
   else
    printf("\n");
   
   fclose(fp);
   stop=clock();
   runtime=(double)(stop-start)/CLOCKS_PER_SEC;
   printf("Running time: %f\n",runtime);
   fp=fopen("search.txt","w");
   for(i=0;i<n;i++)
    {
     fprintf(fp,"%d\n",temp[i]);
    }
   if(j==n)
   fprintf(fp,"searched number found at index: -1");
   else
   fprintf(fp,"searched number %d found at index: %d",key,m);
   
  fclose(fp);
  }
