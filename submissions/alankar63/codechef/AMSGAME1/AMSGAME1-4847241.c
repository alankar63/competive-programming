#include<stdio.h>
#define MAX 1005
#define gc getchar()
typedef long long int ll;
ll ra()
{
 char c;
 ll r=0;
 c=gc;
 while(c<'0' || c>'9')
   c=gc;
 while(c>='0' && c<='9')
 {
    r=(r<<3)+(r<<1)+c-'0';
    c=gc;
 
 }
 
return r;
 
 
}
 
ll gcd(ll a,ll b)
{
   if(b==0)
   {
      return a;
 
   }
   else
     return gcd(b,a%b);
 
 
}
 
int main()
{
  ll a[MAX],n,t,p,i,j;
  t=ra();
  while(t--)
  {
     n=ra();
     for(i=0;i<n;i++)
       a[i]=ra();
     p=a[0];
     for(i=1;i<n;i++)
     {
	p=gcd(p,a[i]);
 
     }
     printf("%lld\n",p);
 
 
  }
 
 
 
 
 
 
return 0;
 
}