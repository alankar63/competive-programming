#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,b;
long int a=0;

scanf("%d",&t);
while(t--)
{
scanf("%d",&b);
if(b>0)
a=a+b;
}
printf("%ld",a);
return 0;
}

