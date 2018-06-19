#include<stdio.h>

void main()
 {
  char s1[20],s2[20];
  printf("Enter first string: ");
  read(&s1);
  printf("Enter second strng: ");
  read(&s2);
  printf("\nConcatenated string :");
  conc(&s1,&s2);
  print(&s1);
  
 }


int read(char *p)
 {
    scanf("%s",&*p);
    return;
 }

int conc(char *p,char *q)
  {
   int i,j;
   for(i=0,j=0;i<19;i++)
    {
     if(q[j]=='\0')
      {
       break;
      }
     else
       {
       if(p[i]=='\0')
         {
         p[i]=q[j];
         p[i+1]='\0';
         j++;
         }
      } 
    }
   return;
  }

int print(char *p)
  {
    printf("%s\n",p);
  }
