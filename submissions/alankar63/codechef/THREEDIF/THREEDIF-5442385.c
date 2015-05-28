#include<stdio.h>
#define SI(x) scanf("%d",&x)
#define SL(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define A 1000000007
int main(){
    int t;
    SI(t);
    while(t--){
        long long a,b,c,ans,tmp1,tmp_low,tmp2,tmp_high,tmp_left;
        SL(a,b,c);
        tmp1 = min(b,c);
        tmp_low = min(tmp1,a);
        tmp2 = max(a,b);
        tmp_high = max(tmp2,c);
        tmp_left = a+b+c-tmp_low-tmp_high;
 
        ans = ((((tmp_low%A)*((tmp_left-1)%A))%A)*((tmp_high-2)%A))%A;
        printf("%lld\n",ans);
    }
 return 0;
}