#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
long long int n;
int g,i,q;
scanf("%d",&g);
while(g--)
{
scanf("%d %lld %d",&i,&n,&q);
 
if(i==1&&q==1)
printf("%lld\n",n/2);
else if(i==1&&q==2)
printf("%lld\n",n-n/2);
else if(i==2&&q==1)
printf("%lld\n",n-n/2);
else if(i==2&&q==2)
printf("%lld\n",n/2);
}
}
return 0;
}