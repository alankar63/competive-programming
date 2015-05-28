#include<stdio.h>
 #include<stdlib.h>
 int main()
 {
     int tc,i,count,j;
     scanf("%d",&tc);
     while(tc--)
     {
         count=0;
         char a[101],b[101];
         scanf("%s",a);
         scanf("%s",b);
         i=0;
         while(b[i]!='\0')
         {
             j=0;
             while(a[j]!='\0')
             {
                if(a[j]==b[i])
                {
                    count++;
                    break;
                }
                 j++;
             }
             i++;
         }
         printf("%d\n",count);
     }
     return 0;
 }