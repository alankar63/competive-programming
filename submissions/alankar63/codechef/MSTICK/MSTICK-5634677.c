//using segment tree......for rmq see next sol

#include<stdio.h>
long long num()
{
    long long n=0;
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
 
long long s[2000000],p[2000000];
long long a[1000000];
int create(long long b,long long e,long long n)
{
    if(b==e)
    {
        s[n]=a[b];
    }
    else
        {
            create(b,(b+e)/2,2*n+1);
            create((b+e)/2+1,e,2*n+2);
            s[n]=s[2*n+1]<s[2*n+2]?s[2*n+1]:s[2*n+2];
        }
    return 0;
}
int createagain(long long b,long long e,long long n)
{
    if(b==e)
    {
        p[n]=a[b];
    }
    else
        {
            createagain(b,(b+e)/2,2*n+1);
            createagain((b+e)/2+1,e,2*n+2);
            p[n]=p[2*n+1]>p[2*n+2]?p[2*n+1]:p[2*n+2];
        }
    return 0;
}
long long ronaldo(long long b,long long e,long long l,long long r,long long n)
{
    long long i,j;
    if(e<l||b>r)
    {
        return 0;
    }
    if(b>=l&&e<=r)
    {
        return p[n];
    }
    i=ronaldo(b,(b+e)/2,l,r,2*n+1);
    j=ronaldo((b+e)/2+1,e,l,r,2*n+2);
    return i>j?i:j;
}
long long messi(long long b,long long e,long long l,long long r,long long n)
{
    long long i,j;
    if(e<l||b>r)
    {
        return 100000001;
    }
    if(b>=l&&e<=r)
    {
        return s[n];
    }
    i=messi(b,(b+e)/2,l,r,2*n+1);
    j=messi((b+e)/2+1,e,l,r,2*n+2);
    return i<j?i:j;
}
int main()
{
    long long n,l,r,q,i;
    double u,v,w,x;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        a[i]=num();
    create(0,n-1,0);
    createagain(0,n-1,0);
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld",&l,&r);
        u=l!=0?ronaldo(0,n-1,0,l-1,0):0;
        v=ronaldo(0,n-1,l,r,0);
        w=r!=n-1?ronaldo(0,n-1,r+1,n-1,0):0;
        x=messi(0,n-1,l,r,0);
        u+=x;
        w+=x;
        v=x+(v-x)/2;
        u=u>w?u:w;
        u=u>v?u:v;
        printf("%.1f\n",u);
    }
    return 0;
}