#include<bits/stdc++.h>
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pnt pair<int,int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define eps 1e-9
#define pi 3.14159265358979323846
#define gc getchar_unlocked

#define dbg(x)	{cerr<< #x << " = " << x <<endl;}

typedef long long ll;
typedef unsigned long long ull;

const ll MOD=1000000007;

using namespace std;

inline int inp(){
	int n=0;
	char c;
	c=gc();
	while(c<'0' || c>'9'){
		c=gc();
	}
	while(c>='0' && c<='9'){
		n=(n<<3)+(n<<1)+c-'0';
		c=gc();
	}
	return n;
}

ll power(ll a,ll b,ll mod){
      if(b==0)
            return 1;
      ll temp=power(a,b/2,mod);
      temp=(temp*temp)%mod;
      if(b&1)
            temp=(temp*a)%mod;
      return temp;
}

int pwr(int a,int b){
      if(b==0)
            return 1;
      int temp=pwr(a,b/2);
      temp=(temp*temp);
      if(b&1)
            temp=(temp*a);
      return temp;
}

ll gcd(ll a,ll b){
      return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
      return (a/gcd(a,b))*b;
}

ll modularInverse(ll a,ll m){
      return power(a,m-2,m);
}

int ceill(int a,int b){
	return (a+b-1)/b;
}

vector<int>v[10001];
vector<int>vv[10001];
vector<int>v2[101];
queue<int>q;
bool visited[10001];
int dist[10001];
int comp[10001];
int co=0;
bool vis[10001];
int max_dist[10001];
int array[10001];
int parent[10001];
bool visitedd[10001];

void bfs(int source){
	int p,i;
	visited[source]=true;
	dist[source]=0;
	parent[source]=-1;
	q.push(source);
	while(!q.empty()){
		p=q.front();
		FOR(i,0,v[p].size()){
			if(!visited[v[p][i]]){
				parent[v[p][i]]=p;
				q.push(v[p][i]);
				visited[v[p][i]]=true;
				dist[v[p][i]]=dist[p]+1;
			}
		}
		q.pop();
	}
}

void dfs(int source){
	int i;
	comp[source]=co;
	vis[source]=true;
	FOR(i,0,vv[source].size()){
		if(!vis[vv[source][i]]){
			dfs(vv[source][i]);
		}
	}
}

int find_parent(int x){
	if(visitedd[x])	return dist[x];
	return find_parent(parent[x]);
}

void mark_node(int A,int B){
	visitedd[A]=true;
	if(A==B)	return;
	mark_node(parent[A],B);
}

int main(){
	int n,k,B,A,P,Q,i,j,x,y,F,ans,flag,val,maxx,pp,flagi,a1;
	#ifndef ONLINE_JUDGE
		freopen("inpu.txt","r",stdin);
	#endif
	n=inp();
	k=inp();
	B=inp();
	B--;
	FOR(i,0,n-1){
		x=inp();
		y=inp();
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
		if(x!=B && y!=B){
			vv[x].pb(y);
			vv[y].pb(x);
		}
	}
	bfs(B);
	FOR(i,0,n){
		F=inp();
		array[i]=F;
		v2[F].pb(i);
	}
	FOR(i,1,k+1){
		sort(v2[i].begin(),v2[i].end());
	}
	FOR(i,0,n){
		if(i!=B && !vis[i]){
			co++;
			dfs(i);
		}
	}
	Q=inp();
	FOR(i,0,Q){
		flag=0;
		A=inp();
		P=inp();
		A--;
		if(v2[P].size()==0){
			cout<<"-1\n";
			continue;
		}

		if(array[A]==P){
			if(A==B)	ans=v2[P][0]+1;
			else{
				flagi=0;
				FOR(j,0,v2[P].size()){
					if(comp[v2[P][j]]==comp[A] && v2[P][j]!=A){
						flagi=1;
					}
				}
				if(flagi){
					mset(visitedd,false);
					mark_node(A,B);
					maxx=dist[A];
					ans=A;
					FOR(j,0,v2[P].size()){
						if(comp[A]==comp[v2[P][j]] && v2[P][j]!=A){
							a1=find_parent(v2[P][j]);
							if(a1==maxx){
								ans=min(ans,v2[P][j]);
							}
						}
					}
					ans++;
				}
				else{
					ans=A+1;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		flagi=0;
		FOR(j,0,v2[P].size()){
			if(comp[v2[P][j]]==comp[A]){
				flagi=1;
			}
		}
		if(flagi){
			maxx=-1;
			mset(visitedd,false);
			mark_node(A,B);
			FOR(j,0,v2[P].size()){
				if(comp[A]==comp[v2[P][j]]){
					a1=find_parent(v2[P][j]);
					if(a1>maxx){
						maxx=a1;
						ans=v2[P][j];
					}
					else if(a1==maxx){
						ans=min(ans,v2[P][j]);
					}
				}
			}
			ans++;
		}
		else{
			ans=v2[P][0]+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}