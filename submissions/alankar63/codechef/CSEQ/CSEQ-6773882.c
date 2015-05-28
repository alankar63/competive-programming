#include <stdio.h>
#include <stdlib.h>
#define ll long long 
#define miN(a,b)                ((a)<(b)?(a):(b))
#define mod 1000003
#define maxx 1000003
inline int scan(){
register int t=0;char c=getchar_unlocked();
while(c<'0' || c>'9')c=getchar_unlocked();
while(c>='0' && c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}
return(t);}
ll power(ll a,ll b)
{
    ll x=1,y=a%mod; 
    while(b > 0)
    {
        if(b&1)
        x=(x*y)%mod;
        y=(y*y)%mod;
        b=b>>1;
    }
    return x%mod;
}
ll C(ll n, ll r)
{
	ll y=miN(n,r);
	ll num=1,den=1,i;
	for(i=0;i<y;i++)
	{
		num=(num*(n-i))%mod;
		den=(den*(y-i))%mod;
	}
	ll o=(num*power(den,mod-2))%mod;
	return o;
}
inline ll Lucas(ll n, ll m)
{
    if (n==0 && m==0) return 1;
    int ni = n % mod;
    int mi = m % mod;
    if (mi>ni) return 0;
    return (Lucas(n/mod,m/mod)%mod*C(ni,mi))%mod;
}
int main() 
{
	int t,n,l,r,p,i;
	ll k;
	t=scan();
	while(t--)
	{
		n=scan(),l=scan(),r=scan();
		p=(r-l)+1;
		k=Lucas(p+n,n);
		printf("%lld\n",(k-1+mod)%mod);
	}
	return 0;
}