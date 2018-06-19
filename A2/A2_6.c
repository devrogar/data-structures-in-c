#include<stdio.h>
#include<time.h>
 
int left(int i)
  {
   return ((2*i)+1);
  }

int right(int i)
  {
   return ((2*i)+2);
  }

int exchange(int *a, int *b)
  {
   int temp=0;
   temp=*a;
   *a=*b;
   *b=temp;
  }

int max_heapify(int *A,int i,int n)
  {
   int l,r,p;
   l=left(i);
   r=right(i);
   if((l<=n) && (A[l]>A[i]))
     p=l;
   else
     p=i;

   if((r<=n) && (A[r]>A[p]))
     p=r;
   if(p!=i)
    {
     exchange(&A[i],&A[p]);
     max_heapify(&*A,p,n);
    }
  }

int main()
  {
   FILE *fp;
   clock_t start,stop;
   double runtime;
   int i,j,k,n;
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
    build_heap(&a,n);
    heap_sort(&a,n);
    printf("after heap sort:\n");
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

int build_heap(int *A,int n)
   {
    int i;
    for(i=(n/2)-1;i>=0;i--)
       max_heapify(&*A,i,n);
   }

int heap_sort(int *A, int n)
  {
   int i;
   for(i=n;i>=1;i--)
     {
      exchange(&A[i],&A[0]);
      n--;
      max_heapify(&*A,0,n);
     }
  }
