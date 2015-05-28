#include<stdio.h>
#include<math.h>
#define ll long long int
ll min(ll a,ll b)
{
    return a>b?b:a;
}
int main()
{   ll l,r,res;
    int t,c,rem;
   ll e[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999};
   ll s[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&l,&r);
        int ld=(int)log10(l)+1;
        int rd=(int)log10(r)+1;
        res=0;
        while(ld!=rd)
        {
            res=res+((l+e[ld])*(e[ld]-l+1)*ld)/2;
            ld++;
            l=s[ld];
            res %=1000000007;
        }
        res=res+((l+r)*ld*(r-l+1))/2;
        res %=1000000007;
        printf("%lld\n",res);
    }
    return 0;
}