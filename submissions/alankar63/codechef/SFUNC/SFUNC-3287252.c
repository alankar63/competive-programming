#include<stdio.h>
 
long long int t;
long long int gcd(long long int x,long long int y)
{
    while(y!=0)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}
 
int main()
{
    long long int n,sum;
    int m,k,i,j;
 
    scanf("%lld %d %d",&n,&k,&m);
    if(m==1)
    {
        printf("0");
        return 0;
    }
    sum=1;
    j=0;
    for(i=2;i<n;i++)
    {
        if(gcd(i,n)==1)
        {
            sum+=pow(i,k);
            if(sum>m)
                sum=sum%m;
        }
    }
    printf("%lld",sum);
    return 0;
}