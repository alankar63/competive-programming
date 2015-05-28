#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <string>
#include <cstring>
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
#define rf freopen("in.in", "r", stdin)
#define wf freopen("out.out", "w", stdout)
using namespace std;
const int mx = 1e5+10;
#define ll long long

int n, q, r, t;
static ll co[mx]={1}, m;
vector<ll> pr;
map<ll, ll> nco[mx];
map<ll, ll>::iterator it;

ll exp(ll b, ll e)
{
	ll x=1;
	while(e)
	{
		if(e&1) x = (x*b)%m;
		b = (b*b)%m; e/=2;
	}
	return x;
}

ll ext_euclid(ll a, ll b)
{
	ll q, ps=1, s=0, pt=0, t=1, r;

	while(a%b != 0)
	{
		q = a/b; r = a-q*b;

		ll tmps=s, tmpt=t;
		s = ps-q*s, t = pt-q*t;
		ps = tmps, pt = tmpt;

		a=b; b=r;
	}
	return (t+m)%m;
}

void produce_primes()
{
	pr.push_back(2); pr.push_back(3);
	rep(i, 4, mx-1)
	{
		int j=0;
		for(; pr[j]<=sqrt(i); ++j)
			if(i%pr[j]==0)
				break;
		if(i%pr[j]!=0) pr.push_back(i); 
	}
}

int main()
{
	//rf;// wf;

	produce_primes();
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %lld %d", &n, &m, &q);
		rep(i, 1, n)
			co[i]=1, nco[i].clear();
		
		for(int j=0; pr[j]<=n; ++j)
		{
			for(int k=1; k*pr[j]<=n; ++k)
			{
				ll num=k*pr[j], cnt=0, idx=num;
				while(num%pr[j]==0)
					cnt++, num/=pr[j];
				cnt*=idx;

				if(__gcd(m, pr[j])>1)
					nco[idx][pr[j]] += cnt;
				else co[idx] = (co[idx] * exp(pr[j], cnt))%m;
			}
		}

		rep(i, 2, n)
		{
			co[i] = (co[i]*co[i-1])%m;

			for(it = nco[i-1].begin(); it!=nco[i-1].end(); ++it)
				nco[i][it->first] += it->second;
		}

		while(q--)
		{
			scanf("%d", &r);
			
			ll ans = (co[r]*co[n-r])%m;
			ans = ext_euclid(m, ans);

			for(it = nco[n].begin(); it!=nco[n].end(); ++it)
			{
				ll pw = it->second - nco[r][it->first] - nco[n-r][it->first];
				ans = (ans * exp(it->first, pw))%m; 
			}
			ans = (ans*co[n])%m;
			printf("%lld\n", ans);
		}
	}
	return 0;
}