#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007ll

string name[110];

int main(void){
    int N,M,i,j;
    
    cin >> N >> M;
    REP(i,N) cin >> name[i];
    
    ll ans = 1;
    REP(j,M){
        set <char> s;
        REP(i,N) s.insert(name[i][j]);
        ll tmp = s.size();
        ans = ans * tmp % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}