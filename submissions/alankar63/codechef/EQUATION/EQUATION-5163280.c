#include <stdio.h>
# define gc getchar_unlocked
 
inline  int sscan()
{int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0')
    {
n=n*10+c-'0';
c=gc();
    }
return n;
}
 
long long f(long long n)
{
            long long r;
            if(n<0)
                   return 0;
            r=((n+1)*(n+2)*(n+3));
            return r/6;
}
 
int main()
{
    int t;
    t=sscan();
    while(t--)
    {
        int a,b,c,n;
        n=sscan();  a=sscan();  b=sscan();  c=sscan();
        unsigned long long ct;
 
        ct=f(n)-f(n-a-1)-f(n-b-1)-f(n-c-1)+f(n-a-b-2)+f(n-b-c-2)+f(n-a-c-2)-f(n-a-b-c-3);
 
        printf("%llu\n",ct);
    }
return 0;
}