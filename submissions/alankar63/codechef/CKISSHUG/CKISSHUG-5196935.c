#include<stdio.h>
    #define MOD 1000000007
    long long p(int n)
    {
    if(n==0) return 1;
    if(n%2==0)
    {
    long long x=p(n/2);
    return (x*x)%MOD;
    }
    else
    {
    long long x=p(n/2);
    return (x*x*2)%MOD;
    }
    }
    int main()
    {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
    scanf("%d",&n);
    int ans;
    if(n%2==0)
    ans=(3*p(n/2)-2)%MOD;
    else
    ans=(4*p((n-1)/2)-2)%MOD;
    printf("%d\n",ans);
    }
    }