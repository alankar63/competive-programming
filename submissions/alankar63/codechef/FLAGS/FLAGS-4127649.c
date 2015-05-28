#include<stdio.h>

#include<stdlib.h>
int main()
{long long int t,a,b=0;
scanf("%llu",&t);
while(t--)
{
scanf("%llu",&a);
b=2*(a-1)*(a-1)*a+a*(a-1)*(a-2)+a*(a-1)*(a-2)*(a-2)*2;
printf("%llu\n",b);
}
return 0;
}