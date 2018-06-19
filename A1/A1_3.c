#include<string.h>
#include<stdio.h>

void main()
  {
   FILE *fp;
   char fname[10],s1[10],s2[10],c,check[10];
   int i=0,j=0;
   printf("Enter file name: ");
   scanf("%s",fname);

   fp=fopen(fname,"r+");
   if ((fp=fopen(fname,"r+"))==NULL)
       {
       printf ("Cannot open file\n");
       }
   else
        

   printf("Enter two strings: ");
   scanf("%s%s",s1,s2);
   
    
     while (fscanf(fp, "%s", check) != EOF) 
        {
         if(strcmp(check,s1)==0)
           *s1=*s2;
        }
          
    while((c=fgetc(fp))!=EOF)
          putchar(c);

    if(fp)
     {
      fclose(fp);
     }
  }
