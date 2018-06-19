#include<stdio.h>

int main()
 {
  int a,b,c;
  printf("Enter two numbers: ");
  scanf("%d%d",&a,&b);
  
  printf("\t1-Sum \n \t2-difference \n Enter your choice: ");
  scanf("%d", &c);
  
  switch(c)
   {
    case 1:
       printf("Selected operation is sum and the result is %d\n",a+b);
       break;
    case 2:
       printf("Selected operation is difference and the result is %d\n", a-b);
       break;
    default:
       printf("Invalid choice\n");
   }
 }
