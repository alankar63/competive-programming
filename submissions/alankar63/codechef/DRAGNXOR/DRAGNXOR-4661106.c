#include<stdio.h>
#include<math.h>
#define ch ((i+j)>=n?((2*n)-i-j):i+j)
int main()
{
long long int n,t,a,b,a1,k,l,s,i,j;
scanf("%lld",&t);
while(t--)
{
scanf("%lld%lld%lld",&n,&a,&b);
s=0;i=0;j=0;
while(a!=0)
{
if(a%2!=0)
{
a/=2;
i++;
}
else
a/=2;
}   
while(b!=0)
{
if(b%2!=0)
{
b/=2;
j++;
}
else
b/=2;
}  
k=ch;
a1=1;
while(a1<=k)
{
n--;                    
s+=pow(2,n);
a1++;
}
printf("%lld\n",s);
}
return 0;          
}