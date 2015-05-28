#include<stdio.h>
#include<stdlib.h>
int main()
{
int a;
float b,c;
scanf("%d %f",&a,&b);
c=b-a-0.5;
if(a%5!=0||a>=(b-0.5))
printf("%.2f",b);
else
printf("%.2f",c);
return 0;
}