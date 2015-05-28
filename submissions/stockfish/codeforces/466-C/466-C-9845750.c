#include<stdio.h>
long long int sum[500010];
int main(){
    long long int x,n,t=0,y,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {   scanf("%lld",&x);
        sum[i]=x+sum[i-1];
    }
    if(sum[n]%3!=0)
        printf("0\n");
    else{
        x=sum[n]/3;
        y=0;
        for(i=n-1;i>=1;i--){
            if(sum[i]==x)
                t+=y;
            if(sum[i]==2*x)
                y++;
        }
            printf("%lld\n",t);
    }
    return 0;
}