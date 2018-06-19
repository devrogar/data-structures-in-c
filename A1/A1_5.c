#include<stdio.h>

int main()
{
 int n,i,j,k;
 
 printf("enter a positive integer n:");
 scanf("%d", &n);
 

 for(j=2;j<=n;j++)
  {
   if(n%j==0)
    {
    for(i=2,k=1;i<=j;i++)
     {
      if(j%i!=0)
       {
        k++;
       }
      else
       {
        if(j==i){
          k++;
          break;}
       }  
     
       }
     if(j==k)
       printf("%d\n", j);
     
  }
 }
}
