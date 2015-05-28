#include<stdio.h>
int main()
{int t;
long long int a,b,c,d;
scanf("%d",&t);
while(t--)
{scanf("%llu",&a);
scanf("%llu",&b);
if(((a%2)==1)&&((b%2)==1))
{c=a*b;
d=c-1;
printf("%llu/%llu\n",d/2,c);
}else printf("1/2\n");
}
return 0;
}