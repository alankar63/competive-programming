#include<stdio.h>
inline long long int scan()
{
    int n=0;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9')
    ch=getchar_unlocked();
    while(ch>='0'&&ch<='9')
    {
        n=(n<<3)+(n<<1)+ch-'0';
        ch=getchar_unlocked();
    }
    return n;
}
inline void fastWrite(long long int a)
{
    char snum[20];
    int i=0;
    do
    {
        snum[i++]=a%10+48;
        a=a/10;
    }while(a!=0);
    i=i-1;
    while(i>=0)
    putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
}
long long gcd(long long a,long  long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    long long int t;
    t=scan();
    while(t--)
    {
        long long int n,m,ans=0;
        n=scan();
        m=scan();
        if(n==1 || m==1)
            ans=n>m?n:m;
        else
            ans=gcd(n-1,m-1)+1;
        fastWrite(ans);
    }
    return 0;
}