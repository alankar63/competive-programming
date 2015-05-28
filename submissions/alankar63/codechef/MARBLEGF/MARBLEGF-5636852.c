//use of segment tree
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long a[10000000],s[10000000];
long long num()
{
    int n=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        n=n*10+(c-'0');
        c=getchar();
    }
    return n;
}
long long create(long long b,long long e,long long n)
{
    if(b==e)
    {
        s[n]=a[b];
    }
    else
    {
        s[n]=create(b,(b+e)/2,2*n+1)+create((b+e)/2+1,e,2*n+2);
    }
    return s[n];
}
long long sum(long long b,long long e,long long i,long long j,long long n)
{
    if(b>j||e<i)
    {
        return 0;
    }
    else if(b>=i&&e<=j)
    {
        return s[n];
    }
    else
    {
        return sum(b,(b+e)/2,i,j,2*n+1)+sum((b+e)/2+1,e,i,j,2*n+2);
    }
}
int give(long long b,long long e,long long i,long long j,long long n)
{
    if(b==e&&b==i)
    {
        s[n]+=j;
        return 0;
    }
    s[n]+=j;
    if(i<=(b+e)/2)
        give(b,(b+e)/2,i,j,2*n+1);
    else
        give((b+e)/2+1,e,i,j,2*n+2);
    return 0;
}
int main()
{
    long long n,q,i,j;
    char p[3];
 
    scanf("%lld %lld",&n,&q);
    for(i=0;i<n;i++)
        a[i]=num();
    create(0,n-1,0);
    while(q--)
    {
        scanf("%s %lld %lld",p,&i,&j);
        if(strcmp(p,"S")==0)
        {
            printf("%lld\n",sum(0,n-1,i,j,0));
        }
        else if(strcmp(p,"G")==0)
        {
            give(0,n-1,i,j,0);
        }
        else
        {
            give(0,n-1,i,-1*j,0);
        }
    }
    return 0;
}