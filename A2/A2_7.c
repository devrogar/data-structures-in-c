#include<stdio.h>
#include<time.h>

int main()
 {
  FILE *fp;
  clock_t start,stop;
  int i,j,n;
  double runtime;
  start=clock();
  fp=fopen("sort.txt","r");
  if(fp==NULL)
    printf("cannot open file\n");
  else
   
  fscanf(fp,"%d",&n);
  int a[n];
  for(i=0;i<n;i++)
   {
    fscanf(fp,"%d",&a[i]);
   }
  merge_sort(&a,0,n-1);
  printf("after merge sort:\n");
  for(i=0;i<n;i++)
    {
     printf("%d\n",a[i]);
    }
  fclose(fp);
  stop=clock();
  runtime=(double)(stop-start)/CLOCKS_PER_SEC;
  printf("Running time: %f sec\n",runtime);
  fp=fopen("sort.txt","w");
  for(i=0;i<n;i++)
   {
    fprintf(fp,"%d\n",a[i]);
   }
  fprintf(fp,"Running time: %lf sec.",runtime);
  fclose(fp);
 }

int merge_sort(int *A,int p,int r)
  {
   int mid;
   if(p<r)
    {
     mid=(p+r)/2;
     merge_sort(&*A,p,mid);
     merge_sort(&*A,mid+1,r);
     merge(&*A,p,mid,r);
    }
  }

int merge(int *A,int p,int q,int r) /*not using sentinels*/
  {
   int n1,n2,i,j=0,k=0;
   n1=q-p+1;
   n2=r-q;
   int L[n1],R[n2];
   for(i=p;i<q+1;i++)
      {
       L[i-p]=A[i];
      }
   for(i=q+1;i<r+1;i++)
      {
       R[i-q-1]=A[i];
      }
   for(i=p;i<=r;i++)
      {
       if(j<n1)
         {
          if(L[j]<R[k] && k<n2)
            {
             A[i]=L[j];
             j++;
            }
          else
            {
             if(k==n2)
               {
                A[i]=L[j];
                j++;
               }
             else
               {
                A[i]=R[k];
                k++;
               }
            }
         }
      }
   }
