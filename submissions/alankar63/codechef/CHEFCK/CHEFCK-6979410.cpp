#include<bits/stdc++.h>
 
using namespace std;
 
#define 	SZ(A) 		((int)A.size())
#define 	LEN(A) 		((int)A.length())
#define 	MS(A) 		memset(A, 0, sizeof(A))
#define 	MSV(A,a) 	memset(A, a, sizeof(A))
#define 	mp(x,y)		make_pair((x),(y))
#define 	pb(x) 		push_back(x)
#define		F 		first
#define 	S 		second
#define 	INF 		(ll(1e9))
#define 	INFL 		(ll(1e18))
#define 	EPS 		1e-12
 
#define 	chkbit(s, b) 	(s & (1<<b))
#define 	setbit(s, b) 	(s |= (1<<b))
#define 	clrbit(s, b) 	(s &= ~(1<<b))
 
#define 	swap(x,y)  	{x=x+y-(y=x);}
#define 	FOUND(A, x) 	(A.find(x) != A.end())
 
#define 	s(x) 		scanf("%d",&x);
#define 	s2(x,y) 	scanf("%d%d",&x,&y);
#define 	sl(x) 		scanf("%lld",&x);
#define 	p(x) 		printf("%d\n",x);
#define 	p1d(a,n)        for(int i = 0; i < n; i++) printf("%d ",a[i]); printf("\n");
 
 
#define 	REP(i, n) 	for(i = 0; i < (n); i++)
#define 	FOR(i, a, n) 	for(i = a; i < n; i++)
#define 	REV(i, a, n) 	for(i = a; i >= n; i--)
#define 	FORALL(itr, c) 	for(itr = (c).begin(); itr != (c).end(); itr++)
#define 	ALL(A) 		A.begin(), A.end()
#define 	LLA(A) 		A.rbegin(), A.rend()
#define 	print(a,n)	REP(int i = 0; i < (n) ; i++)	pl(a[i]);
 
#define 	MOD	        1000000007
 
#define gc getchar//_unlocked
 
#define 	DEBUG 		1
#define 	TRACE 		1
 
#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif
 
typedef long long ll;
typedef unsigned long long ull;
 
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;
 
#define NN			10000001
#define LOGMAXNN	23
#define mo 			1000000007
 
int M[2][NN];
 
void SparseTable(int N,int co){
    int i, j;
	
	for (j = 1; (1 << j <= N) && (j <= co) ; j++){
		for (i = 0; i + (1 << j) - 1 < N; i++){
			if (M[!(j&1)][i] < M[!(j&1)][i + (1 << (j - 1))])
				M[j&1][i] = M[!(j&1)][i];
			else
				M[j&1][i] = M[!(j&1)][i + (1 << (j - 1))];
		}
	}
	
}
 
int main(){
	ll s,r,t,a,b,d,e,N,K,Q,c,f,m,L1,La,Lc,Lm,D1,Da,Dc,Dm,i,x;;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif
	
	sl(N);
	sl(K);
	sl(Q);
	sl(a);
	sl(b);
	sl(c);
	sl(d);
	sl(e);
	sl(f);
	sl(r);
	sl(s);
	sl(t);
	sl(m);
	s(M[0][0]);
	sl(L1);
	sl(La);
	sl(Lc);
	sl(Lm);
	sl(D1);
	sl(Da);
	sl(Dc);
	sl(Dm);
	
	a %= m;
	b %= m;
	c %= m;
	d %= m;
	e %= m;
	f %= m;
	
	int power_of_two[25] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216};
	
	int copyK = K;
	int co = 0;
	while(copyK){
		copyK /= 2;
		co++;
	}
	if(K&(K-1)==0)	co--;
	
	ll temp = t;
	FOR(x,1,N){
		t = (t*temp)%s;
		if(t <= r)
			M[0][x] = ((a * M[0][x-1])%m * M[0][x-1] + b * M[0][x-1] + c)% m;
		else
			M[0][x] = ((d * M[0][x-1])%m * M[0][x-1] + e * M[0][x-1] + f)% m;
	}
	
	SparseTable(N,co);
	
	ll ans1 = 0;
	ll ans2 = 1;
	ll cur;
	
	REP(i,Q){
		L1 = (La * L1 + Lc) % Lm;
		D1 = (Da * D1 + Dc) % Dm; 
		ll L = L1 + 1;
		ll R = min(L + K - 1 + D1, N);
		L--;
		R--;
		
		int k = co;
		
		if( L + power_of_two[k] - 1 > R ){
			k--;
		}
		
		if(M[k&1][L] <= M[k&1][R - power_of_two[k] + 1]){
			cur = M[k&1][L];
		}
		else{
			cur = M[k&1][R - power_of_two[k] + 1];
		}
		
		ans1 += cur;
		ans2 *= cur;
		if(ans2 >= mo)
			ans2 %= mo;
	}
	
	printf("%lld %lld\n",ans1,ans2);
}