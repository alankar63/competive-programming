#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
 
using namespace std;
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define y0 isdnfviu
#define y1 asinhiv
#define fst first
#define snd second
#define count sdifnsugh
 
ll a[3];
 
int main()
{
        ll n;
        for(int i=0; i<3; i++) cin >> a[i];
        sort(a,a+3);
        reverse(a,a+3);
        if (a[0]<(a[1]+a[2])*2) cout << (a[0]+a[1]+a[2])/3;
        else cout << a[1]+a[2];
        cin >> n;
        return 0;
}