#include<stdio.h>

typedef union p
 {
  float height;
  int age;
 }P;

int main()
 {
  P detail;
  int c;
  char g;
  float h;
  h=detail.height;
  printf("\nEnter the Gender:");
  scanf("%c",&g);
  if(g=='f' || g=='F')
    {
      printf("Enter Height:");
      scanf("%f", &detail.height);
      printf("Height=%f\nAge=%d\n",detail.height,detail.age);
    }

  if(g=='m' || g=='M')
   {
      printf("Enter Age:");
      scanf("%d", &detail.age);
      printf("Height=%f\nAge=%d\n",h,detail.age);
   }
 }

