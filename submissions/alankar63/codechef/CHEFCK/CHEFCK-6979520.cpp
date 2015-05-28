//using sliding window
#include<bits/stdc++.h>
#define md 1000000007
#define gc getchar//_unlocked
#define ll  long long
using namespace std;
ll ar[10000010];
int dp[10000010];
void find( int n, int k)
{
    std::deque<int>  Qi(k);
    int i;
    for (i =0; i < k; ++i)
    {
        
        while ( (!Qi.empty()) && ar[i+1] <= ar[Qi.back()+1])
            Qi.pop_back(); 
 
        
        Qi.push_back(i);
		
		
    }
 
    int j=1;
    for ( ; i <n; ++i)
    {
       
        dp[j++]= ar[Qi.front()+1];
		
        
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  
 
        
        while ( (!Qi.empty()) && ar[i+1] <= ar[Qi.back()+1])
            Qi.pop_back();
 
         
        Qi.push_back(i);
    }
    dp[j++]=ar[Qi.front()+1];
}
int main()
{
	
    	clock_t start;
    double duration;
	start = clock();
			#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);		
		#endif
		int n,k,q;
		
		ll sum=0;
		ll mul=1;
		cin>>n>>k>>q;
		ll a, b, c, d, e, f, r, s, t, m;
		cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>ar[1];
		//scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&ar[1]);
		
		
	
		ll pow=t;
		for(int x=2;x<=n;x++){
			pow=(pow*t);
			if(pow>s)
				pow%=s;
			if(pow<=r)
				ar[x] = (ar[x-1]*(a*(ar[x-1]) + b)%m + c)% m;
			else
				ar[x] = (ar[x-1]*(d*(ar[x-1]) + e)%m + f) %m;
			
		}
	
	find(n,k);
	
	
		ll L1, La, Lc, Lm, D1, Da, Dc, Dm;
			cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
			//scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
			
			for(int i=1;i<=q;i++){
				ll L,R;
				L1 = (La * L1 + Lc) % Lm;
				D1 = (Da * D1 + Dc) % Dm; 
				L = L1 + 1;
				R = min(L + k - 1 + D1, (ll)n);
				
				int mn=min(dp[L],dp[R-k+1]);
				sum+=mn;
				mul=(mul*mn)%md;
			}
			
		cout<<sum<<" "<<mul<<endl;
		
	
    return 0;
}