#include<stdio.h>
typedef long long ll;
ll prime[100000+10], dp[100000][10], pre[100000];
int p[100000+10];
void precalc()
{
    ll i,j,l;
	prime[0]=2;
	l=1;
	for(i=3;i<=100007;i+=2)
	{
		if(!p[i])  
            for(j=i*i, prime[l++]=i; j<=100007; j+=2*i) 
            {
                p[j]=1;
            }
	}
}
ll gcd(ll a, ll b)
{
	ll temp;
	while(a)
	{
		temp=a;
		a=b%a;
		b=temp;
	}
	return b;
}
void EE(ll a, ll b, ll *x, ll *y)
{
	if(a==0)
	{
		*x=0; *y=1; return;
	}
	ll temp_x,temp_y;
	EE(b%a, a, &temp_x, &temp_y);
	*y=temp_x;
	*x=temp_y - (b/a)*temp_x;
 
}
ll inverse(ll a,ll m)
{
	ll x,y;
	EE(a,m,&x,&y);
	while(x<0) x+=m;  
	return x;
}
ll mod_pow(ll a,ll b,ll m)
{
	ll r=1;
	while(b)
	{
		if(b%2==1) r=r*a%m;
		a=(a*a)%m;b/=2;
	}
	return r;
}
int main()
{
    ll t,n,m,q,i,j,temp,ans;
	precalc();
 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld", &n,&m,&q);
		// fact array to store all distinct prime factors of m
		ll fact[100000+10];
		temp=m;
		int pos=0;
		for(j=0; prime[j]*prime[j]<=temp; j++)
		{
			if(temp%prime[j]==0)
			{
			    fact[pos++] = prime[j];
				while(temp%prime[j]==0)
                    temp/=prime[j];
			}
		}
		if(temp>1)
            fact[pos++] = temp;
		ll l=pos; 
 
		//
		for(j=0;j<l;j++) dp[1][j]=0;
		for(j=0;j<l;j++) dp[0][j]=0;
		pre[0]=1%m;
		pre[1]=1%m;
		for(i=2;i<=n;i++)
		{
			temp=i;
			for(j=0;j<l;j++)
			{
				if(temp%fact[j]==0)
				{
					ll e=0;
					while(temp%fact[j] == 0)
					{
						e++;
						temp/=fact[j];
					}
					dp[i][j] = dp[i-1][j] + e*i;
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
            }
			temp = mod_pow(temp,i,m);
			pre[i] = pre[i-1]*(temp)%m;
		}
		while(q--)
		{
			ll r;
			scanf("%lld",&r);
 
			ans= pre[r]*pre[n-r]%m;
			ans = pre[n]*inverse(ans,m)%m;
			for(j=0;j<l;j++)
			{
				temp = mod_pow(fact[j],dp[n][j]-dp[r][j]-dp[n-r][j],m);
				ans = ans*temp%m;
			}
			printf("%lld\n",ans);
		}
	}
}