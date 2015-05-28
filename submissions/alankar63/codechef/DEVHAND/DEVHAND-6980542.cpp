//using trie approach
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
#define mset(a) memset(a, 0, sizeof(a))
 
ll powMod(ll a, ll b, ll x){
	ll res = 1;
	while (b){
		if (b & 1) res = (res * a) % x;
		a = (a * a) % x;
		b >>= 1;
	}
	return res;
}
ll n,k; 
ll f1(ll x){
	if (x == 0) return (k * f1(1)) % md;
	return (((powMod(k, n - x + 1, md) - 1 + md) % md) * powMod(k - 1, md - 2, md)) % md;
}
ll f2(ll x){
	ll s1 = (((powMod(k, n - x, md) - 1 + md) % md) * powMod(k - 1, md - 2, md)) % md;
	ll s2 = (powMod(k, n - x + 2, md) + k ) % md;
	ll s3 = (((2 * powMod(k, n - x + 1, md)) % md)*(n - x)) % md;
	ll d1 = powMod(2*(k-1), md - 2, md);
	return ((((s1 * s2) % md - s3 + md) % md) * d1) % md;
}
ll f3(){
	ll res = 0;
	if (k > 1){
		ll s1 = (((powMod(k, 3*n + 3, md) - powMod(k, n + 5, md) + md) % md) * (powMod(2 * (k*k - 1) * (k - 1) * (k - 1), md - 2, md))) % md;
		res = (res + s1) % md;
		
		ll s2 = (((powMod(k, 2*n + 2, md) - powMod(k, n + 3, md) + md) % md) * powMod(2*(k-1)*(k-1)*(k-1), md - 2, md)) % md;
		res = (res + s2) % md;
		
		ll s3 = (((powMod(k, 2*n + 3, md) - powMod(k, n + 4, md) + md) % md) * powMod(2*(k-1)*(k-1)*(k-1), md - 2, md)) % md;
		res = (res - s3 + md) % md;
 
		//~ ll s4 = ((((n - 1) * powMod(k, n + 2, md)) % md) * powMod(2*(k-1)*(k-1), md - 2, md)) % md;
		//~ res = (res - s4 + md) % md;
 
		ll s5 = (((powMod(k, 2*n + 2, md) - powMod(k, n + 3, md) + md) % md) * powMod(2*(k-1)*(k-1)*(k-1), md - 2, md)) % md;
		res = (res - s5 + md) % md;
			
		ll s6 = ((((n - 1) * powMod(k, n + 1, md)) % md) * powMod(2*(k-1)*(k-1), md - 2, md)) % md;
		res = (res - s6 + md) % md;
 
		//~ ll s7 = ((((n - 1) * powMod(k, n + 2, md)) % md) * powMod(2*(k-1)*(k-1), md - 2, md)) % md;
		//~ res = (res + s7 + md) % md;
 
		ll s8 = (((powMod(k, n + 1, md) - powMod(k, 2, md) + md) % md) * powMod(2*(k-1)*(k-1)*(k-1), md - 2, md)) % md;
		res = (res + s8 + md) % md;
		
		ll s9 = ( ((n * ((powMod(k, 2*n + 2, md) - powMod(k, n + 3, md) + md) % md) ) % md) * powMod((k-1)*(k-1), md - 2, md)) % md;
		res = (res - s9 + md) % md;
		
		ll s10_1 = (((powMod(k, 2*n + 2, md) - ((n-1)*powMod(k, n + 3, md)) % md + md) % md) * powMod((k-1)*(k-1), md - 2, md)) % md;
		ll s10_2 = (((powMod(k, 2*n + 2, md) - powMod(k, n + 4, md) + md) % md) * powMod((k-1)*(k-1)*(k-1), md - 2, md)) % md;
		res = (res + s10_1 + s10_2) % md;
		
		ll s11_dash = ((((((n % md)*(n-1)) % md) * powMod(k, n + 1, md)) % md) * powMod(2*(k - 1), md - 2, md)) % md;
		res = (res + s11_dash) % md;
		
		res = (res + (((((k*(k-1)) % md) * f1(n)) % md) * f2(n)) % md) % md;
	}
	//~ printf("after part1: %lld\n", res);
	if (k > 2){
		ll pre = (((k*(k-2))%md)*powMod(6*(k-1)*(k-1), md - 2, md)) % md;
		ll post = (((powMod(k, 3*n + 2, md) - powMod(k, n + 2, md) + md) % md) * powMod(k*k - 1, md - 2, md)) % md;
		post = (post - ((3 * ((powMod(k, 2*n + 1, md) - powMod(k, n + 1, md) + md) % md) % md) * powMod(k - 1, md - 2, md)) % md + md) % md;
		post = (post + (((3*n) % md) * powMod(k, n, md)) % md) % md;
		post = (post - (((powMod(k, n, md) - 1 + md) % md) * powMod(k-1, md - 2, md)) % md + md) % md;
		res = (res + (pre * post) % md) % md;
	}
	//~ printf("after part2: %lld\n", res);
	return res;
}
int main()
{
	ll t, test; scanf("%lld", &test);
	for (ll t = 0; t < test; t++){		
		scanf("%lld %lld", &n, &k);
		//~ ll kc2 = ((k*(k-1))/2) % md, kc3 = ((k * (k - 1) * (k - 2)) / 6) % md;
		//~ for (ll i = n - 1; i >= 1; i--) f1[i] = (k * f1[i+1] + 1) % md;
		//~ f1[0] = (k * f1[1]) % md;
		//~ for (ll i = n - 1; i >= 0; i--){
			//~ f2[i] = (k * f2[i+1]) % md;
			//~ if (k >= 2) f2[i] = (f2[i] + (((kc2 * f1(i + 1)) % md) * f1(i+1)) % md) % md;
		//~ }
		//~ for (ll i = n - 1; i >= 0; i--){
			//~ f3[i] = (k * f3[i+1]) % md;
			//~ if (k >= 2) f3[i] = (f3[i] + (((((kc2 * 2) % md) * f1(i + 1)) % md) * f2(i + 1)) % md ) % md;
			//~ if (k >= 3) f3[i] = (f3[i] + (((((kc3 * f1(i + 1)) % md) * f1(i + 1)) % md) * f1(i + 1)) % md) % md;
		//~ }
		printf("%lld\n", (f3() * 6) % md);
		//~ printf("%lld %lld\n", f1(1), f2(1));
	}
	return 0;
}
/*
Sum[(((k^(n - x - i) - 1) / (k - 1)) * ( k ^ (n - x - i - 1) + k) - 2 * (k^(n-x-i))*(n-x-i-1)) * ((k^(n - x - i) - 1) / (k - 1)) * (k ^ (i + 1)), {i, 0, n - x -1}]
Sum[((k*(k-1)*(k-2))/6) * (((k^(n - x - i) - 1) / (k - 1)) ^ 3), {i, 0, n - x -1}]
*/