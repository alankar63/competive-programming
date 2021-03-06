#include <bits/stdc++.h>
using namespace std;
#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;
 
const int MAX = 201;
 
int vis[MAX], booked[MAX];
vector<int> G[MAX];
 
bool dfs(int x){
    REP(i, 0, G[x].size()){
        int u = G[x][i];
        if(vis[u]) continue;
        int t = booked[u];
        booked[u] = x;
        vis[u] = true;
        if(t == -1 || dfs(t)) return true;
        booked[u] = t;
    }
    return false;
}
 
 
int main(){
    int n, m;
    cin >> n >> m;
    REP(i, 0, m){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    int ans = n;
    memset(booked, -1, sizeof booked);
    REP(i, 1, n+1){
        memset(vis, 0, sizeof vis);
        if(dfs(i)){
            ans--;
        }
    }
 
    cout << ans << endl;
    return 0;
}