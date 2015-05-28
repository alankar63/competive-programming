#include<stdio.h>
#include<math.h>
long long ar[1000];
long long check(long long a)
{
long long s,d,f,g,h,j,k,l;
while(a)
{
s=a%10;
if(s!=1 && s!=4 && s!=9 && s!=0) return 0;
a=a/10;
}
return 1;
}
int main()
{
long long a,s,d,f,g,h,j,k,l;
k=0;
for(a=1;a<=100000;a++)
{
s=a*a;
if(check(s))
{
ar[k]=s;
k++;
}
}
scanf("%lld",&a);
while(a--)
{
scanf("%lld%lld",&s,&d);
l=0;
for(j=0;j<k;j++) if(ar[j]>=s && ar[j]<=d) l++;
printf("%lld\n",l);
}
}