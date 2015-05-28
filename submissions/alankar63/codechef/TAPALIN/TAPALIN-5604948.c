#include<stdio.h>
#define ll long long int
#define M 1000000007
ll pw(ll a,ll b)
{
	ll r;
	if(b==0)
	return 1;
	else if(b==1)
	return a;
	else 
	{
		r=pw(a,b/2);
		if(b%2==0)
		return (r*r)%M;
		else
		return ((r*r)%M*a)%M;
	}
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
	ll n,s=0;
	scanf("%lld",&n);
	if(n%2==0)
	{
		s=(((pw(26,n/2)-1)*52)%M*pw(25,1000000005))%M;
	}
	else
	{
		s=(((pw(26,(n-1)/2)-1)*52)%M*pw(25,1000000005))%M;
		s=(s+pw(26,(n+1)/2))%M;
	}
	printf("%lld\n",s);
}	
}