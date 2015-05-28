#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXL = 100005;
int n,p,ans,l,r;
char a[MAXL];

int main(){
    //freopen("input","r",stdin);
    scanf("%d%d",&n,&p);
    scanf("%s",a);
    -- p;
    if(p >= (n >> 1)) p = n - p - 1;
    l = r = 0;
    for(int i = 0;i < p;++ i)
    if(a[i] != a[n - 1 - i]){
        l = p - i; break;
    }
    for(int j = p + 1;j < (n >> 1);++ j)
    if(a[j] != a[n - 1 - j])
        r = j - p;
    if(l == 0)
        ans = r;
    else if(r == 0)
        ans = l;
    else
        ans = l > r ? l + r * 2 : r + l * 2;
    for(int i = 0,dt;i < (n >> 1);++ i)
    if(a[i] != a[n - 1 - i]){
        dt = a[n - 1 - i] > a[i] ? a[n - 1 - i] - a[i] : a[i] - a[n - 1 - i];
        if(26 - dt < dt) dt = 26 - dt;
        ans += dt;
    }
    printf("%d\n",ans);
    return 0;
}