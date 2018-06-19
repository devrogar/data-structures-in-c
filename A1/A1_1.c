#include<stdio.h>

int main()
 {
  int n,i;
  printf("Enter the value for n: ");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements of the array:");
  for(i=0;i<n;i++)
   {
    scanf("%d", &a[i]);
   }
  printf("Entered array:");
  printArr(&a,n);
  reverse(&a,n,0);
  printf("reversed array:");
  printArr(&a,n);  
 }
    
int printArr(int *p,int n)
 {
  int i;
  for(i=0;i<n;i++)
   { 
    printf("%d ", p[i]);
   }
 printf("\n");
 }

int reverse(int *p,int n, int i)
 {
  int k;
  if(i<n/2)
    {
    k=p[i];
    p[i]=p[n-1-i];
    p[n-1-i]=k;
    reverse(&*p,n,i+1);
    }
}
