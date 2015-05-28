#include<stdio.h>
#include<stdlib.h>
//#define MAX 10000001
#define MOD 1000000007
long long int powmod(int a,int n)
{
    long long int x=a,p;
    if(n==0)
        return 1;
    if(n==1)
        return x;
    p=powmod(a,n/2);
    p*=p;
    p=p%MOD;
    if(n&1)
    {
        p*=x;
        p=p%MOD;
    }
    return p;
}
int main()
{
    int t,n,m,l,r,/*a[MAX],b[MAX],*/d,i;long long int sum;
    int *a,*b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&l,&r);
        a=(int*)malloc(sizeof(int)*(m+1));
        b=(int*)malloc(sizeof(int)*(m+1));
        for(i=l;i<=m;i++)
        {
            a[i]=powmod(m/i,n);
            while(m/i==m/(i+1))
            {
                i++;
                a[i]=a[i-1];
            }
        }
        b[m]=1;
        for(d=m-1;d>=l;d--)
        {
            sum=0;
            for(i=2*d;i<=m;i+=d)
            {
                sum+=b[i];
                if(sum>=MOD)sum-=MOD;
            }
            b[d]=a[d]-sum;
            if(b[d]<0)
                b[d]+=MOD;
        }
        sum=0;
        for(d=l;d<=r;d++)
        {
            sum+=b[d];
            if(sum>=MOD)sum-=MOD;
        }
        printf("%lld\n",sum);
        free(a);
        free(b);
    }
    return 0;
}