using namespace std;
 
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
 
#define EPS 1e-11
#define inf ( 1LL << 31 ) - 1
#define LL long long
 
#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define rep( i, n ) _rep( i, 0, n - 1, 1 )
#define rrep( i, a, b ) for( __typeof(b) i = ( a ); i >= ( b ); --i )
#define xrep( i, a, b ) _rep( i, a, b, 1 )
 
#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))
#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()

/*
Spirits coming from the mind,
waking up my deepest horrors,
capture my thoughts, make me blind.

Weird, ‘cause I don't want to see
the abyss of my possibilities.

Scared I can't look away.

It has come to my side.
Sister demon - my bride.

I want you, I need you
and I have set you free.
You're always right behind me,
I know the devil's sent you to me.
You want me, you need me,
now that I've set you free.
Look always right behind you,
You know the devil's sent me to you.

What has started as a longing
almost is possession now,
it drives me again and again.
Put a light into your window,
maybe I can find a hold.
I run against myself ‘till I find the end.

Sent by the devil
*/
 
typedef vector <int> vi;
const int MAX = 100000;
const int NLEVEL = 17;
int Left[4*MAX+2], Right[4*MAX+2], Len[4*MAX+2];
vi sarray[4*MAX+2];
int input[MAX+2];
int cnt;
int intervals[4*MAX+2];
 
void mergeSort(int node, int L, int R)
{
    if (L > R) return;
    Left[node] = L; Right[node] = R; Len[node] = (R - L + 1);
    sarray[node].clear();
    if (L == R)
    {
        sarray[node].pb(input[L]);
        return;
    }
    int mid = (L + R)/2;
    mergeSort(2*node, L, mid);
    mergeSort(2*node+1,mid+1,R);
    int i = 0, j = 0, k = 0;
    while (i < Len[2*node] && j < Len[2*node+1])
    {
        if (sarray[2*node][i] <= sarray[2*node+1][j])
            sarray[node].pb(sarray[2*node][i++]);
        else
            sarray[node].pb(sarray[2*node+1][j++]);
    }
    if (i == Len[2*node]) while (j < Len[2*node+1]) sarray[node].pb(sarray[2*node+1][j++]);
    else while (i < Len[2*node]) sarray[node].pb(sarray[2*node][i++]);
}
 
void query(int node, int L, int R)
{
    if (R < Left[node] || Right[node] < L) return;
    if (L <= Left[node] && Right[node] <= R)
    {
        intervals[cnt++] = node;
        return;
    }
    int mid = (Left[node] + Right[node]) / 2;
    query(2*node, L, R);
    query(2*node+1, L, R);
 
}
 
int check(int node, LL num)
{
 
    int lo = 0, hi = Len[node]-1, mid;
 
    if (hi == 0)
    {
        if (sarray[node][0] <= num) return 1;
        return 0;
    }
 
    while (lo < hi)
    {
        mid = (lo + hi)/2;
        if (sarray[node][mid] >= num) hi = mid;
        else lo = mid + 1;
    }
    if (lo >= 0 && sarray[node][lo] > num) lo--;
 
 
    return lo + 1;
}
 
int main()
{
        #ifdef Local
                freopen("/home/wasi/Desktop/input.txt", "r", stdin);
        #endif
    int n, m, a, b, k;
    while (scanf("%d %d", &n, &m) == 2)
    {
        rep(i,n) scanf("%d", &input[i+1]);
        mergeSort(1, 1, n);
 
        rep(i,m)
        {
            scanf("%d %d %d", &a, &b, &k);
            cnt = 0;
            query(1, a, b);
 
            LL lo = 0, hi = 2000000000, mid;
            int tot;
 
            while (lo < hi)
            {
                mid = lo + (hi - lo)/2;
                tot = 0;
 
                rep(j, cnt)
                    tot += check(intervals[j], mid - 1000000000);
 
                if (tot >= k) hi = mid;
                else lo = mid + 1;
            }
            printf("%lld\n", lo-1000000000);
        }
 
    }
        return 0;
}