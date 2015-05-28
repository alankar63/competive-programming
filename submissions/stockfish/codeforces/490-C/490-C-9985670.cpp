#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define mp make_pair
#define pb push_back

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const double pi = acos(-1.0);
const int inf = (int) 1e9;

int kol[1000006];

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("weyland.in","r",stdin);
    //freopen("weyland.out","w",stdout);
#endif
    string s;
    cin >> s;
    int a,b;
    cin >> a >> b;
    int n = s.size();
    LL now = 0;
    FOR(i,n - 1) {
        now *= 10;
        now += (s[i] - '0');
        now %= a;
        if (now == 0 && s[i + 1] != '0') {
            kol[i]++;
        }
    }
    now = 0;
    LL st = 1;
    for(int i = n - 1; i > 0; --i) {
        now += (s[i] - '0') * st;
        st *= 10;
        st %= b;
        now %= b;
        if (now == 0 && s[i] != '0') {
            kol[i - 1]++;
        }
    }
    FOR(i,n) {
        if (kol[i] == 2) {
            cout << "YES\n";
            FORE(j,i) {
                cout << s[j];
            }
            cout << "\n";
            REP(j,i + 1,n) {
                cout << s[j];
            }
            return 0;
        }
    }
    cout << "NO";
    return 0;
}