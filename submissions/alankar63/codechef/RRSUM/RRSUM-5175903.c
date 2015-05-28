#include <stdio.h>
#include <stdlib.h>
 inline void scanint(long long int* x)
    {
    register char c = getchar_unlocked();
    *x = 0;
    for(; (c<48)||(c>57);c = getchar_unlocked());
    for(; (c>47)&&(c<58);c = getchar_unlocked())
    *x = (long long int)((((*x)<<1) + ((*x)<<3)) + c - 48);
    }
 
    inline void printint(int n)
    {
    if(n == 0)
    {
    putchar_unlocked('0');
    putchar_unlocked('\n');
    }
    else
    {
    char buf[20];
    buf[19] = '\n';
    int i = 18;
    while(n)
    {
    buf[i--] = n % 10 + '0';
    n /= 10;
    }
    while(buf[i] != '\n')
    putchar_unlocked(buf[++i]);
    }
    }
int main()
{
    long long int n,m,q;
    scanint(&n);
    scanint(&m);
    while(m--){
        scanint(&q);
        if(q<=n+1)
            printint(0);
        else if(q<=2*n+1)
            printint(n-(2*n+1-q));
        else
            printint(n-(q-1-2*n));
    }
    return 0;
}