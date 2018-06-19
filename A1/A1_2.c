#include<stdio.h>
#include<string.h>

void main()
{
 char p[10000],k,str[10]; /*p=paragraph*/
 int i,pl=0,sl=0;
 printf("Enter a paragraph:\n");
 do
  {
    k=getchar();
    p[i]=k;
    i++;
  }
  while(k!='\n');
  
 for(i=0;i<9999;i++)
   {
    if(p[i]!='\n')
       pl++;
    else
     {
      p[i]='\0';
      break;
     }
   }

 printf("Enter the string to be searched: ");
 scanf("%s",&*str);
 
  for(i=0;i<9;i++)
   {
    if(str[i]!='\0')
       sl++;
    else
     {
      break;
     }
   }

 search(&p,&str,pl-1,sl,0,0);

}

int search(int *p,int *s,int pl,int sl,int i,int o)
 {
 int j; 
 for(j=0;j<sl;j++)
  {
   while(i<pl)
    {
     if((p[i]==s[j]) && p[i-j-1]==' ')
      {
       i++;
       break;
      }
     else
       i++;
    }
  }
  if(j==sl)
   {
    if(p[i+1]=='\0' || p[i+2]=='\0')
      {
       o++;
       printf("Number of occurances: %d\n",o);
      }
    else
      {
       if(p[i+1]=='.' || p[i+3]=='i+33')
         {
         o++;
         search(&*p,&*s,pl,sl,i+3,o);
         }
       if(p[i+1]==' ')
         {
          o++;
          search(&*p,&*s,pl,sl,i+2,o);
         }
       }
   }
 } 
/*int length(int *p,int m,int n)
  {
  int i;
  for(i=0;i<n;i++)
   {
    if(p[i]!='\0')
       m++;
    else
     {
      break;
     }
   }
   return(m);
  }*/
