#include<stdio.h>
 
int main()
{
long  int a,n,k,i;
scanf("%ld%ld%ld",&a,&n,&k);
n+=1;
for(i=0;i<k;i++)
{
                if(a>0)
                {
                       printf("%ld ",a%n);
                       a=a/n;
                       }
                       else printf("0 ");
                       }
                       return 0;
                       }